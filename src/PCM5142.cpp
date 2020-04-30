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

#include "PCM5142.h"

PCM5142::PCM5142(TwoWire& wire /* = Wire */, uint8_t slaveAddress /* = 0x4C */)
{
	// To complete
}

void PCM5142::selectPage(uint8_t page)
{
	if (page == _page)	// Check if the page is already selected
		return;
		
	writeRegister(0, page);
	_page = page;
}

void PCM5142::reset(void)
{
	reset(true, true);
}

void PCM5142::reset(bool registers, bool modules /*= false*/)
{
	if (modules)
		// POWER_MODE_STANDBY
		
	selectPage(0);
	writeRegister(1, modules << 4 + registers);
	
	if (modules)
		// POWER_MODE_ACTIVE
}

void PCM5142::mute(bool channels)
{
	mute(channels, channels);
}

void PCM5142::mute(bool left, bool right)
{
	selectPage(0);
	writeRegister(3, left << 4 + right);
}

/*	Register 43 : DSP Program Selection *	These bits select the DSP program to use for audio processing.
 *	Default value: 00001
 *	00000: Reserved (do not set)
 *	00001: 8x/4x/2x FIR interpolation filter with de-emphasis
 *	00010: 8x/4x/2x Low latency IIR interpolation filter with de-emphasis
 *	00011: High attenuation x8/x4/x2 interpolation filter with de-emphasis
 *	00100: Reserved
 *	00101: Fixed process flow with configurable parameters
 *	00110: Reserved (do not set)
 *	00111: 8x Ringing-less low latency FIR interpolation filter without de-emphasis
 *	11111: User program in RAM
 *	others: Reserved (do not set)
 */

void PCM5142::selectDSPProgram(uint8_t p)
{
	
}

/*	Register 60 : Digital Volume Control *	These bits control the behavior of the digital volume.
 *	Default value: xxxx xx00
 *	00: The volume for Left and right channels are independent
 *	01: Right channel volume follows left channel setting
 *	10: Left channel volume follows right channel setting
 *	11: Reserved (The volume for Left and right channels are independent)
 */

void PCM5142::setVolumeControl(uint8_t t)
{
	selectPage(0);
	writeRegister(60, t);
	_volControl = t;
}

void PCM5142::setVolume(uint8_t v)
{
	switch (_volControl)
	{
		case 0:
			setVolumeRight(v);
			setVolumeLeft(v);
			break;
		case 1:
			setVolumeLeft(v);
			break;
		case 2:
			setVolumeRight(v);
			break;
		default:
			setVolumeRight(v);
			setVolumeLeft(v);
			break;
	}
}

void PCM5142::setVolume(uint8_t left, uint8_t right)
{
	setVolumeRight(left);
	setVolumeLeft(right);
}

void PCM5142::setVolumeLeft(uint8_t v)
{
	selectPage(0);
	writeRegister(61, v);
}

void PCM5142::setVolumeRight(uint8_t v)
{
	selectPage(0);
	writeRegister(62, v);
}

int PCM5142::readRegister(uint8_t address)
{
	uint8_t value;
	
	if (readRegisters(address, &value, sizeof(value)) != 1)
		return -1;
	
	return value;
}

int PCM5142::readRegisters(uint8_t address, uint8_t* data, size_t length)
{
	_wire->beginTransmission(_slaveAddress);
	_wire->write(address);

	if (_wire->endTransmission(false) != 0)
		return -1;

	if (_wire->requestFrom(_slaveAddress, length) != length)
		return 0;

	for (size_t i = 0; i < length; i++)
		*data++ = _wire->read();
	
	return 1;
}

int PCM5142::writeRegister(uint8_t address, uint8_t value)
{
	_wire->beginTransmission(_slaveAddress);
	_wire->write(address);
	_wire->write(value);
	
	if (_wire->endTransmission() != 0)
		return 0;
	
	return 1;
}