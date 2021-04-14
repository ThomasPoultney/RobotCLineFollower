//Declaring sensors variables
#pragma config(Sensor, port2, gyroSensor, sensorEV3_Gyro)
#pragma config(Sensor, port3, colorSensor, sensorEV3_Color)
#pragma config(Sensor, port4, ultrasonicSensor, sensorEV3_Ultrasonic)

task main()
{
	wait1Msec(1000);
	// We vary these speeds for experiments
	motor[motorB] = 60;
	motor[motorC] = 60;

	while(true){

		// Upon hitting white line stop motors
		if (SensorValue[colorSensor] < COLORTHRESHHOLD) {
				displayBigTextLine(10,  "%s", "hit white");
			motor[motorC] = 0;
			motor[motorB] = 0;

		}
	}
}
