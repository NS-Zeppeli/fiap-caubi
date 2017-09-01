/*
		Robo: Caubi 
		Versão: 3.3
		Data:01/09/2017 
		                                                                                       
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
		obs: Sempre Editar a data da edição 
		se for uma pequena complementação soma a versão: +X.1 , se for grande +1.X
		Vou deixar esse espaço de complementação e comentários
*/

// Bibliotecas 

#include <Arduino.h>

#include <DHT.h>

#define DHTPIN A0
#define DHTTYPE DHT11

int IN1 = 4; 	//motor Dianteiro direito
int IN2 = 5; 	//motor Dianteiro direito
int IN3 = 6;	//motor Traseiro direito
int IN4 = 7;	//motor Traseiro direito
int IN5 = 8;	//motor Dianteiro Esquerdo
int IN6 = 9;	//motor Dianteiro Esquerdo
int IN7 = 10;	//motor Traseiro Esquerdo
int IN8 = 11;	//motor Traseiro Esquerdo

DHT dht(DHTPIN, DHTTYPE);
// declaração de objetos (Motores) // preciso da documentação e arquivos do motor 

// Declaração de Variaveis úteis

char dataIn = 'q';  // começa parado
char determinante;
					// coisa do bluetooth
char data = 0;            //Variavel para armazenar dados

void setup()
{
   	Serial.begin(9600);   //Prepara o baud para transmissão de dados em serial                           
	pinMode(IN1, OUTPUT);
 	pinMode(IN2, OUTPUT);
 	pinMode(IN3, OUTPUT);
 	pinMode(IN4, OUTPUT); 
	pinMode(IN5, OUTPUT);
 	pinMode(IN6, OUTPUT);
 	pinMode(IN7, OUTPUT);
 	pinMode(IN8, OUTPUT);
}


void loop()
{
	
	// Leitura de dados que chegaram via serial (RX do Arduino)
	if (Serial.available())
	 X = Serial.read();
 	// Escreve valores na serial (TX do Arduino)
	 Serial.print("X: ");
 	Serial.println(X);
	if (Serial.available() > 0){// Se for uma variavel valida do serial
    		dataIn = Serial.read();
		switch (dataIn){
			case 'w':  
			  Frente();
			  break;
			case 'x':  
			   tras();
			  break;
			case 'z':  
			  esquerda();
			  break;
			case 'y':
			  direita();  
			  break;
			case 'q':
			  parado();
			break;
		}	
	}
}		

	void frente() // vai para frente 
	{
	// Liga os motores direitos sentido horário
	  	digitalWrite(IN1, HIGH); 
 		digitalWrite(IN2, LOW);
		digitalWrite(IN3, HIGH);
 		digitalWrite(IN4, LOW);
	// Liga os motores esquerdos sentido anti-horário	
		digitalWrite(IN5, LOW);
 		digitalWrite(IN6, HIGH);
		digitalWrite(IN7, LOW);
 		digitalWrite(IN8, HIGH);
	}

	void tras()
	{
	// Liga os motores direitos sentido Anti-horário
	  	digitalWrite(IN1, LOW); 
 		digitalWrite(IN2, HIGH);
		digitalWrite(IN3, LOW);
 		digitalWrite(IN4, HIGH);
	// Liga os motores esquerdos sentido horário	
		digitalWrite(IN5, HIGH);
 		digitalWrite(IN6, LOW);
		digitalWrite(IN7, HIGH);
 		digitalWrite(IN8, LOW);
	}

	void esquerda()
	{
	  // Liga os motores direitos sentido horário
	  	digitalWrite(IN1, HIGH); 
 		digitalWrite(IN2, LOW);
		digitalWrite(IN3, HIGH);
 		digitalWrite(IN4, LOW);
	// Liga os motores esquerdos Anti-horário	
		digitalWrite(IN5, LOW);
 		digitalWrite(IN6, LOW);
		digitalWrite(IN7, LOW);
 		digitalWrite(IN8, LOW);  
	}

	void direita()
	{
	  // desliga os motores direitos
	  	digitalWrite(IN1, LOW); 
 		digitalWrite(IN2, LOW);
		digitalWrite(IN3, LOW);
 		digitalWrite(IN4, LOW);
	// Liga os motores esquerdos em sentido anti-horário	
		digitalWrite(IN5, LOW);
 		digitalWrite(IN6, HIGH);
		digitalWrite(IN7, LOW);
 		digitalWrite(IN8, HIGH); 
	}

	void parado()// para motores
	{
	 // desliga os motores direitos
	  	digitalWrite(IN1, LOW); 
 		digitalWrite(IN2, LOW);
		digitalWrite(IN3, LOW);
 		digitalWrite(IN4, LOW);
	// desliga os motores esquerdos 	
		digitalWrite(IN5, LOW);
 		digitalWrite(IN6, LOW);
		digitalWrite(IN7, LOW);
 		digitalWrite(IN8, LOW);
	}





