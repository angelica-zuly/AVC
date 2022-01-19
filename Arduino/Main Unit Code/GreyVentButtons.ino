
//used to grey out the vent buttons
void GreyVentButtons(){

  //VENT 1
  tft.setCursor(40, 75);
  tft.setTextColor(GRAY);
  tft.setTextSize(3);
  tft.print("Open");
  tft.setCursor(150, 75);
  tft.setTextColor(GRAY);
  tft.setTextSize(3);
  tft.print("Closed");

  //VENT 2
  tft.setCursor(40, 130);
  tft.setTextColor(GRAY);
  tft.setTextSize(3);
  tft.print("Open");
  tft.setCursor(150, 130);
  tft.setTextColor(GRAY);
  tft.setTextSize(3);
  tft.print("Closed");

  //VENT 3
  tft.setCursor(40, 185);
  tft.setTextColor(GRAY);
  tft.setTextSize(3);
  tft.print("Open");
  tft.setCursor(150, 185);
  tft.setTextColor(GRAY);
  tft.setTextSize(3);
  tft.print("Closed");

  //VENT 4
  tft.setCursor(40, 240);
  tft.setTextColor(GRAY);
  tft.setTextSize(3);
  tft.print("Open");
  tft.setCursor(150, 240);
  tft.setTextColor(GRAY);
  tft.setTextSize(3);
  tft.print("Closed");
}
