#ifndef NODE_H
#define NODE_H
template <typename T>
struct Node {
	std::string _data;
	Node* _pre;
	Node* _next;
};
#endif
