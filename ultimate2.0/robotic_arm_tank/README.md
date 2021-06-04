# ROBOTIC ARM TANK.
The Robotic Arm consists of a highly-adaptable track chassis and a flexible robotic arm. the major function of the robot is to help you grip, lift and deliver objects in various terrains.

# Mechanism And Control
The robotic arm is controlled by the MegaPi board. Every part of the robot that is to be controlled has to be connected to the MegaPi board for easy coordination. You can check out more details on the megaPi board in the ultimate2.0 readme file.


The robotic arm can essentially perform two types of motion. The rotational and translational motion. It achieves this with the help of three basic types of motors of which only two will be used here.
- The stepper motor.
- The DC motor.
- The Encoder motor.

The major difference between these motors is that stepper motors move in discrete steps i.e it rotates one step at a time and open loop (able to make precise moves without feedback regarding the motor position). The Encoder motors and DC motors are similiar the only difference is that one uses an encoder. They are both closed loop. Without encoder, you just know how much speed you sent to the motor but you don't have information of the speed that is on it as lower battery voltage can decrease the speed of the motor. Encoders allows you to measure the position of the motor from which you can calculate it's speed and regulate those parameters, for example using the PID (Position Integral Derivative) regulator

The robotic arm tank uses only the DC and Encoder motors to achieve its task. It uses three encoder motors and 1 DC motor.

The Megapi board has some peripherals mounted on it so that it can accomodate more devices. Part of the peripheral are the ports for controlling the encoder motors and the stepper/DC motor interface. The MegaPi has four ports mounted on it and four motor interfaces for the stepper/DC motors. 

The Encoder motors are controlled by the emcoder motor drivers.The encoder motors are connected to the encoder drivers via the connection cables supplied in the kit. These drivers are inserted into the ports and the help to control the speed of the motor through a closed loop feedback mechanism. As earlier mentioned, three encoder motors are used here. Two(2) 185RPM and one(1) 86RPM Encoder motors are used. The 185RPM control the front and back tires and are connected to port 1 and port 2 as the case is here. The 86RPM motor is connected to port 3 and it controls the robot arm. The control mechanism actually takes place in these ports as they are used in the code or block programming to control the motors. For illustration, lets say one of the 185RPM is connected to port 1 and controls the front tire. To implement this in the code, the port it is connected to is what tells MegaPi where to channel the instructions to.

The DC motor controls the gripper of the robot arm tank. It rotates to open and close up the gripper. The DC motor has just two pins has opposed to the four pins the Interface has. There are four interfaces, hence we can connect as much as 8DC motors simultaneously.





