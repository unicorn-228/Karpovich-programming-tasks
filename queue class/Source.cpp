#include <iostream>
#include "Header.h"

using namespace std;
/*
Веретило Илья 7 группа
задача лист бумаги на своей очереди

*/




struct Point {
	int i;
	int q;
};

void addNULL(int **data, qwerty &lol, int i, int q , int n , int m) {
	if (i > 0) {
		if (data[i - 1][q] == 0) {
			Point *temp = new Point;
			temp->i = i - 1;
			temp->q = q;
			lol.push((void*)temp);
		}
	}
	if (i < n-1) {
		if (data[i + 1][q] == 0) {
			Point *temp = new Point;
			temp->i = i + 1;
			temp->q = q;
			lol.push((void*)temp);
		}
	}
	if (q > 0) {
		if (data[i][q - 1] == 0) {
			Point *temp = new Point;
			temp->i = i;
			temp->q = q - 1;
			lol.push((void*)temp);
		}
	}
	if (q < m-1) {
		if (data[i][q + 1] == 0) {
			Point *temp = new Point;
			temp->i = i;
			temp->q = q + 1;
			lol.push((void*)temp);
		}
	}
	data[i][q] = 2;
}

void coutData(int **data, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int q = 0; q < m; q++) {
			cout << data[i][q] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main() {
	qwerty lol;
	cout << "vvedite razmer bumagi" << endl;
	int n, m;
	cin >> n >> m;
	cout << "vvedite pole bumagi" << " " << n << "x" << m << endl;
	cout << "0 - bumaga , 1 - razrez" << endl;
	int **data = new int*[n];
	for (int i = 0; i < n; i++) {
		data[i] = new int[m];
		for (int q = 0; q < m; q++) {
			int temp;
			cin >> temp;
			data[i][q] = temp;
		}
	}
	int result = 0;
	for (int i = 0; i < n; i++) {
		for (int q = 0; q < m; q++) {
			if (data[i][q] == 0) {
				addNULL(data, lol, i, q, n, m);
				while (lol.getSize() != 0) {
					Point *temp = new Point;
					temp = (Point*)lol.top();
					lol.deleteTop();
					addNULL(data, lol, temp->i, temp->q, n, m);
					//coutData(data, n, m);
					//cout << result << endl;
				}
				result++;
			}
		}
	}
	cout << "listok raspadetsa na " << result << " novix listka" << endl;
	system("pause");
	return 0;
}