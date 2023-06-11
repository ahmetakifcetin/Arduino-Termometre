#include <Adafruit_GFX.h>       
#include <Adafruit_SSD1306.h>  
#include <Fonts/FreeMonoBold18pt7b.h>  
#include "DHT.h"

#define DHTPIN 8 
#define DHTTYPE DHT11   

DHT dht (DHTPIN , DHTTYPE);
Adafruit_SSD1306 display(128, 64);      


void setup()
{                
  delay(100);  
  dht.begin();
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  
  display.clearDisplay();  
  display.setTextColor(WHITE);  
}

void loop()
{
  float temp = dht.readTemperature();

  display.clearDisplay();  
  display.setFont();
  display.setCursor(45,10); 
  display.println("SICAKLIK");  

  char string[10];  
  dtostrf(temp, 3, 0, string); 
  
  display.setFont(&FreeMonoBold18pt7b);  
  display.setCursor(20,50);  
  display.println(string);  
  display.setCursor(90,50); 
  display.println("C");  
  display.setCursor(77,32);  
  display.println("."); 
  display.fillCircle(18, 55, 7, WHITE); 
  display.drawRoundRect(16, 3, 5, 49, 2, WHITE);  

  for (int i = 6; i<=45; i=i+3)
  {
    display.drawLine(21, i, 22, i, WHITE);  
  }
  
  display.drawLine(18, 46, 18, 46-temp, WHITE);  
  display.display();  
}
