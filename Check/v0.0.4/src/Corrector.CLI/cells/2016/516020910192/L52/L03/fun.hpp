#pragma once
struct LinkedNode//
{//
	int data;//
	LinkedNode* prev;//
	LinkedNode* next;//
};//

LinkedNode* create(int* array, int size)
{
	LinkedNode *head, *iterator;//定义结点和中间结构体
	head = iterator = new LinkedNode();//create结构体
	iterator->data = *array;//输入第一个结构体的三个元素
	iterator->prev = nullptr;//
	iterator->next = nullptr;//
	for (int i = 1; i < size; i++)//循环size-1次创建size-1个结点
	{//
		iterator->next = new LinkedNode();//在每一个结点的next创建一个结构体
		iterator->next->data = array[i];//填写数据
		iterator->next->prev = iterator;//新结构体的prev指向这个结点
		iterator->next->next = nullptr;//新结构体的next暂定为空
		iterator = iterator->next;//更改iterator为新结构体指针用以循环
	}//
	return head;//返回第一个结点的指针
}//

LinkedNode* find(LinkedNode* head, int index)
{//
	while (--index>0)//循环index-1次找到该结点
	{
		if (head->next == nullptr) return nullptr;//如果在循环中超过了链表长度，返回nullptr
		else head = head->next;//head指针向后推一项用来循环
	}//
	return head;//返回head
}

bool insert(LinkedNode* node, LinkedNode** head, int index)
{
	if (*head == nullptr)//如果链表是空的
	{//
		node->prev = nullptr;//定义node为链表第一个结点
		node->next = nullptr;//
		*head = node;//
		return true;//返回true
	}//
	LinkedNode* n = find(*head, index);//使指针n指向第index个结点
	if (n == nullptr)//如果不存在这个结点
	{//
		n = find(*head, index - 1);//让n指向第index-1个结点
		if (n == nullptr)//如果还不存在，即超出链表长度
		{//
			delete node;//删除node
			return false;//返回false
		}//
		else//
		{//否则即插入的为最后一个结点
			n->next = node;//把node与原最后一结点建立关系并使之作为最后一结点
			node->prev = n;//
			node->next = nullptr;//
			return true;//返回true
		}//
	}//
	if (n->prev == nullptr) *head = node;//如果要在第一个结点之前插入，让*head指向node
	else n->prev->next = node;//其他情况这一项前一项的next指向node
	node->prev = n->prev;//node的prev指向这一项的前一项
	node->next = n;//node的next指向这一项
	n->prev = node;//这一项的prev指向node
	return true;//返回true
}

bool remove(LinkedNode** head, int index)
{//
	LinkedNode* node = find(*head, index);//定义node指向第index个结点
	if (node == nullptr) return false;//如果node无法指向即超出链表返回false
	else if (node->prev == nullptr && node->next == nullptr)//否则当这一项为链表唯一的结点时
	{//
		*head = nullptr;//删除这一个结点
		return true;//返回true
	}//
	else//否则
	{//
		if (node->prev == nullptr) *head = node->next;//若删第一个结点，把*head指向下一个结点
		else node->prev->next = node->next;//否则它前一个结点的next指向它后一个结点
		if (node->next != nullptr) node->next->prev = node->prev;//若未删最后一个结点，把它下一个结点的prev指向它上一个结点
		delete node;//删除node指向的结点
		return true;//返回true
	}//
}

void destory(LinkedNode* head)
{//
	while (head != nullptr)//只要链表第一个结点存在
	{
		LinkedNode* tmp = head;//用tmp代表指向第一个结点
		head = head->next;//使head指向下一个结点
		delete tmp;//把第一个结点删除
	}//
}//
	else
	{
		if(node->prev == nullptr)*head = node->next;
		else node->prev->next=node->next;
		if (node->next !=nullptr)node->next->prev=node->prev;
		delete node;
		return true;
	}
}

void destory(LinkedNode* head)
{

}