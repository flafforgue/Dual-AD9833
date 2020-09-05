EESchema Schematic File Version 4
LIBS:Dual-AD9833-cache
EELAYER 29 0
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
L power:GND #PWR0101
U 1 1 5CE2DBEF
P 8650 5000
F 0 "#PWR0101" H 8650 4750 50  0001 C CNN
F 1 "GND" H 8655 4827 50  0000 C CNN
F 2 "" H 8650 5000 50  0001 C CNN
F 3 "" H 8650 5000 50  0001 C CNN
	1    8650 5000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0102
U 1 1 5CE2E0C3
P 8950 5000
F 0 "#PWR0102" H 8950 4750 50  0001 C CNN
F 1 "GND" H 8955 4827 50  0000 C CNN
F 2 "" H 8950 5000 50  0001 C CNN
F 3 "" H 8950 5000 50  0001 C CNN
	1    8950 5000
	1    0    0    -1  
$EndComp
$Comp
L 00_Fred:Level-4Chn M3
U 1 1 5CE3B82A
P 8800 3800
F 0 "M3" H 8800 4250 50  0000 C CNN
F 1 "Level-4Chn" V 8800 3700 50  0000 C CNN
F 2 "Package_DIP:DIP-12_W10.16mm_LongPads" H 8750 3300 50  0001 C CNN
F 3 "" H 8800 4100 50  0001 C CNN
	1    8800 3800
	-1   0    0    -1  
$EndComp
Wire Wire Line
	7150 3950 8350 3950
Wire Wire Line
	7100 3850 8350 3850
Wire Wire Line
	7050 3750 8350 3750
Wire Wire Line
	7000 3650 8350 3650
$Comp
L power:GND #PWR0103
U 1 1 5CE68651
P 9650 5000
F 0 "#PWR0103" H 9650 4750 50  0001 C CNN
F 1 "GND" H 9655 4827 50  0000 C CNN
F 2 "" H 9650 5000 50  0001 C CNN
F 3 "" H 9650 5000 50  0001 C CNN
	1    9650 5000
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0105
U 1 1 5CE6AFE8
P 9450 5000
F 0 "#PWR0105" H 9450 4850 50  0001 C CNN
F 1 "+5V" H 9465 5173 50  0000 C CNN
F 2 "" H 9450 5000 50  0001 C CNN
F 3 "" H 9450 5000 50  0001 C CNN
	1    9450 5000
	-1   0    0    1   
$EndComp
Wire Wire Line
	9750 4650 9650 4650
Wire Wire Line
	9650 4650 9650 5000
Wire Wire Line
	9750 4550 9450 4550
Wire Wire Line
	9450 4550 9450 5000
Wire Wire Line
	8950 4450 8950 5000
Wire Wire Line
	8650 4450 8650 5000
$Comp
L power:+3.3V #PWR0106
U 1 1 5CE71068
P 8950 2650
F 0 "#PWR0106" H 8950 2500 50  0001 C CNN
F 1 "+3.3V" H 8965 2823 50  0000 C CNN
F 2 "" H 8950 2650 50  0001 C CNN
F 3 "" H 8950 2650 50  0001 C CNN
	1    8950 2650
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0107
U 1 1 5CE7106E
P 8650 2650
F 0 "#PWR0107" H 8650 2500 50  0001 C CNN
F 1 "+5V" H 8665 2823 50  0000 C CNN
F 2 "" H 8650 2650 50  0001 C CNN
F 3 "" H 8650 2650 50  0001 C CNN
	1    8650 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	8950 2650 8950 3200
Wire Wire Line
	8650 2650 8650 3200
