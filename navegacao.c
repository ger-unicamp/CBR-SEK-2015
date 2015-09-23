#define FRENTE 1
#define TRAS -1
#define HORARIO 1
#define ANTIHORARIO -1
#define DESLIGA 0

// potencias sempre de 0 a 100


//Desloca o robo linearmente
void setaMotor(int sentido, int potencia)
{
   setMotorSpeed (motorB, potencia*sentido);
   setMotorSpeed (motorA, potencia*sentido);
}



void GiraRobo(int sentido, int potencia, long degreeDado)
{
	   resetGyro(S3);
     delay (100);
     while(1){
       	 if(getGyroDegrees(S3) >= degreeDado*sentido)
       	 {
       	  //setaMotor(desliga,100);
       	 	playSound(soundBlip);
       	  break;
       		}
       	else
	       setMotorSpeed (motorB,potencia*sentido);
	       setMotorSpeed (motorA,potencia*sentido*(-1));
	   }
}

//void RecolheBonecoComPa ()

task main()
{
	while (1){
		GiraRobo(HORARIO, 100, 90);
		setaMotor(desliga, 100);


		delay (2000);
	  setaMotor(FRENTE, 100);
	  delay (2000);
	  setaMotor (TRAS, 100);
	  delay (2000);
  }
}
