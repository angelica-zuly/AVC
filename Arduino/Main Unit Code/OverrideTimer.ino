
void OverrideTimer(){
  
  //assumes automation has been turned off
  if( (automation==0) && (flag==false) ){
    //trigger 1 hour timer
    lastMillis = millis();
    flag = true;
  }

  //assumes 3 hours has passed since trigger
  if(flag && (millis()-lastMillis >= 3600L * 3000) ){    
    //turn automation back on
    automation = 1;
    //reset flag
    flag = false;
    //redraw home screen
    DrawHomeScreen();
    //close vents once override time is done
    CloseAllVents();
    allVentsClosed = true;
    allVentsOpened = false;     
  }

  
}
