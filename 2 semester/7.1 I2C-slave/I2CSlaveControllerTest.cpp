#include "I2CSlaveControllerTest.h"

void I2CSlaveControllerTest::on_start()
{
  sc_uint<9> goal_byte = 274;
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
      scl.write(true);
    }
    if (count.read() == 10)
    {
      sda.write(true);
    }
    if (count.read() == 11)
    {
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
      count.write(count.read() + 1);
    }
    wait();
    if (count.read() == 9)
    {
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
      {
        std::cerr << "Error: Invalid sda_o at " << sc_time_stamp() << " (need 'z' got " << sda_o.read() << ")" << std::endl;
      }
    }
    wait(50, SC_NS);
    if (count.read() <= 8)
    {
      scl.write(false);
      sda.write(goal_byte[8 - count.read()]);
    }
    if (count.read() == 9)
    {
      scl.write(false);
      sda.write(false);
    }
    if (count.read() == 10)
    {
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
