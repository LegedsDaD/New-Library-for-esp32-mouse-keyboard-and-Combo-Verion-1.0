#include "ReportMap.h"
0x75, 0x01, // Report Size (1)
0x95, 0x08, // Report Count (8)
0x81, 0x02, // Input (Data,Var,Abs) ; Modifier byte


0x75, 0x08, // Report Size (8)
0x95, 0x01, // Report Count (1)
0x81, 0x01, // Input (Const) ; Reserved


0x05, 0x07, // Usage Page (Keyboard)
0x19, 0x00, // Usage Minimum (0)
0x29, 0x65, // Usage Maximum (101)
0x15, 0x00, // Logical Minimum (0)
0x25, 0x65, // Logical Maximum (101)
0x75, 0x08, // Report Size (8)
0x95, 0x06, // Report Count (6)
0x81, 0x00, // Input (Data,Array) ; Key arrays (6 bytes)


// --- Mouse
0x05, 0x01, // Usage Page (Generic Desktop)
0x09, 0x02, // Usage (Mouse)
0xA1, 0x02, // Collection (Logical)
0x09, 0x01, // Usage (Pointer)
0xA1, 0x00, // Collection (Physical)
0x05, 0x09, // Usage Page (Buttons)
0x19, 0x01, // Usage Minimum (1)
0x29, 0x03, // Usage Maximum (3)
0x15, 0x00, // Logical Minimum (0)
0x25, 0x01, // Logical Maximum (1)
0x95, 0x03, // Report Count (3)
0x75, 0x01, // Report Size (1)
0x81, 0x02, // Input (Data,Var,Abs)


0x95, 0x01, // Report Count (1)
0x75, 0x05, // Report Size (5)
0x81, 0x01, // Input (Const,Array,Abs) ; padding


0x05, 0x01, // Usage Page (Generic Desktop)
0x09, 0x30, // Usage (X)
0x09, 0x31, // Usage (Y)
0x09, 0x38, // Usage (Wheel)
0x15, 0x81, // Logical Minimum (-127)
0x25, 0x7F, // Logical Maximum (127)
0x75, 0x08, // Report Size (8)
0x95, 0x03, // Report Count (3)
0x81, 0x06, // Input (Data,Var,Rel)


0xC0, // End Collection
0xC0, // End Collection
0xC0 // End Collection
};


const uint8_t* ReportMap::getComboReportMap() { return comboReportMap; }
size_t ReportMap::getComboReportMapLength() { return sizeof(comboReportMap); }


// Fallbacks (not used directly in MVP but provided)
const uint8_t* ReportMap::getKeyboardReportMap() { return comboReportMap; }
size_t ReportMap::getKeyboardReportMapLength() { return sizeof(comboReportMap); }
const uint8_t* ReportMap::getMouseReportMap() { return comboReportMap; }
size_t ReportMap::getMouseReportMapLength() { return sizeof(comboReportMap); }