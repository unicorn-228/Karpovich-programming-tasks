#include "Header.h"

using namespace std;


void stud_1::operator= (stud_2 a) {
	name = a.name;
	kurs = a.kurs;
	otdelenie = a.otdelenie;
}
bool stud_1::operator== (stud_2 a) {
	if (a.name == name &&
		a.kurs == kurs &&
		a.otdelenie == otdelenie) {
		return true;
	}
	return false;
}
void stud_1::dataOut(ostream& a) {
	a << name << " ";
	a << kurs << " ";
	a << otdelenie << " ";
}
void stud_1::dataIn(ifstream& a) {
	a >> name;
	a >> kurs;
	a >> otdelenie;
}
void stud_1::dataOut(ofstream& a) {
	a << name << " ";
	a << kurs << " ";
	a << otdelenie << " ";
}


void stud_2::operator= (stud_1 a) {
	name = a.name;
	kurs = a.kurs;
	otdelenie = a.otdelenie;
}
bool stud_2::operator== (stud_1 a) {
	if (a.name == name &&
		a.kurs == kurs &&
		a.otdelenie == otdelenie) {
		return true;
	}
	return false;
}
void stud_2::dataOut(ostream& a) {
	a << name << " ";
	a << kurs << " ";
	a << otdelenie << " ";
}
void stud_2::dataIn(ifstream& a) {
	a >> name;
	a >> kurs;
	a >> otdelenie;
}
void stud_2::dataOut(ofstream& a) {
	a << name << " ";
	a << kurs << " ";
	a << otdelenie << " ";
}
void stud_3::operator= (stud_1 a) {
	name = a.name;
	kurs = a.kurs;
	otdelenie = a.otdelenie;
}
void stud_3::operator= (stud_2 a) {
	name = a.name;
	kurs = a.kurs;
	otdelenie = a.otdelenie;
}
void stud_3::dataOut(ostream& a) {
	a << name << " ";
	a << kurs << " ";
	a << otdelenie << " ";
}
void stud_3::dataIn(ifstream& a) {
	a >> name;
	a >> kurs;
	a >> otdelenie;
}
void stud_3::dataOut(ofstream& a) {
	a << name << " ";
	a << kurs << " ";
	a << otdelenie << " ";
}

template <class A> void CONTAINER<A>::poiskOdnoiSpecialnsti() {
	for (int i = 0; i < realSize; i++) {
		for (int q = i + 1; q < realSize; q++) {
			if (data[i].otdelenie == data[q].otdelenie) {
				cout << data[i].name << " " << data[i].kurs << " " << data[i].otdelenie << endl;
				cout << data[q].name << " " << data[q].kurs << " " << data[q].otdelenie << endl;
			}
		}
	}
}

template <class A> void CONTAINER<A>::BINOut(string filename) {
	ofstream fileOut;
	fileOut.open(filename, ios::binary);
	BINOut(fileOut);
}

template <class A> void CONTAINER<A>::BINOut(ofstream& a) {
	for (int i = 0; i < realSize; i++) {
		a.write((char*)&data[i], sizeof(A));
	}
}

CONTAINER<stud_3>& operator+ (CONTAINER<stud_1>& a, CONTAINER<stud_2>& b) {
	CONTAINER<stud_3> result;// = new CONTAINER<stud_3>;
	result.resize(a.realSize + b.realSize);
	int pos = 0;
	for (int i = 0; i < b.realSize; i++) {
		for (int q = i; q < a.realSize; q++) {
			if (b.data[i] == a.data[q]) {
				result.data[pos] = b.data[i];
				result.realSize++;
				pos++;
			}
		}
	}
	return result;
}

int compare(const void *a, const void *b) {
	stud_1 *newa = (stud_1*)a;
	stud_1 *newb = (stud_1*)b;
	return newa->kurs - newb->kurs;
}

template <class A> void CONTAINER<A>::sort() {
	qsort(data, realSize, sizeof(A), compare);
}

template <class A> A& CONTAINER<A>::operator [] (int i) {
	return data[i];
}

template<class A> void CONTAINER<A>::operator = (CONTAINER<A> b) {
	resize(b.size);
	realSize = b.realSize;
	for (int i = 0; i < realSize; i++) {
		data[i] = b.data[i];
	}
}

template <class A> void CONTAINER<A>::resize(int newSize) {
	size = newSize;
	realSize = 0;
	delete[] data;
	data = new A[size];
}

template <class A> CONTAINER<A>::CONTAINER() {
	size = 0;
	realSize = 0;
	data = NULL;
}
template <class A> CONTAINER<A>::CONTAINER(int newSize) {
	size = newSize;
	realSize = 0;
	data = new A[size];
}

template <class A> void CONTAINER<A>::TXTOut(string filename) {
	ofstream a;
	a.open(filename, ios::out);
	TXTOut(a);
}
template <class A> void CONTAINER<A>::TXTOut(ofstream & a) {
	for (int i = 0; i < realSize; i++) {
		data[i].dataOut(a);
		a << endl;
	}
}
template <class A> void CONTAINER<A>::TXTOut() {
	for (int i = 0; i < realSize; i++) {
		data[i].dataOut(cout);
		cout << endl;
	}
}



template <class A> void CONTAINER<A>::TXTIn(ifstream& a) {
	int i = 0;
	while (!a.eof()) {
		data[i].dataIn(a);
		i++;
		realSize++;
	}
}

template <class A> void CONTAINER<A>::TXTIn(string filename) {
	ifstream a;
	a.open(filename, ios::in);
	int i = 0;
	while (!a.eof()) {
		data[i].dataIn(a);
		i++;
		realSize++;
	}
}

template <class A> ostream& operator << (ostream& a, CONTAINER<A> & b) {
	for (int i = 0; i < b.realSize; i++) {
		b.data[i].dataOut(a);
		cout << endl;
	}
}