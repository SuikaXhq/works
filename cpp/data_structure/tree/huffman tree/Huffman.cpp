#include <iostream>
#include "PriorityQueue.h"
#include "BinTree.h"
#include <string>
using namespace std;


BinNode<char>* huffmanTree(char*, double*)		//参数为字符表和对应频率/频数表，返回一个Huffman树的根节点 
string* huffmanCode(char*, double*);	//参数为字符表和对应频率/频数表，返回一个顺序与字符表一致的二进制编码表
string encoder(string);					//参数为字符串，返回对应的Huffman二进制码 
string decoder(string, BinNode<char>*);		//参数为Huffman二进制码和Huffman树根节点，返回原字符串 


int main() {
	
}

string* huffmanCode(char* alphabet, double* weights) {
	
}

string encoder(string s) {
	
}

string decoder(string bins, string* root) {
	
}
