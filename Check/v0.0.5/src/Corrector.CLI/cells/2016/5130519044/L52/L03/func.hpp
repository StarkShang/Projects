#pragma once
struct LinkedNode
{
	int data;
	LinkedNode* prev;
	LinkedNode* next;
};

LinkedNode* create(int* array, int size) //根据数组数据创建数据链表
{
	LinkedNode *head, *iterator;
	head = iterator = new LinkedNode();
	iterator->data = *array; //节点的数据指向数组的元素
	iterator->prev = nullptr;//prev和next指针赋值为空指针
	iterator->next = nullptr;
	for (int i = 1; i < size; i++)
	{
		iterator->next = new LinkedNode(); //开辟一个存放LinkedNode型数据的空间（即节点）
		iterator->next->data = array[i];
		iterator->next->prev = iterator;
		iterator->next->next = nullptr;
		iterator = iterator->next;
	}
	return head;
}

LinkedNode* find(LinkedNode* head, int index) //找到第i个节点的函数
{
	while (--index>0)
	{
		if (head->next == nullptr) return nullptr;
		else head = head->next;
	}
	return head;
}

bool insert(LinkedNode* node, LinkedNode** head, int index) //在第i个节点前插入节点
{
	if (*head == nullptr)
	{
		node->prev = nullptr;
		node->next = nullptr;
		*head = node;
		return true;
	}
	LinkedNode* n = find(*head, index);
	if (n == nullptr)
	{
		n = find(*head, index - 1);
		if (n == nullptr)
		{
			delete node;
			return false;
		}
		else
		{
			n->next = node;
			node->prev = n;
			node->next = nullptr;
			return true;
		}
	}
	if (n->prev == nullptr) *head = node;
	else n->prev->next = node;
	node->prev = n->prev;
	node->next = n;
	n->prev = node;
	return true;
}

bool remove(LinkedNode** head, int index) //删除第i个节点
{
	LinkedNode* node = find(*head, index);
	if (node == nullptr) return false;
	else if (node->prev == nullptr && node->next == nullptr)
	{
		*head = nullptr;
		return true;
	}
	else
	{
		if (node->prev == nullptr) *head = node->next;
		else node->prev->next = node->next;
		if (node->next != nullptr) node->next->prev = node->prev;
		delete node;
		return true;
	}
}

void destory(LinkedNode* head) //销毁整个链表
{
	while (head != nullptr)
	{
		LinkedNode* tmp = head;
		head = head->next;
		delete tmp;
	}
}