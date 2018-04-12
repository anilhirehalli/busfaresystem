#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
#define I2C_ADDR    0x3F // LCD address
#define BACKLIGHT_PIN     3
#define En_pin  2
#define Rw_pin  1
#define Rs_pin  0
#define D4_pin  4
#define D5_pin  5
#define D6_pin  6
#define D7_pin  7
LiquidCrystal_I2C  lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);
#include <SPI.h>
#include <MFRC522.h>
#define RST_PIN         9
#define SS_PIN          10
#include <Keypad.h>
int k=1;
int f=1;
int key=0;
#include <SoftwareSerial.h>



SoftwareSerial mySerial(7,8);//tx,rx//gsm
char str[181];
char g[20];
char h[50];
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = 
{
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
     byte colPins[COLS] = {A1,A0,2,3}; //   orange,blue,green,yellow,
  byte rowPins[ROWS] = {5,6,A3,A2}; //  not cement,cement,pink,light blue
    Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
   MFRC522 mfrc522(SS_PIN, RST_PIN);
int RfidNo = 0;
int b = 0;
int n,x,a,j,c,m,z;
char e;
char password1[5] = "1111";
char password[5] = "2222";
  char tempPassword[5];
int tempPasswordIndex = 0;
void setup()
{
   mySerial.begin(9600);   // Setting the baud rate of GSM Module  
lcd.begin (16,2); //  <<----- My LCD was 16x2
// Switch on the backlight
lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
lcd.setBacklight(HIGH);
lcd.home (); // go home
//lcd.print("        Anil");  
Serial.begin(9600);
SPI.begin();
mfrc522.PCD_Init();
lcd.print("Welcome to KSRTC");
//lcd.print(n);
 lcd.setCursor (0,1);        // go to start of 2nd line
 lcd.print("Scan the Card");
 

}

void loop() {
  


RfidScan();
}

int anil(int n ,int x)
{
   while(1)
  {
  char key = keypad.getKey();
  
   if (int(key)!=0)
   {
  lcd.clear();
  lcd.setCursor (0,0);
mohith(n,x);
return;
   }
  }
}


void dump_byte_array(byte *buffer, byte bufferSize)
{ int n ,x;
lcd.clear();
 lcd.setCursor (0,0);        // go to start of 2nd line
// lcd.print("      EngIN");
//Serial.print("~");
if(buffer[0] == 161){RfidNo = 1;Serial.print(RfidNo);}
if(buffer[0] == 171){RfidNo = 2;Serial.print(RfidNo);}
if(buffer[0] == 160){RfidNo = 3;lcd.print("Invalid card.");}
if(buffer[3] == 190){RfidNo = 4;lcd.print("GuruPrasad ");
 lcd.setCursor (0,1);  
lcd.print("Enter the Pass");
n = buffer[3];
x = RfidNo;
anil(n,x);
//password(n,x);
return;}
if(buffer[0] == 181){RfidNo = 5;lcd.print("Anil kumar");
 lcd.setCursor (0,1);  
lcd.print("Enter the Pass");
n = buffer[0];
x = RfidNo;
anil(n,x);
//passwo0rd(n,x);
return;
}
//Serial.print("!");
//while(1){getFingerprintIDez();}
}

void RfidScan()
{
  
if ( ! mfrc522.PICC_IsNewCardPresent())
return;

if ( ! mfrc522.PICC_ReadCardSerial())
return;
dump_byte_array(mfrc522.uid.uidByte, mfrc522.uid.size);

}
void mohith(int n, int x)//
{
 while(1)
 {
    char key = keypad.getKey();
  if (int(key)!=0){
   if (key){
     lcd.print("*");
     
    tempPassword[tempPasswordIndex] = key;
    tempPasswordIndex++;
     if(tempPasswordIndex>3)
     
    {  
      if(n==190)
      {
         
      tempPasswordIndex = 0;
     if(checkPassword1())
      {
        lcd.setCursor (0,1); 
       lcd.print("success....");
        delay(2000);
       lcd.clear();
        lcd.setCursor (0,0); 
        lcd.print("Destination");
        ashwin(n);
    }
    else
      {
        lcd.setCursor (0,1); 
        lcd.print("wrong....");
         delay(2000);
        lcd.clear();
       
   }
      }
       
      if(n==181)
      {
      tempPasswordIndex = 0;
     if(checkPassword())
      {
         lcd.setCursor (0,1); 
       lcd.print("success....");
        delay(2000);
       lcd.clear();
        lcd.setCursor (0,0); 
        lcd.print("Destination");
        ashwin(n);
    }
    else
      {
        lcd.setCursor (0,1); 
        lcd.print("wrong....");
        delay(2000);
        lcd.clear();
       
   }
      }
   }
   }
   delay(10);

  }

  }
}

  void guru(int b,int n)
  {
      lcd.clear();
      lcd.setCursor (0,0); 
      lcd.print("number of people");  
     while(1){
      char key = keypad.getKey();

  if (int(key)!=0){
   //clear
   if((int(key)!=65)&&(int(key)!=66)&&(int(key)!=67)&&(int(key)!=42)&&(int(key)!=48)&&(int(key)!=35)&&(int(key)!=68))
   {
    lcd.setCursor (0,1); 
    lcd.print(key);
   e=(key);
   }
   if (int(key)==68){
    if(e==0){
      lcd.setCursor (0,1);
      lcd.print("enter correctly");
      lcd.clear();
       lcd.setCursor (0,0); 
      lcd.print("number of people");
      }
      else{
        
    c=(e-48);
     lcd.clear();
      lcd.setCursor(0,0);
       lcd.print("total amount");
      
       lcd.setCursor(0,1);
        lcd.print(e);lcd.print("x");lcd.print(b);lcd.print("=");lcd.print(c*b);
   
        manoj(b,n,c);
      }
        }
      }
    }
  }
  
     void ashwin(int n)
   {
     while(1)
  {
     char key = keypad.getKey();

  //if (int(key)!=0){
   
      if(int(key)==65){        
      { f++;
     
      if(f==2){ lcd.clear();
       lcd.setCursor (0,0);      
      lcd.print("Destination");
      lcd.setCursor (0,1);  
      lcd.print("mandya");}
      if(f==3){ lcd.clear();
       lcd.setCursor (0,0);      
      lcd.print("Destination");
      lcd.setCursor (0,1); 
      lcd.print("ramanagara");}
      if(f==4){  lcd.clear();
       lcd.setCursor (0,0);      
       lcd.print("Destination");
      lcd.setCursor (0,1);lcd.print("maddur");}
    
      if(f==5){  lcd.clear();
       lcd.setCursor (0,0);      
      lcd.print("Destination");
      lcd.setCursor (0,1); 
      lcd.print("bidadi");}
     
      if(f==6){ lcd.clear();
       lcd.setCursor (0,0);      
      lcd.print("Destination");
      lcd.setCursor (0,1); 
      lcd.print("bangalore");}
       
        }  
        }
        else if(int(key)==66)
        {
          f--; 
     if(f==2){ lcd.clear();
       lcd.setCursor (0,0);      
       lcd.print("Destination");
      lcd.setCursor (0,1); 
      lcd.print("mandya");}
   
      if(f==3){  lcd.clear();
       lcd.setCursor (0,0);      
      lcd.print("Destination");
      lcd.setCursor (0,1); 
      lcd.print("ramanagara");}
     
      if(f==4){ lcd.clear();
       lcd.setCursor (0,0);      
       lcd.print("Destination");
      lcd.setCursor (0,1); 
      lcd.print("maddur");}
      
      if(f==5){lcd.clear();
       lcd.setCursor (0,0);      
      lcd.print("Destination");
      lcd.setCursor (0,1); 
      lcd.print("bidadi");}
      
      if(f==6){lcd.clear();
       lcd.setCursor (0,0);      
      lcd.print("Destination");
      lcd.setCursor (0,1); 
      lcd.print("bangalore");}
    
      
      }
      else if(int(key)==68)
      { lcd.clear();
      lcd.setCursor (0,0); 
      lcd.print("Destination is ");
      lcd.setCursor (0,1); 
      if(f<2){b=28;lcd.print("mandya");}
      if(f==2){b=28;lcd.print("mandya");}
      if(f==3){b=52;lcd.print("ramanagara");}
      if(f==4){b=75;lcd.print("maddur");}
      if(f==5){b=90;lcd.print("bidadi");}
      if(f==6){b=130;lcd.print("bangalore");}
      if(f>6){b=130;lcd.print("bangalore");}
       delay(1000);
        a=f;
        guru(b,n);
        }
  }
   }

   void manoj(int b,int n, int c)
   {
    while(1){
     char key = keypad.getKey();
    if(int(key)==68)
    {
       lcd.clear();
      lcd.setCursor(0,0);
    lcd.print("Sending an SMS.....");
    delay(2000);
    if(n==190)
    {
      lcd.clear();
      lcd.setCursor(0,0);
     lcd.print("Guruprasad ");
      lcd.setCursor(0,1);
    if(f<2){b=28; lcd.print("mandya    ");}
      if(f==2){b=28; lcd.print("mandya   ");}
      if(f==3){b=52; lcd.print("ramanagara   ");}
      if(f==4){b=75; lcd.print("maddur   ");}
      if(f==5){b=90; lcd.print("bidadi   ");}
      if(f==6){b=130; lcd.print("bangalore   ");}
      if(f>6){b=130; lcd.print("bangalore    ");}
      lcd.print(c*b);
       mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
   delay(1000);  // Delay of 1000 milli seconds or 1 second
   mySerial.println("AT+CMGS=\"+919844267405\"\r"); // Replace x with mobile number
   delay(1000);
   mes( b, n, c);
   //sprintf(str, "Value of Pi = %d",c);
  
  
  
      }
      
     else if(n==181)
    {
       lcd.clear();
      lcd.setCursor(0,0);
     lcd.print("Anil kumar");
      lcd.setCursor(0,1);
          if(f<2){b=28; lcd.print("mandya    ");}
      if(f==2){b=28; lcd.print("mandya   ");}
      if(f==3){b=52; lcd.print("ramanagara   ");}
      if(f==4){b=75; lcd.print("maddur   ");}
      if(f==5){b=90; lcd.print("bidadi   ");}
      if(f==6){b=130; lcd.print("bangalore   ");}
      if(f>6){b=130; lcd.print("bangalore    ");}
      lcd.print(c*b);
      mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
   delay(1000);  // Delay of 1000 milli seconds or 1 second
   mySerial.println("AT+CMGS=\"+919738677538\"\r"); 
   delay(1000);
   mes( b, n, c);
  
  
  
  
      }
    }
    }
   return; }
    
    boolean checkPassword1()
 {
   if(strncmp(password1, tempPassword, 4) == 0)
   {
    return true;
   }
   return false;
 }
  boolean checkPassword()
 {
   if(strncmp(password, tempPassword, 4) == 0)
   {
    return true;
   }
   return false;
 }

 void mes(int b,int n, int c)
 {
  m=c*b;
  if(n==181)
  {
    sprintf(g,"Anil kumar");
    }
     if(n==190)
  {
    sprintf(g,"Guru prasad");
    }
     if(f<2){b=28; sprintf(h,"mandya");}
      if(f==2){b=28; sprintf(h,"mandya");}
      if(f==3){b=52; sprintf(h,"ramanagar");}
      if(f==4){b=75; sprintf(h,"maddur");}
      if(f==5){b=90;sprintf(h,"bidadi");}
      if(f==6){b=130;sprintf(h,"bangalore");}
      if(f>6){b=130;sprintf(h,"bangalore");}
  sprintf(str, "(Serial number) (date and time) Hi %s You are travelling to %s total ticket is %d & total amount is %d ... Happy journey..!!",g,h,c,m);
   mySerial.println(str);// The SMS text you want to send
   delay(100);
    mySerial.println((char)26);// ASCII code of CTRL+Z
   delay(1000);
   Serial.print(g);
   space();
   Serial.print(h);  
   space();
   Serial.print(c);
   space();
   Serial.println(m);
  }

  void space()
  {
  for(z=0;z<4;z++)
  {
   Serial.print("\t"); 
   }  
  }
