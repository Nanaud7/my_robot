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
L Connector_Generic:Conn_02x04_Odd_Even J1
U 1 1 613798DD
P 6850 1650
F 0 "J1" H 6900 1850 50  0000 C CNN
F 1 "Conn_02x04_Odd_Even_MountingPin" H 6900 1300 50  0001 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x04_P2.54mm_Vertical" H 6850 1650 50  0001 C CNN
F 3 "~" H 6850 1650 50  0001 C CNN
	1    6850 1650
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0101
U 1 1 6137ADBA
P 4150 1900
F 0 "#PWR0101" H 4150 1750 50  0001 C CNN
F 1 "+3V3" H 4165 2073 50  0000 C CNN
F 2 "" H 4150 1900 50  0001 C CNN
F 3 "" H 4150 1900 50  0001 C CNN
	1    4150 1900
	1    0    0    -1  
$EndComp
Wire Wire Line
	4150 2000 4150 1900
$Comp
L power:+3V3 #PWR0102
U 1 1 6137B938
P 7650 1500
F 0 "#PWR0102" H 7650 1350 50  0001 C CNN
F 1 "+3V3" H 7665 1673 50  0000 C CNN
F 2 "" H 7650 1500 50  0001 C CNN
F 3 "" H 7650 1500 50  0001 C CNN
	1    7650 1500
	1    0    0    -1  
$EndComp
Wire Wire Line
	7650 1550 7650 1500
$Comp
L Device:CP1_Small C1
U 1 1 6137E190
P 7650 1700
F 0 "C1" H 7741 1746 50  0000 L CNN
F 1 "CP1_Small" H 7741 1655 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D5.0mm_P2.50mm" H 7650 1700 50  0001 C CNN
F 3 "~" H 7650 1700 50  0001 C CNN
	1    7650 1700
	1    0    0    -1  
$EndComp
Wire Wire Line
	7650 1600 7650 1550
Connection ~ 7650 1550
$Comp
L power:GND #PWR0103
U 1 1 6137E9C8
P 7650 1850
F 0 "#PWR0103" H 7650 1600 50  0001 C CNN
F 1 "GND" H 7655 1677 50  0000 C CNN
F 2 "" H 7650 1850 50  0001 C CNN
F 3 "" H 7650 1850 50  0001 C CNN
	1    7650 1850
	1    0    0    -1  
$EndComp
Wire Wire Line
	7650 1800 7650 1850
$Comp
L power:GND #PWR0104
U 1 1 6137F4C9
P 4150 4100
F 0 "#PWR0104" H 4150 3850 50  0001 C CNN
F 1 "GND" H 4155 3927 50  0000 C CNN
F 2 "" H 4150 4100 50  0001 C CNN
F 3 "" H 4150 4100 50  0001 C CNN
	1    4150 4100
	1    0    0    -1  
$EndComp
Wire Wire Line
	4150 4100 4150 4050
Wire Wire Line
	4150 4050 4050 4050
Wire Wire Line
	4050 4050 4050 4000
Connection ~ 4150 4050
Wire Wire Line
	4150 4050 4150 4000
Wire Wire Line
	7150 1550 7650 1550
Wire Wire Line
	7150 1650 7250 1650
Wire Wire Line
	7150 1750 7250 1750
Wire Wire Line
	7150 1850 7250 1850
Text Label 7250 1650 0    50   ~ 0
CS
Text Label 7250 1750 0    50   ~ 0
MOSI
Text Label 7250 1850 0    50   ~ 0
IRQ
Text Label 6500 1650 0    50   ~ 0
CE
Text Label 6500 1750 0    50   ~ 0
SCK
Text Label 6500 1850 0    50   ~ 0
MISO
$Comp
L power:GND #PWR0105
U 1 1 61381943
P 6300 1650
F 0 "#PWR0105" H 6300 1400 50  0001 C CNN
F 1 "GND" H 6305 1477 50  0000 C CNN
F 2 "" H 6300 1650 50  0001 C CNN
F 3 "" H 6300 1650 50  0001 C CNN
	1    6300 1650
	1    0    0    -1  
$EndComp
Wire Wire Line
	6300 1550 6300 1650
Wire Wire Line
	6300 1550 6650 1550
Wire Wire Line
	6500 1650 6650 1650
Wire Wire Line
	6500 1750 6650 1750
Wire Wire Line
	6500 1850 6650 1850
Wire Wire Line
	3300 3700 3550 3700
Text Label 3300 3700 0    50   ~ 0
SCK
Wire Wire Line
	3550 3600 3300 3600
Wire Wire Line
	3550 3500 3300 3500
Wire Wire Line
	3550 3400 3300 3400
Text Label 3300 3600 0    50   ~ 0
MISO
Text Label 3300 3500 0    50   ~ 0
MOSI
Text Label 3300 3400 0    50   ~ 0
CS
$Comp
L Mechanical:MountingHole H1
U 1 1 613A0057
P 6250 2850
F 0 "H1" H 6350 2896 50  0000 L CNN
F 1 "MountingHole" H 6350 2805 50  0000 L CNN
F 2 "MountingHole:MountingHole_2.2mm_M2_ISO7380_Pad" H 6250 2850 50  0001 C CNN
F 3 "~" H 6250 2850 50  0001 C CNN
	1    6250 2850
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H2
U 1 1 613A4CAC
P 6250 3050
F 0 "H2" H 6350 3096 50  0000 L CNN
F 1 "MountingHole" H 6350 3005 50  0000 L CNN
F 2 "MountingHole:MountingHole_2.2mm_M2_ISO7380_Pad" H 6250 3050 50  0001 C CNN
F 3 "~" H 6250 3050 50  0001 C CNN
	1    6250 3050
	1    0    0    -1  
$EndComp
Text Label 4700 3400 0    50   ~ 0
CE
Wire Wire Line
	4550 3400 4700 3400
$Comp
L MCU_Module:Arduino_Nano_v3.x A1
U 1 1 61373980
P 4050 3000
F 0 "A1" H 3700 3950 50  0000 C CNN
F 1 "Arduino_Nano_v3.x" H 4050 1820 50  0001 C CNN
F 2 "Module:Arduino_Nano" H 4050 3000 50  0001 C CIN
F 3 "http://www.mouser.com/pdfdocs/Gravitech_Arduino_Nano3_0.pdf" H 4050 3000 50  0001 C CNN
	1    4050 3000
	1    0    0    -1  
$EndComp
$EndSCHEMATC
