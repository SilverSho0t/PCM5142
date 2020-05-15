# PCM5142.PowerMode

void **PowerMode**(bool **standby**, bool **powerdown** = false);

## Description

Sets a power mode, request standby or powerdown.

#### Standby Request
When this bit is set, the DAC will be forced into a system standby mode, which is also the mode the system enters in the case of clock errors. In this mode, most subsystems will be powered down but the charge pump and digital power supply.

Default register value: 0 (false)<br>
false: Normal operation<br>
true: Standby mode

#### Powerdown Request
When this bit is set, the DAC will be forced into powerdown mode, in which the power consumption would be minimum as the charge pump is also powered down. However, it will take longer to restart from this mode. This mode has higher precedence than the standby mode, that is, setting this bit along with bit 4 for standby mode will result in the DAC going into powerdown mode.

Default register value: 0 (false)<br>
false: Normal operation<br>
true: Powerdown mode


```c++
#include <PCM5142.h>

PCM5142 dac = PCM5142(0x4C);

void setup()
{
	dac.Begin();
	// Puts the DAC into standby mode.
	dac.PowerMode(true);

	// Change registers that need DAC in standby mode.

	// Puts the DAC into normal mode.
	dac.PowerMode(false);
}

void loop()
{}
```

```c++
#include <PCM5142.h>

PCM5142 dac = PCM5142(0x4C);

void setup()
{
	dac.Begin();

	// Puts the DAC into powerdown mode to save power.
	dac.PowerMode(false, true);
}

void loop()
{}
```