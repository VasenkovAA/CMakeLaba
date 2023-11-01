// Copirite 2023 Vasenkov Andrey
#ifndef _LIST_H_
#define _LIST_H_
//#include <iostream>

template<typename T>
class TNode {
	T data_;
	TNode* pNext_;
public:
	TNode(const T& tmp, TNode* _pNext = nullptr) : data_(tmp), pNext_(_pNext) {}
	~TNode() {}
	TNode* getNext() const { return pNext_; }
	void setNext(TNode* node) { pNext_ = node; }
	T& getData() { return data_; }
};

template<typename T>
class TList {
	int count_;
	TNode<T>* pTail_;
	TNode<T>* pHead_;
public:
	TList() : count_(0), pTail_(nullptr), pHead_(nullptr) {}
	TList(T* ObjectMass, int MassSize) {}
	~TList() {
		TNode<T>* currentNode = pHead_;
		while (currentNode != nullptr) {
			TNode<T>* nextNode = currentNode->getNext();
			delete currentNode;
			currentNode = nextNode;
		}
		pTail_ = nullptr;
		pHead_ = nullptr;
	}

	void push_back(const T& data) {
		TNode<T>* newNode = new TNode<T>(data, nullptr);
		if (pHead_ == nullptr) {
			pHead_ = newNode;
			pTail_ = newNode;
		}
		else {
			pTail_->setNext(newNode);
			pTail_ = newNode;
		}
		count_++;
	}

	void push_front(const T& data) {
		TNode<T>* newNode = new TNode<T>(data, pHead_);
		pHead_ = newNode;
		if (pTail_ == nullptr) {
			pTail_ = newNode;
		}
		count_++;
	}

	void insert(const T& data, int index) {
		if (index > count_) {

			throw std::logic_error("index exceeded the length of the list");
		}
		if (index == 0) {
			push_front(data);
			return;
		}
		if (index == count_) {
			push_back(data);
			return;
		}
		TNode<T>* currentNode = pHead_;
		for (unsigned int i = 0; i < index - 1; i++) {
			currentNode = currentNode->getNext();
		}
		TNode<T>* newNode = new TNode<T>(data, currentNode->getNext());
		currentNode->setNext(newNode);
		count_++;
	}

	void remove(const T& data) {
		TNode<T>* currentNode = pHead_;
		TNode<T>* previousNode = nullptr;
		while (currentNode != nullptr) {
			if (currentNode->getData() == data) {
				if (previousNode == nullptr) {
					pHead_ = currentNode->getNext();
				}
				else {
					previousNode->setNext(currentNode->getNext());
				}
				if (currentNode == pTail_) {
					pTail_ = previousNode;
				}
				delete currentNode;
				count_--;
				return;
			}
			previousNode = currentNode;
			currentNode = currentNode->getNext();
		}
	}

	void pop_back() {
		if (count_ == 0) {
			return;
		}
		if (count_ == 1) {
			delete pTail_;
			pHead_ = nullptr;
			pTail_ = nullptr;
			count_ = 0;
			return;
		}
		TNode<T>* currentNode = pHead_;
		while (currentNode->getNext() != pTail_) {
			currentNode = currentNode->getNext();
		}
		delete pTail_;
		pTail_ = currentNode;
		pTail_->setNext(nullptr);
		count_--;
	}

	void pop_front() {
		if (count_ == 0) {
			return;
		}
		if (count_ == 1) {
			delete pHead_;
			pHead_ = nullptr;
			pTail_ = nullptr;
			count_ = 0;
			return;
		}
		TNode<T>* nodeToRemove = pHead_;
		pHead_ = pHead_->getNext();
		delete nodeToRemove;
		count_--;
	}

	void insert(TNode<T>* node) {
		if (pHead_ == nullptr) {
			pHead_ = node;
			pTail_ = node;
			node->setNext(nullptr);
		}
		else {
			pTail_->setNext(node);
			pTail_ = node;
			node->setNext(nullptr);
		}
		count_++;
	}

	void Delete(TNode<T>* node) {
		TNode<T>* currentNode = pHead_;
		TNode<T>* previousNode = nullptr;
		while (currentNode != nullptr) {
			if (currentNode == node) {
				if (previousNode == nullptr) {
					pHead_ = currentNode->getNext();
				}
				else {
					previousNode->setNext(currentNode->getNext());
				}
				if (currentNode == pTail_) {
					pTail_ = previousNode;
				}
				delete currentNode;
				count_--;
				return;
			}
			previousNode = currentNode;
			currentNode = currentNode->getNext();
		}
	}

	int getCount() {
		return count_;
	}

	bool isEmpty() {
		return(count_ == 0);
	}

	T& Head() {
		return (pHead_->getData());
	}
	T& Tail() {
		return (pTail_->getData());
	}

	bool hasCycleByFloid() {
		if (pHead_ == nullptr) {
			return false;
		}
		TNode<T>* slow = pHead_;
		TNode<T>* fast = pHead_->getNext();
		while (fast != nullptr && fast->getNext() != nullptr) {
			if (slow == fast) {
				return true;
			}
			slow = slow->getNext();
			fast = fast->getNext()->getNext();
		}
		return false;
	}
	bool hasCycleByHash() {
		std::unordered_set<TNode<T>*> visited;
		TNode<T>* currentNode = pHead_;
		while (currentNode != nullptr) {
			if (visited.count(currentNode) > 0) {
				return true;
			}
			visited.insert(currentNode);
			currentNode = currentNode->getNext();
		}
		return false;
	}
	bool hasCycleByRevers() {
		TNode<T>* currentNode = pHead_;
		TNode<T>* previousNode = nullptr;
		while (currentNode != nullptr) {
			TNode<T>* nextNode = currentNode->getNext();
			currentNode->setNext(previousNode);
			previousNode = currentNode;
			currentNode = nextNode;
		}
		return (previousNode != pHead_);
	}
};






#endif // !_LIST_H_
