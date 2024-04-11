# DAQ Signoff

## Functionality

The primary function of the data acquisition (DAQ) is capturing and displaying relevant testing data in real-time. The DAQ resolves this constraint through a process containing signal conditioners, signal converters, a controller, and software. Through the execution of correctly applying these systems, accurate, real-time data will be derived to support the generation of a model.

## Constraints
|No.        |Constraints   |Origin   |
|---|---------------------|--------|
|3|Capture current and voltage supplied to the drive motor along with vehicle speed, torque, horsepower, and rpm and display all results.         |Design Constraint |
|5|Comply with all relevant codes and standards listed in II. Ethical, Professional, and Standard Considerations.       |Ethics Constraint|

3.)  In order for successful system operation to be achieved, it is important that derived information is logged accurately. To do so, data needs to be properly displayed through the process of relaying sensor outputs to the correct pins on the Arduino Mega 2560 board. Once connecting all sensors, verification of generated data must be carried out. To verify this information, comparison between sensor values and the bike’s internal DAQ’s metrics will be conducted. Upon verification, the DAQ can successfully deliver output signals to the user interface to be displayed.

5.)   It is required that all operations that occur shall follow the codes in II. Ethical, Professional, and Standard Considerations. This will ensure that everything being designed and tested is done in a proper and safe manner.

## Schematics

### ATMega 2560 R3 Wiring Diagram

![image](https://github.com/Dylan2432/Capstone1_Team3_EV-Motorcycle-Chassis-Dynamometer/assets/100161665/1315ed39-813b-4921-a6d4-7d59e6c4dffd)

### GPIO Terminal Block for ATMega

![image](https://github.com/Dylan2432/Capstone1_Team3_EV-Motorcycle-Chassis-Dynamometer/assets/100161665/8f1a0d65-bd72-4ea7-ab0b-776cb64db4e0)

The team will be implementing a GPIO terminal block breakout board module to keep wiring secure and improve reliability.


## Analysis

Arduino:

The design of this subsystem presents an Elegoo ATMega 2560 R3 board and Arduino software to be the brain to effectively power sensors, capture sensor outputs, calibrate raw sensor data, perform necessary conversions/calculations, and send data to the user interface system for display/logging. The 2560 has 16 analog input pins, 54 digital I/O pins, 15 PWM output pins, and 3 5v pins. The analog pins allow for interfacing with analog sensors capturing test data (shown in schematic.) The PWM and digital I/O pins allow for the addition of digital sensors or motors from other subsystems. The 2560 also provides 5v and 3.3v power necessary for sensors to operate. However, the board with multiple sensors attached will draw more power than a USB connection can supply, so the team proposes to obtain an external power supply that will offer extra 5v and 3.3v pins. The board itself will be powered by a 7-12v ¬wall outlet adapter. It communicates via a USB cord with a laptop/PC where it will send data to the user-interface system; this indicates it is necessary to purchase the correct cord long enough to work in any environment.

Along with hardware, this board works with Arduino software with many libraries making it easy to work with sensors, motors, and the user interface. This is also where the raw sensor data will be converted into readable, relevant metrics before being sent off to the user interface.

This allows the team to address constraint 3, enabling the sensors to bring in relevant metrics. This Arduino controller must be utilized correctly for the team to meet all safety and workplace standards. This applies directly to constraint 5.

To prove that the ATMega 2560 Board can successfully sample accurate enough for all of the sensors, the team finds that the sensor with the fastest response time would solve this. The reason being is that the faster the response time, the more accurate the measurement is to real time. Out of all of the sensors that are being used, the team have found that the rpm sensor would be best as the it has a response time of 1ms. The sample rate of the ATMega is given as 15000 samples per second allowing the sensor output to be received in a very short amount of time.


## BOM
|Item        |Quantity   |Price   |Total   |
|------------|-----------|--------|--------|
|ELEGOO ATMega 2560 Board|1          |\$ 29.99 |$ 29.99|
|25ft USB-A to USB-B Cord|1         |$ 15.99|$ 15.99|
|Terminal Block Board Module |1| $ 25.90| $ 25.90|
|ATMega External Power Supply |1 |$12.99|$12.99
Subsystem Total |||$ 84.87|

## References

ATMega 2560 R3 Terminal Block:
https://czh-labs.com/products/ultra-small-gpio-terminal-block-breakout-board-module-for-arduino-mega-2560 

ELEGOO ATMega 2560 R3:
https://m.media-amazon.com/images/I/91RAy+evkrL.pdf

Referenced Arduino ATMega 2560 R3 Datasheet:
[A000067-full-pinout.pdf (arduino.cc)](https://docs.arduino.cc/resources/pinouts/A000067-full-pinout.pdf)

Arduino Libraries:
https://www.arduino.cc/reference/en/libraries/category/sensors/

