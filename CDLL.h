#pragma once
#include<iostream>
using namespace std;

template <class Item>
class CDLL {
private:
		class Node {
		public:
			Node(Item val, Node * nx = NULL, Node *pr =NULL) : value(val), next(nx),previous(pr) { }
			Item value;
			Node * next;
			Node * previous;// For a double linked list, need another pointer that points to the previous node to show which helps to put it in a circle formation.
	};

protected:// inorder to be used by TopSpin Protected
		Node * m_head;
		Node * m_tail;
		unsigned int m_size;
public:
	//Inline method prototypes and out of class definitions 
	CDLL();
	~CDLL();

	void addData(Item d);
		void incrementHead();
		void decrementHead();
	void swap(unsigned int src, unsigned int dst);
	Item getData (unsigned int i)const;

};

template <class Item>
CDLL<Item> ::CDLL() {// Default Constructor then sets all member variables to null and 0.
	m_head = NULL;
	m_tail = NULL;
	m_size=0;
	
	
}

template <class Item>
CDLL<Item> :: ~CDLL() {// Destructor
	
	Node * here = m_head;//Assigning a temporary node pointer as head of the existing nodes, this is 
	Node *nextNode = NULL;//Creating another temporary node pointer and setting NULL to be further used in the for loop
	

	

	for (int b = 1; b <= m_size; b++)// Goes through each element in the list using nextNode and then deletes the other temporary node ptr here. After that, it reassings here to nextnode so when it enters loop again it is ready to go the next node/next element in the list. Then repeat.
	{
		nextNode = here->next;
		delete here;
		here = nextNode;
	}


}

template <class Item>//This function links all items/nodes/elements together into a circular double linked list.
void CDLL<Item> ::addData(Item d)
{
	
	if (m_size==0)// If there is no nodes/elements yet and this is the first element being assigned then...

		// This program starts by dynamically assigning the value passed into the function into an arbitary node pointer. This is assigned to m_Head.

		// First I assign the value b to m_head through this way. Since only one element, m_head's next points to itself.

		//Next the head is also the tail because there is only one element. Finally m_head's previous is tail to link the two elements together, creating two nodes and connecting them in a circle properly.
	{
		Node *b = new Node(d);
		m_head = b;
		m_head->next = m_head; 
		m_tail = m_head;
		m_head->previous = m_tail;
		
		m_size++;// Incrementing and updating size from 0 to 1 to show one element is in the list.
	}
	else// If there is a node already present we create another aribtary node that is assigned to d as it's value.
		// That arbitary node a's next is head, as it is now the new tail. A's previous is the old tail as that is behind the new tail a.
		//Finally updating m_tail's next and m_head's to A (the new tail). We can assign m_tail with a.
	{
		
		Node *a = new Node(d);
		a->next = m_head;
		a->previous = m_tail;
		m_tail->next = a;
		m_tail = a;
		m_head->previous = a;
		
		
		m_size++;// Increments and Updates size.
	}
	
	}



template <class Item>
void CDLL<Item>::incrementHead() {// Increment head means the element/node after head becomes the new head and everything else moves over.

	// So first update to show that new m_Head is now old m_head's next.
	m_head= m_head->next;
	m_tail = m_tail->next;
	// Same for tail, new m_tail is old m_tail's next.


	}


template <class Item>
void CDLL<Item> ::decrementHead() {// Opposite of increment. Moving head to it's previous node and same with tail.
	m_tail = m_tail->previous;
	m_head = m_head->previous;
	
}

template <class Item>
void CDLL<Item> ::swap(unsigned int src, unsigned int dst) {//This takes the value at node at the src position and swaps with the value at the dst position.
	Node *a = NULL;
	Node*b= NULL;
	a = m_head;
	b = m_head;
	//Creating two arbitary node pointer both set to m_head inorder to run through the node until src and dst.
	for (int j = 1; j < src; j++)//Loop that runs till src and assigns to a.
	{
		a = a->next;
	}
	for (int k = 1; k < dst; k++)// Loop that runs till dst th node and is assigned to b.
	{
		b = b->next;
	}
	
	int x;// creating a temporary value to assign it as the a's value.
	x = a->value;
	a->value = b->value;// Setting a's value as b's value.
	b->value = x;// Setting b's value as x (which keeps a's original value). Hence swapped.
		
}

template <class Item>
Item CDLL<Item> ::getData(unsigned int i)const {
	//Precondition  i must be a valid current list position 1<=i<=size()-> Programmed in Top-Spin
	
		Node * here = m_head;// creating an aribtary note pointer inorder to loop through it's next and return it's value until the ith node/element in the list
		for (unsigned int k = 1; k < i; k++)
		{
			here = here->next;
		}
		
		return here->value;
	
		}
