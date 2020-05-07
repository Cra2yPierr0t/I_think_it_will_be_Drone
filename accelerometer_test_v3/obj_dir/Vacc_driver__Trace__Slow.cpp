// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vacc_driver__Syms.h"


//======================

void Vacc_driver::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback(&Vacc_driver::traceInit, &Vacc_driver::traceFull, &Vacc_driver::traceChg, this);
}
void Vacc_driver::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    Vacc_driver* t = (Vacc_driver*)userthis;
    Vacc_driver__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vcdp->scopeEscape(' ');
    t->traceInitThis(vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void Vacc_driver::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vacc_driver* t = (Vacc_driver*)userthis;
    Vacc_driver__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    t->traceFullThis(vlSymsp, vcdp, code);
}

//======================


void Vacc_driver::traceInitThis(Vacc_driver__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vacc_driver* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name());  // Setup signal names
    // Body
    {
        vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void Vacc_driver::traceFullThis(Vacc_driver__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vacc_driver* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vacc_driver::traceInitThis__1(Vacc_driver__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vacc_driver* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->declBit(c+17,"clk12M", false,-1);
        vcdp->declBit(c+25,"SDA", false,-1);
        vcdp->declBit(c+33,"SCL", false,-1);
        vcdp->declBit(c+17,"acc_driver clk12M", false,-1);
        vcdp->declBit(c+25,"acc_driver SDA", false,-1);
        vcdp->declBit(c+33,"acc_driver SCL", false,-1);
        vcdp->declBit(c+1,"acc_driver clk400K", false,-1);
        vcdp->declBus(c+9,"acc_driver clk_cnt", false,-1, 5,0);
    }
}

void Vacc_driver::traceFullThis__1(Vacc_driver__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vacc_driver* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->fullBit(c+1,(vlTOPp->acc_driver__DOT__clk400K));
        vcdp->fullBus(c+9,(vlTOPp->acc_driver__DOT__clk_cnt),6);
        vcdp->fullBit(c+17,(vlTOPp->clk12M));
        vcdp->fullBit(c+25,(vlTOPp->SDA));
        vcdp->fullBit(c+33,(vlTOPp->SCL));
    }
}
