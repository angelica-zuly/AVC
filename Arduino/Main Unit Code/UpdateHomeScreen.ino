void UpdateHomeScreen() {

  //Outdoor Circle Data
  tft.fillCircle(360, 130, 90, BLACK);
  tft.drawCircle(360, 130, 90, WHITE);
  tft.setCursor(300, 80);
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.print("Outdoor");
  tft.setCursor(325, 110);
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.print(outdoorT);
  tft.print(char(248)); //degree symbol
  tft.setCursor(290, 145);
  tft.setTextSize(2);
  tft.print("Humidity:");
  tft.print(outdoorH);
  tft.print("%"); 
  
  //Indoor Circle Data
  tft.fillCircle(385, 265, 95, BLACK);
  tft.drawCircle(385, 265, 95, WHITE);
  tft.setCursor(330, 198);
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.print("Indoor");
  tft.setCursor(335, 235);
  tft.setTextColor(WHITE);
  tft.setTextSize(4);
  tft.print(AvgTemperatureString);
  tft.print(char(248)); //degree symbol
  tft.setCursor(300, 275);
  tft.setTextSize(2);
  tft.print("Humidity:");
  tft.print(AvgHumidityString);
  tft.print("%");

  //FORMATTING: Redraw Information Circle
  tft.fillCircle(440, 40, 35, BLACK);
  tft.drawCircle(440, 40, 35, WHITE);
  tft.setCursor(430, 22);
  tft.setTextColor(WHITE);
  tft.setTextSize(5);
  tft.print("i");

  if( (automation == 1) && (toggleScreen == '0') ){
    //disable vent buttons during automation
    GreyVentButtons();    
  }
  
  DrawUnderlines();

  //FORMATTING: Redraw Border
  tft.drawRect(0, 0, 480, 320, BLUE); //border
}
