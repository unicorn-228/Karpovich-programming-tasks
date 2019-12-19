#pragma once
class qwerty {
public:
	struct azaza {
		void * data;
		azaza * next;
		azaza();
		~azaza() {};
	};
	azaza * head;
	azaza * tail;
	int size;
	qwerty();
	~qwerty();
	void push(void * data);
	void deleteTop();
	void* top();
	int getSize();
};