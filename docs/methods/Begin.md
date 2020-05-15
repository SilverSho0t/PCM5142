# PCM5142 documentation

## PCM5142.Begin

public void **Begin**(void);

### Description

Initialises the library with the device by a Wire.begin(), selecting page 0 and selecting the volume behaviour to 0 (see [SetVolumeControl()](SetVolumeControl)).

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