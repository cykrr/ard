class Motor {
    public: 
    Motor() {}
    int pinA, pinB;
    Motor(int pinA, int pinB) {
        this->pinA = pinA;
        this->pinB = pinB;
    
        pinMode(this->pinA, OUTPUT);
        pinMode(this->pinB, OUTPUT);
    }
    void setSpeed(int speed) {
        if (speed > 0) {

            analogWrite(this->pinA, speed);
            analogWrite(this->pinB, 0);
        } else if (speed < 0){
            analogWrite(this->pinA, 0);
            analogWrite(this->pinB, abs(speed));
        } else {
            analogWrite(this->pinA, 0);
            analogWrite(this->pinB, 0);
        }
    }
};

