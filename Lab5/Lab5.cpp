// Lab5.cpp: определяет точку входа для консольного приложения.
//
//#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <stdint.h>
#include <bitset> 
#include <windows.h>
#include <cstdint>

//#include <array>
//
//#include <istream>
//#include <io.h>

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
	

	//STUDENTS
	//Student students[3];
	//students_insrt (*students, sizeof(students)/sizeof(students[0]));
	//for (int i = 0; i<3; i++){
	//	 calc( (uint16_t)&students , '-' ,(uint16_t)&students[i].name);
	//	 //cout << sizeof(&students[i].year) << endl;
	//	 cout << &students[i].name << "_" << &students[i].year << endl;
	//	 cout << offsetof (Student, year)<< endl;


	// BMP

	//FILE* file = fopen("D:\\Projects\\Lab5\\L5.bmp", "r");
	////ifstream file ("D:\Projects\Lab5\l5.bmp", std::ios::in | std::ifstream::binary);
	////BITMAPFILEHEADER bfh ;
	////BITMAPINFOHEADER bih ;
	////RGBQUAD rgbquad;
	////int width, height;
	//int size;
	//char data;
	//char msg[]= "hi There!";
	//if (file){
	//	fseek(file,0,SEEK_END);
	//	size = ftell(file);
	//	fseek(file,0,SEEK_SET);
	//	
	//	//data = new char [size];
	//	cout<< size<< endl;
	//	for (size_t i = 0 ; i<size; i++){
	//			data = fgetc(file);
	//			print_in_binary(data);
	//			cout<< "data:" << data << endl;				
	//			
	//			data = msg[i];

	//			print_in_binary(data);
	//			cout<< "data_mod:" << data << endl;
	//			cin>>act;
	//	}
//}
	// FILE READ 



	char fname[100];
	string fname_str ;
	int str_end=0;
	cin >> fname;
	for (int i = 0; fname[i]!=0; i++){
		//printf( "%i %c\n", i, fname[i] );
		if (fname[i] == '*' || fname[i] == '<' || fname[i] == '>'){
			printf("Wrong name\n");
			return 0;
		};
	}

	if (strstr(fname,".txt")-fname != (strchr(fname, '\0')-fname-4))
	{
		printf("not TXT\n");
	}

	FILE * f ;
	if ((f=fopen(fname, "r")) == NULL) {
		 printf("Cannot open file");
		 //return -1;
	}
	fseek(f,0,FILE_END);\
	int filesize= ftell(f);
	fseek(f,0,FILE_BEGIN);

	printf("%i\n", filesize);

	char * buffer = (char*)malloc(filesize * sizeof(char));  // D:\Projects\Lab5\ttt.txt
	fread(buffer,sizeof(char),filesize,f);

	
	printf("%s\n", buffer);
	//find input_str
	char input_str[100];
	printf("Enter string\n" );
	cin >> input_str;






	//Count '.' to find the number of sentences

	char* pnt = strchr(buffer, '.');
	int num_of_sent = 0;
	while (pnt !=0) 
	{
		num_of_sent++;
		pnt  = strchr(pnt+1, '.');
	}
	printf("Num of sents %i\n", num_of_sent);
	//calc (op1, act, op2);
	
 
	system("pause");
	//fclose(f);

	//free(fname);
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
	case '+':
		tmp = op1 + op2;
		print_in_binary (&tmp, sizeof(tmp));
		break;
	case '-':
		tmp = op1 - op2;
		print_in_hex (&tmp, sizeof(tmp));

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

