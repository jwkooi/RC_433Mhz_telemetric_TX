void loop() {

  //** BMP180
  int32_t b5;

  b5 = temperature();         // Read and calculate temperature (T) b5 is not the temperature
  P = pressure(b5);           // Read and calculate pressure (P)


  //** HC12 EasyTranfer

  //this is how you access the variables. [name of the group].[variable name]
  rcData.battery = analogRead(batteryPin);
  rcData.temperature = T;
  rcData.pressure = P;


//  Serial.println (rcData.battery);
//  Serial.println (rcData.temperature);
//  Serial.println (rcData.pressure);


  //send the data
  ET.sendData();

  delay(100);  // Delay between each readout for BPM180

}
