#include <wiringPi.h>
#include <softPwm.h>
#include "Robot.h"

void robot::init() {
	
	wiringPiSetup();

	pinMode(AIN1_PIN, OUTPUT);
	pinMode(AIN2_PIN, OUTPUT);
	pinMode(BIN1_PIN, OUTPUT);
	pinMode(BIN2_PIN, OUTPUT);

	softPwmCreate(PWMA_PIN, 0, 255);
	softPwmCreate(PWMB_PIN, 0, 255);
}

void robot::run(int leftSpeed, int rightSpeed) {
  
  // Left side motors
  digitalWrite(AIN1_PIN, HIGH);   
  digitalWrite(AIN2_PIN, LOW);  
  softPwmWrite(PWMA_PIN, leftSpeed);

  // Right side motors
  digitalWrite(BIN1_PIN, HIGH);  
  digitalWrite(BIN2_PIN, LOW); 
  softPwmWrite(PWMB_PIN, rightSpeed);
}

void robot::stop() {
  digitalWrite(AIN1_PIN, LOW);
  digitalWrite(AIN2_PIN, LOW);
  digitalWrite(BIN1_PIN, LOW);
  digitalWrite(BIN2_PIN, LOW);
}
