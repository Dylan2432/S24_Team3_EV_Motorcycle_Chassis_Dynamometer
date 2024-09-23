## Functionality ##
This subsystem is to supply the current to the motor windings for DC injection braking used in the braking subsystem. The user will be able to change the amount of current that is entered into the motor winding. It will have a power supply going into a buck converter and the current will change depending on the duty cycle of the MOSFET which is used as a switch. The user will set the duty cycle, this will cause the current to increase as the duty cycle decreases and to decrease as the duty cycle increases.

## Constraints ##
| No. | Constraints                                                                                     | Origin           |
|-----|-------------------------------------------------------------------------------------------------|------------------|
| 1   | Current entering the motor winding must not exceed 18.4375 amps       | Design Constraint |
| 2   | Must be controlled from the user interface       | Design Constraint |
| 3   | Inductors, diodes, and MOSFETs must be able to withstand a current of 16.867A | Derived from further considerations|
| 4   | Comply with all relevant codes and standards listed in II. Ethical, Professional, and Standard Considerations. | Safey Constraint|

1. This value is based off adding 150% of 125% of the FLA of the motor of 5.9. There is risk of damanging the motor if this value is exceeded.
2. It must be able change the voltage or current from the user interface. This will increase safety as the user is further away from high amperage of the buck converter.
3. This is the max amount of current that will go through the inductor, diode, and MOSFET. This value wil be further disccussed in the analysis portion.
4. One example that must be folowed is NEC 310-16 ampacity chart to ensure proper wiring for the amount of current in the circuit

