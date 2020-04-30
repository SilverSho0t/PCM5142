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

class PCM5142
{
	public:
		PCM5142(TwoWire& wire = Wire, uint8_t slaveAddress = 0x4C);
		~PCM5142();
		
		// Any page
		void selectPage(uint8_t page);							// Register 0 : Page Select
		
		// Page 0
		void reset(void);									// Register 1 : Reset Modules & Registers
		void reset(bool registers, bool modules = false);	// Register 1 : Reset Registers / Modules
		void power(void);
		void mute(bool channels);							// Register 3 : Mute Left & Right Channel
		void mute(bool left, bool right);					// Register 3 : Mute Left / Right Channel
		void PLL(void);
		
		void selectDSPProgram(uint8_t p);					// Register 43 : DSP Program Selection
		
		void setVolumeControl(uint8_t t);					// Register 60 : Digital Volume Control
		void setVolume(uint8_t v);							// Set the volume in function of register 60
		void setVolume(uint8_t left, uint8_t right);		// Set the volume of both registers
		void setVolumeLeft(uint8_t v);						// Register 61 : Left Digital Volume
		void setVolumeRight(uint8_t v);						// Register 62 : Right Digital Volume
		
		// Page 1
		
		
		
		// DSP
		void setDSPUserProgram(void);		// Upload the user program into the RAM
		
		// I²C functions
		int readRegister(uint8_t address);
		int readRegisters(uint8_t address, uint8_t* data, size_t length);
		int writeRegister(uint8_t address, uint8_t value);
		//int writeRegisters(uint8_t address, uint8_t* data, size_t length);
	
	private:
		TwoWire* _wire;
		uint8_t _slaveAddress;
		uint8_t _page;
		uint8_t _volControl;
};