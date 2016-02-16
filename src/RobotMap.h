#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

// motors
const int LEFTMOTOR = 3;
const int RIGHTMOTOR = 4;

// sensors
// Ultrasonic: refer to datasheet: http://maxbotix.com/documents/LV-MaxSonar-EZ_Datasheet.pdf
const int ULTRASONIC_ANI_PORT = 5;
const float VCC = 5.0f;
const float ULTRASONIC_SCALEFACTOR = VCC/1024.0f;
const float ULTRASONIC_READING_TO_INCH = 1.6f;

// conversion
const double METER_TO_INCH = 0.0254;
const double INCH_TO_METER = 1/METER_TO_INCH;
const double METER_TO_CM = 0.01;
const double CM_TO_METER = 1/METER_TO_CM;

#endif
