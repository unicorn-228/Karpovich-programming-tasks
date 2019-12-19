#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct stud_1;
struct stud_2;
struct stud_3;

struct stud {
public:
	virtual void dataIn(ifstream& a) = 0;
	virtual void dataOut(ofstream& a) = 0;
	virtual void dataOut(ostream& a) = 0;
};

struct stud_1 : public stud { // туенты дневного отделения
	string name;
	int kurs;
	int otdelenie;
	void dataIn(ifstream& a);
	void dataOut(ofstream& a);
	void dataOut(ostream& a);
	bool operator == (stud_2 a);
	void operator = (stud_2 a);
};

struct stud_2 : public stud { // туенты заочного отделения
	string name;
	int kurs;
	int otdelenie;
	void dataIn(ifstream& a);
	void dataOut(ofstream& a);
	void dataOut(ostream& a);
	bool operator == (stud_1 a);
	void operator = (stud_1 a);
};

struct stud_3 : public stud { // вссе студенты
	string name;
	int kurs;
	int otdelenie;
	void dataIn(ifstream& a);
	void dataOut(ofstream& a);
	void dataOut(ostream& a);
	void operator = (stud_2 a);
	void operator = (stud_1 a);
};

template <class A> class CONTAINER {
	int size;
	int realSize;
	A *data;
public:
	CONTAINER();
	CONTAINER(int newSize);
	~CONTAINER() {};
	void resize(int newSize);
	void TXTIn(ifstream& a);
	void TXTIn(string filename);
	void TXTOut(); // на консоль
	void TXTOut(ofstream& a); // в файл
	void TXTOut(string filename); // в файл
	void operator = (CONTAINER<A> a);
	A& operator [] (int i);
	void sort();
	void BINOut(ofstream& a);
	void BINOut(string filename);
	friend ostream& operator << (ostream& a, CONTAINER& b); // консольный вывод
	friend CONTAINER<stud_3>& operator + (CONTAINER<stud_1>& a, CONTAINER<stud_2>& b);
	void poiskOdnoiSpecialnsti();
};
