class Ultrasonic {
    public:

    int trigPin, echoPin;

    Ultrasonic(int trigPin, int echoPin) {
        this->trigPin = trigPin;
        this->echoPin = echoPin;
    
        pinMode(trigPin, OUTPUT);
        pinMode(echoPin, INPUT);
    }
    float getDistance() {
        digitalWrite(trigPin, LOW);
        delayMicroseconds(2);
        digitalWrite(trigPin, HIGH);
        delayMicroseconds(10);
        digitalWrite(trigPin, LOW);
        return pulseIn(echoPin, HIGH) / 58.;
    }
};