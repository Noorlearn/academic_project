#include <stdio.h>
#include<string.h>
#include <LiquidCrystal.h>
#include <Adafruit_Fingerprint.h>
const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 =8 ;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int party1=0,party2=0,party3=0,dummy=0,total=0;
int m1=A4;int m2=A5;
int person1=0,person2=0,person3=0,person4=0,person5=0,person6=0,person7=0,person8=0,person9=0,person10=0;
SoftwareSerial mySerial(2, 3);
int OTP=0,otp=0,data=0;
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);
int cam=A1;
String number="8897225631";
int message=0;   
int times=0;


#define b1 7
#define b2 6
#define b3 5
int motor=4;
unsigned char key[5];
unsigned int temp=0;
signed int val=0;


uint8_t id=1;
uint8_t dummyid=1;
int buzzer=A0;



int idnumber=0;
String inputString = "";         // a String to hold incoming data
boolean stringComplete = false;

    
void setup()  
{
   pinMode(m1, OUTPUT);
   pinMode(m2, OUTPUT);digitalWrite(m2,LOW);digitalWrite(m1,LOW);
   pinMode(buzzer, OUTPUT);digitalWrite(buzzer,HIGH);delay(1000);digitalWrite(buzzer,LOW);
  pinMode(b1, INPUT_PULLUP); pinMode(cam, INPUT);
  pinMode(b2, INPUT_PULLUP);
  pinMode(b3, INPUT_PULLUP);
 lcd.begin(16, 2);delay(1000);
 lcd.setCursor(0,0); lcd.print("SECURE VOTING");delay(1000);
 lcd.setCursor(0,1); lcd.print(" SYSTEM USING ARDUINO");delay(1000);
 Serial.begin(9600);delay(1000);
 
  finger.begin(57600);     // set the data rate for the sensor serial port
 

  while (!Serial);  
  delay(100);
 //Serial.println("\n\nFingerprint code by using Arduino");

  if (finger.verifyPassword()) {
   //// Serial.println("Found fingerprint sensor!");
  } else {
   // Serial.println("Did not find fingerprint sensor :(");
   // Serial.println("Please turn off and turn on the power");
    while (1) { delay(1); }
  }
 

lcd.clear();lcd.print("AT");Serial.print("AT\r\n");delay(1000);
lcd.clear();lcd.print("ATE0");Serial.print("ATE0\r\n");delay(1000);
lcd.clear();lcd.print("AT+CMGF=1");Serial.print("AT+CMGF=1\r\n");delay(1000);
lcd.clear();lcd.print("AT+CNMI=1,2,0,0");Serial.print("AT+CNMI=1,2,0,0\r\n");delay(1000);
lcd.clear();lcd.print("Waiting for N/W....");delay(1000);

lcd.clear();lcd.print("change u r number");delay(10000);
lcd.clear();lcd.print("AT");Serial.print("AT\r\n");delay(1000); 
lcd.clear();lcd.print("ATE0");Serial.print("ATE0\r\n");delay(1000);
lcd.clear();lcd.print("AT+CMGF=1");Serial.print("AT+CMGF=1\r\n");delay(1000); 
lcd.clear();lcd.print("AT+CNMI=1,2,0,0");Serial.print("AT+CNMI=1,2,0,0\r\n");delay(1000);

lcd.clear();lcd.print(number);delay(5000); lcd.clear();lcd.print("AT");Serial.print("AT\r\n");delay(1000); 
lcd.clear();lcd.print("ATE0");Serial.print("ATE0\r\n");delay(1000); lcd.clear();lcd.print("AT+CMGF=1");
Serial.print("AT+CMGF=1\r\n");delay(1000);  lcd.clear();lcd.print("AT+CNMI=1,2,0,0");
Serial.print("AT+CNMI=1,2,0,0\r\n");delay(1000);
Serial.print("AT+CMGS=");
Serial.print('"');
Serial.print(number);
Serial.print('"');
Serial.print("\r\n");delay(1000);
Serial.print(number);Serial.print(":Number Registed");delay(100);
Serial.write(0x1A);delay(10000); 
lcd.clear();lcd.print("Ready to use>>>");  

 String iot="Party1_"+String(party1)+"_party2_"+String(party2)+"_party3_"+String(party3);
  mySerial.println(iot);delay(1000);  


}

void beep()
{
digitalWrite(buzzer,HIGH);delay(1000);digitalWrite(buzzer,LOW);delay(1000);  
}

