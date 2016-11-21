#pragma once
struct LinkedNode
{
	int data;
	LinkedNode* prev;
	LinkedNode* next;
};                                            //�������������struct����

LinkedNode* create(int* array, int size)      //�������鴴������
{
	LinkedNode *head, *iterator;              
	head = iterator = new LinkedNode();       //������һ���ڵ�
	iterator->data = *array;
	iterator->prev = nullptr;
	iterator->next = nullptr;                 //��prevָ���һ���ڵ�
	for (int i = 1; i < size; i++)
	{
		iterator->next = new LinkedNode();           //�����ڵ�
		iterator->next->data = array[i];             //�������ݸ�ֵ
		iterator->next->prev = iterator;             //ָ��ǰһ����ָ��
		iterator->next->next = nullptr;              //
		iterator = iterator->next;                   //ָ����һ���ڵ�
	}
	return head;                                     //���ص�һ���ڵ�ĵ�ַ
}

LinkedNode* find(LinkedNode* head, int index)        //�ҵ���һ���ڵ�
{
	while (--index>0)
	{
		if (head->next == nullptr) return nullptr;    //�������ڽڵ���������nullptr
		else head = head->next;
	}
	return head;
}

bool insert(LinkedNode* node, LinkedNode** head, int index)      //�ڵ�i���ڵ㴦ǰ����ڵ�ĺ���������ɹ��򷵻�true��
{
	if (*head == nullptr)
	{
		node->prev = nullptr;
		node->next = nullptr;
		*head = node;
		return true;
	}
	LinkedNode* n = find(*head, index);
	if (n == nullptr)
	{
		n = find(*head, index - 1);
		if (n == nullptr)
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
	if (n->prev == nullptr) *head = node;
	else n->prev->next = node;                          //����i-1���ڵ��ָ��ָ��ָ��node
	node->prev = n->prev;                               //��node��ָǰָ��ָ���i-1���ڵ�
	node->next = n;                                     //��node��ָ��ָ��ָ���i���ڵ�
	n->prev = node;                                     //����i���ڵ��ָǰָ��ָ��node
	return true;                                        //����true
}

bool remove(LinkedNode** head, int index)                   //ɾ����i���ڵ�
{
	LinkedNode* node = find(*head, index);
	if (node == nullptr) return false;                                //�ҵ���i���ڵ�
	else if (node->prev == nullptr && node->next == nullptr)
	{
		*head = nullptr;
		return true;
	}
	else
	{
		if (node->prev == nullptr) *head = node->next;
		else node->prev->next = node->next;
		if (node->next != nullptr) node->next->prev = node->prev;
		delete node;                                              //ɾ����i���ڵ�
		return true;
	}
}

void destory(LinkedNode* head)                           //������������
{
	while (head != nullptr)
	{
		LinkedNode* tmp = head;
		head = head->next;
		delete tmp;
	}
}