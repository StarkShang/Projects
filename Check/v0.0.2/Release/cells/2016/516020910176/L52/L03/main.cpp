#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "func__.hpp"

void showLinkedNodes(LinkedNode* head)
{
	if (head == nullptr)
	{
		std::cout << "The linked list is empty!" <<std::endl;
		return;
	}

	std::cout << "The linked list now is : " << std::endl;
	std::cout << head->data;
	while (head->next != nullptr)
	{
		head = head->next;
		std::cout << " -> " << head->data;
	}
	std::cout << std::endl;
}

int main(int argc, char* argv)
{
	int nums[1024];
	char str[1024];
	int counter = 0;
	std::cout << "Please input the number of numbers (less than 1024) : ";
	std::cin >> counter;
	std::cout << "Please input some numbers to initialize a linked list (less than 1024 numbers) : ";
	for (int i = 0; i < counter; i++) std::cin >> nums[i];
	LinkedNode* head = create(nums, counter);
	strcpy(str, "Create succeed!");

	while (true)
	{
		char cmd;
		system("cls");
		std::cout << str << std::endl;
		showLinkedNodes(head);
		std::cout << std::endl << "What do you want to do ?" << std::endl;
		std::cout << "[1] insert a node" << std::endl;
		std::cout << "[2] delete a node" << std::endl;
		std::cout << "[q] quit" << std::endl;
		std::cout << std::endl << "Input your choice : ";
		std::cin >> cmd;

		int data, index;
		LinkedNode* node;
		switch (cmd)
		{
			case '1':
				std::cout << "Please input the data you want to insert : ";
				std::cin >> data;
				std::cout << "Please input where you want to insert : ";
				std::cin >> index;
				node = new LinkedNode();
				node->data = data;
				if (insert(node, &head, index)) strcpy(str, "Insert succeed!");
				else  strcpy(str, "Insert failed!");
				break;
			case '2':
				std::cout << "Please input the index of node you want to remove : ";
				std::cin >> index;
				if (remove(&head, index)) strcpy(str, "Remove succeed!");
				else  strcpy(str, "Remove failed!");
				break;
			case 'q': 
				destory(head);
				std::cout << "Exiting program..." << std::endl;
				system("pause");
				return  0;
			default : break;
		}
	}
	return 0;
}