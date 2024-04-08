# Throttle Control Subsystem

## Functionality
The purpose of the Remote Throttle Control Subsystem is to be able to adjust the speed of the EV bike while it is on the dyno without having to be near the bike and adjust it manually. It allows the adjustments of the speed to be made based on the input of the user and be able to set test runs to change to multiple speeds within a single test run. This is done for safety concerns so that there does not have to be a user on the bike while it is running on the dyno and instead can be operated from a safe distance.

## Constraints
| No. | Constraints                                                                                     | Origin           |
|-----|-------------------------------------------------------------------------------------------------|------------------|
| 1   | Be able to be fully operated remotely.                                                          | Safety Constraint |
| 2   | Support repeatedly testing the bike from 0 km/h to 50 km/h and then back down to 0 km/h.        | Design Constraint |
| 3   | Be able to adjust operating speeds in 1 km/h increments and measure response time.              | Design Constraint |

1. This constraint is set into place to keep all personnel operating the equipment and testing the bike safe. By allowing it to be operated remotely, all testing can be done at a safe distance, so no one will be injured in case something were to go wrong. It also serves as a way to increase the accuracy of testing by not having to worry about the weight of someone on the bike while it is running and being able to precisely change the speed at desired increments. 

2. This is a specification that was made by the customer. According to this, test runs must be incorporated into the programming for the user interface so that the user can create set runs to allow the bike to go through without having to change it every time. For example, the user should be able to select a test run through the user interface that will make the bike go from 0 km/h to 50 km/h and then back to 0 km/h, and the bike will perform this run without having to manually enter in each step every time. This will make the testing procedures much more convenient for tests that need to be repeated.   

3. This is an extremely important constraint that was requested by the customer because it specifies how accurate the throttle control system needs to be. This also provides evidence for why a remote throttle control system is needed because precisely incrementing the speed by 1 km/h manually with someone on the bike is difficult to achieve and can be inaccurate. This constraint affects the design of the system because in order to achieve this, a motor must be used that can be accurately controlled enough to make these small adjustments to the throttle handle.

## Schematics


