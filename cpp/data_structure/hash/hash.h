#ifndef HASH_H
#define HASH_H

#include <string>
#include <ctime>
using namespace std;

static const double phi = 0.6180339887;

class Hasher {
	unsigned base;  // a prime number for base
	unsigned mbase; // base ^ (|q|-1)
	unsigned ql;     // query length
	unsigned oldhash;     // hash code of previous one

	//universal hash
	unsigned a;
	unsigned b;
	unsigned p;
	
	
	unsigned prehash(string const& s) {     //encoding s to a number
		unsigned rawhash = 0;
		for (int i=0; i<ql; ++i) {
			rawhash *= base;
			rawhash += getCode(s[i]);
		}
		oldhash = rawhash;
		return rawhash;
	}

	unsigned nextPrehash(char head, char next) {    //encoding next s to a number using previous result
		oldhash -= getCode(head) * mbase;
		oldhash *= base;
		oldhash += getCode(next);
		return oldhash;
	}
	
	unsigned selectHash(unsigned temp, int mode) {      // mode=0: Division Hash, mode=1: Multiplication Hash, mode=2: Universal Hash
		switch (mode) {
		case 0:
			return temp % ql;
  		case 1:
  			return unsigned( ql * ( (phi * temp) - unsigned(phi * temp) ) );
		case 2:
			return ( (a * temp + b) % p ) % ql;
		}
	}
	
public:
	Hasher(unsigned b, unsigned q) : base(b), mbase(1), ql(q), oldhash(0) {
		for (int i=1; i<ql; ++i) {
			mbase *= base;
		}
		
		//universal hash
		p = 244244587;		// a prime near 5^12
		srand(time(0));
		a = ( rand() % (p-1) ) + 1;
		b = rand() % p;
	}
	
	// hash functions
	unsigned hash(string const& s, int mode=0) {
		return selectHash(prehash(s), mode);
	}
	
	unsigned nextHash(char head, char next, int mode=0) {
		return selectHash(nextPrehash(head, next), mode);
	}
	

	unsigned getCode(char c) {      // encoding ACTG
		switch (c) {
		case 'A':
			return 0;
		case 'C':
			return 1;
		case 'T':
			return 2;
		case 'G':
			return 3;
		}
	}
	
};

#endif
