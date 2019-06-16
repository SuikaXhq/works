#ifndef DATA_H
#define DATA_H

#include <string>
#include <fstream>
#include <vector>
using namespace std;

class Data {
	string name;
	string data;
public:
	Data(string const& n, string const& d) : name(n), data(d) {}
	virtual string const& getName() const { return name; }
	virtual string const& getData() const { return data; }
	virtual void setName(string const& n) { name = n; }
	virtual void setData(string const& d) { data = d; }
};

struct Result {
	string DBname;
	unsigned offset;
};

class Query : public Data {
	vector<Result> results;
public:
	Query(string const& n, string const& d) : Data(n, d) {}
	
	virtual void addResult(string name, unsigned offset) {
		Result temp;
		temp.DBname = name;
		temp.offset = offset;
		results.push_back(temp);
	}
	
	virtual vector<Result> const& getResults() const{
		return results;
	}
	
	friend ofstream& operator<<(ofstream& output, Query const& q) {
		output << q.getName() << '\n';
		
		if (q.getResults().size() != 0) {
			for (auto r : q.getResults()) {
				output << '[' << r.DBname << ']' << " at offset " << r.offset << '\n';
			}
			
		} else {
			output << "NOT FOUND" << '\n';
		}
		
		output << endl;

		return output;
	}
};

#endif
