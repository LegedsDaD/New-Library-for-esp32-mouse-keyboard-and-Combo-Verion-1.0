#ifndef HIDDEVICE_H
#define HIDDEVICE_H


#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>


#include "ReportMap.h"


class HIDDevice {
public:
	HIDDevice(const char* name = "ESP32 BLE HID");
	~HIDDevice();


	bool begin();
	void end();


	bool isConnected();


	// send raw report (reportId included if used)
	void sendReport(const uint8_t* data, size_t len);


	void setManufacturer(const char* m);
	void setDeviceName(const char* n);


private:
	const char* deviceName;
	const char* manufacturer;


	BLEServer* pServer = nullptr;
	BLEService* hidService = nullptr;
	BLECharacteristic* reportMapChar = nullptr;
	BLECharacteristic* reportChar = nullptr;
	BLECharacteristic* hidInfoChar = nullptr;
	BLECharacteristic* controlPointChar = nullptr;
	BLECharacteristic* protocolModeChar = nullptr;


	bool connected = false;


	void setupHID();


	class ServerCallbacks : public BLEServerCallbacks {
	public:
		ServerCallbacks(HIDDevice* outer) : _outer(outer) {}
		void onConnect(BLEServer* pServer) override { _outer->connected = true; }
		void onDisconnect(BLEServer* pServer) override { _outer->connected = false; pServer->getAdvertising()->start(); }
	private:
		HIDDevice* _outer;
	};
};


extern HIDDevice GlobalHID; // convenience global


#endif // HIDDEVICE_H