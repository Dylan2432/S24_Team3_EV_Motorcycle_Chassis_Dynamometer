# DAQ Signoff

## Functionality

The primary function of the data acquisition (DAQ) is capturing and displaying relevant testing data in real-time. The DAQ resolves this constraint through a process containing signal conditioners, signal converters, a controller, and software. Through the execution of correctly applying these systems, accurate, real-time data will be derived to support the generation of a model.

## Constraints
|No.        |Constraints   |Origin   |
|---|---------------------|--------|
|3|The microcontroller must have at least 10 analog inputs, to cover all possible sensors being used from the sensor integration system.         |Design Constraint |
|16|Analog input pins must be able to read a 0-5 V input.       |Derived from further considerations|
|17|The microcontroller must have an analog-to-digital converter with a minimum of 10-bit resolution.       |Derived from further considerations|
|18|The controller ADC must be able to sample atleast 4800 samples per second       |Derived from further considerations|
|19|The microcontroller sampling must have enough resolution to see 1% changes in sensor outputs      |Derived from further considerations|


3.)  For successful system operation to be achieved, derived information must be logged accurately.  To do so, data needs to be properly displayed through the process of relaying sensor outputs to the correct pins on the Arduino Mega 2560 board.  This specific board has 16 analog inputs, allowing different sensors to input measurements.  Once connecting all sensors, verification of generated data must be carried out. To verify this information, a comparison between sensor values and the bike’s internal DAQ metrics will be conducted. Upon verification, the DAQ can successfully deliver output signals to the user interface to be displayed.

16.)   An industry standard for sending a signal from a sensor to a data acquisition system or controller is a 4-20 mA current loop or 0-5 V voltage.  Because of this, the microcontroller selected must be able to handle either 4-20 mA or 0-5 V on an I/O pin.

17:  It is important to have a microcontroller with an analog-to-digital converter of at least 10 bits.  The reason for this is to ensure better accuracy and higher precision.  This is further described below in the Analysis section with mathematical proof.

18.)   For 10 bits of resolution, the ADC clock frequency must be between 50-200kHz to make the measurements as accurate as possible.  With this information, along with the 16MHz clock frequency, the 13 ADC clock cycles, and the calculations described below, we find that the sample rate must be no higher than the 4800S/s.

19.)   The values must be displayed with these increments to ensure that the values that are displayed are accurate enough.  These values are determined by the calculations for each of the sensors, along with the values that are given by the microcontroller.



## Schematics

### ATMega 2560 R3 Wiring Diagram
Note: Due to the braking subsystem, the voltage and current sensors have been removed from the schematic. However, if changes in the braking subsystem occur, adding them back to the DAQ successfully has already been proven feasible.

