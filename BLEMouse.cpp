#include "BLEMouse.h"


BLEMouse::BLEMouse(const char* name) : devName(name) { HIDReport::buildComboReport(report); }


bool BLEMouse::begin() {
	GlobalHID.setDeviceName(devName);
	return GlobalHID.begin();
}


void BLEMouse::end() { GlobalHID.end(); }


void BLEMouse::move(int8_t x, int8_t y, int8_t wheel) {
	// clear keyboard bytes to avoid ghosting
	for (int i = 0; i < 6; ++i) report[3 + i] = 0;
	report[1] = 0; // modifiers
	HIDReport::setMouseButtons(report, report[9]);
	HIDReport::setMouseMove(report, x, y, wheel);
	GlobalHID.sendReport(report, sizeof(report));
	// reset movement to 0 after sending
	HIDReport::setMouseMove(report, 0, 0, 0);
}


void BLEMouse::click(uint8_t buttons) {
	HIDReport::setMouseButtons(report, buttons);
	GlobalHID.sendReport(report, sizeof(report));
	delay(8);
	HIDReport::setMouseButtons(report, 0);
	GlobalHID.sendReport(report, sizeof(report));
}


void BLEMouse::press(uint8_t buttons) {
	HIDReport::setMouseButtons(report, buttons);
	GlobalHID.sendReport(report, sizeof(report));
}


void BLEMouse::release(uint8_t buttons) {
	uint8_t cur = report[9];
	cur &= ~buttons;
	HIDReport::setMouseButtons(report, cur);
	GlobalHID.sendReport(report, sizeof(report));
}


bool BLEMouse::isConnected() { return GlobalHID.isConnected(); }