#include <Wire.h>
#include <Adafruit_BMP085.h>
#include "SH1106.h" 
#include <Adafruit_NeoPixel.h>

#define BUTTON_PRESS   17  
#define BUTTON_LEFT    18                        
#define BUTTON_RIGHT   16 

#define PIXEL_PIN    21
#define PIXEL_COUNT 1

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);
bool oldState = HIGH;
int showType = 0;

Adafruit_BMP085 bmp;
SH1106  display(0x3c,4,5);

void setup() {
  pinMode(BUTTON_PRESS, INPUT_PULLUP);
  pinMode(BUTTON_LEFT, INPUT_PULLUP);
  pinMode(BUTTON_RIGHT, INPUT_PULLUP);
   
  strip.begin();
  strip.show();
  
  display.init();
  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_10);
  delay(10);
 
  
  Serial.begin(9600);
  Wire.begin(4,5);
  if (!bmp.begin()) {
	Serial.println("Could not find a valid BMP085 sensor, check wiring!");
	while (1) {}
  }
}
  
void loop() {
  

    display.clear();
    display.setFont(ArialMT_Plain_10);
    Serial.print("Temperature = ");
    Serial.print(bmp.readTemperature());
    Serial.println(" *C");
    String tem = String(bmp.readTemperature());
    display.drawString( 0, 0, "T="+tem+" *C");
   
    


    
    Serial.print("Pressure = ");
    Serial.print(bmp.readPressure());
    Serial.println(" Pa");
    String pre = String(bmp.readPressure());
    display.drawString( 0, 10, "P="+pre+" Pa");
    // Calculate altitude assuming 'standard' barometric
    // pressure of 1013.25 millibar = 101325 Pascal
    Serial.print("Altitude = ");
    Serial.print(bmp.readAltitude());
    Serial.println(" meters");
    String alt = String(bmp.readAltitude(102000));
    display.drawString( 0, 20, "H="+alt+" meters");
    
    
    display.setFont(ArialMT_Plain_16);
    display.drawString( 35, 40, "DSTIKE");

    
    Serial.print("Pressure at sealevel (calculated) = ");
    Serial.print(bmp.readSealevelPressure());
    Serial.println(" Pa");
    

  // you can get a more precise measurement of altitude
  // if you know the current sea level pressure which will
  // vary with weather and such. If it is 1015 millibars
  // that is equal to 101500 Pascals.
    Serial.print("Real altitude = ");
    Serial.print(bmp.readAltitude(102000));
    Serial.println(" meters");
    
    Serial.println();
    
    display.display();
    delay(100);
  colorWipe(strip.Color(0, 0, 0), 50);  // Black/off
  //colorWipe(strip.Color(127, 127, 127), 50); //White
  
  
    if(digitalRead(BUTTON_LEFT)==LOW)
  {
    colorWipe(strip.Color(255, 0, 0), 50); // Red
  }
  if(digitalRead(BUTTON_RIGHT)==LOW)
  {
    colorWipe(strip.Color(0, 255, 0), 50); // Green
  }
    if(digitalRead(BUTTON_PRESS)==LOW)
  {
    colorWipe(strip.Color(0, 0, 255), 50);  // Blue
  }
}

void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}