$Comp
L power:GND #PWR0108
U 1 1 5CE7A7A9
P 1450 5850
F 0 "#PWR0108" H 1450 5600 50  0001 C CNN
F 1 "GND" H 1455 5677 50  0000 C CNN
F 2 "" H 1450 5850 50  0001 C CNN
F 3 "" H 1450 5850 50  0001 C CNN
	1    1450 5850
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0109
U 1 1 5CE7A7AF
P 1600 5850
F 0 "#PWR0109" H 1600 5600 50  0001 C CNN
F 1 "GND" H 1605 5677 50  0000 C CNN
F 2 "" H 1600 5850 50  0001 C CNN
F 3 "" H 1600 5850 50  0001 C CNN
	1    1600 5850
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0110
U 1 1 5CE7A7B5
P 1750 2650
F 0 "#PWR0110" H 1750 2500 50  0001 C CNN
F 1 "+3.3V" H 1765 2823 50  0000 C CNN
F 2 "" H 1750 2650 50  0001 C CNN
F 3 "" H 1750 2650 50  0001 C CNN
	1    1750 2650
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0111
U 1 1 5CE7A7BB
P 1500 2650
F 0 "#PWR0111" H 1500 2500 50  0001 C CNN
F 1 "+5V" H 1515 2823 50  0000 C CNN
F 2 "" H 1500 2650 50  0001 C CNN
F 3 "" H 1500 2650 50  0001 C CNN
	1    1500 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	1500 2650 1500 2750
Wire Wire Line
	1500 2750 1600 2750
Wire Wire Line
	1600 2750 1600 2850
Wire Wire Line
	1750 2850 1750 2650
Wire Wire Line
	1450 5750 1450 5850
Wire Wire Line
	1600 5750 1600 5850
$Comp
L power:+5V #PWR0112
U 1 1 5CE8FC12
P 9300 2650
F 0 "#PWR0112" H 9300 2500 50  0001 C CNN
F 1 "+5V" H 9315 2823 50  0000 C CNN
F 2 "" H 9300 2650 50  0001 C CNN
F 3 "" H 9300 2650 50  0001 C CNN
	1    9300 2650
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 5CE901DC
P 9300 3300
F 0 "R1" H 9370 3346 50  0000 L CNN
F 1 "1K" V 9300 3250 50  0000 L CNN
F 2 "00-Fred-mod:Rx" V 9230 3300 50  0001 C CNN
F 3 "~" H 9300 3300 50  0001 C CNN
	1    9300 3300
	1    0    0    -1  
$EndComp
$Comp
L 00_Fred:TFT-KMR-1.8-128x160 DSP1
U 1 1 5CF432E6
P 10200 3850
F 0 "DSP1" H 10217 2585 50  0000 C CNN
F 1 "TFT-KMR-1.8-128x160" H 10217 2676 50  0000 C CNN
F 2 "00-Fred-mod:TFT-18-KMR-128x160" V 10550 3750 50  0001 C CNN
F 3 "https://forum.arduino.cc/index.php?topic=406501.0" H 10150 4500 50  0001 C CNN
	1    10200 3850
	1    0    0    1   
$EndComp
Wire Wire Line
	9300 3450 9300 4050
Wire Wire Line
	9300 4050 9750 4050
$Comp
L power:GND #PWR0104
U 1 1 5CF7C1B4
P 9550 2650
F 0 "#PWR0104" H 9550 2400 50  0001 C CNN
F 1 "GND" H 9555 2477 50  0000 C CNN
F 2 "" H 9550 2650 50  0001 C CNN
F 3 "" H 9550 2650 50  0001 C CNN
	1    9550 2650
	-1   0    0    1   
$EndComp
Wire Wire Line
	9550 2650 9550 2850
Wire Wire Line
	9550 2850 9750 2850
Wire Wire Line
	9300 2650 9300 2950
$Comp
L Device:R R2
U 1 1 5CF7F290
P 9500 2950
F 0 "R2" V 9400 2900 50  0000 L CNN
F 1 "22R" V 9500 2900 50  0000 L CNN
F 2 "00-Fred-mod:Rx" V 9430 2950 50  0001 C CNN
F 3 "~" H 9500 2950 50  0001 C CNN
	1    9500 2950
	0    -1   -1   0   
$EndComp
Wire Wire Line
	9750 2950 9650 2950
Wire Wire Line
	9350 2950 9300 2950
