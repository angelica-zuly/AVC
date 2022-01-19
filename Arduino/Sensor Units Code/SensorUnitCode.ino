
#include<SoftwareSerial.h>
#include <DHT.h>

SoftwareSerial BTSerial(8, 9); // RX, TX
DHT dht = DHT(2, DHT22);  //DHTPIN, DHTTYPE

float temperature = 0.0;
float humidity = 0.0;
int counter = 0;

void setup() {
  
  // Begin serial communication at a baud rate of 9600:
  //Serial.begin(9600);
  BTSerial.begin(9600);//bluetooth module
  dht.begin();//temperature and humiity sensor
  
  //Serial.println("TESTING: SLAVE IS READY! ");

  //turning on the bt module
  pinMode(6, OUTPUT);
  digitalWrite(6, HIGH);
}

void loop() {  
  
 delay(1000);

 counter++;

 if(counter >= 10){
 
    //read and store values
    temperature = dht.readTemperature(true); 
    humidity = dht.readHumidity();

    //save in a string (i.g. "*75.1,55.3");
    String climateDataString = "*" + String(temperature,1) + "," + String(humidity,1);
    
    //send string to master module
    BTSerial.print(climateDataString);

    //reset counter
    counter = 0;
  }
      
  delay(1000); //small delay  
}
