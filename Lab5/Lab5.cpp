// Lab5.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <stdint.h>
#include <bitset> 

using namespace std;
void print_in_hex(uint8_t byte);
void print_in_hex(const void* data, size_t size);
void print_in_binary(uint8_t byte);
void print_in_binary(const void* data, size_t size);
void calc (uint16_t op1, char action, uint16_t op2);


int _tmain(int argc, _TCHAR* argv[])
{
	//uint8_t ui8 = 11;
	
	char str[] = "hello!!";
	uint16_t i = 15 & 127;
	cout << i;
	print_in_hex(&i, sizeof(i)-1);
	print_in_binary(&i, sizeof(i)-1);

	//calc (1025, '&', 127);
	system("pause");
	return 0;
}

void 
print_in_hex(uint8_t byte){
	std::cout <<std::hex << (byte & 255) << endl;
	return;
};

 

void 
print_in_hex(const void* data, size_t size){
	char tmp;
	for (int i = 0; i<size; i++){
		tmp = *((char*)data + i);	
		print_in_hex(tmp);
	}
	return;
};
void 
print_in_binary(uint8_t byte){
	std::cout << bitset<sizeof(byte) * 8> (byte )<< endl;
};
void 
print_in_binary(const void* data, size_t size){
	char tmp;
	for (int i = 0; i<size; i++){
		tmp = *((char*)data + i);	
		print_in_binary(tmp);
	}
	return;
};

void calc (uint16_t op1, char action, uint16_t op2){
	uint16_t tmp;
	switch (action) {
	case '&':
		tmp = op1	 &  op2;
		print_in_binary (&tmp, sizeof(tmp));/*; sizeof(tmp-1);*/
		break;
	case '|':
		tmp = 0;//op1	 &  op2;
		//del
		break;
	default:
		cout << "wrong action";
		break;
	}
};

