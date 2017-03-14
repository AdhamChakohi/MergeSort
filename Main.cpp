#include <iostream>
using namespace std;

class Node{
public:
	int data;
	Node *next;
};

Node* createLinkedList(){
	Node *startptr = nullptr;
	Node *endptr = nullptr;
	while (true){
		int num;
		cin >> num;
		if (num == 0) break;
		if (startptr == nullptr && endptr == nullptr){
			startptr = new Node;
			startptr->data = num;
			startptr->next = nullptr;
			endptr = startptr;
		} else{
			Node *nextendptr = new Node;
			nextendptr->data = num;
			nextendptr->next = nullptr;
			endptr->next = nextendptr;
			endptr = nextendptr;
		}
	}
	return startptr;
}


Node* getMidpoint(Node *startptr){
	Node *fast = startptr->next;
	Node *slow = startptr;
  if (startptr != NULL){
	while (fast != NULL && fast->next != NULL) {
		fast = fast->next;
		fast = fast->next;
		slow = slow->next;
    }
		return slow;
  }
}

Node* merge(Node *x, Node *y){
	Node *min = nullptr;
	if (x == nullptr){
     return y;
   }
	if (y == nullptr){
   return x;
 }
	if (x->data > y->data){
		min = y;
		min->next = merge(x, y->next);
	}
  else{
		min = x;
		min->next = merge(x->next, y);
	}
	return min;
}

Node* mergeSort(Node *startptr){
	Node *lPtr = startptr;
	if (startptr->next == nullptr) {
		return startptr;}
	lPtr = getMidpoint(startptr);
	Node *rPtr = lPtr->next;
	lPtr->next = nullptr;
	lPtr = startptr;
	Node *leftList = mergeSort(lPtr);
	Node *rightList = mergeSort(rPtr);
	return merge(leftList, rightList);
}

void print(Node *startptr){
	while (startptr != nullptr){
		cout << startptr->data << ' ';
		startptr = startptr->next;
	}
}

int main(){
  cout<<"Enter numbers that you need to be sorted, enter 0 to stop."<<endl;
	Node *startptr = createLinkedList();
	cout << "Numbers entered: ";
	print(startptr);
  cout<<endl;
	startptr = mergeSort(startptr);
	cout << "After sorting: ";
	print(startptr);
  cout<<endl;
  while (startptr != nullptr){
		Node *tmp = startptr->next;
		delete startptr;
		startptr = tmp;
	}
	return 0;
}