int keypad()
 {
  lcd.clear();lcd.print("ENTER PASSWORD");delay(2000);lcd.clear(); 
  do
  {
   int i=digitalRead(b1);
  int d=digitalRead(b3);
  int e=digitalRead(b2);

  if(i==LOW)
  {
    OTP=(millis() / 1000); 
//lcd.clear();lcd.print("  OTP=");lcd.print(OTP);
delay(10); 
if(OTP>=99998)
{
OTP=0;  
}
   val=val+1; 
   if(val==10)
   val=0;
   lcd.setCursor( temp,0);lcd.print(val);delay(500);
  }
  if(d==LOW)
  {
    OTP=(millis() / 1000); 
//lcd.clear();lcd.print("  OTP=");lcd.print(OTP);
delay(10); 
if(OTP>=99998)
{
OTP=0;  
}
   val=val-1;
   if(val<0)
   val=9;
   if(val>9)
   val=0; 
   lcd.setCursor(temp,0);lcd.print(val);delay(500);
  }
  
if(e==LOW)
{
  OTP=(millis() / 1000); 
//lcd.clear();lcd.print("  OTP=");lcd.print(OTP);
delay(10); 
if(OTP>=99998)
{
OTP=0;  
}
 key[temp]=val;
 lcd.setCursor(temp,0);lcd.print(val);delay(500);
 temp=temp+1;
 val=0;
}
  }while(temp<=4);

  
 if(temp==5)
 {
  lcd.clear();lcd.setCursor(3,1);
  lcd.print("key=");delay(1000);
  lcd.print(key[0]);delay(1000);
  lcd.print(key[1]);delay(1000);
  lcd.print(key[2]);delay(1000);
  lcd.print(key[3]);delay(1000);
  lcd.print(key[4]);delay(1000);
  temp=0;
   int amount=((key[0]*10000)+(key[1]*1000)+(key[2]*100)+(key[3]*10)+(key[4]*1));
lcd.clear();lcd.print("KEY:");lcd.print(amount);delay(1000);
return amount;

  
 }


}


