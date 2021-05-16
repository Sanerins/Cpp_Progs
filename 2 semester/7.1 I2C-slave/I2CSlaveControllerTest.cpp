#include "I2CSlaveControllerTest.h"

void I2CSlaveControllerTest::on_start()
{
  sc_uint<9> goal_byte = 132;// goal_byte всегда в 2 раза больше, чем нужно передать
  count.write(15);
  reset.write(true);
  scl.write(true);
  sda.write(true);
  wait(50, SC_NS);
  sda.write(false);
  wait(50, SC_NS);
  scl.write(false);
  wait(50, SC_NS);
  reset.write(false);
  wait(50, SC_NS);
  while (1)
  {
    if (count.read() <= 9)
    {
      // подача фронтов при передаче байта или установка в единицу после него
      scl.write(true);
    }
    if (count.read() == 10)
    {
      // установка в единицу после передачи байта
      sda.write(true);
    }
    if (count.read() == 11)
    {
      // сигнал к передаче нового байта
      sda.write(false);
      count.write(0);
      goal_byte += 6;
      if (goal_byte > 512)
      {
        goal_byte -= 504;
      }
    }
    else
    {
      // переход к следующему биту
      count.write(count.read() + 1);
    }
    wait();
    if (count.read() == 9)
    {// проверка подтвержления приема
      if (sda_m.read() != 1)
      {
        std::cerr << "Error: Invalid sda_m at " << sc_time_stamp() << " (need 1 got " << sda_m.read() << ")" << std::endl;
      }
      if (sda_o.read() != 0)
      {
        std::cerr << "Error: Invalid sda_o at " << sc_time_stamp() << " (need 0 got " << sda_o.read() << ")" << std::endl;
      }
    }
    else
    {
      if (sda_m.read() != 0)
      {
        std::cerr << "Error: Invalid sda_m at " << sc_time_stamp() << " (need 0 got " << sda_m.read() << ")" << std::endl;
      }
      if (sda_o.read() != 1)
      {//'z') {
        std::cerr << "Error: Invalid sda_o at " << sc_time_stamp() << " (need 'z' got " << sda_o.read() << ")" << std::endl;
      }
    }
    wait(50, SC_NS);
    if (count.read() <= 8)
    {
      scl.write(false);// подача спадов на scl
      sda.write(goal_byte[8 - count.read()]);// и подача нужного бита на sda
    }
    if (count.read() == 9)
    {
      // во время получения подтверждения все обнуляем
      scl.write(false);
      sda.write(false);
    }
    if (count.read() == 10)
    {// проверка выведенного байта
      if (data.read() != goal_byte / 2)
      {
        std::cerr << "Error: Invalid data at " << sc_time_stamp() << " (need " << goal_byte / 2 << " got " << data.read() << ")"
                  << std::endl;
      }
      if (valid.read() != 1)
      {
        std::cerr << "Error: Invalid valid at " << sc_time_stamp() << " (need 1 got " << valid.read() << ")" << std::endl;
      }
    }
    else
    {
      if (data.read() != 0)
      {
        std::cerr << "Error: Invalid data at " << sc_time_stamp() << " (need 'z' got " << data.read() << ")" << std::endl;
      }
      if (valid.read() != 0)
      {
        std::cerr << "Error: Invalid valid at " << sc_time_stamp() << " (need 0 got " << valid.read() << ")" << std::endl;
      }
    }
    wait(50, SC_NS);
  }
}
