// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vi2c_driver.h for the primary calling header

#include "Vi2c_driver.h"
#include "Vi2c_driver__Syms.h"

//==========

void Vi2c_driver::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vi2c_driver::eval\n"); );
    Vi2c_driver__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vi2c_driver* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("i2c_driver_top.sv", 4, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vi2c_driver::_eval_initial_loop(Vi2c_driver__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("i2c_driver_top.sv", 4, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vi2c_driver::_sequent__TOP__3(Vi2c_driver__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2c_driver::_sequent__TOP__3\n"); );
    Vi2c_driver* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->i2c_driver_top__DOT__master_clk = (1U & 
                                               ((3U 
                                                 == (IData)(vlTOPp->i2c_driver_top__DOT__clk_cnt))
                                                 ? 
                                                (~ (IData)(vlTOPp->i2c_driver_top__DOT__master_clk))
                                                 : (IData)(vlTOPp->i2c_driver_top__DOT__master_clk)));
    vlTOPp->i2c_driver_top__DOT__clk_cnt = (3U & ((IData)(1U) 
                                                  + (IData)(vlTOPp->i2c_driver_top__DOT__clk_cnt)));
}

VL_INLINE_OPT void Vi2c_driver::_sequent__TOP__5(Vi2c_driver__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2c_driver::_sequent__TOP__5\n"); );
    Vi2c_driver* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*1:0*/ __Vdly__i2c_driver_top__DOT__cnt;
    CData/*0:0*/ __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__SDA_en;
    CData/*3:0*/ __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__pstate;
    CData/*3:0*/ __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__state;
    CData/*2:0*/ __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt;
    CData/*2:0*/ __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__data_index;
    CData/*2:0*/ __Vdlyvdim0__i2c_driver_top__DOT____Vcellout__i2c_driver__received_data__v0;
    CData/*2:0*/ __Vdlyvlsb__i2c_driver_top__DOT____Vcellout__i2c_driver__received_data__v0;
    CData/*0:0*/ __Vdlyvval__i2c_driver_top__DOT____Vcellout__i2c_driver__received_data__v0;
    CData/*0:0*/ __Vdlyvset__i2c_driver_top__DOT____Vcellout__i2c_driver__received_data__v0;
    CData/*2:0*/ __Vdlyvdim0__i2c_driver_top__DOT____Vcellout__i2c_driver__received_data__v1;
    CData/*2:0*/ __Vdlyvlsb__i2c_driver_top__DOT____Vcellout__i2c_driver__received_data__v1;
    CData/*0:0*/ __Vdlyvval__i2c_driver_top__DOT____Vcellout__i2c_driver__received_data__v1;
    CData/*0:0*/ __Vdlyvset__i2c_driver_top__DOT____Vcellout__i2c_driver__received_data__v1;
    CData/*2:0*/ __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__data_cnt;
    CData/*0:0*/ __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__ack_flag;
    IData/*26:0*/ __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__input_buf;
    // Body
    __Vdly__i2c_driver_top__DOT__cnt = vlTOPp->i2c_driver_top__DOT__cnt;
    vlTOPp->__Vdly__i2c_driver_top__DOT__end_flag = vlTOPp->i2c_driver_top__DOT__end_flag;
    __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__ack_flag 
        = vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__ack_flag;
    __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__data_cnt 
        = vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__data_cnt;
    __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__data_index 
        = vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__data_index;
    __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt 
        = vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt;
    __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__state 
        = vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__state;
    __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__pstate 
        = vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__pstate;
    __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__SDA_en 
        = vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__SDA_en;
    __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__input_buf 
        = vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__input_buf;
    __Vdlyvset__i2c_driver_top__DOT____Vcellout__i2c_driver__received_data__v0 = 0U;
    __Vdlyvset__i2c_driver_top__DOT____Vcellout__i2c_driver__received_data__v1 = 0U;
    if (((((((((0U == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__state)) 
               | (1U == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__state))) 
              | (2U == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__state))) 
             | (3U == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__state))) 
            | (4U == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__state))) 
           | (5U == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__state))) 
          | (6U == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__state))) 
         | (0xbU == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__state)))) {
        if ((0U == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__state))) {
            __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__input_buf 
                = (0x6800000U | (0xfffffU & __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__input_buf));
            __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__SDA_en = 1U;
            vlTOPp->SCL = 1U;
            vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__SDA_buf = 1U;
            __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__pstate 
                = vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__state;
            __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__input_buf 
                = ((0x7f7ffffU & __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__input_buf) 
                   | ((IData)(vlTOPp->i2c_driver_top__DOT__r_en) 
                      << 0x13U));
            __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__state 
                = ((IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__run_flag)
                    ? 1U : (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__state));
            __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__input_buf 
                = ((0x7f807ffU & __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__input_buf) 
                   | ((IData)(vlTOPp->i2c_driver_top__DOT__send_data) 
                      << 0xbU));
            __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__input_buf 
                = ((0x7fff807U & __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__input_buf) 
                   | ((IData)(vlTOPp->i2c_driver_top__DOT__i_reg_addr) 
                      << 3U));
            __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__input_buf 
                = (0x7fffff8U & __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__input_buf);
        } else {
            if ((1U == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__state))) {
                __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__input_buf 
                    = vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__input_buf;
                __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__SDA_en = 1U;
                if ((0U == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt))) {
                    vlTOPp->SCL = 1U;
                    vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__SDA_buf = 1U;
                    __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt = 1U;
                } else {
                    if ((1U == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt))) {
                        vlTOPp->SCL = 1U;
                        vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__SDA_buf = 1U;
                        __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt = 2U;
                    } else {
                        if ((2U == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt))) {
                            vlTOPp->SCL = 1U;
                            vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__SDA_buf = 0U;
                            __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt = 3U;
                        } else {
                            if ((3U == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt))) {
                                __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__state = 4U;
                                vlTOPp->SCL = 0U;
                                vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__SDA_buf = 0U;
                                __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt = 0U;
                                __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__pstate 
                                    = vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__state;
                            }
                        }
                    }
                }
            } else {
                if ((2U == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__state))) {
                    __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__input_buf 
                        = vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__input_buf;
                    __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__SDA_en = 1U;
                    if ((0U == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt))) {
                        __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt = 1U;
                        vlTOPp->SCL = 0U;
                        vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__SDA_buf = 1U;
                    } else {
                        if ((1U == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt))) {
                            __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt = 2U;
                            vlTOPp->SCL = 1U;
                            vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__SDA_buf = 1U;
                        } else {
                            if ((2U == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt))) {
                                __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt = 3U;
                                vlTOPp->SCL = 1U;
                                vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__SDA_buf = 0U;
                            } else {
                                if ((3U == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt))) {
                                    __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt = 0U;
                                    __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__state = 5U;
                                    vlTOPp->SCL = 0U;
                                    vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__SDA_buf = 0U;
                                    __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__pstate 
                                        = vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__state;
                                }
                            }
                        }
                    }
                } else {
                    if ((3U == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__state))) {
                        __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__input_buf 
                            = vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__input_buf;
                        __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__SDA_en = 1U;
                        if ((0U == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt))) {
                            __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt = 1U;
                            vlTOPp->SCL = 0U;
                            vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__SDA_buf = 0U;
                        } else {
                            if ((1U == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt))) {
                                __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt = 2U;
                                vlTOPp->SCL = 1U;
                                vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__SDA_buf = 0U;
                            } else {
                                if ((2U == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt))) {
                                    __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt = 3U;
                                    vlTOPp->SCL = 1U;
                                    vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__SDA_buf = 1U;
                                    vlTOPp->__Vdly__i2c_driver_top__DOT__end_flag = 1U;
                                } else {
                                    if ((3U == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt))) {
                                        __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt = 0U;
                                        __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__state = 0U;
                                        vlTOPp->SCL = 1U;
                                        vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__SDA_buf = 1U;
                                        __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__pstate 
                                            = vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__state;
                                        vlTOPp->__Vdly__i2c_driver_top__DOT__end_flag = 0U;
                                    }
                                }
                            }
                        }
                    } else {
                        if ((4U == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__state))) {
                            __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__input_buf 
                                = vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__input_buf;
                            __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__SDA_en = 1U;
                            if ((0U == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt))) {
                                __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt = 1U;
                                vlTOPp->SCL = 0U;
                                vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__SDA_buf 
                                    = (1U & ((IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__slave_addr_w) 
                                             >> (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__data_index)));
                            } else {
                                if ((1U == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt))) {
                                    __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt = 2U;
                                    vlTOPp->SCL = 1U;
                                    vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__SDA_buf 
                                        = (1U & ((IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__slave_addr_w) 
                                                 >> (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__data_index)));
                                } else {
                                    if ((2U == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt))) {
                                        __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt = 3U;
                                        vlTOPp->SCL = 1U;
                                        vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__SDA_buf 
                                            = (1U & 
                                               ((IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__slave_addr_w) 
                                                >> (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__data_index)));
                                    } else {
                                        if ((3U == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt))) {
                                            __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt = 0U;
                                            vlTOPp->SCL = 0U;
                                            vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__SDA_buf 
                                                = (1U 
                                                   & ((IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__slave_addr_w) 
                                                      >> (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__data_index)));
                                            if ((0U 
                                                 == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__data_index))) {
                                                __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__state = 8U;
                                                __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__pstate 
                                                    = vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__state;
                                                __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__data_index = 7U;
                                            } else {
                                                __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__data_index 
                                                    = 
                                                    (7U 
                                                     & ((IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__data_index) 
                                                        - (IData)(1U)));
                                                __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__state 
                                                    = vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__state;
                                            }
                                        }
                                    }
                                }
                            }
                        } else {
                            if ((5U == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__state))) {
                                __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__input_buf 
                                    = vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__input_buf;
                                __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__SDA_en = 1U;
                                if ((0U == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt))) {
                                    __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt = 1U;
                                    vlTOPp->SCL = 0U;
                                    vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__SDA_buf 
                                        = (1U & ((IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__slave_addr_r) 
                                                 >> (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__data_index)));
                                } else {
                                    if ((1U == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt))) {
                                        __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt = 2U;
                                        vlTOPp->SCL = 1U;
                                        vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__SDA_buf 
                                            = (1U & 
                                               ((IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__slave_addr_r) 
                                                >> (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__data_index)));
                                    } else {
                                        if ((2U == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt))) {
                                            __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt = 3U;
                                            vlTOPp->SCL = 1U;
                                            vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__SDA_buf 
                                                = (1U 
                                                   & ((IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__slave_addr_r) 
                                                      >> (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__data_index)));
                                        } else {
                                            if ((3U 
                                                 == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt))) {
                                                __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt = 0U;
                                                vlTOPp->SCL = 0U;
                                                vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__SDA_buf 
                                                    = 
                                                    (1U 
                                                     & ((IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__slave_addr_r) 
                                                        >> (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__data_index)));
                                                if (
                                                    (0U 
                                                     == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__data_index))) {
                                                    __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__state = 8U;
                                                    __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__data_index = 7U;
                                                    __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__pstate 
                                                        = vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__state;
                                                } else {
                                                    __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__state 
                                                        = vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__state;
                                                    __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__data_index 
                                                        = 
                                                        (7U 
                                                         & ((IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__data_index) 
                                                            - (IData)(1U)));
                                                }
                                            }
                                        }
                                    }
                                }
                            } else {
                                if ((6U == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__state))) {
                                    __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__input_buf 
                                        = vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__input_buf;
                                    __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__SDA_en = 1U;
                                    if ((0U == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt))) {
                                        __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt = 1U;
                                        vlTOPp->SCL = 0U;
                                        vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__SDA_buf 
                                            = ((0x1aU 
                                                >= 
                                                ((IData)(3U) 
                                                 + (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__data_index))) 
                                               & (vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__input_buf 
                                                  >> 
                                                  ((IData)(3U) 
                                                   + (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__data_index))));
                                    } else {
                                        if ((1U == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt))) {
                                            __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt = 2U;
                                            vlTOPp->SCL = 1U;
                                            vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__SDA_buf 
                                                = (
                                                   (0x1aU 
                                                    >= 
                                                    ((IData)(3U) 
                                                     + (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__data_index))) 
                                                   & (vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__input_buf 
                                                      >> 
                                                      ((IData)(3U) 
                                                       + (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__data_index))));
                                        } else {
                                            if ((2U 
                                                 == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt))) {
                                                __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt = 3U;
                                                vlTOPp->SCL = 1U;
                                                vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__SDA_buf 
                                                    = 
                                                    ((0x1aU 
                                                      >= 
                                                      ((IData)(3U) 
                                                       + (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__data_index))) 
                                                     & (vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__input_buf 
                                                        >> 
                                                        ((IData)(3U) 
                                                         + (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__data_index))));
                                            } else {
                                                if (
                                                    (3U 
                                                     == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt))) {
                                                    __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt = 0U;
                                                    vlTOPp->SCL = 0U;
                                                    vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__SDA_buf 
                                                        = 
                                                        ((0x1aU 
                                                          >= 
                                                          ((IData)(3U) 
                                                           + (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__data_index))) 
                                                         & (vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__input_buf 
                                                            >> 
                                                            ((IData)(3U) 
                                                             + (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__data_index))));
                                                    if (
                                                        (0U 
                                                         == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__data_index))) {
                                                        __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__state = 8U;
                                                        __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__data_index = 7U;
                                                        __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__pstate 
                                                            = vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__state;
                                                    } else {
                                                        __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__state 
                                                            = vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__state;
                                                        __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__data_index 
                                                            = 
                                                            (7U 
                                                             & ((IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__data_index) 
                                                                - (IData)(1U)));
                                                    }
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__input_buf 
                                        = vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__input_buf;
                                    __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__SDA_en = 1U;
                                    if ((0U == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt))) {
                                        __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt = 1U;
                                        vlTOPp->SCL = 0U;
                                        vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__SDA_buf 
                                            = ((0x1aU 
                                                >= 
                                                ((IData)(0xbU) 
                                                 + (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__data_index))) 
                                               & (vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__input_buf 
                                                  >> 
                                                  ((IData)(0xbU) 
                                                   + (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__data_index))));
                                    } else {
                                        if ((1U == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt))) {
                                            __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt = 2U;
                                            vlTOPp->SCL = 1U;
                                            vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__SDA_buf 
                                                = (
                                                   (0x1aU 
                                                    >= 
                                                    ((IData)(0xbU) 
                                                     + (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__data_index))) 
                                                   & (vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__input_buf 
                                                      >> 
                                                      ((IData)(0xbU) 
                                                       + (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__data_index))));
                                        } else {
                                            if ((2U 
                                                 == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt))) {
                                                __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt = 3U;
                                                vlTOPp->SCL = 1U;
                                                vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__SDA_buf 
                                                    = 
                                                    ((0x1aU 
                                                      >= 
                                                      ((IData)(0xbU) 
                                                       + (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__data_index))) 
                                                     & (vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__input_buf 
                                                        >> 
                                                        ((IData)(0xbU) 
                                                         + (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__data_index))));
                                            } else {
                                                if (
                                                    (3U 
                                                     == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt))) {
                                                    __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt = 0U;
                                                    vlTOPp->SCL = 0U;
                                                    vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__SDA_buf 
                                                        = 
                                                        ((0x1aU 
                                                          >= 
                                                          ((IData)(0xbU) 
                                                           + (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__data_index))) 
                                                         & (vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__input_buf 
                                                            >> 
                                                            ((IData)(0xbU) 
                                                             + (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__data_index))));
                                                    if (
                                                        (0U 
                                                         == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__data_index))) {
                                                        __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__state = 8U;
                                                        __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__data_index = 7U;
                                                        __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__pstate 
                                                            = vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__state;
                                                    } else {
                                                        __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__state 
                                                            = vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__state;
                                                        __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__data_index 
                                                            = 
                                                            (7U 
                                                             & ((IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__data_index) 
                                                                - (IData)(1U)));
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    } else {
        if ((7U == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__state))) {
            __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__input_buf 
                = vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__input_buf;
            __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__SDA_en = 0U;
            if ((0U == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt))) {
                __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt = 1U;
                vlTOPp->SCL = 0U;
            } else {
                if ((1U == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt))) {
                    __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt = 2U;
                    vlTOPp->SCL = 1U;
                    __Vdlyvval__i2c_driver_top__DOT____Vcellout__i2c_driver__received_data__v0 
                        = vlTOPp->SDA;
                    __Vdlyvset__i2c_driver_top__DOT____Vcellout__i2c_driver__received_data__v0 = 1U;
                    __Vdlyvlsb__i2c_driver_top__DOT____Vcellout__i2c_driver__received_data__v0 
                        = vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__data_cnt;
                    __Vdlyvdim0__i2c_driver_top__DOT____Vcellout__i2c_driver__received_data__v0 
                        = vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__data_index;
                } else {
                    if ((2U == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt))) {
                        __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt = 3U;
                        vlTOPp->SCL = 1U;
                        __Vdlyvval__i2c_driver_top__DOT____Vcellout__i2c_driver__received_data__v1 
                            = vlTOPp->SDA;
                        __Vdlyvset__i2c_driver_top__DOT____Vcellout__i2c_driver__received_data__v1 = 1U;
                        __Vdlyvlsb__i2c_driver_top__DOT____Vcellout__i2c_driver__received_data__v1 
                            = vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__data_cnt;
                        __Vdlyvdim0__i2c_driver_top__DOT____Vcellout__i2c_driver__received_data__v1 
                            = vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__data_index;
                    } else {
                        if ((3U == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt))) {
                            __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt = 0U;
                            vlTOPp->SCL = 0U;
                            if (((0U == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__data_index)) 
                                 & ((7U & vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__input_buf) 
                                    != (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__data_cnt)))) {
                                __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__state = 0xcU;
                                __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__data_index = 7U;
                                __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__data_cnt 
                                    = (7U & ((IData)(1U) 
                                             + (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__data_cnt)));
                                __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__pstate 
                                    = vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__state;
                            } else {
                                if (((0U == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__data_index)) 
                                     & ((7U & vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__input_buf) 
                                        == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__data_cnt)))) {
                                    __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__state = 9U;
                                    __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__data_index = 7U;
                                    __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__data_cnt = 0U;
                                    __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__pstate 
                                        = vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__state;
                                } else {
                                    __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__state 
                                        = vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__state;
                                    __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__data_index 
                                        = (7U & ((IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__data_index) 
                                                 - (IData)(1U)));
                                }
                            }
                        }
                    }
                }
            }
        } else {
            if ((8U == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__state))) {
                __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__input_buf 
                    = vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__input_buf;
                vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__SDA_en = 0U;
                if ((0U == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt))) {
                    __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt = 1U;
                    vlTOPp->SCL = 0U;
                    __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__ack_flag = 1U;
                } else {
                    if ((1U == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt))) {
                        __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt = 2U;
                        vlTOPp->SCL = 1U;
                        __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__ack_flag 
                            = (1U & (~ (IData)(vlTOPp->SDA)));
                    } else {
                        if ((2U == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt))) {
                            __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt = 3U;
                            vlTOPp->SCL = 1U;
                            __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__ack_flag 
                                = (1U & (~ (IData)(vlTOPp->SDA)));
                        } else {
                            if ((3U == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt))) {
                                __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__pstate 
                                    = vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__state;
                                if (vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__ack_flag) {
                                    __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt = 0U;
                                    __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__state 
                                        = ((4U == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__pstate))
                                            ? 6U : 
                                           ((6U == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__pstate))
                                             ? ((0x80000U 
                                                 & vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__input_buf)
                                                 ? 2U
                                                 : 0xbU)
                                             : ((5U 
                                                 == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__pstate))
                                                 ? 7U
                                                 : 
                                                ((0xbU 
                                                  == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__pstate))
                                                  ? 3U
                                                  : 0xaU))));
                                    vlTOPp->SCL = 0U;
                                } else {
                                    __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt = 1U;
                                    __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__state 
                                        = vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__state;
                                    vlTOPp->SCL = 1U;
                                }
                            }
                        }
                    }
                }
            } else {
                if ((9U == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__state))) {
                    __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__input_buf 
                        = vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__input_buf;
                    vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__SDA_en = 1U;
                    if ((0U == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt))) {
                        __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt = 1U;
                        vlTOPp->SCL = 0U;
                        vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__SDA_buf = 1U;
                    } else {
                        if ((1U == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt))) {
                            __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt = 2U;
                            vlTOPp->SCL = 1U;
                            vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__SDA_buf = 1U;
                        } else {
                            if ((2U == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt))) {
                                __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt = 3U;
                                vlTOPp->SCL = 1U;
                                vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__SDA_buf = 1U;
                            } else {
                                if ((3U == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt))) {
                                    __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt = 0U;
                                    __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__state = 3U;
                                    vlTOPp->SCL = 0U;
                                    vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__SDA_buf = 1U;
                                    __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__pstate 
                                        = vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__state;
                                }
                            }
                        }
                    }
                } else {
                    if ((0xcU == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__state))) {
                        __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__input_buf 
                            = vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__input_buf;
                        vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__SDA_en = 1U;
                        if ((0U == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt))) {
                            __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt = 1U;
                            vlTOPp->SCL = 0U;
                            vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__SDA_buf = 0U;
                        } else {
                            if ((1U == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt))) {
                                __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt = 2U;
                                vlTOPp->SCL = 1U;
                                vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__SDA_buf = 0U;
                            } else {
                                if ((2U == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt))) {
                                    __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt = 3U;
                                    vlTOPp->SCL = 1U;
                                    vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__SDA_buf = 0U;
                                } else {
                                    if ((3U == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt))) {
                                        __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt = 0U;
                                        __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__state = 7U;
                                        vlTOPp->SCL = 0U;
                                        vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__SDA_buf = 0U;
                                        __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__pstate 
                                            = vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__state;
                                    }
                                }
                            }
                        }
                    } else {
                        if ((0xaU == (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__state))) {
                            __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__input_buf 
                                = vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__input_buf;
                            vlTOPp->SCL = 1U;
                            vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__SDA_buf = 1U;
                        }
                    }
                }
            }
        }
    }
    vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__ack_flag 
        = __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__ack_flag;
    vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__state 
        = __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__state;
    vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt 
        = __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt;
    vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__data_index 
        = __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__data_index;
    vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__data_cnt 
        = __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__data_cnt;
    vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__pstate 
        = __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__pstate;
    vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__SDA_en 
        = __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__SDA_en;
    vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__input_buf 
        = __Vdly__i2c_driver_top__DOT__i2c_driver__DOT__input_buf;
    if (__Vdlyvset__i2c_driver_top__DOT____Vcellout__i2c_driver__received_data__v0) {
        vlTOPp->i2c_driver_top__DOT____Vcellout__i2c_driver__received_data[__Vdlyvdim0__i2c_driver_top__DOT____Vcellout__i2c_driver__received_data__v0] 
            = (((~ ((IData)(1U) << (IData)(__Vdlyvlsb__i2c_driver_top__DOT____Vcellout__i2c_driver__received_data__v0))) 
                & vlTOPp->i2c_driver_top__DOT____Vcellout__i2c_driver__received_data
                [__Vdlyvdim0__i2c_driver_top__DOT____Vcellout__i2c_driver__received_data__v0]) 
               | ((IData)(__Vdlyvval__i2c_driver_top__DOT____Vcellout__i2c_driver__received_data__v0) 
                  << (IData)(__Vdlyvlsb__i2c_driver_top__DOT____Vcellout__i2c_driver__received_data__v0)));
    }
    if (__Vdlyvset__i2c_driver_top__DOT____Vcellout__i2c_driver__received_data__v1) {
        vlTOPp->i2c_driver_top__DOT____Vcellout__i2c_driver__received_data[__Vdlyvdim0__i2c_driver_top__DOT____Vcellout__i2c_driver__received_data__v1] 
            = (((~ ((IData)(1U) << (IData)(__Vdlyvlsb__i2c_driver_top__DOT____Vcellout__i2c_driver__received_data__v1))) 
                & vlTOPp->i2c_driver_top__DOT____Vcellout__i2c_driver__received_data
                [__Vdlyvdim0__i2c_driver_top__DOT____Vcellout__i2c_driver__received_data__v1]) 
               | ((IData)(__Vdlyvval__i2c_driver_top__DOT____Vcellout__i2c_driver__received_data__v1) 
                  << (IData)(__Vdlyvlsb__i2c_driver_top__DOT____Vcellout__i2c_driver__received_data__v1)));
    }
    vlTOPp->SDA = (((((IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__SDA_en) 
                      & (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__SDA_buf)) 
                     & (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__SDA_en)) 
                    & (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__SDA_en)) 
                   & (IData)(vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__SDA_en));
    vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__slave_addr_w 
        = (0xfeU & (vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__input_buf 
                    >> 0x13U));
    vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__slave_addr_r 
        = (1U | (0xfeU & (vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__input_buf 
                          >> 0x13U)));
    if ((2U >= (IData)(vlTOPp->i2c_driver_top__DOT__cnt))) {
        vlTOPp->i2c_driver_top__DOT__i_reg_addr = vlTOPp->i2c_driver_top__DOT__addrs
            [vlTOPp->i2c_driver_top__DOT__cnt];
        vlTOPp->i2c_driver_top__DOT__send_data = vlTOPp->i2c_driver_top__DOT__send_datas
            [vlTOPp->i2c_driver_top__DOT__cnt];
    } else {
        vlTOPp->i2c_driver_top__DOT__i_reg_addr = 0U;
        vlTOPp->i2c_driver_top__DOT__send_data = 0U;
    }
    if (vlTOPp->i2c_driver_top__DOT__end_flag) {
        if ((2U != (IData)(vlTOPp->i2c_driver_top__DOT__cnt))) {
            __Vdly__i2c_driver_top__DOT__cnt = (3U 
                                                & ((IData)(1U) 
                                                   + (IData)(vlTOPp->i2c_driver_top__DOT__cnt)));
        } else {
            __Vdly__i2c_driver_top__DOT__cnt = vlTOPp->i2c_driver_top__DOT__cnt;
            vlTOPp->i2c_driver_top__DOT__r_en = 1U;
        }
    }
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
    vlTOPp->i2c_driver_top__DOT__cnt = __Vdly__i2c_driver_top__DOT__cnt;
}

