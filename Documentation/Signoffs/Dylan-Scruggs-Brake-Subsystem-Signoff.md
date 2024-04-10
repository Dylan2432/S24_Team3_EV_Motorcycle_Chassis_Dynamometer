# Brake Control System

## Functionality
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp; The Brake Control System is being implemented to allow for simulation of the bike's brake to be captured through controlled inputs. This system will be the driving factor behind ensuring the customer's desires are satisfied. With this system the user shall be able to apply a desired load to observe how the bike reacts to different braking and road grade loads. This will be made possible with the implementation of a 3-phase AC electric motor, connected to the drum mechanically, to operate as a generator. With this, a load bank will be attached to the output of the generator to dissipate generated electrical energy in order to provide different loads. Through the coaction of these components, this subsystem will be able to deliver desired metrics over various simulated conditions.

## Constraints
|No.        |Constraints   |Origin   |
|---|---------------------|--------|
|2|Be able to safely operate the motorcycle up to 74 km/h.         |Safety Constraint |
|3|Capture current and voltage supplied to the drive motor along with vehicle speed, torque, horsepower, and rpm and display all results.       |Design Constraint|
|5|Comply with all relevant codes and standards listed in II. Ethical, Professional, and Standard Considerations, Section B below.         |Safety Constraint |
|7|Support incline testing up to 8% road grade.       |Design Constraint|
|8|Support repeatedly testing the bike from 0km/h to 50km/h and then back down to 0km/h.         |Design Constraint |
|13|Be able to simulate the braking system of the motorcycle. (50km/h to 30km/h)       |Design Constraint|

2.) This constraint will be resolved through the use of this system by ensuring the dyno has the ability to slow down operation in the event of dangerous situations. <br>
3.) To help deliver all metrics listed in this constraint, implementation of voltage and current sensors, reading the output of the generator, will be used to calculate torque at different time intervals. Additionally, a rpm sensor will be attached at the drum to derive a value for drum and rear wheel angular velocity. This data will then be transferred to the DAQ in order to be displayed.<br>
5.) This system will follow all relevant codes and standards listed in the conceptual design and proposal. One standard with a high magnitude of importance that will be met throughout this design is NFPA 79 – 10.7.1. This standard encompasses that any electrically operated industrial device must posses an emergency stop. This will be implemented through the collaboration of both this system as well as mechanical design.<br>
7.) To support incline testing, the coaction of this system and further designed systems will be needed. The design within the road simulation subsystem will be implemented and use the generator and load bank to simulate these road grade changes.<br>
8.) The braking system will be used within this testing to ensure full stoppage of the bike and support stop time. The bike will slow to a stop on its own, once letting go of the throttle, but if required to stop in a faster time span than the braking subsystem will be activated as well.<br>
13.) This constraint presents than main reason for implementing this braking system. To simulate speed drops from 50km/h to 30km/h, within a desired time span, a load bank must be used. This will allow for the user to select a desired load (in kilowatts) in order to allow the generator to simulate a braking effect on the drum.<br>

