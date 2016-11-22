#pragma once
struct LinkedNode //创建结构体
{
	int data; //结点整型数据
	LinkedNode* prev;//结构体指针prev
	LinkedNode* next;//结构体指针next
};

LinkedNode* create(int* array, int size) //创建链表
{
	LinkedNode *head, *iterator;  //定义两个结构体指针
	head = iterator = new LinkedNode();//开辟存放结构体的空间
	iterator->data = *array;  //将数据放入结点
	iterator->prev = nullptr;
	iterator->next = nullptr;
	for (int i = 1; i < size; i++)
	{
		iterator->next = new LinkedNode();//开辟存放结构体的空间
		iterator->next->data = array[i];//将数据放入结点
		iterator->next->prev = iterator;
		iterator->next->next = nullptr;
		iterator = iterator->next; //将前后结点进行联系
	}
	return head;
}

LinkedNode* find(LinkedNode* head, int index)//找到第i个结点
{
	while (--index>0)
	{
		if (head->next == nullptr) return nullptr;//超出链表长度返回空
		else head = head->next; //进行查找
	}
	return head; //返回查找结点
}

bool insert(LinkedNode* node, LinkedNode** head, int index)//在第i个结点前添加一个结点
{
	if (*head == nullptr)
	{
		node->prev = nullptr;
		node->next = nullptr;
		*head = node;  //当链表为空时，直接插入第一个结点
		return true;
	}
	LinkedNode* n = find(*head, index);//查找需要插入的位置结点
	if (n == nullptr)
	{
		n = find(*head, index - 1);
		if (n == nullptr)
		{
			delete node;
			return false;//当插入位置多于最后结点两个时，插入失败
		}
		else
		{
			n->next = node;
			node->prev = n;
			node->next = nullptr;//在末位置增加一个节点
			return true;
		}
	}
	if (n->prev == nullptr) *head = node;//将节点插入首位置
	else n->prev->next = node; 
	node->prev = n->prev;
	node->next = n;
	n->prev = node;//在中间位置插入结点
	return true;
}

bool remove(LinkedNode** head, int index)//删除第i个结点
{
	LinkedNode* node = find(*head, index);//查找需要删除的位置结点
	if (node == nullptr) return false;
	else if (node->prev == nullptr && node->next == nullptr)
	{
		*head = nullptr;//当链表只有一个节点时，将此节点删除
		return true;
	}
	else
	{
		if (node->prev == nullptr) *head = node->next;//查找需要删除的结点在开头时，将第一个结点屏蔽
		else node->prev->next = node->next;//不在第一个位置时，将查找的结点屏蔽
		if (node->next != nullptr) node->next->prev = node->prev;//当要删除的结点不为空时，进行屏蔽
		delete node;
		return true;
	}
}

void destory(LinkedNode* head) //销毁链表
{
	while (head != nullptr) //当结点存在时进行while循环操作
	{
		LinkedNode* tmp = head;//将节点复制给tnm
		head = head->next;//将第一个结点屏蔽
		delete tmp;//撤销tnm
	}
}

bool append(LinkedNode*node,LinkedNode* head) //在链表最后面添加一个结点
{
	if(head==nullptr)
	{
		node->prev = nullptr;
		node->next = nullptr;
		head = node;  //当链表为空时，直接添加为第一个结点
		return true;
	}
	else
	{
		while(head!=nullptr)
		{
			head = head->next;//当链表不为空时，查找最后一个节点
		}
		node->prev=head;
		node->next = nullptr;//在最后面添加一个节点
		return true;
	}
}
