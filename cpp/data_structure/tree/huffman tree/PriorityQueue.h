template <class T>
struct ListNode {
	int priority;
	T data;
	ListNode* next;
};

template <class T>
class PriorityQueue {
	ListNode<T>* head;
	int size;
	ListNode<T>* findProperPosition(int);    //找到适合新结点的位置，priority越大，队列中越靠后
	
public:
	PriorityQueue();
	~PriorityQueue();
	void push(const T&, int);
	bool pop(T&);
	bool pop();
	T& front();
	bool empty();   //return true if empty
	
};

template <class T>
PriorityQueue<T>::PriorityQueue(){
	head = new ListNode<T>;
	head->next = 0;
	head->priority = 0;
	size = 0;
}

template <class T>
PriorityQueue<T>::~PriorityQueue() {
	while (!empty()) {		//pop all 
		pop();
	}
	delete head;
}

template <class T>
void PriorityQueue<T>::push(const T& data, int prior) {
	ListNode<T>* newNode = new ListNode<T>;
	newNode->data = data;
	newNode->priority = prior;

	ListNode<T>* preNode = findProperPosition(prior);
	newNode->next = preNode->next;
	preNode->next = newNode;
	++size;
}

template <class T>
ListNode<T>* PriorityQueue<T>::findProperPosition(int prior) {
	ListNode<T>* temp = head;
	while (temp->next != 0 && temp->next->priority <= prior) {
		temp = temp->next;
	}
	return temp;	//返回最后一个优先级小于等于prior的结点 
}

template <class T>
bool PriorityQueue<T>::pop(T& value) {
	if (!empty()) {
		ListNode<T>* temp = head->next;
		value = temp->data;
		head->next = temp->next;
		delete temp;
		--size;
		return true;
	} else {
		return false;
	}
	
}
template <class T>
bool PriorityQueue<T>::pop() {
	if (!empty()) {
		ListNode<T>* temp = head->next;
		head->next = temp->next;
		delete temp;
		--size;
		return true;
	} else {
		return false;
	}
}
template <class T>
T& PriorityQueue<T>::front() {
	if (!empty()) {
		return head->next->data;
	} else {
		throw "The queue is empty.";
	}
}
template <class T>
bool PriorityQueue<T>::empty() {
	return size==0;
}
