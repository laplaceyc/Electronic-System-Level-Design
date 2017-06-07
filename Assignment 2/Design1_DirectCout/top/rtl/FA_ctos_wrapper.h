// *****************************************************************************
//                         Cadence C-to-Silicon Compiler
//          Version 14.20-s400  (32 bit), build 84938 Mon, 27 Jun 2016
// 
// File created on Tue Jun  6 02:14:01 2017
// 
// The code contained herein is generated for Cadences customer and third
// parties authorized by customer.  It may be used in accordance with a
// previously executed license agreement between Cadence and that customer.
// Absolutely no disassembling, decompiling, reverse-translations or
// reverse-engineering of the generated code is allowed.
// 
//*****************************************************************************
#ifndef FA_ctos_wrapper_P
#define FA_ctos_wrapper_P

#include <systemc.h>

#define CTOS_TARGET_SUFFIX(ARG) CTOS_TARGET_SUFFIX_TMP(ARG)
#define CTOS_TARGET_SUFFIX_TMP(ARG) "_" #ARG


// This foreign module encapsulates the CtoS generated Verilog models
class FA_ctos_wrapper_vlog : public ncsc_foreign_module {
    SC_HAS_PROCESS(FA_ctos_wrapper_vlog);
  public:
    FA_ctos_wrapper_vlog(sc_module_name name, char  const *ctosModelSuffix)
    :   ncsc_foreign_module(name),
        A("A"),
        B("B"),
        Cin("Cin"),
        S("S"),
        Cout("Cout"),
        m_hdlName("FA")
    {
        m_hdlName+=ctosModelSuffix;
    }
    sc_in<sc_lv<1> >  A;
    sc_in<sc_lv<1> >  B;
    sc_in<sc_lv<1> >  Cin;
    sc_out<sc_lv<1> >  S;
    sc_out<sc_lv<1> >  Cout;
    std::string m_hdlName;
    char  const *hdl_name() const
    {
        return m_hdlName.c_str();
    }
};


