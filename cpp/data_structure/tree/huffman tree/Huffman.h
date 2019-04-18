#include <iostream>
#include "PriorityQueue.h"
#include <string>
#include <unordered_map>
using namespace std;





template <class T>
struct HuffNode {
	T data;
	int freq;       //frequency
	HuffNode* left;
	HuffNode* right;

	~HuffNode() {
		delete left;
		delete right;
	}
};





HuffNode<char>* huffmanTree(char*, int*, int);								//参数为字符表、对应频数表及大小，返回一个Huffman树的根节点
void huffmanCode(char*, int*, int);											//参数为字符表、对应频数表及大小，打印二进制编码表
string encoder(string, char*, int*, int);									//参数为字符串，返回对应的Huffman二进制码
string decoder(string, HuffNode<char>*);										//参数为Huffman二进制码和Huffman树根节点，返回原字符串
void getCode(unordered_map<char, string>&, HuffNode<char>*, string="");		//将树中字符对应的编码存入hashmap







HuffNode<char>* huffmanTree(char* alphabet, int* weights, int size) {

	//create node queue
	PriorityQueue<HuffNode<char>*> queue;
	for (int i = 0; i < size; ++i) {
		HuffNode<char>* temp = new HuffNode<char>;
		temp->data = alphabet[i];
		temp->freq = weights[i];
		temp->left = 0;
		temp->right = 0;
		queue.push(temp, temp->freq);
	}


	//construct huffman tree
	for (int i = 0; i < size-1; ++i) {

		//pick two nodes having smallest frequencies
		HuffNode<char>* temp1;
		queue.pop(temp1);
		
		HuffNode<char>* temp2;
		queue.pop(temp2);


		//create a new root node
		HuffNode<char>* newNode = new HuffNode<char>;
		newNode->data = 0;
		newNode->freq = temp1->freq + temp2->freq;
		newNode->left = temp1;
		newNode->right = temp2;

		queue.push(newNode, newNode->freq);

	}

	return queue.front();

}











void getCode(unordered_map<char, string>& map, HuffNode<char>* root, string code) {

	if (root->left == 0 && root->right == 0) {  // if root is a leaf node
		map.insert(make_pair(root->data, code));
		return;
	}


	// recursion to traverse leaf nodes
	if (root->left != 0) {
		getCode(map, root->left, code+'0');
	}
	if (root->right != 0) {
		getCode(map, root->right, code+'1');
	}

}














void huffmanCode(char* alphabet, int* weights, int size) {
	
	HuffNode<char>* tree = huffmanTree(alphabet, weights, size);
	unordered_map<char, string> codeMap;
	getCode(codeMap, tree);
	cout << endl;
	
	//print codes
	for (int i = 0; i < size; ++i) {
		cout << '\'' << alphabet[i] << "' : " << codeMap.at(alphabet[i]) << endl;
	}
	delete tree;
	
}

















string encoder(string s, char* alphabet, int* weights, int size) {

	//get huffman code
	HuffNode<char>* tree = huffmanTree(alphabet, weights, size);
	unordered_map<char, string> codeMap;
	getCode(codeMap, tree);

	//create bin string
	string bins;
	int length = s.size();
	for (int i = 0; i < length; ++i) {
		bins += codeMap.at(s[i]);
	}
	delete tree;
	return bins;
	
}













string decoder(string bins, HuffNode<char>* root) {

	int size = bins.size();
	HuffNode<char>* temp = root;
	string result;

	for (int i = 0; i < size; ++i) {

		temp = bins[i] == '0' ? temp->left : temp->right;

		if (temp->left == 0 && temp->right == 0) { // if temp is a leaf node
			result += temp->data;
			temp = root;
		}

	}

	return result;

}
