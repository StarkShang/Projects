#pragma once
struct LinkedNode
{
	LinkedNode *prev;
	int data;
	LinkedNode *next;
};

LinkedNode* create(int* array, int size)
{
    LinkedNode *head, *iterator;
    head = iterator = new LinkedNode();
    iterator->data=*array;
    iterator->prev=nullptr;
    iterator->next=nullptr;
    
	for (int i=1; i<size; i++)
	{
        iterator->next = new LinkedNode();
        iterator->next->data = array[i];
        iterator->next->prev = iterator;
        iterator->next->next = nullptr;
        iterator=iterator->next;
	}
    return head;
}

LinkedNode* find(LinkedNode* head, int index)
{
    LinkedNode *temp=head;
    for (int i=0; i<index-1; i++)
    {
        temp = (*temp).next;
    }
    return temp;
}

bool insert(LinkedNode* node, LinkedNode** head, int index)
{
    if(*head==nullptr)
    {
       node->prev = nullptr;
       node->next = nullptr;
       *head = node;
       return true;
    }
    LinkedNode* n = find(*head, index);
    if(n == nullptr)
    {
        n=find(*head, index-1);
        if(n==nullptr)
        {
            delete node;
            return false;
        }
        else
        {
            n->next = node;
            node->prev = n;
            node->next = nullptr;
            return true;
        }
    }
    if(n->prev == nullptr) *head=node;
    else n->prev->next = node;
    node->prev = n->prev;
    node->next = n;
    n->prev = node;
    return true;
}

bool remove(LinkedNode** head, int index)
{
    LinkedNode *node = find(*head, index);
    if(node == nullptr) return false;
    else if(node->prev == nullptr && node->next == nullptr)
    {
        *head = nullptr;
        return true;
    }
    else
    {
        if(node->prev == nullptr) *head = node->next;
        else node->prev->next = node->next;
        if(node->next != nullptr) node->next->prev = node->prev;
        return true;
    }
}

void destory(LinkedNode* head)
{
    LinkedNode *temp=head, *temp1;
    while( temp->next != nullptr )
    {
        temp  = temp->next;
    }
	while( temp->prev != nullptr)
	{
		temp1 = temp->prev;
		delete temp;
		temp  = temp1;
	}
}
