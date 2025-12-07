#ifndef BLEKEYBOARD_H
#include "HIDReport.h"
#include "HIDDevice.h"


class BLEKeyboard {
public:
	BLEKeyboard(const char* name = "ESP32 Keyboard");
	bool begin();
	void end();


	void press(uint8_t k);
	void release(uint8_t k);
	void releaseAll();
	size_t write(uint8_t k);


	bool isConnected();


protected:
	const char* devName;
	uint8_t report[HIDReport::COMBO_LEN];
};


#endif // BLEKEYBOARD_H
