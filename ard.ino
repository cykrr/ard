#include "motors.h"
#include "ultrasonic.h"


class Motors {
    public: 
        Motor motor_left;
        Motor motor_right;
        float proportion = 0.8;
        Motors() {
            motor_left = Motor(6, 5);
            motor_right = Motor(11, 10);
        }
        void setSpeed(int speed) {
            motor_left.setSpeed(speed);
            motor_right.setSpeed(speed);
        }
};

#include <SoftwareSerial.h>




float PID (float Kp, float Ki, float Kd, float setpoint, float input) {
    static float integral = 0, last_error = 0;
    float error = setpoint - input;
    integral += error;
    float derivative = error - last_error;
    last_error = error;
    float sum = Kp * error + Ki * integral + Kd * derivative;
    return sum;
}

static Motors motors;
static Ultrasonic ultrasonic = Ultrasonic(12, 13);
static SoftwareSerial BTSerial(4, 3);


void setup() {
    motors.setSpeed(0);
    BTSerial.begin(9600);
    Serial.begin(9600);

}

void loop() {
    static float setpoint = 20;
    float input = ultrasonic.getDistance();
    BTSerial.println(input);
    // float pid = PID(-1.0, -0.1, -0.1, setpoint, input);
    // Serial.println("DISTANCIA\tPID");
    // Serial.print(input);
    // Serial.print("\t\t");
    // Serial.println(pid);
    // if (pid > 5) {
    //     // kick
    //     motors.setSpeed(110);
    //     delay(100);
    //     motors.setSpeed(60);
    // } else if (pid < -5) {
    //     motors.setSpeed(-110);
    //     delay(100);
    //     motors.setSpeed(-60);
    // } else {
    //     motors.setSpeed(0);
    // }
    if (BTSerial.available()) {
        Serial.write(BTSerial.read());
    }
    if (Serial.available()) {
        BTSerial.write(Serial.read());
    }
    // // delay(100);
    // motors.setSpeed(0);
    // // delay(500);

}