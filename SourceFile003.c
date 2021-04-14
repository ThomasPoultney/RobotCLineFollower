#pragma config(Sensor, port2,  gyroSensor,     sensorEV3_Gyro)
#pragma config(Sensor, port3,  colorSensor,    sensorEV3_Color)
#pragma config(Sensor, port4,  ultrasonicSensor, sensorEV3_Ultrasonic)


//const float REVOLUTIONS_PER_DEGREE = 2.3;
const	int COLORTHRESHHOLD = 15;
task main()
{

	motor[motorB] = 50;
	motor[motorC] = 50;
	int lockRotation = SensorValue[gyroSensor];
	while (true)
	{

		clearTimer(T1);
		if (SensorValue[colorSensor] < COLORTHRESHHOLD) {

			if (time1[T1] < 300) {
				while (SensorValue[gyroSensor] < lockRotation) {
					motor[motorB] = 50;
					motor[motorC] = 0;
				}
			}
			else {
				motor[motorC] = 50;
				motor[motorB] = -20;
			}
		}

		if (SensorValue[colorSensor] > COLORTHRESHHOLD) {
			int lockRotation = SensorValue[gyroSensor];
			clearTimer(T1);
			motor[motorB] = 50;
			motor[motorC] = -20;

		}

	}


}
