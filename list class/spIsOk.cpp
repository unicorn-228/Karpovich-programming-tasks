#include "Header.h"
#include <iostream>

using namespace std;

void spIsOk::coutListInt() {
	item *q = head;
	while (q != tail) {
		cout << (int)(int *)q->data << " ";
		q = q->next;
	}
	cout << (int)(int *)tail->data;
	cout << endl;
}

void spIsOk::push_top(void * a) {

	if (size == 0) {
		item * qwerty = new item;
		qwerty->data = a;
		head = qwerty;
		tail = qwerty;
	}
	else {
		item *q = new item;
		q->data = a;
		q->next = head;
		q->prev = head->prev;
		head->prev = q;
		head = q;
	}
	size++;
}
void spIsOk::push_back(void * a) {

	if (size == 0) {
		item * qwerty = new item;
		qwerty->data = a;
		head = qwerty;
		tail = qwerty;
	}
	else {
		item *q = new item;
		q->data = a;
		q->next = tail->next;
		q->prev = tail;
		tail->next = q;
		tail = q;
	}
	size++;
}
void * spIsOk::pop_front() {

	void * data_q = head->data;
	if (head->next != NULL) head->next->prev = head->prev;
	if (head->prev != NULL) head->prev->next = head->next;
	head = head->next;
	size--;
	return data_q;
}
void * spIsOk::pop_back() {
	void * data_q = tail->data;
	if (tail->next != NULL) tail->next->prev = tail->prev;
	if (tail->prev != NULL) tail->prev->next = tail->next;
	tail = tail->prev;
	size--;
	return data_q;
}

void * spIsOk::lookByIndex(int index) {
	item *temp = head;
	while (index != 0) {
		temp = temp->next;
		index--;
	}
	return temp->data;
}

void * spIsOk::popByIndex(int index) {
	item *temp = head;
	while (index != 0) {
		temp = temp->next;
		index--;
	}
	temp->next->prev = temp->prev;
	temp->prev->next = temp->next;
	void * q = temp->data;
	delete temp;
	size--;
	return q;
}

void * spIsOk::popByIndexAndChangeHeadAndTail(int index) {
	item *temp = head;
	while (index != 0) {
		temp = temp->next;
		index--;
	}
	temp->next->prev = temp->prev;
	temp->prev->next = temp->next;
	head = temp->next;
	tail = temp->prev;
	void * q = temp->data;
	delete temp;
	size--;
	return q;
}

void spIsOk::makeItCircle() {
	tail->next = head;
	head->prev = tail;
}

void * spIsOk::look_front() {
	return head->data;
}

void * spIsOk::look_back() {
	return tail->data;
}

int spIsOk::getSize() {
	return size;
}

spIsOk::item::item() {
	next = NULL;
	prev = NULL;
	data = NULL;
}
spIsOk::spIsOk() {
	head = NULL;
	tail = NULL;
	size = 0;
}