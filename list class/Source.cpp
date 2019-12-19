#include <iostream>
#include "Header.h"

using namespace std;

/*
Веретило Илья 7 группа
задача иосифа на своем списке
*/



int main() {
	spIsOk lol;
	int n, m;
	cout << "vvedite n i m" << endl;
	cout << "otschet idet s nulya" << endl;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		lol.push_back((void *)(int *)i);
	}
	lol.makeItCircle();
	int index = 0;
	while (lol.getSize() > 1) {
		lol.popByIndexAndChangeHeadAndTail(m);
	}
	cout << "nomer cheloveka, kotorii ostanetsya" << endl;
	cout << (int)(int*)lol.look_front() << endl;
	system("pause");
	return 0;
}