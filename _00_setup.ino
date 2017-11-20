//**setup

void setup() {
  Serial.begin(9600);

  Wire.begin();                             // Activate I2C for BMP180

  init_SENSOR();                            // Initialize baro sensor variables
  delay(100);


  //*** HC-12
  pinMode(4, OUTPUT);

  hc12Serial.begin(9600);


  // setup of the hc12 module
  digitalWrite(4, LOW);                   // enter AT command mode
  hc12Serial.print(F("AT+DEFAULT\r\n"));  // 9600, CH1, FU3, (F) to bypass flash memory
  delay(100);
  digitalWrite (4, HIGH);                   // enter transparent mode



  //*** EasyTransfer
  // start the library, pass in the data details and the name of the serial port.
  // Can be Serial, Serial1, Serial2, etc.
  ET.begin(details(rcData), &hc12Serial);

}

