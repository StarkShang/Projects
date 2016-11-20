#pragma once
struct LinkedNode//建立结构体LinkedNode
{
	int data;//包含整形元素data
	LinkedNode* prev;//包含LinkedNode形指针prev
	LinkedNode* next;//包含LinkedNode形指针next
};

LinkedNode* create(int* array, int size)
{
	LinkedNode *head, *iterator;//定义指针head,iterator为LinkedNode形
	head = iterator = new LinkedNode();//给头一个结点给定一个空间
	iterator->data = *array;//给头一个结点赋值
	iterator->prev = nullptr;//头结点的prev指向空
	iterator->next = nullptr;//头结点的next暂时指向空
	for (int i = 1; i < size; i++)//用循环体给接下来每一个结点赋值，便建立联系
	{
		iterator->next = new LinkedNode();//先给下一个结点给定一个空间
		iterator->next->data = array[i];//给接下来每一个结点赋值
		iterator->next->prev = iterator;//下一个结点的prev指向本节点地址
		iterator->next->next = nullptr;//下一个结点next暂时指向空
		iterator = iterator->next;//本结点的地址指向下一节点
	}//循环完毕，双向链表完成，最后一个结点的next指向空
	return head;//返回函数
}//提问：为什么不直接返回interator，虽然head与interator用的是同一空间，返回head不影响返回值，可直接返回interator不是更简洁吗，还不用定义head了

LinkedNode* find(LinkedNode* head, int index)
{
	while (--index>0)//当index大于0时循环，且index减1
	{
		if (head->next == nullptr) return nullptr;//若头结点为空，返回空
		else head = head->next;//否则指针往后移一个结点
	}//往后移index-1次后找到，第index个结点
	return head;//返回函数值
}

bool insert(LinkedNode* node, LinkedNode** head, int index)
{
	if (*head == nullptr)//若头结点为空为空
	{
		node->prev = nullptr;//所插入结点的prev为空
		node->next = nullptr;//所插入结点的next也为空
		*head = node;//插入节点即为头结点
		return true;//返回函数值
	}
	LinkedNode* n = find(*head, index);//找到要插入结点的位置
	if (n == nullptr)//若要插入的地方为空
	{
		n = find(*head, index - 1);//向前移一个结点
		if (n == nullptr)//若还为空
		{
			delete node;//删除要插入结点
			return false;//返回错误
		}
		else//若已不为空
		{
			n->next = node;//n(要插入结点）的next指向node（被插入链的最后一结点）
			node->prev = n;//node的prev指向n
			node->next = nullptr;//node的next指向空
			return true;//返回正确
		}
	}
	if (n->prev == nullptr) *head = node;//若要插入点的前一项为空，既要在头结点前插入结点，头结点为node
	else n->prev->next = node;//若要插入的地方不为空，要插入点的前一项也不为空
	node->prev = n->prev;//node（被插入链的被插入结点）的prev指向n(要插入结点）的prev
	node->next = n;//node的next指向n
	n->prev = node;//n的prev指向node
	return true;//返回正确
}

bool remove(LinkedNode** head, int index)
{
	LinkedNode* node = find(*head, index);//找到欲删除结点的位置
	if (node == nullptr) return false;//若该处为空，返回错误
	else if (node->prev == nullptr && node->next == nullptr)//若不为空且前一结点为空，后一结点为空，（该链只有一个结点且为头结点）
	{
		*head = nullptr;//删除该头结点（使该头结点为空）
		return true;//返回正确
	}
	else//若该位置不为空且前一结点不为空，后一结点也不为空
	{
		if (node->prev == nullptr) *head = node->next;//若要删除的结点前一结点为空（要删除的为头结点），头结点指向下一结点，此时头结点消失
		else node->prev->next = node->next;//若不为头结点，此结点的前一结的next跳过此结点直接指向下一结点
		if (node->next != nullptr) node->next->prev = node->prev;//若此结点的下一结点不为空（此结点不为最后一个结点），此结点的下一结点的prev跳过此结点直接指向上一结点，此结点从链中消失
		delete node;//删除此结点
		return true;//返回正确
	}
}

void destory(LinkedNode* head)
{
	while (head != nullptr)//当头节点不为空时循环
	{
		LinkedNode* tmp = head;//定义指针tmp使其指向头结点,
		head = head->next;//头结点的指针指向下一结点，头结点被从链中移除下一结点变为头结点
		delete tmp;//删除原头结点地址
	}
}
//以下为练习
bool append(LinkedNode*node,LinkedNode*head)
{
	if(head==NULL)return false;//若头结点为空，返回错误
	else//否则
	{
		while(head->next!=NULL)//当当前节点的下一结点不为空，进行循环
		{
			head=head->next;//向后移一结点
		}
		head->next=node;//当前节点的next指向被插入结点
		node->prev=head;//被插入结点的prev指向当前结点
		node->next=NULL;//被插入节点的next指向空
		return true;//返回正确
	}
}