Connection ~ 9300 2950
Wire Wire Line
	9300 2950 9300 3150
$Comp
L 00_Fred:Arduino-Nano U1
U 1 1 5CE2FB4F
P 1700 4100
F 0 "U1" H 1950 5300 50  0000 C CNN
F 1 "Arduino-Nano" V 1400 3950 50  0000 C CNN
F 2 "00-Fred-mod:DIP-30-W15.25mm_Socket_LongPads" V 1550 3950 50  0001 C CNN
F 3 "https://store.arduino.cc/arduino-nano" H 1850 5300 50  0001 C CNN
	1    1700 4100
	1    0    0    -1  
$EndComp
$Comp
L Dual-AD9833-rescue:AD9833-Module-00_Fred M2
U 1 1 5CF98807
P 5500 1200
F 0 "M2" H 5828 1071 50  0000 L CNN
F 1 "AD9833-Module" H 5828 980 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x06_P2.54mm_Vertical" H 5600 1600 50  0001 C CNN
F 3 "https://www.analog.com/media/en/technical-documentation/data-sheets/ad9833.pdf" H 5600 1600 50  0001 C CNN
	1    5500 1200
	1    0    0    -1  
$EndComp
$Comp
L Dual-AD9833-rescue:AD9833-Module-00_Fred M1
U 1 1 5CF9B743
P 5500 2350
F 0 "M1" H 5828 2221 50  0000 L CNN
F 1 "AD9833-Module" H 5828 2130 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x06_P2.54mm_Vertical" H 5600 2750 50  0001 C CNN
F 3 "https://www.analog.com/media/en/technical-documentation/data-sheets/ad9833.pdf" H 5600 2750 50  0001 C CNN
	1    5500 2350
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D2
U 1 1 5CF9CC71
P 1700 1250
F 0 "D2" H 1850 1300 50  0000 C CNN
F 1 "LED" H 1693 1375 50  0000 C CNN
F 2 "LED_THT:LED_D3.0mm_Clear" H 1700 1250 50  0001 C CNN
F 3 "~" H 1700 1250 50  0001 C CNN
	1    1700 1250
	-1   0    0    1   
$EndComp
$Comp
L Device:LED D1
U 1 1 5CF9EE23
P 1700 900
F 0 "D1" H 1850 950 50  0000 C CNN
F 1 "LED" H 1693 1025 50  0000 C CNN
F 2 "LED_THT:LED_D3.0mm_Clear" H 1700 900 50  0001 C CNN
F 3 "~" H 1700 900 50  0001 C CNN
	1    1700 900 
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR0113
U 1 1 5CFA6778
P 3550 7450
F 0 "#PWR0113" H 3550 7200 50  0001 C CNN
F 1 "GND" H 3555 7277 50  0000 C CNN
F 2 "" H 3550 7450 50  0001 C CNN
F 3 "" H 3550 7450 50  0001 C CNN
	1    3550 7450
	1    0    0    -1  
$EndComp
$Comp
L Device:C C2
U 1 1 5CFA6F83
P 3000 7100
F 0 "C2" H 3000 7200 50  0000 L CNN
F 1 "C" H 3050 7000 50  0000 L CNN
F 2 "00-Fred-mod:Cmkv5" H 3038 6950 50  0001 C CNN
F 3 "~" H 3000 7100 50  0001 C CNN
	1    3000 7100
	1    0    0    -1  
$EndComp
$Comp
L Device:C C1
U 1 1 5CFA9103
P 2750 7100
F 0 "C1" H 2750 7200 50  0000 L CNN
F 1 "C" H 2800 7000 50  0000 L CNN
F 2 "00-Fred-mod:Cmkv5" H 2788 6950 50  0001 C CNN
F 3 "~" H 2750 7100 50  0001 C CNN
	1    2750 7100
	1    0    0    -1  
