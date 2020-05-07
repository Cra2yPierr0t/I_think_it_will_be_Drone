// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vacc_driver.h for the primary calling header

#include "Vacc_driver.h"
#include "Vacc_driver__Syms.h"

//==========

VL_CTOR_IMP(Vacc_driver) {
    Vacc_driver__Syms* __restrict vlSymsp = __VlSymsp = new Vacc_driver__Syms(this, name());
    Vacc_driver* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vacc_driver::__Vconfigure(Vacc_driver__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vacc_driver::~Vacc_driver() {
    delete __VlSymsp; __VlSymsp=NULL;
}

void Vacc_driver::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vacc_driver::eval\n"); );
    Vacc_driver__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vacc_driver* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
#ifdef VM_TRACE
    // Tracing
#endif  // VM_TRACE
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
            VL_FATAL_MT("acc_driver.sv", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vacc_driver::_eval_initial_loop(Vacc_driver__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("acc_driver.sv", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vacc_driver::_initial__TOP__1(Vacc_driver__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vacc_driver::_initial__TOP__1\n"); );
    Vacc_driver* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->SDA = 0U;
    vlTOPp->acc_driver__DOT__clk_cnt = 0U;
    vlTOPp->acc_driver__DOT__clk400K = 0U;
}

VL_INLINE_OPT void Vacc_driver::_sequent__TOP__2(Vacc_driver__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vacc_driver::_sequent__TOP__2\n"); );
    Vacc_driver* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((0xeU == (IData)(vlTOPp->acc_driver__DOT__clk_cnt))) {
        vlTOPp->acc_driver__DOT__clk400K = (1U & (~ (IData)(vlTOPp->acc_driver__DOT__clk400K)));
        vlTOPp->acc_driver__DOT__clk_cnt = 0U;
    } else {
        vlTOPp->acc_driver__DOT__clk_cnt = (0x3fU & 
                                            ((IData)(1U) 
                                             + (IData)(vlTOPp->acc_driver__DOT__clk_cnt)));
    }
    vlTOPp->SCL = vlTOPp->acc_driver__DOT__clk400K;
}

void Vacc_driver::_settle__TOP__3(Vacc_driver__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vacc_driver::_settle__TOP__3\n"); );
    Vacc_driver* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->SCL = vlTOPp->acc_driver__DOT__clk400K;
}

void Vacc_driver::_eval(Vacc_driver__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vacc_driver::_eval\n"); );
    Vacc_driver* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk12M) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk12M)))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
        vlTOPp->__Vm_traceActivity = (2U | vlTOPp->__Vm_traceActivity);
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk12M = vlTOPp->clk12M;
}

void Vacc_driver::_eval_initial(Vacc_driver__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vacc_driver::_eval_initial\n"); );
    Vacc_driver* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vm_traceActivity = (1U | vlTOPp->__Vm_traceActivity);
    vlTOPp->__Vclklast__TOP__clk12M = vlTOPp->clk12M;
}

void Vacc_driver::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vacc_driver::final\n"); );
    // Variables
    Vacc_driver__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vacc_driver* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vacc_driver::_eval_settle(Vacc_driver__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vacc_driver::_eval_settle\n"); );
    Vacc_driver* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__3(vlSymsp);
}

VL_INLINE_OPT QData Vacc_driver::_change_request(Vacc_driver__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vacc_driver::_change_request\n"); );
    Vacc_driver* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vacc_driver::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vacc_driver::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk12M & 0xfeU))) {
        Verilated::overWidthError("clk12M");}
    if (VL_UNLIKELY((SDA & 0xfeU))) {
        Verilated::overWidthError("SDA");}
}
#endif  // VL_DEBUG

void Vacc_driver::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vacc_driver::_ctor_var_reset\n"); );
    // Body
    clk12M = VL_RAND_RESET_I(1);
    SDA = VL_RAND_RESET_I(1);
    SCL = VL_RAND_RESET_I(1);
    acc_driver__DOT__clk400K = VL_RAND_RESET_I(1);
    acc_driver__DOT__clk_cnt = VL_RAND_RESET_I(6);
    __Vm_traceActivity = 0;
}
