/*
  ESP8266 LED
*/
#include "controller.h"
#include "uploadOTA.h"
#include "webServer.h"


//////////////////////////////////////////////////////////Server/////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Model model("MyName1");
Model modelxxx("MyName1xxx");
  
//printf("Model name1: %s\n", model._name.c_str());
//printf("Model adress1: %p\n", &model);
  
Controller controller(model); 
//printf("Controller adress1: %p\n", &controller);
  
WebServer wserver(controller);

void setup() {
  //////////////////////////////////////////////////////////OTA and Server/////////////////////////////////////////////////////////////////////////
  Serial.begin(115200);
  Serial.println("Booting");
  UploadOTA uploadOTA;

  
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  
  Serial.println("LED initialization...");
  pinMode(2, OUTPUT);
  
  Serial.println("insert RGB values...");
  RGB pin_color = { 125, 25, 48 };
  controller.insertRGB(pin_color);
}


// the loop function runs over and over again forever
void loop() {
  wserver.server.handleClient();                      // run the server
  wserver.webSocket.loop();                           // constantly check for websocket events
  ArduinoOTA.handle();                        // listen for OTA events
  
  /*for(int i=0; i<=10; i++){
    controller.runQueue();
    delay(2000);
  }*/
}
