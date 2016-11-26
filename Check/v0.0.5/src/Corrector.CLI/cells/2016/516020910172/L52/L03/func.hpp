#pragma once
struct LinkedNode//�����ṹ��
{
	int data;//���int��������
	LinkedNode* prev;//linkednodeָ��
	LinkedNode* next;//linkednodeָ��
};

LinkedNode* create(int* array, int size)//���ڸ����������ݴ�������ĺ���
{
	LinkedNode *head, *iterator;//��������linkednode�ṹ��
	head = iterator = new LinkedNode();//����һ���µ�head
	iterator->data = *array;//�м������dataָ��array
	iterator->prev = nullptr;//��prev��ֵΪ��
	iterator->next = nullptr;//��next��ֵΪ��
	for (int i = 1; i < size; i++)//ѭ������node
	{
		iterator->next = new LinkedNode();//�����µĽṹ��
		iterator->next->data = array[i];//��data��ֵ
		iterator->next->prev = iterator;//��prev��ֵΪǰһ��iterator
		iterator->next->next = nullptr;//��next��ֵΪ��
		iterator = iterator->next;//iterator��ֵΪǰһ����next
	}
	return head;//����head
}

LinkedNode* find(LinkedNode* head, int index)//�ҵ���i�����ĺ���
{
	while (--index>0)//��ʼѭ������
	{
		if (head->next == nullptr) return nullptr;//����ҵ����nextΪ�գ����ؿ�
		else head = head->next;//һ��һ��������
	}
	return head;//����head
}

bool insert(LinkedNode* node, LinkedNode** head, int index)//�ڵ�i�����ǰ������ĺ���
{
	if (*head == nullptr)//���headΪ��
	{
		node->prev = nullptr;//��prev��ֵΪ��
		node->next = nullptr;//��next��ֵΪ��
		*head = node;
		return true;//���ز���ɹ�
	}
	LinkedNode* n = find(*head, index);//����find�������ҽ��
	if (n == nullptr)
	{
		n = find(*head, index - 1);//����ֵ��ǰһλ
		if (n == nullptr)//�ж��Ƿ��ҵ�
		{
			delete node;
			return false;//û���ҵ�����false
		}
		else
		{
			n->next = node;//��next��ֵΪnode
			node->prev = n;//node��prev��ֵΪn
			node->next = nullptr;//node��next��ֵΪ��
			return true;//���ز���ɹ�
		}
	}
	if (n->prev == nullptr) *head = node;//head��ֵΪnode
	else n->prev->next = node;
   node->prev = n->prev;//��n��prev��ֵ��node
	node->next = n;//node��next��ֵΪn
	n->prev = node;//n��prev��ֵΪnode
	return true;//���ز���ɹ�
}

bool remove(LinkedNode** head, int index)//ɾ����i�����ĺ���
{
	LinkedNode* node = find(*head, index);//���ýṹ��node����Ϊfind���� ���ҽ��
	if (node == nullptr) return false;//������Ҳ��� ����false
	else if (node->prev == nullptr && node->next == nullptr)//���prev��nextͬΪ��
	{
		*head = nullptr;//headΪ��
		return true;//����true
	}
	else
	{
		if (node->prev == nullptr) *head = node->next;//���prevΪ�� head��ֵΪnode�е�next
		else node->prev->next = node->next;
		if (node->next != nullptr) node->next->prev = node->prev;//���next��Ϊ�յ����
		delete node;//�ҵ��ڵ㲢ɾ��
		return true;//����ɾ���ɹ�true
	}
}

void destory(LinkedNode* head)//������������
{
	while (head != nullptr)//��ʼѭ��ֱ��headΪ��
	{
		LinkedNode* tmp = head;//������ʱ����
		head = head->next;//ָ���������ָ
		delete tmp;//ɾ������
	}
}