template <class T>
struct BinNode {
	T data;
	BinNode* left;
	BinNode* right;
	
	static BinNode<T>* combine(BinNode<T>*, BinNode<T>*);
};

BinNode<T>* BinNode<T>::combine(BinNode<T>* leftNode, BinNode<T>* rightNode) {
	BinNode<T>* root = new BinNode<T>;
	root->left = leftNode;
	root->right = rightNode;
}

template <class T>
class BinTree {
	
	BinNode<T>* root;
	
public:
	BinTree();
	~BinTree();
	static virtual void combine(BinTree<T>, BinTree<T>);
	BinNode<T> getRoot();
};

template <class T>
BinTree<T>::BinTree() {
	root = new BinNode<T>;
	root
}
