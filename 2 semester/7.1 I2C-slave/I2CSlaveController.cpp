#include "I2CSlaveController.h"

void I2CSlaveController::writeByte()// фронт scl
{
  if (count.read() == 11)
  {
    isShowingRef.write(!isShowing.read());
    count.write(2);
  }
  else
  {
    if (count.read() == 2)
    {
      if (sda.read())
      {
        out.write(128);
      }
      else
      {
        out.write(0);
      }
    }
    else
    {
      if (sda.read())
      {
        out.write(out.read() + (1 << (9 - count.read())));
      }
    }
    count.write(count.read() + 1);
  }
}

void I2CSlaveController::validate()// спад scl
{
  if (count.read() == 10)
  {
    validation.write(1);
  }
  else
  {
    validation.write(0);
  }
}

void I2CSlaveController::startComb()// изменение scl
{
  nextScl.write(!scl.read());
}

void I2CSlaveController::finish()//фронт sda
{
  if (count.read() == 2)
  {
    isShowing.write(isShowingRef.read());
  }
}

void I2CSlaveController::combLogic()
{
  if (scl.read())
  {
    if ((isShowing.read() != isShowingRef.read()))
    {
      data.write(out);
      valid.write(true);
    }
    else
    {
      if (count.read() < 3)
      {
        data.write(0);
        valid.write(false);
      }
    }
  }
  else
  {
    if (validation.read())
    {
      sda_m.write(true);
      sda_o.write(false);
    }
    else
    {
      sda_m.write(false);
      sda_o.write('Z');
    }
  }
}
