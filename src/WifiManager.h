#ifndef WIFI_MANAGER_H
#define WIFI_MANAGER_H

#include <ESPAsyncWebServer.h>
#include <DNSServer.h>

#include "Configuration.h"

class WifiManagerClass {
	public:
		WifiManagerClass();
  		void begin(AsyncWebServer *server);
  		void startManagementServer(const char *ssid);
		String getHostname();
		String getSSID();
		int8_t getRSSI();
		IPAddress getIP();
		bool connectToWifi();
		bool isConnected();
		void check();

	private:

		AsyncWebServer *_server = nullptr;

		DNSServer dnsServer;
		Configuration _config;

		bool _connected;

		int _reconnectIntervalCheck;
		int _connectionTimeout;

		String _networks;
		String _hostname;
		String _ssid;

		IPAddress _ip;

		unsigned long _nextReconnectCheck;

		String getAvailableNetworks();

		bool waitForConnection();
		void serveDefaultUI();
		bool acceptsCompressedResponse(AsyncWebServerRequest *request);
};

extern WifiManagerClass WifiManager;

#endif
