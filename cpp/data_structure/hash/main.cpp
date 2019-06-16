#include <iostream>
#include "hash.h"
#include "database.h"
#include <string>
#include <iostream>
#include <fstream>
#include <exception>
using namespace std;


void simple_query(Data const& data, Query& q, Hasher& hasher) {     // query processing function for one sequence of data
	unsigned qlength = q.getData().size();
	unsigned dlength = data.getData().size();
	string head = data.getData().substr(0, qlength);
	unsigned queryHash = hasher.hash(q.getData());
	unsigned dataHash = hasher.hash(head);
	
	if (dataHash == queryHash) {        // judge if the first part of data == query data
		bool flag = true;
		for (int i = 0; i < qlength; ++i) {
			if (data.getData()[i] != q.getData()[i]) {
				flag = false;
				break;
			}
		}

		if (flag) {
			q.addResult(data.getName(), 0);
			cout << "Found in " << data.getName() << " at offset 0" << endl;
			return;
		}
	}
	
	for (int i = 1; i < dlength-qlength+1; ++i) {     // index from 1 to dlength-qlength
		dataHash = hasher.nextHash( data.getData()[i-1], data.getData()[i-1+qlength] );
		if (dataHash == queryHash) {	//collision
			
			bool flag = true;
			for (int j = 0; j < qlength; ++j) {
				if ( data.getData()[i+j] != q.getData()[j] ) {
					flag = false;
					break;
				}
			}
			
			if (flag) {
				q.addResult(data.getName(), i);
				cout << "Found in " << data.getName() << " at offset " << i << endl;
				return;
			}
			
		}
	}

	cout << "Not found in " << data.getName() << endl;
}

void query(DataBase const& db, Query& q) {      // main query processing function
	Hasher hasher(5, q.getData().size());
	for (auto data : db.getData()) {
		simple_query(data, q, hasher);
	}
}

int main() {
	
	try {

		string DBname, QBname, resultName;      // file names
		cout << "Please input Data Base file name: ";
		cin >> DBname;
		cout << "Please input Query Base file name: ";
		cin >> QBname;
		cout << "Please input result file name: ";
		cin >> resultName;
		
		cout << "\nReading data base..." << endl;
		
		ifstream DB, QB;
		DB.open(DBname, ios::in);
		QB.open(QBname, ios::in);
		
		ofstream result;
		result.open(resultName, ios::out);
		
		DataBase dataBase;

		time_t startTime = time(0);
		
		// reading database
		while (1) {
			if (DB.peek() == '>') {
				string tempname, data, tempdata;
				DB.ignore();
				getline(DB, tempname);
				if (tempname == "EOF")
					break;
				
				while (DB.peek() != '>') {
					getline(DB, tempdata);
					data = data + tempdata;
				}
				dataBase.add(tempname, data);
				cout << tempname << " added." << endl;
			} else {
				cout << "Unexcepted input found." << endl;
				exit(0);
			}
		}
		
		// processing query
		cout << "\nProcessing queries..." << endl;
		while (1) {
			if (QB.peek() == '>') {
				string tempname, data, tempdata;
				QB.ignore();
				getline(QB, tempname);
				if (tempname == "EOF")
					break;
				cout << "Processing " << tempname << endl;
				while (QB.peek() != '>') {
					getline(QB, tempdata);
					data = data + tempdata;
				}
				cout << data << endl;
				Query q(tempname, data);
				query(dataBase, q);
				result << q;
				cout << tempname << " processed." << endl;
			} else {
				cout << "Unexcepted input found." << endl;
				exit(0);
			}
		}
		
		time_t endTime = time(0);

		cout << "Time cost: " << (endTime - startTime) << 's'  << endl;
		cout << "\nAll queries processed. Program ended." << endl;
		system("pause");

	} catch (exception& e) {
		cout << e.what() << endl;
	}
}