// This is the main module for the verification wrapper
class FA_ctos_wrapper : public sc_module {
    SC_HAS_PROCESS(FA_ctos_wrapper);
  public:
    FA_ctos_wrapper(sc_module_name name, char  const *ctosDutSuffix = "", char  const *ctosRefSuffix = NULL, bool compare = false)
    :   sc_module(name),
        A("A"),
        B("B"),
        Cin("Cin"),
        S("S"),
        Cout("Cout"),
        m_enableCompare(true),
        A_vlog(NULL),
        B_vlog(NULL),
        Cin_vlog(NULL),
        S_vlog_dut(NULL),
        S_vlog_ref(NULL),
        S_cpp("S_cpp"),
        Cout_vlog_dut(NULL),
        Cout_vlog_ref(NULL),
        Cout_cpp("Cout_cpp"),
        m_ctos_compare(compare)
    {
        m_ctos_dut_type=modelTypeLookUp(ctosDutSuffix);
        m_ctos_ref_type=modelTypeLookUp(ctosRefSuffix);
        if (m_ctos_dut_type==ORIG) {
            m_dut_cpp=new FA("m_dut_cpp");
            m_dut_cpp->A(A);
            m_dut_cpp->B(B);
            m_dut_cpp->Cin(Cin);
            m_dut_cpp->S(S);
            m_dut_cpp->Cout(Cout);
            std::cout << "CtoS Verification Wrapper: Instantiating module FA as DUT" << std::endl;
        } else {
            m_dut_vlog=new FA_ctos_wrapper_vlog("m_dut_vlog", ctosDutSuffix);
            A_vlog=new sc_signal<sc_lv<1> > ("A_vlog");
            m_dut_vlog->A(*A_vlog);
            B_vlog=new sc_signal<sc_lv<1> > ("B_vlog");
            m_dut_vlog->B(*B_vlog);
            Cin_vlog=new sc_signal<sc_lv<1> > ("Cin_vlog");
            m_dut_vlog->Cin(*Cin_vlog);
            S_vlog_dut=new sc_signal<sc_lv<1> > ("S_vlog_dut");
            m_dut_vlog->S(*S_vlog_dut);
            Cout_vlog_dut=new sc_signal<sc_lv<1> > ("Cout_vlog_dut");
            m_dut_vlog->Cout(*Cout_vlog_dut);
            std::cout << "CtoS Verification Wrapper: Instantiating module " << m_dut_vlog->hdl_name() << " as DUT" << std::endl;
        }
        if (m_ctos_ref_type!=UNKNOWN) {
            if (m_ctos_ref_type==ORIG) {
                m_ref_cpp=new FA("m_ref_cpp");
                m_ref_cpp->A(A);
                m_ref_cpp->B(B);
                m_ref_cpp->Cin(Cin);
                m_ref_cpp->S(S_cpp);
                m_ref_cpp->Cout(Cout_cpp);
                std::cout << "CtoS Verification Wrapper: Instantiating module FA as REF" << std::endl;
            } else {
                m_ref_vlog=new FA_ctos_wrapper_vlog("m_ref_vlog", ctosRefSuffix);
                if (A_vlog==NULL) {
                    A_vlog=new sc_signal<sc_lv<1> > ("A_vlog");
                }
                m_ref_vlog->A(*A_vlog);
                if (B_vlog==NULL) {
                    B_vlog=new sc_signal<sc_lv<1> > ("B_vlog");
                }
                m_ref_vlog->B(*B_vlog);
                if (Cin_vlog==NULL) {
                    Cin_vlog=new sc_signal<sc_lv<1> > ("Cin_vlog");
                }
                m_ref_vlog->Cin(*Cin_vlog);
                if (S_vlog_ref==NULL) {
                    S_vlog_ref=new sc_signal<sc_lv<1> > ("S_vlog_ref");
                }
                m_ref_vlog->S(*S_vlog_ref);
                if (Cout_vlog_ref==NULL) {
                    Cout_vlog_ref=new sc_signal<sc_lv<1> > ("Cout_vlog_ref");
                }
                m_ref_vlog->Cout(*Cout_vlog_ref);
                std::cout << "CtoS Verification Wrapper: Instantiating module " << m_ref_vlog->hdl_name() << " as REF" << std::endl;
            }
        }
        if ((((unsigned int)m_ctos_dut_type)>1U)||((m_ctos_ref_type!=UNKNOWN)&&(((unsigned int)m_ctos_ref_type)>1U))) {
            SC_METHOD(ctos_convert_input);
            sensitive << A;
            SC_METHOD(ctos_convert_input_0);
            sensitive << B;
            SC_METHOD(ctos_convert_input_1);
            sensitive << Cin;
            if (S_vlog_dut!=NULL) {
                SC_METHOD(ctos_convert_output);
                dont_initialize();
                sensitive << *S_vlog_dut;
            }
            if (Cout_vlog_dut!=NULL) {
                SC_METHOD(ctos_convert_output_0);
                dont_initialize();
                sensitive << *Cout_vlog_dut;
            }
        }
        if ((m_ctos_ref_type!=UNKNOWN)&&m_ctos_compare) {
            SC_METHOD(ctos_compare_outputs);
            dont_initialize();
            sensitive << S;
            SC_METHOD(ctos_compare_outputs_0);
            dont_initialize();
            sensitive << Cout;
        }
    }
    sc_in<bool>  A;
    sc_in<bool>  B;
    sc_in<bool>  Cin;
    sc_out<bool>  S;
    sc_out<bool>  Cout;
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

