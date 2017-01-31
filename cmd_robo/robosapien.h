#ifndef ROBOSAPIEN_H
#define ROBOSAPIEN_H

typedef enum 
{
  none               = 0x0,
  // only a very small subset of commands
  TurnRight          = 0x80,
  RightArmUp         = 0x81,
  RightArmOut        = 0x82,
  TiltBodyRight      = 0x83,
  RightArmDown       = 0x84,
  RightArmIn         = 0x85,
  WalkForward        = 0x86,
  WalkBackward       = 0x87,
  TurnLeft           = 0x88,
  LeftArmUp          = 0x89,
  LeftArmOut         = 0x8A,
  TiltBodyLeft       = 0x8B,
  LeftArmDown        = 0x8C,
  LeftArmIn          = 0x8D,
  StopMoving         = 0x8E,
    
  RightTurnStep      = 0xA0,
  RightHandThump     = 0xA1,
  RightHandThrow     = 0xA2,
  Sleep              = 0xA3,
  RightHandPickup    = 0xA4,
  LeanBackward       = 0xA5,
  ForwardStep        = 0xA6,
  BackwardStep       = 0xA7,
  LeftTurnStep       = 0xA8,
  LeftHandThump      = 0xA9,
  LeftHandThrow      = 0xAA,
  Listen             = 0xAB,
  LeftHandPickup     = 0xAC,
  LeanForward        = 0xAD,
  Reset              = 0xAE,
  
  MasterExecute      = 0xB0, // (master command program execute) 
  Wakeup             = 0xB1, 
  RightExecute       = 0xB2, // (right sensor program execute) 
  LeftExecute        = 0xB3, //(left sensor program execute) 
  SonicExecute       = 0xB4, // (sonic sensor program execute) 
 
  RightHandStrike_3  = 0xC0,
  RightHandSweep     = 0xC1,
  Burp               = 0xC2,
  RightHandStrike_2  = 0xC3,
  High               = 0xC4,
  RightHandStrike_1  = 0xC5,
  Bulldozer          = 0xC6,
  Oops               = 0xC7,
  LeftHandStrike_3   = 0xC8,
  LeftHandSweep      = 0xC9,
  Whistle            = 0xCA,
  LeftHandStrike_2   = 0xCB,
  Talkback           = 0xCC,
  LeftHandStrike_1   = 0xCD,
  Roar               = 0xCE,
  AllDemo            = 0xD0,
  PowerOff           = 0xD1, // (drop snow-globe and say "Rosebud")
  DemoKarate         = 0xD2,
  DemoRude           = 0xD3,
  Dance              = 0xD4,
  
}enRoboCmd;

int robosapien_iInit();
int robosapien_iSendCmd(enRoboCmd enCmd);

#endif