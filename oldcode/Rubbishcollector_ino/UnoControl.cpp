/* 
	UnoControl.cpp - Class for controlling the robot on a high level on the Uno.
	Created by Jacky M. Lui 8 December 2015.
	Works within the BUDDY system
*/

#include "UnoControl.h"


void UnoControl::UnoControlsetup()
{
	Serial.begin(9600); // Begin the serial monitor at 9600bps
	Serial.println("serialMonitor is turned on");
  SerialTrans.begin(9600);
  SerialTrans.print("");
  SerialTransEleven.begin(9600);
  SerialTransEleven.print("");
	lightcount = 0; //start lightcount
  robspeed = 21; //remove later
  robdirection = 0; // remove later
  robspin = 0; //remove later
  // Set undefined range for Ultrasonics 
  SerialStart = OFF; //Switch for Serial Transmission to Nano   
  Downsensor = -1;
  ComputerCommand = 'G';
  ComputerStop = OFF;
  Danger_Flag = OFF;
  // int IRread[4];
  // for (int ii =0; ii < 4; ii++) IRread[ii] = -1;
}	

void UnoControl::Interface()
{
  SerialNano();
  if (Danger_Flag == OFF)
  {
    SensorUno();
    Navigation(); 
  } 
  //DangerScenarios();
  Light(SET);
}

void UnoControl::SerialNano()
{
    ComputerRead();
    while (ComputerStop == SET) 
    {
      ComputerRead();
      if (ComputerCommand == 'G')
        {
          Light(SET);
          ComputerStop = OFF; // Turns Robot back on
          Serial.print("Start Motion");   
        }
    }
    if (ComputerCommand == 'F' | ComputerStop == SET) // Turns off motors and Light
      {
        ComputerStop = SET; //Keeps Robot off until detects 'G'
        robspeed = 0;
        robdirection = 0;
        robspin = 0;
        Light(OFF);
        Serial.print("Stop Motion");
      }
    // Convert rob values to string
    String srobspeed = String(robspeed);
    String srobdirection = String(robdirection);
    String srobspin = String(robspin);
    String senddata = "S";
    // Serial.print("Speed: ");
    // Serial.print(srobspeed);
    // Serial.print("direction ");
    // Serial.print(srobdirection);
    // Serial.print("spin: ");
    Serial.println(srobspin);
    senddata.concat(robspeed);
    senddata.concat(" ");
    senddata.concat(robdirection);
    senddata.concat(" ");
    senddata.concat(robspin);
    senddata.concat(" ");
    senddata.concat("E");    
    for(int ii = 0; ii < senddata.length(); ii++)
    {
      SerialTrans.println(senddata[ii]);
      delay(10); 
    }
}

void UnoControl::SensorUno()
{
  SensorCon.SensorsSetup();
  SensorCon.UltrasonicCon();
  UltrasonicReturn = SensorCon.UltrasonicOutputs();
  Rightsensor = int(UltrasonicReturn[0]);
  Backsensor = int(UltrasonicReturn[1]);
  Leftsensor = int(UltrasonicReturn[2]);
  Frontsensor = int(UltrasonicReturn[3]);
  Downsensor = int(UltrasonicReturn[4]);

  
//  for (int ii =0; ii < 4; ii++) IRread[ii] = -1;
//  IRread = SensorCon.IR_Beacon();
//   Serial.print("US Right: ");
//   Serial.println(Rightsensor);
//   Serial.print("US Back: ");
//   Serial.println(Backsensor);
//   Serial.print("US Left: ");
//   Serial.println(Leftsensor);
//   Serial.print("US Front: ");
//   Serial.println(Frontsensor);
//   Serial.print("US Down: ");
//   Serial.println(Downsensor); 
//
//   Serial.print("IR_F: ");
//   Serial.println(IRread[0]);
//   Serial.print("IR_R: ");
//   Serial.println(IRread[1]);
//   Serial.print("IR_B: ");
//   Serial.println(IRread[2]);
//   Serial.print("IR_L: ");
//   Serial.println(IRread[3]); 
}

void UnoControl::SerialEleven()
{

}

void UnoControl::Light(int l_switch) // this function makes sure the light doesn't turn on when everything else is turning on
{
  if (l_switch == SET) digitalWrite(13, HIGH);
  if (l_switch == OFF) digitalWrite(13, LOW);
}

void UnoControl::ComputerRead() // Reads input from Computer and allows robot to be turned on and off
{
    if (Serial.available() > OFF)
    {
      ComputerCommand = Serial.read();
    }
}

