# DAQ Signoff

## Functionality

The primary function of the data acquisition (DAQ) is capturing and displaying relevant testing data in real-time. The DAQ resolves this constraint through a process containing signal conditioners, signal converters, a controller, and software. Through the execution of correctly applying these systems, accurate, real-time data will be derived to support the generation of a model.

## Constraints
|No.        |Constraints   |Origin   |
|---|---------------------|--------|
|3|The microcontroller must have at least 10 analog inputs, to cover all possible sensors being used from the sensor integration system.         |Design Constraint |
|5|Comply with all relevant codes and standards listed in II. Ethical, Professional, and Standard Considerations.       |Ethics Constraint|
|16|Analog input pins must be able to read a 0-5 V or 4-20 mA output from the sensors.       |Derived from further considerations|
|17|The microcontroller must have an analog-to-digital converter with a minimum of 10-bit resolution.       |Derived from further considerations|
|18|The sensors must send at most 4800 samples per second.       |Derived from further considerations|
|19|The microcontroller must be able to read the RPM sensor in increments of 1 RPM, voltage in increments of 0.5 V, current in increments of 0.1 A, and torque in increments of 0.1 N-m.       |Derived from further considerations|


3.)  For successful system operation to be achieved, derived information must be logged accurately.  To do so, data needs to be properly displayed through the process of relaying sensor outputs to the correct pins on the Arduino Mega 2560 board.  This specific board has 16 analog inputs, allowing different sensors to input measurements.  Once connecting all sensors, verification of generated data must be carried out. To verify this information, a comparison between sensor values and the bike’s internal DAQ metrics will be conducted. Upon verification, the DAQ can successfully deliver output signals to the user interface to be displayed.

5.)   To guarantee that the project is being completed in a safe and proper manner, it is important to abide by certain standards.  One specific standard to follow is IEEE standard for Sensor Performance Parameter Definitions, also known as IEEE 2700-2017, which establishes a common framework for the required terminology, units, conditions, and limits for the specific sensor performance.  Another standard that is worth mentioning is IEC 61131-6.  This standard gives guidelines for controllers and the related parts, such as sensors and software, and ensures that they need to be reliable and effective.

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

The design of this subsystem presents an Elegoo ATMega 2560 R3 board and Arduino software to be the brain to effectively power sensors, capture sensor outputs, calibrate raw sensor data, perform necessary conversions/calculations, and send data to the user interface system for display/logging. The 2560 has 16 analog input pins, 54 digital I/O pins, 15 PWM output pins, and 3 5 V pins. The analog pins allow for interfacing with analog sensors capturing test data (shown in schematic.) The PWM and digital I/O pins allow for the addition of digital sensors or motors from other subsystems. The 2560 also provides 5 V and 3.3 V power necessary for sensors to operate. However, the board with multiple sensors attached will draw more power than a USB connection can supply, so the team proposes to obtain an external power supply that will offer extra 5 V and 3.3 V pins. The board itself will be powered by a 7-12 V wall outlet adapter. It communicates via a USB cord with a laptop/PC where it will send data to the user-interface system; this indicates it is necessary to purchase the correct cord long enough to work in any environment.

Along with hardware, this board works with Arduino software with many libraries making it easy to work with sensors, motors, and the user interface. This is also where the raw sensor data will be converted into readable, relevant metrics before being sent off to the user interface.

This allows the team to address constraint 3, enabling the sensors to bring in relevant metrics. This Arduino controller must be utilized correctly for the team to meet all safety and workplace standards. This applies directly to constraint 5.

### Resolution and Sample Rate:

To prove that the ATMega 2560 Board can successfully sample accurately enough for all of the sensors, the team finds values to determine if this specific microcontroller is fast enough to determine real-time values.  Finding the maximum values of sample rate and I/O pin currents, as well as the resolution, can show how accurate and precise the sensors are measuring.

The ADC clock frequency must be between 50 – 200 kHz for maximum accuracy at 10 bits of resolution. The clock frequency of 16 MHz is pre-scaled by 128 to 125 kHz so it is within the range. A normal conversion takes 13 ADC clock cycles, this means the sampling frequency would be 125000/13 = 9615.38 Hz. This means our Nyquist frequency, sampling frequency divided by 2, is 4800 Hz, which is the amount to avoid aliasing.

