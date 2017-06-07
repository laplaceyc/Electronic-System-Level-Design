# *****************************************************************************
#                         Cadence C-to-Silicon Compiler
#           Version 14.20-p100  (32 bit), build 80582 Tue, 02 Dec 2014
# 
# File created on Tue Feb 23 15:33:16 2016
# 
# The code contained herein is generated for Cadences customer and third
# parties authorized by customer.  It may be used in accordance with a
# previously executed license agreement between Cadence and that customer.
# Absolutely no disassembling, decompiling, reverse-translations or
# reverse-engineering of the generated code is allowed.
# 
# ******************************************************************************
if {[get_design] != ""} {
    close_design
}

new_design FullAdder
set_attr design_dir "top" [get_design]
set_attr auto_write_models "true" [get_design]
set_attr source_files [list FA.cpp HA.cpp main.cpp] [get_design]
set_attr header_files [list FA.h HA.h] [get_design]
set_attr compile_flags " -w" [get_design]
set_attr top_module_path "FA" [get_design]
set_attr rc_work_dir rc_work [get_design]
set_attr tech_lib_names [list tutorial.lib] [get_design]

#define_clock -name clk -period 20000 -rise 0 -fall 10000

define_sim_config -model_dir "top/rtl" [get_design]

build
schedule -passes 200 [get_design]/modules/FA
allocate_registers 
write_rtl -dir top/rtl [get_design]/modules/FA
save_design [get_design]
close_design [get_design]

