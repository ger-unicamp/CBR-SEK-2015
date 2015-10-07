#define FRENTE 1
#define TRAS -1
#define HORARIO 1
#define ANTIHORARIO -1
#define DESLIGA 0

// potencias sempre de 0 a 100
// para setar a potencia do motor, basta chamar setMotorSpeed uma vez!

// Pode ser util
struct Robo{
	// Colocar dados e variaveis de estado importantes
	int status;

};
typedef struct Robo Robo

//Desloca o robo linearmente
// Sentido = uma das constantes
void setaMotor(int sentido, int potencia)
{
   setMotorSpeed (motorB, potencia*sentido);
   setMotorSpeed (motorA, potencia*sentido);
}


// Gira o robo por degreeDado graus
void giraRobo(int sentido, int potencia, long degreeDado)
{
	resetGyro(S3);
    delay (100);
    setMotorSpeed (motorB,potencia*sentido);
	setMotorSpeed (motorA, -potencia*sentido);

    while(getGyroDegrees(S3) < degreeDado*sentido);
    
    playSound(soundBlip);
    setMotorSpeed(DESLIGA, 0);
    break;
}

//void RecolheBonecoComPa ()

task main()
{
	Robo labRobo, circRobo;

	while (1){
		giraRobo(HORARIO, 100, 90);

		delay (2000);
		setaMotor(FRENTE, 100);
		delay (2000);
		setaMotor (TRAS, 100);
		delay (2000);
	}
}
