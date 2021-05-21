#include "stdafx.h"
#include <iostream>

struct elem
{
	int data;
	elem* next;
};

elem* push_first(elem* head, int data)
{
	if (head == nullptr)
	{
		head = new elem;
		head->data = data;
		head->next = nullptr;
		return head;
	}
	else
	{
		elem* tmp = new elem;
		tmp->data = data;
		tmp->next = head;
		return tmp;
	}
}

elem* pop_first(elem* head)
{
	if (head == nullptr) return nullptr;
	elem* tmp = head;
	head = head->next;
	delete tmp;
	return head;
}

elem* pop_last(elem* head) {
	
	if (head == nullptr) {
		return NULL;
	}
	if (head->next == nullptr) {
		delete head;
		return NULL;
	}
	elem* copyhead = head;
	while (head->next->next != nullptr)
	{
		head = head->next;
	}
	delete head->next;
	head->next = NULL;
	return copyhead;
}

void print_list(elem* head)
{
	std::cout << "Our list: ";
	while (head != nullptr) {
		std::cout << head->data << " ";
		head = head->next;
	}
	std::cout << std::endl;
}

elem* push_back(elem* head, int data)
{
	elem* tmp = new elem;
	tmp->next = nullptr;
	tmp->data = data;
	if (head == nullptr) return tmp;

	elem* copy_head = head;
	while (head->next != nullptr)
	{
		head = head->next;
	}
	head->next = tmp;
	return copy_head;
}

int main() {
	elem* head = nullptr;
	for (int i = 0; i < 10; i++)
		head = push_back(head, i);
	print_list(head);
	pop_last(head);
	print_list(head);
	return 0;
}
