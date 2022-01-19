
//determines what vent button was selected
void TriggerVentButtons(TSPoint p) {

  //TRIGGERED VENT 1
  if (p.x > 35 && p.x < 115 && p.y > 215 && p.y < 250) {
    //Open
    ventTrigger = true;
    currentTimeForCounter = 0;
    //setting string status to open
    vent1 = "1";
    //open relays for vent 1
    digitalWrite(30, LOW);
    digitalWrite(33, LOW);
    digitalWrite(31, HIGH);
    digitalWrite(32, HIGH);
    allVentsClosed = false;
  } else if (p.x > 145 && p.x < 260 && p.y > 215 && p.y < 250) {
    //Closed
    ventTrigger = true;
    currentTimeForCounter = 0;
    //setting string status to closed
    vent1 = "0";
    //close relays for vent 1
    digitalWrite(30, HIGH);
    digitalWrite(33, HIGH);
    digitalWrite(31, LOW);
    digitalWrite(32, LOW);
    allVentsOpened = false;
  }

  //TRIGGERED VENT 2
  else if (p.x > 35 && p.x < 115 && p.y > 160 && p.y < 195) {
    //Open
    ventTrigger = true;
    currentTimeForCounter = 0;
    //setting string status to open
    vent2 = "1";
    //open relays for vent 2
    digitalWrite(34, LOW);
    digitalWrite(37, LOW);
    digitalWrite(35, HIGH);
    digitalWrite(36, HIGH);
    allVentsClosed = false;
  } else if (p.x > 145 && p.x < 260 && p.y > 160 && p.y < 195) {
    //Closed
    ventTrigger = true;
    currentTimeForCounter = 0;
    //setting string status to closed
    vent2 = "0";
    //close relays for vent 2
    digitalWrite(34, HIGH);
    digitalWrite(37, HIGH);
    digitalWrite(35, LOW);
    digitalWrite(36, LOW);
    allVentsOpened = false;
  }

  //TRIGGERED VENT 3
  else if (p.x > 35 && p.x < 115 && p.y > 105 && p.y < 140) {
    //Open
    ventTrigger = true;
    currentTimeForCounter = 0;
    //setting string status to open
    vent3 = "1";
    //open relays for vent 3
    digitalWrite(38, LOW);
    digitalWrite(41, LOW);
    digitalWrite(39, HIGH);
    digitalWrite(40, HIGH);
    allVentsClosed = false;
  } else if (p.x > 145 && p.x < 260 && p.y > 105 && p.y < 140) {
    //Closed
    ventTrigger = true;
    currentTimeForCounter = 0;
    //setting string status to closed
    vent3 = "0";
    //close relays for vent 3
    digitalWrite(38, HIGH);
    digitalWrite(41, HIGH);
    digitalWrite(39, LOW);
    digitalWrite(40, LOW);
    allVentsOpened = false;
  }

  //TRIGGERED VENT 4
  else if (p.x > 35 && p.x < 115 && p.y > 50 && p.y < 85) {
    //Open
    ventTrigger = true;
    currentTimeForCounter = 0;
    //setting string status to open
    vent4 = "1";
    //open relays for vent 4
    digitalWrite(42, LOW);
    digitalWrite(45, LOW);
    digitalWrite(43, HIGH);
    digitalWrite(44, HIGH);
    allVentsClosed = false;
  } else if (p.x > 145 && p.x < 260 && p.y > 50 && p.y < 85) {
    //Closed
    ventTrigger = true;
    currentTimeForCounter = 0;
    //setting string status to closed
    vent4 = "0";
    //close relays for vent 4
    digitalWrite(42, HIGH);
    digitalWrite(45, HIGH);
    digitalWrite(43, LOW);
    digitalWrite(44, LOW);
    allVentsOpened = false;
  }
  
}
