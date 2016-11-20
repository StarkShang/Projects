#pragma once
struct LinkedNode//定义链表节点的结构体
{
	int data;
	LinkedNode* prev;
	LinkedNode* next;
};

LinkedNode* create(int* array, int size)//输入数组指针和数组大小，执行函数后建立对应链表并输出第一个节点的指针
{
	LinkedNode *head, *iterator;//定义第一个节点的指针和一个指针迭代器
	head = iterator = new LinkedNode();//建立一个节点，赋指针值给head和迭代器
	iterator->data = *array;
	iterator->prev = nullptr;
	iterator->next = nullptr;//给第一个节点赋值
	for (int i = 1; i < size; i++)//利用迭代器，从第二个节点开始循环赋值
	{
		iterator->next = new LinkedNode();//新建节点，新节点的指针赋给上一个的next
		iterator->next->data = array[i];//数组值赋给新节点的data
		iterator->next->prev = iterator;//上一个节点的指针赋给新节点的prev
		iterator->next->next = nullptr;//新节点的next为空
		iterator = iterator->next;//迭代
	}
	return head;//返回第一个节点的指针
}

LinkedNode* find(LinkedNode* head, int index)//输入链表第一个节点的指针和需要查找第几个，返回所查节点的指针
{
	while (--index>0)//找第n个节点将运行n-1次
	{
		if (head->next == nullptr) return nullptr;//如果index超出链表长度，返回空指针
		else head = head->next;//否则指针移到下一个节点
	}
	return head;//返回所查指针
}

bool insert(LinkedNode* node, LinkedNode** head, int index)//输入节点，链表起始位置，插入位置，返回是否能够插入的判断，能够则执行插入节点
{
	if (*head == nullptr)//如果链表无节点，则加入参数节点，赋值，返回true,并结束函数
	{
		node->prev = nullptr;
		node->next = nullptr;
		*head = node;
		return true;
	}
	LinkedNode* n = find(*head, index);//找到第index个节点的指针，赋值给n
	if (n == nullptr)//如果不存在第index个节点
	{
		n = find(*head, index - 1);//看前一个节点
		if (n == nullptr)//如果也不存在，表明超出链表长度，不能插入，清空数据，返回false，结束函数
		{
			delete node;
			return false;
		}
		else//如果存在，表明是最后一个节点
		{
			n->next = node;
			node->prev = n;
			node->next = nullptr;//在最后一个节点之后插入node节点，修改对应的数据
			return true;//插入成功，返回true，结束函数
		}
	}
	if (n->prev == nullptr) *head = node;//如果第index个节点是第一个节点，则把node作为链表指针(即为第一个节点)
	else n->prev->next = node;//如果不是第一个节点，修改前一个节点的next值来插入node
	node->prev = n->prev;
	node->next = n;
	n->prev = node;//修改第index个节点与node节点的prev和next，建立前后对应关系（如果插在第一个节点前，将把node的prev改成空）
	return true;//插入成功，返回true
}

bool remove(LinkedNode** head, int index)//输入链表指针与要删第几个节点，返回能否删除，能够则执行删除
{
	LinkedNode* node = find(*head, index);//找到第index个节点
	if (node == nullptr) return false;//如果第index个节点不存在，不能删除，返回false
	else if (node->prev == nullptr && node->next == nullptr)//如果存在，查看prev和next是否都为空，以此判断是否该节点是仅有的一个节点
	{
		*head = nullptr;
		return true;//如果是就把链表指针变为空指针，实现删除，返回true
	}
	else//如果链表不止一个节点
	{
		if (node->prev == nullptr) *head = node->next;//如果是第一个节点，把链表节点移到第二个节点，实现删除
		else node->prev->next = node->next;//如果不是第一个节点，把前一个节点的next改为后一个节点
		if (node->next != nullptr) node->next->prev = node->prev;//如果当前节点不是最后一个节点，则把下一个节点的prev改成上一个节点，实现删除(如果删除了第一个，将把第二个的prev改成空)
		delete node;//清除node的空间
		return true;//删除成功，返回true
	}
}

void destory(LinkedNode* head)//输入链表指针，清空链表数据的空间
{
	while (head != nullptr)//只要当前节点存在就将运行
	{
		LinkedNode* tmp = head;//暂存当前节点
		head = head->next;//指针移到下个节点
		delete tmp;//删除暂存的节点
	}
}