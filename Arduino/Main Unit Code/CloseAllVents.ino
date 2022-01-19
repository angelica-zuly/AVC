
void CloseAllVents() {

  //close relays for vent 1
  digitalWrite(30, HIGH);
  digitalWrite(33, HIGH);
  digitalWrite(31, LOW);
  digitalWrite(32, LOW);
  vent1 = "0";
  delay(1000);

  //close relays for vent 2
  digitalWrite(34, HIGH);
  digitalWrite(37, HIGH);
  digitalWrite(35, LOW);
  digitalWrite(36, LOW);
  vent2 = "0";
  delay(1000);

  //close relays for vent 3
  digitalWrite(38, HIGH);
  digitalWrite(41, HIGH);
  digitalWrite(39, LOW);
  digitalWrite(40, LOW);
  vent3 = "0";
  delay(1000);

  //close relays for vent 4
  digitalWrite(42, HIGH);
  digitalWrite(45, HIGH);
  digitalWrite(43, LOW);
  digitalWrite(44, LOW);
  vent4 = "0";

  //let time pass to allow vents to fully close
  delay(40000);

  //turn off relays
  PowerOffRelays();
  
  allVentsClosed = true;
  allVentsOpened = false;

}
