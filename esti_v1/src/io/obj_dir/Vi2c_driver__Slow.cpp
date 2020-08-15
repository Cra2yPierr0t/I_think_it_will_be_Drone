// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vi2c_driver.h for the primary calling header

#include "Vi2c_driver.h"
#include "Vi2c_driver__Syms.h"

//==========

VL_CTOR_IMP(Vi2c_driver) {
    Vi2c_driver__Syms* __restrict vlSymsp = __VlSymsp = new Vi2c_driver__Syms(this, name());
    Vi2c_driver* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vi2c_driver::__Vconfigure(Vi2c_driver__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vi2c_driver::~Vi2c_driver() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vi2c_driver::_initial__TOP__1(Vi2c_driver__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2c_driver::_initial__TOP__1\n"); );
    Vi2c_driver* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->SCL = 1U;
    vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__SDA_en = 0U;
    vlTOPp->i2c_driver_top__DOT__clk_cnt = 0U;
    vlTOPp->i2c_driver_top__DOT__master_clk = 0U;
    vlTOPp->i2c_driver_top__DOT__r_en = 0U;
    vlTOPp->i2c_driver_top__DOT__i_reg_addr = 0x6bU;
    vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__run_flag = 0U;
    vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt = 0U;
    vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__state = 0U;
    vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__pstate = 0U;
    vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__data_index = 7U;
    vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__data_cnt = 1U;
    vlTOPp->i2c_driver_top__DOT__run_req = 0U;
    vlTOPp->i2c_driver_top__DOT__end_flag = 0U;
    vlTOPp->i2c_driver_top__DOT__cnt = 0U;
}

void Vi2c_driver::_settle__TOP__4(Vi2c_driver__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2c_driver::_settle__TOP__4\n"); );
    Vi2c_driver* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__slave_addr_w 
        = (0xfeU & (vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__input_buf 
                    >> 0x13U));
    vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__slave_addr_r 
        = (1U | (0xfeU & (vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__input_buf 
                          >> 0x13U)));
    vlTOPp->received_data[7U] = vlTOPp->i2c_driver_top__DOT____Vcellout__i2c_driver__received_data
        [7U];
    vlTOPp->received_data[6U] = vlTOPp->i2c_driver_top__DOT____Vcellout__i2c_driver__received_data
        [6U];
    vlTOPp->received_data[5U] = vlTOPp->i2c_driver_top__DOT____Vcellout__i2c_driver__received_data
        [5U];
    vlTOPp->received_data[4U] = vlTOPp->i2c_driver_top__DOT____Vcellout__i2c_driver__received_data
        [4U];
    vlTOPp->received_data[3U] = vlTOPp->i2c_driver_top__DOT____Vcellout__i2c_driver__received_data
        [3U];
    vlTOPp->received_data[2U] = vlTOPp->i2c_driver_top__DOT____Vcellout__i2c_driver__received_data
        [2U];
    vlTOPp->received_data[1U] = vlTOPp->i2c_driver_top__DOT____Vcellout__i2c_driver__received_data
        [1U];
    vlTOPp->received_data[0U] = vlTOPp->i2c_driver_top__DOT____Vcellout__i2c_driver__received_data
        [0U];
    vlTOPp->i2c_driver_top__DOT__addrs[0U] = 0x6bU;
    vlTOPp->i2c_driver_top__DOT__addrs[1U] = 0x1cU;
    vlTOPp->i2c_driver_top__DOT__addrs[2U] = 0x47U;
    vlTOPp->i2c_driver_top__DOT__send_datas[0U] = 0U;
    vlTOPp->i2c_driver_top__DOT__send_datas[1U] = 8U;
    vlTOPp->i2c_driver_top__DOT__send_datas[2U] = 0U;
    vlTOPp->SDA = (((((IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__SDA_en) 
                      & (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__SDA_buf)) 
                     & (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__SDA_en)) 
                    & (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__SDA_en)) 
                   & (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__SDA_en));
}

void Vi2c_driver::_eval_initial(Vi2c_driver__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2c_driver::_eval_initial\n"); );
    Vi2c_driver* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vm_traceActivity[1U] = 1U;
    vlTOPp->__Vm_traceActivity[0U] = 1U;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__i2c_driver_top__DOT__end_flag 
        = vlTOPp->__VinpClk__TOP__i2c_driver_top__DOT__end_flag;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__i2c_driver_top__DOT__run_req 
        = vlTOPp->__VinpClk__TOP__i2c_driver_top__DOT__run_req;
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__i2c_driver_top__DOT__master_clk 
        = vlTOPp->__VinpClk__TOP__i2c_driver_top__DOT__master_clk;
}

void Vi2c_driver::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2c_driver::final\n"); );
    // Variables
    Vi2c_driver__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vi2c_driver* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vi2c_driver::_eval_settle(Vi2c_driver__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2c_driver::_eval_settle\n"); );
    Vi2c_driver* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__4(vlSymsp);
    vlTOPp->__Vm_traceActivity[1U] = 1U;
    vlTOPp->__Vm_traceActivity[0U] = 1U;
}

void Vi2c_driver::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2c_driver::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    SCL = VL_RAND_RESET_I(1);
    SDA = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<8; ++__Vi0) {
            received_data[__Vi0] = VL_RAND_RESET_I(8);
    }}
    i2c_driver_top__DOT__master_clk = VL_RAND_RESET_I(1);
    i2c_driver_top__DOT__clk_cnt = VL_RAND_RESET_I(2);
    i2c_driver_top__DOT__run_req = VL_RAND_RESET_I(1);
    i2c_driver_top__DOT__r_en = VL_RAND_RESET_I(1);
    i2c_driver_top__DOT__i_reg_addr = VL_RAND_RESET_I(8);
    i2c_driver_top__DOT__end_flag = VL_RAND_RESET_I(1);
    i2c_driver_top__DOT__send_data = VL_RAND_RESET_I(8);
    i2c_driver_top__DOT__cnt = VL_RAND_RESET_I(2);
    { int __Vi0=0; for (; __Vi0<3; ++__Vi0) {
            i2c_driver_top__DOT__addrs[__Vi0] = VL_RAND_RESET_I(8);
    }}
    { int __Vi0=0; for (; __Vi0<3; ++__Vi0) {
            i2c_driver_top__DOT__send_datas[__Vi0] = VL_RAND_RESET_I(8);
    }}
    { int __Vi0=0; for (; __Vi0<8; ++__Vi0) {
            i2c_driver_top__DOT____Vcellout__i2c_driver__received_data[__Vi0] = VL_RAND_RESET_I(8);
    }}
    i2c_driver_top__DOT__i2c_driver__DOT__run_flag = VL_RAND_RESET_I(1);
    i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt = VL_RAND_RESET_I(3);
    i2c_driver_top__DOT__i2c_driver__DOT__state = VL_RAND_RESET_I(4);
    i2c_driver_top__DOT__i2c_driver__DOT__pstate = VL_RAND_RESET_I(4);
    i2c_driver_top__DOT__i2c_driver__DOT__data_index = VL_RAND_RESET_I(3);
    i2c_driver_top__DOT__i2c_driver__DOT__slave_addr_w = VL_RAND_RESET_I(8);
    i2c_driver_top__DOT__i2c_driver__DOT__slave_addr_r = VL_RAND_RESET_I(8);
    i2c_driver_top__DOT__i2c_driver__DOT__input_buf = VL_RAND_RESET_I(27);
    i2c_driver_top__DOT__i2c_driver__DOT__ack_flag = VL_RAND_RESET_I(1);
    i2c_driver_top__DOT__i2c_driver__DOT__SDA_buf = VL_RAND_RESET_I(1);
    i2c_driver_top__DOT__i2c_driver__DOT__SDA_en = VL_RAND_RESET_I(1);
    i2c_driver_top__DOT__i2c_driver__DOT__data_cnt = VL_RAND_RESET_I(3);
    __Vdly__i2c_driver_top__DOT__end_flag = VL_RAND_RESET_I(1);
    __VinpClk__TOP__i2c_driver_top__DOT__end_flag = VL_RAND_RESET_I(1);
    __VinpClk__TOP__i2c_driver_top__DOT__run_req = VL_RAND_RESET_I(1);
    __VinpClk__TOP__i2c_driver_top__DOT__master_clk = VL_RAND_RESET_I(1);
    __Vchglast__TOP__i2c_driver_top__DOT__master_clk = VL_RAND_RESET_I(1);
    __Vchglast__TOP__i2c_driver_top__DOT__run_req = VL_RAND_RESET_I(1);
    __Vchglast__TOP__i2c_driver_top__DOT__end_flag = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}
