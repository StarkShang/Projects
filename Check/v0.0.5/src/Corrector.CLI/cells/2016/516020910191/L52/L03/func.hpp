#pragma once
struct LinkedNode //����ṹ��
{
	int data;
	LinkedNode* prev;
	LinkedNode* next;
};

LinkedNode* create(int* array, int size)
{
	LinkedNode *head, *iterator;//����ڵ�ͷָ�� ����ָ��
	head = iterator = new LinkedNode();
	iterator->data = *array;//�����е�ֵ��ֵ������ָ���������
	iterator->prev = nullptr;//�ո�ֵ��ָ��ǰһ���ڵ��ָ��
	iterator->next = nullptr;//�ո�ֵ��ָ���һ���ڵ��ָ��
	for (int i = 1; i < size; i++)//ѭ��
	{
		iterator->next = new LinkedNode();
		iterator->next->data = array[i];//ѭ����ֵͷָ���ֵ����һ���ڵ������
		iterator->next->prev = iterator;//������ָ�븳ֵ����һ���ڵ��ָ��ǰһ���ڵ��ָ��
		iterator->next->next = nullptr;//���ո�ֵ��ָ����һ��ָ��Ľڵ��ָ��
		iterator = iterator->next;//ָ����һ������ָ��Ľڵ㸳ֵ������ָ��
	}
	return head;
}

LinkedNode* find(LinkedNode* head, int index)
{
	while (--index>0)
	{
		if (head->next == nullptr) return nullptr;//��ͷָ���ָ����һ���ڵ��ֵΪ�� ���ؿ�
		else head = head->next;//����ͷָ��ָ����һ���ڵ��ֵ��ֵ��ͷָ��
	}
	return head;
}

bool insert(LinkedNode* node, LinkedNode** head, int index)
{
	if (*head == nullptr)//��ͷָ��Ϊ��
	{
		node->prev = nullptr;//�ڵ�ָ��ǰһ��ָ���ֵΪ��
		node->next = nullptr;//�ڵ�ָ���һ��ָ���ֵΪ��
		*head = node;//���ڵ��ֵ��ֵ��ͷָ��
		return true;
	}
	LinkedNode* n = find(*head, index);
	if (n == nullptr)//��nΪ��
	{
		n = find(*head, index - 1);//��find���� �Ľ����ֵ��n
		if (n == nullptr)//��nΪ��
		{
			delete node;//����ڵ�
			return false;//���ش���
		}
		else
		{
			n->next = node;//���ڵ��ֵ��ֵ��ָ���һ���ڵ��ָ��
			node->prev = n;//��n��ֵ��ָ��ǰһ���ڵ��ָ��
			node->next = nullptr;//���ո�ֵ��ָ���һ���ڵ��ָ��
			return true;//������ȷ
		}
	}
	if (n->prev == nullptr) *head = node;//��ָ��nǰһ��ָ���ֵΪ�� ���ڵ��ָ�븳ֵ��ͷָ��
	else n->prev->next = node;
	node->prev = n->prev;//��nָ��ǰһ��ָ���ֵ��ֵ�����е�ָ��ǰһ��ָ���ֵ
	node->next = n;//��n��ֵ�����е�ָ����һ��ָ���ֵ
	n->prev = node;//�����и�ֵ��n��ָ��ǰһ��ָ���ֵ
	return true;//������ȷ
}

bool remove(LinkedNode** head, int index)
{
	LinkedNode* node = find(*head, index);
	if (node == nullptr) return false;//���ڵ�Ϊ�� ���ش���
	else if (node->prev == nullptr && node->next == nullptr)//������ �ڵ�ָ��ǰ���ָ��Ϊ��
	{
		*head = nullptr;//ͷָ��Ϊ��
		return true;//������ȷ
	}
	else
	{
		if (node->prev == nullptr) *head = node->next;//���ڵ�ָ��ǰһ��ָ���ֵΪ�� ���ڵ�ָ���һ��ָ���ֵ��ֵ��ͷָ��
		else node->prev->next = node->next;//���򽫽ڵ�ָ���һ��ָ���ֵ��ֵ���ڵ�ָ���һ��ǰһ��ָ���ֵ
		if (node->next != nullptr) node->next->prev = node->prev;//���ڵ�ָ����һ��ָ���ֵ��Ϊ�� ���ڵ�ָ��ǰһ��ָ���ֵ��ֵ���ڵ�ָ���һ��ǰһ��
		delete node;//����ڵ�
		return true;//������ȷ 
	}
}

void destory(LinkedNode* head)
{
	while (head != nullptr)//��ͷָ�벻Ϊ��
	{
		LinkedNode* tmp = head;//ͷָ�븳ֵ��
		head = head->next;//ͷָ��ָ����һ���ڵ��ֵ��ֵ��ͷָ��
		delete tmp;//���tmp
	}
}