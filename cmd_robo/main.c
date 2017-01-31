#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "robosapien.h"

static int i_VerboseFlag;
static int i_RightArmUp;
static int i_RightArmOut;
static int i_TiltBodyRight;
static int i_RightArmDown;
static int i_RightArmIn;
static int i_LeftArmUp;
static int i_LeftArmOut;
static int i_TiltBodyLeft;
static int i_LeftArmDown;
static int i_LeftArmIn;
static int i_TurnRight; 
static int i_TurnLeft;   
static int i_WalkForward;
static int i_WalkBackward;
static int i_StopMoving; 

static int i_RightTurnStep;    
static int i_RightHandThump;   
static int i_RightHandThrow;   
static int i_Sleep;            
static int i_RightHandPickup;  
static int i_LeanBackward;     
static int i_ForwardStep;      
static int i_BackwardStep;     
static int i_LeftTurnStep;     
static int i_LeftHandThump;    
static int i_LeftHandThrow;    
static int i_Listen;           
static int i_LeftHandPickup;   
static int i_LeanForward;      
static int i_Reset;            
static int i_MasterExecute;    
static int i_Wakeup;           
static int i_RightExecute;     
static int i_LeftExecute;      
static int i_SonicExecute;     
static int i_RightHandStrike_3;
static int i_RightHandSweep;   
static int i_Burp;
static int i_RightHandStrike_2;
static int i_High;             
static int i_RightHandStrike_1;
static int i_Bulldozer;        
static int i_Oops             ;
static int i_LeftHandStrike_3 ;
static int i_LeftHandSweep   ;
static int i_Whistle          ;
static int i_LeftHandStrike_2 ;
static int i_Talkback         ;
static int i_LeftHandStrike_1 ;
static int i_Roar             ;
static int i_AllDemo          ;
static int i_PowerOff         ;
static int i_DemoKarate       ;
static int i_DemoRude         ;
static int i_Dance            ;
 
static enRoboCmd en_GetCmd(int i_Flag);

int main (int argc, char * const argv[])
{
#define SET_CMD(cmd) if (cmd){ if (i_VerboseFlag) pc_Verbose = (const char*)#cmd; en_Cmd = en_GetCmd(cmd); }

  int i_Opt = 0;
  const char* pc_Verbose = NULL;
  enRoboCmd en_Cmd = none;

  while(i_Opt >= 0)
  {
    int i_OptionIndex = 0;
    
    static struct option st_LongOptions[] =
    {
      /* These options set a flag. */
      {"verbose"            , no_argument, &i_VerboseFlag      ,   1 },
      {"brief"              , no_argument, &i_VerboseFlag      ,   0 },
      {"right-arm-up"       , no_argument, &i_RightArmUp       ,   1 },
      {"right-arm-out"      , no_argument, &i_RightArmOut      ,   1 },
      {"tilt-body-right"    , no_argument, &i_TiltBodyRight    ,   1 },
      {"right-arm-down"     , no_argument, &i_RightArmDown     ,   1 },
      {"right-arm-in"       , no_argument, &i_RightArmIn       ,   1 },
      {"left-arm-up"        , no_argument, &i_LeftArmUp        ,   1 },
      {"left-arm-out"       , no_argument, &i_LeftArmOut       ,   1 },
      {"tilt-body-left"     , no_argument, &i_TiltBodyLeft     ,   1 },
      {"left-arm-down"      , no_argument, &i_LeftArmDown      ,   1 },
      {"left-arm-in"        , no_argument, &i_LeftArmIn        ,   1 },
                                                               
      {"bulldozer"          , no_argument, &i_Bulldozer        ,   1 },
      {"demo-karate"        , no_argument, &i_DemoKarate       ,   1 },
      {"demo-rude"          , no_argument, &i_DemoRude         ,   1 },
 
      {"right-hand-strike-1", no_argument, &i_RightHandStrike_1,   1 },
      {"right-hand-strike-2", no_argument, &i_RightHandStrike_2,   1 },
      {"right-hand-strike-3", no_argument, &i_RightHandStrike_3,   1 },

      {"left-hand-strike-1" , no_argument, &i_LeftHandStrike_1 ,   1 },
      {"left-hand-strike-2" , no_argument, &i_LeftHandStrike_2 ,   1 },
      {"left-hand-strike-3" , no_argument, &i_LeftHandStrike_3 ,   1 },

      {"right-hand-throw"   , no_argument, &i_RightHandThrow   ,   1 },
      {"right-hand-thump"   , no_argument, &i_RightHandThump   ,   1 },

      {"left-hand-throw"    , no_argument, &i_LeftHandThrow    ,   1 },
      {"left-hand-thump"    , no_argument, &i_LeftHandThump    ,   1 },
                            
      {"turn-right"         , no_argument, &i_TurnRight        , 'r' },
      {"turn-left"          , no_argument, &i_TurnLeft         , 'l' },
      {"walk-forward"       , no_argument, &i_WalkForward      , 'f' },
      {"walk-backward"      , no_argument, &i_WalkBackward     , 'b' },
      {"stop-moving"        , no_argument, &i_StopMoving       , 's' },
                            
      {"poweroff"           , no_argument, &i_PowerOff         ,   1 },
      {"wakeup"             , no_argument, &i_Wakeup           ,   1 },
      {"reset"              , no_argument, &i_Reset            ,   1 },
      
      
      {                     0,          0,               0 ,   0 }
    };
  
    i_Opt = getopt_long (argc, argv, "rlfbs",
                            st_LongOptions, &i_OptionIndex);
    
    if (i_Opt == -1)
      break;
    
    switch(i_Opt)
    {
      case 'r':
        i_TurnRight = 1;
        break;
      case 'l':
        i_TurnLeft = 1;
        break;
      case 'f':
        i_WalkForward = 1;
        break;
      case 'b':
        i_WalkBackward = 1;
        break;
      case 's':
        i_StopMoving = 1;
        break;
      case '?':
        /* getopt_long already printed an error message. */
        break;
      default:
        break;
    }
    
  }// while

  robosapien_iInit();  

  SET_CMD(i_VerboseFlag);
  SET_CMD(i_RightArmUp);
  SET_CMD(i_RightArmOut);
  SET_CMD(i_TiltBodyRight);
  SET_CMD(i_RightArmDown);
  SET_CMD(i_RightArmIn);
  SET_CMD(i_LeftArmUp);
  SET_CMD(i_LeftArmOut);
  SET_CMD(i_TiltBodyLeft);
  SET_CMD(i_LeftArmDown);
  SET_CMD(i_LeftArmIn);
  SET_CMD(i_TurnRight); 
  SET_CMD(i_TurnLeft);   
  SET_CMD(i_WalkForward);
  SET_CMD(i_WalkBackward);
  SET_CMD(i_StopMoving); 
  
  SET_CMD(i_Bulldozer); 
  SET_CMD(i_DemoKarate); 
  SET_CMD(i_DemoRude); 

  SET_CMD(i_RightHandStrike_1); 
  SET_CMD(i_RightHandStrike_2); 
  SET_CMD(i_RightHandStrike_3); 
 
  SET_CMD(i_LeftHandStrike_1); 
  SET_CMD(i_LeftHandStrike_2); 
  SET_CMD(i_LeftHandStrike_3); 
 
  SET_CMD(i_RightHandThrow); 
  SET_CMD(i_RightHandThump); 
  
  SET_CMD(i_LeftHandThrow); 
  SET_CMD(i_LeftHandThump); 
  
  SET_CMD(i_PowerOff);
  SET_CMD(i_Wakeup);  
  SET_CMD(i_Reset);  

  if (i_VerboseFlag)
    printf("cmd: %s, 0x%02X\n", pc_Verbose, en_Cmd);
  
  robosapien_iSendCmd(en_Cmd);

  return 0 ;
}


