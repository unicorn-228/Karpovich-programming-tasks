#include "Header.h"
#include "qwe.cpp"

using namespace std;




int main() {
	setlocale(LC_ALL, ".1251");
	CONTAINER <stud_1> data1;
	CONTAINER <stud_2> data2;
	CONTAINER <stud_3> data3;
	data1.resize(10);
	data1.TXTIn("�������������������������.txt");
	data2.resize(10);
	data2.TXTIn("�������������������������.txt");
	data3.resize(10);
	cout << "�������� �������� ��������� :" << endl;
	data1.TXTOut();
	cout << endl;
	cout << "�������� �������� :" << endl;
	data2.TXTOut();
	cout << endl;
	data3 =  data1 + data2;
	cout << "�� ��� ���� � ��� � ��� :" << endl;
	data3.TXTOut();
	cout << endl;
	data3.TXTOut("out.txt");
	data3.BINOut("BINOut.bin");
	data3.sort();
	data3.TXTOut("��������������� ������.txt");
	cout << "� �� � ��, ������ ��������������� �� ����� :" << endl;
	data3.TXTOut();
	cout << endl;
	cout << "�������� � ����� �������������� � ������� ���������� :" << endl;
	data3.poiskOdnoiSpecialnsti();
	system("pause");
	return 0;
}