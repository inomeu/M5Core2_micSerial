#include <M5Core2.h>

#define MIC 36
//ここの値はマイクをさした場所

const int sampleWindow = 50;

void setup() {
  M5.begin();
  Serial.begin(115200);
  while (!Serial);
  M5.lcd.setBrightness(20);

  pinMode(MIC,INPUT);
}

void loop() {
  unsigned long t = millis();
  unsigned int sample;
  unsigned int sMax = 0, sMin = 4095;
  
  while(millis() - t < sampleWindow){
    sample = analogRead(MIC);
    if(sample > sMax) sMax = sample;
    if(sample < sMin) sMin = sample;
  }

  float volts = (float)(sMax - sMin) / 4095.0 * 3.6;
  Serial.println(volts);
  delay(100);
}
