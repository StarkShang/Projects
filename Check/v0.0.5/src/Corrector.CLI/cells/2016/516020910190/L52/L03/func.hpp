#pragma once
struct LinkedNode
{
	int data;
	LinkedNode* prev;
	LinkedNode* next;
};//LinkedNode结构体，包含LinkedNode指针prev,int型数据data,LinkedNode指针next

LinkedNode* create(int* array, int size)//创建链表函数
{
	LinkedNode *head, *iterator;
	head = iterator = new LinkedNode();//初始化指针
	iterator->data = *array;//迭代指针指向结点储存数据data赋值array
	iterator->prev = nullptr;//迭代指针指向前一个结点的指针prev赋值空
	iterator->next = nullptr;//迭代指针指向后一个结点的指针next赋值空
	for (int i = 1; i < size; i++)//创建一个个结点之间的链接
	{
		iterator->next = new LinkedNode();
		iterator->next->data = array[i];//指向后一个结点的指针指向的结点储存数据data赋值为array[i]
		iterator->next->prev = iterator;//指向后一个结点的指针指向的前一个结点赋值为迭代指针
		iterator->next->next = nullptr;//迭代指针指向后一个结点的指针指向的后一个结点赋值为空
		iterator = iterator->next;//将迭代指针指向后一个结点的指针next
	}
	return head;//返回头指针
}

LinkedNode* find(LinkedNode* head, int index)//到第i个结点的函数
{
	while (--index>0)//向后找到第index个结点
	{
		if (head->next == nullptr) return nullptr;//如果头指针指向的后一个结点为空，则返回空
		else head = head->next;//否则，头指针赋值为后一个结点的指针
	}
	return head;		//建议重新定义一个结点作为返回值。直接操作head指针会改变原来的链表
}

bool insert(LinkedNode* node, LinkedNode** head, int index)//在第index个结点前插入结点函数
{
	if (*head == nullptr)
	{
		node->prev = nullptr;
		node->next = nullptr;
		*head = node;
		return true;//如果头指针为空，则结点指向前一个赋值为空，后一个赋值为空，插入成功，返回true
	}							//头指针为空，说明链表根本就没有index个结点，个人认为处理为插入错误更合理
	LinkedNode* n = find(*head, index);//寻找第i个结点
	if (n == nullptr)
	{
		n = find(*head, index - 1);
		if (n == nullptr)
		{
			delete node;//如果第index-1个结点为空，删除结点
			return false;//链表长度不够index，插入出错，返回false
		}
		else					//这是第index-1个结点不为空且第index个结点为空的情况
		{
			n->next = node;//否则第index个结点指向的下一个赋值为要插入的结点
			node->prev = n;//该结点指向的前一个赋值为第i个结点
			node->next = nullptr;//要插入结点指向的下一个赋值为空
			return true;//插入成功，返回true
		}
	}
	if (n->prev == nullptr) *head = node;//如果第i个结点指向的前一个为空，将要插入结点赋值于头指针
	else n->prev->next = node;//否则，第i个结点指向的前一个指向的后一个赋值为要插入结点
	node->prev = n->prev;//要插入结点指向的前一个赋值为第i个结点指向的前一个
	node->next = n;//要插入结点指向的后一个赋值为第i个结点
	n->prev = node;//第i个结点指向的前一个赋值为要插入结点
	return true;//插入成功，返回true
}

bool remove(LinkedNode** head, int index)//删除第i个结点函数
{
	LinkedNode* node = find(*head, index);//找到第i个结点
	if (node == nullptr) return false;					//第index个结点本来就不存在，无法删除，返回false
	else if (node->prev == nullptr && node->next == nullptr)		//第index个结点是一个独立的、不与其他节点相连接的结点？？个人认为这是不可能的情况
	{																														//因为find函数的返回值要不是空，要不就是链表中的一个结点，且此结点应当不是孤立的。（只有一个结点的情况除外）
		*head = nullptr;																					//假设此链表确实只有一个结点，直接把head指针置空也是不大合理的处理方式，毕竟index不一定是1
		return true;																							//个人认为处理为删除出错更合理吧
	}
	else
	{
		if (node->prev == nullptr) *head = node->next;//如果该结点前一个为空，则将后一个赋值于头指针
		else node->prev->next = node->next;						//否则该结点前一个的后一个固执为该结点的后一个，即删除了node结点
		if (node->next != nullptr) node->next->prev = node->prev;//如果该结点后一个不为空该结点后一个的前一个赋值为该结点的前一个
		delete node;//删除该结点
		return true;
	}
}

void destory(LinkedNode* head)//销毁链表结构
{
	while (head != nullptr)
	{
		LinkedNode* tmp = head;
		head = head->next;//将头指针后一个赋值于头指针
		delete tmp;//头指针不为空时，删除头指针
	}
}
bool append(LinkedNode* node, LinkedNode* head)
{ bool flag=true;  
	LinkedNode *tmp=head;
	if(tmp==nullptr)//头指针为空，则node结点为链表的第一个结点
	{
		head=node;
		return flag;
	}
	while (tmp->next != nullptr)
	{
		tmp=tmp->next;
	}//将tmp指向最后一个结点
	tmp->next=node;
	node->next=nullptr;
	node->prev=tmp;
	return flag;
}
	
	
	
