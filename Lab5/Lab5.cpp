// Lab5.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <stdint.h>
#include <bitset> 
#include <array>

using namespace std;
struct Student;

void print_in_hex(uint8_t byte);
void print_in_hex(const void* data, size_t size);
void print_in_binary(uint8_t byte);
void print_in_binary(const void* data, size_t size);
void calc (uint16_t op1, char action, uint16_t op2);
void students_insrt(Student& student, int num);


struct Student {
string name;
uint16_t year;
uint8_t mean_grade;
uint8_t sex : 1;
uint8_t num_courses;
Student* starosta;
};

int _tmain(int argc, _TCHAR* argv[])
{
	uint16_t op1 ;
	uint16_t op2 ;
	char act ;
	
	
	Student students[3];
	students_insrt (*students, sizeof(students)/sizeof(students[0]));
	for (int i = 0; i<3; i++){
		 calc( (uint16_t)&students , '-' ,(uint16_t)&students[i].name);
		 //cout << sizeof(&students[i].year) << endl;
		 cout << &students[i].name << "_" << &students[i].year << endl;
		 cout << offsetof (Student, year)<< endl;
	}
	
	//calc (op1, act, op2);
	
 
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
		print_in_binary (&tmp, sizeof(tmp));/*; sizeof(tmp-1);*/
		break;
	case '|':
		tmp = op1 | op2;
		print_in_binary (&tmp, sizeof(tmp));/*; sizeof(tmp-1);*/
		break;
	case '+':
		tmp = op1 + op2;
		print_in_binary (&tmp, sizeof(tmp));/*; sizeof(tmp-1);*/
		break;
	case '-':
		tmp = op1 - op2;
		//print_in_binary (&tmp, sizeof(tmp));/*; sizeof(tmp-1);*/
		print_in_hex (&tmp, sizeof(tmp));/*; sizeof(tmp-1);*/

		break;
	default:
		cout << "wrong action";
		break;
	}
};
void students_insrt(Student& student, int num){
	Student* stud = &student;
	stud[0].name = "Andrey";
	stud[0].year = 2006;
	stud[0].mean_grade = 5;
	stud[0].sex = 1;
	stud[0].num_courses = 24;
	stud[0].starosta = &stud[2];
	

	stud[1].name = "Ivan";
	stud[1].year = 2008;
	stud[1].mean_grade = 4;
	stud[1].sex = 1;
	stud[1].num_courses = 22;
	stud[1].starosta = &stud[2];

	stud[2].name = "Nata";
	stud[2].year = 2007;
	stud[2].mean_grade = 3;
	stud[2].sex = 0;
	stud[2].num_courses = 21;
	stud[2].starosta = nullptr;

}

