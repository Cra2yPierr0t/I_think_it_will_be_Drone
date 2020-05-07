// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vacc_driver__Syms.h"


//======================

void Vacc_driver::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vacc_driver* t = (Vacc_driver*)userthis;
    Vacc_driver__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
        t->traceChgThis(vlSymsp, vcdp, code);
    }
}

//======================


void Vacc_driver::traceChgThis(Vacc_driver__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vacc_driver* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
                               | (vlTOPp->__Vm_traceActivity 
                                  >> 1U))))) {
            vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
        }
        vlTOPp->traceChgThis__3(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vacc_driver::traceChgThis__2(Vacc_driver__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vacc_driver* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+1,(vlTOPp->acc_driver__DOT__clk400K));
        vcdp->chgBus(c+9,(vlTOPp->acc_driver__DOT__clk_cnt),6);
    }
}

void Vacc_driver::traceChgThis__3(Vacc_driver__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vacc_driver* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+17,(vlTOPp->clk12M));
        vcdp->chgBit(c+25,(vlTOPp->SDA));
        vcdp->chgBit(c+33,(vlTOPp->SCL));
    }
}
