#pragma once

#if defined(ESP32)
	#include "src/hardware/Freematics/Freematics ONEPlus model B/freematics.h"
//#elif defined(ESP32C3)
//	#include "src/hardware/Freematics/Freematics ONEPlus model ?/freematics.h"
#elif defined(ARDUINO_ARCH_AVR)
	#include "src/hardware/Freematics/Freematics ONE/hardware.h"
#else
	#error "Unknown Freematics model"
#endif
