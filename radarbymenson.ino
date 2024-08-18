#include <Adafruit_GFX.h>  
#include <Adafruit_ST7789.h> 
#include <SPI.h>
#include <Servo.h>
#define TFT_CS         4
#define TFT_DC         2
#define TFT_RST        15                             
#define TFT_MOSI       D23      
#define TFT_SCLK       D18   
const int trig = 16;    
const int echo = 17; 
unsigned long duration;
int distance;          
int distancee;
static const int servoPin = 13;
Servo servo1;
#define PI 3.14159265
Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

void setup()
{ 
  tft.setSPISpeed(40000000);   
  pinMode(trig,OUTPUT);  
  pinMode(echo,INPUT);
  servo1.attach(servoPin);
  tft.init(240, 320, SPI_MODE3);  
  tft.fillScreen(ST77XX_BLACK); 
  tft.setRotation (3);
  tft.setTextColor(ST77XX_WHITE);
  tft.setTextSize(3);
  tft.setCursor(50,85);
  tft.print("PROJECT MADE");
  tft.setCursor(80,135);
  tft.print( "BY MENSON");
  delay(4000);
  tft.fillRect(0,0,360,360,ST77XX_BLACK);
  KHUNG();
}
void loop()
{
for(int i=0; i<180 ;i++)
{
  servo1.write(180-i);
    delayMicroseconds(2);
    digitalWrite(trig,1);  
    delayMicroseconds(5);   
    digitalWrite(trig,0);  
 duration = pulseIn(echo,HIGH);  
 distance =  int(duration/2/29.412);
 if(distance<101)
 {
 distancee= map(distance,0,100,0,159);
 CHAY(distancee,i);
 GIATRI(distance);
 delay(100);
 tft.fillRect(25,210,35,233,ST77XX_BLACK);
 tft.fillRect(5,25,35,50,ST77XX_BLACK);
}
if(distance>100)
{
CHAY(159,i);
GIATRI(100);
delay(100);
tft.fillRect(25,210,35,233,ST77XX_BLACK);
tft.fillRect(5,25,35,50,ST77XX_BLACK);
}
}
  tft.fillRect(0,0,360,360,ST77XX_BLACK);
  KHUNG();
for(int i=180; i>0 ;i--)
{ 
  servo1.write(180-i);
    delayMicroseconds(2);
    digitalWrite(trig,1);  
    delayMicroseconds(5);   
    digitalWrite(trig,0);  
duration = pulseIn(echo,HIGH);  
distance =  int(duration/2/29.412);;
if(distance<101)
{
distancee= map(distance,0,100,0,159);  
CHAY(distancee,i);
GIATRI(distance);
delay(100);
tft.fillRect(25,210,35,233,ST77XX_BLACK);
tft.fillRect(5,25,35,50,ST77XX_BLACK);
}
if(distance>100)
{
CHAY(159,i);
GIATRI(100);
delay(100);
tft.fillRect(25,210,35,233,ST77XX_BLACK);
tft.fillRect(5,25,35,50,ST77XX_BLACK);
}
}
 tft.fillRect(0,0,360,360,ST77XX_BLACK);
  KHUNG();
}
void GIATRI(int kc)
{ 
  tft.setTextColor(ST77XX_RED);
  tft.setCursor(25,210);
  tft.print(kc);
  tft.print("cm");

  if (kc<99)
  {
  tft.setCursor(5,25);
  tft.setTextSize(2);
  tft.print("YES");
  
  }
    if (kc>99)
  {
  tft.setCursor(5,25);
  tft.setTextSize(2);
  tft.print("NO");
  }

}
void CHAY(int kc, int i)
{
  double val=PI/180;
  double coss=cos(i*val);
  double sinn=sin(i*val);
  unsigned short ngang=coss*159; 
  unsigned short doc=sinn*159; 
  unsigned short ngangg=coss*kc; 
  unsigned short docc=sinn*kc; 
  tft.drawLine(160,190,160-ngang,190-doc,ST77XX_RED);
  tft.drawLine(160,190,160-ngangg,190-docc,ST77XX_GREEN);
  tft.setTextColor(ST77XX_RED);
  tft.setTextSize(1);
  tft.setCursor(25,223);
  tft.print(i);
  tft.write(0xF7);

}
void KHUNG()
{
  tft.drawCircle(160,190,159,ST77XX_GREEN); 
  tft.drawCircle(160,190,109,ST77XX_GREEN); 
  tft.drawCircle(160,190,59,ST77XX_GREEN); 
  tft.drawLine(160,190,160,31,ST77XX_GREEN);
  tft.drawLine(160,190,239,52,ST77XX_GREEN);
  tft.drawLine(160,190,298,111,ST77XX_GREEN);
  tft.drawLine(160,190,81,52,ST77XX_GREEN);
  tft.drawLine(160,190,22,111,ST77XX_GREEN);
  tft.drawLine(0,190,360,190,ST77XX_GREEN);
  tft.fillRect(0,191,360,60,ST77XX_BLACK);

  tft.setTextColor(ST77XX_GREEN);
  tft.setCursor(157,20);
  tft.setTextSize(1);
  tft.print("90");
  tft.write(0xF7);
  tft.setCursor(246,48);
  tft.setTextSize(1);
  tft.print("60");
  tft.write(0xF7);
  tft.setCursor(302,108);
  tft.setTextSize(1);
  tft.print("30");
  tft.write(0xF7);
  tft.setCursor(60,48);
  tft.setTextSize(1);
  tft.print("60");
  tft.write(0xF7);
  tft.setCursor(2,108);
  tft.setTextSize(1);
  tft.print("30");
  tft.write(0xF7);
  tft.setCursor(2,4);
  tft.setTextSize(1);
  tft.print("PHAT HIEN VAT:");

   tft.setCursor(1,192);
  tft.setTextSize(1);
  tft.print("100cm");
  tft.setCursor(48,192);
  tft.setTextSize(1);
  tft.print("60cm");
  tft.setCursor(98,192);
  tft.setTextSize(1);
  tft.print("30cm");
  tft.setCursor(150,192);
  tft.setTextSize(1);
  tft.print("0cm");
  tft.setCursor(290,192);
  tft.setTextSize(1);
  tft.print("100cm");
  tft.setCursor(250,192);
  tft.setTextSize(1);
  tft.print("60cm");
  tft.setCursor(200,192);
  tft.setTextSize(1);
  tft.print("30cm");

  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(120,210);
  tft.setTextSize(2);
  tft.print("DESIGN BY MENSON");
  tft.setTextColor(ST77XX_GREEN);
  tft.setCursor(2,210);
  tft.setTextSize(1);
  tft.print("K/C:");
  tft.setCursor(2,223);
  tft.setTextSize(1);
  tft.print("GOC:");
}


