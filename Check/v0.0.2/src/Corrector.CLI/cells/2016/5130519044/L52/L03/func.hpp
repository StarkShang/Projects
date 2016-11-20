#pragma once
struct LinkedNode
{
	int data;
	LinkedNode* prev;
	LinkedNode* next;
};

LinkedNode* create(int* array, int size) //�����������ݴ�����������
{
	LinkedNode *head, *iterator;
	head = iterator = new LinkedNode();
	iterator->data = *array; //�ڵ������ָ�������Ԫ��
	iterator->prev = nullptr;//prev��nextָ�븳ֵΪ��ָ��
	iterator->next = nullptr;
	for (int i = 1; i < size; i++)
	{
		iterator->next = new LinkedNode(); //����һ�����LinkedNode�����ݵĿռ䣨���ڵ㣩
		iterator->next->data = array[i];
		iterator->next->prev = iterator;
		iterator->next->next = nullptr;
		iterator = iterator->next;
	}
	return head;
}

LinkedNode* find(LinkedNode* head, int index) //�ҵ���i���ڵ�ĺ���
{
	while (--index>0)
	{
		if (head->next == nullptr) return nullptr;
		else head = head->next;
	}
	return head;
}

bool insert(LinkedNode* node, LinkedNode** head, int index) //�ڵ�i���ڵ�ǰ����ڵ�
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
	else n->prev->next = node;
	node->prev = n->prev;
	node->next = n;
	n->prev = node;
	return true;
}

bool remove(LinkedNode** head, int index) //ɾ����i���ڵ�
{
	LinkedNode* node = find(*head, index);
	if (node == nullptr) return false;
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
		delete node;
		return true;
	}
}

void destory(LinkedNode* head) //������������
{
	while (head != nullptr)
	{
		LinkedNode* tmp = head;
		head = head->next;
		delete tmp;
	}
}