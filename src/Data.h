#pragma once
#include <Arduino.h>

static const uint8_t gzip[]  PROGMEM = {};
static const char    html[]  PROGMEM = "<html><body><p>No embedded UI. Please upload filesystem.</p></body></html>";
static const int gzipBytes = 0;
static const int htmlBytes = sizeof(html) - 1;
