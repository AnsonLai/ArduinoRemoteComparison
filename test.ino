/*      
*  IR read codes     
*  by Hanie kiani     
*  https://electropeak.com/learn/        
*/     
#include <IRremote.h>  //including infrared remote header file     
int RECV_PIN = 7; // the pin where you connect the output pin of IR sensor     
IRrecv irrecv(RECV_PIN);     
decode_results results;
int value;
     
void setup(){     
  Serial.begin(9600);     
  irrecv.enableIRIn();     
}
     
void loop()     
{     
  if (irrecv.decode(&results))// Returns 0 if no data ready, 1 if data ready.     
    {     
       value = results.value;// Results of decoding are stored in result.value     
       Serial.println(" ");     
       Serial.print("Code: ");     
       Serial.println(value); //prints the value a a button press     
       Serial.println(" ");     
       irrecv.resume(); // Restart the ISR state machine and Receive the next value

       if (value == -23971) {
        Serial.print("This is 1");
       }
    }
}     


///*
// 4 push signal and one relay module 4 relay with Remote
//
// Turns on and off 4 relays connected to digital
//*/
//// Read RF remote button codes using the RM4 library and send them over serial.
//#include <rm4.h>
//
//// Arduino pin connected to the receiver VCC in. Set this high to enable the
//// receiver.
//static const int kEnablePin = 2;
//
//// Arduino pins connected to the data pins on the receiver.
//static const int kData0Pin = 6;
//static const int kData1Pin = 5;
//static const int kData2Pin = 4;
//static const int kData3Pin = 3;
//
//// Create an RM4 object to read the button codes from the remote.
//RM4 remote(kData0Pin, kData1Pin, kData2Pin, kData3Pin);
//
//void setup() {
//  // Initialize the serial interface.
//  Serial.begin(9600);
//
//  // Turn on the receiver.
//  pinMode(kEnablePin, OUTPUT);
//  digitalWrite(kEnablePin, HIGH);
//
//}
//
//void loop() {
//  // Print the button code to the serial interface every 100 ms.
//  const int button_code = remote.buttonCode();
//   if (button_code == 8) {                      // pin 2 is pressed and connected to GND so it will be LOW
//    Serial.println("button B");                    // remove 5v from pin 11 so relay in1 will be 0v and this make relay on
//    delay (2000);                                 // wait 1 second
//  } 
//   if (button_code == 2) {                      // pin 2 is pressed and connected to GND so it will be LOW
//    Serial.println("button A");                     // remove 5v from pin 11 so relay in1 will be 0v and this make relay on
//    delay (2000);                                 // wait 1 second
//  } 
//   if (button_code == 1) {                      // pin 2 is pressed and connected to GND so it will be LOW
//    Serial.println("button C");                    // remove 5v from pin 11 so relay in1 will be 0v and this make relay on
//    delay (2000);                                 // wait 1 second
//  } 
//   if (button_code == 4) {                      // pin 2 is pressed and connected to GND so it will be LOW
//    Serial.println("button D");                   // remove 5v from pin 11 so relay in1 will be 0v and this make relay on
//    delay (2000);                                 // wait 1 second
//  } 
//
// // Serial.println(button_code);
//  
// // delay(100);
//}
