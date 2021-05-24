# ELEGOO SMART ROBOT CAR
The Eleego Smart Robot Car or ESRC is an arduino based smart robot car that requires no soldering or special tools.
This robot car can be built using the Elegoo Smart Robot Car Kit.
The Kit includes the following components:
1.	2 LiPo batteries and a charger.
2.	Arduino Uno R3 card.
3.	2pins, 3pins, 4pins, 5pins & 6pins cables. 
4.	Line Tracking Module.
5.	I/O Expansion Board.
6.	L298N 
7.	Cell Box
8.	DC Motors
9.	Tires
10.	USB Cable
11.	Fixing Plate
12.	Ultrasonic Sensor
13.	Bluetooth Module
14.	Insulation Tapes
15.	Acrylic Chassis
16.	IR Remote
### DESCRIPTION OF THE ESRC
The ESRC is a 4-wheel design with two levels (i.e it has two layers of acrylic chassis mounted on each other).
On the top layer of the robot, we have Ultrasonic sensor mounted on the servo motor. The combination is then placed on the acrylic chassis. Other components placed on the top acrylic chassis include the cell box which contains the 2 LiPo (Lithium Polymer) batteries. The I/O Expansion borad is connected directly above the arduino Uno R3 card.
The lower level of the robot has the L298N placed on it with the four DC motors placed around the four corners to accommodate the four tyres. Beneath the  acrylic chassis, we have the Line Tracking Module. The ESRC is controlled by either the Bluetooth module or the IR Remote control.
The ESRC allows you to build;
1.	A Bluetooth controlled car.
2.	IR controlled car.
3.	Obstacle Avoidance car.
4.  Line Tracking or Following car.
In this project, we will be building all four of this, but first lets proceed to assemble the Elegoo Smart Robot Car

### BUILDING THE ELEGOO SMART ROBOT CAR
The ESRC is designed in such a way that it can be assembled in just a couple of easy steps. It takes about 45 – 60 minutes to assembly for a first timer but subsequent attempts take lesser time to complete. Assembling the ESRC can be completed in about 12 distinct steps. As we work you through these steps, some precautions will be given to ensure accurate assembly of the robot.
#### STEPS IN ASSEMBLING THE ESRC
###### LEVEL 1: THE GROUND ACRYLIC CHASSIS
1. Install and mount the Line Tracking module beneath the lower acrylic chassis. Caution: Take note of the direction of the cable port and orientation to the big hole.
2. Mount the L298N on the chassis.
3. Assemble and then mount the DC motors on the sides of the acrylic chassis. Caution: The aluminum blocks and motor power cables should be on the same side. 
4. Connect the tyres to the four DC motors.

###### LEVEL 2: THE TOP ACRYLIC CHASSIS
5. Mount the elegoo Uno R3 card on the centre of acrylic chassis.
6. Assemble the SG90 servo motor and mount on the chassis.Caution: Pay attention to the inserting direction of the servo cable terminal. Orange is the signal wire and should be connected to pin 3 on the Uno card.
7. Assemble the Ultrasonic Sensor Module and place it on the SG90 servo motor.
8. Mount the Cell Box on the Chassis
9. Connect the two acrylic chassis together using the rods provided. 

#### THE BLUETOOTH MODULE
The ESRC uses a generic bluetooth module that is similar to HC08 or HC05 (ZS-040) bluetooth module. The bluetooth module
makes use of the arduino serial I/O ports for communication. The serial lines are the data-in and data-out which are equivalent to the digital pins 1s and 0s on the arduino uno card. The above information actually requires us to allows unplug the bluetooth module whenever we want to upload our sketches to the arduino uno via the usc cable so as to avoid conflict in the communication lines as the USB and bluetooth module share the same I/O port.
###### PIN ON THE BLUETOOTH MODULE
The bluetooth module has 5 distinct sets of pins.
1. Rx (Receiver)
2. Tx (Transmitter)
3. GND (Ground)
4. +5v
5. +3.3V
###### CONNECTION ON THE ARDUINO UNO R3 CARD
- Tx is connected to pin 1 on the card.
- Rx is connected to pin 0 on the card.
- GND is connected to GND on the board.
- 5v is connected to 5v on the card.
- 3.3v is connected to 3.3v on the card.

For every remote controlled system, we consider two things:
- The device to be controlled (The ESRC in this case).
- The device we want to use to control (The Elegoo Buetooth BLE tool APK).

