#pragma once
struct LinkedNode //创建结构体
{
	int data;//储存的数据
	LinkedNode* prev;//指向前节点的指针
	LinkedNode* next;//指向后节点的指针
};

LinkedNode* create(int* array, int size)//根据数组数据创造链表的函数
{
	LinkedNode *head, *iterator;//定义两个结构体指针
	head = iterator = new LinkedNode();
	iterator->data = *array;//将数组数据复制给跌代体的DATA成员中
	iterator->prev = nullptr;//把前后指针都赋值为空，即初始化
	iterator->next = nullptr;
	for (int i = 1; i < size; i++)
	{
		iterator->next = new LinkedNode();//吧向下指针开一个内存，建立新的结构体变量
		iterator->next->data = array[i];//吧向下指针的数据成员赋值上数组的第I个数字
		iterator->next->prev = iterator;//而同时向前指针赋值上跌代体
		iterator->next->next = nullptr;//向下指针中的向下指针赋值为空指针
		iterator = iterator->next;//把向下指针赋值给跌代体中，以便下次循环进行
	}
	return head;
}

LinkedNode* find(LinkedNode* head, int index)//找到第I个节点的函数
{
	while (--index>0)
	{
		if (head->next == nullptr) return nullptr;//当HEAD中的向下指针为空时，返回空指针
		else head = head->next;//否则把HEAD赋值为HEAD的向下指针
	}
	return head;//返回HEAD的值
}

bool insert(LinkedNode* node, LinkedNode** head, int index)//在第I个节点插入结点的函数，插入成功返回TRUE,否则返回FALSE
{
	if (*head == nullptr)//当HEAD为空时
	{
		node->prev = nullptr;//NODE的前后指针都赋值空
		node->next = nullptr;
		*head = node;//把HEAD赋值为NODE
		return true;//插入成功
	}
	LinkedNode* n = find(*head, index);//找到第I个节点
	if (n == nullptr)
	{
		n = find(*head, index - 1);//若N是空函数，让N为序号小一个的节点
		if (n == nullptr)
		{
			delete node;//若N仍然是空的，则返回失败，清空内存
			return false;
		}
		else
		{
			n->next = node;//否则，吧NODE赋值给N的向下指针
			node->prev = n;//吧NODE的向前指针赋值为N
			node->next = nullptr;//NODE的向下指针为空
			return true;
		}
	}
	if (n->prev == nullptr) *head = node;//如果N的向前指针为空，则把NEAD赋值为NODE
	else n->prev->next = node;//否则，进行一系列替换，让NODE正常插入
	node->prev = n->prev;
	node->next = n;
	n->prev = node;
	return true;
}

bool remove(LinkedNode** head, int index)//删除第I个节点的函数，成功返回TRUE,失败返回FALSE
{
	LinkedNode* node = find(*head, index);//找到第I个节点
	if (node == nullptr) return false;//若第I个节点为空，返回失败
	else if (node->prev == nullptr && node->next == nullptr)//否则，若第i个节点的前后指针都为空
	{
		*head = nullptr;//让HEAD为空
		return true;
	}
	else
	{
		if (node->prev == nullptr) *head = node->next;//否则，若节点的向前指针式空的，那么让HEAD为NODE 的向后节点
		else node->prev->next = node->next;//若补位空，则把NODE的前指针的后指针赋值为NODE的后指针
		if (node->next != nullptr) node->next->prev = node->prev;//如果NODE的后指针不空，则NODE的后指针的前指针赋值为NODE前指针
		delete node;//释放内存，返回成功
		return true;
	}
}

void destory(LinkedNode* head)//销毁整个数据列表
{
	while (head != nullptr)//当列表不空时，依次释放内存
	{
		LinkedNode* tmp = head;
		head = head->next;
		delete tmp;
	}
}