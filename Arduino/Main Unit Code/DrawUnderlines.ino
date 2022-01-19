
void DrawUnderlines() {
  if (toggleScreen == '0') {
    //UNDERLINE IN GRAY
    if (automation == 1) {
      //VENT 1
      if (vent1 == "1") {
        //button 1 (open)
        tft.drawFastHLine(40, 100, 70, GRAY);
        tft.drawFastHLine(150, 100, 105, BLACK);
      } else if (vent1 == "0") {
        //button 2 (close)
        tft.drawFastHLine(40, 100, 70, BLACK);
        tft.drawFastHLine(150, 100, 105, GRAY);
      }
      //VENT 2
      if (vent2 == "1") {
        //button 3 (open)
        tft.drawFastHLine(40, 155, 70, GRAY);
        tft.drawFastHLine(150, 155, 105, BLACK);
      } else if (vent2 == "0") {
        //button 4 (closed)
        tft.drawFastHLine(40, 155, 70, BLACK);
        tft.drawFastHLine(150, 155, 105, GRAY);
      }
      //VENT 3
      if (vent3 == "1") {
        //button 5 (open)
        tft.drawFastHLine(40, 210, 70, GRAY);
        tft.drawFastHLine(150, 210, 105, BLACK);
      } else if (vent3 == "0") {
        //button 6 (closed)
        tft.drawFastHLine(40, 210, 70, BLACK);
        tft.drawFastHLine(150, 210, 105, GRAY);
      }
      //VENT 4
      if (vent4 == "1") {
        //button 7 (open)
        tft.drawFastHLine(40, 265, 70, GRAY);
        tft.drawFastHLine(150, 265, 105, BLACK);
      } else if (vent4 == "0") {
        //button 8 (closed)
        tft.drawFastHLine(40, 265, 70, BLACK);
        tft.drawFastHLine(150, 265, 105, GRAY);
      }
    }

    //UNDERLINE IN WHITE
    else {
      //VENT 1
      if (vent1 == "1") {
        //button 1 (open)
        tft.drawFastHLine(40, 100, 70, WHITE);
        tft.drawFastHLine(150, 100, 105, BLACK);
      } else if (vent1 == "0") {
        //button 2 (close)
        tft.drawFastHLine(40, 100, 70, BLACK);
        tft.drawFastHLine(150, 100, 105, WHITE);
      }
      //VENT 2
      if (vent2 == "1") {
        //button 3 (open)
        tft.drawFastHLine(40, 155, 70, WHITE);
        tft.drawFastHLine(150, 155, 105, BLACK);
      } else if (vent2 == "0") {
        //button 4 (closed)
        tft.drawFastHLine(40, 155, 70, BLACK);
        tft.drawFastHLine(150, 155, 105, WHITE);
      }
      //VENT 3
      if (vent3 == "1") {
        //button 5 (open)
        tft.drawFastHLine(40, 210, 70, WHITE);
        tft.drawFastHLine(150, 210, 105, BLACK);
      } else if (vent3 == "0") {
        //button 6 (closed)
        tft.drawFastHLine(40, 210, 70, BLACK);
        tft.drawFastHLine(150, 210, 105, WHITE);
      }
      //VENT 4
      if (vent4 == "1") {
        //button 7 (open)
        tft.drawFastHLine(40, 265, 70, WHITE);
        tft.drawFastHLine(150, 265, 105, BLACK);
      } else if (vent4 == "0") {
        //button 8 (closed)
        tft.drawFastHLine(40, 265, 70, BLACK);
        tft.drawFastHLine(150, 265, 105, WHITE);
      }

    }
  }


}
