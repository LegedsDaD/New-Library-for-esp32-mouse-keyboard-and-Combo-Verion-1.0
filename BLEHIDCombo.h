#ifndef BLEHIDCOMBO_H
#define BLEHIDCOMBO_H


#include "BLEKeyboard.h"
#include "BLEMouse.h"


class BLEHIDCombo : public BLEKeyboard, public BLEMouse {
public:
	BLEHIDCombo(const char* name = "ESP32 Combo");
	bool begin();
	void end();
};


#endif // BLEHIDCOMBO_H
