#ifndef HIDREPORT_H
#define HIDREPORT_H


#include <stdint.h>


class HIDReport {
public:
	// Combo report layout (includes Report ID at [0])
	// Layout: [0]=ReportID, [1]=Modifier, [2]=Reserved, [3..8]=Keys(6), [9]=MouseButtons, [10]=X, [11]=Y, [12]=Wheel
	static const size_t COMBO_LEN = 13; // 1 + 1 + 1 + 6 + 1 + 1 + 1 + 1


	static void buildComboReport(uint8_t* buf);


	// keyboard helpers
	static void setModifier(uint8_t* buf, uint8_t modifiers);
	static void setKey(uint8_t* buf, uint8_t keycode, size_t index);
	static void clearKeys(uint8_t* buf);


	// mouse helpers
	static void setMouseButtons(uint8_t* buf, uint8_t buttons);
	static void setMouseMove(uint8_t* buf, int8_t x, int8_t y, int8_t wheel);
};


#endif // HIDREPORT_H
