
void AssignModuleToZero() {

  //assign 0 to the module skipped module
  switch (arrayIndex) {
    //determine the current slave module
    case 0:
      //connected to BT1
      temp1 = 0.0;
      hum1 = 0.0;
      total--;
      break;
    case 1:
      //connected to BT2
      temp2 = 0.0;
      hum2 = 0.0;
      total--;
      break;
    case 2:
      //connected to BT3
      temp3 = 0.0;
      hum3 = 0.0;
      total--;
      break;
    case 3:
      //connected to BT4
      temp4 = 0.0;
      hum4 = 0.0;
      total--;
      break;
    case 4:
      //connected to BT5
      temp5 = 0.0;
      hum5 = 0.0;
      total--;
      break;
  }

}
