#pragma once

struct LinkedNode//建立结构体
{
	int data;//结点int类型数据
	struct LinkedNode * prev;//指针
	struct LinkedNode * next;//指针
};

LinkedNode* create(int* array, int size)//创建链表函数
{
	LinkedNode *head,*a;
	head=a=new LinkedNode();
	a->data=*array;
	a->prev=nullptr;
	a->next=nullptr;
	for(int i=1;i<size;i++)
	{
		a->next=new LinkedNode();
		a->next->data=array[i];
		a->next->prev=a;
		a->next->next=nullptr;
		a=a->next;
	}
	return head;
}

LinkedNode* find(LinkedNode* head, int index)//寻找第i个结点的函数
{
	int j=0;
	LinkedNode *p=head->next;
	while(j<index&&p!=NULL)
	{
		p=p->next;
		j++;
	}
	if(p!=NULL)
		return p;
	else return NULL;
}

bool insert(LinkedNode* node, LinkedNode** head, int index)//插入结点函数
{
	if(*head==nullptr)
	{
		node->prev=nullptr;
		node->next=nullptr;
		*head=node;
		return true;
	}
	LinkedNode*n=find(*head,index);
	if(n==nullptr)
	{
		n=find(*head,index-1);
		if(n==nullptr)
		{
			delete node;
			return false;//超出链表范围返回false
		}
		else
		{
			n->next=node;
			node->prev=n;
			node->next=nullptr;
			return true;
		}
	}
	if(n->prev==nullptr)*head=node;
	else n->prev->next=node;
	node->prev=n->prev;
	node->next=n;
	n->prev=node;
	return true;
}

bool remove(LinkedNode** head, int index)//删除结点函数
{
	LinkedNode*node=find(*head,index);
	if(node==nullptr)
		return false;//超出链表范围返回false
	else if(node->prev==nullptr&&node->next==nullptr)
	{
		*head=nullptr;
		return true;
	}
	else
	{
		if(node->prev==nullptr)*head=node->next;
		else node->prev->next=node->next;
		if(node->next!=nullptr)
			node->next->prev=node->prev;
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