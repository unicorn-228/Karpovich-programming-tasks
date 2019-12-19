#pragma once

class spIsOk {
	struct item {
		item * next;
		item * prev;
		void * data;
		item();
		~item() {};
	};
	item * head;
	item * tail;
public:
	spIsOk();
	~spIsOk() {};
private: int size;
public:
	void push_top(void * a);
	void push_back(void * a);
	void * look_front();
	void * look_back();
	void * pop_front();
	void * pop_back();
	void * lookByIndex(int index);
	void * popByIndex(int index);
	void * popByIndexAndChangeHeadAndTail(int index);
	void makeItCircle();
	void coutListInt();
	int getSize();
};