// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vi2c_driver__Syms.h"


//======================

void Vi2c_driver::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vi2c_driver::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vi2c_driver__Syms* __restrict vlSymsp = static_cast<Vi2c_driver__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vi2c_driver::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vi2c_driver::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vi2c_driver__Syms* __restrict vlSymsp = static_cast<Vi2c_driver__Syms*>(userp);
    Vi2c_driver* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vi2c_driver::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vi2c_driver__Syms* __restrict vlSymsp = static_cast<Vi2c_driver__Syms*>(userp);
    Vi2c_driver* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+30,"clk", false,-1);
        tracep->declBit(c+31,"SCL", false,-1);
        tracep->declBit(c+32,"SDA", false,-1);
        {int i; for (i=0; i<8; i++) {
                tracep->declBus(c+33+i*1,"received_data", true,(i+0), 7,0);}}
        tracep->declBit(c+30,"i2c_driver_top clk", false,-1);
        tracep->declBit(c+31,"i2c_driver_top SCL", false,-1);
        tracep->declBit(c+32,"i2c_driver_top SDA", false,-1);
        {int i; for (i=0; i<8; i++) {
                tracep->declBus(c+33+i*1,"i2c_driver_top received_data", true,(i+0), 7,0);}}
        tracep->declBit(c+41,"i2c_driver_top master_clk", false,-1);
        tracep->declBus(c+42,"i2c_driver_top clk_cnt", false,-1, 1,0);
        tracep->declBit(c+43,"i2c_driver_top run_req", false,-1);
        tracep->declBit(c+7,"i2c_driver_top r_en", false,-1);
        tracep->declBus(c+8,"i2c_driver_top i_reg_addr", false,-1, 7,0);
        tracep->declBit(c+44,"i2c_driver_top end_flag", false,-1);
        tracep->declBus(c+9,"i2c_driver_top send_data", false,-1, 7,0);
        tracep->declBus(c+10,"i2c_driver_top cnt", false,-1, 1,0);
        {int i; for (i=0; i<3; i++) {
                tracep->declBus(c+1+i*1,"i2c_driver_top addrs", true,(i+0), 7,0);}}
        {int i; for (i=0; i<3; i++) {
                tracep->declBus(c+4+i*1,"i2c_driver_top send_datas", true,(i+0), 7,0);}}
        tracep->declBit(c+41,"i2c_driver_top i2c_driver clk", false,-1);
        tracep->declBit(c+31,"i2c_driver_top i2c_driver SCL", false,-1);
        tracep->declBit(c+32,"i2c_driver_top i2c_driver SDA", false,-1);
        tracep->declBit(c+43,"i2c_driver_top i2c_driver run_req", false,-1);
        tracep->declBus(c+46,"i2c_driver_top i2c_driver slave_addr", false,-1, 6,0);
        tracep->declBit(c+7,"i2c_driver_top i2c_driver r_en", false,-1);
        tracep->declBus(c+9,"i2c_driver_top i2c_driver send_data", false,-1, 7,0);
        tracep->declBus(c+8,"i2c_driver_top i2c_driver i_reg_addr", false,-1, 7,0);
        tracep->declBus(c+47,"i2c_driver_top i2c_driver num_data", false,-1, 2,0);
        {int i; for (i=0; i<8; i++) {
                tracep->declBus(c+11+i*1,"i2c_driver_top i2c_driver received_data", true,(i+0), 7,0);}}
        tracep->declBit(c+44,"i2c_driver_top i2c_driver end_flag", false,-1);
        tracep->declBus(c+48,"i2c_driver_top i2c_driver BUSY", false,-1, 3,0);
        tracep->declBus(c+49,"i2c_driver_top i2c_driver START", false,-1, 3,0);
        tracep->declBus(c+50,"i2c_driver_top i2c_driver RSTART", false,-1, 3,0);
        tracep->declBus(c+51,"i2c_driver_top i2c_driver STOP", false,-1, 3,0);
        tracep->declBus(c+52,"i2c_driver_top i2c_driver S_ADDR_W", false,-1, 3,0);
        tracep->declBus(c+53,"i2c_driver_top i2c_driver S_ADDR_R", false,-1, 3,0);
        tracep->declBus(c+54,"i2c_driver_top i2c_driver REG_ADDR", false,-1, 3,0);
        tracep->declBus(c+55,"i2c_driver_top i2c_driver RDATA", false,-1, 3,0);
        tracep->declBus(c+56,"i2c_driver_top i2c_driver ACK", false,-1, 3,0);
        tracep->declBus(c+57,"i2c_driver_top i2c_driver NACK", false,-1, 3,0);
        tracep->declBus(c+58,"i2c_driver_top i2c_driver ERR", false,-1, 3,0);
        tracep->declBus(c+59,"i2c_driver_top i2c_driver WDATA", false,-1, 3,0);
        tracep->declBus(c+60,"i2c_driver_top i2c_driver SEND_ACK", false,-1, 3,0);
        tracep->declBus(c+61,"i2c_driver_top i2c_driver W", false,-1, 0,0);
        tracep->declBus(c+62,"i2c_driver_top i2c_driver R", false,-1, 0,0);
        tracep->declBus(c+63,"i2c_driver_top i2c_driver A", false,-1, 2,0);
        tracep->declBus(c+47,"i2c_driver_top i2c_driver B", false,-1, 2,0);
        tracep->declBus(c+64,"i2c_driver_top i2c_driver C", false,-1, 2,0);
        tracep->declBus(c+65,"i2c_driver_top i2c_driver D", false,-1, 2,0);
        tracep->declBit(c+45,"i2c_driver_top i2c_driver run_flag", false,-1);
        tracep->declBus(c+19,"i2c_driver_top i2c_driver ABCD_cnt", false,-1, 2,0);
        tracep->declBus(c+20,"i2c_driver_top i2c_driver state", false,-1, 3,0);
        tracep->declBus(c+21,"i2c_driver_top i2c_driver pstate", false,-1, 3,0);
        tracep->declBus(c+22,"i2c_driver_top i2c_driver data_index", false,-1, 2,0);
        tracep->declBus(c+23,"i2c_driver_top i2c_driver slave_addr_w", false,-1, 7,0);
        tracep->declBus(c+24,"i2c_driver_top i2c_driver slave_addr_r", false,-1, 7,0);
        tracep->declBus(c+25,"i2c_driver_top i2c_driver input_buf", false,-1, 26,0);
        tracep->declBit(c+26,"i2c_driver_top i2c_driver ack_flag", false,-1);
        tracep->declBit(c+27,"i2c_driver_top i2c_driver SDA_buf", false,-1);
        tracep->declBit(c+28,"i2c_driver_top i2c_driver SDA_en", false,-1);
        tracep->declBus(c+29,"i2c_driver_top i2c_driver data_cnt", false,-1, 2,0);
    }
}

