


float PID(float Kp, float Ki, float Kd, float setpoint, float input) {
    static float integral = 0, last_error = 0;
    float error = setpoint - input;
    integral += error;
    float derivative = error - last_error;
    last_error = error;
    float sum = Kp * error + Ki * integral + Kd * derivative;
    if (sum > 255) {
        return 255;
    } else if (sum < -255) {
        return -255;
    } else {
        return sum;
    }
}


Motors motors;

void setup() {
    Serial.begin(115200);
    motors.setSpeed(0);
}


int min_kick = 110;
int max_speed = 255;
int status = 0;

int prev_dist = 0;
int dist_delta = 0;
void loop () {
    int dist = ultrasonic.getDistance();
    if (dist > 200) dist = prev_dist;
    int ddist = dist * 0.1 + prev_dist * 0.9;

    float pid_reading = PID(-2.5, 0.0, 0.0, 20, ddist);
    motors.setSpeed(pid_reading);

    Serial.println("DISTANCIA\tPID");
    Serial.print(ddist);
    Serial.print("\t\t");
    Serial.println(pid_reading);
    prev_dist = dist;
    delay(100);
    // Serial.println(pid_reading);


}