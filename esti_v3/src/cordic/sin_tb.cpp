#include <iostream>
#include <verilated.h>
#include "verilated_vcd_c.h"
#include "Vsin.h"

unsigned int main_time = 0;

int main(int argc, char *argv[]){
    Verilated::commandArgs(argc, argv);

    Vsin *sin = new Vsin();

    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    sin->trace(tfp, 99);
    tfp->open("wave.vcd");
    
    sin->clk = 0;

    while(!Verilated::gotFinish()){
        if((main_time % 2) == 0)
            sin->clk = !sin->clk;

        sin->eval();
        tfp->dump(main_time);

        if(main_time > 200000)
            break;

        main_time++;
    }
    tfp->close();
    sin->final();
}

