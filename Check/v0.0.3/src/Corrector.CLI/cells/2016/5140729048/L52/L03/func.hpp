#pragma once
struct LinkedNode
{
	int data;
	LinkedNode* prev;
	LinkedNode* next;
};

LinkedNode* create(int* array, int size)
{
	LinkedNode *head, *iterator;
	head = iterator = new LinkedNode();//����һ���µ�����ͷ
	iterator->data = *array;
	iterator->prev = nullptr;
	iterator->next = nullptr;//��������ֵ
	for (int i = 1; i < size; i++)
	{
		iterator->next = new LinkedNode();//����ָ��ָ��һ���µ�����Ԫ
		iterator->next->data = array[i];//���´����ĵ�Ԫ��ֵ
		iterator->next->prev = iterator;
		iterator->next->next = nullptr;
		iterator = iterator->next;//����
	}
	return head;
}

LinkedNode* find(LinkedNode* head, int index)
{
	while (--index>0)//ѭ����index��0Ϊ�ж�����
	{
		if (head->next == nullptr) return nullptr;
		else head = head->next;//Ѱ��Ŀ��
	}
	return head;
}

bool insert(LinkedNode* node, LinkedNode** head, int index)
{
	if (*head == nullptr)//��0���룬�����½�һ��
	{
		node->prev = nullptr;
		node->next = nullptr;
		*head = node;
		return true;
	}
	LinkedNode* n = find(*head, index);//���ú���Ѱ�Ҳ����λ��
	if (n == nullptr)
	{
		n = find(*head, index - 1);
		if (n == nullptr)//�ж��Ƿ񳬳���Χ
		{
			delete node;
			return false;
		}
		else//�ڷ�Χ�ڣ�����
		{
			n->next = node;
			node->prev = n;
			node->next = nullptr;
			return true;
		}
	}
	if (n->prev == nullptr) *head = node;//β������
	else n->prev->next = node;
	node->prev = n->prev;
	node->next = n;
	n->prev = node;
	return true;
}

bool remove(LinkedNode** head, int index)
{
	LinkedNode* node = find(*head, index);//���ú�����λ��
	if (node == nullptr) return false;//������Χ
	else if (node->prev == nullptr && node->next == nullptr)//ֻ��һ�������
	{
		*head = nullptr;
		return true;
	}
	else//��Ҫɾ���ĵ�Ԫ������i������i-1�ĺ���ָ��ָ��i+1��i+1��ǰ��ָ��ָ��i-1������i
	{
		if (node->prev == nullptr) *head = node->next;
		else node->prev->next = node->next;
		if (node->next != nullptr) node->next->prev = node->prev;
		delete node;
		return true;
	}
}

void destory(LinkedNode* head)
{
	while (head != nullptr)//ɾ������
	{
		LinkedNode* tmp = head;
		head = head->next;
		delete tmp;
	}
}