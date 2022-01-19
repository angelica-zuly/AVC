
void VentCycleTime() {
  //Serial.print("currentTimeForCounter = ");
  //Serial.println(currentTimeForCounter);
  //start 25 second counter
  if (currentTimeForCounter >= 32000) {
      //turn off all relays
      PowerOffRelays();
      ventTrigger = false;
      currentTimeForCounter = 0;
  }
  currentTimeForCounter++;

}
