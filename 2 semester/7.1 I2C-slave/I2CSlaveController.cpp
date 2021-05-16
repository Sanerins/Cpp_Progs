#include "I2CSlaveController.h"

void I2CSlaveController::writeByte()// фронт scl
{
  if (count.read() == 11)
  {
    // комб. логика не сработает лишний раз, зато увидит, что надо вывести байт
    isShowingRef.write(!isShowing.read());
    count.write(2);// переходим к ожиданию сигнала начала передачи байта
  }
  else
  {
    if (count.read() == 2)
    {// если передается первый бит,
      // зададим соответствующее стартовое значение сигналу
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
      // запись в соответствующий бит значения с sda
      if (sda.read())
      {
        out.write(out.read() + (1 << (9 - count.read())));
      }
    }
    // «смотрим» на следующий бит
    count.write(count.read() + 1);
  }
}

void I2CSlaveController::validate()// спад scl
{
  if (count.read() == 10)
  {
    // если все биты записаны, выдаем подтверждение
    validation.write(1);
  }
  else
  {
    validation.write(0);
  }
}

void I2CSlaveController::startComb()// изменение scl
{
  // меняем nextScl
  nextScl.write(!scl.read());
}

void I2CSlaveController::finish()//фронт sda
{
  if (count.read() == 2)
  {
    // сработает если надо завершить вывод принятого байта
    isShowing.write(isShowingRef.read());
    // сработает комб. логика и выключит вывод принятого байта
  }
}

void I2CSlaveController::combLogic()
{
  if (scl.read())
  {// если на scl был фронт
    // выводим байт если надо
    if ((isShowing.read() != isShowingRef.read()))
    {
      data.write(out);
      valid.write(true);
    }
    else
    {
      // в случае необходимости заканчиваем вывод байта
      if (count.read() < 3)
      {
        data.write(0);
        valid.write(false);
      }
    }
  }
  else
  {// если же на scl был спад
    // подтверждаем прием если надо
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