static enRoboCmd en_GetCmd(int i_Flag)
{
  if (i_Flag == i_RightArmUp)        return RightArmUp;  
  if (i_Flag == i_RightArmOut)       return RightArmOut;
  if (i_Flag == i_TiltBodyRight)     return TiltBodyRight;
  if (i_Flag == i_RightArmDown)      return RightArmDown;
  if (i_Flag == i_RightArmIn)        return RightArmIn;
  if (i_Flag == i_LeftArmUp)         return LeftArmUp;
  if (i_Flag == i_LeftArmOut)        return LeftArmOut;
  if (i_Flag == i_TiltBodyLeft)      return TiltBodyLeft;
  if (i_Flag == i_LeftArmDown)       return LeftArmDown;
  if (i_Flag == i_LeftArmIn)         return LeftArmIn;
  if (i_Flag == i_TurnRight)         return TurnRight; 
  if (i_Flag == i_TurnLeft)          return TurnLeft;   
  if (i_Flag == i_WalkForward)       return WalkForward;
  if (i_Flag == i_WalkBackward)      return WalkBackward;
  if (i_Flag == i_StopMoving)        return StopMoving;
                                     
  if (i_Flag == i_Bulldozer)         return Bulldozer;
  if (i_Flag == i_DemoKarate)        return DemoKarate;
  if (i_Flag == i_DemoRude)          return DemoRude;
 
  if (i_Flag == i_RightHandStrike_1) return RightHandStrike_1;
  if (i_Flag == i_RightHandStrike_2) return RightHandStrike_2;
  if (i_Flag == i_RightHandStrike_3) return RightHandStrike_3;

  if (i_Flag == i_LeftHandStrike_1)  return LeftHandStrike_1;
  if (i_Flag == i_LeftHandStrike_2)  return LeftHandStrike_2;
  if (i_Flag == i_LeftHandStrike_3)  return LeftHandStrike_3;
                                     
  if (i_Flag == i_RightHandThrow)    return RightHandThrow;
  if (i_Flag == i_RightHandThump)    return RightHandThump;
                                     
  if (i_Flag == i_LeftHandThrow)     return LeftHandThrow;
  if (i_Flag == i_LeftHandThump)     return LeftHandThump;
                                     
  if (i_Flag == i_Wakeup)            return Wakeup;
  if (i_Flag == i_PowerOff)          return PowerOff;
  if (i_Flag == i_Reset)             return Reset;
 
  
}  