#include "BLEKeyboard.h"


BLEKeyboard::BLEKeyboard(const char* name) : devName(name) { HIDReport::buildComboReport(report); }


bool BLEKeyboard::begin() {
	GlobalHID.setDeviceName(devName);
	return GlobalHID.begin();
}


void BLEKeyboard::end() { GlobalHID.end(); }


void BLEKeyboard::press(uint8_t k) {
	// add key into first empty slot
	for (int i = 0; i < 6; ++i) {
		if (report[3 + i] == 0) { report[3 + i] = k; break; }
	}
	GlobalHID.sendReport(report, sizeof(report));
}


void BLEKeyboard::release(uint8_t k) {
	for (int i = 0; i < 6; ++i) {
		if (report[3 + i] == k) { report[3 + i] = 0; }
	}
	GlobalHID.sendReport(report, sizeof(report));
}


void BLEKeyboard::releaseAll() {
	for (int i = 0; i < 6; ++i) report[3 + i] = 0;
	report[1] = 0; // modifiers
	GlobalHID.sendReport(report, sizeof(report));
}


size_t BLEKeyboard::write(uint8_t k) {
	press(k);
	delay(8);
	release(k);
	return 1;
}


bool BLEKeyboard::isConnected() { return GlobalHID.isConnected(); }