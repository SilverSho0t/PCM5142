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

PCM5142::PCM5142(uint8_t slaveAddress /* = 0x4C */, TwoWire& wire /* = Wire */):
_wire(&wire),
_slaveAddress(slaveAddress)
{
}

PCM5142::~PCM5142()
{
}

void PCM5142::begin(void)
{
	// Start I2C
	_wire->begin();

	// Synchronise page variable between the library and the component
	_page = 1;
	selectPage(0);
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
		setPowerMode(true);

	selectPage(0);
	writeRegister(1, (modules << 4) + registers);

	if (modules)
		setPowerMode(false);
}

void PCM5142::setPowerMode(bool standby, bool powerdown /*= false*/)
{
	selectPage(0);
	writeRegister(2, (standby << 4) + powerdown);
}

uint8_t PCM5142::getPowerMode(void)
{
	selectPage(0);
	return readRegister(2);
}

void PCM5142::mute(bool channels)
{
	mute(channels, channels);
}

void PCM5142::mute(bool left, bool right)
{
	selectPage(0);
	writeRegister(3, (left << 4) + right);
}

void PCM5142::PLL(void)
{
	// To be developed later (to use 3-Wire PCM)
}

/*	Register 7 : De-Emphasis & SDOUT Select
 *
 *	De-Emphasis Enable
 *	This bit enables or disables the de-emphasis filter. The default coefficients are for 44.1kHz sampling rate, but
 *	can be changed by reprogramming the appropriate coeffients in RAM
 *	Default value: xxx0 xxxx
 *	0: De-emphasis filter is disabled
 *	1: De-emphasis filter is enabled
 *
 *	SDOUT Select
 *	This bit selects what is being output as SDOUT via GPIO pins.
 *	Default value: xxxx xxx0
 *	0: SDOUT is the DSP output (post-processing)
 *	1: SDOUT is the DSP input (pre-processing)
 */

void PCM5142::deEmphasisEnable(bool enable)
{
	selectPage(0);
	writeRegister(7, enable << 4);
}

void PCM5142::SDOUTMode(bool mode)
{
	selectPage(0);
	writeRegister(7, mode);
}

/*	Register 34 : 16x Interpolation & FS Speed Mode
 *
 *	16x Interpolation
 *	This bit enables or disables the 16x interpolation mode
 *	Default value: 0
 *	0: 8x interpolation
 *	1: 16x interpolation
 *	
 *	FS Speed Mode
 *	These bits select the FS operation mode, which must be set according to the current audio sampling rate.
 *	These bits are ignored in clock auto set mode
 *	Default value: 00
 *	00: Single speed (FS ≤ 48 kHz)
 *	01: Double speed (48 kHz < FS ≤ 96 kHz)
 *	10: Quad speed (96 kHz < FS ≤ 192 kHz)
 *	11: Octal speed (192 kHz < FS ≤ 384 kHz)
 */

void PCM5142::interpolation16x(bool enable)
{
	selectPage(0);
	writeRegister(34, enable << 4);
}

/*	Register 40 : I2S Data Format & Word Length
 *
 *	I2S Data Format
 *	These bits control both input and output audio interface formats for DAC operation.
 *	Default value: xx00 xxxx
 *	00: I2S
 *	01: TDM/DSP
 *	10: RTJ
 *	11: LTJ
 *
 *	I2S Word Length
 *	These bits control both input and output audio interface sample word lengths for DAC operation.
 *	Default value: xxxx xx10
 *	00: 16 bits
 *	01: 20 bits
 *	10: 24 bits
 *	11: 32 bits
 */

void PCM5142::I2SConfig(uint8_t dataFormat, uint8_t wordLength)
{
	selectPage(0);
	writeRegister(40, (dataFormat << 4) + wordLength);
}

/*	Register 43 : DSP Program Selection
 *	These bits select the DSP program to use for audio processing.
 *	Default value: xxx0 0001
 *	00000: Reserved (do not set)
 *	00001: 8x/4x/2x FIR interpolation filter with de-emphasis
 *	00010: 8x/4x/2x Low latency IIR interpolation filter with de-emphasis
 *	00011: High attenuation x8/x4/x2 interpolation filter with de-emphasis
 *	00100: Reserved
 *	00101: Fixed process flow with configurable parameters
 *	00110: Reserved (do not set)
 *	00111: 8x Ringing-less low latency FIR interpolation filter without de-emphasis
 *	11111: User program in RAM (only PCM5141 & PCM5142) else Reserved (do not set)
 *	others: Reserved (do not set)
 */

void PCM5142::selectDSPProgram(uint8_t program)
{
	selectPage(0);
	writeRegister(43, program);
}

/*	Register 60 : Digital Volume Control
 *	These bits control the behavior of the digital volume.
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

// This function is useful only for PCM5141 & PCM5142 DACs
void PCM5142::setDSPUserProgram(reg_value program[], uint16_t programSize, reg_value miniDSP_D[], uint16_t miniDSP_DSize)
{
	for (int i = 0; i < programSize; i++)
	{
		if (program[i].reg_off == 255)	// When reg_off = 255 we transmit miniDSP_D registers
		{
			for (int j = 0; j < miniDSP_DSize; j++)
			{
				writeRegister(miniDSP_D[j].reg_off, miniDSP_D[j].reg_val);
			}
		}
		else
			writeRegister(program[i].reg_off, program[i].reg_val);
	}
}

uint8_t PCM5142::readRegister(uint8_t address)
{
	uint8_t value;

	if (readRegisters(address, &value, sizeof(value)) != 1)
		return -1;

	return value;
}

uint8_t PCM5142::readRegisters(uint8_t address, uint8_t* data, size_t length)
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

uint8_t PCM5142::writeRegister(uint8_t address, uint8_t value)
{
	_wire->beginTransmission(_slaveAddress);
	_wire->write(address);
	_wire->write(value);

	if (_wire->endTransmission() != 0)
		return 0;

	return 1;
}