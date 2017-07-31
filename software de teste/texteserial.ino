
/* Versão de teste

void setup()
{
  Serial.begin(9600);  //inicia comunicação serial com 9600
}
 
void loop()
{
  if(Serial.available())        //se algum dado disponível
  {
    char c = Serial.read();   //le o byte disponivel
    Serial.write(c);           //retorna o que foi lido
  }
}

*/

/*
 * comandos via serial
 * inverte o estado do led conctado a saída 13 do arduino quando recebe o caracter 'A' pela serial
 */
 
const int LED = 13;
void setup() {
  Serial.begin(9600);    //configura comunicação serial com 9600 bps
  pinMode(LED,OUTPUT);   //configura pino do led como saída
}
void loop() {
   if (Serial.available()) //se byte pronto para leitura
   {
    switch(Serial.read())      //verifica qual caracter recebido
    {
      case 'A':                  //caso 'A'
        digitalWrite(LED,!digitalRead(LED)); //inverte estado do LED
      break;
    }
  }
}