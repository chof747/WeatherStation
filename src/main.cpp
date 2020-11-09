#include <Arduino.h>
#include <WiFiManager.h>

void setupNetwork() 
//******************************************************************************
{
  WiFiManager wifi();

  #ifdef SERIAL_PRINT
  wifi.setDebugOutput(true);
  #else
  wifi.setDebugOutput(false);
  #endif

  if(!wifi.autoConnect()) {
    #ifdef SERIAL_PRINT
    Serial.println("failed to connect and hit timeout");
    #endif
    //reset and try again, or maybe put it to deep sleep
    ESP.reset();
    delay(1000);
  } 

}

void setup() 
//******************************************************************************
{
  setupNetwork();
}

void loop() 
//******************************************************************************
{
  // put your main code here, to run repeatedly:
}