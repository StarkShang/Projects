#pragma once
struct LinkedNode //定义结构体
{
	int data;
	LinkedNode* prev;
	LinkedNode* next;
};

LinkedNode* create(int* array, int size)
{
	LinkedNode *head, *iterator;//定义节点头指针 迭代指针
	head = iterator = new LinkedNode();
	iterator->data = *array;//将排列的值赋值到迭代指针的数据中
	iterator->prev = nullptr;//空赋值到指向前一个节点的指针
	iterator->next = nullptr;//空赋值到指向后一个节点的指针
	for (int i = 1; i < size; i++)//循环
	{
		iterator->next = new LinkedNode();
		iterator->next->data = array[i];//循环赋值头指针的值于下一个节点的数据
		iterator->next->prev = iterator;//将迭代指针赋值于下一个节点的指向前一个节点的指针
		iterator->next->next = nullptr;//将空赋值到指向下一个指针的节点的指针
		iterator = iterator->next;//指向下一个迭代指针的节点赋值到迭代指针
	}
	return head;
}

LinkedNode* find(LinkedNode* head, int index)
{
	while (--index>0)
	{
		if (head->next == nullptr) return nullptr;//若头指针的指向下一个节点的值为空 返回空
		else head = head->next;//否则将头指针指向下一个节点的值赋值到头指针
	}
	return head;
}

bool insert(LinkedNode* node, LinkedNode** head, int index)
{
	if (*head == nullptr)//若头指针为空
	{
		node->prev = nullptr;//节点指向前一个指针的值为空
		node->next = nullptr;//节点指向后一个指针的值为空
		*head = node;//将节点的值赋值到头指针
		return true;
	}
	LinkedNode* n = find(*head, index);
	if (n == nullptr)//若n为空
	{
		n = find(*head, index - 1);//将find函数 的结果赋值到n
		if (n == nullptr)//若n为空
		{
			delete node;//清除节点
			return false;//返回错误
		}
		else
		{
			n->next = node;//将节点的值赋值到指向后一个节点的指针
			node->prev = n;//将n赋值到指向前一个节点的指针
			node->next = nullptr;//将空赋值到指向后一个节点的指针
			return true;//返回正确
		}
	}
	if (n->prev == nullptr) *head = node;//若指向n前一个指针的值为空 将节点的指针赋值到头指针
	else n->prev->next = node;
	node->prev = n->prev;//将n指向前一个指针的值赋值到排列的指向前一个指针的值
	node->next = n;//将n赋值到排列的指向下一个指针的值
	n->prev = node;//将排列赋值到n的指向前一个指针的值
	return true;//返回正确
}

bool remove(LinkedNode** head, int index)
{
	LinkedNode* node = find(*head, index);
	if (node == nullptr) return false;//若节点为空 返回错误
	else if (node->prev == nullptr && node->next == nullptr)//否则若 节点指向前后的指针为空
	{
		*head = nullptr;//头指针为空
		return true;//返回正确
	}
	else
	{
		if (node->prev == nullptr) *head = node->next;//若节点指向前一个指针的值为空 将节点指向后一个指针的值赋值到头指针
		else node->prev->next = node->next;//否则将节点指向后一个指针的值赋值到节点指向后一个前一个指针的值
		if (node->next != nullptr) node->next->prev = node->prev;//若节点指向下一个指针的值不为空 将节点指向前一个指针的值赋值到节点指向后一个前一个
		delete node;//清除节点
		return true;//返回正确 
	}
}

void destory(LinkedNode* head)
{
	while (head != nullptr)//若头指针不为空
	{
		LinkedNode* tmp = head;//头指针赋值到
		head = head->next;//头指针指向下一个节点的值赋值到头指针
		delete tmp;//清除tmp
	}
}