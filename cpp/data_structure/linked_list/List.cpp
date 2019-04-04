#include <iostream>
#include <string>
#include "List.h"
using namespace std;
template <typename T>
List<T>::List() {
	_head = new Node<T>;
	_end = new Node<T>;
	_head->_next = _end;
	_head->_pre = NULL;
	_end->_pre = _head;
	_end->_next = NULL;
	_size = 0;
}

template <typename T>
void List<T>::add(T const& s) {
	Node<T>* newNode = new Node<T>;
	newNode->_data = s;
	newNode->_next = _end;
	newNode->_pre = _end->_pre;
	_end->_pre->_next = newNode;
	_end->_pre = newNode;
	_size++;
}

template <typename T>
void List<T>::insert(T const& s, int index) { //index代表插入位置，0为第一个元素前面，_size为最后一个元素后面
	if (index < 0 || index > _size) {
		cerr << "Illegal parameter index (Out of range).\n";
		throw "index = " + index;
	}

	Node<T>* newNode = new Node<T>;
	newNode->_data = s;
	Node<T>* temp = _head;
	for (int i = 0; i < index; i++) {
		temp = temp->_next; //移动temp到待插入位置前一个元素
	}
	newNode->_pre = temp;
	newNode->_next = temp->_next;
	temp->_next->_pre = newNode;
	temp->_next = newNode;
	_size++;
}

template <typename T>
T& List<T>::get(int index) {    //Range 0 - (size - 1)
	if (index < 0 || index > _size) {
		cerr << "Illegal parameter index (Out of range).\n";
		throw "index = " + index;
	}

	Node<T>* temp = _head->_next;
	for (int i = 0; i < index; i++) {
		temp = temp->_next;
	}
	return temp->_data;
}

template <typename T>
T List<T>::find(T const& s, string p) {
	if (p != "forward" && p != "backward") {
		cerr << "Illegal parameter prompt (Unknown order).\n";
		throw "prompt = " + p;
	}
	
	Node<T>* temp = _head->_next;
	for (int i = 0; i < _size; i++) {
		if (temp->_data == s) {
			if (p == "forward")return temp->_next->_data;
			if (p == "backward")return temp->_pre->_data;
			break;
		}
		temp = temp->_next;
	}
	return NULL;
}

template <typename T>
void List<T>::remove(int index) {
	if (index < 0 || index > _size) {
		cerr << "Illegal parameter index (Out of range).\n";
 		throw "index = " + index;
	}

	Node<T>* temp = _head->_next;
	for (int i = 0; i < index; i++) {
		temp = temp->_next;
	}
	temp->_next->_pre = temp->_pre;
	temp->_pre->_next = temp->_next;
	delete temp;
	_size--;
}

template <typename T>
void List<T>::print() {
	if (_size == 0) {
		cout << "{ (Empty list) }" << endl;
		return;
	}
	Node<T>* temp = _head->_next;
	cout << "[ ";
	for (int i = 0; i < _size - 1; i++) {
		cout << temp->_data << ", ";
		temp = temp->_next;
	}
	cout << temp->_data << " ]" << endl;
}

template <typename T>
int List<T>::size() {
	return _size;
}
