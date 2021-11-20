#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include<iostream>

using namespace std;

string Rom(int numero){
	int unidades,decenas,centenas,millar; 
	string romano;
	//2152
	unidades = numero%10; numero /= 10; //unidades = 2 , numero = 215
	decenas = numero%10; numero /= 10; //decenas = 5 , numero = 21
	centenas = numero%10; numero /= 10; //centenas = 1 , numero = 2
	millar = numero%10; numero /= 10; //millar = 2 , numero = 0
	//2000+100+50+2 = 2152
	
	switch(millar){
		case 1: romano += "M";break;
		case 2: romano += "MM"; break;
		case 3: romano += "MMM";break;
	}
	
	switch(centenas){
		case 1: romano += "C";break;
		case 2: romano += "CC";break;
		case 3: romano += "CCC";break;
		case 4: romano += "CD";break;
		case 5: romano += "D";break;
		case 6: romano += "DC";break;
		case 7: romano += "DCC";break;
		case 8: romano += "DCCC";break;
		case 9: romano += "CM";break;
	}
	
	switch(decenas){
		case 1: romano += "X";break;
		case 2: romano += "XX";break;
		case 3: romano += "XXX";break;
		case 4: romano += "XL";break;
		case 5: romano += "L";break;
		case 6: romano += "LX";break;
		case 7: romano += "LXX";break;
		case 8: romano += "LXXX";break;
		case 9: romano += "XC";break;
	}
	
	switch(unidades){
		case 1: romano += "I";break;
		case 2: romano += "II";break;
		case 3: romano += "III";break;
		case 4: romano += "IV";break;
		case 5: romano += "V";break;
		case 6: romano += "VI";break;
		case 7: romano += "VII";break;
		case 8: romano += "VIII";break;
		case 9: romano += "IX";break;
	}
	return romano;
}

TEST_CASE("Test case 1"){
    REQUIRE(Rom(2564)=="MMDLX");
}
TEST_CASE("Test case 2"){
    REQUIRE(Rom(2555)=="MMDLV");
}
TEST_CASE("Test case 3"){
    REQUIRE(Rom(2569)=="MMDLXIX");
}
TEST_CASE("Test case 4"){
    REQUIRE(Rom(2444)=="MMCDXLIV");
}
TEST_CASE("Test case 5"){
    REQUIRE(Rom(1586)=="MDLXXXVI");}