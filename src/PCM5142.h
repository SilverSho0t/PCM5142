/*
	This file is part of the PCM5142 library.
	Copyright (C) 2020  Sean RAMAGET. All rights reserved.

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef PCM5142_H
#define PCM5142_H

#include <Arduino.h>
#include <Wire.h>

// Variables types added to support PurePath Studio generated header file.
typedef uint8_t u8;
typedef String string;

//INSTRUCTIONS & COEFFICIENTS
typedef struct {
    u8 reg_off;
    u8 reg_val;
} reg_value;

class PCM5142
{
	public:
		PCM5142(uint8_t slaveAddress = 0x4C, TwoWire& wire = Wire);
		~PCM5142();

		void begin(void);

		// Any page
		void selectPage(uint8_t page);						// Register 0 : Page Select

		// Page 0
		void reset(void);											// Register 1 : Reset Modules & Registers
		void reset(bool registers, bool modules = false);			// Register 1 : Reset Registers / Modules
		void setPowerMode(bool standby, bool powerdown = false);	// Register 2 : Set Standby & Powerdown Mode
		uint8_t getPowerMode(void);									// Register 2 : Get Standby & Powerdown Mode
		void mute(bool channels);									// Register 3 : Mute Left & Right Channel
		void mute(bool left, bool right);							// Register 3 : Mute Left / Right Channel

		void PLL(void);												// To be developed later (to use 3-Wire PCM)

		void deEmphasisEnable(bool enable);							// Register 7 : De-Emphasis
		void SDOUTMode(bool mode);									// Register 7 : SDOUT Select
		void interpolation16x(bool enable);							// Register 34 : Enables or disables the 16x interpolation mode
		void I2SConfig(uint8_t dataFormat, uint8_t wordLength);		// Register 40 : Configure I2S Data Format & Word Length
		void selectDSPProgram(uint8_t program);						// Register 43 : DSP Program Selection

		void setVolumeControl(uint8_t t);					// Register 60 : Digital Volume Control
		void setVolume(uint8_t v);							// Set the volume in function of register 60
		void setVolume(uint8_t left, uint8_t right);		// Set the volume of both registers
		void setVolumeLeft(uint8_t v);						// Register 61 : Left Digital Volume
		void setVolumeRight(uint8_t v);						// Register 62 : Right Digital Volume

		// Page 1


		// DSP
		void setDSPUserProgram(reg_value program[], uint16_t programSize, reg_value miniDSP_D[], uint16_t miniDSP_DSize);	// Upload the user program into the RAM

		// I²C functions
		uint8_t readRegister(uint8_t address);
		uint8_t readRegisters(uint8_t address, uint8_t* data, size_t length);
		uint8_t writeRegister(uint8_t address, uint8_t value);
		//int writeRegisters(uint8_t address, uint8_t* data, size_t length);

	private:
		TwoWire* _wire;
		uint8_t _slaveAddress;
		uint8_t _page;
		uint8_t _volControl;
};

#endif