## Schematics ##
![image](https://github.com/user-attachments/assets/fbb07980-043c-487d-84ad-926ddbfc3433)
Above: Kicad Schematic

![image](https://github.com/user-attachments/assets/a9cbadcb-280a-4191-81de-70f3ccde1b3e)
Above: Arduino Nano pinout, PWM pins have the ~ symbol.
![image](https://github.com/user-attachments/assets/0bee9599-cdb0-42a9-aacf-5edecf995067)
Above: Arduino Nano Screw Terminal board

## Analysis ##
The basic operation of a buck converter is when the switch is closed the inductor is charged and no current flows through the diode. Then the switch is opened and the inductor acts as the source and goes through a loop through the diode until the switch is closed again.

![image](https://github.com/user-attachments/assets/0b3d8e39-7646-40e5-ba88-f462739e8e50)

Above: Basic Topology of Buck Converte

The equations used to determine componet sizes are from Texas instruments.[1]
We have a 48V, 2.2A source which we want to convert to a 14.667A output to enter in the motor winding. The duty cycle to acclompish this can be found from the following equation.

![image](https://github.com/user-attachments/assets/3f942d3a-56f7-4a8a-b1da-2f5377b715fa)

Where we will assume our efficieny, n, is 0.9 which Texas Instruments says is not unrealistic for a worst-case efficiency.
If Vout is 7.2V, Vin is 48V, and efficiency is 0.9 we have duty cycle of 16.667%. From conservation of energy Pin = Pout and since the input power is known and output voltage is known we can calcutlate the output current is 14.667A. This value will not be the same in reality due to losses but it will be close to accurate.

Then we will calculate the miniumum inductor value from the following equation.

![image](https://github.com/user-attachments/assets/6e7dd296-8e95-4f80-9bec-443e3aed6dd6)

The delta I_L, which is the inductor ripple current, can be estimated to 30% of the output current and using a frequency of 62.5kHz we arrive at a minimum inductance value of 22.25 microhenry. We used a 33 microhenry inductor which is above the minimum value calculated.

To determine the maximum current that will flow through our inductor, diode, and MOSFET we will use the following equation.

![image](https://github.com/user-attachments/assets/0e9f3d6f-bbc1-45b6-9098-384231be1b52)

This gives us a value of 16.867A and the componets must be sized to handle this current and the componets chosen will be atleast 10% above this value.

To determine minimum output capacitor size the following equation is used.

![image](https://github.com/user-attachments/assets/18530d12-b568-4f79-8055-58f700e772a3)

Allowing for the voltage ripple to be 100mV the minimum capacitor size is 88 microfarad. As the output capacitor size increases the amount of voltage ripple will decrease.

To determine the minimum input capacitor size the following equation is used. [2]

![image](https://github.com/user-attachments/assets/ac1dcf1c-0487-4b38-8588-cf4adbfbc5b9)

Having the input votlage ripple to be 100mV we have minimum input capacitor size of 135.8 microfarad.

To assist with power dissipation in the diodes two Schtokky diodes in paralle were used. The forward voltage is 0.87 which causes the power dissipation to be (16.871/2)*(0.87) = 7.34W.

The arduino nano was chosen as it allows for 5V, 8 bit PWM on each PWM pin. Since the clock is 16Mhz, an 8 bit PWM resolution allows for a frequency of 62.5kHz. The 8 bit PWM allows for a duty cycle resolution 0.4% which will allow for greater control.

To simulate the circuit LTSPICE was used.
![image](https://github.com/user-attachments/assets/4c7abf01-b275-4a39-b53e-95024253f314)

At 50% duty cycle, the expected current value would be 4.4A. The measured value in LTSPICE was 4.38A
![image](https://github.com/user-attachments/assets/708589d6-56dd-4017-99c4-d0bf7ba198e3)
At 75% duty cycle the expected current value would be 2.93A. The measure value was 2.94A.
![image](https://github.com/user-attachments/assets/e075e0fe-74e8-48ae-b4bb-c3708dbc0fac)
The current values were within 5% of error from a duty cycle of 15% to a duty cycle of 95%. Which allows for a current range of 2.32A - 14.34A.
If we do not want any current applied we can set the duty cycle to 0 as the MOSFET acting as a switch will never close.

### Arduino and User Interface ###
The MOSFET will be switched on and off from PWM of an Arduino Nano with a frequency of 62.5 kHz and a PWM resolution of 8 bits which gives us 256 levels. This allows us to adjust the duty cycle in 0.391% increments.

The user will enter their desired output current at the user interface. This will correlate to a analog voltage output going to the Arduino Nano as an analog input, that input will then set the duty cycle that is outputed to the MOSFET.

The PWM resolution is 8 bits while the pins have 10 bits of resolution when using analogRead() on pins A0-A7.

### PCB Layout and Thermal Considerations ###
Below is some general points for PCB layouts for a Buck Converter from ROHM semiconductor [3]

![image](https://github.com/user-attachments/assets/ac3eb086-f394-4a3e-aebf-cf6d41280ddb)

![image](https://github.com/user-attachments/assets/83d3c8ae-9a5c-4723-a862-5a593f63c849)
Above: PCB layout for buck converter

Altium has a current table to PCB trace width table that says what trace width will limit your temperature rise to 10 °C with 1 oz./sq. ft. copper weight.[4] For the diodes the max amount of current going through one of them would be 8.4335A so a trace width of 260 mils(0.26 inches) or higher would be chosen. Near the indcutor and diodes where there is a larger current and more power dissipation there is larger traces to assit with this problem. We also have thermal vias near diode, inductor, and the MOSFET to help with heat issues.

Below is PCB thermal layout tips for DC/DC converters from texas instruments.

![image](https://github.com/user-attachments/assets/decc18a0-aae9-4269-8bb2-913b2f3d48db)

We will not have a package with DAP. What Texas instruments means by the "pizza" concept is the fact that the heat will go out radially and you want to avoid cuts closer to the device. They provide an image of two layouts and the heat flow between the two to show this concept.

![image](https://github.com/user-attachments/assets/d45433dc-81eb-408f-9b54-76c7e0e26e6a)

We will also place the higher current componets such as the inductor, MOSFET, and diode closer towards the center so there is more area for the heat to spread out radially. However they cannot be too close as too avoid the heat adding together to create a much greater temperature rise.





## BOM (Bill of Materials) ##
| Item                                                          | Manufacturer | Quantity | Price | Total  | Link|
|---------------------------------------------------------------|------------|----------|-------|--------|----|
|TXN 100-148 Power Supply                                        |    TRACO Power    |  2 |      $25.03 | $50.06| https://www.mouser.com/ProductDetail/TRACO-Power/TXN-100-148?qs=iLKYxzqNS776y9pVP5bizw%3D%3D |
|Screw Terminal Block Breakout Module Board for Arduino Nano/Micro  | CZH-LABS | 1|$22.00 |$22.00| https://www.amazon.com/CZH-LABS-Terminal-Breakout-Module-Arduino/dp/B07QMRDZ3W/ref=sr_1_2_sspa?adgrpid=1334807691573188&dib=eyJ2IjoiMSJ9.8CC4qpKPSQ0agWcQH7KiQq6pslDK34qJiQN40Mm7Mt9xeWnIDN63F7FAjTm_uRgeJOiPqUhQgetgc96PCDZo5nokJVXyAEpfzPe44T2rKkC_LdjXKl-PIzdS3okbKXNPRvrlQkBKWBYvhTVaucQGVCqFrn8fMBAiXBuL7pP4CrDCvY-VmOW1RC3xI4PRuVeasVMyRDHn-aeBA8JpMKT3ORDavsckR7N-cufCDvAQyao.P1T0xlBhmBswXsf0Ti42289M2m9GUqygQsNGsZb-Uvg&dib_tag=se&hvadid=83425694871534&hvbmt=be&hvdev=c&hvlocphy=84181&hvnetw=o&hvqmt=e&hvtargid=kwd-83425850018739%3Aloc-190&hydadcr=18918_13351314&keywords=arduino+nano+screw+terminal&msclkid=98c75911be981aa72f9a3ff9c744c3d7&qid=1726511582&sr=8-2-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&psc=1  |
|Arduino Nano                              |    Arduino|    1 |      $25.10| $25.10| https://www.amazon.com/Arduino-A000005-ARDUINO-Nano/dp/B0097AU5OU/ref=sr_1_3?adgrpid=1337006704097302&dib=eyJ2IjoiMSJ9.gA_RBHQKlL9fqee7OwDWKxgWB1jyYqARwwE-oC7y63gBp15lCBXG0l32vuXa9OL8N2Wfh-eQoKuHM-GqguNax9mDWdLEw2tawAr8AvWxw5ovfnzf9MpV2PD6AYq57TXnwbE_r0vvkeAy3f9ZKeKr1h50ugjkAYwgMCrRXxThVtkRbqi6RGdml_f0gTqQe_uJWJGrwXnSLMTMrN3chFTdvfWbF_wqAF9mA1svqnQbA5A.-IHVaQe_UYRcJSZtBbODjokeBYOKvAlWvwO-XZgeOJ0&dib_tag=se&hvadid=83563305678200&hvbmt=be&hvdev=c&hvlocphy=84181&hvnetw=o&hvqmt=e&hvtargid=kwd-83563266643869%3Aloc-190&hydadcr=24663_13770022&keywords=arduino+nano&msclkid=abcba43110de16bd24c0c2d96fd282ae&qid=1726513005&sr=8-3|
|Arduino Nano USB cable| --- |1 | 6.99| 6.99| https://www.amazon.com/DIYables-Mini-Cable-Arduino-Pieces/dp/B0C7BMS5FG/ref=sr_1_3?crid=2KLUXOMWJCHJS&dib=eyJ2IjoiMSJ9.7pcz7_86rIBdMd3JLAsX67MgwNngLcAxc8l5cFDf7CsBp15lCBXG0l32vuXa9OL8QpCq0MRgz4wqpefroCPajl97TRZWGRWEkL9zRS5eroP8DjLQW7D4M7KBMdROu9HjuxGORpw-lKk1dhXeDCftwrVsl5uV5QYtcf10GJTbmeeYCO5JdnR3SbHCskYez4U2XZCYv7w0H8grBuDyjyNQoaMM3cyM3kaM57TPhVHiSMM.Nww5t30L2Xs7vjrUQmt1Ym_K7IYDIf8is3X3ZiHK5SQ&dib_tag=se&keywords=arduino+nano+with+usb&qid=1726512991&sprefix=arduino+nano+with+usb%2Caps%2C117&sr=8-3|
|Inductor 74437529203330                                       |  Wurth Elektronik |       2 |      $9.43 | $18.86|https://www.mouser.com/ProductDetail/Wurth-Elektronik/74437529203330?qs=sGAEpiMZZMv126LJFLh8y%2Ffsm5hBFUvHDaSzuMlV0Gc%3D | 
|Output Capacitor MAL212029101E3                                     |   EPCOS / TDK |       2 |      $5.41 | $10.82| https://www.mouser.com/ProductDetail/EPCOS-TDK/B41858C9227M?qs=sGAEpiMZZMsh%252B1woXyUXj1SPYG7TfWbY3M%252BRTBa2uXQ%3D |  
|Input Capacitor B41858C9227M                                   | EPCOS / TDK        | 2 |      $1.90 | $3.80| https://www.mouser.com/ProductDetail/EPCOS-TDK/B41858C9227M?qs=sGAEpiMZZMsh%252B1woXyUXj1SPYG7TfWbY3M%252BRTBa2uXQ%3D |
|Schottky Diode RB218NS100TL                                 |   ROHM Semiconductor   |    4 |      $2.09 | $8.36| https://www.mouser.com/ProductDetail/ROHM-Semiconductor/RB218NS100TL?qs=4v%252BiZTmLVHGSz1dy1RhSpg%3D%3D|
|MOSFET SQJ872EP-T1_GE3                               |   Vishay / Siliconix |      2 |      $1.46 | $2.92| https://www.mouser.com/ProductDetail/Vishay-Siliconix/SQJ872EP-T1_GE3?qs=y6ZabgHbY%252ByhIql41nGYsQ%3D%3D |
|30ft 14AWG wire                             |    NAOEVO   |    1 |      $29.99 | $29.99| https://www.amazon.com/dp/B0C27C1RCX/ref=twister_B0CB468CZK?_encoding=UTF8&th=1 |
| **Subsystem Total**                                            |            |          |       | $178.90|

## References ##
[1]https://www.ti.com/lit/an/slva477b/slva477b.pdf?ts=1726447009531&ref_url=https%253A%252F%252Fwww.google.com%252F
[2]https://www.ti.com/lit/an/slyt670/slyt670.pdf
[3]https://fscdn.rohm.com/en/products/databook/applinote/ic/power/switching_regulator/converter_pcb_layout_appli-e.pdf
[4]https://resources.altium.com/p/pcb-trace-width-vs-current-table-high-voltage-design
https://www.mouser.com/pdfdocs/buckconverterdesignnote.pdf
https://docs.arduino.cc/hardware/nano
https://www.arduino.cc/reference/en/language/functions/analog-io/analogread/
https://www.ti.com/lit/ds/symlink/tps40200.pdf