$EndComp
$Comp
L Device:C C3
U 1 1 5CFAE5A0
P 4100 7100
F 0 "C3" H 4150 7200 50  0000 L CNN
F 1 "C" H 4150 7000 50  0000 L CNN
F 2 "00-Fred-mod:Cmkv5" H 4138 6950 50  0001 C CNN
F 3 "~" H 4100 7100 50  0001 C CNN
	1    4100 7100
	1    0    0    -1  
$EndComp
Wire Wire Line
	2750 7250 2750 7350
Wire Wire Line
	2750 7350 3000 7350
Wire Wire Line
	3550 7350 3550 7450
Wire Wire Line
	3000 7250 3000 7350
Wire Wire Line
	4100 7350 4100 7250
Wire Wire Line
	4100 6550 3900 6550
Wire Wire Line
	4100 6550 4100 6950
Wire Wire Line
	3000 6750 3000 6950
$Comp
L Device:Rotary_Encoder_Switch SW3
U 1 1 5CF9F423
P 3600 6650
F 0 "SW3" H 3600 7017 50  0000 C CNN
F 1 "Rotary_Encoder_Switch" H 3600 6926 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 3450 6810 50  0001 C CNN
F 3 "~" H 3600 6910 50  0001 C CNN
	1    3600 6650
	1    0    0    -1  
$EndComp
Connection ~ 3550 7350
Wire Wire Line
	3950 6750 3950 7350
Wire Wire Line
	3550 7350 3950 7350
Connection ~ 3950 7350
Wire Wire Line
	3950 7350 4100 7350
Wire Wire Line
	3900 6750 3950 6750
Wire Wire Line
	2150 5350 2650 5350
Wire Wire Line
	2650 6750 3000 6750
Wire Wire Line
	2150 5250 2750 5250
Wire Wire Line
	4100 2150 5050 2150
Wire Wire Line
	4250 2300 5050 2300
Wire Wire Line
	5050 2450 4400 2450
Wire Wire Line
	5050 1150 4250 1150
Wire Wire Line
	4250 1150 4250 2300
Wire Wire Line
	5050 1300 4400 1300
Wire Wire Line
	4400 1300 4400 2450
Wire Wire Line
	3950 1450 5050 1450
Wire Wire Line
	3800 1000 5050 1000
Wire Wire Line
	2100 1250 1850 1250
Wire Wire Line
	2100 900  1850 900 
Wire Wire Line
	1550 1250 1300 1250
Wire Wire Line
	1300 1250 1300 1100
Wire Wire Line
	1300 900  1550 900 
$Comp
L power:GND #PWR0114
U 1 1 5D04B1C9
P 1000 1200
F 0 "#PWR0114" H 1000 950 50  0001 C CNN
F 1 "GND" H 1005 1027 50  0000 C CNN
F 2 "" H 1000 1200 50  0001 C CNN
F 3 "" H 1000 1200 50  0001 C CNN
	1    1000 1200
	1    0    0    -1  
$EndComp
Wire Wire Line
	1000 1200 1000 1100
Wire Wire Line
	1000 1100 1300 1100
Connection ~ 1300 1100
Wire Wire Line
	1300 1100 1300 900 
Wire Wire Line
	4700 1600 4700 2750
Wire Wire Line
	5050 2750 4700 2750
Wire Wire Line
	4900 1750 4900 2900
Wire Wire Line
	5050 2900 4900 2900
$Comp
L power:GND #PWR0115
U 1 1 5D05CC61
P 4700 850
F 0 "#PWR0115" H 4700 600 50  0001 C CNN
F 1 "GND" H 4705 677 50  0000 C CNN
F 2 "" H 4700 850 50  0001 C CNN
F 3 "" H 4700 850 50  0001 C CNN
	1    4700 850 
	-1   0    0    1   
$EndComp
$Comp
L power:+5V #PWR0116
U 1 1 5D0614F5
P 4900 850
F 0 "#PWR0116" H 4900 700 50  0001 C CNN
F 1 "+5V" H 4915 1023 50  0000 C CNN
F 2 "" H 4900 850 50  0001 C CNN
F 3 "" H 4900 850 50  0001 C CNN
	1    4900 850 
	1    0    0    -1  
