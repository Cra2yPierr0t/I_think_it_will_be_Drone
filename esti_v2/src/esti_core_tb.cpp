#include <iostream>
#include <verilated.h>
#include "verilated_vcd_c.h"
#include "Vesti_core.h"

unsigned int main_time = 0;

int main(int argc, char *argv[]){
    Verilated::commandArgs(argc, argv);

    Vesti_core *esti_core = new Vesti_core();

    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    esti_core->trace(tfp, 99);
    tfp->open("wave.vcd");
    
    esti_core->clk = 0;

    while(!Verilated::gotFinish()){
        if((main_time % 2) == 0)
            esti_core->clk = !esti_core->clk;

        esti_core->eval();
        tfp->dump(main_time);

        esti_core->acc_in = 0x0600;

        if(main_time > 200000)
            break;

        main_time++;
    }
    tfp->close();
    esti_core->final();
}