void loop()                     // run over and over again
{
  back:
 OTP=(millis() / 1000); //lcd.clear();lcd.print("  OTP=");lcd.print(OTP);
delay(1000); 
if(OTP>=99998)
{
OTP=0;  
} 
if(digitalRead(b1)==LOW)
 {
  lcd.clear();lcd.print("Enrolling....");delay(1000);
  getFingerprintEnroll();delay(1000);
  lcd.clear();lcd.print("Ready to use>>>");  
 }

if(digitalRead(b3)==LOW)
 {
   lcd.clear();lcd.print("identifing.....");delay(1000);
  dummy=getFingerprintID();
  lcd.clear();lcd.print("voter id:");lcd.print(dummy);delay(1000);
  if(dummy==1)
  {
  person1=person1+1;delay(1000);
  if(person1>=2)
  {
   lcd.clear();lcd.print("You have already");
   lcd.setCursor(0,1);lcd.print("cast your vote");delay(1000);beep(); lcd.clear();lcd.print("Ready to use>>>");  goto back; 
  }
 
 lcd.setCursor(0,1);lcd.print("PERSON:1");delay(1000);
 lcd.clear();lcd.print("Generating OTP");delay(1000);

 //lcd.clear();lcd.print("OTP:");
 otp=OTP;
 //lcd.print(OTP);delay(2000);

  lcd.clear();lcd.print("SENDING OTP...");delay(1000);
  lcd.clear();lcd.print("change u r number");delay(1000); 
  lcd.clear();lcd.print("AT");Serial.print("AT\r\n");delay(1000);
  lcd.clear();lcd.print("ATE0");Serial.print("ATE0\r\n");delay(1000); 
  lcd.clear();lcd.print("AT+CMGF=1");Serial.print("AT+CMGF=1\r\n");delay(1000);  
  lcd.clear();lcd.print("AT+CNMI=1,2,0,0");Serial.print("AT+CNMI=1,2,0,0\r\n");delay(1000); 
  Serial.print("AT+CMGS=");
  Serial.print('"');
  Serial.print(number);
  Serial.print('"');
  Serial.print("\r\n");delay(1000);
  Serial.print("OTP FROM ARDUINO TO VOTING:");Serial.print(String(OTP));delay(100);
  Serial.write(0x1A);delay(10000); 
  lcd.clear();lcd.print("OTP is sent to");delay(1000);
  lcd.setCursor(0,1);lcd.print("your mobile...");delay(1000);
  lcd.clear();lcd.setCursor(0,1);lcd.print("PLZ ENTER OTP");delay(1000);
  int key=keypad();
  if(key==otp)
  {
   lcd.clear();lcd.print("VALID OTP ");delay(1000);
      lcd.clear();lcd.print("You can Proceed ");delay(1000);
       lcd.setCursor(0,1);lcd.print("to voting buttons");delay(1000);lcd.clear();digitalWrite(m1,HIGH);digitalWrite(m2,LOW);delay(2000);digitalWrite(m2,LOW);digitalWrite(m1,LOW);
      //digitalWrite(m1,HIGH);digitalWrite(m2,LOW);delay(2000);digitalWrite(m2,LOW);digitalWrite(m1,LOW);
      
while(1)
{
if(digitalRead(b1)==LOW){party1=party1+1;delay(1000);lcd.setCursor(0,1);lcd.print("VOTED:P1");delay(1000);lcd.clear();lcd.print("THANK'U'");delay(1000);
  Serial.print("AT+CMGS=");
  Serial.print('"');
  Serial.print(number);
  Serial.print('"');
  Serial.print("\r\n");delay(1000);
  Serial.print("Thank you for your support and voting for Nation");delay(100);
  Serial.write(0x1A);delay(10000); 
  lcd.clear();lcd.print(" SMS SENT.....");delay(1000);
  lcd.setCursor(0,1);lcd.print("CHECH U R INBOX...");delay(1000);
   String iot="Party1_"+String(party1)+"_party2_"+String(party2)+"_party3_"+String(party3);
  mySerial.println(iot);delay(1000);     digitalWrite(m1,LOW);digitalWrite(m2,HIGH);delay(2000);digitalWrite(m2,LOW);digitalWrite(m1,LOW);
  
   lcd.clear();lcd.print("Ready to use>>>");  goto back;}
if(digitalRead(b2)==LOW){party2=party2+1;delay(1000);lcd.setCursor(0,1);lcd.print("VOTED:P2");delay(1000);lcd.clear();lcd.print("THANK'U'");delay(1000);
Serial.print("AT+CMGS=");
  Serial.print('"');
  Serial.print(number);
  Serial.print('"');
  Serial.print("\r\n");delay(1000);
  Serial.print("Thank you for your support and voting for Nation");delay(100);
  Serial.write(0x1A);delay(10000); 
  lcd.clear();lcd.print(" SMS SENT.....");delay(1000);
  lcd.setCursor(0,1);lcd.print("CHECH U R INBOX...");delay(1000);
    String iot="Party1_"+String(party1)+"_party2_"+String(party2)+"_party3_"+String(party3);
  mySerial.println(iot);delay(1000);     digitalWrite(m1,LOW);digitalWrite(m2,HIGH);delay(2000);digitalWrite(m2,LOW);digitalWrite(m1,LOW);
  //digitalWrite(m1,LOW);digitalWrite(m2,HIGH);delay(2000);digitalWrite(m2,LOW);digitalWrite(m1,LOW);
 
   lcd.clear();lcd.print("Ready to use>>>");  goto back;}
if(digitalRead(b3)==LOW){party3=party3+1;delay(1000);lcd.setCursor(0,1);lcd.print("VOTED:P3");delay(1000);lcd.clear();lcd.print("THANK'U'");delay(1000);
Serial.print("AT+CMGS=");
  Serial.print('"');
  Serial.print(number);
  Serial.print('"');
  Serial.print("\r\n");delay(1000);
  Serial.print("Thank you for your support and voting for Nation");delay(100);
  Serial.write(0x1A);delay(10000); 
  lcd.clear();lcd.print(" SMS SENT.....");delay(1000);
  lcd.setCursor(0,1);lcd.print("CHECH U R INBOX...");delay(1000);
  
   String iot="Party1_"+String(party1)+"_party2_"+String(party2)+"_party3_"+String(party3);
  mySerial.println(iot);delay(1000);     digitalWrite(m1,LOW);digitalWrite(m2,HIGH);delay(2000);digitalWrite(m2,LOW);digitalWrite(m1,LOW);
  
   lcd.clear();lcd.print("Ready to use>>>");  goto back;}

}
  }  
  else
  {
   lcd.clear();lcd.print("INVALID OTP ");delay(1000);beep();beep();
lcd.clear();lcd.print("change u r number");delay(5000); lcd.clear();lcd.print("AT");Serial.print("AT\r\n");delay(1000);  lcd.clear();lcd.print("ATE0");Serial.print("ATE0\r\n");delay(1000); lcd.clear();lcd.print("AT+CMGF=1");Serial.print("AT+CMGF=1\r\n");delay(1000);  lcd.clear();lcd.print("AT+CNMI=1,2,0,0");Serial.print("AT+CNMI=1,2,0,0\r\n");delay(1000); Serial.print("AT+CMGS=");

  Serial.print("AT+CMGS=");
  Serial.print('"');
  Serial.print(number);
  Serial.print('"');
  Serial.print("\r\n");delay(1000);
  Serial.print("U ENTERED WRONG OTP FOR VOTING:");delay(100);
  Serial.write(0x1A);delay(10000); 
 // Serial.end();delay(10000);Serial.begin(9600);delay(1000);
  lcd.clear();lcd.print(" SMS SENT.....");delay(1000);
  lcd.setCursor(0,1);lcd.print("CHECH U R INBOX...");delay(1000);
  if(dummy==1)
  {
   person1=0; 
  }
 if(dummy==2)
 {
  person2=0;
 }
 if(dummy==3)
 {
  person3=0;
 }
   lcd.clear();lcd.print("Ready to use>>>");  goto back; 
  }
 }




  else if(dummy==2)
  {
  person2=person2+1;delay(1000);
  if(person2>=2)
  {
   lcd.clear();lcd.print("You have already");
   lcd.setCursor(0,1);lcd.print("cast your vote");delay(1000);beep(); lcd.clear();lcd.print("Ready to use>>>");  goto back; 
  }
 
 lcd.setCursor(0,1);lcd.print("PERSON:2");delay(1000);
 lcd.clear();lcd.print("Generating OTP");delay(1000);

 //lcd.clear();lcd.print("OTP:");
 otp=OTP;
 //lcd.print(OTP);delay(2000);

  lcd.clear();lcd.print("SENDING OTP...");delay(1000);
  lcd.clear();lcd.print("change u r number");delay(1000); 
  lcd.clear();lcd.print("AT");Serial.print("AT\r\n");delay(1000);
  lcd.clear();lcd.print("ATE0");Serial.print("ATE0\r\n");delay(1000); 
  lcd.clear();lcd.print("AT+CMGF=1");Serial.print("AT+CMGF=1\r\n");delay(1000);  
  lcd.clear();lcd.print("AT+CNMI=1,2,0,0");Serial.print("AT+CNMI=1,2,0,0\r\n");delay(1000); 
  Serial.print("AT+CMGS=");
  Serial.print('"');
  Serial.print(number);
  Serial.print('"');
  Serial.print("\r\n");delay(1000);
  Serial.print("OTP FROM ARDUINO TO VOTING:");Serial.print(String(OTP));delay(100);
  Serial.write(0x1A);delay(10000); 
  lcd.clear();lcd.print("OTP is sent to");delay(1000);
  lcd.setCursor(0,1);lcd.print("your mobile...");delay(1000);
  lcd.clear();lcd.setCursor(0,1);lcd.print("PLZ ENTER OTP");delay(1000);
  int key=keypad();
  if(key==otp)
  {
   lcd.clear();lcd.print("VALID OTP ");delay(1000);
      lcd.clear();lcd.print("You can Proceed ");delay(1000);
       lcd.setCursor(0,1);lcd.print("to voting buttons");delay(1000);lcd.clear();digitalWrite(m1,HIGH);digitalWrite(m2,LOW);delay(2000);digitalWrite(m2,LOW);digitalWrite(m1,LOW);
while(1)
{
if(digitalRead(b1)==LOW){party1=party1+1;delay(1000);lcd.setCursor(0,1);lcd.print("VOTED:P1");delay(1000);lcd.clear();lcd.print("THANK'U'");delay(1000);
  Serial.print("AT+CMGS=");
  Serial.print('"');
  Serial.print(number);
  Serial.print('"');
  Serial.print("\r\n");delay(1000);
  Serial.print("Thank you for your support and voting for Nation");delay(100);
  Serial.write(0x1A);delay(10000); 
  lcd.clear();lcd.print(" SMS SENT.....");delay(1000);
  lcd.setCursor(0,1);lcd.print("CHECH U R INBOX...");delay(1000);
   String iot="Party1_"+String(party1)+"_party2_"+String(party2)+"_party3_"+String(party3);
  mySerial.println(iot);delay(1000);     digitalWrite(m1,LOW);digitalWrite(m2,HIGH);delay(2000);digitalWrite(m2,LOW);digitalWrite(m1,LOW);
  
   lcd.clear();lcd.print("Ready to use>>>");  goto back;}
if(digitalRead(b2)==LOW){party2=party2+1;delay(1000);lcd.setCursor(0,1);lcd.print("VOTED:P2");delay(1000);lcd.clear();lcd.print("THANK'U'");delay(1000);
Serial.print("AT+CMGS=");
  Serial.print('"');
  Serial.print(number);
  Serial.print('"');
  Serial.print("\r\n");delay(1000);
  Serial.print("Thank you for your support and voting for Nation");delay(100);
  Serial.write(0x1A);delay(10000); 
  lcd.clear();lcd.print(" SMS SENT.....");delay(1000);
  lcd.setCursor(0,1);lcd.print("CHECH U R INBOX...");delay(1000);
    String iot="Party1_"+String(party1)+"_party2_"+String(party2)+"_party3_"+String(party3);
  mySerial.println(iot);delay(1000);     digitalWrite(m1,LOW);digitalWrite(m2,HIGH);delay(2000);digitalWrite(m2,LOW);digitalWrite(m1,LOW);
 
   lcd.clear();lcd.print("Ready to use>>>");  goto back;}
if(digitalRead(b3)==LOW){party3=party3+1;delay(1000);lcd.setCursor(0,1);lcd.print("VOTED:P3");delay(1000);lcd.clear();lcd.print("THANK'U'");delay(1000);
Serial.print("AT+CMGS=");
  Serial.print('"');
  Serial.print(number);
  Serial.print('"');
  Serial.print("\r\n");delay(1000);
  Serial.print("Thank you for your support and voting for Nation");delay(100);
  Serial.write(0x1A);delay(10000); 
  lcd.clear();lcd.print(" SMS SENT.....");delay(1000);
  lcd.setCursor(0,1);lcd.print("CHECH U R INBOX...");delay(1000);
  
   String iot="Party1_"+String(party1)+"_party2_"+String(party2)+"_party3_"+String(party3);
  mySerial.println(iot);delay(1000);     digitalWrite(m1,LOW);digitalWrite(m2,HIGH);delay(2000);digitalWrite(m2,LOW);digitalWrite(m1,LOW);
  
   lcd.clear();lcd.print("Ready to use>>>");  goto back;}

}
  }  
  else
  {
   lcd.clear();lcd.print("INVALID OTP ");delay(1000);beep();beep();
lcd.clear();lcd.print("change u r number");delay(5000); lcd.clear();lcd.print("AT");Serial.print("AT\r\n");delay(1000);  lcd.clear();lcd.print("ATE0");Serial.print("ATE0\r\n");delay(1000); lcd.clear();lcd.print("AT+CMGF=1");Serial.print("AT+CMGF=1\r\n");delay(1000);  lcd.clear();lcd.print("AT+CNMI=1,2,0,0");Serial.print("AT+CNMI=1,2,0,0\r\n");delay(1000); Serial.print("AT+CMGS=");

  Serial.print("AT+CMGS=");
  Serial.print('"');
  Serial.print(number);
  Serial.print('"');
  Serial.print("\r\n");delay(1000);
  Serial.print("U ENTERED WRONG OTP FOR VOTING:");delay(100);
  Serial.write(0x1A);delay(10000); 
 // Serial.end();delay(10000);Serial.begin(9600);delay(1000);
  lcd.clear();lcd.print(" SMS SENT.....");delay(1000);
  lcd.setCursor(0,1);lcd.print("CHECH U R INBOX...");delay(1000);
  if(dummy==1)
  {
   person1=0; 
  }
 if(dummy==2)
 {
  person2=0;
 }
 if(dummy==3)
 {
  person3=0;
 }
   lcd.clear();lcd.print("Ready to use>>>");  goto back; 
  }
 }





  if(dummy==3)
  {
  person3=person3+1;delay(1000);
  if(person3>=2)
  {
   lcd.clear();lcd.print("You have already");
   lcd.setCursor(0,1);lcd.print("cast your vote");delay(1000);beep(); lcd.clear();lcd.print("Ready to use>>>");  goto back; 
  }
 
 lcd.setCursor(0,1);lcd.print("PERSON:1");delay(1000);
 lcd.clear();lcd.print("Generating OTP");delay(1000);

 //lcd.clear();lcd.print("OTP:");
 otp=OTP;
 //lcd.print(OTP);delay(2000);

  lcd.clear();lcd.print("SENDING OTP...");delay(1000);
  lcd.clear();lcd.print("change u r number");delay(1000); 
  lcd.clear();lcd.print("AT");Serial.print("AT\r\n");delay(1000);
  lcd.clear();lcd.print("ATE0");Serial.print("ATE0\r\n");delay(1000); 
  lcd.clear();lcd.print("AT+CMGF=1");Serial.print("AT+CMGF=1\r\n");delay(1000);  
  lcd.clear();lcd.print("AT+CNMI=1,2,0,0");Serial.print("AT+CNMI=1,2,0,0\r\n");delay(1000); 
  Serial.print("AT+CMGS=");
  Serial.print('"');
  Serial.print(number);
  Serial.print('"');
  Serial.print("\r\n");delay(1000);
  Serial.print("OTP FROM ARDUINO TO VOTING:");Serial.print(String(OTP));delay(100);
  Serial.write(0x1A);delay(10000); 
  lcd.clear();lcd.print("OTP is sent to");delay(1000);
  lcd.setCursor(0,1);lcd.print("your mobile...");delay(1000);
  lcd.clear();lcd.setCursor(0,1);lcd.print("PLZ ENTER OTP");delay(1000);
  int key=keypad();
  if(key==otp)
  {
   lcd.clear();lcd.print("VALID OTP ");delay(1000);
      lcd.clear();lcd.print("You can Proceed ");delay(1000);
       lcd.setCursor(0,1);lcd.print("to voting buttons");delay(1000);lcd.clear();digitalWrite(m1,HIGH);digitalWrite(m2,LOW);delay(2000);digitalWrite(m2,LOW);digitalWrite(m1,LOW);
while(1)
{
if(digitalRead(b1)==LOW){party1=party1+1;delay(1000);lcd.setCursor(0,1);lcd.print("VOTED:P1");delay(1000);lcd.clear();lcd.print("THANK'U'");delay(1000);
  Serial.print("AT+CMGS=");
  Serial.print('"');
  Serial.print(number);
  Serial.print('"');
  Serial.print("\r\n");delay(1000);
  Serial.print("Thank you for your support and voting for Nation");delay(100);
  Serial.write(0x1A);delay(10000); 
  lcd.clear();lcd.print(" SMS SENT.....");delay(1000);
  lcd.setCursor(0,1);lcd.print("CHECH U R INBOX...");delay(1000);
   String iot="Party1_"+String(party1)+"_party2_"+String(party2)+"_party3_"+String(party3);
  mySerial.println(iot);delay(1000);     digitalWrite(m1,LOW);digitalWrite(m2,HIGH);delay(2000);digitalWrite(m2,LOW);digitalWrite(m1,LOW);
  
   lcd.clear();lcd.print("Ready to use>>>");  goto back;}
if(digitalRead(b2)==LOW){party2=party2+1;delay(1000);lcd.setCursor(0,1);lcd.print("VOTED:P2");delay(1000);lcd.clear();lcd.print("THANK'U'");delay(1000);
Serial.print("AT+CMGS=");
  Serial.print('"');
  Serial.print(number);
  Serial.print('"');
  Serial.print("\r\n");delay(1000);
  Serial.print("Thank you for your support and voting for Nation");delay(100);
  Serial.write(0x1A);delay(10000); 
  lcd.clear();lcd.print(" SMS SENT.....");delay(1000);
  lcd.setCursor(0,1);lcd.print("CHECH U R INBOX...");delay(1000);
   String iot="Party1_"+String(party1)+"_party2_"+String(party2)+"_party3_"+String(party3);
  mySerial.println(iot);delay(1000);     digitalWrite(m1,LOW);digitalWrite(m2,HIGH);delay(2000);digitalWrite(m2,LOW);digitalWrite(m1,LOW);
  
   lcd.clear();lcd.print("Ready to use>>>");  goto back;}
if(digitalRead(b3)==LOW){party3=party3+1;delay(1000);lcd.setCursor(0,1);lcd.print("VOTED:P3");delay(1000);lcd.clear();lcd.print("THANK'U'");delay(1000);
Serial.print("AT+CMGS=");
  Serial.print('"');
  Serial.print(number);
  Serial.print('"');
  Serial.print("\r\n");delay(1000);
  Serial.print("Thank you for your support and voting for Nation");delay(100);
  Serial.write(0x1A);delay(10000); 
  lcd.clear();lcd.print(" SMS SENT.....");delay(1000);
  lcd.setCursor(0,1);lcd.print("CHECH U R INBOX...");delay(1000);
  
   String iot="Party1_"+String(party1)+"_party2_"+String(party2)+"_party3_"+String(party3);
  mySerial.println(iot);delay(1000);     digitalWrite(m1,LOW);digitalWrite(m2,HIGH);delay(2000);digitalWrite(m2,LOW);digitalWrite(m1,LOW);
  
   lcd.clear();lcd.print("Ready to use>>>");  goto back;}

}
  }  
  else
  {
   lcd.clear();lcd.print("INVALID OTP ");delay(1000);beep();beep();
lcd.clear();lcd.print("change u r number");delay(5000); lcd.clear();lcd.print("AT");Serial.print("AT\r\n");delay(1000);  lcd.clear();lcd.print("ATE0");Serial.print("ATE0\r\n");delay(1000); lcd.clear();lcd.print("AT+CMGF=1");Serial.print("AT+CMGF=1\r\n");delay(1000);  lcd.clear();lcd.print("AT+CNMI=1,2,0,0");Serial.print("AT+CNMI=1,2,0,0\r\n");delay(1000); Serial.print("AT+CMGS=");

  Serial.print("AT+CMGS=");
  Serial.print('"');
  Serial.print(number);
  Serial.print('"');
  Serial.print("\r\n");delay(1000);
  Serial.print("U ENTERED WRONG OTP FOR VOTING:");delay(100);
  Serial.write(0x1A);delay(10000); 
 // Serial.end();delay(10000);Serial.begin(9600);delay(1000);
  lcd.clear();lcd.print(" SMS SENT.....");delay(1000);
  lcd.setCursor(0,1);lcd.print("CHECH U R INBOX...");delay(1000);
  if(dummy==1)
  {
   person1=0; 
  }
 if(dummy==2)
 {
  person2=0;
 }
 if(dummy==3)
 {
  person3=0;
 }
   String iot="Party1_"+String(party1)+"_party2_"+String(party2)+"_party3_"+String(party3);
  mySerial.println(iot);delay(1000);     digitalWrite(m1,LOW);digitalWrite(m2,HIGH);delay(2000);digitalWrite(m2,LOW);digitalWrite(m1,LOW);
   lcd.clear();lcd.print("Ready to use>>>");  goto back; 
  }
 }

 }

}
///////////////////////////////////////Enroll////////////////////////////////////////