$EndComp
Wire Wire Line
	2150 4250 7000 4250
Wire Wire Line
	7000 4250 7000 3650
Wire Wire Line
	2150 4450 7050 4450
Wire Wire Line
	7050 4450 7050 3750
Wire Wire Line
	5050 1600 4700 1600
Wire Wire Line
	4700 850  4700 1600
Connection ~ 4700 1600
Wire Wire Line
	4900 850  4900 1750
Connection ~ 4900 1750
Wire Wire Line
	4900 1750 5050 1750
Wire Wire Line
	3300 6650 3250 6650
Wire Wire Line
	3250 6650 3250 7350
Connection ~ 3250 7350
Wire Wire Line
	3250 7350 3550 7350
Wire Wire Line
	2750 6550 3300 6550
Connection ~ 2750 6550
Wire Wire Line
	2750 6550 2750 6950
Wire Wire Line
	3000 6750 3300 6750
Connection ~ 3000 6750
Wire Wire Line
	3000 7350 3250 7350
Connection ~ 3000 7350
Wire Wire Line
	2850 6150 4100 6150
Wire Wire Line
	4100 6150 4100 6550
Connection ~ 4100 6550
Wire Wire Line
	2650 5350 2650 6750
Wire Wire Line
	2750 5250 2750 6550
$Comp
L Device:R R4
U 1 1 5CFC9C72
P 2250 1250
F 0 "R4" H 2320 1296 50  0000 L CNN
F 1 "1K" V 2250 1200 50  0000 L CNN
F 2 "00-Fred-mod:Rx" V 2180 1250 50  0001 C CNN
F 3 "~" H 2250 1250 50  0001 C CNN
	1    2250 1250
	0    1    1    0   
$EndComp
$Comp
L Device:R R3
U 1 1 5CFCD90E
P 2250 900
F 0 "R3" H 2320 946 50  0000 L CNN
F 1 "1K" V 2250 850 50  0000 L CNN
F 2 "00-Fred-mod:Rx" V 2180 900 50  0001 C CNN
F 3 "~" H 2250 900 50  0001 C CNN
	1    2250 900 
	0    1    1    0   
$EndComp
Wire Wire Line
	2850 6150 2850 4000
Wire Wire Line
	2850 4000 2150 4000
Wire Wire Line
	9250 3650 9600 3650
Wire Wire Line
	9600 3650 9600 3750
Wire Wire Line
	9600 3750 9750 3750
Wire Wire Line
	9250 3750 9550 3750
Wire Wire Line
	9550 3750 9550 3850
Wire Wire Line
	9550 3850 9750 3850
Wire Wire Line
	7100 4650 7100 3850
Wire Wire Line
	2150 4750 7150 4750
Wire Wire Line
	7150 4750 7150 3950
Wire Wire Line
	9250 3950 9750 3950
Wire Wire Line
	9250 3850 9450 3850
Wire Wire Line
	9450 3850 9450 3550
Wire Wire Line
	9450 3550 9650 3550
Wire Wire Line
	9650 3550 9650 3650
Wire Wire Line
	9650 3650 9750 3650
Wire Wire Line
	2150 4650 7100 4650
Wire Wire Line
	4250 2300 4250 4950
Wire Wire Line
	4250 4950 2150 4950
Connection ~ 4250 2300
Wire Wire Line
	2150 4850 4400 4850
Wire Wire Line
	4400 4850 4400 2450
Connection ~ 4400 2450
Wire Wire Line
	2150 5150 3800 5150
Wire Wire Line
	3800 5150 3800 1000
Wire Wire Line
	4100 2150 4100 5050
Wire Wire Line
	4100 5050 2150 5050
Wire Wire Line
	2150 4550 3950 4550
Wire Wire Line
	3950 4550 3950 1450
Wire Wire Line
	2150 3900 3600 3900
Wire Wire Line
	3600 3900 3600 900 
Wire Wire Line
	2400 900  3600 900 
