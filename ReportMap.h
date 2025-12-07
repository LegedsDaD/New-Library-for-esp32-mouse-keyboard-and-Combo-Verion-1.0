#ifndef REPORTMAP_H
#define REPORTMAP_H


#include <stdint.h>


namespace ReportMap {
	const uint8_t* getComboReportMap();
	size_t getComboReportMapLength();
	const uint8_t* getKeyboardReportMap();
	size_t getKeyboardReportMapLength();
	const uint8_t* getMouseReportMap();
	size_t getMouseReportMapLength();
}


#endif // REPORTMAP_H