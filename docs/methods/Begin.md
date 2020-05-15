# PCM5142.Begin

public void **Begin**(void);

## Description

Initialises the library with the device with a Wire.begin(), selects page 0 and selects the volume behaviour to 0 (see [SetVolumeControl()](SetVolumeControl)).

```c++
#include <PCM5142.h>

PCM5142 dac = PCM5142(0x4C);

void setup()
{
	dac.Begin();
}

void loop()
{}
```