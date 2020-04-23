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
		
		void reset(void);
		void power(void);
		void mute(void);
		void PLL(void);
		
		void setVolume(uint8_t v);
		void setVolumeRight(uint8_t v);
		void setVolumeLeft(uint8_t v);
		
		void setDSPUserProgram(void);
		
		// I²C functions
		int readRegister(uint8_t address);
		int readRegisters(uint8_t address, uint8_t* data, size_t length);
		int writeRegister(uint8_t address, uint8_t value);
		//int writeRegisters(uint8_t address, uint8_t* data, size_t length);
	
	private:
		TwoWire* _wire;
		uint8_t _slaveAddress;
		uint8_t _page;
};