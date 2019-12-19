#include <iostream>


using namespace std;

/*
Веретило Илья 
задача соседи со своим стеком
*/

class qwerty {
public:
	struct azaza{
		void * data;
		azaza * next;
		azaza() ;
		~azaza() {};
	};
	azaza * head;
	int size;
	qwerty() ;
	~qwerty() ;
	void push(void * data) ;
	void deleteTop() ;
	void* top() ;
	int getSize() ;
};

qwerty::azaza::azaza() {
	data = NULL;
	next = NULL;
}
qwerty::qwerty() {
	head = new azaza;
	size = 0;
}
qwerty::~qwerty() {
	azaza *q = head;
	while (q != NULL) {
		azaza *saveNext = q->next;
		delete q;
		q = saveNext;
	}
}
void qwerty::push(void * data) {
	azaza *newAzaza = new azaza;
	newAzaza->data = data;
	newAzaza->next = head;
	head = newAzaza;
	size++;
}
void qwerty::deleteTop() {
	azaza *save = head->next;
	delete head;
	head = save;
	size--;
}
void* qwerty::top() {
	return head->data;
}
int qwerty::getSize() {
	return size;
}

int main() {
	qwerty a;
	setlocale(LC_ALL, ".1251");
	cout << "введите количество цифр" << endl;
	int num;
	cin >> num;
	cout << "введите строку цифр" << endl;
	for (int i = 0; i < num; i++) { // ввод
		int temp;
		cin >> temp;
		a.push((void*)(int*)temp);
	}
	int result = 0;
	while (a.size > 2) { // цикл поиска соседей
		int q, w, e; // достаем из стэка 3 числа
		q = (int)(int*)a.top();
		a.deleteTop();
		w = (int)(int*)a.top();
		a.deleteTop();
		e = (int)(int*)a.top();
		a.deleteTop();
		if (e == q) { // проверяем на соседей
			result++;
		}
		a.push((void*)(int*)e); // засовываем обратно
		a.push((void*)(int*)w);
	}
	cout << "количество чисел, у которых одинковые соседи = ";
	cout << result << endl;
	system("pause");
	return 0;
}