    sc_signal<sc_lv<1> >  *A_vlog;
    sc_signal<sc_lv<1> >  *B_vlog;
    sc_signal<sc_lv<1> >  *Cin_vlog;
    sc_signal<sc_lv<1> >  *S_vlog_dut;
    sc_signal<sc_lv<1> >  *S_vlog_ref;
    sc_signal<bool>  S_cpp;
    sc_signal<sc_lv<1> >  *Cout_vlog_dut;
    sc_signal<sc_lv<1> >  *Cout_vlog_ref;
    sc_signal<bool>  Cout_cpp;
    ModelTypeEnum m_ctos_dut_type;
    ModelTypeEnum m_ctos_ref_type;
    bool m_ctos_compare;
    
    union {
      public:
        FA *m_ref_cpp;
        FA_ctos_wrapper_vlog *m_ref_vlog;
    };

    
    union {
      public:
        FA *m_dut_cpp;
        FA_ctos_wrapper_vlog *m_dut_vlog;
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
        *A_vlog=sc_lv<1> ((A.read()));
    }
    void ctos_convert_input_0()
    {
        *B_vlog=sc_lv<1> ((B.read()));
    }
    void ctos_convert_input_1()
    {
        *Cin_vlog=sc_lv<1> ((Cin.read()));
    }
    void ctos_convert_output()
    {
        S=S_vlog_dut->read().to_uint();
    }
    void ctos_convert_output_0()
    {
        Cout=Cout_vlog_dut->read().to_uint();
    }
    void ctos_compare_outputs()
    {}
    void ctos_compare_outputs_0()
    {}
  public:
    // Use this constructor only if your CtoS verilog model has no suffix
    FA_ctos_wrapper(sc_module_name name, SimulateRTLOnlyEnum simulateRTLOnly)
    :   sc_module(name),
        A("A"),
        B("B"),
        Cin("Cin"),
        S("S"),
        Cout("Cout"),
        m_enableCompare(false),
        m_ctos_compare(false)
    {
        m_ctos_dut_type=VLOG;
        m_ctos_ref_type=UNKNOWN;
        m_dut_vlog=new FA_ctos_wrapper_vlog("m_dut_vlog", "");
        A_vlog=new sc_signal<sc_lv<1> > ("A_vlog");
        m_dut_vlog->A(*A_vlog);
        B_vlog=new sc_signal<sc_lv<1> > ("B_vlog");
        m_dut_vlog->B(*B_vlog);
        Cin_vlog=new sc_signal<sc_lv<1> > ("Cin_vlog");
        m_dut_vlog->Cin(*Cin_vlog);
        S_vlog_dut=new sc_signal<sc_lv<1> > ("S_vlog_dut");
        m_dut_vlog->S(*S_vlog_dut);
        Cout_vlog_dut=new sc_signal<sc_lv<1> > ("Cout_vlog_dut");
        m_dut_vlog->Cout(*Cout_vlog_dut);
        std::cout << "CtoS Verification Wrapper: Instantiating RTL module " << m_dut_vlog->hdl_name() << " as DUT" << std::endl;
        SC_METHOD(ctos_convert_input);
        sensitive << A;
        SC_METHOD(ctos_convert_input_0);
        sensitive << B;
        SC_METHOD(ctos_convert_input_1);
        sensitive << Cin;
        SC_METHOD(ctos_convert_output);
        dont_initialize();
        sensitive << *S_vlog_dut;
        SC_METHOD(ctos_convert_output_0);
        dont_initialize();
        sensitive << *Cout_vlog_dut;
    }
};




    typedef FA_ctos_wrapper FA_ctos;
  #define FA_CTOS_INSTANCE(INSTNAME) FA_ctos(INSTNAME, CTOS_TARGET_SUFFIX(CTOS_MODEL), NULL, false)
  #define FA_CTOS_COMPARE_INSTANCE(INSTNAME, REFNAME) FA_ctos(INSTNAME, CTOS_TARGET_SUFFIX(CTOS_MODEL), REFNAME, true)
  #define FA_CTOS_RTL_ONLY_INSTANCE(INSTNAME) FA_ctos(INSTNAME, FA_ctos::SimulateRTLOnly)
#endif // ifdef FA_ctos_wrapper_P

