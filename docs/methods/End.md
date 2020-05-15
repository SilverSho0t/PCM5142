# PCM5142.End

public void **End**(void);

## Description

Closes the communication between the library and the device with a Wire.end() .

```c++
#include <PCM5142.h>

PCM5142 dac = PCM5142(0x4C);
bool commOpened = false;

void setup()
{
	dac.Begin();
	commOpened = true;
}

void loop()
{
	delay(5000);

	if(commOpened)
	{
		dac.End();
		commOpened = false;
	}
}
```