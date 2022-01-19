void RestartLoop() {
  //reset the current bt module
  digitalWrite(6, LOW);
  delay(500);
  digitalWrite(6, HIGH);
  delay(800);

  Serial1.write("AT+RESET\r\n");
  Serial.println("RESET BUTTON PRESSED!");

  // reset index counter to the first module
  arrayIndex = 0;

  //grab the slave in array
  currentBTmodule = btModules[arrayIndex];

  delay(1000);

  //set a connection to the first BT module
  Serial1.write("AT+CON");
  Serial1.write(currentBTmodule);
  Serial1.write("\r\n");
  //Serial.print("AT+CON");
  //Serial.println(currentBTmodule);
}
