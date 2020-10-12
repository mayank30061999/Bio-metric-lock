#include <SoftwareSerial.h>
SoftwareSerial BT(10, 11); //RX, TX respetively
String device;
int check = 0;
void setup() {
  BT.begin(9600);
  Serial.begin(9600);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
}
//-----------------------------------------------------------------------//
void loop() {
  while (BT.available()) { //Check if there is an available byte to read
    delay(10); //Delay added to make thing stable
    char c = BT.read(); //Conduct a serial read
    device += c; //build the string.
  }
  if (device.length() > 0) {
    Serial.println(device);
    if (device == "adrfjhlnm\n")
    {if(check==0)
      { digitalWrite(7, HIGH);
        BT.print("LOCKING    ");
        check = 1;
        delay(300);
        digitalWrite(7, LOW);
      }
      BT.print("LOCKED    ");
      delay(1000); 
    }
    else if (device == "wrong\n")
    {if (check==1)
    {  digitalWrite(8, HIGH);
        BT.print("UNLOCKING    ");
        check = 0;
        delay(300);
        digitalWrite(8, LOW);
    } 
      BT.print("UNLOCKED    ");
      delay(1000);
    }
    device = "";
  }
  
} //Reset the variable
