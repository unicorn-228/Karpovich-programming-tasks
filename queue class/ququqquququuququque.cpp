#include <iostream>
#include "Header.h"

qwerty::azaza::azaza() {
	data = NULL;
	next = NULL;
}
qwerty::qwerty() {
	head = NULL;
	tail = head;
	size = 0;
}
qwerty::~qwerty() {}

void qwerty::push(void * data) {
	azaza *dat = new azaza;
	dat->data = data;
	if (tail == NULL) {
		head = dat;
		tail = dat;
	}
	else {
		tail->next = dat;
		tail = dat;
	}
	size++;
}
void qwerty::deleteTop() {
	azaza *save = head->next;
	delete head;
	head = save;
	if (size == 1) {
		head = NULL;
		tail = NULL;
	}
	size--;
}
void* qwerty::top() {
	return head->data;
}
int qwerty::getSize() {
	return size;
}