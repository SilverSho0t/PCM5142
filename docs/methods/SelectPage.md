# PCM5142.SelectPage

void **SelectPage**(uint8_t **page**);

## Description

Selects the page to which you will modify registers.

```c++
#include <PCM5142.h>

PCM5142 dac = PCM5142(0x4C);

void setup()
{
	dac.Begin();
	dac.SelectPage(1);				// Selects page 1
	dac.WriteRegister(2, 0x11);		// Writes 0x11 into register 2 from page 1.
}

void loop()
{}
```