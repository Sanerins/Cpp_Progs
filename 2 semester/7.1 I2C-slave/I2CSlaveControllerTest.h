#ifndef INC_7_1_I2C_SLAVE_I2CSLAVECONTROLLERTEST_H
#define INC_7_1_I2C_SLAVE_I2CSLAVECONTROLLERTEST_H

#include <iostream>
#include <systemc.h>

SC_MODULE(I2CSlaveControllerTest)
{
  /*** INPUT SIGNALS: ***/
  sc_in<bool> clk;
  sc_in<sc_uint<8> > data;
  sc_in<bool> valid;
  sc_in<bool> sda_m;
  sc_in<bool> sda_o;
  /*** OUTPUT SIGNALS: ***/
  sc_out<bool> reset;
  sc_out<bool> scl;
  sc_out<bool> sda;
  /*** INTERNAL SIGNALS: ***/
  sc_signal<sc_uint<4> > count;

  void on_start();

  SC_CTOR(I2CSlaveControllerTest)
  {
    SC_THREAD(on_start);
    sensitive << clk;
  }
};

#endif //INC_7_1_I2C_SLAVE_I2CSLAVECONTROLLERTEST_H
