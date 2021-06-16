#include "SH1106.h" 
#define BUTTON_PRESS   19 
#define BUTTON_LEFT    18                      
#define BUTTON_RIGHT   27 
#define BUTTON_32   32 

SH1106  display1(0x3d,21,22);
SH1106  display2(0x3c,21,22);

void setup() {
  pinMode(BUTTON_LEFT,INPUT_PULLUP);
  pinMode(BUTTON_PRESS,INPUT_PULLUP);
  pinMode(BUTTON_RIGHT,INPUT_PULLUP);
  pinMode(BUTTON_32,INPUT_PULLUP);

  display1.init();
  display1.flipScreenVertically();
  display1.setFont(ArialMT_Plain_10);
  delay(10);
  display1.clear();
  display1.drawString( 0, 0, "Please press each button");
  display1.drawString( 0, 10, "Switch Left");
  display1.drawString( 0, 20, "Switch Press");
  display1.drawString( 0, 30, "Switch Right");
  display1.drawString( 0, 40, "Switch Lower Left corner");
  display1.display();
  

  display2.init();
  display2.flipScreenVertically();
  display2.setFont(ArialMT_Plain_24);
  delay(10);
  display2.clear();
  display2.display();
}

void loop() {
  

  if(digitalRead(BUTTON_LEFT)== LOW)
  {display2.clear();
   display2.drawString( 0, 0, "Button--18");
   display2.drawString( 0, 24, "Test OK");
   display2.display();
  }
    if(digitalRead(BUTTON_RIGHT)== LOW)
  {display2.clear();
   display2.drawString( 0, 0, "Button--27");
   display2.drawString( 0, 24, "Test OK");
   display2.display();
  }
    if(digitalRead(BUTTON_PRESS)== LOW)
  {display2.clear();
   display2.drawString( 0, 0, "Button--19");
   display2.drawString( 0, 24, "Test OK");
   display2.display();
  }
      if(digitalRead(BUTTON_32)== LOW)
  {display2.clear();
   display2.drawString( 0, 0, "Button--32");
   display2.drawString( 0, 24, "Test OK");
   display2.display();
  }
}
