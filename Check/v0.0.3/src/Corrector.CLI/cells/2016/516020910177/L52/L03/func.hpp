#pragma once
struct LinkedNode        //�����ṹ��
{
	LinkedNode *prev;
	int data;
	LinkedNode *next;
};

LinkedNode* create(int* array, int size)    //�����������ݴ�������ĺ���
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

LinkedNode* find(LinkedNode* head, int index)//�ҵ��� i �����ĺ���
{
	LinkedNode*T=head;
	if(index==1) return T;
	for(int i=0;i<index-1;i++)
	{
		T=(*T).next;
	}
	return T;


}

bool insert(LinkedNode* node, LinkedNode** head, int index)//2.3�ڵ� i ����㴦ǰ������ĺ���������ɹ����򷵻� true������������Χ���򷵻� false 
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

bool remove(LinkedNode** head, int index)//ɾ���� i �����ĺ�����ɾ���ɹ����򷵻� true������������Χ���򷵻� false : 
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
