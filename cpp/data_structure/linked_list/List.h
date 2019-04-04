#ifndef LIST_H
#define LIST_H
#include "Node.h"
#include <string>
using std::string;
template <typename T>
class List {
	Node<T>* _head;
	Node<T>* _end;
	int _size;
public:
	List();
	void add(T const&);
	void insert(T const&, int);
	T& get(int);
	T find(T const&, string);
	void remove(int);
	void print();
	int size();
};
#endif
