#pragma once
struct LinkedNode //建立结构体
{
	LinkedNode *prev;
	int data;
	LinkedNode *next;
};

LinkedNode* create(int* array, int size)  //根据数组创建链表
{
	LinkedNode* Head = new LinkedNode;  //创建第一个节点
	Head->prev = NULL;
	Head->next = NULL;
	Head->data = *array;
	LinkedNode* prev = Head;  //将prev指向第一个节点
	for (int i = 1; i < size; i++)
	{
		LinkedNode *node = new LinkedNode; //创建节点
		node->data=*(array+i);  //根据数组赋值
		node->prev = prev; //指向前一个的指针
		prev->next = node; //由前一节点指向该节点的指针
		node->next = NULL; //指向下一个节点的指针指向空
		prev = node; //将prev指向该节点，进入下一个节点的创建
	}
	return Head; //返回第一个节点的地址
}

LinkedNode* find(LinkedNode* head, int index) //找到第i个节点
{
	int i = 1;
	LinkedNode *Node = head;
	for (; Node->next != NULL;)  //计算有多少个节点
	{
		i = i + 1;
		Node = Node->next;
	}
	if (index > i) return NULL;  //如果i大于节点数，返回NULL
	else 
	{
		i = 1;
		LinkedNode *node = head;
		for (; i < index; i++) //找到第i个节点
		{
			node = node->next; //node指向noded的下一个节点
		}
		return node; //返回node
	}
}

bool insert(LinkedNode* node, LinkedNode** head, int index) //在第 i个结点处前插入结点的函数 ，插入成功则返回true,失败则返回FALSE
{
	int i = 1;
	LinkedNode *Node = *head;
	LinkedNode *Prev;
	for (; Node->next != NULL;) //计算有多少个节点
	{
		i = i + 1;
		Node = Node->next;
	}
	if (index > i) return false; //如果插入失败则返回false
	else //在第i个节点前插入
	{
		Node = find(*head, index); //找到第i个节点
		Prev = find(*head, index-1); //找到第i-1个节点
		Prev->next = node;//将第i-1个节点的指后指针指向node
		node->prev = Node->prev; //将node的指前指针指向第i-1个节点
		node->next = Node; //将node的指后指针指向第i个节点
		Node->prev = node; //将第i个节点的指前指针指向node
		return true; //返回true
	}
}

bool remove(LinkedNode** head, int index) //删除第i个节点
{
	int i = 1;
	LinkedNode *Node = *head;
	LinkedNode *Prev;
	LinkedNode *Next;
	for (; Node->next != NULL;) //计算节点个数
	{
		i = i + 1;
		Node = Node->next;
	}
	if (index > i) return false; //如果溢出返回false
	else 
	{
		Node = find(*head, index); //找到第i个节点
		Prev = Node->prev; //记录下第i-1个节点的地址
		Next = Node->next;//记录下第i+1个节点的地址
		Prev->next = Next;//将第i-1个节点与第i+1个节点相连
		Next->prev = Prev;
		delete Node; //删除第i个节点
		return true;//返回true
	}
}

void destory(LinkedNode* head) //销毁整个链表
{
	LinkedNode*Next = head;//创建Next用以储存
	for (; Next->next != NULL;)
	{
		LinkedNode *Node = Next;
		Next = Node->next; //找到下一个节点
		delete Node; //删除当前节点
	}
}

bool append(LinkedNode* node, LinkedNode* head) //在链表的最后添加一个节点
{
	LinkedNode *Node = head; 
	for (; Node->next != NULL;) //找到最后一个节点
	{
		Node - Node->next;
	}
	Node->next = node;//将最后一个节点的指后指针指向添加的节点
	node->prev = Node;//将添加节点的指前指针指向最后一个节点
	node->next = NULL;//将添加节点变为最后一个节点
	return true;//返回true以表示添加成功
}