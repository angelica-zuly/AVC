bool heatPocket = false;

void AutomationLogic() {

  //convert all values here to floats!!!
  float outdoorTemperature = outdoorT.toFloat();

  if (outdoorHumidity < 90) {
    //assume its not raining and vents are not all already closed
    //check that not all vents are opened...

    //open all vents if indoor average is hotter than outdoor AND  any sensor is hotter than ideal by 3 degrees - letting some heat out
    if ( (avgTemp > outdoorTemperature) && ((avgTemp > idealTemperature + 2.0) ||
                                            ((temp1 > idealTemperature + 3.0) || (temp3 > idealTemperature + 3.0) ||
                                             (temp4 > idealTemperature + 3.0) || (temp5 > idealTemperature + 3.0)) )  ) {
      heatPocket = true;
      if (allVentsOpened == false) {
        //open all vents (make a stop trigger)
        OpenAllVents();
        DrawUnderlines();
      }

    } else {
      heatPocket = false;
    }

    if ((avgTemp <= idealTemperature) && (heatPocket == false)) {
      if (allVentsClosed == false) {
        //close all vents
        CloseAllVents();
        DrawUnderlines();
      }
    }

  } else {
    //assume its raining and all vents should be closed
    if (allVentsClosed == false) {
      //make sure vents are closed if rain is detected
      CloseAllVents();
    }
  }

}
