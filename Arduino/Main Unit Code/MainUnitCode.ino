
//libraries for sensor
#include <Adafruit_Sensor.h>
//libraries for display
#include <Adafruit_TFTLCD.h>
#include <Adafruit_GFX.h>
#include <TouchScreen.h>

///////////////////////////////////////////////////////////////////////////////

#define MINPRESSURE 10
#define MAXPRESSURE 1000

#define TS_MINX 150
#define TS_MINY 120
#define TS_MAXX 920
#define TS_MAXY 940

#define LCD_CS A3
#define LCD_CD A2
#define LCD_WR A1
#define LCD_RD A0
#define LCD_RESET 40 //optional

Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);

//NOTE: WIRING IS DIFFERENT FROM THE CODE!
#define YP A6   // A5
#define XM A5   // A6
#define YM A4   // A7
#define XP A7   // A4

TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

// 16-bit color values:
#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
#define GRAY    0x73AE

#define bt_power 6
#define wifi_power 7

///////////////////////////////////////////////////////////////////////////////

char* btModules[] = {"F8300238517C",
                     "B0B11367103B",
                     "F8300238563E",
                     "F830023767D5",
                     "F83002376255"
                    };
int arrayIndex = 0;
char* currentBTmodule = btModules[arrayIndex];

char toggleScreen = '0';
int buttonPushed = 0; //(0-8)
int currentTimeForCounter;

//variables for temporarily holding data
String databaseString = "";
String AvgTemperatureString = "";
String AvgHumidityString = "";
float temp1, temp2, temp3, temp4, temp5, hum1, hum2, hum3, hum4, hum5, avgTemp, avgHum;

//vent status: "0"=closed, "1"=open
String vent1 = "0";
String vent2 = "0";
String vent3 = "0";
String vent4 = "0";

//data strings from wifi
String outdoorT, outdoorH, automationStat, idealTemp;
String updatedFlag;
int updated = 0;
float idealTemperature = 0.0;
int outdoorHumidity = 0;

//variables for vent automation and timers
bool ventTrigger = false;
int automation = 1;
unsigned long lastMillis;
bool flag = false;
bool allVentsClosed;
bool allVentsOpened;

bool checkVent1 = false;
bool checkVent2 = false;
bool checkVent3 = false;
bool checkVent4 = false;

//assume AC is ON at startup
bool ACisOff = false;

int connectionCounter = 0;
int total = 4;

///////////////////////////////////////////////////////////////////////////////

void setup() {

  pinMode(bt_power, OUTPUT);
  digitalWrite(bt_power, HIGH); // power on the bt
  pinMode(wifi_power, OUTPUT);
  digitalWrite(wifi_power, HIGH); // power on the wifi

  //relay module #1
  pinMode(30, OUTPUT);
  pinMode(31, OUTPUT);
  pinMode(32, OUTPUT);
  pinMode(33, OUTPUT);

  //relay module #2
  pinMode(34, OUTPUT);
  pinMode(35, OUTPUT);
  pinMode(36, OUTPUT);
  pinMode(37, OUTPUT);

  //relay module #3
  pinMode(38, OUTPUT);
  pinMode(39, OUTPUT);
  pinMode(40, OUTPUT);
  pinMode(41, OUTPUT);

  //relay module #4
  pinMode(42, OUTPUT);
  pinMode(43, OUTPUT);
  pinMode(44, OUTPUT);
  pinMode(45, OUTPUT);

  //make sure vents are closed at startup
  CloseAllVents();
  allVentsClosed = true;
  allVentsOpened = false;

  // Begin serial communication
  Serial.begin(9600);
  Serial1.begin(9600); //for bluetooth
  Serial2.begin(115200); //for wifi

  // HX8357D LCD driver
  uint16_t identifier  = 0x8357;

  //initialization
  tft.reset();
  tft.begin(identifier);
  tft.setRotation(1);

  // Display Home Screen at start
  DrawHomeScreen();

  //TODO: move to loop()
  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);

  //CONFIGURE MASTER BT MODULE
  //Serial.println("\nTESTING: MASTER IS READY! ");
  delay(1000);
  Serial1.write("AT+IMME1\r\n");
  //Serial.println("AT+IMME1");

  delay(1000);
  Serial1.write("AT+ROLE1\r\n");
  //Serial.println("AT+ROLE1");

  delay(1000);
  Serial1.write("AT+RESET\r\n");
  //Serial.println("AT+RESET");

  delay(1000);

  //set a connection to the first BT module
  Serial1.write("AT+CON");
  Serial1.write(currentBTmodule);
  Serial1.write("\r\n");
  //Serial.print("AT+CON");
  //Serial.println(currentBTmodule);

  delay(1000);
}
///////////////////////////////////////////////////////////////////////////////

void loop() {

  //TASK #1 - check response from bt module
  CheckBtResponse();

  //TASK #2 - read from DB
  if (Serial2.available() > 0) {
    //format being sent over: data with * tag
    String trimmedResponce = Serial2.readString();
    //Serial.print("RESPONCE: ");
    //Serial.println(trimmedResponce);
    //save and update data recieved by wifi module
    ParseWifiData(trimmedResponce);
  }

  //TASK #3 - check vent automation
  idealTemperature = idealTemp.toFloat();
  if (idealTemperature > 0.0) {
    //ideal temperature has been set in database
    if ((automation == 1) && (ACisOff)) {
      AutomationLogic();
    } else {
      //open/close vents if they have been updated on website
      CheckVents();      
    }
  }

  //TASK #4 - check touch screen
  CheckTouchScreen();
    
  //this makes sure that overrides lasts 3 hours
  OverrideTimer();

  if (ventTrigger == true) {
    //Give a 25 second cycle time
    VentCycleTime();
  }

}
