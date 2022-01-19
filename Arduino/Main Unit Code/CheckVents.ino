
void CheckVents() {
  //determines if vents should be opened or closed

  if (updated == 1) {
    
    //VENT 1
    if ( (vent1 == "1") && (checkVent1 == false) ) {
      //Open
      ventTrigger = true;
      currentTimeForCounter = 0;
      //open relays for vent 1
      digitalWrite(30, LOW);
      digitalWrite(33, LOW);
      digitalWrite(31, HIGH);
      digitalWrite(32, HIGH);
      checkVent1 = true;
      allVentsClosed = false;
    } else if ((vent1 == "0") && (checkVent1 == false) ) {
      //Closed
      ventTrigger = true;
      currentTimeForCounter = 0;
      //close relays for vent 1
      digitalWrite(30, HIGH);
      digitalWrite(33, HIGH);
      digitalWrite(31, LOW);
      digitalWrite(32, LOW);
      checkVent1 = true;
      allVentsOpened = false;
    }

    //VENT 2
    if ((vent2 == "1") && (checkVent2 == false) ) {
      //Open
      ventTrigger = true;
      currentTimeForCounter = 0;
      //open relays for vent 2
      digitalWrite(34, LOW);
      digitalWrite(37, LOW);
      digitalWrite(35, HIGH);
      digitalWrite(36, HIGH);
      checkVent2 = true;
      allVentsClosed = false;
    } else if ((vent2 == "0") && (checkVent2 == false)) {
      //Closed
      ventTrigger = true;
      currentTimeForCounter = 0;
      //setting string status to closed
      digitalWrite(34, HIGH);
      digitalWrite(37, HIGH);
      digitalWrite(35, LOW);
      digitalWrite(36, LOW);
      checkVent2 = true;
      allVentsOpened = false;
    }

    //VENT 3
    if ((vent3 == "1") && (checkVent3 == false)) {
      //Open
      ventTrigger = true;
      currentTimeForCounter = 0;
      //open relays for vent 3
      digitalWrite(38, LOW);
      digitalWrite(41, LOW);
      digitalWrite(39, HIGH);
      digitalWrite(40, HIGH);
      checkVent3 = true;
      allVentsClosed = false;
    } else if ((vent3 == "0") && (checkVent3 == false)) {
      //Closed
      ventTrigger = true;
      currentTimeForCounter = 0;
      //setting string status to closed
      digitalWrite(38, HIGH);
      digitalWrite(41, HIGH);
      digitalWrite(39, LOW);
      digitalWrite(40, LOW);
      checkVent3 = true;
      allVentsOpened = false;
    }

    //VENT 4
    if ((vent4 == "1") && (checkVent4 == false)) {
      //Open
      ventTrigger = true;
      currentTimeForCounter = 0;
      //open relays for vent 4
      digitalWrite(42, LOW);
      digitalWrite(45, LOW);
      digitalWrite(43, HIGH);
      digitalWrite(44, HIGH);
      checkVent4 = true;
      allVentsClosed = false;
    } else if ((vent4 == "0") && (checkVent4 == false)) {
      //Closed
      ventTrigger = true;
      currentTimeForCounter = 0;
      //close relays for vent 4
      digitalWrite(42, HIGH);
      digitalWrite(45, HIGH);
      digitalWrite(43, LOW);
      digitalWrite(44, LOW);
      checkVent4 = true;
      allVentsOpened = false;
    }

  }

}
