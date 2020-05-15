# PCM5142 documentation

## Description
This library is meant to ease the programming of PCM512x/PCM514x family devices.

The PCM512x/PCM514x devices are a family of monolithic CMOS-integrated circuits that include a stereo digital-to-analog converter and additional support circuitry in a small TSSOP package. The PCM512x/PCM514x uses the latest generation of TI’s advanced segment-DAC architecture to achieve excellent dynamic performance and improved tolerance to clock jitter.

Members of the PCM512x family integrate preset audio processing functions with programmable coefficients, allowing developers to change the characteristics of the interpolation filter, speaker EQ, dynamic range controls, and average volume control in their products.

Members of the PCM514x family integrate a fully programmable miniDSP core, allowing developers to integrate filters, dynamic range controls, custom interpolators, and other differentiating features to their products.

The PCM512x/PCM514x provides 2.1-VRMS ground centered outputs, allowing designers to eliminate DC-blocking capacitors on the output, as well as external muting circuits traditionally associated with single-supply line drivers.

The integrated line driver surpasses all other charge pump-based line drivers by supporting loads down to 1 kΩ, allowing the PCM512x/PCM514x to drive up to 10 products in parallel, such as LCD TV, DVDR, and AV receivers.

The integrated PLL on the device removes the requirement for a system clock (commonly known as master clock), allowing a 3-wire I
2S connection and reducing system EMI.

## Compatibility

| PART<br>NUMBER | PROCESSING | DYNAMIC<br>RANGE | SNR | THD |
|:---:|:---:|:---:|:---:|:---:|
| [PCM5121](http://www.ti.com/lit/ds/symlink/pcm5121.pdf)  | Fixed-Function Processing (EQ, DRC) | 106 dB | 106 dB | –92 dB |
| [PCM5122](http://www.ti.com/lit/ds/symlink/pcm5122.pdf)  | Fixed-Function Processing (EQ, DRC) | 112 dB | 112 dB | –93 dB |
| [PCM5141](http://www.ti.com/lit/ds/symlink/pcm5141.pdf)  | Programmable miniDSP | 106 dB | 106 dB | –92 dB |
| [PCM5142](http://www.ti.com/lit/ds/symlink/pcm5142.pdf)  | Programmable miniDSP | 112 dB | 112 dB | –93 dB |

## Properties

| Name | Description |
|:-------------|:------------------|
| [&#95;wire](properties/wire)  | TwoWire from Wire.h library (Wire, Wire1...). |
| [&#95;slaveAddress](properties/slaveAddress)  | The I²C address of the device. |
| [&#95;page](properties/page)  | The selected page. |
| [&#95;volControl](properties/volControl)  | The behavior of the digital volume. |

## Constructors

| Name | Description |
|:-------------|:------------------|
| [PCM5142](constructors/PCM5142)  | Creates a new PCM5142. |

## Public Methods

| Name | Description |
|:-------------|:------------------|
| [Begin](methods/Begin)  | Initialises the library with the device. |
| [End](methods/End)  | Closes the communication between the library and the device. |
| [SelectPage](methods/SelectPage)  | Selects the page to which you will modify registers. |
| [Reset](methods/Reset)  | Resets modules or/and registers. |
| [PowerMode](methods/PowerMode)  | Sets a power mode, request standby or powerdown. |
| [Mute](methods/Mute)  | Enables or disables the mute mode. |
| [DeEmphasisEnable](methods/DeEmphasisEnable)  | Enables or disables the de-emphasis filter. |
| [SDOUTMode](methods/SDOUTMode)  | Selects what is being output as SDOUT via GPIO pins. |
| [Interpolation16x](methods/Interpolation16x)  | Enables or disables the 16x interpolation mode. |
| [I2SConfig](methods/Interpolation16x)  | Sets input and output audio interface formats and sample word lengths. |
| [SelectDSPProgram](methods/SelectDSPProgram)  | Selects the DSP program to use for audio processing. |
| [SetVolumeControl](methods/SetVolumeControl)  | Sets the behavior of the digital volume. |
| [SetVolume](methods/SetVolume)  | Sets the digital volume depending of the behavior selected. |
| [SetVolumeLeft](methods/SetVolumeLeft)  | Sets the left channel digital volume. |
| [SetVolumeRight](methods/SetVolumeRight)  | Sets the right channel digital volume. |
| [FSSpeedMode](methods/FSSpeedMode) | Returns the actual FS operation mode being used. |
| [DSPBootDone](methods/DSPBootDone)  | Returns whether the DSP boot is completed. |
| [PowerState](methods/PowerState)  | Returns the current power state of the DAC. |
| [DACMode](methods/DACMode)  | Sets the DAC architecture to vary the DAC auditory signature. |
| [SetDSPUserProgram](methods/SetDSPUserProgram)  | Sets the miniDSP program (only PCM514x family). |
| [ReadRegister](methods/ReadRegister)  | Returns the value of a specific register. |
| [ReadRegisters](methods/ReadRegisters)  | Returns the value of multiples registers. |
| [WriteRegister](methods/WriteRegister)  | Sets the value of a specific register. |
