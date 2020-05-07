#include<iostream>
#include<verilated.h>
#include"verilated_vcd_c.h"
#include"Vacc_driver.h"

unsigned int main_time = 0;

int main(){
    Vacc_driver *acc_driver = new Vacc_driver();

    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    acc_driver->trace(tfp, 99);
    tfp->open("wave.vcd");

    acc_driver->clk12M = 0;

    while(1){
        if((main_time % 2)  == 0)
            acc_driver->clk12M = !acc_driver->clk12M;

        acc_driver->eval();
        tfp->dump(main_time);

        if(main_time > 200000)
            break;

        main_time++;
    }

    tfp->close();
    acc_driver->final();
}
