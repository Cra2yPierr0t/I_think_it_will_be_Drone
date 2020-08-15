// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vi2c_driver__Syms.h"


void Vi2c_driver::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vi2c_driver__Syms* __restrict vlSymsp = static_cast<Vi2c_driver__Syms*>(userp);
    Vi2c_driver* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vi2c_driver::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vi2c_driver__Syms* __restrict vlSymsp = static_cast<Vi2c_driver__Syms*>(userp);
    Vi2c_driver* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[0U])) {
            tracep->chgCData(oldp+0,(vlTOPp->i2c_driver_top__DOT__addrs[0]),8);
            tracep->chgCData(oldp+1,(vlTOPp->i2c_driver_top__DOT__addrs[1]),8);
            tracep->chgCData(oldp+2,(vlTOPp->i2c_driver_top__DOT__addrs[2]),8);
            tracep->chgCData(oldp+3,(vlTOPp->i2c_driver_top__DOT__send_datas[0]),8);
            tracep->chgCData(oldp+4,(vlTOPp->i2c_driver_top__DOT__send_datas[1]),8);
            tracep->chgCData(oldp+5,(vlTOPp->i2c_driver_top__DOT__send_datas[2]),8);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgBit(oldp+6,(vlTOPp->i2c_driver_top__DOT__r_en));
            tracep->chgCData(oldp+7,(vlTOPp->i2c_driver_top__DOT__i_reg_addr),8);
            tracep->chgCData(oldp+8,(vlTOPp->i2c_driver_top__DOT__send_data),8);
            tracep->chgCData(oldp+9,(vlTOPp->i2c_driver_top__DOT__cnt),2);
            tracep->chgCData(oldp+10,(vlTOPp->i2c_driver_top__DOT____Vcellout__i2c_driver__received_data[0]),8);
            tracep->chgCData(oldp+11,(vlTOPp->i2c_driver_top__DOT____Vcellout__i2c_driver__received_data[1]),8);
            tracep->chgCData(oldp+12,(vlTOPp->i2c_driver_top__DOT____Vcellout__i2c_driver__received_data[2]),8);
            tracep->chgCData(oldp+13,(vlTOPp->i2c_driver_top__DOT____Vcellout__i2c_driver__received_data[3]),8);
            tracep->chgCData(oldp+14,(vlTOPp->i2c_driver_top__DOT____Vcellout__i2c_driver__received_data[4]),8);
            tracep->chgCData(oldp+15,(vlTOPp->i2c_driver_top__DOT____Vcellout__i2c_driver__received_data[5]),8);
            tracep->chgCData(oldp+16,(vlTOPp->i2c_driver_top__DOT____Vcellout__i2c_driver__received_data[6]),8);
            tracep->chgCData(oldp+17,(vlTOPp->i2c_driver_top__DOT____Vcellout__i2c_driver__received_data[7]),8);
            tracep->chgCData(oldp+18,(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt),3);
            tracep->chgCData(oldp+19,(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__state),4);
            tracep->chgCData(oldp+20,(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__pstate),4);
            tracep->chgCData(oldp+21,(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__data_index),3);
            tracep->chgCData(oldp+22,((0xfeU & (vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__input_buf 
                                                >> 0x13U))),8);
            tracep->chgCData(oldp+23,((1U | (0xfeU 
                                             & (vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__input_buf 
                                                >> 0x13U)))),8);
            tracep->chgIData(oldp+24,(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__input_buf),27);
            tracep->chgBit(oldp+25,(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__ack_flag));
            tracep->chgBit(oldp+26,(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__SDA_buf));
            tracep->chgBit(oldp+27,(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__SDA_en));
            tracep->chgCData(oldp+28,(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__data_cnt),3);
        }
        tracep->chgBit(oldp+29,(vlTOPp->clk));
        tracep->chgBit(oldp+30,(vlTOPp->SCL));
        tracep->chgBit(oldp+31,(vlTOPp->SDA));
        tracep->chgCData(oldp+32,(vlTOPp->received_data[0]),8);
        tracep->chgCData(oldp+33,(vlTOPp->received_data[1]),8);
        tracep->chgCData(oldp+34,(vlTOPp->received_data[2]),8);
        tracep->chgCData(oldp+35,(vlTOPp->received_data[3]),8);
        tracep->chgCData(oldp+36,(vlTOPp->received_data[4]),8);
        tracep->chgCData(oldp+37,(vlTOPp->received_data[5]),8);
        tracep->chgCData(oldp+38,(vlTOPp->received_data[6]),8);
        tracep->chgCData(oldp+39,(vlTOPp->received_data[7]),8);
        tracep->chgBit(oldp+40,(vlTOPp->i2c_driver_top__DOT__master_clk));
        tracep->chgCData(oldp+41,(vlTOPp->i2c_driver_top__DOT__clk_cnt),2);
        tracep->chgBit(oldp+42,(vlTOPp->i2c_driver_top__DOT__run_req));
        tracep->chgBit(oldp+43,(vlTOPp->i2c_driver_top__DOT__end_flag));
        tracep->chgBit(oldp+44,(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__run_flag));
    }
}

void Vi2c_driver::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vi2c_driver__Syms* __restrict vlSymsp = static_cast<Vi2c_driver__Syms*>(userp);
    Vi2c_driver* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
    }
}