uint8_t getFingerprintEnroll() {

  int p = -1;
  //Serial.print("Waiting for valid finger to enroll as #"); ////Serial.println(id);
  while (p != FINGERPRINT_OK) {
    p = finger.getImage();
    
    ////Serial.println(p);
    ////Serial.println(FINGERPRINT_OK);
    ////Serial.println(FINGERPRINT_NOFINGER);
    ////Serial.println(FINGERPRINT_PACKETRECIEVEERR);
    ////Serial.println(FINGERPRINT_IMAGEFAIL);
    switch (p) {
    case FINGERPRINT_OK:              //result 0
      ////Serial.println("Image taken");
      
      break;
    case FINGERPRINT_NOFINGER:      //result 2
      ////Serial.println(".");
      break;
    case FINGERPRINT_PACKETRECIEVEERR:
      ////Serial.println("Communication error");
      goto ending;
      break;
    case FINGERPRINT_IMAGEFAIL:
      ////Serial.println("Imaging error");
      goto ending;
      break;
    default:
      ////Serial.println("Unknown error");
      goto ending;
      break;
    }
    delay(1000);
  }

  // OK success!
  ////Serial.println("Image converting.......");
  p = finger.image2Tz(1);
  ////Serial.println(p);
  switch (p) {
    case FINGERPRINT_OK:
      ////Serial.println("Image converted");
      break;
    case FINGERPRINT_IMAGEMESS:
      ////Serial.println("Image too messy");
      goto ending;
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      ////Serial.println("Communication error");
      goto ending;
      return p;
    case FINGERPRINT_FEATUREFAIL:
      ////Serial.println("Could not find fingerprint features");
      goto ending;
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      ////Serial.println("Could not find fingerprint features");
      goto ending;
      return p;
    default:
      ////Serial.println("Unknown error");
      goto ending;
      return p;
  }
  delay(1000);
  
  ////Serial.println("Remove finger");
  delay(1000);lcd.clear();lcd.print("Remove finger");delay(1000);
  delay(2000);
  p = 0;
  ////Serial.println(FINGERPRINT_NOFINGER);
  while (p != FINGERPRINT_NOFINGER) {
    p = finger.getImage();
  }
  ////Serial.println(FINGERPRINT_NOFINGER);
  ////Serial.println(p);
  //Serial.print("ID "); ////Serial.println(id);
  p = -1;
  ////Serial.println("Place same finger again");
   delay(1000);lcd.clear();lcd.print("Same finger Again");delay(1000);
  while (p != FINGERPRINT_OK) {
    p = finger.getImage();
    ////Serial.println(p);
    switch (p) {
    case FINGERPRINT_OK:
      ////Serial.println("Image taken");
      break;
    case FINGERPRINT_NOFINGER:
      //Serial.print(".");
      break;
    case FINGERPRINT_PACKETRECIEVEERR:
      ////Serial.println("Communication error");
      goto ending;
      break;
    case FINGERPRINT_IMAGEFAIL:
      ////Serial.println("Imaging error");
      goto ending;
      break;
    default:
      ////Serial.println("Unknown error");
      goto ending;
      break;
    }
  }

  // OK success!

  p = finger.image2Tz(2);
  ////Serial.println(p);
  switch (p) {
    case FINGERPRINT_OK:
      ////Serial.println("Image converted");
      break;
    case FINGERPRINT_IMAGEMESS:
      ////Serial.println("Image too messy");
      goto ending;
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      ////Serial.println("Communication error");
      goto ending;
      return p;
    case FINGERPRINT_FEATUREFAIL:
      ////Serial.println("Could not find fingerprint features");
      goto ending;
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      ////Serial.println("Could not find fingerprint features");
      goto ending;
      return p;
    default:
      ////Serial.println("Unknown error");
      goto ending;
      return p;
  }
  
  // OK converted!
  //Serial.print("Creating model for #");  ////Serial.println(id);
  
  p = finger.createModel();
  ////Serial.println(p);
  if (p == FINGERPRINT_OK) {
    ////Serial.println("Prints matched!");
  // lcd.clear(); lcd.print("Prints matched!");delay(1000);
    
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    ////Serial.println("Communication error");
    goto ending;
    return p;
  } else if (p == FINGERPRINT_ENROLLMISMATCH) {
    ////Serial.println("Fingerprints did not match");
    lcd.clear();lcd.print("Fingerprints did not match");delay(1000);
    goto ending;
    return p;
  } else {
    ////Serial.println("Unknown error");
    goto ending;
    return p;
  }   
  
  //Serial.print("ID "); ////Serial.println(id);
  p = finger.storeModel(id);
  ////Serial.println(p);
  delay(1000);lcd.clear();lcd.print("Place is:");lcd.print(id);delay(1000);
  if (p == FINGERPRINT_OK) {
    ////Serial.println("Stored!");
     delay(1000);lcd.clear();lcd.print("Stored");delay(1000);
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    ////Serial.println("Communication error");
    goto ending;
    return p;
  } else if (p == FINGERPRINT_BADLOCATION) {
    ////Serial.println("Could not store in that location");
    goto ending;
    return p;
  } else if (p == FINGERPRINT_FLASHERR) {
    ////Serial.println("Error writing to flash");
    goto ending;
    return p;
  } else {
    ////Serial.println("Unknown error");
    goto ending;
    return p;
  }
id = id+1;delay(100);
      if (id == 0) {                  // ID #0 not allowed, try again!
      return;
      }
ending:
delay(10);
}

