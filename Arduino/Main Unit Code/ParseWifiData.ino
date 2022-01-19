
void ParseWifiData(String trimmedResponce){

  //data indexes
  int index1, index2, index3, index4, index5, index6, index7, index8, index9;
  checkVent1 = false;
  checkVent2 = false;
  checkVent3 = false;
  checkVent4 = false;

  //storing vent 1 status
  index1 = trimmedResponce.indexOf(',');
  vent1 = trimmedResponce.substring(0, index1);

  //storing vent 2 status
  index2 = trimmedResponce.indexOf(',', index1 + 1);
  vent2 = trimmedResponce.substring(index1 + 1, index2);

  //storing vent 3 status
  index3 = trimmedResponce.indexOf(',', index2 + 1);
  vent3 = trimmedResponce.substring(index2 + 1, index3);

  //storing vent 4 status
  index4 = trimmedResponce.indexOf(',', index3 + 1);
  vent4 = trimmedResponce.substring(index3 + 1, index4);

  //storing outdoor temperature
  index5 = trimmedResponce.indexOf(',', index4 + 1);
  outdoorT = trimmedResponce.substring(index4 + 1, index5);

  //storing outdoor humidity
  index6 = trimmedResponce.indexOf(',', index5 + 1);
  outdoorH = trimmedResponce.substring(index5 + 1, index6);
  outdoorHumidity = outdoorH.toInt();

  //storing automation
  index7 = trimmedResponce.indexOf(',', index6 + 1);
  automationStat = trimmedResponce.substring(index6 + 1, index7);
  automation = automationStat.toInt();
  if(automation == 1){
    flag = false;
  }

  //storing idealTemp
  index8 = trimmedResponce.indexOf(',', index7 + 1);
  idealTemp = trimmedResponce.substring(index7 + 1, index7 + 3);  

  //storing updated flag
  index9 = trimmedResponce.indexOf(',', index8 + 1);
  updatedFlag = trimmedResponce.substring(index8 + 1, index9);
  updated = updatedFlag.toInt();

  if(toggleScreen == '0'){
    DrawHomeScreen();
  }else if (toggleScreen == '1'){
    UpdateInfoScreen();
  }
}
