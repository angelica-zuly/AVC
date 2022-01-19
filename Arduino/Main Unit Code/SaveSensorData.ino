
 //method to set values for each sensor unit
void SaveSensorData(String response) { 

  //storing index of delimiters
  int starIndex  = response.indexOf("*");
  int commaIndex  = response.indexOf(",");

  //saving values
  String temperature = response.substring(starIndex + 1, commaIndex);
  String humidity = response.substring(commaIndex + 1);

  switch (arrayIndex) {
    //determine the current slave module
    case 0:
      //connected to BT1
      temp1 = temperature.toFloat();
      temp1 = temp1 - 2.0;
      hum1 = humidity.toFloat();
      break;
    case 1:
      //connected to BT2 (located near AC)
      temp2 = temperature.toFloat();
      temp2 = temp2 - 2.0;
      hum2 = humidity.toFloat();
      break;
    case 2:
      //connected to BT3 
      temp3 = temperature.toFloat();
      temp3 = temp3 - 2.0;
      hum3 = humidity.toFloat();
      break;
    case 3:
      //connected to BT4
      temp4 = temperature.toFloat();
      temp4 = temp4 - 2.0;
      hum4 = humidity.toFloat();
      break;
    case 4:
      //connected to BT5
      temp5 = temperature.toFloat();
      temp5 = temp5 - 2.0;
      hum5 = humidity.toFloat();
      break;
  }

  //update data on information screen ONLY if on information screen
  if (toggleScreen == '1') {    
    UpdateInfoScreen();
  }
  
  //Serial.println(temperature);
  //Serial.println(humidity);
  //Serial.println();
}