///////////////////////////////////Identifying//////////////////

uint8_t getFingerprintID() {
  uint8_t p = finger.getImage();
  switch (p) {
    case FINGERPRINT_OK:
      ////Serial.println("Image taken");
      break;
    case FINGERPRINT_NOFINGER:
      ////Serial.println("No finger detected");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      ////Serial.println("Communication error");
      goto ending;
      return p;
    case FINGERPRINT_IMAGEFAIL:
      ////Serial.println("Imaging error");
      goto ending;
      return p;
    default:
      ////Serial.println("Unknown error");
      goto ending;
      return p;
  }

  // OK success!

  p = finger.image2Tz();
  switch (p) {
    case FINGERPRINT_OK:
      ////Serial.println("Image converted");
      break;
    case FINGERPRINT_IMAGEMESS:
      ////Serial.println("Image too messy");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      ////Serial.println("Communication error");
      goto ending;
      return p;
    case FINGERPRINT_FEATUREFAIL:
      ////Serial.println("Could not find fingerprint features");
      goto ending;
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      ////Serial.println("Could not find fingerprint features");
      goto ending;
      return p;
    default:
      ////Serial.println("Unknown error");
      goto ending;
      return p;
  }
  
  // OK converted!
  p = finger.fingerFastSearch();
  if (p == FINGERPRINT_OK) {
    ////Serial.println("Found a print match!");
   // lcd.clear();lcd.print("Found a print match!");delay(1000);
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    ////Serial.println("Communication error");
    goto ending;
    return p;
  } else if (p == FINGERPRINT_NOTFOUND) {
    ////Serial.println("Did not find a match");
    lcd.clear();lcd.print("Did not find a match");delay(1000);
    idnumber=0;delay(1000);beep();beep();  
     lcd.clear();lcd.print("Ready to use>>>");
    goto ending;
    return p;
  } else {
    ////Serial.println("Unknown error");
    goto ending;
    return p;
  }   
  
  // found a match!
  //Serial.print("Found ID #"); //Serial.print(finger.fingerID); 
  //Serial.print(" with confidence of "); ////Serial.println(finger.confidence); 
  delay(1000);lcd.clear();lcd.print("Found ID #");lcd.print(finger.fingerID); delay(2000);


   //lcd.setCursor(0,1);lcd.print(" with confidence of "); lcd.print(finger.confidence); 
  return finger.fingerID;
  ending:
  delay(10);
}
//////////////////////////////////////////////////Deleting finger////////////////////////////
uint8_t deleteFingerprint(uint8_t id) {
  uint8_t p = -1;
  
  p = finger.deleteModel(id);

  if (p == FINGERPRINT_OK) {
    ////Serial.println("Deleted!");
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    ////Serial.println("Communication error");
    goto ending;
    return p;
  } else if (p == FINGERPRINT_BADLOCATION) {
    ////Serial.println("Could not delete in that location");
    goto ending;
    return p;
  } else if (p == FINGERPRINT_FLASHERR) {
    ////Serial.println("Error writing to flash");
    goto ending;
    return p;
  } else {
    //Serial.print("Unknown error: 0x"); ////Serial.println(p, HEX);
    return p;
  }   
  ending:
  delay(10);
}
