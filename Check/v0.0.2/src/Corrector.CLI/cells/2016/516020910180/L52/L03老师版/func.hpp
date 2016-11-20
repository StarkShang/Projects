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
	head = iterator = new LinkedNode();//��������ĵ�һ���ṹ��
	iterator->data = *array;
	iterator->prev = nullptr;
	iterator->next = nullptr;
	for (int i = 1; i < size; i++)//������������ʽ����
	{
		iterator->next = new LinkedNode();
		iterator->next->data = array[i];
		iterator->next->prev = iterator;
		iterator->next->next = nullptr;
		iterator = iterator->next;
	}
	return head;
}

LinkedNode* find(LinkedNode* head, int index)//Ѱ������
{
	while (--index>0)
	{
		if (head->next == nullptr) return nullptr;//����������Χ
		else head = head->next;//ѭ��index-1���ҵ���index����
	}
	return head;
}

bool insert(LinkedNode* node, LinkedNode** head, int index)
{
	if (*head == nullptr)//�Ƿ�ԭ��û��Ԫ��
	{
		node->prev = nullptr;
		node->next = nullptr;
		*head = node;//�����뼴Ϊ��һ��
		return true;
	}
	LinkedNode* n = find(*head, index);//Ѱ��ԭ���ĵ�n��Ԫ��
	if (n == nullptr)//������n��
	{
		n = find(*head, index - 1);
		if (n == nullptr)//������������
		{
			delete node;
			return false;
		}
		else//���뵽���
		{
			n->next = node;
			node->prev = n;
			node->next = nullptr;
			return true;
		}
	}
	if (n->prev == nullptr) *head = node;//���뵽��һ��
	else n->prev->next = node;
	node->prev = n->prev;
	node->next = n;
	n->prev = node;//��node����n֮ǰ
	return true;
}

bool remove(LinkedNode** head, int index)
{
	LinkedNode* node = find(*head, index);//��Ҫȥ������
	if (node == nullptr) return false;//������Χ
	else if (node->prev == nullptr && node->next == nullptr)
	{
		*head = nullptr;//ֻ��һ��Ԫ��
		return true;
	}
	else
	{
		if (node->prev == nullptr) *head = node->next;//ȥ���׸�Ԫ��
		else node->prev->next = node->next;
		if (node->next != nullptr) node->next->prev = node->prev;//ȥ��Ԫ��
		delete node;
		return true;
	}
}

void destory(LinkedNode* head)
{
	while (head != nullptr)//��Ԫ��һ��һ��ɾȥ
	{
		LinkedNode* tmp = head;
		head = head->next;
		delete tmp;
	}
}

void append(LinkedNode* node,LinkedNode* head)
{
	while(head->next!=nullptr)
		head=head->next;
	head->next=node;
	node->prev=head;
	node->next=nullptr;
}