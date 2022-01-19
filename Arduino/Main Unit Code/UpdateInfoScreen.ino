
void UpdateInfoScreen(){
  
  //refresh background
  tft.fillRect(0, 221, 480, 99, BLACK);
  //refresh border 
  tft.drawRect(0, 0, 480, 320, BLUE);

  //data for ideal temperature
  tft.fillRect(90, 155, 90, 30, BLACK); //TODO
  tft.setCursor(100, 155);
  tft.setTextSize(4);
  tft.print(idealTemp);
  tft.print(char(248)); //degree symbol
   
  //data for Sensor Unit 1
  tft.setCursor(30, 245);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print(temp1,1);
  tft.print(char(248)); //degree symbol
  tft.setCursor(30, 285);
  tft.print(hum1,1);
  tft.print("%");
  
  //data for Sensor Unit 2
  tft.setCursor(120, 245);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print(temp2,1);
  tft.print(char(248)); //degree symbol
  tft.setCursor(120, 285);
  tft.print(hum2,1);
  tft.print("%");
  
  //data for Sensor Unit 3
  tft.setCursor(210, 245);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print(temp3,1);
  tft.print(char(248)); //degree symbol
  tft.setCursor(210, 285);
  tft.print(hum3,1);
  tft.print("%");

  //data for Sensor Unit 4
  tft.setCursor(300, 245);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print(temp4,1);
  tft.print(char(248)); //degree symbol
  tft.setCursor(300, 285);
  tft.print(hum4,1);
  tft.print("%");
  
  //data for Sensor Unit 5
  tft.setCursor(390, 245);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print(temp5,1);
  tft.print(char(248)); //degree symbol
  tft.setCursor(390, 285);
  tft.print(hum5,1);
  tft.print("%");

}
