# THIS FILE IS AUTOMATICALLY GENERATED
# Project: C:\Users\214016586\Documents\GitHub\PSoC_TIA\TIA\TIA.cydsn\TIA.cyprj
# Date: Tue, 25 Jul 2017 13:58:58 GMT
#set_units -time ns
create_clock -name {ADC_SAR_Seq_1_intClock(FFB)} -period 250 -waveform {0 125} [list [get_pins {ClockBlock/ff_div_7}]]
create_clock -name {CyRouted1} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/dsi_in_0}]]
create_clock -name {CyILO} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/ilo}]]
create_clock -name {CyLFCLK} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/lfclk}]]
create_clock -name {CyIMO} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyHFCLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/hfclk}]]
create_clock -name {CySYSCLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/sysclk}]]
create_generated_clock -name {ADC_SAR_Seq_1_intClock} -source [get_pins {ClockBlock/hfclk}] -edges {1 7 13} [list]
create_generated_clock -name {Clock_2} -source [get_pins {ClockBlock/hfclk}] -edges {1 801 1599} -nominal_period 33333.333333333328 [list [get_pins {ClockBlock/udb_div_0}]]


# Component constraints for C:\Users\214016586\Documents\GitHub\PSoC_TIA\TIA\TIA.cydsn\TopDesign\TopDesign.cysch
# Project: C:\Users\214016586\Documents\GitHub\PSoC_TIA\TIA\TIA.cydsn\TIA.cyprj
# Date: Tue, 25 Jul 2017 13:58:53 GMT
