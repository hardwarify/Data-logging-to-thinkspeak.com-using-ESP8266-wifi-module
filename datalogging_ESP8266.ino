#include <AltSoftSerial.h> 
 
AltSoftSerial esp(9,8); // RX | TX 
 
void setup() { 
pinMode(13,OUTPUT);
Serial.begin(9600); // communication with the host computer 
esp.begin(115200); 
Serial.println(""); 
Serial.println("Remember to to set Both NL & CR in the serial monitor."); 
Serial.println("Ready"); 
Serial.println(""); 
//esp.println("AT");
//printer();
esp.println("AT+RST");
printer();
//esp.println("AT+GMR");
//printer();
esp.println("AT+CWMODE=3");
printer();

esp.println("AT+CIFSR");
printer();

esp.println("AT+CIPMUX=0");
printer();



} 
 
void loop() { 
  digitalWrite(13,HIGH);
  delay(200);
  digitalWrite(13,LOW);
  delay(1000);
  
  esp.println("AT+CIPSTART=\"TCP\",\"184.106.153.149\",80");
  printer();
  
  int a= analogRead(0);
  String getStr="GET /update?api_key=O9GDA2P26T4G130W&field1=";
  getStr +=String(a);
  getStr +="\r\n";
  
  String cmd="AT+CIPSEND=";
  cmd +=String(getStr.length());  
  esp.println(cmd);

  if(esp.find(">"))
  {
   esp.println(getStr);
  }
  printer();
  printer();
  printer();

  
  esp.println("AT+CIPCLOSE");
  printer();
  delay(16000);
  
}


void printer(){
  
 long int time1=millis();
 long int time2 =millis();
 
 String response="";
 
 while(time2-time1<1000){
    
   time2=millis();
    if(esp.available()) { 
       Serial.write(esp.read());
     
      }
  }

 return ;
}
 
