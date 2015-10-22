//Codigo Nipo
//GER - SEK 2015
//Robo usado para separar os bonecos por cor no modulo central

//Definicoes de constantes
#define FRENTE 1
#define TRAS -1
#define HORARIO 1
#define ANTIHORARIO -1
#define DESLIGA 0

//Struct que armazena os valores atuais dos sensores
struct Sensores{
	int sensor_cor_1;
	int sensor_cor_2;
	int sensor_us;
};

//Variaveis Globais
Sensores sensores;

// potencias sempre de 0 a 100
// para setar a potencia do motor, basta chamar setMotorSpeed uma vez!

//Sensoriamento

//Rotina que atualiza sensores
task atualizaSensores()
{
		while(1){
			//Atualiza sensores de cor
			//sensores.sensor_cor_1 = getColorName(S2);
			sensores.sensor_cor_2 = getColorName(S1);

		//Atualiza sensor US
		sensores.sensor_us = getUSDistance(S4);
		}
}

//Mostra no LCD os estados atuais dos sensores
void imprimeSensores()
{
		displayBigTextLine(0, "US: %d",sensores.sensor_us);
		displayBigTextLine(4, "Cor 2: %d",sensores.sensor_cor_2);
		displayBigTextLine(8, "Cor 1: %d",sensores.sensor_cor_1);
}

//Atuacao

void setaMotor(int sentido, int potencia)
{
   setMotorSpeed (motorB, potencia*sentido);
   setMotorSpeed (motorA, potencia*sentido);
}

// Gira o robo por degreeDado graus
void giraRobo(int sentido, long degreeDado)
{
		resetGyro(S3);
		delay(100);

		setaMotor(DESLIGA, 0);
    delay(200);

    setMotorSpeed (motorB,-30*sentido);
		setMotorSpeed (motorA, 30*sentido);

    while(getGyroHeading(S3) < degreeDado*sentido)
    {
    	displayBigTextLine(6,"%d",getGyroHeading(S3));
    }

    setaMotor(DESLIGA, 0);
}


task main()
{
	startTask(atualizaSensores);

	delay(200);



	while (1){

	if(sensores.sensor_cor_2 == 0)
	setaMotor(FRENTE,30);

	if(sensores.sensor_cor_2 == 1)
	{
		delay(300);
		setaMotor(DESLIGA,0);
		delay(1000);
		if(sensores.sensor_cor_2 == 1)
		{
			moveMotorTarget(MotorC, 90, 20);
  		delay(1000);
		}

		while(1)
			setaMotor(FRENTE,30);
	}



	}
}