Use the following equation to determine the precision that the ATMega provides at 10 bits of resolution: 

![image](https://github.com/Dylan2432/Capstone1_Team3_EV-Motorcycle-Chassis-Dynamometer/assets/157453598/720d4f84-d0a3-44b4-ab01-e97a1ae3008c)


  Where VD is the full-scale input range of the logger, which is 5 V, VS is the full-scale range of the measured signal, which is 5 V, E is the engineering units that represent VS, Resolution represents the smallest change the DAQ can measure, and B is 0 as the logger is unipolar meaning it will measure from 0-5 V.

  We can verify the accuracy of the equation through an example. Say we have a DAQ with an input range of 0-5 volts, a sensor that measures current from 0-100 amps with an output range of 0-5 volts, the sensor was unipolar and the DAQ has a bit resolution of 10 bits. 10 bits represent 1024 locations that can be addressed. In this example our resolution is 0.09765625 A/location which is the smallest change the DAQ can measure. Then if we multiply our resolution by the number of locations the DAQ can provide, 1024, we get back to 100 A.


  Our E value was chosen as higher than the expected value to prepare for a worst-case scenario. A lower E value would lead to more precision.

  For voltage, our E is 100 VDC, which allows our precision to be 0.0976 V. This means the logger will respond to voltage changes of 0.0976V or more.

  For current, our E is 50 A, which allows the precision to be 0.0195 A.

  For RPM, our E is 1000 RPM, this is based on the max rpm of the rear wheel being 700.69. This means the precision is 0.977.

  For torque our E is 10 Nm, this is based on the max torque of the rear wheel being 4.995 Nm. This means the precision is 0.00977 Nm.

  These values are more precise than other dynos on the market, which provides confidence in the ability of the ATMega 2560 to work as a DAQ.

### Range:

  The ATMega brings in 0-5 volts (5.5-volt max) through the analog input ports, which meets the constraint for sensor inputs. It cannot use 4-20 mA as input, however, with an external 4-20 mA to 0-5 V converter circuit, the ATMega could be compatible with 4-20 mA sensors. This is ideal due to the less noise these signals produce compared to 0-5 V. This implementation, if necessary, will be discussed in the sensor implementation subsystem along with other discussions of signal noise. 



## BOM
|Item        |Quantity   |Price   |Total   |
|------------|-----------|--------|--------|
|ELEGOO ATMega 2560 Board|1          |\$ 29.99 |$ 29.99|
|Terminal Block Board Module |1| $ 25.90| $ 25.90|
|ATMega External Power Supply |1 |$ 12.99|$ 12.99
Subsystem Total |||$ 68.88|

## References

ATMega 2560 R3 Terminal Block:
https://czh-labs.com/products/ultra-small-gpio-terminal-block-breakout-board-module-for-arduino-mega-2560 

ELEGOO ATMega 2560 R3:
https://m.media-amazon.com/images/I/91RAy+evkrL.pdf

Referenced Arduino ATMega 2560 R3 Datasheet:
[A000067-full-pinout.pdf (arduino.cc)](https://docs.arduino.cc/resources/pinouts/A000067-full-pinout.pdf)

Arduino Libraries:
https://www.arduino.cc/reference/en/libraries/category/sensors/

Analog 4-20 mA current loop:
High-Performance, High-Accuracy 4-20mA Current-Loop Transmitter Meets Toughest Industrial Requirements - Reference Schematic - Maxim (analog.com)


PG 271 for sampling rate
ATmega640/1280/1281/2560/2561 Datasheet (microchip.com)

Bit resolution requirement
https://www.dataq.com/resources/pdfs/article_pdfs/adc-resolution.pdf

IEEE Standard 2700-2017:
2700-2017 - IEEE Standard for Sensor Performance Parameter Definitions | IEEE Standard | IEEE Xplore

IEC Standard 61131-6:
iec_61131-6_preview.pdf (plcopen.org)


