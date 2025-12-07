#include "HIDDevice.h"
uint8_t protocol = 1; // Report
protocolModeChar->setValue(&protocol, 1);


// Report characteristic (notify)
reportChar = hidService->createCharacteristic(REPORT_UUID, BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_NOTIFY);
reportChar->addDescriptor(new BLE2902());


// Control Point
controlPointChar = hidService->createCharacteristic(HID_CTRL_PT_UUID, BLECharacteristic::PROPERTY_WRITE);


hidService->start();


// Advertising
BLEAdvertising* advertising = BLEDevice::getAdvertising();
advertising->addServiceUUID(HID_SERVICE_UUID);
advertising->setScanResponse(true);
advertising->setMinPreferred(0x06); // functions that help with iPhone connection
advertising->setMinPreferred(0x12);
BLEDevice::startAdvertising();


return true;
}


void HIDDevice::end() {
	if (pServer) {
		BLEDevice::deinit(true);
		pServer = nullptr;
	}
}


bool HIDDevice::isConnected() {
	return connected;
}


void HIDDevice::sendReport(const uint8_t* data, size_t len) {
	if (!reportChar) return;
	reportChar->setValue(data, len);
	if (connected) {
		reportChar->notify();
	}
}


void HIDDevice::setManufacturer(const char* m) { manufacturer = m; }
void HIDDevice::setDeviceName(const char* n) { deviceName = n; }