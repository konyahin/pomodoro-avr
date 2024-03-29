EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L MCU_Microchip_ATtiny:ATtiny45-20PU U1
U 1 1 62586CA3
P 3650 3750
F 0 "U1" H 3121 3796 50  0000 R CNN
F 1 "ATtiny45-20PU" H 3121 3705 50  0000 R CNN
F 2 "Package_DIP:DIP-8_W7.62mm" H 3650 3750 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/atmel-2586-avr-8-bit-microcontroller-attiny25-attiny45-attiny85_datasheet.pdf" H 3650 3750 50  0001 C CNN
	1    3650 3750
	1    0    0    -1  
$EndComp
$Comp
L Device:Battery_Cell BT1
U 1 1 62587AAF
P 3650 2850
F 0 "BT1" H 3532 2854 50  0000 R CNN
F 1 "3V" H 3532 2945 50  0000 R CNN
F 2 "Battery:BatteryHolder_Keystone_103_1x20mm" V 3650 2910 50  0001 C CNN
F 3 "~" V 3650 2910 50  0001 C CNN
	1    3650 2850
	-1   0    0    1   
$EndComp
$Comp
L agg-kicad:C C1
U 1 1 6258819D
P 3450 3100
F 0 "C1" H 3500 3200 50  0000 C CNN
F 1 "100n" H 3450 3000 50  0000 C CNN
F 2 "Capacitor_THT:C_Rect_L7.0mm_W2.0mm_P5.00mm" H 3450 3100 50  0001 C CNN
F 3 "" H 3450 3100 50  0001 C CNN
	1    3450 3100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR01
U 1 1 62588D7C
P 3450 3100
F 0 "#PWR01" H 3450 2850 50  0001 C CNN
F 1 "GND" V 3455 2972 50  0000 R CNN
F 2 "" H 3450 3100 50  0001 C CNN
F 3 "" H 3450 3100 50  0001 C CNN
	1    3450 3100
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR03
U 1 1 62588F82
P 3650 4350
F 0 "#PWR03" H 3650 4100 50  0001 C CNN
F 1 "GND" H 3655 4177 50  0000 C CNN
F 2 "" H 3650 4350 50  0001 C CNN
F 3 "" H 3650 4350 50  0001 C CNN
	1    3650 4350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR02
U 1 1 62589D70
P 3650 2750
F 0 "#PWR02" H 3650 2500 50  0001 C CNN
F 1 "GND" H 3655 2577 50  0000 C CNN
F 2 "" H 3650 2750 50  0001 C CNN
F 3 "" H 3650 2750 50  0001 C CNN
	1    3650 2750
	-1   0    0    1   
$EndComp
$Comp
L agg-kicad:LED D2
U 1 1 6258B184
P 4850 4100
F 0 "D2" H 4850 4200 50  0000 C BNN
F 1 "GREEN" H 4800 4300 50  0000 C CNN
F 2 "Diode_THT:D_DO-15_P2.54mm_Vertical_AnodeUp" H 4850 4100 50  0001 C CNN
F 3 "" H 4850 4100 50  0001 C CNN
	1    4850 4100
	-1   0    0    1   
$EndComp
$Comp
L agg-kicad:LED D1
U 1 1 6258B581
P 4850 3750
F 0 "D1" H 4900 3850 50  0000 C BNN
F 1 "RED" H 4900 3950 50  0000 C CNN
F 2 "Diode_THT:D_DO-15_P2.54mm_Vertical_AnodeUp" H 4850 3750 50  0001 C CNN
F 3 "" H 4850 3750 50  0001 C CNN
	1    4850 3750
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR08
U 1 1 6258BEF8
P 4900 3750
F 0 "#PWR08" H 4900 3500 50  0001 C CNN
F 1 "GND" V 4905 3622 50  0000 R CNN
F 2 "" H 4900 3750 50  0001 C CNN
F 3 "" H 4900 3750 50  0001 C CNN
	1    4900 3750
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR09
U 1 1 6258C1E8
P 4850 4100
F 0 "#PWR09" H 4850 3850 50  0001 C CNN
F 1 "GND" V 4855 3972 50  0000 R CNN
F 2 "" H 4850 4100 50  0001 C CNN
F 3 "" H 4850 4100 50  0001 C CNN
	1    4850 4100
	0    -1   -1   0   
