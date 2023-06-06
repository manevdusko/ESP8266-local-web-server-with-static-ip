#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "webpageCode.h";
//------------------------------------------
ESP8266WebServer server(80);
const char* ssid = "";
const char* password = "";
//------------------------------------------
void webpage()
{
  server.send(200,"text/html", webpageCode);
}
//=================================================================
void setup()
{
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  IPAddress l(192, 168, 0, 199);
  IPAddress g(192, 168, 0, 1);
  IPAddress s(255, 255, 255, 0);
  while(!WiFi.config(l, g, s)){delay(500);Serial.print(".");}
  WiFi.mode(WIFI_STA);
  while(WiFi.status()!=WL_CONNECTED){delay(500);Serial.print(".");}
  Serial.println();
  Serial.print("IP Address: "); Serial.println(WiFi.localIP());

  server.on("/", webpage);
  server.begin();
}
//=================================================================
void loop()
{
  server.handleClient();
}