![image](https://github.com/Dylan2432/Capstone1_Team3_EV-Motorcycle-Chassis-Dynamometer/assets/157453598/73cc76ce-7a36-492f-9340-87c22a202c2c)


### GPIO Terminal Block for ATMega

![image](https://github.com/Dylan2432/Capstone1_Team3_EV-Motorcycle-Chassis-Dynamometer/assets/100161665/8f1a0d65-bd72-4ea7-ab0b-776cb64db4e0)

The team will be implementing a GPIO terminal block breakout board module to keep wiring secure and improve reliability.


## Analysis

### Arduino:

The design of this subsystem presents an Elegoo ATMega 2560 R3 board and Arduino software to be the brain to effectively power sensors, capture sensor outputs, calibrate raw sensor data, perform necessary conversions/calculations, and send data to the user interface system for display/logging. The 2560 has 16 analog input pins which exceeds the minimum requirement of 10 pins. This satisfies constraint 3. It also has 54 digital I/O pins, 15 PWM output pins, and 3 5 V pins. The analog pins allow for interfacing with analog sensors capturing test data (shown in schematic.) The PWM and digital I/O pins allow for the addition of digital sensors or motors from other subsystems. The 2560 also provides 5 V and 3.3 V power necessary for sensors to operate. However, the board with multiple sensors attached will draw more power than a USB connection can supply, so the team proposes to obtain an external power supply that will offer extra 5 V and 3.3 V pins. The board itself will be powered by a 7-12 V wall outlet adapter. It communicates via a USB cord with a laptop/PC where it will send data to the user-interface system; this indicates it is necessary to purchase the correct cord long enough to work in any environment. All of the specs are included in the data sheet attached in references. 

Along with hardware, this board works with Arduino software with many libraries making it easy to work with sensors, motors, and the user interface. This is also where the raw sensor data will be converted into readable, relevant metrics before being sent off to the user interface.  

### Resolution and Sample Rate:

To prove that the ATMega 2560 Board can successfully sample accurately enough for all of the sensors, the team finds values to determine if this specific microcontroller is fast enough to determine real-time values. Finding the maximum values of sample rate and I/O pin currents, as well as the resolution, can show how accurate and precise the sensors are measuring.

The ADC on the ATMega operates with 10 bits of resolution. This meets constraint 17. The ADC clock frequency must be between 50 – 200 kHz for maximum accuracy at 10 bits. The clock frequency of 16 MHz is pre-scaled by 128 to 125 kHz so it is within the range. A normal conversion takes 13 ADC clock cycles, this means the sampling frequency would be 125000/13 = 9615.38 Hz. This means our Nyquist frequency, sampling frequency divided by 2, is approximately 4800 Hz, which is the amount to avoid aliasing. This meets constraint 18.

Use the following equation to determine the precision that the ATMega provides at 10 bits of resolution: 

![image](https://github.com/Dylan2432/Capstone1_Team3_EV-Motorcycle-Chassis-Dynamometer/assets/157453598/720d4f84-d0a3-44b4-ab01-e97a1ae3008c)


  Where VD is the full-scale input range of the logger, which is 5 V, VS is the full-scale range of the measured signal, which is 5 V, E is the engineering units that represent VS, Resolution represents the smallest change the DAQ can measure, and B is 0 as the logger is unipolar meaning it will measure from 0-5 V.

  We can verify the accuracy of the equation through an example. Say we have a DAQ with an input range of 0-5 volts, a sensor that measures current from 0-100 amps with an output range of 0-5 volts, the sensor was unipolar and the DAQ has a bit resolution of 10 bits. 10 bits represent 1024 locations that can be addressed. In this example our resolution is 0.09765625 A/location which is the smallest change the DAQ can measure. Then if we multiply our resolution by the number of locations the DAQ can provide, 1024, we get back to 100 A.


  Our E value was chosen as higher than the expected value to prepare for a worst-case scenario. A lower E value would lead to more precision.

  For voltage, our E is 100 VDC, which allows our precision to be 0.0976 V. This means the logger will respond to voltage changes of 0.0976V or more. 1% of E is 1; therefore precision of 0.0976 meets and exceeds the limitations of constraint 19.

  For current, our E is 50 A, which allows the precision to be 0.0195 A. 1% of E is 0.5; therefore precision of 0.0195 meets and exceeds the limitations of constraint 19.

  For RPM, our E is 1000 RPM, this is based on the max rpm of the rear wheel being 700.69. This means the precision is 0.977. 1% of E is 10; therefore precision of 0.977 meets and exceeds the limitations of constraint 19.

  For torque our E is 10 Nm, this is based on the max torque of the rear wheel being 4.995 Nm. This means the precision is 0.00977 Nm. 1% of E is 0.1; therefore precision of 0.00977 meets and exceeds the limitations of constraint 19.

  These values are also more precise than other dynos on the market, which provides confidence in the ability of the ATMega 2560 to work as a DAQ. 

### Range:

  The ATMega brings in 0-5 volts (5.5-volt max) through the analog input ports, which meets constraint 16 for analog inputs. Another common sensor is 4-20mA. It cannot use 4-20 mA as input, however, with an external 4-20 mA to 0-5 V converter circuit, the ATMega could be compatible with 4-20 mA sensors. This is ideal due to the less noise these signals produce compared to 0-5 V. This implementation, if necessary, will be discussed in the sensor implementation subsystem along with other discussions of signal noise. 



## BOM
|Item        |Quantity   |Price   |Total   |
|------------|-----------|--------|--------|
|ELEGOO ATMega 2560 Board|1          |\$ 29.99 |$ 29.99|
|Terminal Block Board Module |1| $ 25.90| $ 25.90|
|ATMega External Power Supply |1 |$ 9.99|$ 9.99
Subsystem Total |||$ 65.88|

## References

ATMega 2560 R3 Terminal Block:
https://czh-labs.com/products/ultra-small-gpio-terminal-block-breakout-board-module-for-arduino-mega-2560 

ELEGOO ATMega 2560 R3 Amazon:
https://www.amazon.com/ELEGOO-ATmega2560-ATMEGA16U2-Projects-Compliant/dp/B01H4ZLZLQ/ref=sr_1_1_sspa?crid=16BRP029GSDKD&dib=eyJ2IjoiMSJ9.YRe92sVKsG5qQ38nGt8ugRxG4oLlSTah1ujLWpkFo3I9IkiwxW5I1pK32YzBYAqbClf7thyoD7D0lR_Zqs0PXVBlJ1r7CxGpNdOUA2xwMvV9MWmvwieXpCFE1ChRG3-sGZOnrH9QqMwVr4YU71kvEyyS6Q1vRVboQZutMsr029pTRUziqep3jBl_Ywe78AyNL3r5k_k9pzr6fBi--6O8mYOOVorQli4IFwLtvLH2pgtP3xLJYIr-Z6grlAWDSzNlZ-Mxa-yAL2E-oytPkCoNQEixNwJ9NWv3V_qZG52JM8I.I_5K0qMY8UsodlCg9LY-Y8lqIF_PiYvp4h4zx7FSRMo&dib_tag=se&keywords=elegoo%2Batmega%2B2560&qid=1713464089&s=electronics&sprefix=elegoo%2Batmega%2B2560%2Celectronics%2C102&sr=1-1-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&th=1

ELEGOO ATMega 2560 R3 Full DataSheet:
https://m.media-amazon.com/images/I/91RAy+evkrL.pdf

Referenced Arduino ATMega 2560 R3 Datasheet:
[A000067-full-pinout.pdf (arduino.cc)](https://docs.arduino.cc/resources/pinouts/A000067-full-pinout.pdf)

Arduino Libraries:
https://www.arduino.cc/reference/en/libraries/category/sensors/

External Power Supply:
https://www.amazon.com/Power-Supply-Adapter-Cable-Arduino/dp/B0852JLTL9/ref=asc_df_B0852JLTL9/?tag=hyprod-20&linkCode=df0&hvadid=475752117837&hvpos=&hvnetw=g&hvrand=14142554888701368671&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=1025954&hvtargid=pla-1184753013526&psc=1&mcid=f7e467adc9293800ad670f7468fa99fc&gclid=Cj0KCQjwiYOxBhC5ARIsAIvdH52rauyA9vbQUKzORgxSjnxEoIROpZE4KwMwHbB57TDYEfsaDWTlc84aAs6kEALw_wcB

PG 271 for sampling rate
ATmega640/1280/1281/2560/2561 Datasheet (microchip.com)

Bit resolution requirement
https://www.dataq.com/resources/pdfs/article_pdfs/adc-resolution.pdf