Wire Wire Line
	3500 1250 3500 3800
Wire Wire Line
	3500 3800 2150 3800
Wire Wire Line
	2400 1250 3500 1250
Wire Wire Line
	3400 2600 3400 3700
Wire Wire Line
	3400 3700 2150 3700
Wire Wire Line
	3400 2600 5050 2600
Wire Wire Line
	2550 1750 3200 1750
Wire Wire Line
	3200 3600 2150 3600
Wire Wire Line
	3100 3500 3100 2350
Wire Wire Line
	3100 2000 2550 2000
$Comp
L Switch:SW_Push SW1
U 1 1 5D018902
P 2350 1750
F 0 "SW1" H 2250 1850 50  0000 C CNN
F 1 "SW_Push" H 2650 1800 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x02_P2.54mm_Vertical" H 2350 1950 50  0001 C CNN
F 3 "~" H 2350 1950 50  0001 C CNN
	1    2350 1750
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW2
U 1 1 5D0198C2
P 2350 2000
F 0 "SW2" H 2250 2100 50  0000 C CNN
F 1 "SW_Push" H 2650 2050 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x02_P2.54mm_Vertical" H 2350 2200 50  0001 C CNN
F 3 "~" H 2350 2200 50  0001 C CNN
	1    2350 2000
	1    0    0    -1  
$EndComp
Wire Wire Line
	1600 1750 1600 1850
Wire Wire Line
	1600 2000 2150 2000
Wire Wire Line
	1600 1750 2150 1750
Wire Wire Line
	1600 1850 1000 1850
Wire Wire Line
	1000 1850 1000 1950
Connection ~ 1600 1850
Wire Wire Line
	1600 1850 1600 2000
$Comp
L power:GND #PWR0117
U 1 1 5D03CC2D
P 1000 1950
F 0 "#PWR0117" H 1000 1700 50  0001 C CNN
F 1 "GND" H 1005 1777 50  0000 C CNN
F 2 "" H 1000 1950 50  0001 C CNN
F 3 "" H 1000 1950 50  0001 C CNN
	1    1000 1950
	1    0    0    -1  
$EndComp
$Comp
L Device:R R5
U 1 1 5D042D06
P 2800 2350
F 0 "R5" V 2850 2500 50  0000 L CNN
F 1 "10k" V 2800 2300 50  0000 L CNN
F 2 "00-Fred-mod:Rx" V 2730 2350 50  0001 C CNN
F 3 "~" H 2800 2350 50  0001 C CNN
	1    2800 2350
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R6
U 1 1 5D048DF6
P 2800 2550
F 0 "R6" V 2850 2700 50  0000 L CNN
F 1 "10k" V 2800 2500 50  0000 L CNN
F 2 "00-Fred-mod:Rx" V 2730 2550 50  0001 C CNN
F 3 "~" H 2800 2550 50  0001 C CNN
	1    2800 2550
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2950 2350 3100 2350
Wire Wire Line
	2950 2550 3200 2550
Wire Wire Line
	2650 2350 2400 2350
Wire Wire Line
	2400 2550 2650 2550
Wire Wire Line
	2250 2450 2250 2400
Connection ~ 3100 2350
Connection ~ 3200 2550
Wire Wire Line
	3200 2550 3200 3600
Wire Wire Line
	3200 1750 3200 2550
Wire Wire Line
	3100 2000 3100 2350
$Comp
L power:+5V #PWR0118
U 1 1 5D066DEB
P 2250 2400
F 0 "#PWR0118" H 2250 2250 50  0001 C CNN
F 1 "+5V" H 2150 2500 50  0000 C CNN
F 2 "" H 2250 2400 50  0001 C CNN
F 3 "" H 2250 2400 50  0001 C CNN
	1    2250 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	2400 2350 2400 2450
Wire Wire Line
	2250 2450 2400 2450
Connection ~ 2400 2450
Wire Wire Line
	2400 2450 2400 2550
Wire Wire Line
	2150 3500 3100 3500
$EndSCHEMATC
