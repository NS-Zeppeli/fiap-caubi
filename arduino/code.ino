/*
		Robo: Caubi 
		Versão: 0.2.2
		Data:11/07/2017 16:41
	
		obs: Sempre Editar a data da edição Meu Caros,
		se for uma pequena complementação soma a versão: +X.1 , se for grande +1.X
		Vou deixar esse espaço de complementação e comentários
*/

// Bibliotecas 
#include <> // Falta biblioteca do motor
#include <Arduino.h>

// declaração de objetos (Motores) // preciso da documentação e arquivos do motor 
<nome do motor na biblioteca> motorRight(1, ); 
<nome do motor na biblioteca> motorLeft(3, );  

// Declaração de Variaveis úteis

char dataIn = 'P';  // começa parado
char determinante;
int vel = 0;					// coisa do bluetooth
char data = 0;            //Variavel para armazenar dados


void setup()
{
    Serial.begin(9600);   //Prepara o baud para transmissão de dados em serial                            
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
      if(data == '1')              // Checa quando valor de data é igual a 1
         digitalWrite(13, HIGH);   //Se o valor é 1 então LED liga
      else if(data == '0')         // Checa quando valor de data é igual a 0
         digitalWrite(13, LOW);    //Se o valor é 0 então LED desliga
   }
   */
   /*
   
			Precisa Rever Tudo depois 
   
	*/
    switch (data){
		case 'F': // F, move para frente
    motorRight.setSpeed(vel);
    motorLeft.setSpeed(vel);
    motorRight.run(FORWARD);      
    motorLeft.run(FORWARD);
    data = check();
    break;
    
    case 'T': // T move para tras
    motorRight.setSpeed(vel);
    motorLeft.setSpeed(vel);
    motorRight.run(BACKWARD);      
    motorLeft.run(BACKWARD);
    data = check();
    break;
    
    case 'E':// E vai para esquerda
    motorRight.setSpeed(vel);
    motorLeft.setSpeed(vel/4);
    motorRight.run(FORWARD);      
    motorLeft.run(FORWARD);
    data = check();
    break;
    
    case 'D': // D vai pra direira
    motorRight.setSpeed(vel/4);
    motorLeft.setSpeed(vel);
    motorRight.run(FORWARD);      
    motorLeft.run(FORWARD);
    data = check();
    break;
	
	case 'P': // P, para
    motorRight.setSpeed(vel);
    motorLeft.setSpeed(vel);
    motorRight.run(RELEASE);      
    motorLeft.run(RELEASE);
    data = check();
    break;
	}
	// pega o codigo do bluetooth pela porta serial
	int check(){
  if (Serial.available() > 0){// Se for uma variavel valida do serial
    dataIn = Serial.read();// guarda o valor da variavel
    
    // Checa o codigo
    if (dataIn == 'F'){//Frente
      determinante = 'F';
    }
    else if (dataIn == 'T'){//para Trás
      determinante = 'T';
    }
    else if (dataIn == 'E'){//Esquerda
      determinante = 'E';
    }
    else if (dataIn == 'D'){//Right
      determinante = 'D';
    }
	else if (dataIn == 'S'){//Stop
      determinante = 'S';
    }
  }
}
   return determinant;

}