
#include <ESP8266WiFi.h>
#include <WiFiClient.h>

const char* ssid     = "RAR_5G";
const char* password = "TEAM2556";

//Domain name and URL path
const char* serverName = "ventcontroller.herokuapp.com";
int portNumber = 80;

//data strings
String temp1, temp2, temp3, temp4, temp5, hum1, hum2, hum3, hum4, hum5, avgTemp, avgHum, automation, vent1, vent2, vent3, vent4;
String trimmedResponce;

//data indexes
int index1, index2, index3, index4, index5, index6, index7, index8, index9, index10, index11, index12, index13, index14, index15, index16, index17;

WiFiClient client;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password); //network name and pw to network

  //Serial.println("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    //Serial.print(".");
  }
  //Serial.println("");
  //Serial.print("Connected to WiFi network with IP Address: ");
  //Serial.println(WiFi.localIP());
  delay(1000);
}


void loop() {

  if (Serial.available() > 0) {

    //store data string that has been sent from master unit to wi-fi module
    String recievedString = Serial.readString();

    //storing temp1
    index1 = recievedString.indexOf(',');
    temp1 = recievedString.substring(0, index1);

    //storing temp2
    index2 = recievedString.indexOf(',', index1 + 1);
    temp2 = recievedString.substring(index1 + 1, index2);

    //storing temp3
    index3 = recievedString.indexOf(',', index2 + 1);
    temp3 = recievedString.substring(index2 + 1, index3);

    //storing temp4
    index4 = recievedString.indexOf(',', index3 + 1);
    temp4 = recievedString.substring(index3 + 1, index4);

    //storing temp5
    index5 = recievedString.indexOf(',', index4 + 1);
    temp5 = recievedString.substring(index4 + 1, index5);

    //storing hum1
    index6 = recievedString.indexOf(',', index5 + 1);
    hum1 = recievedString.substring(index5 + 1, index6);

    //storing hum2
    index7 = recievedString.indexOf(',', index6 + 1);
    hum2 = recievedString.substring(index6 + 1, index7);

    //storing hum3
    index8 = recievedString.indexOf(',', index7 + 1);
    hum3 = recievedString.substring(index7 + 1, index8);

    //storing hum4
    index9 = recievedString.indexOf(',', index8 + 1);
    hum4 = recievedString.substring(index8 + 1, index9);

    //storing hum5
    index10 = recievedString.indexOf(',', index9 + 1);
    hum5 = recievedString.substring(index9 + 1, index10);

    //storing average temperature
    index11 = recievedString.indexOf(',', index10 + 1);
    avgTemp = recievedString.substring(index10 + 1, index11);

    //storing average humidity
    index12 = recievedString.indexOf(',', index11 + 1);
    avgHum = recievedString.substring(index11 + 1, index12);

    //storing automation status
    index13 = recievedString.indexOf(',', index12 + 1);
    automation = recievedString.substring(index12 + 1, index13);

    //storing vent1 status
    index14 = recievedString.indexOf(',', index13 + 1);
    vent1 = recievedString.substring(index13 + 1, index14);

    //storing vent2 status
    index15 = recievedString.indexOf(',', index14 + 1);
    vent2 = recievedString.substring(index14 + 1, index15);

    //storing vent3 status
    index16 = recievedString.indexOf(',', index15 + 1);
    vent3 = recievedString.substring(index15 + 1, index16);

    //storing vent4 status
    index17 = recievedString.indexOf(',', index16 + 1);
    vent4 = recievedString.substring(index16 + 1, index17);

    //Check WiFi connection status
    if (WiFi.status() == WL_CONNECTED) {

      // Preparing HTTP POST request data string
      String httpRequestData = "temp1=" + temp1
                               + "&temp2=" + temp2
                               + "&temp3=" + temp3
                               + "&temp4=" + temp4
                               + "&temp5=" + temp5
                               + "&hum1=" + hum1
                               + "&hum2=" + hum2
                               + "&hum3=" + hum3
                               + "&hum4=" + hum4
                               + "&hum5=" + hum5
                               + "&avgTemp=" + avgTemp
                               + "&avgHum=" + avgHum
                               + "&automation=" + automation
                               + "&vent1=" + vent1
                               + "&vent2=" + vent2
                               + "&vent3=" + vent3
                               + "&vent4=" + vent4 + "";

      //Serial.println(httpRequestData);

      //SEND DATA STRING TO PHP
      if (client.connect(serverName, portNumber)) {
        client.println("POST /test.php HTTP/1.1");
        client.println("Host: ventcontroller.herokuapp.com");
        client.println("Content-Type: application/x-www-form-urlencoded");
        client.print("Content-Length: ");
        client.println(httpRequestData.length());
        client.println();
        client.print(httpRequestData);

        //AND THEN READ DATA FROM PHP
        //Serial.println("=====");
        String clientResponce = client.readString(); 
        int starIndex = clientResponce.indexOf('*');
        if ( (clientResponce.length() > 0) && (starIndex >= 0) ) {
          trimmedResponce = clientResponce.substring(starIndex+1);
          //tag found - display "$climateDataString"
          Serial.println(trimmedResponce);
        }
                     
      }

    }
  }
} //end of loop
