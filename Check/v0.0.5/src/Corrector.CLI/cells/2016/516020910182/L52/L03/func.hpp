#pragma once
struct LinkedNode
{
	LinkedNode* prev;
	LinkedNode* next;
	int data;
};

LinkedNode* create(int* array, int size)
{
	LinkedNode  *head,*iterator;
	head=iterator=new LinkedNode();
	(*iterator).data=*array;
	(*iterator).prev=nullptr;
	(*iterator).next=nullptr;
	for(int i=1;i<size;i++)
	{
		(*iterator).next=new LinkedNode();
		(*((*iterator).next)).data=array[i];
		(*((*iterator).next)).prev=iterator;
		(*((*iterator).next)).next=nullptr;
		iterator=(*iterator).next;
	}
	return head;
}

LinkedNode* find(LinkedNode* head, int index)
{
	LinkedNode *node;
	node=head;
	for(int i=1;i<index;i++)
	{
		if(node==nullptr)
		{
			break;
		}
		else node = (*node).next;
	}
	return node;
}

bool insert(LinkedNode* node, LinkedNode** head, int index)
{
	LinkedNode *nodep;
	LinkedNode *noden;
    noden=find( *head, index);
	if(noden!=nullptr)
	{
		if(index!=1)
		{
			nodep=(*noden).prev;
			(*node).next=noden;
			(*node).prev=nodep;
			(*noden).prev=node;
			(*nodep).next=node;
			return true;
		}
		else
		{
			int n;
			n=(**head).data;
			(**head).data=(*node).data;
			(*node).next=(**head).next;
			(*node).data=n;
			(*node).prev=*head;
			(**head).next=node;
			return true;
		}
	}
	else return false;
}

bool remove(LinkedNode** head, int index)
{
	LinkedNode* node=find(*head , index);
	if(node==nullptr) return false;
	else if((*node).prev==nullptr && (*node).next==nullptr)
	{
		*head=nullptr;
		return true;
	}
	else
	{
		if((*node).prev==nullptr) *head=(*node).next;
		else (*(*node).prev).next=(*node).next;
		if((*node).next!=nullptr)  (*(*node).next).prev=(*node).prev;
		delete node;
		return true;
	}
}

void destory(LinkedNode* head)
{
	LinkedNode* n;
	n=head;
	for(int t=0;t<1024;t++)
	{
		if((*n).next==nullptr) break;
		else n=(*n).next;
	}
	for(int m=0;m<1024;m++)
	{
		if((*n).prev==nullptr) break;
		else
		{
			n=(*n).prev;
			(*n).next=nullptr;
		}
	}
	n=nullptr;
}