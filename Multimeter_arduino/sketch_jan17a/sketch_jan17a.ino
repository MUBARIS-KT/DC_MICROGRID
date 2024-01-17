#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64 
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int current_sensor_pin = A0;
const int voltage_sensor_Pin = A2;
float Read_voltage();
float Read_current();
float r1 = 10000;
float r2 = 3000;

void setup()
{
  Serial.begin(9600);
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
}

void loop() {
 
display.clearDisplay();
display.setCursor(0, 0);
display.print("V= " + String(Read_voltage()) + " V\n\nI= " + String(Read_current()) + " A");
display.display();
delay(300);
}
// USER_FUNCTION_DEFNITIONS
float Read_voltage()
{
  int value_in = analogRead(voltage_sensor_Pin);
  float temp_1 = value_in * 5/1023.0;
  float v = temp_1*(r1+r2)/r2;
  return v;
}

float Read_current()
{
  int adc = analogRead(current_sensor_pin);
  float temp_v = adc*5/1023.0;
  float i = (temp_v -2.5)/0.185;
  return i ;
}