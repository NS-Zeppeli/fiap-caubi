/*
		Robo: Caubi 
		Vers�o: 0.3.1
		Data:12/07/2017 8:59
		                                                                                       
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
		obs: Sempre Editar a data da edi��o Meu Caros,
		se for uma pequena complementa��o soma a vers�o: +X.1 , se for grande +1.X
		Vou deixar esse espa�o de complementa��o e coment�rios
*/

// Bibliotecas 
#include <> // Falta biblioteca do motor
#include <Arduino.h>

// declara��o de objetos (Motores) // preciso da documenta��o e arquivos do motor 
<nome do motor na biblioteca> motorRight(1, ); 
<nome do motor na biblioteca> motorLeft(3, );  

// Declara��o de Variaveis �teis

char dataIn = 'P';  // come�a parado
char determinante;
int vel = 0;					// coisa do bluetooth
char data = 0;            //Variavel para armazenar dados


void setup()
{
    Serial.begin(9600);   //Prepara o baud para transmiss�o de dados em serial                            
    // pinMode(13, OUTPUT);  //Coloca o pin 13 como saida para Led
	// precisa ver isso no motor que agente comprar
	// pode mudar \/
	motorRight.setSpeed(0); // motor right vem da biblioteca
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
    else if (dataIn == 'T'){//para Tr�s
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