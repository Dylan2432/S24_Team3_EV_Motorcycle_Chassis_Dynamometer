# Experimental Analysis Report

## Introduction
The purpose of this report is to evaluate the application of design constraints through various experimental testing procedures. These results will then be compared against their corresponding measure of success in order to prove effective implementation. For results failing to satisfy requirements, future steps will be provided in order to satisfy the design.

## Requirements Table
|ID	|Constraint or Specification	|Applicable Subsystem|
|---|---------------------|--------|
|1|	VFD shall be able to run on a single-phase power input|	Braking Subsystem|
|2	|VFD’s output current shall be greater than the motor’s full load amperage multiplied by the square root of 3	|Braking Subsystem|
|3	|VFD shall be correctly parameterized to the controlled motor’s ratings	|Braking Subsystem|
|4	|An application shall be put into place to dissipate any regenerated power back into the VFD	|Braking Subsystem|
|5	|An E-stop must be present to fully stop operation upon pressing	|Braking Subsystem|
|6	|All electronics shall be properly enclosed and mounted (VFD, Relays, DAQ, etc.)	|All Subsystems|
|7	|DAQ must be able to read the RPM sensor in increments of 1 RPM	|DAQ subsystem|
|8	|DAQ must be able to read the torque sensor in increments of 0.1 N-m	|DAQ subsystem|
|9	|DAQ must be able to read the maximum RPM of motor	|DAQ subsystem|
|10	|UI must be able to start and stop the drive through the HMI	|User Interface subsystem|
|11	|UI must be able to set the frequency reference of the drive through the HMI	|User Interface subsystem|
|12	|UI must be able to save all time-stamped experimental data (torque, rpm, power, DC bus voltage) to an Excel file	|User Interface Subsystem|
|13	|The throttle shall rotate from the starting position to full throttle based on the analog signal from the user interface	|Throttle Control Subsystem|
|14	|The throttle control shall be able to rotate in 1 km/hr increments	|Throttle Control Subsystem|		
		




# Results

## Constraint 1 – Single phase power input to VFD
#### Experimental Design
After verification of transformer’s ability to step up 10 V to 20 V, using the oscilloscope and waveform generator, successful power up of the VFD, from a 120V power source, without signaling a undervoltage alarm was monitored. A yes was recorded in the table for each successful start-up.
#### Results
|Trial No.|Result|
|--|---|
|1|Yes|
|2|Yes|
|3|Yes|
|4|Yes|

#### Interpretation of Results
Through this experiment, the implemented transformer correctly stepped up 120V to 240V. This allowed for successful start up of the VFD in each trial. 
#### Conclusion
This constraint was proven to be satisfied.

