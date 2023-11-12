#pragma once

#include "Node.h"

class Ejercicio01
{

private: 
		Node<int>* reverseLinkedList(Node<int>* head);
		Node<int>* Helper(Node<int>* l1, int sizeL1, Node<int>* l2, int sizeL2);
public:
	Node<int>* addTwoNumbers(Node<int>* l1, int sizeL1, Node<int>* l2, int sizeL2);


};
