// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VI2C_DRIVER_H_
#define _VI2C_DRIVER_H_  // guard

#include "verilated.h"

//==========

class Vi2c_driver__Syms;
class Vi2c_driver_VerilatedVcd;


//----------

VL_MODULE(Vi2c_driver) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_OUT8(SCL,0,0);
    VL_INOUT8(SDA,0,0);
    VL_OUT8(received_data[8],7,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*0:0*/ i2c_driver_top__DOT__master_clk;
    CData/*0:0*/ i2c_driver_top__DOT__run_req;
    CData/*0:0*/ i2c_driver_top__DOT__end_flag;
    CData/*1:0*/ i2c_driver_top__DOT__clk_cnt;
    CData/*0:0*/ i2c_driver_top__DOT__r_en;
    CData/*7:0*/ i2c_driver_top__DOT__i_reg_addr;
    CData/*7:0*/ i2c_driver_top__DOT__send_data;
    CData/*1:0*/ i2c_driver_top__DOT__cnt;
    CData/*0:0*/ i2c_driver_top__DOT__i2c_driver__DOT__run_flag;
    CData/*2:0*/ i2c_driver_top__DOT__i2c_driver__DOT__ABCD_cnt;
    CData/*3:0*/ i2c_driver_top__DOT__i2c_driver__DOT__state;
    CData/*3:0*/ i2c_driver_top__DOT__i2c_driver__DOT__pstate;
    CData/*2:0*/ i2c_driver_top__DOT__i2c_driver__DOT__data_index;
    CData/*7:0*/ i2c_driver_top__DOT__i2c_driver__DOT__slave_addr_w;
    CData/*7:0*/ i2c_driver_top__DOT__i2c_driver__DOT__slave_addr_r;
    CData/*0:0*/ i2c_driver_top__DOT__i2c_driver__DOT__ack_flag;
    CData/*0:0*/ i2c_driver_top__DOT__i2c_driver__DOT__SDA_buf;
    CData/*0:0*/ i2c_driver_top__DOT__i2c_driver__DOT__SDA_en;
    CData/*2:0*/ i2c_driver_top__DOT__i2c_driver__DOT__data_cnt;
    IData/*26:0*/ i2c_driver_top__DOT__i2c_driver__DOT__input_buf;
    CData/*7:0*/ i2c_driver_top__DOT__addrs[3];
    CData/*7:0*/ i2c_driver_top__DOT__send_datas[3];
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vdly__i2c_driver_top__DOT__end_flag;
    CData/*0:0*/ __VinpClk__TOP__i2c_driver_top__DOT__end_flag;
    CData/*0:0*/ __VinpClk__TOP__i2c_driver_top__DOT__run_req;
    CData/*0:0*/ __VinpClk__TOP__i2c_driver_top__DOT__master_clk;
    CData/*0:0*/ __Vclklast__TOP____VinpClk__TOP__i2c_driver_top__DOT__end_flag;
    CData/*0:0*/ __Vclklast__TOP____VinpClk__TOP__i2c_driver_top__DOT__run_req;
    CData/*0:0*/ __Vclklast__TOP__clk;
    CData/*0:0*/ __Vclklast__TOP____VinpClk__TOP__i2c_driver_top__DOT__master_clk;
    CData/*0:0*/ __Vchglast__TOP__i2c_driver_top__DOT__master_clk;
    CData/*0:0*/ __Vchglast__TOP__i2c_driver_top__DOT__run_req;
    CData/*0:0*/ __Vchglast__TOP__i2c_driver_top__DOT__end_flag;
    CData/*7:0*/ i2c_driver_top__DOT____Vcellout__i2c_driver__received_data[8];
    CData/*0:0*/ __Vm_traceActivity[2];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vi2c_driver__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vi2c_driver);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vi2c_driver(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vi2c_driver();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vi2c_driver__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vi2c_driver__Syms* symsp, bool first);
  private:
    static QData _change_request(Vi2c_driver__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vi2c_driver__Syms* __restrict vlSymsp);
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vi2c_driver__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vi2c_driver__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vi2c_driver__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__1(Vi2c_driver__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__3(Vi2c_driver__Syms* __restrict vlSymsp);
    static void _sequent__TOP__5(Vi2c_driver__Syms* __restrict vlSymsp);
    static void _sequent__TOP__6(Vi2c_driver__Syms* __restrict vlSymsp);
    static void _sequent__TOP__7(Vi2c_driver__Syms* __restrict vlSymsp);
    static void _settle__TOP__4(Vi2c_driver__Syms* __restrict vlSymsp) VL_ATTR_COLD;
  private:
    static void traceChgSub0(void* userp, VerilatedVcd* tracep);
    static void traceChgTop0(void* userp, VerilatedVcd* tracep);
    static void traceCleanup(void* userp, VerilatedVcd* /*unused*/);
    static void traceFullSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceFullTop0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitTop(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    void traceRegister(VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