VL_INLINE_OPT void Vi2c_driver::_sequent__TOP__6(Vi2c_driver__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2c_driver::_sequent__TOP__6\n"); );
    Vi2c_driver* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->i2c_driver_top__DOT__run_req) {
        vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__run_flag = 1U;
    } else {
        if (vlTOPp->i2c_driver_top__DOT__end_flag) {
            vlTOPp->i2c_driver_top__DOT__i2c_driver__DOT__run_flag = 0U;
        }
    }
}

VL_INLINE_OPT void Vi2c_driver::_sequent__TOP__7(Vi2c_driver__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2c_driver::_sequent__TOP__7\n"); );
    Vi2c_driver* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->i2c_driver_top__DOT__end_flag = vlTOPp->__Vdly__i2c_driver_top__DOT__end_flag;
    vlTOPp->i2c_driver_top__DOT__run_req = 1U;
}

void Vi2c_driver::_eval(Vi2c_driver__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2c_driver::_eval\n"); );
    Vi2c_driver* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__3(vlSymsp);
    }
    if (((IData)(vlTOPp->__VinpClk__TOP__i2c_driver_top__DOT__master_clk) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__i2c_driver_top__DOT__master_clk)))) {
        vlTOPp->_sequent__TOP__5(vlSymsp);
        vlTOPp->__Vm_traceActivity[1U] = 1U;
    }
    if ((((IData)(vlTOPp->__VinpClk__TOP__i2c_driver_top__DOT__end_flag) 
          & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__i2c_driver_top__DOT__end_flag))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__i2c_driver_top__DOT__run_req) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__i2c_driver_top__DOT__run_req))))) {
        vlTOPp->_sequent__TOP__6(vlSymsp);
    }
    if (((IData)(vlTOPp->__VinpClk__TOP__i2c_driver_top__DOT__master_clk) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__i2c_driver_top__DOT__master_clk)))) {
        vlTOPp->_sequent__TOP__7(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__i2c_driver_top__DOT__end_flag 
        = vlTOPp->__VinpClk__TOP__i2c_driver_top__DOT__end_flag;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__i2c_driver_top__DOT__run_req 
        = vlTOPp->__VinpClk__TOP__i2c_driver_top__DOT__run_req;
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__i2c_driver_top__DOT__master_clk 
        = vlTOPp->__VinpClk__TOP__i2c_driver_top__DOT__master_clk;
    vlTOPp->__VinpClk__TOP__i2c_driver_top__DOT__end_flag 
        = vlTOPp->i2c_driver_top__DOT__end_flag;
    vlTOPp->__VinpClk__TOP__i2c_driver_top__DOT__run_req 
        = vlTOPp->i2c_driver_top__DOT__run_req;
    vlTOPp->__VinpClk__TOP__i2c_driver_top__DOT__master_clk 
        = vlTOPp->i2c_driver_top__DOT__master_clk;
}

VL_INLINE_OPT QData Vi2c_driver::_change_request(Vi2c_driver__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2c_driver::_change_request\n"); );
    Vi2c_driver* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vi2c_driver::_change_request_1(Vi2c_driver__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2c_driver::_change_request_1\n"); );
    Vi2c_driver* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    __req |= ((vlTOPp->i2c_driver_top__DOT__master_clk ^ vlTOPp->__Vchglast__TOP__i2c_driver_top__DOT__master_clk)
         | (vlTOPp->i2c_driver_top__DOT__run_req ^ vlTOPp->__Vchglast__TOP__i2c_driver_top__DOT__run_req)
         | (vlTOPp->i2c_driver_top__DOT__end_flag ^ vlTOPp->__Vchglast__TOP__i2c_driver_top__DOT__end_flag));
    VL_DEBUG_IF( if(__req && ((vlTOPp->i2c_driver_top__DOT__master_clk ^ vlTOPp->__Vchglast__TOP__i2c_driver_top__DOT__master_clk))) VL_DBG_MSGF("        CHANGE: i2c_driver_top.sv:11: i2c_driver_top.master_clk\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->i2c_driver_top__DOT__run_req ^ vlTOPp->__Vchglast__TOP__i2c_driver_top__DOT__run_req))) VL_DBG_MSGF("        CHANGE: i2c_driver_top.sv:23: i2c_driver_top.run_req\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->i2c_driver_top__DOT__end_flag ^ vlTOPp->__Vchglast__TOP__i2c_driver_top__DOT__end_flag))) VL_DBG_MSGF("        CHANGE: i2c_driver_top.sv:26: i2c_driver_top.end_flag\n"); );
    // Final
    vlTOPp->__Vchglast__TOP__i2c_driver_top__DOT__master_clk 
        = vlTOPp->i2c_driver_top__DOT__master_clk;
    vlTOPp->__Vchglast__TOP__i2c_driver_top__DOT__run_req 
        = vlTOPp->i2c_driver_top__DOT__run_req;
    vlTOPp->__Vchglast__TOP__i2c_driver_top__DOT__end_flag 
        = vlTOPp->i2c_driver_top__DOT__end_flag;
    return __req;
}

#ifdef VL_DEBUG
void Vi2c_driver::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2c_driver::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((SDA & 0xfeU))) {
        Verilated::overWidthError("SDA");}
}
#endif  // VL_DEBUG
