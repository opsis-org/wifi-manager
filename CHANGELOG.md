# Changelog

## 2.1.2

- Updated `getSSID()` to return the soft AP SSID if the management server is started

## 2.1.1

- Updated `getLocalIP()` to `getIP()` to support both local and soft AP IP addresses

## 2.1.0

- Added `getLocalIP()` as a utility method

## 2.0.0

- The WifiManager is now more in line with other Arduino libraries, and there is no need to instantiate it on your own
- Added a few utility methods that should speak for themselves:
  - `getSSID()` returns the configured SSID
  - `getRSSI()` returns the signal strength for the currently connected wifi
  - `getHostname()` returns the configured hostname
  - `isConnected()` tells you if you are currently connected or not
- Fixed issue in manager UI if it could not load any networks
- Fixed issue in manager UI if the client could not save configuration
- Fixed issue with SPIFFS if you started the Management Server without attempting to connect to the wifi first.

## 1.0.3

- Fixed issue with mDNS in newer version of espressif32.

## 1.0.2

- Fixed issue with hostname not being set correctly on the newest version of the espressif32 platform due to a bug in `<WiFi.h>`.

## 1.0.1

- Updated dependency of `me-no-dev/ESP Async WebServer@^1.2.3` to `esphome/ESPAsyncWebServer-esphome@^3.0.0` as the latest release on PlatformIO is currently not compiling on expressif > 3.5.0.

## 1.0.0

- Initial release