## Constraint 2 – VFD output current properly derated for single phase usage
This constraint is not traditionally testable; however, correct derating can be proven through the VFD’s and motor’s specs.
#### Motor Specs 
![image](https://github.com/user-attachments/assets/432d374d-eb9f-402e-ba3e-8b9878a36046)

#### VFD Specs
![image](https://github.com/user-attachments/assets/a55d3ce6-d27a-4cf8-9ea8-2241956ce4d6)

#### Interpretation of Result
Since the controlled motor’s full load amperage times the square root of 3 (1.9*√3 = 3.3) is less than the VFD’s max output current (3.5 A), the VFD is correctly sized for single phase power usage.
#### Conclusion
This constraint was proven to be satisfied.

## Constraint 3 – VFD must be correctly parameterized to the motor’s ratings
#### Experimental Design
After verification of correct wiring between the motor and VFD, Yaskawa Drive Wizard was used to correctly parameterize the drive for the controlled motor. These settings were confirmed through monitoring the current output from the drive at different applied frequencies.
#### Results
Trial 1:
|Frequency (Hz)|	Current (A)|
|--|--|
|10|1.31|
|20|1.32|
|30|1.33|
|40|1.35|
|50|1.36|
|60|1.38|



Trial 2:
|Frequency (Hz)	|Current (A)|
|--|--|
|10|	1.30|
|20	|1.32|
|30	|1.34|
|40	|1.35|
|50|	1.37|
|60	|1.38|

#### Interpretation of Results
These two trials prove that the VFD was correctly parameterized for the controlled motor due to the output current never reaching or exceeding the motors FLA (1.7 A).
#### Conclusion
This constraint was proven to be satisfied.

## Constraint 4 – Regenerated power must be dissipated
This constraint is not yet proven due to system not being mechanically mounted to the testing surface. However, the selected braking resistor is sized to dissipate 400 Watts of the maximum expected 245 Watts. Tests will be conducted, once mounted, to prove this resistor’s ability to dissipate regenerated power by monitoring the DC bus voltage level and the output to the braking resistor.

## Constraint 5 - An E-stop must be functionally present 
#### Experimental Design
Upon verification of correct wiring of the E-stop to the VFD, successful functionality was tested through various attempts to stop the motor. A yes was recorded in the table, under the stop section, for each successful emergency stop. A no was recorded, under the start section, for attempting to start while the E-stop was still latched. 
#### Result

|Trial No.	|Stop|	Start|
|--|--|--|
|1	|Yes|	No|
|2	|Yes	|No|
|3	|Yes	|No|
|4|	Yes	|No|
 
#### Interpretation of Result
Through this experiment, the emergency stop’s functionality was proven to operate correctly.
#### Conclusion
This constraint was proven to be satisfied

## Constraint 6 – Electronics shall be properly enclosed and mounted 
This constraint is not traditionally experimental but was satisfied.

## Constraint 7 – DAQ must be able to read the RPM sensor in increments of 1 RPM
#### Experimental Design:
The objective of this experiment was to demonstrate the USB-6003’s ability to precisely measure RPM from torque sensor.  A test was ran to show the RPM measurements at different recorded times.  A small section of the test is shown below.
#### Results:

|Time (s)|	RPM|
|--|--|
|5.728	|6.687|
|5.749|	7.421|
|5.769	|6.108|
|5.789|	5.022|
|5.813|	5.914|
|5.837|	9.019|
|5.860	|13.818|

#### Interpretation of Results:
In this experiment, we are not only able to prove that the RPM is measured in increments of 1, but that it is able to measure changes smaller than 1, with measurements precise to the thousandths place.
#### Conclusion:
This constraint was proven to be satisfied.

## Constraint 8 – DAQ must be able to read the torque sensor in increments of 0.1 N-m 
#### Experimental Design:
This experiment aimed to test and confirm the DAQ’s precision by measuring torque from the torque sensor.  The table shown below displays the torque values during a small sample of the test.
#### Results:

|Time (s)	|Torque (N-m)|
|--|--|
|5.022	|0.826|
|5.045	|0.920|
|5.092	|0.994|
|5.133	|1.065|
|5.155	|1.118|
|5.202	|1.230|
|5.317|	1.303|
	
#### Interpretation of Results:
As seen from the results above, the torque is shown to be going up by less than 0.1 N-m on each measurement. The torque is aleo shown to be measured to the thousandths place, which exceeds the 0.1 N-m increment needed for the constraint.
#### Conclusion:
This constraint was proven to be satisfied.

## Constraint 9 – DAQ must be able to read the maximum RPM of motor
#### Experimental Design:
For this experiment, it is known that the motor is rated for a maximum speed of 1800 RPM.  It is also known that the output signal of the torque sensor is rated for 0-10 V.  This experiment is tested to see if the DAQ can handle the input signal within this voltage range, ensuring that the full signal is accurately measured.
#### Results:
![image](https://github.com/user-attachments/assets/2eb160c3-00c8-4e26-907c-c49e6cd11d47)

#### Interpretation of Results:
The graph illustrates the RPM range from 0-1800 RPM, with measurements taken at different size increments.  As you can see, the DAQ was able to successfully measure at 1800 RPM.
#### Conclusion:
The constraint was proven to be satisfied. 
	
## Constraint 10 - UI must be able to start and stop the drive through the HMI
#### Experimental Design:
The User-Interface is connected to the start/stop of the drive through a NO relay with the coil connected to a DAQ digital output pin. The output is controlled through a stationary button on the HMI that toggles on each press again.  
The experiment is set up to apply a frequency (0-60 Hz) on the drive, and then the user will press the “start/stop VFD” button and observe the outcome. Once the motor has properly activated, the same “start/stop VFD” button will be pressed, and the outcome will be observed.
#### Results:
|Trial	|Result|
|--|--|
|Start Check 1	|Pass|
|Stop Check 1	|Pass|
|Start Check 2|	Pass|
|Stop Check 2	|Pass|

#### Interpretation of Results:
The HMI start/stop capabilities were thoroughly tested and proved to pass in every scenario. These capabilities are shown to operate correctly in each of the experimental videos in Github.
#### Conclusion:
This constraint was proven to be satisfied.

## Constraint 11 - UI must be able to set the frequency reference of the drive through the HMI
#### Experimental Design	:
The User-Interface is connected to the drive through a DAQ analog pin outputting 0-10 VDC. This voltage controls the frequency of the running motor (0-60 Hz). The experiment is to change to various 0-60 Hz frequencies on the HMI and record the outputs of the motor and drive to verify proper operation.
#### Results:
Set at 5 Hz:
![image](https://github.com/user-attachments/assets/12ab6b7b-60b4-4203-ac69-2161d3cdc006)
Set at 10 Hz:
![image](https://github.com/user-attachments/assets/ab13e0a0-7916-4af2-83ad-193610fea934)
Set at 20 Hz:
![image](https://github.com/user-attachments/assets/466d04c4-3dfc-47ba-b88f-8c9e39458fb7)

#### Interpretation of Results
As can be seen in the previous photos and a video on Github, the HMI properly adjusts the frequency reference. The video verifies that the frequency on the HMI is the same as the frequency on the VFD display. This is also verified by the RPM display (on HMI) changing up and down in accordance with the frequency. 
#### Conclusion
This constraint was proven to be satisfied.

## Constraint 12 - UI must be able to save all time-stamped experimental data (torque, rpm, power, DC bus voltage) to a spreadsheet
#### Experimental Design:
The experimental data captured throughout a test run must be captured for later analysis by the user. This is done by saving each desired data point into an array on LabVIEW, and at the end of the run “stop” will be pressed on the HMI. This will prompt the user to save the data to a desired file name and type (.xls). The experiment put into place was to complete a full mock run of the system capturing torque (N-m), speed (RPM), power (W), and DC bus (V). The device tested for this experiment was a battery-operated handheld drill. 
#### Results:
![image](https://github.com/user-attachments/assets/3efb98e5-04a6-4fb1-ae69-1ae0e5a0597e)

#### Interpretation of Results:
As shown in the table above, all the data captured in the experiment is saved properly to a spreadsheet. The data aligns with the proper elapsed time, so it is time-stamped as the constraint specifies. The entire run of this experiment is displayed in the video on GitHub. 
#### Conclusion:
This constraint was proven to be satisfied.

## Constraint 13 - The throttle shall rotate from the starting position to full throttle based on the analog signal from the user interface
#### Experimental Design:
The throttle control system is operated by a stepper motor, driven by a compact motor driver. The motor driver is controlled by an Arduino microcontroller, which can be programmed to perform various functions depending on what the user needs. For this system, the Arduino was programmed to read in a 0-5V analog signal input and proportionally rotate the stepper motor within a range of 0 to 90 degrees. The rotation is determined by the ratio of the input signal, providing precise and consistent control over the throttle position. To test the results of this several tests were run to ensure that the throttle rotates to the exact angle that it needs to based on the users input.
#### Results:
|Trial	|Result|
|--|--|
|0V	|0°|
|2.5V|	45°|
|5V	|90°|

#### Interpretation of Results:
Although the exact angle of full throttle will change depending on the bike, a 90-degree full throttle was used as a baseline for testing purposes. This full throttle angle can be easily adjusted in the code so that it will suit any bike. However, using the 90-degree throttle for every user input the motor rotated to the correct position.
#### Conclusion:
This constraint was proven to be satisfied.

## Constraint 14- The throttle control shall be able to rotate in 1 km/hr increments
#### Experimental Design:
This constraint ensures that the user will have accurate enough control over the throttle to control it within 1 km/hr increments. This does however depend upon the max speed of the bike being tested. The nema 17 stepper motor that was used has a baseline step angle of 1.8, and since a 90-degree max angle is being used that only gives the user 50 steps within that range. If the bike has a max speed over 50 km/hr or if the max throttle angle is less than 90 degrees, then the user would not be able to control the throttle in 1 km/hr increments.
To fix this a motor driver with a micro stepping was used. This allows the per step angle to be lowered and increases the amount of steps available within the throttles range at the cost of torque. Since throttles require relatively low torque to be rotated this was not an issue.  
#### Results:
![image](https://github.com/user-attachments/assets/cefb82e7-cda6-42ec-bede-45988a9b6108)

#### Interpretation of Results:
This from the datasheet of the A4988 motor driver that was used. It shows the step angle ratio and what pins to set high to achieve it. If it was set to ¼ it would change the per step angle to 0.45 and give the user 200 steps within the 90-degree range which is more than enough steps to control the throttle in 1 km/hr increments.
#### Conclusion:
This constraint was proven to be satisfied.

# Conclusion
|ID|	Constraint or Specification|	Constraint Met?|
|---|---|---|
|1	|VFD shall be able to run on a single-phase power input|	Yes
|2|	VFD’s output current shall be greater than the motor’s full load amperage multiplied by the square root of 3|	Yes|
|3	|VFD shall be correctly parameterized to the controlled motor’s ratings|	Yes|
|4	|An application shall be put into place to dissipate any regenerated power back into the VFD|	N/A|
|5	|An E-stop must be present to fully stop operation upon pressing	|Yes|
|6	|All electronics shall be properly enclosed and mounted (VFD, Relays, DAQ, etc.)	|Yes|
|7	|DAQ must be able to read the RPM sensor in increments of 1 RPM	|Yes|
|8	|DAQ must be able to read the torque sensor in increments of 0.1 N-m	|Yes|
|9	|DAQ must be able to read the maximum RPM of motor|	Yes|
|10	|UI must be able to start and stop the drive through the HMI	|Yes|
|11	|UI must be able to set the frequency reference of the drive through the HMI	|Yes|
|12	|UI must be able to save all time-stamped experimental data (torque, rpm, power, DC bus voltage) to a spreadsheet|	Yes|
|13	|The throttle shall rotate from the starting position to full throttle based on the analog signal from the user interface	|Yes|
|14	|The throttle control shall be able to rotate in 1 km/hr increments	|Yes|




