/*
  ESP8266 AWS IoT demo

  Simple demo code to provide static data into AWS IoT platform
  
  created   Mar 2017
  by CheapskateProjects

  ---------------------------
  The MIT License (MIT)

  Copyright (c) 2017 CheapskateProjects

  Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <ESP8266WiFi.h>
#include "AmazonIOTClient.h"
#include "ESP8266AWSImplementations.h"

Esp8266HttpClient httpClient;
Esp8266DateTimeProvider dateTimeProvider;

AmazonIOTClient iotClient;
ActionError actionError;

const char* ssid = "vijay";
const char* password = "23201994";



void setup() {
  Serial.begin(115200);
  delay(10);

  // Connect to WAP
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  iotClient.setAWSRegion("ap-south-1");
  iotClient.setAWSEndpoint("amazonaws.com");
  iotClient.setAWSDomain("a2n5n5amtiui59.iot.ap-south-1.amazonaws.com");
  iotClient.setAWSKeyID("AKIAJWVNYHMDNH5DQSZQ");
  iotClient.setAWSSecretKey("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");
  iotClient.setHttpClient(&httpClient);
  iotClient.setDateTimeProvider(&dateTimeProvider);
}

void loop(){
  char* shadow = "{\"state\":{\"reported\": {\"foobar\": \"bar\"}}}";

  char* result = iotClient.update_shadow(shadow, actionError);
  Serial.print(result);

  delay(60000);
}
