#include <wiringPi.h>

#include "robosapien.h"
#include "robosapien_cfg.h"

/*
 * ***************************************************************************
 * PROTOTYPES
 * ***************************************************************************
 */
static int i_DelayTimeSlices(int i_Slices);

/*
 * ***************************************************************************
 * GLOBAL FUNCTIONS
 * ***************************************************************************
 */

/*!
 * \brief Init the Pins of Rasberry
 */

int robosapien_iInit()
{
  int i_Pin = RASPBERRY_WRITE_IR_PIN;

  wiringPiSetup () ;
  pinMode (i_Pin, OUTPUT) ;
  digitalWrite (i_Pin, HIGH); 
}

/*!
 * \brief Write out the command
 */

int robosapien_iSendCmd(enRoboCmd enCmd)
{
  int i_Pin = RASPBERRY_WRITE_IR_PIN;
  

  // Initial Low
  digitalWrite (i_Pin,  LOW); 
  i_DelayTimeSlices(8);
  
  for(int i_Bit = 7; i_Bit>=0; i_Bit--) 
  {
    digitalWrite(i_Pin, HIGH);
    i_DelayTimeSlices((enCmd & 1<<i_Bit) ? 4 : 1 );
    digitalWrite(i_Pin, LOW);
    i_DelayTimeSlices(1);
  }

  digitalWrite(i_Pin, HIGH);
  
  pinMode (i_Pin, INPUT) ;
}

/*
 * ***************************************************************************
 * STATIC FUNCTIONS
 * ***************************************************************************
 */


/*!
 * \brief Time slice delay
 */

static int i_DelayTimeSlices(int i_Slices)
{
  delayMicroseconds(TIME_SLICE_DELAY * i_Slices);
}
