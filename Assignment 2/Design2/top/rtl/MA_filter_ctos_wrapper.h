// *****************************************************************************
//                         Cadence C-to-Silicon Compiler
//          Version 14.20-s400  (32 bit), build 84938 Mon, 27 Jun 2016
// 
// File created on Tue Jun  6 05:21:39 2017
// 
// The code contained herein is generated for Cadences customer and third
// parties authorized by customer.  It may be used in accordance with a
// previously executed license agreement between Cadence and that customer.
// Absolutely no disassembling, decompiling, reverse-translations or
// reverse-engineering of the generated code is allowed.
// 
//*****************************************************************************
#ifndef MA_filter_ctos_wrapper_P
#define MA_filter_ctos_wrapper_P

#include <systemc.h>

#define CTOS_TARGET_SUFFIX(ARG) CTOS_TARGET_SUFFIX_TMP(ARG)
#define CTOS_TARGET_SUFFIX_TMP(ARG) "_" #ARG


// This foreign module encapsulates the CtoS generated Verilog models
class MA_filter_ctos_wrapper_vlog : public ncsc_foreign_module {
    SC_HAS_PROCESS(MA_filter_ctos_wrapper_vlog);
  public:
    MA_filter_ctos_wrapper_vlog(sc_module_name name, char  const *ctosModelSuffix)
    :   ncsc_foreign_module(name),
        input_("input_"),
        rst("rst"),
        clk("clk"),
        output_("output_"),
        m_hdlName("MA_filter")
    {
        m_hdlName+=ctosModelSuffix;
    }
    sc_in<sc_lv<32> >  input_;
    sc_in<bool>  rst;
    sc_in<bool>  clk;
    sc_out<sc_lv<32> >  output_;
    std::string m_hdlName;
    char  const *hdl_name() const
    {
        return m_hdlName.c_str();
    }
};


// This is the main module for the verification wrapper
class MA_filter_ctos_wrapper : public sc_module {
    SC_HAS_PROCESS(MA_filter_ctos_wrapper);
  public:
    MA_filter_ctos_wrapper(sc_module_name name, char  const *ctosDutSuffix = "", char  const *ctosRefSuffix = NULL, bool compare = false)
    :   sc_module(name),
        input("input"),
        rst("rst"),
        clk("clk"),
        output("output"),
        m_enableCompare(true),
        input_vlog(NULL),
        output_vlog_dut(NULL),
        output_vlog_ref(NULL),
        output_cpp("output_cpp"),
        m_ctos_compare(compare)
    {
        m_ctos_dut_type=modelTypeLookUp(ctosDutSuffix);
        m_ctos_ref_type=modelTypeLookUp(ctosRefSuffix);
        if (m_ctos_dut_type==ORIG) {
            m_dut_cpp=new MA_filter("m_dut_cpp");
            m_dut_cpp->input(input);
            m_dut_cpp->rst(rst);
            m_dut_cpp->clk(clk);
            m_dut_cpp->output(output);
            std::cout << "CtoS Verification Wrapper: Instantiating module MA_filter as DUT" << std::endl;
        } else {
            m_dut_vlog=new MA_filter_ctos_wrapper_vlog("m_dut_vlog", ctosDutSuffix);
            input_vlog=new sc_signal<sc_lv<32> > ("input_vlog");
            m_dut_vlog->input_(*input_vlog);
            m_dut_vlog->rst(rst);
            m_dut_vlog->clk(clk);
            output_vlog_dut=new sc_signal<sc_lv<32> > ("output_vlog_dut");
            m_dut_vlog->output_(*output_vlog_dut);
            std::cout << "CtoS Verification Wrapper: Instantiating module " << m_dut_vlog->hdl_name() << " as DUT" << std::endl;
        }
        if (m_ctos_ref_type!=UNKNOWN) {
            if (m_ctos_ref_type==ORIG) {
                m_ref_cpp=new MA_filter("m_ref_cpp");
                m_ref_cpp->input(input);
                m_ref_cpp->rst(rst);
                m_ref_cpp->clk(clk);
                m_ref_cpp->output(output_cpp);
                std::cout << "CtoS Verification Wrapper: Instantiating module MA_filter as REF" << std::endl;
            } else {
                m_ref_vlog=new MA_filter_ctos_wrapper_vlog("m_ref_vlog", ctosRefSuffix);
                if (input_vlog==NULL) {
                    input_vlog=new sc_signal<sc_lv<32> > ("input_vlog");
                }
                m_ref_vlog->input_(*input_vlog);
                m_ref_vlog->rst(rst);
                m_ref_vlog->clk(clk);
                if (output_vlog_ref==NULL) {
                    output_vlog_ref=new sc_signal<sc_lv<32> > ("output_vlog_ref");
                }
                m_ref_vlog->output_(*output_vlog_ref);
                std::cout << "CtoS Verification Wrapper: Instantiating module " << m_ref_vlog->hdl_name() << " as REF" << std::endl;
            }
        }
        if ((((unsigned int)m_ctos_dut_type)>1U)||((m_ctos_ref_type!=UNKNOWN)&&(((unsigned int)m_ctos_ref_type)>1U))) {
            SC_METHOD(ctos_convert_input);
            sensitive << input;
            if (output_vlog_dut!=NULL) {
                SC_METHOD(ctos_convert_output);
                dont_initialize();
                sensitive << *output_vlog_dut;
            }
        }
        if ((m_ctos_ref_type!=UNKNOWN)&&m_ctos_compare) {
            SC_METHOD(ctos_compare_outputs);
            dont_initialize();
            sensitive << clk.neg();
        }
    }
    sc_in<sc_uint<32> >  input;
    // reset rst true
    sc_in<bool>  rst;
    // clock clk period 20000 rise 0 fall 10000
    sc_in<bool>  clk;
    sc_out<sc_uint<32> >  output;
    sc_event m_ctosWrapperError;
    bool m_enableCompare;
    
