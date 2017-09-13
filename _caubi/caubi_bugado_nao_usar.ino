

// PRECISA REVER ESSE CODIGO
/*#include <Arduino.h>

#include <DHT.h>

#define DHTPIN A0
#define DHTTYPE DHT11
*/
int IN1 = 4;   //motor Dianteiro direito
int IN2 = 5;  //motor Dianteiro direito
int IN3 = 6;  //motor Traseiro direito
int IN4 = 7;  //motor Traseiro direito
int IN5 = 8;  //motor Dianteiro Esquerdo
int IN6 = 9;  //motor Dianteiro Esquerdo
int IN7 = 10; //motor Traseiro Esquerdo
int IN8 = 11; //motor Traseiro Esquerdo
int luz = A1;
int valorsensor = 0;
int LUMINOS;
int RX = 0;


//DHT dht(DHTPIN, DHTTYPE);
// declara??o de objetos (Motores) // preciso da documenta??o e arquivos do motor 

void setup()
{
    Serial.begin(9600);   //Prepara o baud para transmiss?o de dados em serial  
 // dht.begin();
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT); 
  pinMode(IN5, OUTPUT);
  pinMode(IN6, OUTPUT);
  pinMode(IN7, OUTPUT);
  pinMode(IN8, OUTPUT);
  pinMode(A1, INPUT);
  pinMode(RX, INPUT);
}


void loop()
{
  // Leitura de dados que chegaram via serial (RX do Arduino)
  if (Serial.available() > 0){// Se for uma variavel valida do serial
        RX = Serial.read();
    switch (RX){
      case 'F':  
        frente();
        break;
      case 'B':  
         tras();
        break;
      case 'L':  
        esquerda();
        break;
      case 'R':
        direita();  
        break;
      case 'S':
        parado();
      break;
      case 'V':
        lumi();
        break;
      default:
        parado();
      break;
      }
    } 
  }
     

  void frente() // vai para frente 
  {
  // Liga os motores direitos sentido hor?rio
      digitalWrite(IN1, HIGH); 
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  // Liga os motores esquerdos sentido anti-hor?rio 
    digitalWrite(IN5, LOW);
    digitalWrite(IN6, HIGH);
    digitalWrite(IN7, LOW);
    digitalWrite(IN8, HIGH);
  }

  void tras()
  {
  // Liga os motores direitos sentido Anti-hor?rio
      digitalWrite(IN1, LOW); 
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  // Liga os motores esquerdos sentido hor?rio  
    digitalWrite(IN5, HIGH);
    digitalWrite(IN6, LOW);
    digitalWrite(IN7, HIGH);
    digitalWrite(IN8, LOW);
  }

  void esquerda()
  {
    // Liga os motores direitos sentido hor?rio
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
    // desliga os motores direitos
      digitalWrite(IN1, LOW); 
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  // Liga os motores esquerdos em sentido anti-hor?rio  
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

  void lumi()
  {
    valorsensor = analogRead(luz);
    LUMINOS = map(valorsensor, 0, 960, 0, 100);

    if (LUMINOS > 100)
    {
      LUMINOS = 100;
    }
    else if (LUMINOS < 0)
    {
      LUMINOS =0;
    }
    Serial.print("L = ");
    Serial.print(LUMINOS);
    Serial.print(" % ");
    Serial.println(" ");
  }


  /*
   * h = dht.readHumidity();
            t = dht.readTemperature();
            if (isnan(h) || isnan(t))
        {
              return;
        }
            hic = dht.computeHeatIndex(t, h, false);
   */
  