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
	uint16_t op1 ;
	uint16_t op2 ;
	char act ;

	char str[] = "hello!!";
	uint16_t i = 127 ;
	
	cout << i<< endl;
	print_in_hex(&i, sizeof(i));
	print_in_binary(&i, sizeof(i));
	//i=15&14;
	//print_in_binary(&i, sizeof(i)-1);
	
	cin >>  op1 ;
	//cout << op1;
	cin >>  act; 
	//cout << act;

	
	cin >> op2;
	//cout <<op2;

	calc (op1, act, op2);
	system("pause");
	return 0;
}

void 
print_in_hex(uint8_t byte){
	std::cout <<std::hex << (byte & 255)<<" ";
	return;
};

 

void 
print_in_hex(const void* data, size_t size){
	char tmp;
	for (int i = 0; i<size; i++){
		tmp = *((char*)data + i);	
		print_in_hex(tmp);
		if (i%2) {cout << endl;}
	}
	return;
};
void 
print_in_binary(uint8_t byte){
	std::cout << bitset<sizeof(byte) * 8> (byte )<< " ";
};
void 
print_in_binary(const void* data, size_t size){
	char tmp;
	for (int i = 0; i<size; i++){
		tmp = *((char*)data + i);	
		print_in_binary(tmp);
		if (i%2) {cout << endl;}
	}
	return;
};

void calc (uint16_t op1, char action, uint16_t op2){
	uint16_t tmp;
	switch (action) {
	case '&':
		tmp = op1 & op2;
		print_in_binary (&tmp, sizeof(tmp));
		break;
	case '|':
		tmp = op1 | op2;
		print_in_binary (&tmp, sizeof(tmp));
		break;
	default:
		cout << "wrong action";
		break;
	}
};

