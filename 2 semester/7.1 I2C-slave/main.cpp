#include <systemc.h>
#include "I2CSlaveController.h"
#include "I2CSlaveControllerTest.h"

int sc_main(int argc, char *argv[])
{
  I2CSlaveController slave("slave");
  I2CSlaveControllerTest slave_test("slave_test");
  sc_clock s_clk("clk", 10, SC_NS);
  sc_signal<bool> s_reset("reset");
  sc_signal<sc_uint<8> > s_data("data");
  sc_signal<bool> s_valid("valid");
  sc_signal<bool> s_scl("scl");
  sc_signal<bool> s_sda("sda");
  sc_signal<bool> s_sda_m("sda_m");
  sc_signal<bool> s_sda_o("sda_o");

  slave.data(s_data);
  slave.valid(s_valid);
  slave.scl(s_scl);
  slave.sda(s_sda);
  slave.sda_m(s_sda_m);
  slave.sda_o(s_sda_o);
  slave_test.clk(s_clk);
  slave_test.reset(s_reset);
  slave_test.data(s_data);
  slave_test.valid(s_valid);
  slave_test.scl(s_scl);
  slave_test.sda(s_sda);
  slave_test.sda_m(s_sda_m);
  slave_test.sda_o(s_sda_o);
  sc_trace_file *tf = sc_create_vcd_trace_file("labI2CSlave");
  tf->set_time_unit(1, SC_NS);
  sc_trace(tf, s_clk, "clk");
  sc_trace(tf, s_reset, "reset");
  sc_trace(tf, s_data, "data");
  sc_trace(tf, s_valid, "valid");
  sc_trace(tf, s_scl, "scl");
  sc_trace(tf, s_sda, "sda");
  sc_trace(tf, s_sda_m, "sda_m");
  sc_trace(tf, s_sda_o, "sda_o");
  sc_start(20000, SC_NS);
  sc_close_vcd_trace_file(tf);
  return 0;
}
