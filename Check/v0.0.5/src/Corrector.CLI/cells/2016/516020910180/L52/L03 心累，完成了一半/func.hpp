#pragma once
struct LinkedNode
{
	LinkedNode* prev;
	int data;
	LinkedNode* next;
};

LinkedNode* create(int* array, int size)
{
	LinkedNode* HEAD=new LinkedNode;
	HEAD->prev=NULL;
	HEAD->next=NULL;
	HEAD->data=*array;
	LinkedNode* link=HEAD;
	int i;
	for(i=1;i<size;i++)
	{
		link->next=new LinkedNode;
		link->next->data=array[i];
		link->next->prev=link;
		link->next->next=NULL;
		link=link->next;
	}
	return HEAD;
}

LinkedNode* find(LinkedNode* head, int index)
{
	int i;
	LinkedNode* find=head;
	for(i=1;i<index;i++)
		find=find->next;
	return find;
}

bool insert(LinkedNode* node, LinkedNode** head, int index)
{
	if(*head=NULL)
	{
		node->prev=NULL;
		node->next=NULL;
		*head=node;
		return true;
	}
	else
	{
		LinkedNode* node_i=find(*head,index);
		if(node_i==NULL)
		{
			delete node;
			return false;
		}
		else
		{
			node->next=node_i;
			node->prev=node_i->prev;
			node_i->prev->next=node;
			node_i->prev=node;
			return true;
		}
	}
}

bool remove(LinkedNode** head, int index)
{
	LinkedNode* n=find(*head,index);
	if(n=NULL)
		return false;
	else
	{
		if(find(*head,index+1)==NULL)
		{
			n->prev->next=NULL;
			delete n;
		}
		else
		{
			n->prev->next=n->next;
			n->next->prev=n->prev;
			delete n;
		}
		return true;
	}
}

void destory(LinkedNode* head)
{

}