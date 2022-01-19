
void CheckBtResponse() {
  
  if (Serial1.available() > 0) {
    //determine what is being recived from bt
    
    String response  = "";
    response = Serial1.readString();

    if (response.indexOf('*') >= 0) {
      connectionCounter = 0;
      //response is climate data
      //Serial.print("Recived Data From Module: ");
      //Serial.println(arrayIndex+1);
      //save received data from SLAVE (set temp and hum values)
      SaveSensorData(response);
      //turn module off/on, grab next module, clear, connect to next bt module
      NextSlave();
    } else {
      connectionCounter++;
      //send connection command again...
      Serial1.write("AT+CON");
      Serial1.write(currentBTmodule);
      Serial1.write("\r\n");
    }

    //skipping bt module
    if (connectionCounter == 20) {
      AssignModuleToZero();
      NextSlave(); //now move on to the next module
    }
        
  }

}
