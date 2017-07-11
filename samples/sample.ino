//  _ ___ _______     ___ ___ ___  ___ _   _ ___ _____ ___ 
// / |_  )__ /   \   / __|_ _| _ \/ __| | | |_ _|_   _/ __| 
// | |/ / |_ \ |) | | (__ | ||   / (__| |_| || |  | | \__ \ 
// |_/___|___/___/   \___|___|_|_\\___|\___/|___| |_| |___/ 
// 
// Aula de arduino Por Fabio Pimentel
// 
// License: CC-BY-SA 3.0

// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
// Variaveis sao declaradas com os pinos que elas estao encaixadas por exemplo X = pino 13 == X = 13;
int L2 = 13;
int CHA = 10;
int CHB = 11;
int L1 = 12;
// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  // Você Declara quais sao as entradas e saidas apartir das variaveis
  pinMode(CHA, INPUT);
  pinMode(CHB, INPUT);
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
}

// the loop routine runs over and over again forever:
// == Main
void loop() {
  
  //R = digitalRead(CHA);// Faça uma leitura digital na entrada CHA
  //if (R == 0) // mesma coisa que a abaixo
    
  if (digitalRead(CHA) == 0)
  	digitalWrite(L1, HIGH);
  else 
    digitalWrite(L1, LOW);
  
  if (digitalRead(CHB) == 0)
  	digitalWrite(L2, HIGH);
  else 
    digitalWrite(L2, LOW);
    
    
  /*
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second
  */
}
