#include "Header.h"
#include "qwe.cpp"

using namespace std;




int main() {
	setlocale(LC_ALL, ".1251");
	CONTAINER <stud_1> data1;
	CONTAINER <stud_2> data2;
	CONTAINER <stud_3> data3;
	data1.resize(10);
	data1.TXTIn("студентыƒневногоќтделени€.txt");
	data2.resize(10);
	data2.TXTIn("студенты«аочногоќтделени€.txt");
	data3.resize(10);
	cout << "студенты дневного отделени€ :" << endl;
	data1.TXTOut();
	cout << endl;
	cout << "студенты заочники :" << endl;
	data2.TXTOut();
	cout << endl;
	data3 =  data1 + data2;
	cout << "те кто есть и там и там :" << endl;
	data3.TXTOut();
	cout << endl;
	data3.TXTOut("out.txt");
	data3.BINOut("BINOut.bin");
	data3.sort();
	data3.TXTOut("ќтсторитованные данные.txt");
	cout << "и те и те, только отсортированные по курсу :" << endl;
	data3.TXTOut();
	cout << endl;
	cout << "студенты с одной специальностью в третьем контейнере :" << endl;
	data3.poiskOdnoiSpecialnsti();
	system("pause");
	return 0;
}