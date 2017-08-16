/*
		Robo: Caubi 
		Versão: 2.0
		Data:14/08/2017 17:16
		                                                                                       
        CCCCCCCCCCCCC               AAA           UUUUUUUU     UUUUUUUUBBBBBBBBBBBBBBBBB   IIIIIIIIII
     CCC::::::::::::C              A:::A          U::::::U     U::::::UB::::::::::::::::B  I::::::::I
   CC:::::::::::::::C             A:::::A         U::::::U     U::::::UB::::::BBBBBB:::::B I::::::::I
  C:::::CCCCCCCC::::C            A:::::::A        UU:::::U     U:::::UUBB:::::B     B:::::BII::::::II
 C:::::C       CCCCCC           A:::::::::A        U:::::U     U:::::U   B::::B     B:::::B  I::::I  
C:::::C                        A:::::A:::::A       U:::::D     D:::::U   B::::B     B:::::B  I::::I  
C:::::C                       A:::::A A:::::A      U:::::D     D:::::U   B::::BBBBBB:::::B   I::::I  
C:::::C                      A:::::A   A:::::A     U:::::D     D:::::U   B:::::::::::::BB    I::::I  
C:::::C                     A:::::A     A:::::A    U:::::D     D:::::U   B::::BBBBBB:::::B   I::::I  
C:::::C                    A:::::AAAAAAAAA:::::A   U:::::D     D:::::U   B::::B     B:::::B  I::::I  
C:::::C                   A:::::::::::::::::::::A  U:::::D     D:::::U   B::::B     B:::::B  I::::I  
 C:::::C       CCCCCC    A:::::AAAAAAAAAAAAA:::::A U::::::U   U::::::U   B::::B     B:::::B  I::::I  
  C:::::CCCCCCCC::::C   A:::::A             A:::::AU:::::::UUU:::::::U BB:::::BBBBBB::::::BII::::::II
   CC:::::::::::::::C  A:::::A               A:::::AUU:::::::::::::UU  B:::::::::::::::::B I::::::::I
     CCC::::::::::::C A:::::A                 A:::::A UU:::::::::UU    B::::::::::::::::B  I::::::::I
        CCCCCCCCCCCCCAAAAAAA                   AAAAAAA  UUUUUUUUU      BBBBBBBBBBBBBBBBB   IIIIIIIIII
		
		// http://patorjk.com/blog/software/ // ASCII Art Source XD
		obs: Sempre Editar a data da edição Meu Caros,
		se for uma pequena complementação soma a versão: +X.1 , se for grande +1.X
		Vou deixar esse espaço de complementação e comentários
*/

// Bibliotecas 
#include <AFMotor.h> // biblioteca do motor
#include <Arduino.h>

// declaração de objetos (Motores) // preciso da documentação e arquivos do motor 
AF_DCMotor motorRight1(1); 
AF_DCMotor motorRight2(2);
AF_DCMotor motorLeft1(3);
AF_DCMotor motorLeft2(4); // o numero interno é a porta no shield XD

// Declaração de Variaveis úteis

char dataIn = 'P';  // começa parado
char determinante;
int vel = 0;					// coisa do bluetooth
char data = 0;            //Variavel para armazenar dados
const int Ledligado = 6; // liga led

void setup()
{
    Serial.begin(9600);   //Prepara o baud para transmissão de dados em serial                            
    // pinMode(13, OUTPUT);  //Coloca o pin 13 como saida para Led
	// precisa ver isso no motor que agente comprar
	// pode mudar \/
	motorRight1.setSpeed(0); // motor right vem da biblioteca
	motorLeft1.setSpeed(0);
	motorRight1.run(RELEASE);
	motorLeft1.run(RELEASE);
	motorRight2.setSpeed(0); // motor right vem da biblioteca
	motorLeft2.setSpeed(0);
	motorRight2.run(RELEASE);
	motorLeft2.run(RELEASE);
	pinMode(Ledligado, OUTPUT);
}


void loop()
{
	switch (dataIn){
		case 'w': // F, move para frente
		motorRight1.setSpeed(90);
		motorRight1.run(FORWARD); 
		motorRight2.setSpeed(90);
		motorRight2.run(FORWARD);
		motorLeft1.setSpeed(90);
		motorLeft1.run(FORWARD); 
		motorLeft2.setSpeed(90);
		motorLeft2.run(FORWARD);
		data = check();
		break;
    
		case 's': // T move para tras
		motorRight1.setSpeed(90); 
		motorRight1.run(BACKWARD); //roda motor sentido anti-horario
		motorRight2.setSpeed(90); 
		motorRight2.run(BACKWARD); 
		motorLeft1.setSpeed(90); 
		motorLeft1.run(BACKWARD); //roda motor sentido anti-horario
		motorLeft2.setSpeed(90); 
		motorLeft2.run(BACKWARD);
		data = check();
		break;
    
		case 'a':// E vai para esquerda
		motorRight1.setSpeed(90); // coloca velociade maxima
		motorRight1.run(FORWARD);
		motorRight2.setSpeed(90); 
		motorRight2.run(FORWARD);	  
		motorLeft1.setSpeed(0); // desliga motor 2
		motorLeft1.run(RELEASE);
		motorLeft2.setSpeed(0); 
		motorLeft2.run(RELEASE);	
		data = check();
		break;
    
		case 'd': // D vai pra direira
		motorRight1.setSpeed(0); //Desliga motor 1
		motorRight2.setSpeed(0);
		motorRight1.run(RELEASE);
		motorRight2.run(RELEASE);
		motorLeft1.setSpeed(90);
		motorLeft2.setSpeed(90);
		motorLeft1.run(FORWARD); 
		motorLeft2.run(FORWARD);
		data = check();
		break;
	
		case 'q': // q, para
		motorRight1.setSpeed(0);
		motorRight2.setSpeed(0);
		motorRight1.run(RELEASE); 
		motorRight2.run(RELEASE);
		motorLeft1.setSpeed(0);
		motorLeft2.setSpeed(0);
		motorLeft1.run(RELEASE);
		motorLeft2.run(RELEASE);
		data = check();
		break;
		
	}
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
	
	
	
	/*	
 _______  _____  ______  _____  ______  _____  _______      _______ __   _ _______ _____  ______  _____  _______
 |       |     | |     \   |   |  ____ |     | |______      |_____| | \  |    |      |   |  ____ |     | |______
 |_____  |_____| |_____/ __|__ |_____| |_____| ______|      |     | |  \_|    |    __|__ |_____| |_____| ______|
	
	
	

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



*/







