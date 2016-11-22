#pragma once
struct LinkedNode
{
	int data;
	LinkedNode* prev;
	LinkedNode* next;
};                                            //定义变量，设置struct函数

LinkedNode* create(int* array, int size)      //根据数组创建链表
{
	LinkedNode *head, *iterator;              
	head = iterator = new LinkedNode();       //创建第一个节点
	iterator->data = *array;
	iterator->prev = nullptr;
	iterator->next = nullptr;                 //将prev指向第一个节点
	for (int i = 1; i < size; i++)
	{
		iterator->next = new LinkedNode();           //创建节点
		iterator->next->data = array[i];             //根据数据赋值
		iterator->next->prev = iterator;             //指向前一个的指针
		iterator->next->next = nullptr;              //
		iterator = iterator->next;                   //指向下一个节点
	}
	return head;                                     //返回第一个节点的地址
}

LinkedNode* find(LinkedNode* head, int index)        //找到第一个节点
{
	while (--index>0)
	{
		if (head->next == nullptr) return nullptr;    //如果其大于节点数，返回nullptr
		else head = head->next;
	}
	return head;
}

bool insert(LinkedNode* node, LinkedNode** head, int index)      //在第i个节点处前插入节点的函数，插入成功则返回true。
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
	else n->prev->next = node;                          //将第i-1个节点的指后指针指向node
	node->prev = n->prev;                               //将node的指前指针指向第i-1个节点
	node->next = n;                                     //将node的指后指针指向第i个节点
	n->prev = node;                                     //将第i个节点的指前指针指向node
	return true;                                        //返回true
}

bool remove(LinkedNode** head, int index)                   //删除第i个节点
{
	LinkedNode* node = find(*head, index);
	if (node == nullptr) return false;                                //找到第i个节点
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
		delete node;                                              //删除第i个节点
		return true;
	}
}

void destory(LinkedNode* head)                           //销毁整个链表
{
	while (head != nullptr)
	{
		LinkedNode* tmp = head;
		head = head->next;
		delete tmp;
	}
}