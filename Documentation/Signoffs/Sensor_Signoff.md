# Sensor Signoff
## Functionality

The functionality of sensor integration within an electric motorcycle dynamometer is essential for collecting data to accurately assess the motorcycle's performance. By seamlessly integrating sensors into the dynamometer and outputting gathered signals to the DAQ system, users can conduct comprehensive testing and optimization of the electric motorcycle.

## Constraints

|No.        |Constraints   |Origin   |
|---|---------------------|--------|
|3|	The system shall support a roller with induced torque up to 19.13 lb-ft.	|Design Constraint|
|6|	Comply with NFPA NEC 310.16 Conductors for General Wiring and NEC 250.122 Equipment Grounding Conductor Sizing	|Ethics/Standard Constraint|
|16|	Sensors must output either digital or analog signals of 0-10V	|Constrains to DAQ|
|19|	Sensors must be able to measure within the range of expected bike values	|Design Constraint|
	
3:  This constraint requires the sensor integration system to support the drum’s maximum torque of 19.13 lb-ft. Including a 20% safety factor, the system must be able to measure up to 22.96 lb-ft. It also requires supporting the drum’s maximum RPM of 1,288.

6:  Each sensor will contain wiring to communicate with the DAQ. This wiring must meet the codes listed to ensure safety and correct operation.

16:  This constraint is set and satisfied by the DAQ subsystem, which has ports that can supply or receive 0-10 volts.

19:  Due to the electric motorcycle’s data sheets, it has been calculated that the test data must be able to be captured in these ranges:

RPM:  0-1,288 RPM

Torque:  0-25.94Nm (calculated using 22.96 lb-ft with a conversion ratio of 1lb-ft = 1.3558 Nm)

## Schematics

### Rotary Torque Sensor Application:

 ![image](https://github.com/user-attachments/assets/d9eba0f2-4f64-4a90-9811-57e863a3841e)


The image above shows where the rotary torque sensor shall be installed within the dynamometer's mechanical system. It shall be coupled directly between the drum (labeled Load Equipment) and one of two electric motors (labeled Power Equipment). The sensor shaft has a coupling on each side that connects the solid protruding shaft of the sensor. Then, the sensor can measure the RPM seen by an internal encoder and the torque applied by an integral strain gauge attached to the solid protruding shaft.


### Rotary Torque Sensor Wiring Schedule:
 ![image](https://github.com/user-attachments/assets/cc51497b-23e1-4309-8449-b6eeedec3bc1)
 ![image](https://github.com/user-attachments/assets/f9c313e3-b487-4814-b57c-716658497eb2)

The image above shows the wiring schedule for the torque sensor cable. The connections are to the DAQ (NI USB_6215) and a USB to RS485 converter. This allows the user to program the sensor's parameters and provides a redundant data display to ensure the DAQ output matches the sensor's output. The ninth pin is connected to the cable shield, which will be attached to terminal 11 on the DAQ to eliminate any chance of noise generated onto the signal from electromagnetic interference.



### Rotary Torque Sensor Installation Dimensions:

![image](https://github.com/user-attachments/assets/04b262e3-b051-4b7a-8d39-33ea47275d50)

The image above shows the required dimensions in millimeters for mounting the sensor into the dynamometer.

## Analysis
### Rotary Torque Sensor:
The torque sensor is a transducer that converts mechanical torque into an electric output signal. This is achieved by attaching strain gauges to the shaft. As the shaft's torsion increases, the strain gauges' value proportionally changes, and the change in voltage or resistance measured is used to calculate the shaft's induced torque. The drum’s maximum torque from the bike’s 3500 W drive motor is 19.13 lb-ft. With a 20% safety factor, the system must then be able to measure up to 22.96 lb-ft. The selected sensor can support up to 100 Nm, which converts to 73.756 lb-ft, exceeding any anticipated torque capacity from the drum.

### RPM Sensor:
The rpm sensor is internally incorporated into the selected component. The RPM is measured with an encoder that reads the rotations per minute of the shaft passing through the device. To calculate the drum’s maximum RPM, we multiply the gear ratio by the bike’s maximum RPM. To calculate the gear ratio, we use the diameter of the bike’s rear tire, which is 22 inches, divided by the diameter of the drum, which is 12 inches. The gear ratio equals 1.833. The bike’s maximum RPM is calculated using RPM=[(Top Speed)(60)]/[(π)(Tire Diameter)]. The bike’s top speed is 74 kmh or 20.56 m/s, and the rear tire diameter is 22 inches or 0.559 m. Therefore, the bike’s maximum RPM equals 702.45. Then, we multiply the gear ratio by the bike’s maximum RPM of 702.45, giving us the drum’s maximum RPM of 1,288. The selected sensor is rated for up to 10,000 RPM and will support up to 15,000 RPM, which is well above the drum's anticipated RPM. The sensor will be powered by a 24-volt power supply and output a 0-5 volt signal. After calculating the gearing ratio and implementing that into the DAQ software, the output signal can be converted to display the correct RPM of the bike being tested on the dynamometer.

### Standards:
To meet the wire sizing standard discussed in the constraints, the team will verify that the wiring included with the sensors is at least 24 AWG. This is the recommended wire size for 0-5 volt sensors to meet NEC codes. 

## BOM

|Manufactuer			|Item					|Part No.	|Quantity	|Price|
|ATO Industrial Automation	|ATO Rotary Torque Sensor 100Nm, +5V	|ATO-TQS-D03|	1|		$1,021.99| 
|ATO Industrial Automation	|ATO USB to RS485 adapter PLUS Software	|ATO-UT-890A|	1|		$335.00|
|Subsystem Total| 	 	 	 	|$1,356.99| 

## References

Torque Sensor: https://www.ato.com/rotary-torque-sensor-10000-nm

USB to RS485 adapter: https://www.ato.com/usb-to-rs485-converter

NU USB-6215 Specs: https://www.ni.com/docs/en-US/bundle/usb-6215-specs/page/specs.html

NU USB-6215 Pinout: https://documentation.help/NI-DAQmx-de/6215Pinout.html

How rotary torque sensors work: https://www.futek.com/torque-meter

Understanding cable shielding: https://www.mouser.com/pdfdocs/alphawire-Understanding-Shielded-Cable.pdf

Adapter wiring diagram: https://az849230.vo.msecnd.net/resources/ic832a_rev3_20242.pdf 


