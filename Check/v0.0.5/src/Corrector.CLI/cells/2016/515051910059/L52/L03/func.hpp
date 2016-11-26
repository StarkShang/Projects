#pragma once
struct LinkedNode//建立链表的结构体
{
	int data; //定义结点int类型数据
	LinkedNode* prev;//定义向前的指针
	LinkedNode* next;//定义向后的指针
};

LinkedNode* create(int* array, int size)//定义创建链表函数
{
	LinkedNode *head, *iterator;//定义两个指针变量
	head = iterator = new LinkedNode();//指针变量初始化
	iterator->data = *array;//给整型变量赋初值
	iterator->prev = nullptr;//给指针变量prev赋初值
	iterator->next = nullptr;//给指针变量next赋初值
	for (int i = 1; i < size; i++)//进行for循环，建立指定数目的结点
	{
		iterator->next = new LinkedNode();//建立下一个结点
		iterator->next->data = array[i];//存储第i个数据
		iterator->next->prev = iterator;//给相应的指针变量赋值
		iterator->next->next = nullptr;
		iterator = iterator->next;
	}
	return head;//链表建立完毕返回函数待用
}

LinkedNode* find(LinkedNode* head, int index)//定义寻找结点的函数
{
	while (--index>0)//寻找指定的结点
	{
		if (head->next == nullptr) return nullptr;
		else head = head->next;
	}
	return head;
}

bool insert(LinkedNode* node, LinkedNode** head, int index)//定义控制插入结点的函数
{
	if (*head == nullptr)
	{
		node->prev = nullptr;
		node->next = nullptr;
		*head = node;
		return true;
	}
	LinkedNode* n = find(*head, index);//寻找想要插入结点的位置
	if (n == nullptr)
	{
		n = find(*head, index - 1);//在找到的结点前插入结点
		if (n == nullptr)//如果超出链表范围，插入失败，返回false
		{
			delete node;
			return false;
		}
		else//如果未超过链表范围，插入成功，返回true
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

bool remove(LinkedNode** head, int index)//定义控制删除节点的函数
{
	LinkedNode* node = find(*head, index);//寻找想要删除的结点
	if (node == nullptr) return false;//如果找不到想要的结点，返回false
	else if (node->prev == nullptr && node->next == nullptr)//判断给条件下结点的删除指令
	{
		*head = nullptr;
		return true;
	}
	else//删除想要删除的结点，删除成功返回true
	{
		if (node->prev == nullptr) *head = node->next;
		else node->prev->next = node->next;
		if (node->next != nullptr) node->next->prev = node->prev;
		delete node;
		return true;
	}
}

void destory(LinkedNode* head)//定义销毁链表的函数
{
	while (head != nullptr)//进行while循环销毁整个列表
	{
		LinkedNode* tmp = head;
		head = head->next;
		delete tmp;
	}
}