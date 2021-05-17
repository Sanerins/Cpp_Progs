#ifndef INC_7_1_I2C_SLAVE_I2CSLAVECONTROLLER_H
#define INC_7_1_I2C_SLAVE_I2CSLAVECONTROLLER_H

#include <systemc.h>

SC_MODULE(I2CSlaveController)
{
  /*** INPUT SIGNALS: ***/
  sc_in<bool> scl;
  sc_in<bool> sda;
  /*** OUTPUT SIGNALS: ***/
  sc_out<sc_uint<8> > data;
  sc_out<bool> valid;
  sc_out<bool> sda_m;
  sc_out<bool> sda_o;
  /*** INTERNAL SIGNALS: ***/
  sc_signal<sc_uint<4> > count;
  sc_signal<sc_uint<8>> out;
  sc_signal<bool> nextScl;
  sc_signal<bool> validation;
  sc_signal<bool> isShowing;
  sc_signal<bool> isShowingRef;

  void combLogic();

  void writeByte();

  void validate();

  void startComb();

  void finish();

  SC_CTOR(I2CSlaveController)
  {
    SC_METHOD(writeByte);
    sensitive << scl.pos();
    SC_METHOD(validate);
    sensitive << scl.neg();
    SC_METHOD(startComb);
    sensitive << scl;
    SC_METHOD(finish);
    sensitive << sda.pos();
    SC_METHOD(combLogic);
    sensitive << nextScl << isShowing;
  }
};

#endif //INC_7_1_I2C_SLAVE_I2CSLAVECONTROLLER_H
