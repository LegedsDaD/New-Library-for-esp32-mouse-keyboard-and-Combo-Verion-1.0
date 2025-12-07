#ifndef BLEMOUSE_H
#define BLEMOUSE_H


#include <Arduino.h>
#include "HIDReport.h"
#include "HIDDevice.h"


class BLEMouse {
public:
	BLEMouse(const char* name = "ESP32 Mouse");
	bool begin();
	void end();


	void move(int8_t x, int8_t y, int8_t wheel = 0);
	void click(uint8_t buttons = 1);
	void press(uint8_t buttons = 1);
	void release(uint8_t buttons = 1);


	bool isConnected();


protected:
	const char* devName;
	uint8_t report[HIDReport::COMBO_LEN];
};


#endif // BLEMOUSE_H
