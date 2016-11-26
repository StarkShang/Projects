#pragma once
struct LinkedNode
{
	int data;
	LinkedNode* prev;
	LinkedNode* next;
};

LinkedNode* create(int* array, int size)
{
	LinkedNode *head, *iterator;
	head = iterator = new LinkedNode();//创建一个新的链表头
	iterator->data = *array;
	iterator->prev = nullptr;
	iterator->next = nullptr;//迭代器赋值
	for (int i = 1; i < size; i++)
	{
		iterator->next = new LinkedNode();//后向指针指向一个新的链表单元
		iterator->next->data = array[i];//对新创建的单元赋值
		iterator->next->prev = iterator;
		iterator->next->next = nullptr;
		iterator = iterator->next;//迭代
	}
	return head;
}

LinkedNode* find(LinkedNode* head, int index)
{
	while (--index>0)//循环，index＞0为判断条件
	{
		if (head->next == nullptr) return nullptr;
		else head = head->next;//寻找目标
	}
	return head;
}

bool insert(LinkedNode* node, LinkedNode** head, int index)
{
	if (*head == nullptr)//从0插入，等于新建一个
	{
		node->prev = nullptr;
		node->next = nullptr;
		*head = node;
		return true;
	}
	LinkedNode* n = find(*head, index);//调用函数寻找插入的位置
	if (n == nullptr)
	{
		n = find(*head, index - 1);
		if (n == nullptr)//判断是否超出范围
		{
			delete node;
			return false;
		}
		else//在范围内，插入
		{
			n->next = node;
			node->prev = n;
			node->next = nullptr;
			return true;
		}
	}
	if (n->prev == nullptr) *head = node;//尾部插入
	else n->prev->next = node;
	node->prev = n->prev;
	node->next = n;
	n->prev = node;
	return true;
}

bool remove(LinkedNode** head, int index)
{
	LinkedNode* node = find(*head, index);//调用函数找位置
	if (node == nullptr) return false;//超出范围
	else if (node->prev == nullptr && node->next == nullptr)//只有一个的情况
	{
		*head = nullptr;
		return true;
	}
	else//把要删除的单元记作第i个。把i-1的后向指针指向i+1。i+1的前向指针指向i-1，跳过i
	{
		if (node->prev == nullptr) *head = node->next;
		else node->prev->next = node->next;
		if (node->next != nullptr) node->next->prev = node->prev;
		delete node;
		return true;
	}
}

void destory(LinkedNode* head)
{
	while (head != nullptr)//删除链表
	{
		LinkedNode* tmp = head;
		head = head->next;
		delete tmp;
	}
}