void DrawHomeScreen() {

  tft.fillScreen(BLACK);

  /////////////////////////////////[VENTILATION CIRCLE]///////////////////////////////////////
  tft.drawCircle(120, 160, 180, WHITE);
  tft.setCursor(20, 20);
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.print("Ventilation");

  /////////////////////////////////[VENT 1]//////////////////////////////////////////
  tft.setCursor(10, 75);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print("1");

  tft.setCursor(40, 75);
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.print("Open");
  //tft.drawRect(35, 70, 80, 35, YELLOW); //button

  tft.setCursor(150, 75);
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.print("Closed");
  //tft.drawRect(145, 70, 115, 35, YELLOW); //button

  /////////////////////////////////[VENT 2]//////////////////////////////////////////
  tft.setCursor(10, 130);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print("2");

  tft.setCursor(40, 130);
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.print("Open");
  //tft.drawRect(35, 125, 80, 35, YELLOW); //button

  tft.setCursor(150, 130);
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.print("Closed");
  //tft.drawRect(145, 125, 115, 35, YELLOW); //button

  /////////////////////////////////[VENT 3]//////////////////////////////////////////
  tft.setCursor(10, 185);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print("3");

  tft.setCursor(40, 185);
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.print("Open");
  //tft.drawRect(35, 180, 80, 35, YELLOW); //button

  tft.setCursor(150, 185);
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.print("Closed");
  //tft.drawRect(145, 180, 115, 35, YELLOW); //button

  /////////////////////////////////[VENT 4]//////////////////////////////////////////
  tft.setCursor(10, 240);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print("4");

  tft.setCursor(40, 240);
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.print("Open");
  //tft.drawRect(35, 235, 80, 35, YELLOW); //button

  tft.setCursor(150, 240);
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.print("Closed");
  //tft.drawRect(145, 235, 115, 35, YELLOW); //button

  /////////////////////////////////[OUTDOOR CIRCLE]///////////////////////////////////////

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

  /////////////////////////////////[INDOOR CIRCLE]///////////////////////////////////////

  tft.fillCircle(385, 265, 95, BLACK);
  tft.drawCircle(385, 265, 95, WHITE);
  tft.setCursor(330, 203);
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
  
  /////////////////////////////////[INFO CIRCLE]///////////////////////////////////////

  tft.fillCircle(440, 40, 35, BLACK);
  tft.drawCircle(440, 40, 35, WHITE);
  tft.setCursor(430, 22);
  tft.setTextColor(WHITE);
  tft.setTextSize(5);
  tft.print("i");
  //tft.drawRect(410, 10, 60, 60, YELLOW); //button

  /////////////////////////////////////////////////////////////////////////////////////  
  
  if(automation == 1){
    //disable vent buttons during automation
    GreyVentButtons();
  }

  DrawUnderlines();

  tft.drawRect(0, 0, 480, 320, BLUE); //border
  
}
