#pragma once

struct LinkedNode//�����ṹ��
{
	int data;//���int��������
	struct LinkedNode * prev;//ָ��
	struct LinkedNode * next;//ָ��
};

LinkedNode* create(int* array, int size)//����������
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

LinkedNode* find(LinkedNode* head, int index)//Ѱ�ҵ�i�����ĺ���
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

bool insert(LinkedNode* node, LinkedNode** head, int index)//�����㺯��
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
			return false;//��������Χ����false
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

bool remove(LinkedNode** head, int index)//ɾ����㺯��
{
	LinkedNode*node=find(*head,index);
	if(node==nullptr)
		return false;//��������Χ����false
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

void destory(LinkedNode* head)//������������ĺ���
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