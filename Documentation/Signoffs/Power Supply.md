## Functionality ##
A 30 volt 20 amp variable power supply that is controlled from the user interface. It will be used to support the braking subsystem as to supply the
DC current for the DC injection braking into the AC motor.

## Constraints ##
| No. | Constraints                                                                                     | Origin           |
|-----|-------------------------------------------------------------------------------------------------|------------------|
| 1   | Be able to supply at least 14.75 amps   | Design Constraint |
| 2   | Must not exceed 18.4375 amps       | Design Constraint |
| 3   | Must be controlled from the user interface           | Design Constraint |

1. This value is based off adding 150% of the FLA to the FLA of 5.9. This is further discussed in the braking subsystem
2. This value is based off adding 150% of 125% of the FLA to 125% of the FLA of 5.9. There is risk of damanging the motor if this value is exceeded.
3. It must be able change the voltage or current from the user interface and not from knobs on a power supply.

## Schematics ##
The design will take three  12V 20A DC power supplies and wire them in series so that it is now an equivalent 36V 20A power supply.
This will be the input to the circuit below that uses four LM338 voltage regulators. The circuit is based off a circuit in the datasheet of the LM338.
The LM338 has an output range of 1.2 to 32V.
![image](https://github.com/Dylan2432/Capstone1_Team3_EV-Motorcycle-Chassis-Dynamometer/assets/158186278/bc1c88c0-9af4-40bf-8b69-e65cb53b07f7)
The variable resistor at the bottom changes the voltage output of the circuit and the variable resistor at the output will change the current.

The following circuit uses BJT transistors as switches that are controlled from the user interface that determine if the current will be sent to the winding
of the AC motro to cause braking.
![image](https://github.com/Dylan2432/Capstone1_Team3_EV-Motorcycle-Chassis-Dynamometer/assets/158186278/4f92f643-927f-49b5-8501-40dfd839ff78)
The output of the previous circuit is going into the emitter of a 2N4398 PNP transistor, a resistor is added to the base to protect the BJT. A 2SD1484KT146R BJT collector is connected
to the base of the 2N4398. The base of the 2SD1484KT146R is connected to a resistor and to an output on the DAQ. The DAQ will be able to determine whether the transistors are in saturation or in cutoff. 

## Analysis ##
The LM338 has a max output current of 5A, these can simply be put in parralel and as the input current is 20A and 4 LM338's are being used they are now able to be
used. They are also able to handle 12 amps of current for short periods to time.

The first transistor in the switching circuit must be able to handle at least 20 Amps. The selected 2N4398 has a max current of 30V more than 50% of
the maxiumum current it will detect.
The base current of the 2N4398 is found from the max current going through the tranistor of 20A divided by the minimum HCE of 40. This gives a
value of 500mA. From here the resistor value is found from 36-0.7-4/0.500 = 62.6 so we will use a 75 ohm 1 watt resistor here. The next transistor used is
2SD1484KT146R for it's high HFE of 180. We will need the base collector to be greater than 500/180 = 2.77 mA. The DAQ will be also able to supply a value greater
than this which is needed. The resistor to connect to the base can be calculated by 3.84-0.7/2.77mA = 1133.57 ohms and we will use an 1000 ohm 1/4 watt resistor to gurantee saturation.
## BOM (Bill of Materials) ##
| Item                                                          |  Quantity | Price | Total  |
|---------------------------------------------------------------|------------|----------|-------|--------|
|  ALITOVE DC 12V 20A 240W Power Supply  | 3        | $22.99| $68.97 |
|       2N4398 BJT PNP Transistor  | 1        | $4.52 | $4.52  |
|  LM338T/NOPB Voltage Regulator| 4 | $2.34| $9.36 |
| 2SD1484KT146R BJT Transistor |  1 | $0.40 | 0.40 |
|	     75 Ohm 1 Watt Resistor  | 100  | $0.0745 |	$7.45 |
|	     1000 Ohm 1/4 Watt Resistor  | 10  | $0.55 |	$5.46 |
|2N2905 PNP BJT Transistor|10 | $0.199 | 1.99 |
|Multilayer Ceramic Capacitors MLCC - SMD/SMT 100V 200pF C0G 0805 2%| 1 | $1.99 | 1.99 |
|BK-AHCF-18-R 18 amp fuse| 5 | $6.30 | 31.50 |
| **Subsystem Total**                                            |            |          |       | $67.95 |

## References ##
LM338 datasheet: https://www.ti.com/lit/ds/symlink/lm338.pdf
