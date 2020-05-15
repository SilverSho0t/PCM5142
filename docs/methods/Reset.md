# PCM5142.Reset

void **Reset**(void);

void **Reset**(bool **registers**, bool **modules** = false);

## Description

Resets modules or/and registers.

#### Reset Registers
This bit resets the mode registers back to their initial values. The RAM content is not cleared, but the execution
source will be back to ROM. This bit is auto cleared and must be set only when the DAC is in standby mode
(resetting registers when the DAC is running is prohibited and not supported).

Default register value: 0

false: Normal

true:  Reset mode registers

#### Reset Modules
This bit resets the interpolation filter and the DAC modules. Since the DSP is also reset, the coeffient RAM
content will also be cleared by the DSP. This bit is auto cleared and can be set only in standby mode.

Default register value: 0

false: Normal

true:  Reset modules

```c++
#include <PCM5142.h>

PCM5142 dac = PCM5142(0x4C);

void setup()
{
	dac.Begin();
}

void loop()
{
	if (/* */)
	{
		// Resets both registers & modules.
		dac.Reset();

		// Resets only registers.
		dac.Reset(true);

		// Resets only modules.
		dac.Reset(false, true);
	}
}
```