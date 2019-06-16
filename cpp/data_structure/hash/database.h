#ifndef DATA_BASE_H
#define DATA_BASE_H

#include <string>
#include <vector>
#include "data.h"
using namespace std;

class DataBase {
	vector<Data> db;
	unsigned size;
public:
	DataBase() : size(0) {
	}
	
	void add(string const& name, string const& data) {
		Data temp(name, data);
		db.push_back(temp);
		++size;
	}
	void add(Data const& d) {
		db.push_back(d);
		++size;
	}
	
	Data const& get(int index) const{
		return db.at(index);
	}
	
	Data const& operator[](int index) const{
		return get(index);
	}
	
	vector<Data> const& getData() const{
		return db;
	}
	
	unsigned getSize() const{
		return size;
	}
};

#endif
