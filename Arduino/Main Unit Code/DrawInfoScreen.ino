void DrawInfoScreen() {
  
  tft.fillScreen(BLACK);

  //back button (top-left)
  //tft.drawRect(10, 10, 80, 80, YELLOW); //touch for BACK button
  tft.drawCircle(50, 50, 40, WHITE);
  tft.setCursor(32, 32);
  tft.setTextColor(WHITE);
  tft.setTextSize(5);
  tft.print("<");  

  //automation string
  tft.setCursor(105, 40);
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.print("Automation: ");

  //tft.drawRect(300, 30, 60, 50, YELLOW); //touch for ON button
  tft.setCursor(320, 40);
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.print("ON");
  //tft.drawRect(400, 30, 70, 50, YELLOW); //touch for OFF button
  tft.setCursor(410, 40);
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.print("OFF");

  //determine which button to underline
  if(automation == 1){
    //automation on
    tft.drawFastHLine(320, 65, 35, WHITE);
    tft.drawFastHLine(410, 65, 50, BLACK);
  }else{
    //automation off
    tft.drawFastHLine(410, 65, 50, WHITE); 
    tft.drawFastHLine(320, 65, 35, BLACK);
  } 
 
  //ideal temperature string (set in website only)
  tft.setCursor(30, 120);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print("Ideal Temperature:");
  tft.setCursor(100, 155);
  tft.setTextSize(4);
  tft.print(idealTemp);
  tft.print(char(248)); //degree symbol
  
  //reset button (still need to program the button, redirect to home screen)
  tft.drawRect(310, 125, 135, 50, WHITE); //box for reset button
  tft.setCursor(320, 135);
  tft.setTextColor(WHITE);
  tft.setTextSize(4);
  tft.print("RESET");
  //blue horizontal line across screen
  tft.drawFastHLine(0, 220, 480, BLUE);

  //draw info for each sensor unit
  UpdateInfoScreen();
  
  tft.drawRect(0, 0, 480, 320, BLUE); //border

}
