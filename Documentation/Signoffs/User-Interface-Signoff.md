# User-Interface Signoff

## Functionality

The user interface will be the key system by which the user communicates with the test hardware/equipment. It will receive test parameter inputs from the user (bike speed and road grade simulation), translate this data to the testing equipment, as well as communicate test results/metrics to the user. Further discussion will be addressed in the following sections.

## Constraints

The following are constraints imposed on this subsystem by different stakeholders in the project. They are explained in the section below:
|No.        |Constraints   |Origin   |
|---|---------------------|--------|
|4|   Be able to fully operate throttle control and dyno braking from an HMI/PC        | Design Constraint |
|10|Display/capture values for bike speed vs time and torque vs time.       |Design Constraint|
|15|Alert users of the potential risk of operating this chassis dyno system         |Ethical Concern |

4: This constraint requests that the full testing operation of the stand be able to be completed without an individual physically on the bike operating it. This applies to this subsystem since the user interface controls the throttle and braking subsystems. 

10: This forces the design to find a way to take test data from the DAQ system, visualize it, and store it for later analysis. 

15: Constraint 15 addresses an ethical concern for safety, and the user interface is responsible for carrying it out due to it being the direct bridge between the dyno user and the test equipment. The solution is addressed in analysis.

## Schematics

Hardware connections between PC, DAQ, throttle control, and braking:
![image](https://github.com/Dylan2432/Capstone1_Team3_EV-Motorcycle-Chassis-Dynamometer/assets/100161665/a89480a3-144c-4aa2-8cb1-1ff55df00baf)




## Analysis

In order to meet the constraints listed, the user interface will need to be able to take in user inputs for bike speed. It will then need to write this data to the respective subsystems through the DAQ card and begin the bike test run. Then, it will need to successfully read in data from the DAQ system and plot/store them along with the respective time via the PC. These needs can be met by utilizing National Instruments LabVIEW (graphical programming software) front and rear panels.


 

### User Input

For user input, LabVIEW software utilizes a front and rear panel. The front panel is the HMI layout where there will be the option to set a desired speed of 0-50 km/hr (from the customer). This front panel is what will be displayed on the PC during the test run, acting as the HMI. The user will be able to set up a custom duration test, or they will always have to option to change throttle/braking manually from here as well.

### Writing to Throttle/Braking Subsystem

Once the user chooses preferences for the test, the PC running LabVIEW writes to the DAQ. The LabVIEW VI code for the DAQ will be programmed to apply full-throttle (using PWM signals to the throttle system) until the bike’s speed reaches the designated speed. The DAQ houses 2 32-bit counters with the ability to perform pulse outputs (PWM). This speed will be maintained using closed-loop control, which is a commonly used tool in LabVIEW. Depending on the design of the braking/ torque measuring system, the VI will be programmed differently to control it. However, due to the versatility of LabVIEW, there is no issue in constraining another system to work within its uses. The schematic shows braking attached to an analog output, which is a likely possibility.

### Reading From DAQ
	
The HMI on the PC will also be designed to plot the different metrics that are relevant to the specific test being done. This data will be sent from the DAQ during the test, and displayed on the HMI (LabVIEW front panel). At the end of the test, (whenever the user ends the simulation on LabVIEW) the VI will write all of the time-stamped data acquired into an Excel/Matlab compatible file where it can be analyzed later. This is done simply by writing data into arrays and/or spreadsheets on the LabVIEW rear panel.  

### Safety Warning

To address constraint 15, the HMI screen will display a message regarding safety as the user begins the setup/input process. They will be prompted with: “Operating a vehicle on a dyno can be dangerous and cause great harm or death if operated incorrectly. Ensure the bike is securely fastened to the dyno and no loose objects are hanging near the bike. Push accept if you have ensured the bike is safe and secure for operation." After this has been accepted, normal testing operations may continue.

### Buying Software

Normally, NI LabVIEW would have to be purchased to be used. However, Tennessee Tech has a license for its use so this is not necessary for purchase.

### Wire Connections

The connection between the User Interface PC and DAQ is extremely important for this entire project. The BOM includes a 10ft USB-A to USB-B for connecting the DAQ to the PC (running LabVIEW).

## BOM

|Item        |Quantity   |Price   |Total   |
|------------|-----------|--------|--------|
|10ft USB-A to USB-B Cord |1         |$ 9.99 |$ 9.99|
|Subsystem Total |||$ 9.99|

*User-Interface Subsystem will utilize the DAQ purchased in DAQ subsystem

## References

USB Cord:
https://www.amazon.com/Printer-Braided-Keyboard-Controller-Microphone/dp/B095HPPZ4G?th=1 

NI USB-6215 DAQ Specs:
https://www.ni.com/docs/en-US/bundle/usb-6215-specs/page/specs.html 


