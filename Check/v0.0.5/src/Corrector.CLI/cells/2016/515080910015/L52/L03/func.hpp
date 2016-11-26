#pragma once
struct LinkedNode //�����ṹ��
{
	int data; //�����������
	LinkedNode* prev;//�ṹ��ָ��prev
	LinkedNode* next;//�ṹ��ָ��next
};

LinkedNode* create(int* array, int size) //��������
{
	LinkedNode *head, *iterator;  //���������ṹ��ָ��
	head = iterator = new LinkedNode();//���ٴ�Žṹ��Ŀռ�
	iterator->data = *array;  //�����ݷ�����
	iterator->prev = nullptr;
	iterator->next = nullptr;
	for (int i = 1; i < size; i++)
	{
		iterator->next = new LinkedNode();//���ٴ�Žṹ��Ŀռ�
		iterator->next->data = array[i];//�����ݷ�����
		iterator->next->prev = iterator;
		iterator->next->next = nullptr;
		iterator = iterator->next; //��ǰ���������ϵ
	}
	return head;
}

LinkedNode* find(LinkedNode* head, int index)//�ҵ���i�����
{
	while (--index>0)
	{
		if (head->next == nullptr) return nullptr;//���������ȷ��ؿ�
		else head = head->next; //���в���
	}
	return head; //���ز��ҽ��
}

bool insert(LinkedNode* node, LinkedNode** head, int index)//�ڵ�i�����ǰ���һ�����
{
	if (*head == nullptr)
	{
		node->prev = nullptr;
		node->next = nullptr;
		*head = node;  //������Ϊ��ʱ��ֱ�Ӳ����һ�����
		return true;
	}
	LinkedNode* n = find(*head, index);//������Ҫ�����λ�ý��
	if (n == nullptr)
	{
		n = find(*head, index - 1);
		if (n == nullptr)
		{
			delete node;
			return false;//������λ�ö������������ʱ������ʧ��
		}
		else
		{
			n->next = node;
			node->prev = n;
			node->next = nullptr;//��ĩλ������һ���ڵ�
			return true;
		}
	}
	if (n->prev == nullptr) *head = node;//���ڵ������λ��
	else n->prev->next = node; 
	node->prev = n->prev;
	node->next = n;
	n->prev = node;//���м�λ�ò�����
	return true;
}

bool remove(LinkedNode** head, int index)//ɾ����i�����
{
	LinkedNode* node = find(*head, index);//������Ҫɾ����λ�ý��
	if (node == nullptr) return false;
	else if (node->prev == nullptr && node->next == nullptr)
	{
		*head = nullptr;//������ֻ��һ���ڵ�ʱ�����˽ڵ�ɾ��
		return true;
	}
	else
	{
		if (node->prev == nullptr) *head = node->next;//������Ҫɾ���Ľ���ڿ�ͷʱ������һ���������
		else node->prev->next = node->next;//���ڵ�һ��λ��ʱ�������ҵĽ������
		if (node->next != nullptr) node->next->prev = node->prev;//��Ҫɾ���Ľ�㲻Ϊ��ʱ����������
		delete node;
		return true;
	}
}

void destory(LinkedNode* head) //��������
{
	while (head != nullptr) //��������ʱ����whileѭ������
	{
		LinkedNode* tmp = head;//���ڵ㸴�Ƹ�tnm
		head = head->next;//����һ���������
		delete tmp;//����tnm
	}
}

bool append(LinkedNode*node,LinkedNode* head) //��������������һ�����
{
	if(head==nullptr)
	{
		node->prev = nullptr;
		node->next = nullptr;
		head = node;  //������Ϊ��ʱ��ֱ�����Ϊ��һ�����
		return true;
	}
	else
	{
		while(head!=nullptr)
		{
			head = head->next;//������Ϊ��ʱ���������һ���ڵ�
		}
		node->prev=head;
		node->next = nullptr;//����������һ���ڵ�
		return true;
	}
}
