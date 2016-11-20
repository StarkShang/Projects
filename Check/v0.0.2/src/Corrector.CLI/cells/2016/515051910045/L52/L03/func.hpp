#pragma once
struct LinkedNode    //定义一个结构体来表示节点
{
	int data;
	LinkedNode* prev;
	LinkedNode* next;
};

LinkedNode* create(int* array, int size)   //定义create函数来创建一个链表
{
	LinkedNode *head, *iterator;
	head = iterator = new LinkedNode();       //定义首地址并赋值
	iterator->data = *array;                 //首地址所对应的数据赋值
	iterator->prev = nullptr;                //首地址的前一个结点地址为空
	iterator->next = nullptr;                //首地址的下一个结点地址为空
	for (int i = 1; i < size; i++)
	{
		iterator->next = new LinkedNode();   //定义下一个结点的地址
		iterator->next->data = array[i];    //对下一个结点所对应数据赋值
		iterator->next->prev = iterator;     //将下一个结节点的地址与此结点地址对应关系
		iterator->next->next = nullptr;     //定义下下一个结点的地址为空
		iterator = iterator->next;         //对下一个结点的地址赋值
	}
	return head;
}

LinkedNode* find(LinkedNode* head, int index)     //定义函数find来寻找第index个结点
{
	while (--index>0)       
	{ 
		if (head->next == nullptr) return nullptr;    //如果超出范围，则返回空
		else head = head->next;      //通过索引的变换来求出索引对应的地址并将该地址赋给首地址
	}
	return head;
}
 
bool insert(LinkedNode* node, LinkedNode** head, int index)       //定义insert函数来插入一个新的结点
{ 
	if (*head == nullptr)
	{
		node->prev = nullptr;
		node->next = nullptr;
		*head = node;
		return true;
	}
	LinkedNode* n = find(*head, index);
	if (n == nullptr)        //判断是否超出范围
	{
		n = find(*head, index - 1);//判断能否不在链表的最后一位
		if (n == nullptr)   //不能添加到最后一位则返回false
		{
			delete node;
			return false;
		}
		else                //能添加到最后一位则返回true
		{
			n->next = node;        
			node->prev = n;      
			node->next = nullptr;  
			return true;
		}
	}
	if (n->prev == nullptr) *head = node;      //判断是否添加的链节在首位
	else n->prev->next = node;      //添加的结点既不在首位也不在末位
	node->prev = n->prev;
	node->next = n;
	n->prev = node;
	return true;
}

bool remove(LinkedNode** head, int index)     //定义remove函数来移除一个结点
{
	LinkedNode* node = find(*head, index);
	if (node == nullptr) return false;       //判断结点是否存在
	else if (node->prev == nullptr && node->next == nullptr)     //判断是否仅有一个结点
	{
		*head = nullptr;
		return true;
	}
	else
	{
		if (node->prev == nullptr) *head = node->next;    //判断是否为首结点
		else node->prev->next = node->next;
		if (node->next != nullptr) node->next->prev = node->prev;
		delete node;
		return true;
	}
}

void destory(LinkedNode* head)   //定义destory函数来销毁整个链表
{
	while (head != nullptr)        //判断首地址是否为空
	{
		LinkedNode* tmp = head;     
		head = head->next;
		delete tmp;
	}
}