/*
  Analog input, analog output, serial output

  Reads an analog input pin, maps the result to a range from 0 to 255 and uses
  the result to set the pulse width modulation (PWM) of an output pin.
  Also prints the results to the Serial Monitor.

  The circuit:
  - potentiometer connected to analog pin 0.
    Center pin of the potentiometer goes to the analog pin.
    side pins of the potentiometer go to +5V and ground
  - LED connected from digital pin 9 to ground

  created 29 Dec. 2008
  modified 9 Apr 2012
  by Tom Igo

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogInOutSerial
*/

// These constants won't change. They're used to give names to the pins used:
const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int analogOutPin = 9; // Analog output pin that the LED is attached to

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}

void loop() {
  static float waktu=0; // dalam milisecond
  float amplitude=50;
  int periode=40; // berapa lama delay
  float frekuensi=0.5;
float angka=0;
  
  angka=2*M_PI*frekuensi*waktu;
  outputValue=128+sin(2*M_PI*frekuensi*waktu/1000)*amplitude;
  analogWrite(analogOutPin, outputValue);
  Serial.print("t = ");
  Serial.print(waktu);
  Serial.print("\t output = ");
  Serial.println(outputValue);
  delay(periode);
  waktu+=periode;  
}
