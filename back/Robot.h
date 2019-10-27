#ifndef _ROBOT_H_
#define _ROBOT_H_

#define AIN1_PIN 29
#define AIN2_PIN 28
#define BIN1_PIN 25
#define BIN2_PIN 24
#define PWMA_PIN 27
#define PWMB_PIN 23

namespace robot {
	void init();
	void run(int leftSpeed, int rightSpeed);
	void stop();
}

#endif