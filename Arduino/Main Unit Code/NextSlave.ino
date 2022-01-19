
void NextSlave() {
  //reset the current bt module
  digitalWrite(6, LOW);
  delay(500);
  digitalWrite(6, HIGH);
  delay(2000);

  //determine the current slave
  if (arrayIndex == ((sizeof(btModules)) / (sizeof(btModules[0]))) - 1) {
    //connected to the last module...

    //determine if AC is ON/OFF
    if (temp2 < avgTemp - 4.0) {
      //ac is turned on
      ACisOff = false;
      if (allVentsClosed == false) {
        //close all vents
        CloseAllVents();
        DrawUnderlines();
      }
    } else {
      ACisOff = true;
    }

    //save climate data in a long string with ',' delimeters
    CreateDataString();

    //Serial.print("SENDING: ");
    Serial.println(databaseString); //for display - delete later

    //send the climate data string to Wi-Fi Serial
    Serial2.print(databaseString);

    //Serial.println("loop is now restarting..."); //for display - delete later

    //reset index counter
    arrayIndex = 0;
    total = 4;

    //FOR UPDATING DISPLAY
    if (toggleScreen == '0') {
      //update data on home screen ONLY if on home screen
      UpdateHomeScreen();
    } else if (toggleScreen == '1') {
      //update data on information screen ONLY if on information screen
      UpdateInfoScreen();
    }

  } else {
    //not connected to last module - increment index
    arrayIndex++;
  }

  //grab the next slave in array
  currentBTmodule = btModules[arrayIndex];

  //disconnecting from last slave
  Serial1.write("AT+CLEAR\r\n");
  //Serial.println("AT+CLEAR");
  //Serial.println(" \n");

  //small delay
  delay(1000);

  //connecting to next slave bt module
  Serial1.write("AT+CON");
  Serial1.write(currentBTmodule);
  Serial1.write("\r\n");

  //Serial.print("AT+CON");
  //Serial.println(currentBTmodule);

  //small delay
  delay(2000);
}
