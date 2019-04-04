template <class T>
struct ListNode {
	int priority;
	T data;
	ListNode* next;
};

template <class T>
class SortedQueue {
	ListNode<T>* head;
	int size;
	ListNode<T>* findProperPosition(int);    //找到适合新结点的位置，priority越大，队列中越靠后
	
public:
	SortedQueue();
	~SortedQueue();
	bool push(const T&, int);
	bool pop(T&);
	bool pop();
	T& front();
	bool empty();   //return true if empty
	
};

template <class T>
SortedQueue<T>::SortedQueue(){
	head = new ListNode<T>;
	head->next = 0;
	head->priority = 0;
	size = 0;
}

template <class T>
SortedQueue<T>::~SortedQueue() {
	while (!empty()) {
		pop();
	}
	delete head;
}

template <class T>
bool SortedQueue<T>::push(const T& data, int prior) {
	ListNode<T>* newNode = new ListNode<T>;
	newNode->data = data;
	newNode->priority = prior;

	ListNode<T>* preNode = findProperPosition(prior);
	newNode->next = preNode->next;
	preNode->next = newNode;
	++size;
}

template <class T>
ListNode<T>* SortedQueue<T>::findProperPosition(int prior) {
	ListNode<T>* temp = head;
	while (temp->next != 0 && temp->next->priority <= prior) {
		temp = temp->next;
	}
	return temp;
}

template <class T>
bool SortedQueue<T>::pop(T& value) {
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
bool SortedQueue<T>::pop() {
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
T& SortedQueue<T>::front() {
	if (!empty()) {
		return head->next->data;
	} else {
		throw "The queue is empty.";
	}
}
template <class T>
bool SortedQueue<T>::empty() {
	return size==0;
}
