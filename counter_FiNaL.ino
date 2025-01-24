#include <LCD-I2C.h>

//JMD ELECTRONIKS//VELLORE9080265658
//jmdelectroniks@gmail.com
#include <Wire.h> 

int mode =0; 
LCD_I2C lcd(0x27, 16, 2); 
int Ir=A0;
int count_value=0;

void setup()
{
                  
    Wire.begin();
    lcd.begin(&Wire);
    lcd.display();
    lcd.backlight();
 
 pinMode(Ir,INPUT_PULLUP);
}


void loop()
{

  int IR_SENSOR = digitalRead(Ir);
  
  if(IR_SENSOR == 0)
    {
    mode =1;delay(100);
    }
   if(IR_SENSOR == 1) 
    {
      if(mode == 1)
     { count_value++;
      mode =0;delay(100);}
      }

  lcd.setCursor(0,0);
  lcd.print("SMART COUNTER");
  lcd.setCursor(0,1);
  lcd.print("COUNT = ");
  lcd.print(count_value );
   
    
}
///have a good day
