#include <Thermistor.h>
#include <Servo.h>
//PrintWritter output;
#define LED 13 //Define LED como 13

Thermistor temp(0);
Servo myservo;
int pos = 0; 

void setup()
{   
  myservo.attach(9);
  Serial.begin(9600);
  pinMode(LED, OUTPUT); //Define o pino 13(LED) como saída
//  output = createWritter("data.txt");
} 

void loop() 
{   

  float temperatura = temp.getTemp();   
  //Serial.print("Temperatura no ambiente: ");   
  Serial.print(temperatura);
  Serial.println("*C");  
  
  if (temperatura >= 39.51){
    digitalWrite(LED, HIGH); //Liga o LED
    pos = 0;
    while(pos < 720){
      myservo.write(pos);
      pos++;
      delay(1);
    }
  }
  
  else{
    digitalWrite(LED, LOW); //Apaga o LED
  }

  delay(100);
//  delay(1800000); 

}
