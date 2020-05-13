# PCM512x / PCM514x documentation

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

| PART NUMBER | PROCESSING | DYNAMIC RANGE | SNR | THD |
|:---:|:---:|:---:|:---:|:---:|
| [PCM5121](http://www.ti.com/lit/ds/symlink/pcm5121.pdf)  | Fixed-Function Processing (EQ, DRC) | 106 dB | 106 dB | –92 dB |
| [PCM5122](http://www.ti.com/lit/ds/symlink/pcm5122.pdf)  | Fixed-Function Processing (EQ, DRC) | 112 dB | 112 dB | –93 dB |
| [PCM5141](http://www.ti.com/lit/ds/symlink/pcm5141.pdf)  | Programmable miniDSP | 106 dB | 106 dB | –92 dB |
| [PCM5142](http://www.ti.com/lit/ds/symlink/pcm5142.pdf)  | Programmable miniDSP | 112 dB | 112 dB | –93 dB |

## Properties

| Name | Description |
|:-------------|:------------------|
| [&#95;wire](wire)  | Content Cell  |
| [&#95;slaveAddress](slaveAddress.md)  | Content Cell  |
| [&#95;page](url)  | Content Cell  |
| [&#95;volControl](url)  | Content Cell  |

## Constructors

| Name | Description |
|:-------------|:------------------|
| [PCM5142](url)  | Content Cell |

## Public Methods

| Name | Description |
|:-------------|:------------------|
| [Begin](url)  | Content Cell |
| [End](url)  | Content Cell |
| [SelectPage](url)  | Content Cell |
| [Reset](url)  | Content Cell |
| [PowerMode](url)  | Content Cell |
| [Reset](url)  | Content Cell |
| [Mute](url)  | Content Cell |
| [DeEmphasisEnable](url)  | Content Cell |
| [SDOUTMode](url)  | Content Cell |
| [Interpolation16x](url)  | Content Cell |
| [SDOUTMode](url)  | Content Cell |
| [I2SConfig](url)  | Content Cell |
| [SDOUTMode](url)  | Content Cell |
| [SelectDSPProgram](url)  | Content Cell |
| [SetVolumeControl](url)  | Content Cell |
| [SetVolume](url)  | Content Cell |
| [SetVolumeLeft](url)  | Content Cell |
| [SetVolumeRight](url)  | Content Cell |
| [DSPBootDoneFlag](url)  | Content Cell |
| [PowerState](url)  | Content Cell |
| [DACMode](url)  | Content Cell |
| [SetDSPUserProgram](url)  | Content Cell |
| [ReadRegister](url)  | Content Cell |
| [ReadRegisters](url)  | Content Cell |
| [WriteRegister](url)  | Content Cell |
