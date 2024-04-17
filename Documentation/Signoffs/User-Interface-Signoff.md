# User-Interface Signoff

## Functionality

The user interface will be the key system by which the user communicates with the test hardware/equipment. It will receive test parameter inputs from the user (bike speed ranges and road grade simulation), translate this data to the testing equipment, as well as communicate test results/metrics to the user; all this being done via PC-compatible software. Further discussion will be addressed in the following sections

## Constraints

The following are constraints from the conceptual design imposed on this subsystem by different stakeholders in the project. They are explained in the section below.
|No.        |Constraints   |Origin   |
|---|---------------------|--------|
|4|    Be able to be fully operated remotely       | Design Constraint |
|10|Display/capture values for bike speed, acceleration, and torque on a single PC        |Design Constraint|
|15|Alert users of risk and ensure they are following correct procedures.         |Ethical Concern |

4: This constraint requests that the full testing operation of the stand be able to be completed without an individual on the bike operating it. This applies to this subsystem since the user interface controls the throttle subsystem that would otherwise be completed by direct contact with the bike.

10: This forces the design to work specifically with PC-compatible software. It also makes the design need a way to take test data from the DAQ system, plot it, and store it for later analysis. 

15: Constraint 15 addresses an ethical concern for safety, and the user interface is responsible for carrying it out due to it being the direct bridge between the dyno user and the test equipment. The solution is addressed in analysis.

## Schematics

Since this subsystem consists of primarily software utilization, the schematics will not be hardware. The first schematic demonstrates how the PC containing the user interface interacts with the other subsystems. It also demonstrates what it takes in as inputs along with what it outputs and where to.

![image](https://github.com/Dylan2432/Capstone1_Team3_EV-Motorcycle-Chassis-Dynamometer/assets/100161665/7ab706ac-cbc5-4bda-bbcd-dfdb96a64ccd)

Hardware connections between PC and Throttle Control Subsystem:

![image](https://github.com/Dylan2432/Capstone1_Team3_EV-Motorcycle-Chassis-Dynamometer/assets/100161665/d88abf95-29e3-4b61-967f-e06983edc533)

Hardware connections between PC and DAQ Subsystem:

![image](https://github.com/Dylan2432/Capstone1_Team3_EV-Motorcycle-Chassis-Dynamometer/assets/100161665/4e3b9725-b700-4411-8be2-336eed7b42cc)


Flow chart of what user will experience before/during/after testing:

![image](https://github.com/Dylan2432/Capstone1_Team3_EV-Motorcycle-Chassis-Dynamometer/assets/100161665/f9a29173-79e3-458f-b486-cd5b56bdfbcc)

## Analysis

In order to meet the constraints listed, the user interface will need to be able to take in user inputs for bike speed ranges, road grade simulation, and braking. The interface will alert the user the   It will then need to write this data to the Throttle Control System where it will begin the bike test run. It will then need to successfully read in data points from the DAQ system (ATMega 2560)* and plot/store them along with the respective time. These needs can be met by utilizing Microsoft Excel and other PC based software. Excel is an ideal tool for meeting project constraints due to the wide range of its abilities specifically explained below. It is also a very commonly accessible tool due to it being included in a Microsoft Office license. This prevents users from buying extra hardware and/or software.

*Note: The ATMega 2560 is included in the DAQ BOM and is not necessary for purchase for this subsystem.
 

### User Input

Excel offers Visual Basic as an option for UI inside the application. This will be utilized to bring in the desired test parameters. Using VBE, the software will prompt the user to enter the desired maximum speed and choose incline testing (if yes, select the desired grade from 0-8%). The appropriate measures to take for incline testing will be displayed after this. Next, the testing will begin by signaling the throttle system. From this point on, the user input will allow the user to press stop at any time to signal the throttle system to stop applying the throttle. This will end the test and then ask if the user would like to test again, restarting the process. 

### Writing to Throttle Subsystem

Excel Data Streamer allows for the interface between PC and microcontroller. This would allow for the throttle subsystem to operate with user-inputted values via the serial communication abilities of the ATMega 2560 (to which the throttle is connected). Arduino IDE software will be written to control the throttle using the feedback from the DAQ to bring the bike to the desired speed and keep it there (closed-loop control system). 

### Reading From DAQ
	
For a maximum user-friendly output visual, this subsystem will utilize a microcontroller-specific data logging software called “Telemetry Viewer.” It is an open-source Java-based program that can take in data via serial communication, which makes it compatible with the ATMega 2560 (the DAQ). Using Arduino IDE, the DAQ system will send the conditioned, calibrated test statistics to the serial monitor (comma-separated values (CSV) format), where Telemetry Viewer will receive the data through the specified port (COM3 for example) and build user-specified graphs to display each desired statistic vs time. Using CSV format allows for the serial communication of multiple data points at once, allowing our project to have no constraint by this. When testing is complete, the program can export the plotted data to Excel where it can be stored in the PC’s files for later analysis.

### Safety Warning

To address constraint 15, the user interface will pop up a message regarding safety as the user begins the setup/input process. They will be prompted with: “Operating a vehicle on a dyno can be dangerous and cause great harm or death if operated incorrectly. Ensure the bike is securely fastened to the dyno and no loose objects are hanging near the bike. Push accept if you have ensured the bike is safe and secure for operation." After this has been accepted, normal testing operations may continue. This addition will be included on the Excel sheet using VBE. 

### Wire Connections

The connection between the UI PC and ATMega 2560 is extremely important for this entire project. There is also the situation of having an unknown testing location, so the BOM includes a 25ft USB-A to USB-B cord to ensure that no matter the testing situation there is enough cord to connect the UI PC to the ATMega.

## BOM

|Item        |Quantity   |Price   |Total   |
|------------|-----------|--------|--------|
|*Microsoft Office License|*1          |*$ 150.00 |*$ 150.00|
|25ft USB-A to USB-B Cord |1         |$ 15.99 |$ 15.99|
|Subsystem Total |||$ 15.99|

*Only if not already available to the customer 

## References

Information regarding data Telemetry Viewer plotting/logging software (v0.7):
 http://farrellf.com/TelemetryViewer/