## Schematics
### Baldor EM3218T 3-Phase AC Motor
![image](https://github.com/Dylan2432/Capstone1_Team3_EV-Motorcycle-Chassis-Dynamometer/assets/100161668/63679f90-e452-4ada-b278-12ee7a131072)

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The diagram above shows a layout of the Baldor EM3218T 3 Phase AC Motor that was chosen based on the specs and calculations. This motor will be used as a generator to produce electrical energy so that it can be dissipated and cause a braking affect. The process and reason for choosing this motor is further explained in the analysis section below.

### Arcol FFLB – 19” Rack Mountable Resistive Load Bank (5kW)
![image](https://github.com/Dylan2432/Capstone1_Team3_EV-Motorcycle-Chassis-Dynamometer/assets/100161668/8a1a1fa8-9ba1-4597-afd9-520b0705ba29)

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The picture above portrays the load bank selection made. However, the voltage rating listed in the picture as 110V will actually be 230V. This decision was made based on the metrics within the data sheet matching with the range of values in the motor’s datasheet.

### Motor to Load Bank Wire Diagram
![image](https://github.com/Dylan2432/Capstone1_Team3_EV-Motorcycle-Chassis-Dynamometer/assets/100161668/2b5828b9-09b7-4841-bcc1-13111f8a0420)

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;This wire schematic shows how the electrical motor (in generator mode) will produce and output electrical energy to the load bank to be dissipated. The process in which this goes through will be further explained in the analysis. Precise sensor specifications will be discussed within the sensor integration subsystem. 

## Analysis
### Motor Analysis
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The Baldor EM3218T 3 Phase AC Motor was the chosen motor to use to simulate braking most efficiently and effectively. This was done through a series of well thought out steps to prove its use. 

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The first specification that was considered was that it is a synchronous motor. To further explain this, AC motors consist of 2 main types: induction and synchronous. When trying to use an induction motor as a generator an optimal, efficient system is not produced. This is due to induction motors’ maximum power being limited by the rated current of its windings. Therefore, the use of a synchronous motor is apparent as it can operate as an alternator. One drawback of both motors is that synchronous speed must be exceeded by the mechanical input. To find this value, the equation: NS (synchronous speed) = (120*frequency)/(number Poles) can be used. When plugging in the specs of this motor from the data sheet attached in references, the synchronous speed comes out to 1800. To resolve this issue, the mechanical team will implement a gear ratio system to achieve this speed once throttle is initially engaged. 

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;After the type of motor was selected, the next factor was choosing a motor with the correct horsepower, voltage, current, and RPM rating. The voltage and current ratings, although important, followed deciding if the rated RPM and power ratings were usable. To decide the range of power needed, the rated maximum power output of the bike was used. This value was set at 3500 W. To find the RPM range, a variety of equations were used. First, the maximum speed of the bike, 74 km/h, was converted to 20.56 m/s. Then, the equation for angular velocity was implemented which is ((Speedmax)*(60))/((π)*(Diameter)). This equation was then used to find the maximum angular velocity of the rear wheel of the bike to determine a baseline rpm value. This was done by taking the rear tire dimensions (110/70-16 6PR) and deriving the total diameter of the rear wheel (tire + rim). To do this, the sidewall height of the tire was solved from: ((Aspect Ratio)/100)x(width). The 70 in the tire label is the aspect ratio and the 110 is the width in millimeters. This outputted a value of 77 mm. Then, the total diameter was solved through the equation, (2*(Sidewall Heigth))+(Rim Diameter). The rim diameter in this case is the 16 in the tire label in inches. After plugging in these values, the total diameter of the rear wheel comes out to 560.4 mm or 22.06 inches. This was then plugged back into the previously stated angular velocity equation as well as the maximum speed to generate that the bike’s maximum rear wheel angular velocity is 700.69 rpms. Now, different drum diameters can be plugged into this equation to see what the maximum angular velocity would be. To further support drum diameter testing, the minimum diameter requirement of the drum has been solved. This is solved through the equation: Min radius(drum)=  TorqueMax/ForceMax. To find the maximum torque and maximum force values, more bike specs are used as well as previously solved metrics. The max torque of the rear wheel is defined as Torque(WheelMax)=  PowerMax/RPMMax. Therefore, the rated output power (3.5 kW) and the maximum angular velocity of the wheel (700.69 rpms) are plugged in and portray that the maximum torque the rear wheel can produce is 4.995 N-m. In order to find the force, further calculations are needed. To start, F=ma, and the weight of the bike is given as 120kg. From this, it can be seen that acceleration needs to be solved for. This is done through the equation a=(Velocity(Final)-Velocity(initial))/time. The maximum speed is presented as 74 km/h on the provided spec sheet, and the time used is the time it takes to go from 0 to its max speed (7 seconds). Through these calculations, the max acceleration is 2.94 m/s^2. With these values the force can be found to be 352.8 N. With the max torque and force value, the minimum radius of the drum can now be found to be 0.0142 meters, further simplified to be a minimum diameter of 1.118 inches. Therefore, any angular velocity found from using this diameter or greater proves to work for the system. 

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;With this analysis, it can be proven that this is the correct motor to be implemented in order to satisfy all requirements.

### Load Bank Analysis
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Selection of a load bank that is compatible with the motor selected is crucial to allow various loads to be simulated. This selection process was not as in depth as the motor as all specifications were already proven above. This selection came down to ensuring all parameters match the motor’s parameters listed on each data sheet. Each of these data sheets are referenced below to prove compatibility. 

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The operation of this load bank consists of being supplied electrical energy from the generator and dissipating various amounts as heat based on the load selected. This load bank holds a variety of different load choices up to 5 kW. This load will never exceed 5 kW as the motor is only rated at 3.6 kW. Through the application of selecting and applying different loads, this subsystem will be able to simulate the effects of braking.

### Wire Diagram Analysis
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The wire diagram listed above shows the use of a voltage and current sensor to retrieve the produced volt and amperage values. This is done through the use of 2 3-Phase sensors (further explained in the sensor integration subsystem) where their outputs go to the ATMega 2560 R3. Before outputting electrical energy to the load bank, these voltage and current values are simplified to get power. This power is then multiplied by the change in time using the built in counter of the microcontroller. Through this, the electrical energy being produced by the generator is found and sent to the load bank to be dissipated based on load selection.

## BOM
|Item        |Quantity   |Price   |Total   |
|------------|-----------|--------|--------|
|FFLB-5kW 230V Load Bank|1          |$ 1298.73 |$ 1298.73|
|Baldor EM3218T 3-Phase AC Motor|1         |$ 680.00|$ 680.00|
|Subsystem Total |||$ 1978.73|

## References
Baldor EM3218T 3-Phase AC Motor Datasheet: https://www.baldor.com/api/products/EM3218T/infopacket
FFLB-5kW 230V Load Bank Datasheet: https://www.ohmite.com/assets/docs/acl_fflb.pdf?r=false