    enum SimulateRTLOnlyEnum {
        Unsupported = 0,
        SimulateRTLOnly = 1
    };

  private:
    
    enum ModelTypeEnum {
        ORIG = 0,
        VLOG = 2,
        UNKNOWN = 3
    };

    sc_signal<sc_lv<32> >  *input_vlog;
    sc_signal<sc_lv<32> >  *output_vlog_dut;
    sc_signal<sc_lv<32> >  *output_vlog_ref;
    sc_signal<sc_uint<32> >  output_cpp;
    ModelTypeEnum m_ctos_dut_type;
    ModelTypeEnum m_ctos_ref_type;
    bool m_ctos_compare;
    
    union {
      public:
        MA_filter *m_ref_cpp;
        MA_filter_ctos_wrapper_vlog *m_ref_vlog;
    };

    
    union {
      public:
        MA_filter *m_dut_cpp;
        MA_filter_ctos_wrapper_vlog *m_dut_vlog;
    };

    // Converts input string to enumeration
    ModelTypeEnum modelTypeLookUp(char  const *str)
    {
        if (!str) {
            return UNKNOWN;
        }
        std::string inputString = str;
        if (inputString.empty()) {
            return ORIG;
        } else {
            return VLOG;
        }
    }
    
    template <class T, class U> 
    bool ctos_check_unknown_values(T  const *dutSig, U  const &refSig, std::string  const &dutName, std::string  const &refName)
    {
        if (!(dutSig->read().is_01())) {
            std::cout << sc_time_stamp()
            	      << ": ctos_check_unknown_values encountered unknown values!"
            	      << std::endl << dutName << ": " << (dutSig->read().to_string())
            	      << std::endl << refName << ": " << refSig << std::endl;
        }
        return true;
    }
    
    template <class T> 
    void ctos_compare_output_values(T  const &dutSig, T  const &refSig, std::string  const &dutName, std::string  const &refName)
    {
        if (!(dutSig==refSig)) {
            std::cout << sc_time_stamp()
            	      << ": ctos_compare_output_values mismatch!"
            	      << std::endl << dutName << ": " << dutSig
            	      << std::endl << refName << ": " << refSig << std::endl;
            m_ctosWrapperError.notify();
        }
    }
    void ctos_convert_input()
    {
        *input_vlog=sc_lv<32> ((input.read()));
    }
    void ctos_convert_output()
    {
        output=sc_uint<32>(output_vlog_dut->read());
    }
    void ctos_compare_outputs()
    {
        if ((rst.read()!=1U)&&m_enableCompare) {
            sc_uint<32> output_ref;
            sc_uint<32> output_dut;
            output_dut=output->read();
            if (m_ctos_ref_type==ORIG) {
                output_ref=output_cpp.read();
            } else {
                output_ref=sc_uint<32>(output_vlog_ref->read());
                ctos_check_unknown_values(output_vlog_ref, output_ref, "output_vlog_ref", "output_ref");
            }
            if (m_ctos_dut_type==VLOG) {
                ctos_check_unknown_values(output_vlog_dut, output_ref, "output_vlog_dut", "output_ref");
            }
            ctos_compare_output_values(output_dut, output_ref, "output_dut", "output_ref");
        }
    }
  public:
    // Use this constructor only if your CtoS verilog model has no suffix
    MA_filter_ctos_wrapper(sc_module_name name, SimulateRTLOnlyEnum simulateRTLOnly)
    :   sc_module(name),
        input("input"),
        rst("rst"),
        clk("clk"),
        output("output"),
        m_enableCompare(false),
        m_ctos_compare(false)
    {
        m_ctos_dut_type=VLOG;
        m_ctos_ref_type=UNKNOWN;
        m_dut_vlog=new MA_filter_ctos_wrapper_vlog("m_dut_vlog", "");
        input_vlog=new sc_signal<sc_lv<32> > ("input_vlog");
        m_dut_vlog->input_(*input_vlog);
        m_dut_vlog->rst(rst);
        m_dut_vlog->clk(clk);
        output_vlog_dut=new sc_signal<sc_lv<32> > ("output_vlog_dut");
        m_dut_vlog->output_(*output_vlog_dut);
        std::cout << "CtoS Verification Wrapper: Instantiating RTL module " << m_dut_vlog->hdl_name() << " as DUT" << std::endl;
        SC_METHOD(ctos_convert_input);
        sensitive << input;
        SC_METHOD(ctos_convert_output);
        dont_initialize();
        sensitive << *output_vlog_dut;
    }
};




    typedef MA_filter_ctos_wrapper MA_filter_ctos;
  #define MA_FILTER_CTOS_INSTANCE(INSTNAME) MA_filter_ctos(INSTNAME, CTOS_TARGET_SUFFIX(CTOS_MODEL), NULL, false)
  #define MA_FILTER_CTOS_COMPARE_INSTANCE(INSTNAME, REFNAME) MA_filter_ctos(INSTNAME, CTOS_TARGET_SUFFIX(CTOS_MODEL), REFNAME, true)
  #define MA_FILTER_CTOS_RTL_ONLY_INSTANCE(INSTNAME) MA_filter_ctos(INSTNAME, MA_filter_ctos::SimulateRTLOnly)
#endif // ifdef MA_filter_ctos_wrapper_P

