# Obtaining-data-from-UR-sensor-using-ESP32
 We are printing and observing the distance measured by the HC-SR04 sensor connected to ESP32.

## Task number: 07

## Task name: Obtaining data from ultrasonic sensor using ESP32. 

## Reference
https://randomnerdtutorials.com/esp32-hc-sr04-ultrasonic-arduino/

## Components used
ESP32, ultrasonic sensor,oled display, jumper wires and breadboard.

Connections: Here, we connect the trig pin of the sensor to GPIO-5 and echo pin to GPIO-18. Connect Vcc and ground of ESP32 to that of the sensor. 
If we wish to see output on oled then, along with the above connections, connect the VCC and ground of it to that of ESP32. Connect SCK and SDA pins of oled to the same pins of ESP32 i.e. GPIO-22 and GPIO-21 respectively.

## Theory 
Here we are printing and observing the distance measured by the HC-SR04 sensor connected to ESP32.
HC-SR04 Ultrasonic sensor: uses sonar to find distance to an object, can read from 2cm to 400cm. This has 4 pinouts, VCC, ground, trigger input and echo output. 
The transmitter at trig pin, transmits high frequency sound waves,this sound travelling through air bounces back when it finds an object. The ultrasonic receiver at the echo pin, receives this bounced back signal.
Now, distance=((velocity of sound in air)*duration)/2
Here, duration is the interval between the sound wave emitted and detected.

## Code
https://github.com/meghana-23-7/Obtaining-data-from-UR-sensor-using-ESP32/blob/main/sketch_task7Oled.ino
The above code is for connections with OLED, if not required just remove the unnecessary part of the code, and it works fine. 
 
With no OLED:
https://github.com/meghana-23-7/Obtaining-data-from-UR-sensor-using-ESP32/blob/main/sketch_task7NoOled.ino


## Procedure
Create a sketch for this project on arduino, write and verify the above code.
Make the necessary connections between ESP32, OLED and Sensor.
Connect this circuit to the computer through USB cable.
Go to tools, select appropriate board names and com ports.
Upload the code to ESP32.
Open the serial monitor to see the output.
Also observe the output on OLED if connected.

## Problems faced: none for this task. 

## Output 
The ultrasonic measured the distance from the object, distance was successfully printed on serial monitor and also the OLED display. Here it has measured how far is the ceiling above the table.



