# PCM5142.DACMode

public void **DACMode**(uint8_t **mode**);

## Description

Sets the DAC architecture to vary the DAC auditory signature. Controls the register 121, page 0.

Default register value: 0<br>
0: Mode1 - New hyper-advanced current-segment architecture<br>
1: Mode2 - Classic PCM1792 advanced current-segment architecture

```c++
#include <PCM5142.h>

PCM5142 dac = PCM5142(0x4C);

void setup()
{
	dac.Begin();
	dac.DACMode(1);	// Sets the DAC into Classic PCM1792 mode.
}

void loop()
{}
```