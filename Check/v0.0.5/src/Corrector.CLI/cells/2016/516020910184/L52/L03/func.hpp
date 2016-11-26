#pragma once
struct LinkedNode//建立结构体，包含 LinkedNode指针prev，int型data LinkedNode指针next
{
	 LinkedNode *prev;
	 int data;
	 LinkedNode *next;
};

LinkedNode* create(int* array, int size)
{
	 LinkedNode *head,*iterator;//定义LinkedNode型结构体head,iterator；
	 head = iterator = new LinkedNode();//为head,iterator分配动态内存
	 iterator->data=*array;//将数组首元素的值分给iterator的data
	 iterator->prev=nullptr;//iterator指向前一个的指针为空
	 iterator->next=nullptr;//iterator指向后一个的指针为空
	 for(int i=1;i<size;i++)//循环语句给链表赋值
	 {
		 iterator->next=new LinkedNode();//给iterator分配动态内存
		 iterator->next->data=array[i];//将数组第i个元素的值分给iterator的next 的data
		 iterator->next->prev=iterator;//iterator的next 的pre指向iterator本身
		 iterator->next->next=nullptr;//iterator的next 的next指向空
		 iterator= iterator->next;//iterator指向它的next

	 }
	 return head;//返回LinkedNode型结构体head
}

LinkedNode* find(LinkedNode* head, int index)
{
	 LinkedNode *iterator;//定义LinkedNode型结构体iterator
	 iterator = head;//iterator指向head
	 int i;//定义变量
	for( i=0;i<index;i++)//循环语句找到第i个节点
	 {
		 if(iterator->next != nullptr)//如果存在需要找到的第i个节点
		 iterator =iterator->next;//执行iterator指向它的next
		 else break;//否则跳出循环语句
	 }
	if(i==(index-1))return iterator;//如果存在需要找到的第i个节点，返回iterator
	else return nullptr;//否则返回空
}

bool insert(LinkedNode* node, LinkedNode** head, int index)
{
	
	if (*head == nullptr)//当链表为空的时候，创建一个结点node，返回true

	{
		node->prev = nullptr;
		node->next = nullptr;
		*head = node;
		return true;
	}
	else if( find( *head,  index)!=nullptr ||find( *head,  index-1)!=nullptr)//如果存在需要找到的第i个节点，执行插入语句并返回真
		{
		 
		 node->next=find( *head,  index);//node的next指向第i个节点
		 node->prev=find( *head,  (index-1));//node的pre指向第i-个节点
		 return true;//返回真
		}
	else //如果不存在需要找到的第i个节点，返回假
		return false;
	
}

bool remove(LinkedNode** head, int index)
{
	LinkedNode* n = find(*head, index);
	if (*head == nullptr)//当链表为空的时候，返回false

	{
		return false;
	}
	else if( n!=nullptr )//如果存在需要找到的第i个节点，执行删除语句并返回真
	{
		n=nullptr;
		find(*head, index-1)->next=find(*head, index+1);
		find(*head, index+1)->prev=find(*head, index-1);
		return true;
	}
	else//如果不存在需要找到的第i个节点，返回假
		return false;

}

void destory(LinkedNode* head)
{
	while (head != nullptr)
	{
		LinkedNode* tmp = head;
		head = head->next;
		delete tmp;
	}
}