#pragma once
struct LinkedNode
{
	int data;
	LinkedNode* prev;//指向前一个节点的指针
	LinkedNode* next;//指向后一个节点的指针
};

LinkedNode* create(int* array, int size)
{
	LinkedNode *head, *iterator;//定义头指针 迭代指针
	head = iterator = new LinkedNode();//初始化
	iterator->data = *array;//带入数据
	iterator->prev = nullptr;//赋值给前一个
	iterator->next = nullptr;//赋值给后一个
	for (int i = 1; i < size; i++)//设置循环
	{
		iterator->next = new LinkedNode();
		iterator->next->data = array[i];
		iterator->next->prev = iterator;
		iterator->next->next = nullptr;
		iterator = iterator->next;//节点赋值
	}
	return head;//返回头
}

LinkedNode* find(LinkedNode* head, int index)
{
	while (--index>0)//当index的值大于0时
	{
		if (head->next == nullptr) return nullptr;//如果满足条件就返回空
		else head = head->next;//否则下一个成为头
	}
	return head;//返回头
}

bool insert(LinkedNode* node, LinkedNode** head, int index)

	if (*head == nullptr)//如果头指针是空
	{
		node->prev = nullptr;//指针节点指向前一个
		node->next = nullptr;//指针节点指向后一个
		*head = node;//赋值
		return true;//返回真值
	}
	LinkedNode* n = find(*head, index);
	if (n == nullptr)//如果两者相等
	{
		n = find(*head, index - 1);//给n赋值
		if (n == nullptr)//如果两者相等
		{
			delete node;//删除节点
			return false;//返回false
		}
		else//否则
		{
			n->next = node;//n成为下一个节点指针
			node->prev = n;//指针节点指向前一个
			node->next = nullptr;//指针节点指向后一个
			return true;//返回true
		}
	}
	if (n->prev == nullptr) *head = node;//如果两者相等
	else n->prev->next = node;//否则把节点的值赋值值到n，指向前一个指针的指向后一个指针
	node->prev = n->prev;//指向前一个指针
	node->next = n;//指向后一个指针
	n->prev = node;//节点前移
	return true;//返回TRUE
}

bool remove(LinkedNode** head, int index)
{
	LinkedNode* node = find(*head, index);
	if (node == nullptr) return false;//相等就返回FALSE
	else if (node->prev == nullptr && node->next == nullptr)//若同时满足
	{
		*head = nullptr;//头指针指向空
		return true;//返回FALSE
	}
	else//否则
	{
		if (node->prev == nullptr) *head = node->next;//如果节点指针前移是空，那么头指针指向下一个
		else node->prev->next = node->next;//否则节点指向前一个指针的指向后一个指针
		if (node->next != nullptr) node->next->prev = node->prev;
		delete node;//删除节点
		return true;//返回TRUE
	}
}

void destory(LinkedNode* head)
{
	while (head != nullptr)//当头不是空时
	{
		LinkedNode* tmp = head;
		head = head->next;//头指向下一个
		delete tmp;//删除
	}
}