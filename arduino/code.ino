/*
		Robo: Caubi 
		Vers�o: 0.1
		Data:11/07/2017 12:13
	
		obs: Sempre anotar a data da edi��o Meu Caros,
		se for uma pequena complementa��o soma a vers�o: +X.1 , se for grande +1.X
		Vou deixar esse espa�o de complementa��o e coment�rios
*/

// Falta biblioteca do motor // entrada e saida de dados ?
#include <>

// Declara��o de Variaveis �teis

char dataIn = 'S';
char determinant;
int vel = 0					// coisa do bluetooth
char data = 0;            //Variavel para armazenar dados



void setup()
{
    Serial.begin(9600);   //Prepara o baud para transmiss�o de dados em serial                            
    pinMode(13, OUTPUT);  //Coloca o pin 13 como saida
	// precisa ver isso no motor que agente comprar
	// pode mudar \/
	motorRight.setSpeed(0);
	motorLeft.setSpeed(0);
	motorRight.run(RELEASE);
	motorLeft.run(RELEASE);
}
void loop()
{
   data = check();

		/* If para ligar led (TESTE)
   if(Serial.available() > 0)      // manda dados somente quando receber dados:
   {
      data = Serial.read();        //ler os dados que vieram e armazena em data
      Serial.print(data);          //Print do valor de data no monitor serial
      Serial.print("\n");        
      if(data == '1')              // Checa quando valor de data � igual a 1
         digitalWrite(13, HIGH);   //Se o valor � 1 ent�o LED liga
      else if(data == '0')         // Checa quando valor de data � igual a 0
         digitalWrite(13, LOW);    //Se o valor � 0 ent�o LED desliga
   }
   */
   /*
   
			Precisa Rever Tudo depois 
   
	*/
    switch (det){
		case 'F': // F, move para frente
    motorRight.setSpeed(vel);
    motorLeft.setSpeed(vel);
    motorRight.run(FORWARD);      
    motorLeft.run(FORWARD);
    det = check();
    break;
    
    case 'T': // T move para tras
    motorRight.setSpeed(vel);
    motorLeft.setSpeed(vel);
    motorRight.run(BACKWARD);      
    motorLeft.run(BACKWARD);
    det = check();
    break;
    
    case 'E':// E vai para esquerda
    motorRight.setSpeed(vel);
    motorLeft.setSpeed(vel/4);
    motorRight.run(FORWARD);      
    motorLeft.run(FORWARD);
    det = check();
    break;
    
    case 'D': // D vai pra direira
    motorRight.setSpeed(vel/4);
    motorLeft.setSpeed(vel);
    motorRight.run(FORWARD);      
    motorLeft.run(FORWARD);
    det = check();
    break;
	
	case 'P': // P, para
    motorRight.setSpeed(vel);
    motorLeft.setSpeed(vel);
    motorRight.run(RELEASE);      
    motorLeft.run(RELEASE);
    det = check();
    break;
	}
	// pega o codigo do bluetooth pela porta serial
	int check(){
  if (Serial.available() > 0){// Se for uma variavel valida do serial
    dataIn = Serial.read();// guarda o valor da variavel
    
    // Checa o codigo
    if (dataIn == 'F'){//Frente
      determinant = 'F';
    }
    else if (dataIn == 'T'){//para Tr�s
      determinant = 'T';
    }
    else if (dataIn == 'E'){//Esquerda
      determinant = 'E';
    }
    else if (dataIn == 'D'){//Right
      determinant = 'D';
    }
	else if (dataIn == 'S'){//Stop
      determinant = 'S';
    }
  }
}
   return determinant;

}