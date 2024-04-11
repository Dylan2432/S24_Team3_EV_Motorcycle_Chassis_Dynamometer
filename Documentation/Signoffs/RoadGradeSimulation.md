## Functionality
The purpose will be to simulate road grade from -8 to 8% road grade. 
At the beginning of the test the user will select the desired road grade and load weight. 
From there an amount of resistive torque will be applied to the drum to either cause more demand on the motor, 
simulating going uphill, or less demand on the motor, simulating going downhill.

## Constraints
| No. | Constraints                                                                                     | Origin           |
|-----|-------------------------------------------------------------------------------------------------|------------------|
| 7   | Be able to simulate an 8% road grade incline and decline.                                  | Design Constraint |
| 11   | Test at load weights up to 400 lbs.        | Design Constraint |

Both constraints are specified by the customer and are key in determining the amount of resistance that will be applied to the drum as both are in the equation for grade resistance [1]. 
For constraint 11 the customer wants the bike to be tested at 150, 250, and 400 lbs.

## Schematics
![image](https://github.com/Dylan2432/Capstone1_Team3_EV-Motorcycle-Chassis-Dynamometer/assets/158186278/b01b89e7-9733-485d-997c-16bce9430211)
To save on cost and simplicity the braking subsystem will be utilized to apply the resistive torque that is needed based on the user inputs.
After the user inputs the load weight and road grade the grade resistance will be calculated. 
From here the amount of resistive torque that must be applied to the drum will be calculated. 
This will be expanded on in the analysis section.

## Analysis
The amount of force that must be generated will be found from the grade resistance from the formula 
F_grade=mg sin⁡β [1] where m is the mass, g is acceleration due to gravity, and β is road grade angle. 
The road grade angle is found from tan^(-1)⁡(β) which at the max road grade 8% is 4.57392°.  
The max amount of force that must be applied will be at the highest mass and the highest road grade angle. 
The highest load mass will be 400 lbs (181.436948 kg) plus the bike weight of 125 kg, totaling to 306.436948 kg. 
The highest angle will be at 4.57392°. This means that to simulate an 8% road grade at 400 lbs, a force of 239.7257518 N must be applied. 
At the other testing weights, 150 lbs(68.0388555 kg) and 250 lbs (113.398092 kg), at a max angle 151.0143769 N and 186.4989264 N must be applied respectively. 
The system will also be able to simulate downhill driving so it must also be able to apply up to -239.7258 N of force. 
The maximum amount of torque that can be produced from the motor used, Baldor EM3218T is found from the equation 
Power_HP=(Torque_(lb-ft)*Speed_RPM)/5252 with 5 HP at 1750 RPM the amount of torque produced at max rpm is 
15.006 lb-ft which is equivalent to 20.345 Nm. 
The distance the torque must be applied must be 0.08487 m or less at max RPM to achieve 239.7257518N. 
This is from the equation Torque_Nm=F_N*d_m where torque is 20.345 Nm and F is 239.7257518 N. 
To measure the force outputted a CK2500 miniature compression load cell will be used.


## BOM (Bill of Materials)
| Item                                                          |  Quantity | Price | Total  |
|---------------------------------------------------------------|----------|-------|--------|
| CK2500 Miniature Load Cell  |  1        | $245.00| $245.00 |
| **Subsystem Total**                                            |         |       | $245.00 |

## References
[1] X. Li, J. Ma, X. Zhao and L. Wang, "Intelligent Two-Step Estimation 
Approach for Vehicle Mass and Road Grade," in IEEE Access, vol. 8, 
pp. 218853-218862, 2020, doi: 10.1109/ACCESS.2020.3042656.
