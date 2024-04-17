## Functionality
The purpose will be to simulate road grade up to 8% road grade. At the beginning of the test the user will select the desired road grade and load weight. A 3 phase AC motor will be connected to the drum of the dyno mechanically. When a grade higher than 0% is desired a DC power supply injects DC voltage into the windings causing the motor to deaccelerate. This causes the motor to work against the drum. The value the user must set the power supply to will be calculated and displayed on the user interface.

## Constraints
| No. | Constraints                                                                                     | Origin           |
|-----|-------------------------------------------------------------------------------------------------|------------------|
| 7   | Support incline testing up to 8% road grade.                               | Design Constraint |
| 11   | Test at load weights up to 400 lbs.        | Design Constraint |

Both constraints are specified by the customer and are key in determining the amount of resistance that will be applied to the drum as both are in the equation for grade resistance [1]. This will be further discussed in the analysis section.
For constraint 11 the customer wants the bike to be tested at 150, 250, and 400 lbs.

## Schematics
![image](https://github.com/Dylan2432/Capstone1_Team3_EV-Motorcycle-Chassis-Dynamometer/assets/158186278/94dffc19-4dc1-4fae-b7de-2c392e9ae070)
A Dayton 2 HP 3 phase motor will be used. The shaft is hooked up to the drum of the dyno. A NICE-POWER variable DC power supply, 100 V and 10 A, is used to cause DC injection braking. On the user interface the desired road grade and load weight will be selected to find the grade resistance. Then the user interface will display what the power supply must be set at to simulate the desired road grade. The power supply will act as DC injection braking to the motor which will work against the drum. The strength of the torque is proportional to the amount of DC current that is applied to the windings.

![image](https://github.com/Dylan2432/Capstone1_Team3_EV-Motorcycle-Chassis-Dynamometer/assets/158186278/2707264e-52f1-4944-927a-89ee4fdd06c2)
![Torque Curve Motor_230V_2](https://github.com/Dylan2432/Capstone1_Team3_EV-Motorcycle-Chassis-Dynamometer/assets/158186278/8b635250-8c61-4367-a0e2-b7eaff5a9c7b)

Above: Performance Curves of 48ZJ90, the motor being used.


## Analysis
The amount of force that must be generated will be found from the grade resistance from the formula 
F_grade=mg sin⁡β [1] where m is the mass, g is acceleration due to gravity, and β is road grade angle. 
The road grade angle is found from tan^(-1)⁡(β) which at the max road grade 8% is 4.57392°.  
The max amount of force that must be applied will be at the highest mass and the highest road grade angle. 
The highest load mass will be 400 lbs (181.436948 kg) plus the bike weight of 125 kg, totaling to 306.436948 kg. 
The highest angle will be at 4.57392°. This means that to simulate an 8% road grade at 400 lbs, a force of 239.7257518 N must be applied. 
At the other testing weights, 150 lbs(68.0388555 kg) and 250 lbs (113.398092 kg), at a max angle 151.0143769 N and 186.4989264 N must be applied respectively.
The amount of torque created will be based on the distance from the axis of rotation as the force needed is known. If the distance is 4 cm, 9.589 Nm of torque needs to be applied to be equivalent to 239.725718 N of force.


## References
[1] X. Li, J. Ma, X. Zhao and L. Wang, "Intelligent Two-Step Estimation 
Approach for Vehicle Mass and Road Grade," in IEEE Access, vol. 8, 
pp. 218853-218862, 2020, doi: 10.1109/ACCESS.2020.3042656.

Dayton 48ZJ90 Documentation: https://xchanger.com/wp-content/uploads/2015/05/Dayton_48ZJ90_Documentation.pdf
