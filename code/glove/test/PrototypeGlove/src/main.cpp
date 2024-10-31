#include <Arduino.h>

#include <ResponsiveAnalogRead.h>
#include <esp_now.h>
#include <WiFi.h>

//#include <ESPNowW.h>
#include <HapticGlove_ESPNOW.h>

uint8_t receiver_mac[] = {0x3C, 0x84, 0x27, 0xE1, 0xC2, 0x30};//{0x3C, 0x84, 0x27, 0x14, 0x7B, 0xB0};

//define multiplexer input pins
#define S0 D3
#define S1 D4
#define S2 D5
#define S3 D6

#define SENSOR_COUNT 16

ResponsiveAnalogRead analog(A1, true);

int rawVals[SENSOR_COUNT];
int angles[SENSOR_COUNT];

int min_angles[SENSOR_COUNT];
int max_angles[SENSOR_COUNT];

String dataOut = "";

double polyVals[16][3] = {
  {-0.000050156739812,0.308087774294671,-325.54858934169279}, //pinkie 0
  {-0.000204869267408,1.180238586110067,-1522.071698458919325}, //pinkie 1
  {0.00009027900176,-0.57849114376526,925.953643298021097}, //pinkie 2
  {-0.000053897180763,0.344485903814262,-417.201492537313433}, //ring 3
  {-0.000406773372404,2.026886777162145,-2364.087785492362531}, //ring 4
  {0.000020669692875,-0.186416998438648,403.233727023548938}, //ring 5
  {-0.000041474654378,0.275529953917051,-295.161290322580645}, //middle 6
  {-0.000155663598998,0.846081469596033,-994.321241823930591}, //middle 7
  {0.000170233984067,-1.128460118194487,1768.951835332448657}, //middle 8
  {-0.000005288207298,0.121258593336859,-147.245901639344262}, //pointer 9
  {-0.000135942468348,0.817456387325188,-1033.093236601650843}, //pointer 10
  {0.000101643291297,-0.646716069346575,1031.971761445997989}, //pointer 11
  {-0.000087481431887,0.549306011516565,-709.440158534950912}, //thumb 12
  {0.000043188683603,-0.288631646308703,+518.26001946236131}, //thumb 13
  {0.000081944493116,-0.48715545187493,753.215310445897971}, //thumb 14
  {0.000029299702805,-0.235958663536102,473.892439373476074}  //thumb 15
};

double poly(double x, double a,double b,double c){
  return a*pow(x,2)+b*x+c;
}

void printRawVals() {
  for (uint8_t i = 0; i < SENSOR_COUNT; i++){
    Serial.print(">Joint_");
    Serial.print(i);
    Serial.print(":");
    Serial.println(rawVals[i]);
  }
}

void printAngles() {
  for (uint8_t i = 0; i < SENSOR_COUNT; i++){
    Serial.print(">Joint_");
    Serial.print(i);
    Serial.print(":");
    Serial.println(angles[i]);
  }
}

void printDataOut() {
  Serial.println(dataOut);
}

void measureAngles(){
  for (uint8_t i = 0; i < SENSOR_COUNT; i++){
    digitalWrite(S0, i&0b1);
    digitalWrite(S1, i>>1&0b1);
    digitalWrite(S2, i>>2&0b1);
    digitalWrite(S3, i>>3&0b1);

    delay(5); //not sure if this is necessary


    analog.update();
    int rawVal = analog.getRawValue();
    rawVals[i] = rawVal;
  }

  for (uint8_t i = 0; i < 16; i++){
    int angle = (int)poly(rawVals[i],polyVals[i][0],polyVals[i][1],polyVals[i][2]);
    angles[i] = angle;
    String angleStr = String(angle);
    if(angleStr.length()==1){
      dataOut += "00"+angleStr;
    }else if (angleStr.length()==2){
      dataOut += "0"+angleStr;
    }else{
      dataOut += angleStr;
    }
    if(i!=15){
      dataOut += " ";
    }
  }
}

void calibration(){
  for (uint8_t i = 0; i < SENSOR_COUNT; i++){
    if(angles[i]<min_angles[i]){
      min_angles[i] = angles[i];
    }else if(angles[i]>max_angles[i]){
      max_angles[i] = angles[i];
    }
  }
}

void adjustAngles(){
  for (uint8_t i = 0; i < SENSOR_COUNT; i++){

  }
}

void sendData(int finger_pos[]){
  uint8_t fpos[16];
  uint8_t wpos[3];
  uint8_t apos[3];
  for(int j=0; j<16; j++){
    fpos[j] = (uint8_t)finger_pos[j];
  }
  for(int j=0; j<3; j++){
    wpos[j] = random(1, 255);
    apos[j] = random(1, 255);
  }

  //position_packet.messages_rec = glove_messages_rcv;

  glove_sendData(fpos, wpos, apos);

  glove_messages_send_attempt += 1;
}

void initializeCalibrationValues(){
  for (uint8_t i = 0; i < SENSOR_COUNT; i++){
    min_angles[i] = -10000;
    max_angles[i] = 10000;
  }
}

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  //set the resolution to 12 bits (0-4096)
  analogReadResolution(12);

  pinMode(D2, OUTPUT);

  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);

  digitalWrite(D2, LOW);

  initializeCalibrationValues();

  glove_ESPNOWsetup(2);
}

void loop() {

  measureAngles();

  calibration();

  adjustAngles();

  //printRawVals();
  printAngles();
  // printDataOut();

  sendData(angles);

  delay(1000/DATA_RATE);

}

