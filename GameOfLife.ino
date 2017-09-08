#include "LedControl.h"

struct Frame
{
  byte columns[8];

  Frame(){
    memset(columns, 0x00, 8);
  }
  
  void SetPixel(int x, int y)
  {
    columns[y] = columns[y] | (B10000000 >> x);
  }
};

/*
This implementation uses a single MAX72XX with a 8x8 LED dot matrix.
pin 12 is connected to the DataIn 
pin 11 is connected to LOAD(CS)
pin 10 is connected to the CLK 
*/
LedControl lc=LedControl(12,10,11,1);

void setup() {
  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */ 
  lc.shutdown(0,false);

  /* Set the brightness to a medium values */
  lc.setIntensity(0,8);

  /* and clear the display */
  lc.clearDisplay(0);
}

void setDisplay(Frame & frame) {
  lc.setRow(0,0,frame.columns[0]);
  lc.setRow(0,1,frame.columns[1]);
  lc.setRow(0,2,frame.columns[2]);
  lc.setRow(0,3,frame.columns[3]);
  lc.setRow(0,4,frame.columns[4]);
  lc.setRow(0,5,frame.columns[5]);
  lc.setRow(0,6,frame.columns[6]);
  lc.setRow(0,7,frame.columns[7]);
}

void loop() {
  for(int x = 0; x < 8; x++){
    for(int y = 0; y < 8; y++){
      Frame frame;
      frame.SetPixel(x, y);
      setDisplay(frame);
      delay(100);
    }
  }
}

