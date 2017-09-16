/*
		Robo: Caubi 
		Versão: 5.8
		Data: 15/09/2017 - 22:19
		                                                                                       
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
// Biblioteca 

#include <DHT.h>
#define DHTPIN A0

dht DHT;
int temp;
int umid;

//DECLARAÇÃO DAS PORTAS
const int IN1 = 4;   //motor Dianteiro direito
const int IN2 = 5;  //motor Dianteiro direito
const int IN3 = 6;  //motor Traseiro direito
const int IN4 = 7;  //motor Traseiro direito
const int IN5 = 8;  //motor Dianteiro Esquerdo
const int IN6 = 9;  //motor Dianteiro Esquerdo
const int IN7 = 10; //motor Traseiro Esquerdo
const int IN8 = 11; //motor Traseiro Esquerdo
const int luz = A1; //porta do sensor de luz
// Variaveis do sensor de luz
int valorsensor = 0; 
int LUMINOS;
// declaração de objetos (Motores) // preciso da documentação e arquivos do motor 
char entrada;    // começa parado        

//DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  Serial.begin(9600);   //Prepara o baud para transmissão de dados em serial  
  //dht.begin();
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT); 
  pinMode(IN5, OUTPUT);
  pinMode(IN6, OUTPUT);
  pinMode(IN7, OUTPUT);
  pinMode(IN8, OUTPUT);
  pinMode(A1, INPUT);
}

void loop()
{ 
  // Leitura de dados que chegarão via serial (RX do Arduino)
  while (Serial.available() > 0){ // ISSO FUNCIONA
        entrada = Serial.read();
    switch (entrada){
      case 'F':  
      frente();
      Serial.print("ANDA PRA FRENTE"); // PRINT PARA VER SE ESTÁ RODANDO
      break;
      case 'B':  
      tras();
      Serial.print("ANDA PRA TRAS"); // PRINT PARA VER SE ESTÁ RODANDO
      break;
      case 'L':  
      esquerda();
      Serial.print("VIRA A ESQUERDA"); // PRINT PARA VER SE ESTÁ RODANDO
      break;
      case 'R':
      direita();
      Serial.print("VIRA A DIREITA"); // PRINT PARA VER SE ESTÁ RODANDO 
      break;
      case 'S':
      parado();
      break;
      case 'V':
      lumi();
      dht();
      break;
      default:
      parado();
      break;
    }
  } 
}
  
 ///////////////////////////////////// 
 ///////////// Funções ///////////////
 ///////////////////////////////////// 

  void frente() // vai para frente 
  {
  // Liga os motores direitos sentido horário
    parado();
    delay(300);
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
  
    parado();
    delay(300);
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
    parado();
    delay(300);
    // Liga os motores direitos sentido horário
    digitalWrite(IN1, HIGH); 
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  // Desliga os motores esquerdos 
    digitalWrite(IN5, LOW);
    digitalWrite(IN6, LOW);
    digitalWrite(IN7, LOW);
    digitalWrite(IN8, LOW);  
  }

  void direita()
  {
    parado();
    delay(300);
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
  
  ///////////////////////////////////// 
  /////// Funções DOS SENSORES ////////
  /////////////////////////////////////
  
  void lumi()
  {
    valorsensor = analogRead(luz); // armazena valor analogico de luz na variavel
    LUMINOS = map(valorsensor, 0, 960, 0, 100); //armazena valor mapeado de 0 a 100
  
  // condicional para o valor da luminosidade não dar acima de 100% ou abaixo de 0%
    if (LUMINOS > 100)
    {
      LUMINOS = 100;
    }
    else if (LUMINOS < 0)
    {
      LUMINOS =0;
    }
  }

void dht()
{
	DHT.read11(DHTPIN)
	temp = DHT.temperature -4;
	umid = DHT.humidity;
	if (temp < 0)
	{
		temp = 0;
	}
	// print no programa
   	 Serial.print("L = ");
   	 Serial.print(LUMINOS);
   	 Serial.print(" % ");
	Serial.print("U = ");
    	Serial.print(umid);
    	Serial.print(" % ");
	Serial.print("T = ");
    	Serial.print(temp);
    	Serial.print(" C");
   	Serial.println(" ");
}
