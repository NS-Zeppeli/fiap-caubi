/*
		Robo: Caubi 
		Versão: 2.1
		Data:15/08/2017 11:17
		                                                                                       
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

//Variavel para armazenar dados
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
	if(Serial.available() > 0){ 
		command = Serial.read(); 
		parado(); //Inicializa os motores parados
		//Serial.println(command); // printa comando para testar entrada
		switch(command){
		case 'w':  
		  Frente();
		  break;
		case 's':  
		   tras();
		  break;
		case 'a':  
		  esquerda();
		  break;
		case 'd':
		  direita();  
		  break;
		case 'p':
		  parado();
		break;
		  /*
		case 'W':
		  digitalWrite(6,HIGH);
		  break;
		case 'w':
		  digitalWrite(6,LOW);
		  break;
		  */
		 }
	  } 
		
}
	
	
	void frente() // vai para frente 
	{
	  motorRight1.setSpeed(90);
	  motorRight1.run(FORWARD); 
	  motorRight2.setSpeed(90);
	  motorRight2.run(FORWARD);
	  motorLeft1.setSpeed(90);
	  motorLeft1.run(FORWARD); 
	  motorLeft2.setSpeed(90);
	  motorLeft2.run(FORWARD);
	}

	void tras()
	{
	  motorRight1.setSpeed(90); 
	  motorRight1.run(BACKWARD); //roda motor sentido anti-horario
	  motorRight2.setSpeed(90); 
	  motorRight2.run(BACKWARD); 
	  motorLeft1.setSpeed(90); 
	  motorLeft1.run(BACKWARD); //roda motor sentido anti-horario
	  motorLeft2.setSpeed(90); 
	  motorLeft2.run(BACKWARD);
	}

	void esquerda()
	{
	  motorRight1.setSpeed(90); // coloca velociade maxima
	  motorRight1.run(FORWARD);
	  motorRight2.setSpeed(90); 
	  motorRight2.run(FORWARD);	  
	  motorLeft1.setSpeed(0); // desliga motor 2
	  motorLeft1.run(RELEASE);
	  motorLeft2.setSpeed(0); 
	  motorLeft2.run(RELEASE);	  
	}

	void direita()
	{
	  motorRight1.setSpeed(0); //Desliga motor 1
	  motorRight2.setSpeed(0);
	  motorRight1.run(RELEASE);
	  motorRight2.run(RELEASE);
	  motorLeft1.setSpeed(90);
	  motorLeft2.setSpeed(90);
	  motorLeft1.run(FORWARD); 
	  motorLeft2.run(FORWARD);
	}

	void parado()// para motores
	{
	  motorRight1.setSpeed(0);
	  motorRight2.setSpeed(0);
	  motorRight1.run(RELEASE); 
	  motorRight2.run(RELEASE);
	  motorLeft1.setSpeed(0);
	  motorLeft2.setSpeed(0);
	  motorLeft1.run(RELEASE);
	  motorLeft2.run(RELEASE);
	}
	






