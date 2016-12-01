#pragma once
struct LinkedNode
{
	int data;
	LinkedNode* prev;//ָ��ǰһ���ڵ��ָ��
	LinkedNode* next;//ָ���һ���ڵ��ָ��
};

LinkedNode* create(int* array, int size)
{
	LinkedNode *head, *iterator;//����ͷָ�� ����ָ��
	head = iterator = new LinkedNode();//��ʼ��
	iterator->data = *array;//��������
	iterator->prev = nullptr;//��ֵ��ǰһ��
	iterator->next = nullptr;//��ֵ����һ��
	for (int i = 1; i < size; i++)//����ѭ��
	{
		iterator->next = new LinkedNode();
		iterator->next->data = array[i];
		iterator->next->prev = iterator;
		iterator->next->next = nullptr;
		iterator = iterator->next;//�ڵ㸳ֵ
	}
	return head;//����ͷ
}

LinkedNode* find(LinkedNode* head, int index)
{
	while (--index>0)//��index��ֵ����0ʱ
	{
		if (head->next == nullptr) return nullptr;//������������ͷ��ؿ�
		else head = head->next;//������һ����Ϊͷ
	}
	return head;//����ͷ
}

bool insert(LinkedNode* node, LinkedNode** head, int index)

	if (*head == nullptr)//���ͷָ���ǿ�
	{
		node->prev = nullptr;//ָ��ڵ�ָ��ǰһ��
		node->next = nullptr;//ָ��ڵ�ָ���һ��
		*head = node;//��ֵ
		return true;//������ֵ
	}
	LinkedNode* n = find(*head, index);
	if (n == nullptr)//����������
	{
		n = find(*head, index - 1);//��n��ֵ
		if (n == nullptr)//����������
		{
			delete node;//ɾ���ڵ�
			return false;//����false
		}
		else//����
		{
			n->next = node;//n��Ϊ��һ���ڵ�ָ��
			node->prev = n;//ָ��ڵ�ָ��ǰһ��
			node->next = nullptr;//ָ��ڵ�ָ���һ��
			return true;//����true
		}
	}
	if (n->prev == nullptr) *head = node;//����������
	else n->prev->next = node;//����ѽڵ��ֵ��ֵֵ��n��ָ��ǰһ��ָ���ָ���һ��ָ��
	node->prev = n->prev;//ָ��ǰһ��ָ��
	node->next = n;//ָ���һ��ָ��
	n->prev = node;//�ڵ�ǰ��
	return true;//����TRUE
}

bool remove(LinkedNode** head, int index)
{
	LinkedNode* node = find(*head, index);
	if (node == nullptr) return false;//��Ⱦͷ���FALSE
	else if (node->prev == nullptr && node->next == nullptr)//��ͬʱ����
	{
		*head = nullptr;//ͷָ��ָ���
		return true;//����FALSE
	}
	else//����
	{
		if (node->prev == nullptr) *head = node->next;//����ڵ�ָ��ǰ���ǿգ���ôͷָ��ָ����һ��
		else node->prev->next = node->next;//����ڵ�ָ��ǰһ��ָ���ָ���һ��ָ��
		if (node->next != nullptr) node->next->prev = node->prev;
		delete node;//ɾ���ڵ�
		return true;//����TRUE
	}
}

void destory(LinkedNode* head)
{
	while (head != nullptr)//��ͷ���ǿ�ʱ
	{
		LinkedNode* tmp = head;
		head = head->next;//ͷָ����һ��
		delete tmp;//ɾ��
	}
}