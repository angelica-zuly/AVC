
void CheckTouchScreen() {
  //saving point touched on screen
  TSPoint p = ts.getPoint();

  //DISPLAYING HOME SCREEN
  if (toggleScreen == '0') {
    if (p.z > MINPRESSURE && p.z < MAXPRESSURE) {
      //determine what button was selected
      p.x = map(p.x, TS_MINY, TS_MAXY, tft.width(), 0);
      p.y = map(p.y, TS_MINX, TS_MAXX, tft.height(), 0);

      if (automation == 0) {
        //vent buttons are enabled (automation off)
        TriggerVentButtons(p);
        DrawUnderlines();
      }
      
      //Pressed top right, info button
      if (p.x > 410 && p.x < 470 && p.y > 250 && p.y < 310) {
        toggleScreen = '1';
        buttonPushed = 0;
        DrawInfoScreen(); //change to info screen
      }
    }
  }

  //DISPLAYING INFORMATION SCREEN
  else if (toggleScreen == '1') {
    if (p.z > MINPRESSURE && p.z < MAXPRESSURE) {
      //determine what button was selected
      p.x = map(p.x, TS_MINY, TS_MAXY, tft.width(), 0);
      p.y = map(p.y, TS_MINX, TS_MAXX, tft.height(), 0);

      //pressed top-left, back button
      if (p.x > 10 && p.x < 90 && p.y > 230 && p.y < 310) {
        toggleScreen = '0';
        DrawHomeScreen(); //back to main screen
      }

      //pressed ON - set automation = 1 (on)
      if (p.x > 305 && p.x < 365 && p.y > 240 && p.y < 290) {
        automation = 1;
        tft.drawFastHLine(320, 65, 35, WHITE);
        tft.drawFastHLine(410, 65, 50, BLACK);
      }

      //pressed OFF - set automation = 0 (off)
      if (p.x > 390 && p.x < 460 && p.y > 240 && p.y < 290) {
        automation = 0;
        tft.drawFastHLine(410, 65, 50, WHITE);
        tft.drawFastHLine(320, 65, 35, BLACK);
      }

      //pressed "RESET" button
      if (p.x > 310 && p.x < 445 && p.y > 145 && p.y < 195) {        
        DrawHomeScreen();
        toggleScreen = '0';
        RestartLoop();        
      }
    }
  }

}
