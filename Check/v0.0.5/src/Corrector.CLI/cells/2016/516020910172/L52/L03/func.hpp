#pragma once
struct LinkedNode//建立结构体
{
	int data;//结点int类型数据
	LinkedNode* prev;//linkednode指针
	LinkedNode* next;//linkednode指针
};

LinkedNode* create(int* array, int size)//用于根据数组数据创建链表的函数
{
	LinkedNode *head, *iterator;//定义两个linkednode结构体
	head = iterator = new LinkedNode();//创建一个新的head
	iterator->data = *array;//中间变量的data指向array
	iterator->prev = nullptr;//将prev赋值为空
	iterator->next = nullptr;//将next赋值为空
	for (int i = 1; i < size; i++)//循环创建node
	{
		iterator->next = new LinkedNode();//创建新的结构体
		iterator->next->data = array[i];//对data赋值
		iterator->next->prev = iterator;//将prev赋值为前一个iterator
		iterator->next->next = nullptr;//将next赋值为空
		iterator = iterator->next;//iterator赋值为前一个的next
	}
	return head;//返回head
}

LinkedNode* find(LinkedNode* head, int index)//找到第i个结点的函数
{
	while (--index>0)//开始循环查找
	{
		if (head->next == nullptr) return nullptr;//如果找到最后next为空，返回空
		else head = head->next;//一个一个向后查找
	}
	return head;//返回head
}

bool insert(LinkedNode* node, LinkedNode** head, int index)//在第i个结点前插入结点的函数
{
	if (*head == nullptr)//如果head为空
	{
		node->prev = nullptr;//将prev赋值为空
		node->next = nullptr;//将next赋值为空
		*head = node;
		return true;//返回插入成功
	}
	LinkedNode* n = find(*head, index);//利用find函数查找结点
	if (n == nullptr)
	{
		n = find(*head, index - 1);//索引值向前一位
		if (n == nullptr)//判断是否找到
		{
			delete node;
			return false;//没有找到返回false
		}
		else
		{
			n->next = node;//将next赋值为node
			node->prev = n;//node的prev赋值为n
			node->next = nullptr;//node的next赋值为空
			return true;//返回插入成功
		}
	}
	if (n->prev == nullptr) *head = node;//head赋值为node
	else n->prev->next = node;
   node->prev = n->prev;//将n的prev赋值给node
	node->next = n;//node的next赋值为n
	n->prev = node;//n的prev赋值为node
	return true;//返回插入成功
}

bool remove(LinkedNode** head, int index)//删除第i个结点的函数
{
	LinkedNode* node = find(*head, index);//利用结构体node定义为find函数 查找结点
	if (node == nullptr) return false;//如果查找不到 返回false
	else if (node->prev == nullptr && node->next == nullptr)//如果prev和next同为空
	{
		*head = nullptr;//head为空
		return true;//返回true
	}
	else
	{
		if (node->prev == nullptr) *head = node->next;//如果prev为空 head赋值为node中的next
		else node->prev->next = node->next;
		if (node->next != nullptr) node->next->prev = node->prev;//如果next不为空的情况
		delete node;//找到节点并删除
		return true;//返回删除成功true
	}
}

void destory(LinkedNode* head)//销毁整个链表
{
	while (head != nullptr)//开始循环直到head为空
	{
		LinkedNode* tmp = head;//引入临时变量
		head = head->next;//指针向后依次指
		delete tmp;//删除数据
	}
}