# DAQ Signoff

## Functionality

The primary function of the data acquisition (DAQ) is capturing and displaying relevant testing data in real-time. The DAQ resolves this constraint through a process containing signal conditioners, signal converters, a controller, and software. Through the execution of correctly applying these systems, accurate, real-time data will be derived to support the generation of a model.

## Constraints
|No.        |Constraints   |Origin   |
|---|---------------------|--------|
|3|The DAQ must have at least 10 analog inputs, to cover all possible sensors being used from the sensor integration system.         |Design Constraint |
|16|Analog input pins must be able to read an output of 0-5 V, 0-10 V, or 4-20mA input from the sensors.       |Derived from further considerations|
|17|The DAQ must have an analog-to-digital converter with a minimum of 10-bit resolution.       |Derived from further considerations|
|18|The DAQ must have a sampling rate of at least 4.8kS/s       |Derived from further considerations|
|19|The DAQ must be able to read the RPM sensor in increments of 1 rpm, voltage in increments of 0.5 V, current in increments of 0.1 A, and torque in incremets of 0.1 N-m.      |Derived from further considerations|


3.) To make sure all possible sensors are accounted for, it is vital to have a minimum of 10 analog inputs.

16.) An industry standard for sending a signal from a sensor to a data acquisition system or controller is a 4-20 mA current loop or 0-5v voltage.  Because of this, the daq selected must be able to read in either 4-20mA, 0-5v, or 0-10v sensors on an analog input pin.

17.)  Using the resolution equation in the analysis, a 10-bit ADC would allow the team to meet the minimum specified resolution. 

18.) Based on different DAQ applications, it is vital that the DAQ system operates at a minimum of 4800S/s.

19.)  The values must be displayed with these increments to ensure that the values that are displayed are accurate enough.  These values are determined by the calculations for each of the sensors, along with the values that are given by the daq.




## Schematics

Note: Due to the braking subsystem, the sensors are subject to change. However, if changes in the braking subsystem occur, there are plenty of analog inputs available for added sensors. Adding additional power for sensors will be addressed based on specific sensors in the sensor integration subsystem.

### NI USB-6215 Wiring Diagram


![image](https://github.com/Dylan2432/Capstone1_Team3_EV-Motorcycle-Chassis-Dynamometer/assets/157453598/2a84bf06-5fef-403f-88f1-9fcf9d6aa0c7)



## Analysis

### USB-6215:

The design of this subsystem presents a National Instruments USB-6215 multifunction DAQ device and LabVIEW software to effectively power sensors, capture sensor outputs, calibrate raw sensor data, perform necessary conversions/calculations, and send data to the user interface system for display/logging.  The USB-6215 has 16 analog input pins which exceeds the minimum requirement of 10 pins.  This satisfies constraint 3.  The analog input pins allow for interfacing with analog sensors to capture test data.  It also has 8 digital I/O pins, 4 PWM output pins, and 1 5V pin.  The PWM and digital I/O pins allow for the addition of digital sensors or motors from other subsystems.  This system allows analog input of ±0-10 volts which widens the variety of available sensors, compared to only 0-5v. The system itself will be powered by the USB-B connection. The system communicates with a laptop/PC via the same USB-B connection, where it will send the measured data to the user-interface system. 

  The system will operate with the LabVIEW software, making it easy to work with sensors, motors, and displays.  This is also where the raw sensor data will be converted to relevant metrics, to then be sent to the user interface for display.



### Resolution and Sample Rate:

To prove that the NI USB-6215 system can successfully sample accurately enough for all of the sensors, the team finds values to determine if this specific system is fast enough to determine real-time values. Finding the maximum values of sample rate and I/O pin currents, as well as the resolution, can show how accurate and precise the sensors are measuring.

The sample rate is given in the data sheet of the system as 250kS/s, which exceeds constraint 18 by a significant amount.  This is very high compared to most systems and allows the system to capture measurements at a greater accuracy, along with a better resolution.


Use the following equation to determine the precision that the USB-6215 provides at 16 bits of resolution: 

![image](https://github.com/Dylan2432/Capstone1_Team3_EV-Motorcycle-Chassis-Dynamometer/assets/157453598/720d4f84-d0a3-44b4-ab01-e97a1ae3008c)


  Where VD is the full-scale input range of the logger, which is 10 V, VS is the full-scale range of the measured signal, which is 10 V, E is the engineering units that represent VS, Resolution represents the smallest change the DAQ can measure, and B is 0 as the logger is unipolar meaning it will measure from 0-10 V.


We can verify the accuracy of the equation through an example. Say we have a DAQ with an input range of 0-10 volts, a sensor that measures current from 0-100 amps with an output range of 0-10 volts, the sensor was unipolar and the DAQ has a bit resolution of 10 bits. 10 bits represent 1024 locations that can be addressed. In this example our resolution is 0.09765625 A/location which is the smallest change the DAQ can measure. Then if we multiply our resolution by the number of locations the DAQ can provide, 1024, we get back to 100 A.



  Our E value was chosen as higher than the expected value to prepare for a worst-case scenario. A lower E value would lead to more precision.

  For voltage, our E is 100 VDC, which allows our precision to be 0.001526 V. This means the logger will respond to voltage changes of 0.001526V or more. 1% of E is 1; therefore precision of 0.001526 meets and exceeds the limitations of constraint 19.


For current, our E is 50 A, which allows the precision to be 0.000763 A. 1% of E is 0.5; therefore precision of 0.000763 meets and exceeds the limitations of constraint 19.


  For RPM, our E is 1000 RPM, this is based on the max rpm of the rear wheel being 700.69. This means the precision is 0.01526. 1% of E is 10; therefore precision of 0.01526 meets and exceeds the limitations of constraint 19.

  For torque our E is 10 Nm, this is based on the max torque of the rear wheel being 4.995 Nm. This means the precision is 0.0001526 Nm. 1% of E is 0.1; therefore precision of 0.0001526 meets and exceeds the limitations of constraint 19.

  These values are more precise than other dynos on the market, which provides confidence in the ability of the USB-6215 to work as a DAQ.



### Range:
The USB-6215 brings in 0-10 volts (10.4 volts max) through the analog input ports, which meets constraint 16 for analog inputs. It cannot use 4-20 mA as input, however, with an external 4-20mA to 0-10v converter circuit, the system could be compatible with 4-20mA sensors.  This is an ideal situation due to the less noise these signals produce compared to 0-10V.  This is discussed in the sensor implementation subsystem, if necessary.





## BOM
|Item        |Quantity   |Price   |Total   |
|------------|-----------|--------|--------|
|NI USB-6215 DAQ|1          |\$ 1903.00 |$ 1903.00|
Subsystem Total |||$ 1903.00|

## References

USB-6215 Data sheet:
USB-6215 Specifications - NI

USB-6215 Information:
 USB-6215 - NI


Bit resolution requirement
https://www.dataq.com/resources/pdfs/article_pdfs/adc-resolution.pdf





