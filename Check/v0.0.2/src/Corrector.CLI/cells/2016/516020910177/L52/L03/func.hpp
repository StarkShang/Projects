#pragma once
struct LinkedNode        //构建结构体
{
	LinkedNode *prev;
	int data;
	LinkedNode *next;
};

LinkedNode* create(int* array, int size)    //根据数组数据创建链表的函数
{
	LinkedNode*head,*node;
	head =node=new LinkedNode();
	node->data=*array;
	node->prev=nullptr;
	node->next=nullptr;
	for(int i=1;i<size;i++)
	{
		node->next=new LinkedNode();
		node->next->data=array[i];
		node->next->prev=node;
		node->next->next=nullptr;

		node=node->next;
	}
	return head;
}

LinkedNode* find(LinkedNode* head, int index)//找到第 i 个结点的函数
{
	LinkedNode*T=head;
	if(index==1) return T;
	for(int i=0;i<index-1;i++)
	{
		T=(*T).next;
	}
	return T;


}

bool insert(LinkedNode* node, LinkedNode** head, int index)//2.3在第 i 个结点处前插入结点的函数，插入成功，则返回 true。若超出链表范围，则返回 false 
{
	if(*head==nullptr)
	{
		node->prev=nullptr;
		node->next=nullptr;
		*head=node;
		return true;
	}
	LinkedNode*n=find(*head,index-1);
	if(n==nullptr)
	{
		n=find(*head,index-1);

	if(n==nullptr)
	{
		delete node;
		return false;
	}
	else
	{
		n->next=node;
		node->prev=n;
		node->next=nullptr;
		return true;
	}}
if(n->prev==nullptr) *head=node;
else n->prev->next=node;
node->prev=n->prev;
node->next=n;
n->prev=node;
return true;
}

bool remove(LinkedNode** head, int index)//删除第 i 个结点的函数，删除成功，则返回 true。若超出链表范围，则返回 false : 
{

	LinkedNode*node=find(*head,index);
	if(node==nullptr)return false;
	else if(node->prev==nullptr&&node->next==nullptr)
	{
		*head=nullptr;
		return true;
	}
	else
	{
		if (node->prev==nullptr)*head=node->next;
		else node->prev->next=node->next;
		if(node->next!=nullptr)node->next->prev=node->prev;
		delete node;
		return true;
}
}
void destory(LinkedNode* head)//销毁整个链表的函数
{
struct LinkedNode *p;
while(head!=NULL)
{
	p=head;
	head=head->next;
	p->next=NULL;
	free(p);
	p=NULL;
}


}