void Vi2c_driver::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vi2c_driver::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vi2c_driver__Syms* __restrict vlSymsp = static_cast<Vi2c_driver__Syms*>(userp);
    Vi2c_driver* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vi2c_driver::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vi2c_driver__Syms* __restrict vlSymsp = static_cast<Vi2c_driver__Syms*>(userp);
    Vi2c_driver* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullCData(oldp+1,(vlTOPp->i2c_driver_top__DOT__addrs[0]),8);
        tracep->fullCData(oldp+2,(vlTOPp->i2c_driver_top__DOT__addrs[1]),8);
        tracep->fullCData(oldp+3,(vlTOPp->i2c_driver_top__DOT__addrs[2]),8);
        tracep->fullCData(oldp+4,(vlTOPp->i2c_driver_top__DOT__send_datas[0]),8);
        tracep->fullCData(oldp+5,(vlTOPp->i2c_driver_top__DOT__send_datas[1]),8);
        tracep->fullCData(oldp+6,(vlTOPp->i2c_driver_top__DOT__send_datas[2]),8);
        tracep->fullBit(oldp+7,(vlTOPp->i2c_driver_top__DOT__r_en));
        tracep->fullCData(oldp+8,(vlTOPp->i2c_driver_top__DOT__i_reg_addr),8);
        tracep->fullCData(oldp+9,(vlTOPp->i2c_driver_top__DOT__send_data),8);
        tracep->fullCData(oldp+10,(vlTOPp->i2c_driver_top__DOT__cnt),2);
        tracep->fullCData(oldp+11,(vlTOPp->i2c_driver_top__DOT____Vcellout__i2c_driver__received_data[0]),8);
        tracep->fullCData(oldp+12,(vlTOPp->i2c_driver_top__DOT____Vcellout__i2c_driver__received_data[1]),8);
        tracep->fullCData(oldp+13,(vlTOPp->i2c_driver_top__DOT____Vcellout__i2c_driver__received_data[2]),8);
        tracep->fullCData(oldp+14,(vlTOPp->i2c_driver_top__DOT____Vcellout__i2c_driver__received_data[3]),8);
        tracep->fullCData(oldp+15,(vlTOPp->i2c_driver_top__DOT____Vcellout__i2c_driver__received_data[4]),8);
        tracep->fullCData(oldp+16,(vlTOPp->i2c_driver_top__DOT____Vcellout__i2c_driver__received_data[5]),8);
        tracep->fullCData(oldp+17,(vlTOPp->i2c_driver_top__DOT____Vcellout__i2c_driver__received_data[6]),8);
        tracep->fullCData(oldp+18,(vlTOPp->i2c_driver_top__DOT____Vcellout__i2c_driver__received_data[7]),8);
        tracep->fullCData(oldp+19,(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt),3);
        tracep->fullCData(oldp+20,(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__state),4);
        tracep->fullCData(oldp+21,(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__pstate),4);
        tracep->fullCData(oldp+22,(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__data_index),3);
        tracep->fullCData(oldp+23,((0xfeU & (vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__input_buf 
                                             >> 0x13U))),8);
        tracep->fullCData(oldp+24,((1U | (0xfeU & (vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__input_buf 
                                                   >> 0x13U)))),8);
        tracep->fullIData(oldp+25,(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__input_buf),27);
        tracep->fullBit(oldp+26,(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__ack_flag));
        tracep->fullBit(oldp+27,(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__SDA_buf));
        tracep->fullBit(oldp+28,(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__SDA_en));
        tracep->fullCData(oldp+29,(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__data_cnt),3);
        tracep->fullBit(oldp+30,(vlTOPp->clk));
        tracep->fullBit(oldp+31,(vlTOPp->SCL));
        tracep->fullBit(oldp+32,(vlTOPp->SDA));
        tracep->fullCData(oldp+33,(vlTOPp->received_data[0]),8);
        tracep->fullCData(oldp+34,(vlTOPp->received_data[1]),8);
        tracep->fullCData(oldp+35,(vlTOPp->received_data[2]),8);
        tracep->fullCData(oldp+36,(vlTOPp->received_data[3]),8);
        tracep->fullCData(oldp+37,(vlTOPp->received_data[4]),8);
        tracep->fullCData(oldp+38,(vlTOPp->received_data[5]),8);
        tracep->fullCData(oldp+39,(vlTOPp->received_data[6]),8);
        tracep->fullCData(oldp+40,(vlTOPp->received_data[7]),8);
        tracep->fullBit(oldp+41,(vlTOPp->i2c_driver_top__DOT__master_clk));
        tracep->fullCData(oldp+42,(vlTOPp->i2c_driver_top__DOT__clk_cnt),2);
        tracep->fullBit(oldp+43,(vlTOPp->i2c_driver_top__DOT__run_req));
        tracep->fullBit(oldp+44,(vlTOPp->i2c_driver_top__DOT__end_flag));
        tracep->fullBit(oldp+45,(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__run_flag));
        tracep->fullCData(oldp+46,(0x68U),7);
        tracep->fullCData(oldp+47,(1U),3);
        tracep->fullCData(oldp+48,(0U),4);
        tracep->fullCData(oldp+49,(1U),4);
        tracep->fullCData(oldp+50,(2U),4);
        tracep->fullCData(oldp+51,(3U),4);
        tracep->fullCData(oldp+52,(4U),4);
        tracep->fullCData(oldp+53,(5U),4);
        tracep->fullCData(oldp+54,(6U),4);
        tracep->fullCData(oldp+55,(7U),4);
        tracep->fullCData(oldp+56,(8U),4);
        tracep->fullCData(oldp+57,(9U),4);
        tracep->fullCData(oldp+58,(0xaU),4);
        tracep->fullCData(oldp+59,(0xbU),4);
        tracep->fullCData(oldp+60,(0xcU),4);
        tracep->fullBit(oldp+61,(0U));
        tracep->fullBit(oldp+62,(1U));
        tracep->fullCData(oldp+63,(0U),3);
        tracep->fullCData(oldp+64,(2U),3);
        tracep->fullCData(oldp+65,(3U),3);
    }
}