###### TESTING THE BLUETOOTH MODULE
A sketch file is written to test the bluetooth module to ensure healthy connection between the arduino uno R3 card and the Elegoo Bluetooth BLE APK. This sketch file basically just blinks the LED (Light Emitting Diode) on the board. We upload the sketch file to the board via the usb cable provided in the kit. The sketch file written is called "ESRC_Bluetooth_Test.ino". Ensure that the bluetooth isn't connected on the board while uploading due to reasons stated earlier. After uploading, connect the bluetooth module on the board and test using the APK.

###### CONTROLLING THE ESRC USING THE BLUETOOTH MODULE
To actually control the ESRC car using the bluetooth module, the sketch file "ESRC_Bluetooth.ino" is uploaded to the
uno board and the APK is used to control the ESRC.

### The IR Remote Control
The InfraRed Remote control sends out pulses of infrared light signals. The pulses are modulated at about 38kHz to try and reduce interference. You can't see infrared lights with your naked eyes. However, it may be visible with the use of a digital camera, cellphone camera, or camcoder. The ESRC has a receiver on embedded on the IO expansion board.
Each button on the IR remote control sends a unique code. We can see these codes to control the car.

###### PIN ON THE IR Sensor
It has 3 distinct pins:
1. Output pin
2. Ground GND
3. Vcc (+5v) pin

###### CONNECTION ON THE ARDUINO UNO R3 CARD
- Output pin is connected to pin 12.
- GND is connected to GND.
- 5v is connected to 5v.

###### TESTING AND GETTING THE CODES OF EACH BUTTON ON THE IR REMOTE CONTROL.
To actually test and get the unique codes of each butoon on the IR remote, a very simple sketch file is written to implement it. The sketch file is called "ESRC_IR_Test.ino". For the sketch file to actually work properly, we will be using an external library provided by Arduino to actually communicate with our IR sensor. The file can be found in the libraries folder and it is called IRremote. You can include it in your sketch file. Upload the sketch file to your uno card.

###### CONTROLLING THE ESRC USING THE IR REMOTE CONTROL
To actually control the ESRC car using the IR remote control, the sketch file "ESRC_IR.ino" is uploaded to the
uno board and the APK is used to control the ESRC.



#### OBSTACLE OR COLLISION AVOIDANCE 
To implement the collision avoidance, the two most important components used to achieve this are:
- The Ultrasonic sensor: The ultrasonic sensor is used to detect the obstacles. The sensor is always aimed forward when the car is moving.
- The SG90 Servo Motor: The sensor is mounted on the servo motor to scan 180deg. The scans in three (3) positions - left, right and forward.

###### MODE OF OPERATION
When the car detects an obstacle, it stops and then scans in both direction and determines which direction has the longest distance and moves there. The calculation of the distance is actually based on speed of sound, echo location e.t.c
From our high school physics, we all know that sound travels at the speed of about 343meter/s or 29microsec/cm. The knowledge of echolocation actually lets us know that the ultrasonic sensor actually measures twice the distance, and this makes us divide the distance we get from the ultrasonic sensor by 2.

###### THE CONNECTION OF THE ULTRASONIC SENSOR
The sensor has 4 distinct pins and the connection on the board goes thus:
- The VCC is connected to 5v on the board.
- GND is connected to GND on the board.
- The trigger input is connected to the analog pin A5.
- The Echo Output is connected to the analog pin A4.

###### THE CONNECTION OF THE SG90 SERVO MOTOR
- The vcc is connected to 5v on the board.
- GND is connected to the board GND
- The servo control line is connected to pin 3 of the arduino digital I/O.

###### ALIGNING THE SERVO MOTOR
In implementing the collision avoidance, the proper alignment of the servo motor at 90deg is quite very essential. This ensures that at every 90deg turn of the servo motor, the ultrasonic sensor is facing forward. In order to achieve this, a simple sketch file called "ESRC_Servo_Align_Test.ino" is written and uploaded to the board.

- After uploading the sketch file, the first thing you would want to do is to unmount the sensor from the motor top.

###### RUNNING THE COLLISION AVOIDANCE
Once we have ensured that the servo is properly aligned and we've mounted back the ultrasonic sensor, we can now implement the collision avoidance. Another simple sketcg file is written and it is named "ESRC_Collision_Avoidance.ino".
It is uploaded to the board and tested.


