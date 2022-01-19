
void CreateDataString(){

  //determine average climate
  avgTemp = (temp1 + temp3 + temp4 + temp5)/(total);
  avgHum = (hum1 + hum3 + hum4 + hum5)/(total); 

  //setting average climate strings to display on home screen
  AvgTemperatureString = String(avgTemp,1);
  AvgHumidityString = String(avgHum,1);

  databaseString = ""; //clearing the string  
  //saving float values as Strings to one decimal place (with ',' delimeter)
  databaseString =  String(temp1,1) + "," + 
                    String(temp2,1) + "," + 
                    String(temp3,1) +  "," +
                    String(temp4,1) +  "," +
                    String(temp5,1) +  "," +
                    String(hum1,1) +  "," +
                    String(hum2,1) +  "," +
                    String(hum3,1) +  "," +
                    String(hum4,1) +  "," +
                    String(hum5,1) +  "," +
                    AvgTemperatureString +  "," +
                    AvgHumidityString + "," + String(automation) + "," + vent1 + "," + vent2 + "," + vent3 + "," + vent4;
                     
}
