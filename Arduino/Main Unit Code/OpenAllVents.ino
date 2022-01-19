
void OpenAllVents() {
  //open relays for vent 1
  digitalWrite(30, LOW);
  digitalWrite(33, LOW);
  digitalWrite(31, HIGH);
  digitalWrite(32, HIGH);
  vent1 = "1";
  delay(1000);

  //open relays for vent 2
  digitalWrite(34, LOW);
  digitalWrite(37, LOW);
  digitalWrite(35, HIGH);
  digitalWrite(36, HIGH);
  vent2 = "1";
  delay(1000);

  //open relays for vent 3
  digitalWrite(38, LOW);
  digitalWrite(41, LOW);
  digitalWrite(39, HIGH);
  digitalWrite(40, HIGH);
  vent3 = "1";
  delay(1000);

  //open relays for vent 4
  digitalWrite(42, LOW);
  digitalWrite(45, LOW);
  digitalWrite(43, HIGH);
  digitalWrite(44, HIGH);
  vent4 = "1";
  
  //let time pass to allow vents to open close
  delay(40000);

  //turn off relays
  PowerOffRelays();

  allVentsOpened = true;
  allVentsClosed = false;
  
}
