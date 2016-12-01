#pragma once
struct LinkedNode
{
	int data;
	LinkedNode* prev;
	LinkedNode* next;
};

LinkedNode* create(int* array, int size)
{
	LinkedNode *head, *iterator;//ָʾ��
	head = iterator = new LinkedNode();
	iterator->data = *array;
	iterator->prev = nullptr;
	iterator->next = nullptr;//��ʼ��
	for (int i = 1; i < size; i++)//ѭ��
	{
		iterator->next = new LinkedNode();//������һ��
		iterator->next->data = array[i];//��������
		iterator->next->prev = iterator;//��������
		iterator->next->next = nullptr;//��������һ��
		iterator = iterator->next;//�ƶ�ָʾ��
	}
	return head;//������������head
}

LinkedNode* find(LinkedNode* head, int index)
{
	while (--index>0)//ѭ����Ҫ����������
	{
		if (head->next == nullptr) return nullptr;
		else head = head->next;//�������
	}
	return head;
}

bool insert(LinkedNode* node, LinkedNode** head, int index)
{
	if (*head == nullptr)//�յ�����
	{
		node->prev = nullptr;
		node->next = nullptr;
		*head = node;//ֱ�Ӵ���һ��
		return true;
	}
	LinkedNode* n = find(*head, index);//ʹ�������
	if (n == nullptr)//����Χ
	{
		n = find(*head, index - 1);//ǰһ��
		if (n == nullptr)//���ǳ���Χ
		{
			delete node;
			return false;//�޷�����
		}
		else//ĩβ��
		{
			n->next = node;
			node->prev = n;
			node->next = nullptr;
			return true;//��ĩβ��ӣ�����ɹ�
		}
	}
	if (n->prev == nullptr) *head = node;//��һ��ֱ�����
	else n->prev->next = node;//�м����ȡ�ռ�
	node->prev = n->prev;//n֮�䲻��
	node->next = n;
	n->prev = node;//���뵽ԭ��n��λ��
	return true;//����ɹ�
}

bool remove(LinkedNode** head, int index)
{
	LinkedNode* node = find(*head, index);//�����
	if (node == nullptr) return false;//û����Ƴ�ʧ��
	else if (node->prev == nullptr && node->next == nullptr)//ֻ��һ��
	{
		*head = nullptr;
		return true;//ȫɾ�⣬�ɹ�
	}
	else//��ֹһ��
	{
		if (node->prev == nullptr) *head = node->next;//ԭλ�ǵ�һ�head����Ųһ��
		else node->prev->next = node->next;//ԭλ�������ԭλ������ռ��
		if (node->next != nullptr) node->next->prev = node->prev;//����������һ���Ҫ˵��һ�º���ռ����ԭλ
		delete node;//ɾ��ԭλ����
		return true;//�ɹ�
	}
}

void destory(LinkedNode* head)
{
	while (head != nullptr)//ɾ��֮ǰ
	{
		LinkedNode* tmp = head;//��ȡhead
		head = head->next;//����Ųһ��head
		delete tmp;//����ȡ�����Ķ���ɾ��
	}
}