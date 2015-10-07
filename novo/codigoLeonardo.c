task horario()
{
	setMotorSpeed(motorA, 20);
	setMotorSpeed(motorB, -20);
}

task antiHorario()
{
	setMotorSpeed(motorA, -20);
	setMotorSpeed(motorB, 20);
}

task reto()
{
	setMotorSpeed(motorA, 20);
	setMotorSpeed(motorB, 20);
}

task para()
{
	setMotorSpeed(motorA, 0);
	setMotorSpeed(motorB, 0);
}

task tras()
{
	setMotorSpeed(motorA, -20);
	setMotorSpeed(motorB, -20);
}


task main()
{
	int distMax = 100;
	int distMin = 50;

	resetGyro(S3);
	delay(200);


	/* Gira ateh achar boneco */
	while(SensorValue(S1) > distMax)
	{
		startTask(horario);

	}
	playSound(soundBeepBeep);
	startTask(para);

	/* Segue reto ateh chegar a uma distancia do boneco */
	while(SensorValue(S1) > distMin)
	{
		startTask(reto);

	}
	playSound(soundLowBuzz);
	startTask(para);

	int giroAnte = SensorValue(S3);
	/* Gira ateh o robo estiver de frente para o boneco */
	while(giroAnte + 30 <= SensorValue(S3))
	{
		startTask(antiHorario);
	}
	playSound(soundBlip);

	/* Segue reto ateh o boneco encostar no sensor de toque */
	while(SensorValue(S2) == 0)
	{
		startTask(reto);
	}
	startTask(para);

	/* Gira o braco */
	moveMotorTarget(motorC, 90, 30);

	while(1) {
		startTask(tras);
	}


}
