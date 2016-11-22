#pragma once
struct LinkedNode//��������Ľṹ��
{
	int data; //������int��������
	LinkedNode* prev;//������ǰ��ָ��
	LinkedNode* next;//��������ָ��
};

LinkedNode* create(int* array, int size)//���崴��������
{
	LinkedNode *head, *iterator;//��������ָ�����
	head = iterator = new LinkedNode();//ָ�������ʼ��
	iterator->data = *array;//�����ͱ�������ֵ
	iterator->prev = nullptr;//��ָ�����prev����ֵ
	iterator->next = nullptr;//��ָ�����next����ֵ
	for (int i = 1; i < size; i++)//����forѭ��������ָ����Ŀ�Ľ��
	{
		iterator->next = new LinkedNode();//������һ�����
		iterator->next->data = array[i];//�洢��i������
		iterator->next->prev = iterator;//����Ӧ��ָ�������ֵ
		iterator->next->next = nullptr;
		iterator = iterator->next;
	}
	return head;//��������Ϸ��غ�������
}

LinkedNode* find(LinkedNode* head, int index)//����Ѱ�ҽ��ĺ���
{
	while (--index>0)//Ѱ��ָ���Ľ��
	{
		if (head->next == nullptr) return nullptr;
		else head = head->next;
	}
	return head;
}

bool insert(LinkedNode* node, LinkedNode** head, int index)//������Ʋ�����ĺ���
{
	if (*head == nullptr)
	{
		node->prev = nullptr;
		node->next = nullptr;
		*head = node;
		return true;
	}
	LinkedNode* n = find(*head, index);//Ѱ����Ҫ�������λ��
	if (n == nullptr)
	{
		n = find(*head, index - 1);//���ҵ��Ľ��ǰ������
		if (n == nullptr)//�����������Χ������ʧ�ܣ�����false
		{
			delete node;
			return false;
		}
		else//���δ��������Χ������ɹ�������true
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

bool remove(LinkedNode** head, int index)//�������ɾ���ڵ�ĺ���
{
	LinkedNode* node = find(*head, index);//Ѱ����Ҫɾ���Ľ��
	if (node == nullptr) return false;//����Ҳ�����Ҫ�Ľ�㣬����false
	else if (node->prev == nullptr && node->next == nullptr)//�жϸ������½���ɾ��ָ��
	{
		*head = nullptr;
		return true;
	}
	else//ɾ����Ҫɾ���Ľ�㣬ɾ���ɹ�����true
	{
		if (node->prev == nullptr) *head = node->next;
		else node->prev->next = node->next;
		if (node->next != nullptr) node->next->prev = node->prev;
		delete node;
		return true;
	}
}

void destory(LinkedNode* head)//������������ĺ���
{
	while (head != nullptr)//����whileѭ�����������б�
	{
		LinkedNode* tmp = head;
		head = head->next;
		delete tmp;
	}
}