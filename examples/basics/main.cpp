#include "WifiManager.h"

void setup() {
	// Attempts to connect to Wifi using stored credentials
	bool connected = WifiManager.connectToWifi();

	if (!connected) {
		// If unable to connect on boot, the management server is started
		// so new credentials can be set using the web interface.
		WifiManager.startManagementServer();
	}
}

void loop() {
	// Continously checks if we are connected on WIFI. The wifi manager
    // will automatically reconnect if connection is dropped.
	WifiManager.check();

    // Do your main application loop here.
    // ...
}
