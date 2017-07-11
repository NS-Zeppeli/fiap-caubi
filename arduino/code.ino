char data = 0;            //Variavel para armazenar dados
void setup()
{
    Serial.begin(9600);   //Prepara o baud para transmiss�o de dados em serial                            
    pinMode(13, OUTPUT);  //Coloca o pin 13 como saida
}
void loop()
{
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
}