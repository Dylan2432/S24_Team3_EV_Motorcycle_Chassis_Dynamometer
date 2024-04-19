# Sensor Integration Signoff
 
## Functionality
 
The functionality of sensor integration within an electric motorcycle dynamometer is essential for collecting, monitoring, analyzing, and utilizing data to assess the motorcycle's performance accurately. By seamlessly integrating sensors into the dynamometer system and implementing robust data acquisition, processing, and control capabilities, users can conduct comprehensive testing and optimization of the electric motorcycle.
 
## Constraints
 
|No.|Constraints|Origin|
|-----|-----------|--------|
|3| Capture current and voltage supplied from the battery along with bike speed and torque. | Design Constraint   |
|5|	Comply with NFPA NEC 310.16 Conductors for General Wiring and NEC 250.122 Equipment Grounding Conductor Sizing  |Ethics/Standards Constraint|
|20| Sensors must output either digital or analog signals of 0-5v | Constrains to DAQ  |
|21| Sensors must send out a maximum of 4800 samples per second |  Constrains to DAQ |
|22| Sensors must be able to measure within the range of expected bike values (specifics below) | Design Constraint  |
 
3: This constrains the group to ensure the correct type of sensors that must be implemented in order to successfully test the capability of the motorcycle.
 
 
5:  Each sensor will contain wiring in order to communicate with the DAQ. This wiring will have to meet the codes listed to ensure safety and correct operation. 

20: This is set by the DAQ subsystem which has ports that bring in 0-5 volts (5.5 volt maximumm

21: The DAQ subsystem allows optimal ADC sampling at 9600 samples per second. This divided by 2 gives 4800 samples per second (Nyquist sampling frequency)

22: Due to the electric motorcycle’s data sheets, it has been calculated that the test data must be able to be captured in these ranges:

Voltage: 0-100v;
Current: 0-50A;
RPM: 0-1000 RPM;
Torque: 0-10 N-m

 
## Schematics

![image](https://github.com/Dylan2432/Capstone1_Team3_EV-Motorcycle-Chassis-Dynamometer/assets/100161665/e8f62a1c-bc81-4e8f-9afd-546a9df769ac)

The wiring diagram above displays how each sensor will be connected to the ATMega 2560 so that it’s output can be read. Furthermore, some sensors require external power supplied, outside the 3.3-5V of the ATMega, to operate. This is also depicted in the diagram above. The operation of this and the sensors selected is further explained below.
 
 
## Analysis
 
### Voltage sensor:
Constraint 3 lists the need for voltage sensing on the battery of the motorcycle per request of Proton Power. This will be done by attaching wires to the battery terminals. The voltage sensor attached in the BOM measures up to 1000 VDC and outputs 0-5v at a max rate of 1.5kHz. This allows voltage measuring to meet each constraint.
 
### Current Sensor:
This current transducer measures the battery’s current (DC Amps) load during dynamometer testing. It will easily clip around the wire running from the battery onboard the motorcycle. The transducer measures current up to 100A DC and outputs a voltage signal up to 4v, meeting the design constraints. The full-scale response rate is 167kHz, surpassing the DAQ’s capabilities; however, it has been deemed suitable for less than full-scale due to the sampling rate of the DAQ and other dynos. 
 
### RPM Sensor:
The digital adjustable inferred sensor listed below in references will be used to capture the rpm of the drum. To do this, the sensor will be mounted at a distance within the specified range away from the drum so that it does not detect anything. Then, a small piece will be attached to the drum’s body extruding towards the sensor capturing range. Every time this piece comes into the sensor’s laser, it will detect and register a revolution. This process can then be used to capture the rpm through code within the ATMega. Upon correctly doing this, the generation of an accurate rpm value will be attained. The distance limitations of this sensor range from 0-200cm. It requires a 5V supply, which can be attained through a connection on the ATMega. This sensor can measure the 0-1000, outputs a 0-5v signal, and sends out signals at a frequency the DAQ can operate at, allowing it to meet the required constraints for RPM measurement. 
 
### Load Cell:

The load cell will be used to measure the force exerted by the torque arm attached to the motor being used to induce load on the drum’s body. This arm will push down on the load cell and allow a force measurement to be derived. This force is then measured and sent out to be used. However, before this can be read by the ATMega, the signal must be amplified to a usable value. Since the load cell’s output rating is only 3.0 mV/V, this signal will have to be sent through an amplifier. The component chosen to do so is the load cell amplifier module listed in the references below. This component takes in the load cell signal and amplifies it to a selected 0-5 V signal. With this, the reading can then be transferred directly to the ATMega’s analog to digital pins in order to be computed into torque, meeting the constraint 20. This will be done through the calculation torque = Force * Distance. The distance used will be the length of the torque arm (12in or 1ft), and the Force will be the signal detected by the load cell. In addition to the amplifier, the excitation terminals must receive a 5-15 VDC or VAC for it to operate. Once connected correctly, this load cell can read up to 1,000 lbs of force which meets the constraint for measuring correct ranges of values. Based on various load cell data, the average response time of one is 1ms to 10ms, meaning the 4800 samples per second in the constraints would not be surpassed. 

### Standards

To meet the wire sizing standard discussed in the constraints, the team will verify that the wiring included with the sensors is at least 24 AWG. This is the recommended wire size for 0-5 volt sensors to meet NEC codes.
 
## BOM
 
 
 
|  Item | Quantity  |Price|  Total |
| ------------ | ------------ | ------------ | ------------ |
| High Voltage Sensor (EV1000)  | 1  | $194.25  | $194.25  |
| HCT-0016 4V Series Hall Effect Current Transducer with Power Supply    | 1  | $113.00  | $113.00  |
| Digital Adjustable Infrared Proximity Sensor  | 1  |  $12.90 |  $12.90 |
| Model SPWE: Low-Profile Vessel Weighing Load Cell  |  1  |   $670.00|  $670.00   |
|Load Cell Amplifier Module  |   1   |  $31.98  | $31.98|
| Subsystem Total|||$1022.13  |
 
 
 
## References
 
Voltage Sensor (0-1000VDC): https://store.egauge.net/High-Voltage-Sensor

Current Sensor (0-100A): https://aimdynamics.com/hct-0016-4v-series-hall-effect-current-transducers-by-magnelab

RPM Sensor: https://www.digikey.com/en/products/detail/dfrobot/SEN0239/8019052?utm_adgroup=&utm_source=google&utm_medium=cpc&utm_campaign=PMax%20Shopping_Product_High%20ROAS%20Categories&utm_term=&utm_content=&utm_id=go_cmp-20222717502_adg-_ad-__dev-c_ext-_prd-8019052_sig-CjwKCAjwrIixBhBbEiwACEqDJY9kjIaOApXf6QhDM73I18dvoSR6x2Ql2PHA9MV-epprodtJLi91FxoCgq8QAvD_BwE&gad_source=1&gclid=CjwKCAjwrIixBhBbEiwACEqDJY9kjIaOApXf6QhDM73I18dvoSR6x2Ql2PHA9MV-epprodtJLi91FxoCgq8QAvD_BwE

LoadCell: https://www.800loadcel.com/load-cells/pancake-shear-web-load-cells/spwe.html

LoadCell Amplifer Module: https://www.brightwinelectronics.com/product/load-cell-amplifier-module-4-20ma-0-5v-10v-output
