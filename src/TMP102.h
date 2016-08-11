#ifndef TMP102_h
#define TMP102_h

#if defined(ARDUINO) && ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif
#include <Wire.h>
class TMP102
{
	public:
		TMP102(byte adbegindress);	// Initialize TMP102 sensor at given address
		float readTempC(void);	// Returns the temperature in degrees C
		float readTempF(void);	// Converts readTempC result to degrees F
		void sleep(void);	// Switch sensor to low power mode
		void wakeup(void);	// Wakeup and start running in normal power mode
		bool alert(void);	// Returns state of Alert register
		void setLowTempC(float temperature);  // Sets T_LOW (degrees C) alert threshold
		void setHighTempC(float temperature); // Sets T_HIGH (degrees C) alert threshold
		void setLowTempF(float temperature);  // Sets T_LOW (degrees F) alert threshold
		void setHighTempF(float temperature); // Sets T_HIGH (degrees F) alert threshold
		float readLowTempC(void);	// reads T_LOW register in C
		float readHighTempC(void);	// reads T_HIGH register in C
		float readLowTempF(void);	// reads T_LOW register in F
		float readHighTempF(void);	// reads T_HIGH register in F
		
		// Set the conversion rate (0-3)
		// 0 - 0.25 Hz
		// 1 - 1 Hz
		// 2 - 4 Hz (default)
		// 3 - 8 Hz
		void setConversionRate(byte rate);
		
		// Enable or disable extended mode
		// 0 - disabled (-55C to +128C)
		// 1 - enabled  (-55C to +150C)
		void setExtendedMode(bool mode);
		
		// Set the polarity of Alert
		// 0 - Active LOW
		// 1 - Active HIGH
		void setAlertPolarity(bool polarity); 
		
		// Set the number of consecutive faults
		// 0 - 1 fault
		// 1 - 2 faults
		// 2 - 4 faults
		// 3 - 6 faults
		void setFault(byte faultSetting);
		
		// Set Alert type
		// 0 - Comparator Mode: Active from temp > T_HIGH until temp < T_LOW
		// 1 - Thermostat Mode: Active when temp > T_HIGH until any read operation occurs
		void setAlertMode(bool mode);
		
	private:
		int _address; // Address of Temperature sensor (0x48,0x49,0x4A,0x4B)
		void openPointerRegister(byte pointerReg); // Changes the pointer register
		byte readRegister(bool registerNumber);	// reads 1 byte of from register
};


#endif