void UnoControl::DangerScenarios() // This function moves robot out of dangerous situations
{
  Serial.println("");
  Serial.print("DangerScenarios");
  Serial.println("");
  prevrobspeed = robspeed;
  prevrobdirection = robdirection;
  prevrobspin = robspin;
  // Danger Detect 
  if (Downsensor > 30 && Danger_Flag == OFF) // Danger of Falling
  {
    Serial.println("");
    Serial.println("Flee! Going to Fall!");
    Serial.println("Reverse Direction");
    Serial.println("");
    robspeed = prevrobspeed; //remove later
    if (prevrobdirection >= 180) robdirection = prevrobdirection - 180;
    else robdirection = prevrobdirection + 180; 
    Danger_Flag = SET;
  }
  else if (Downsensor < 17 && Danger_Flag == OFF) // Danger of Falling in
  {
    Serial.println("");
    Serial.println("Flee! Going to Get Stuck!");
    Serial.println("Reverse Direction");
    Serial.println("");
    robspeed = prevrobspeed; //remove later
    if (prevrobdirection >= 180) robdirection = prevrobdirection - 180;
    else robdirection = prevrobdirection + 180; 
    Danger_Flag = SET;
  }
  else if (Danger_Flag == DEBOUNCE) // Debounce
  {
    delay(200); //Debounce milliseconds
    Serial.println("Debounce");
    Danger_Flag = OFF;     
  } 
  else 
   {      
     Serial.println("BAU"); // Business as usual
     Serial.println("");
     robspeed = prevrobspeed; //remove later
     robdirection = prevrobdirection; // remove robdirection = BAUdirection + 180; // remove later
     robspin = prevrobspin; //remove later
     if (Danger_Flag == SET)
     {
        Danger_Flag = DEBOUNCE; // Debounce 
      }
    }
}

void UnoControl::Navigation()
{  
  // Implement Vector Fields
  Serial.println("");
  Serial.print("VectorFields");
  Serial.println("");
  prevrobspeed = robspeed;
  prevrobdirection = robdirection;
  prevrobspin = robspin;  
  
  // Vector Fields values
  // only calculate vector fields if sensors read less than 1m
  if (Rightsensor < 100 || Leftsensor < 100 || Frontsensor < 100 || Backsensor < 100)
  {
      // Scale Everything to 1m
      if (Rightsensor > 100) Rightsensor = 100;
      if (Leftsensor > 100) Leftsensor = 100;
      if (Frontsensor > 100) Frontsensor = 100;
      if (Backsensor > 100) Backsensor = 100;
      // Calculate direction of field
      xdirection = Rightsensor - Leftsensor;
      ydirection = Frontsensor - Backsensor;

      Serial.print("US Right: ");
      Serial.println(Rightsensor);
      Serial.print("US Back: ");
      Serial.println(Backsensor);
      Serial.print("US Left: ");
      Serial.println(Leftsensor);
      Serial.print("US Front: ");
      Serial.println(Frontsensor);
      Serial.print("US Down: ");
      Serial.println(Downsensor);  


      // Convert this into an angle, make sure atan2 does not equal infinity
      if (xdirection == 0)
      {
        if (ydirection > 0) robdirection = 180;
        if (ydirection < 0) robdirection = -180;
        else robdirection = prevrobdirection;
      }
      else
      {
        robdirection = atan2((double)ydirection,(double)xdirection); 

 
        //Convert to degrees
        robdirection = robdirection * 180/PI;
        Serial.print("    robirection now ");
        Serial.println(robdirection); 
        int bufferdirection = robdirection; // used so that robdirection won't be confused in if statements.
        // Convert to Angular Space of Robot
        if (bufferdirection < 90 && bufferdirection >= 0) robdirection = 90-robdirection; 
        if (bufferdirection <= 180 && bufferdirection >= 90) robdirection = 360 - (robdirection - 90);
        if (bufferdirection < 0 && bufferdirection >= -180) robdirection = -robdirection + 90;
        
        if (robdirection == 360) robdirection = 0;
      }
        robspeed = 21;
      robspin = (int)robdirection;
      
    Serial.print("Speed: ");
    Serial.print(robspeed);
    Serial.print(" Direction: ");
    Serial.print(robdirection);
    SerialTransEleven.println("hello is it me you're looking for?");
    SerialTransEleven.println(robdirection);
    Serial.print(" Spin: ");
    Serial.println(robspin);
  }

}    




