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
	head = iterator = new LinkedNode();//创建链表的第一个结构体
	iterator->data = *array;
	iterator->prev = nullptr;
	iterator->next = nullptr;
	for (int i = 1; i < size; i++)//将所有数据链式相连
	{
		iterator->next = new LinkedNode();
		iterator->next->data = array[i];
		iterator->next->prev = iterator;
		iterator->next->next = nullptr;
		iterator = iterator->next;
	}
	return head;
}

LinkedNode* find(LinkedNode* head, int index)//寻找数据
{
	while (--index>0)
	{
		if (head->next == nullptr) return nullptr;//超出检索范围
		else head = head->next;//循环index-1次找到第index个数
	}
	return head;
}

bool insert(LinkedNode* node, LinkedNode** head, int index)
{
	if (*head == nullptr)//是否原来没有元素
	{
		node->prev = nullptr;
		node->next = nullptr;
		*head = node;//待插入即为第一个
		return true;
	}
	LinkedNode* n = find(*head, index);//寻找原来的第n个元素
	if (n == nullptr)//超过第n个
	{
		n = find(*head, index - 1);
		if (n == nullptr)//超出个数限制
		{
			delete node;
			return false;
		}
		else//插入到最后
		{
			n->next = node;
			node->prev = n;
			node->next = nullptr;
			return true;
		}
	}
	if (n->prev == nullptr) *head = node;//插入到第一个
	else n->prev->next = node;
	node->prev = n->prev;
	node->next = n;
	n->prev = node;//将node插入n之前
	return true;
}

bool remove(LinkedNode** head, int index)
{
	LinkedNode* node = find(*head, index);//找要去除的数
	if (node == nullptr) return false;//超出范围
	else if (node->prev == nullptr && node->next == nullptr)
	{
		*head = nullptr;//只有一个元素
		return true;
	}
	else
	{
		if (node->prev == nullptr) *head = node->next;//去除首个元素
		else node->prev->next = node->next;
		if (node->next != nullptr) node->next->prev = node->prev;//去除元素
		delete node;
		return true;
	}
}

void destory(LinkedNode* head)
{
	while (head != nullptr)//将元素一个一个删去
	{
		LinkedNode* tmp = head;
		head = head->next;
		delete tmp;
	}
}

void append(LinkedNode* node,LinkedNode* head)
{
	while(head->next!=nullptr)
		head=head->next;
	head->next=node;
	node->prev=head;
	node->next=nullptr;
}