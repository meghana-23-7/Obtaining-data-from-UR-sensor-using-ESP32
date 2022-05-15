#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//declaring the dimensions of serial monitor
#define ScreenWidth 126
#define ScreenHeight  64

Adafruit_SSD1306 display(ScreenWidth, ScreenHeight, &Wire, -1);

const int trig_pin = 5;
const int echo_pin = 18;

#define Sound_speed 0.034
#define cm_to_inch 0.393701

long duration;
int distanceCm;
int distanceInch;

void setup() {
  Serial.begin(115200);
  pinMode(trig_pin, OUTPUT); 
  pinMode(echo_pin, INPUT); 

/*in the below line, 0x3C indicates address at which oled is found, if it is at different address, check for it, and feed it in place of 0x3C */

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); //when it is unable to connect to the serial monitor, this for loop keeps running.
  }
  delay(500);

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  
  distanceCm = duration * Sound_Speed/2;
  
  distanceInch = distanceCm * cm_to_inch;
  
  // here we are printing the distance on the Serial Monitor
  Serial.print("Distance (cm): ");
  Serial.println(distanceCm);
  Serial.print("Distance (inch): ");
  Serial.println(distanceInch);

  display.clearDisplay();
  display.setCursor(0, 25);

  //Displaying distance in cm
  display.print(distanceCm);
  display.print(" cm");
  
  // Displaying distance in inches, use only if u want to observe this output
  /* display.print(distanceInch);
  display.print(" in");*/

  display.display(); 

  delay(500);  
}
