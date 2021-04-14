// Declaring sensors variables
#pragma config(Sensor, port2, gyroSensor, sensorEV3_Gyro)
#pragma config(Sensor, port3, colorSensor, sensorEV3_Color)
#pragma config(Sensor, port4, ultrasonicSensor, sensorEV3_Ultrasonic)

const	int COLORTHRESHHOLD = 15; // Constant determines if robot is on a line

task main() {
  // Sets the initial speed of the motors to 50
	motor[motorB] = 50;
	motor[motorC] = 50;

  // stores current rotation of Robot
	int lockRotation = SensorValue[gyroSensor];

  // Main Robot loop
	while(true) {

		// If light sensor is off the line
		if (SensorValue[colorSensor] < COLORTHRESHHOLD) {

			// Sensor has not hit a line for 1s
			if (time1[T1] < 1000){

				// If sensor is off the line for 1s it returns to rotation at last line
				while (SensorValue[gyroSensor] < lockRotation) {

					// Turns right until back to last known rotation
					motor[motorB] = 50;
					motor[motorC] = -50;
				}

			// Otherwise follows normal line follower behaviour
			} else {
				motor[motorC] = 50;
				motor[motorB] = -20;
			}
		}

		// Sensor has hit white line
		if (SensorValue[colorSensor] > COLORTHRESHHOLD) {

			// Updates rotation of gyro sensor
			int lockRotation = SensorValue[gyroSensor];

			// Resets timer
			clearTimer(T1);

			// Follows normal line follower behaviour
			motor[motorB] = 50;
			motor[motorC] = -20;
		}
	}
}
