// Declaring sensors variables
#pragma config(Sensor, port2, gyroSensor, sensorEV3_Gyro)
#pragma config(Sensor, port3, colorSensor, sensorEV3_Color)
#pragma config(Sensor, port4, ultrasonicSensor, sensorEV3_Ultrasonic)

const	int COLORTHRESHHOLD = 20; // Constant determines if robot is on a line

task main() {
	wait1Msec(1000);

    // Sets the initial speed of the motors to 50
	motor[motorB] = 50;
	motor[motorC] = 50;

	// Max value of light sensor at center of white line
	const CENTRE_LINE_MAX_VALUE = 80

    // Main Robot loop
    int lockRotation = SensorValue[gyroSensor];
	while(true) {
		displayBigTextLine(8, "%d", SensorValue[colorSensor]);

    	// If light sensor is on the line turn left
		if (SensorValue[colorSensor] >= 65) {
			//Stores rotation of centre of white line
			lockRotation = SensorValue[gyroSensor];

			//resets timer
			clearTimer(T1);
			displayBigTextLine(1, "%s", "Straight");
			motor[motorB] = 50;
			motor[motorC] = 50
		} else if((SensorValue[colorSensor] >= 45)) {
			displayBigTextLine(8, "%s", "Left");
			motor[motorB] = 50;
			//moves back towards line at proportional speed to distance from line
			motor[motorC] = (CENTRE_LINE_MAX_VALUE - SensorValue[colorSensor])*-3;
		}

    	// If light sensor is off the line turn right
		if (SensorValue[colorSensor] < COLORTHRESHHOLD) {
			if (time1[T1] < 1000){
				//stops robot for 1s
				motor[motorB] = 0;
				motor[motorC] = 0;
				wait1Msec(1000);
				while (SensorValue[gyroSensor] < lockRotation) {
					// Turns right of spot until back to last known rotation
					motor[motorB] = 50;
					motor[motorC] = -50;
				}
				motor[motorB] = 50;
				motor[motorC] = 50;
			} else {

				//moves back towards line at proportional speed to distance from line
				displayBigTextLine(10, "%s", "Right");
				motor[motorC] = 50;
				motor[motorB] = (CENTRE_LINE_MAX_VALUE - SensorValue[colorSensor])*-3;
			}
		}
	}
}
