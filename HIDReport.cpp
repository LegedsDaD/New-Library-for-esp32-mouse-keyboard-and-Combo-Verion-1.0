#include "HIDReport.h"
#include <string.h>


void HIDReport::buildComboReport(uint8_t* buf) {
	memset(buf, 0, COMBO_LEN);
	buf[0] = 0x01; // Report ID 1
}


void HIDReport::setModifier(uint8_t* buf, uint8_t modifiers) {
	buf[1] = modifiers;
}


void HIDReport::setKey(uint8_t* buf, uint8_t keycode, size_t index) {
	if (index >= 6) return;
	buf[3 + index] = keycode;
}


void HIDReport::clearKeys(uint8_t* buf) {
	for (int i = 0; i < 6; ++i) buf[3 + i] = 0;
}


void HIDReport::setMouseButtons(uint8_t* buf, uint8_t buttons) {
	buf[9] = buttons & 0x07;
}


void HIDReport::setMouseMove(uint8_t* buf, int8_t x, int8_t y, int8_t wheel) {
	buf[10] = (uint8_t)x;
	buf[11] = (uint8_t)y;
	buf[12] = (uint8_t)wheel;
}