#pragma config(Sensor, port2,  gyroSensor,     sensorEV3_Gyro)
#pragma config(Sensor, port3,  colorSensor,    sensorEV3_Color)
#pragma config(Sensor, port4,  ultrasonicSensor, sensorEV3_Ultrasonic)


//const float REVOLUTIONS_PER_DEGREE = 2.3;
const	int COLORTHRESHHOLD = 15;
task main()
{

	motor[motorB] = 60;
	motor[motorC] = 60;

	while(true)
	{

		int startRotation = SensorValue[gyroSensor];
		if (SensorValue[colorSensor] > COLORTHRESHHOLD) {
			displayBigTextLine(1,  "%s", "Left" );
			while(SensorValue[gyroSensor] < (startRotation+170)) {
				motor[motorB] = 70;
				motor[motorC] = -70;
			}
			motor[motorB] = 0;
			motor[motorC] = 0;
			wait1Msec(500);
		} else {

		motor[motorB] = 60;
	  motor[motorC] = 60;

}




		}

		//displayBigTextLine(1,  "%s%d", "Gsensor: ", SensorValue[gyroSensor]);
		//displayBigTextLine(5,  "%s%d", "Csensor: ", SensorValue[colorSensor]);
		//displayBigTextLine(10,  "%s%d", "Usersor: ", SensorValue[ultrasonicSensor]);

	}
