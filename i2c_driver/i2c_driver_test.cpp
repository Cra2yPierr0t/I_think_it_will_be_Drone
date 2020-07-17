#include <iostream>
#include <verilated.h>
#include "verilated_vcd_c.h"
#include "Vi2c_driver.h"

unsigned int main_time = 0;

int main(int argc, char *argv[]){
    Verilated::commandArgs(argc, argv);

    Vi2c_driver *i2c_driver = new Vi2c_driver();

    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    i2c_driver->trace(tfp, 99);
    tfp->open("wave.vcd");
    
    i2c_driver->clk = 0;

    while(!Verilated::gotFinish()){
        if((main_time % 2) == 0)
            i2c_driver->clk = !i2c_driver->clk;

        i2c_driver->eval();
        tfp->dump(main_time);

        if(main_time > 200000)
            break;

        main_time++;
    }
    tfp->close();
    i2c_driver->final();
}
