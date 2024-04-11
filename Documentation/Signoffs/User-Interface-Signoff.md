# User-Interface Signoff

## Functionality

The user interface will be the key system by which the user communicates with the test hardware/equipment. It will receive test parameter inputs from the user (bike speed ranges, road grade simulation, and braking), translate this data to the testing equipment, as well as communicate test results/metrics to the user; all this being done via PC-compatible software. Further discussion will be addressed in the following sections.

## Constraints

The following are constraints from the conceptual design imposed on this subsystem by different stakeholders in the project. They are explained in the section below.
|No.        |Constraints   |Origin   |
|---|---------------------|--------|
|4|    Be able to be fully operated remotely       | Design Constraint |
|10|Display/capture values for bike speed, acceleration, torque, motor voltage/current on a single PC        |Design Constraint|
|15|Alert users of risk and ensure they are following correct procedures.         |Ethical Concern |

4: This constraint requests that the full testing operation of the stand be able to be completed without an individual on the bike operating it. This applies to this subsystem since the user interface controls the other subsystems (braking, throttle, road grade) that would otherwise be completed by direct contact with the bike.

10: This forces the design to work specifically with PC-compatible software. It also makes the design need a way to take test data from the DAQ system, plot it, and store it for later analysis. 

15: Constraint 15 addresses an ethical concern for safety, and the user interface is responsible for carrying it out due to it being the direct bridge between the dyno user and the test equipment.

## Schematics

Since this subsystem consists of primarily software utilization, the schematics will not be hardware. The first schematic demonstrates how the PC containing the user interface interacts with the other subsystems. It also demonstrates what it takes in as inputs along with what it outputs and where to.

![image](https://github.com/Dylan2432/Capstone1_Team3_EV-Motorcycle-Chassis-Dynamometer/assets/100161665/7ab706ac-cbc5-4bda-bbcd-dfdb96a64ccd)

Flow chart of what user will experience before/during/after testing:

![image](https://github.com/Dylan2432/Capstone1_Team3_EV-Motorcycle-Chassis-Dynamometer/assets/100161665/f9a29173-79e3-458f-b486-cd5b56bdfbcc)

## Analysis

In order to meet the constraints listed, the user interface will need to be able to take in user inputs for bike speed ranges, road grade simulation, and braking. It will then need to write this data to the DAQ where it will distribute to the correct subsystem. It will then need to successfully read in data points from the DAQ system (ATMega) and plot/store them along with the respective time. These needs can be met by utilizing Microsoft Excel. 

### User Input

Excel offers Visual Basic as an option for UI inside the application. This can be used to bring in the parameters for testing.

### Writing to DAQ

Excel Data Streamer allows for the interface between PC and microcontroller. This would allow for the DAQ to be written to with user-inputted values.

### Reading From DAQ
	
The data streamer also allows microcontroller output to excel, which could send over all the metrics needed for plotting/logging.

## BOM

|Item        |Quantity   |Price   |Total   |
|------------|-----------|--------|--------|
|*Microsoft Office License|1          |$ 150.00 |$ 150.00|
|25ft USB-A to USB-B Cord |1         |$ 15.99 |$ 15.99|
|Subsystem Total |||$ 15.99|

## References

Analysis:
