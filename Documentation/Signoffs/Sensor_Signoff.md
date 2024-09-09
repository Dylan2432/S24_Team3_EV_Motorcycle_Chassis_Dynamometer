# Sensor Signoff
## Functionality

The functionality of sensor integration within an electric motorcycle dynamometer is essential for collecting data to accurately assess the motorcycle's performance. By seamlessly integrating sensors into the dynamometer and outputting gathered signals to the DAQ system, users can conduct comprehensive testing and optimization of the electric motorcycle.

## Constraints

|No.        |Constraints   |Origin   |
|---|---------------------|--------|
|3|	The system shall support a roller with induced torque up to 25.94 lb-ft.	|Design Constraint|
|6|	Comply with NFPA NEC 310.16 Conductors for General Wiring and NEC 250.122 Equipment Grounding Conductor Sizing	|Ethics/Standard Constraint|
|16|	Sensors must output either digital or analog signals of 0-10V	|Constrains to DAQ|
|19|	Sensors must be able to measure within the range of expected bike values	|Design Constraint|
	
3:  This constraint requires the sensor integration system to support the bike’s maximum torque output of 25.94 lb-ft. Including a 20% safety factor, the system must be able to measure up to 31.13 lb-ft. It also requires supporting the bike’s maximum RPM of 1,288.

6:  Each sensor will contain wiring to communicate with the DAQ. This wiring must meet the codes listed to ensure safety and correct operation.

16:  This constraint is set and satisfied by the DAQ subsystem, which has ports that can supply or receive 0-10 volts.

19:  Due to the electric motorcycle’s data sheets, it has been calculated that the test data must be able to be captured in these ranges:

RPM:  0-1,288 RPM

Torque:  0-43Nm (calculated using 31.13 lb-ft with a conversion ratio of 1lb-ft = 1.3558 Nm)

## Schematics

### Rotary Torque Sensor Application:

 ![image](https://github.com/user-attachments/assets/d9eba0f2-4f64-4a90-9811-57e863a3841e)


The image above shows where the rotary torque sensor shall be installed within the dynamometer's mechanical system. It shall be installed between the drum (labeled Load Equipment) and one of two electric motors (labeled Power Equipment). The sensor shaft has a coupling on each side that connects the solid protruding shaft of the sensor. Then, the sensor can measure the RPM seen by an internal encoder and the torque applied by an integral strain gauge attached to the solid protruding shaft.


### Rotary Torque Sensor Wiring Schedule:
 ![image](https://github.com/user-attachments/assets/cc51497b-23e1-4309-8449-b6eeedec3bc1)
 ![image](https://github.com/user-attachments/assets/f9c313e3-b487-4814-b57c-716658497eb2)

The image above shows the wiring schedule for the torque sensor cable. The connections are to the DAQ (NI USB_6215) and a USB to RS485 converter. This allows the user to program the sensor's parameters and provides a redundant data display to ensure the DAQ output matches the sensor's output. The ninth pin is connected to the cable shield, which will be attached to terminal 11 on the DAQ to eliminate any chance of noise generated onto the signal from electromagnetic interference.



### Rotary Torque Sensor Installation Dimensions:

![image](https://github.com/user-attachments/assets/04b262e3-b051-4b7a-8d39-33ea47275d50)

The image above shows the required dimensions in millimeters for mounting the sensor into the dynamometer.

## Analysis
### Rotary Torque Sensor:
The torque sensor is a transducer that converts mechanical torque into an electric output signal. This is achieved by attaching strain gauges to the shaft. As the shaft's torsion increases, the strain gauges' value proportionally changes, and the change in voltage or resistance measured is used to calculate the shaft's induced torque. The bike’s maximum torque from the 3500 W drive motor is 25.94 lb-ft. With a 20% safety factor, the system must then be able to measure up to 31.13 lb-ft. The selected sensor can support up to 100 Nm, which converts to 73.756 lb-ft. 

The sensor must also support the drum’s maximum RPM driven from the bike's drive wheel, which is 1,288 RPM. The selected sensor is rated for up to 10,000 RPM and will support up to 15,000 RPM. The sensor will be powered by a 24-volt power supply and output a 0-5 volt signal. The 

### RPM Sensor:
The rpm sensor is internally incorporated into the selected component. The RPM is measured with an encoder that reads the rotations per minute of the shaft passing through the device. This value at the sensor will be higher than the actual value of the bike’s wheel, but it can be converted after calculating the gearing ratio and implementing that into the DAQ software. The drum will be 12 inches in diameter, and the shaft on the sensor is 14.5mm or 0.571 inches in diameter. The diameter of the drum divided by the shaft equals a 21.016 gear ratio. Therefore, when the dynamometer rotates at the maximum RPM of 1,288, the sensor’s shaft speed will measure 27,068 RPM.

### Standards:
To meet the wire sizing standard discussed in the constraints, the team will verify that the wiring included with the sensors is at least 24 AWG. This is the recommended wire size for 0-5 volt sensors to meet NEC codes. 

## BOM
|Item	|Quantity	|Price|
|---|-----------|--------|
|ATO Rotary Torque Sensor 100Nm, +5V	|1|	$1,021.99 |
|ATO USB to RS485 adapter PLUS Software|1|	$335.00 |
|Subsystem Total| 	 	|$1,356.99| 

## References

Torque Sensor: https://www.ato.com/rotary-torque-sensor-10000-nm

USB to RS485 adapter: https://www.ato.com/usb-to-rs485-converter

NU USB-6215 Specs: https://www.ni.com/docs/en-US/bundle/usb-6215-specs/page/specs.html

NU USB-6215 Pinout: https://documentation.help/NI-DAQmx-de/6215Pinout.html

How rotary torque sensors work: https://www.futek.com/torque-meter

Understanding cable shielding: https://www.mouser.com/pdfdocs/alphawire-Understanding-Shielded-Cable.pdf

Adapter wiring diagram: https://az849230.vo.msecnd.net/resources/ic832a_rev3_20242.pdf 