![image](https://github.com/Dylan2432/Capstone1_Team3_EV-Motorcycle-Chassis-Dynamometer/assets/158241294/0e50a1b1-a29c-47ee-92d3-a56e51253466)


### Figure 1 – Throttle Control Assembly
The first schematic shown in the figure is an overview of the system as a whole. It shows exactly how a clamp will be used in conjunction with a motor to control the throttle of the bike. It is important to note that without having access to the Bob bike yet or a 3D model of it, a generic throttle handle was used for the diagram. However, with the subsystem that has been designed, it will not only work with the Bob bike but will also be compatible with any other bike used.  This system can be broken down into four different parts: The clamp, motor, driver, and microcontroller. 
The first part is the clamp. This has been custom made not only to fit the motor being used but also to be fitted to a motorcycle's throttle handle. This system will be 3D printed that to make it more cost-efficient and provide the desired results for this specific outcome. 


![image](https://github.com/Dylan2432/Capstone1_Team3_EV-Motorcycle-Chassis-Dynamometer/assets/158241294/5ae2bca4-eb48-4758-979d-d04601b481cf)



### Figure 2 – Clamp
The motor that will attach to this clamp is a Nema 17 motor. A full explanation as to why this specific motor was chosen can be found in the analysis section. In order to connect the microcontroller to the motor, a driver must be utilized. For this system, an A4988 driver will be used to control the motor with a 24V DC power supply to power the motor. The wiring to connect these components can be found in figure 3 below. 


![image](https://github.com/Dylan2432/Capstone1_Team3_EV-Motorcycle-Chassis-Dynamometer/assets/158241294/7a8f28d8-476d-4231-9fb9-12884f6cb1a0)


### Figure 3 – Full Wiring Diagram
In the middle of the diagram, you can see that the A4988 driver is connected to the motor through 4 pins on the right of it, and the motor is powered by the 24V DC power supply connected to the two pins in the top right corner. A Decoupling capacitor will be added to protect the chip and motor from any voltage spikes. The bottom right corner is connected to the Arduino and this supply’s power to the logic pins. The two pins in the bottom left corner are what control the motor, and these will connect to the output pins on the Arduino. The two pins above that that are connected are the sleep and reset pins and need to be connected for the driver to run. Finally, the top left corner will have MS1 set to high to convert the motor from 200 steps/rev to 400 steps/rev, the reasoning behind this will be explained further in the analysis.

## Analysis
The goal of this subsystem is to create a way to remotely control the throttle of an EV bike while it is running on a dyno. The solution that has been created will accomplish this using four main components: microcontroller, driver, motor, and clamp. With these components, the throttle can be controlled by the user simply with just programming in the microcontroller. This will comply with all the constraints given and accomplish the results desired by the customer. First, a full explanation of each component and how it will all work together must be given.

The microcontroller lies at the core of all of this. It is used because this is the most efficient way to take an input signal from something and run preset calculations to determine what will be sent to the motor. The same microcontroller that is being used to gather the input RPM from the bike, ATMega 2560 Board, will be used to send the instructions to the motor. This reduces any time delays or confusion by communication between two microcontrollers by doing all of it on a single one. However, the microcontroller cannot efficiently communicate directly with the motor and will need a device to fix this problem.

The driver is the middleman between the microcontroller and the motor. It takes input from the microcontroller and sends it to the motor. The driver also takes the power of the power supply and sends it to the motor. The A4988 has a current limiter that can adjust the current going to the pins of the motor by simply adjusting the screw in the bottom middle of the driver. This will ensure that the motor is operating under safe currents and won’t be damaged. However, the driver has other equally important roles. 

The A4988 driver has an extremely useful feature that will be utilized in this project and that is microstepping. This will allow the motor to have finer movement control compared to the base setting. By setting the MS1 to high it will put the driver in half-step mode which essentially doubles the number of steps a motor can take in a full revolution. This will be useful in this project because most throttle handles only rotate around 90 degrees so in the base setting for the motor of 200 steps/rev, or 1.8 degrees/step, only gives you 50 steps to control the throttle with. Considering the bike can reach top speeds of over 80 km/h and the throttle needs to be controlled in 1 km/h increments, according to constraint 3, more steps will be needed to precisely control the throttle. Putting the throttle in half-step mode changes the steps/rev to 400 and will allow the throttle to be controlled at the desired level of precision.  

The motor is going to be the muscle behind turning the throttle handle. It gets the instructions from the microcontroller and driver does exactly what they instruct it to do. The most important aspect of the motor is making sure that it is light and can be easily mounted, but also can be controlled with enough precision to make small adjustments in the throttle and strong enough to rotate it. The Nema 17 stepper motor being used weighs less than a pound so mounting weight won’t be an issue and it works perfectly with both the driver and microcontroller. Luckily since throttles need to be easily turned by humans using just their wrist, the motor does not need to be able to supply that much force. The only issue with the motor is getting the throttle handle to rotate as the motor spindle rotates.

This is where the clamp comes in. The clamp needs to be able to attach the motor to the throttle so that as the motor turns the throttle handle will also turn. It was determined that the most efficient way to do this is by 3D printing a custom clamp. That way it is both affordable and works perfectly for the application it is being used for. The design that was made in figure 2 is similar to a double C-clamp. The reason for this is so that the motor spindle can be perfectly in line with the throttle handle and the degrees of rotation won’t be thrown off once it is tightened down. It is made so that it be easily connected and removed simply by just unscrewing it. Also, the ends of each screw are curved so that it will conform to the throttle handle and add more friction to keep it from sliding. These ends will also be screwed on so that the screws can be removed from the clamp if needed and fine adjustments can be made so that curved ends won’t get in the way of tightening the clamp down. A safety measure that will be implemented is adding silicon tape to the throttle to protect the handle from any possible damage from the clamp and add extra friction to ensure the clamp doesn’t slide at all when being rotated. 

With this setup, the throttle handle of the bike can now be completely remotely controlled by the user. The only other part is programming inside the microcontroller to adjust the speed of the bike as needed. This will depend on several factors on the bike including the max degrees of rotation on the throttle handle, the change in RPM per degree of rotation, and the max RPM of the bike, so it will need to be tested once the bike can be set up. This will also be in conjunction with the user interface subsystem to connect what the user inputs and output instructions to the motor. The last part is mounting the motor to the end of the throttle handle but since this mount will likely attach to whatever dyno the Mechanical Engineering team decides to use it will have to be chosen based on their selection. 

## BOM (Bill of Materials)
| Item                                                          | Item #     | Quantity | Price | Total  |
|---------------------------------------------------------------|------------|----------|-------|--------|
| Stepper Motor Nema 17 Bipolar 40mm 64oz.in(45Ncm) 2A 4 Lead  | 17HS16-2004S | 1        | $12.99| $12.99 |
| A4988 Stepper Motor Drive with Heat Sink for Arduino          | MG046      | 1        | $6.99 | $6.99  |
| EMITEVER 24V DC Power Supply, 96W, 120V AC to 24V DC Converter 4amp | EM-DC-96W | 1        | $29.99| $29.99 |
| 2 Rolls 1IN X 10FT Grip Tape, Rubber Tape, Silicone Tape, Grip Tape for Handles | MB-YCJ-0131 | 1 | $11.99 | $11.99 |
| **Subsystem Total**                                            |            |          |       | $61.96 |

## References
- HowToMechatronics. (08/2023). Arduino Stepper Motors - The Ultimate Guide. Retrieved from [https://howtomechatronics.com/tutorials/arduino/stepper-motors-and-arduino-the-ultimate-guide/](https://howtomechatronics.com/tutorials/arduino/stepper-motors-and-arduino-the-ultimate-guide/) [Accessed on 3/30/2024]