$EndComp
NoConn ~ 4250 3550
$Comp
L agg-kicad:SWITCH_SPST SW1
U 1 1 6258EB83
P 4650 3400
F 0 "SW1" H 4650 3655 50  0000 C CNN
F 1 "SWITCH" H 4650 3564 50  0000 C CNN
F 2 "kon4ru:SW_PUSH_7.5mm" H 4650 3400 50  0001 C CNN
F 3 "" H 4650 3400 50  0001 C CNN
	1    4650 3400
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR06
U 1 1 6258F1B5
P 4800 3400
F 0 "#PWR06" H 4800 3150 50  0001 C CNN
F 1 "GND" V 4805 3272 50  0000 R CNN
F 2 "" H 4800 3400 50  0001 C CNN
F 3 "" H 4800 3400 50  0001 C CNN
	1    4800 3400
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4750 3400 4800 3400
$Comp
L agg-kicad:SOUNDER LS1
U 1 1 62590026
P 4250 3200
F 0 "LS1" H 4250 3410 50  0000 C CNN
F 1 "BUZZER" H 4250 3319 50  0000 C CNN
F 2 "Buzzer_Beeper:Buzzer_D14mm_H7mm_P10mm" H 4250 3220 50  0001 C CNN
F 3 "" H 4250 3220 50  0001 C CNN
	1    4250 3200
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR04
U 1 1 625903E1
P 4250 3100
F 0 "#PWR04" H 4250 2850 50  0001 C CNN
F 1 "GND" V 4255 2972 50  0000 R CNN
F 2 "" H 4250 3100 50  0001 C CNN
F 3 "" H 4250 3100 50  0001 C CNN
	1    4250 3100
	-1   0    0    1   
$EndComp
Wire Wire Line
	3650 3150 3650 3100
Wire Wire Line
	3550 3100 3650 3100
Connection ~ 3650 3100
Wire Wire Line
	3650 3100 3650 3050
$Comp
L Device:R R4
U 1 1 625E7D85
P 4600 4100
F 0 "R4" V 4700 4050 50  0000 C CNN
F 1 "220" V 4700 4200 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0414_L11.9mm_D4.5mm_P7.62mm_Vertical" V 4530 4100 50  0001 C CNN
F 3 "~" H 4600 4100 50  0001 C CNN
	1    4600 4100
	0    1    1    0   
$EndComp
$Comp
L Device:R R3
U 1 1 625E8C23
P 4500 3750
F 0 "R3" V 4400 3800 50  0000 C CNN
F 1 "220" V 4400 3650 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0414_L11.9mm_D4.5mm_P7.62mm_Vertical" V 4430 3750 50  0001 C CNN
F 3 "~" H 4500 3750 50  0001 C CNN
	1    4500 3750
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R1
U 1 1 625E8DD1
P 4250 4100
F 0 "R1" H 4320 4146 50  0000 L CNN
F 1 "10K" H 4320 4055 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0414_L11.9mm_D4.5mm_P7.62mm_Vertical" V 4180 4100 50  0001 C CNN
F 3 "~" H 4250 4100 50  0001 C CNN
	1    4250 4100
	1    0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 625E8FAA
P 4650 3550
F 0 "R2" V 4550 3550 50  0000 L CNN
F 1 "10K" V 4550 3450 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0414_L11.9mm_D4.5mm_P7.62mm_Vertical" V 4580 3550 50  0001 C CNN
F 3 "~" H 4650 3550 50  0001 C CNN
	1    4650 3550
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4450 4100 4450 3850
Wire Wire Line
	4450 3850 4250 3850
Wire Wire Line
	4250 3450 4250 3300
$Comp
L power:VCC #PWR05
U 1 1 626048D2
P 4250 4250
F 0 "#PWR05" H 4250 4100 50  0001 C CNN
F 1 "VCC" H 4265 4423 50  0000 C CNN
F 2 "" H 4250 4250 50  0001 C CNN
F 3 "" H 4250 4250 50  0001 C CNN
	1    4250 4250
	-1   0    0    1   
$EndComp
$Comp
L power:VCC #PWR07
U 1 1 62604A66
P 4800 3550
F 0 "#PWR07" H 4800 3400 50  0001 C CNN
F 1 "VCC" V 4800 3750 50  0000 C CNN
F 2 "" H 4800 3550 50  0001 C CNN
F 3 "" H 4800 3550 50  0001 C CNN
	1    4800 3550
	0    1    1    0   
$EndComp
Wire Wire Line
	4250 3650 4350 3650
Wire Wire Line
	4350 3650 4350 3550
Wire Wire Line
	4350 3550 4500 3550
Wire Wire Line
	4550 3400 4350 3400
Wire Wire Line
	4350 3400 4350 3550
Connection ~ 4350 3550
Wire Wire Line
	4850 3750 4900 3750
Wire Wire Line
	4750 3750 4650 3750
Wire Wire Line
	4350 3750 4250 3750
$EndSCHEMATC
