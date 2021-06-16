#include "SH1106.h" 

SH1106  display1(0x3d,21,22);
SH1106  display2(0x3c,21,22);

int i, j;

void setup() {
  display1.init();
  display1.flipScreenVertically();
  display1.setFont(ArialMT_Plain_10);
  delay(10);
  display1.clear();
  display1.drawString( 24, 0, "Display 1");
  display1.fillCircle(30, 30,  15);
  display1.display();
  delay(1000);
  
  display2.init();
  display2.flipScreenVertically();
  display2.setFont(ArialMT_Plain_10);
  delay(10);
  display2.clear();
  display2.drawString( 24, 0, "Display 2");
  display2.fillRect(30, 30,  25, 25);
  display2.display();
  delay(1000);



}

void loop() {

    for (i = 0; i < 500; i+=1) {
      
    display1.fillCircle(i, 30,  15);
    display1.display();
    display1.clear();

    display2.fillRect(i - 128, 30,  25, 25);
    display2.display();
    display2.clear();
    }
}
