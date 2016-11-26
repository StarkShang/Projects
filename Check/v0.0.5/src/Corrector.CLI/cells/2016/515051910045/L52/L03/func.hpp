#pragma once
struct LinkedNode    //����һ���ṹ������ʾ�ڵ�
{
	int data;
	LinkedNode* prev;
	LinkedNode* next;
};

LinkedNode* create(int* array, int size)   //����create����������һ������
{
	LinkedNode *head, *iterator;
	head = iterator = new LinkedNode();       //�����׵�ַ����ֵ
	iterator->data = *array;                 //�׵�ַ����Ӧ�����ݸ�ֵ
	iterator->prev = nullptr;                //�׵�ַ��ǰһ������ַΪ��
	iterator->next = nullptr;                //�׵�ַ����һ������ַΪ��
	for (int i = 1; i < size; i++)
	{
		iterator->next = new LinkedNode();   //������һ�����ĵ�ַ
		iterator->next->data = array[i];    //����һ���������Ӧ���ݸ�ֵ
		iterator->next->prev = iterator;     //����һ����ڵ�ĵ�ַ��˽���ַ��Ӧ��ϵ
		iterator->next->next = nullptr;     //��������һ�����ĵ�ַΪ��
		iterator = iterator->next;         //����һ�����ĵ�ַ��ֵ
	}
	return head;
}

LinkedNode* find(LinkedNode* head, int index)     //���庯��find��Ѱ�ҵ�index�����
{
	while (--index>0)       
	{ 
		if (head->next == nullptr) return nullptr;    //���������Χ���򷵻ؿ�
		else head = head->next;      //ͨ�������ı任�����������Ӧ�ĵ�ַ�����õ�ַ�����׵�ַ
	}
	return head;
}
 
bool insert(LinkedNode* node, LinkedNode** head, int index)       //����insert����������һ���µĽ��
{ 
	if (*head == nullptr)
	{
		node->prev = nullptr;
		node->next = nullptr;
		*head = node;
		return true;
	}
	LinkedNode* n = find(*head, index);
	if (n == nullptr)        //�ж��Ƿ񳬳���Χ
	{
		n = find(*head, index - 1);//�ж��ܷ�����������һλ
		if (n == nullptr)   //������ӵ����һλ�򷵻�false
		{
			delete node;
			return false;
		}
		else                //����ӵ����һλ�򷵻�true
		{
			n->next = node;        
			node->prev = n;      
			node->next = nullptr;  
			return true;
		}
	}
	if (n->prev == nullptr) *head = node;      //�ж��Ƿ���ӵ���������λ
	else n->prev->next = node;      //��ӵĽ��Ȳ�����λҲ����ĩλ
	node->prev = n->prev;
	node->next = n;
	n->prev = node;
	return true;
}

bool remove(LinkedNode** head, int index)     //����remove�������Ƴ�һ�����
{
	LinkedNode* node = find(*head, index);
	if (node == nullptr) return false;       //�жϽ���Ƿ����
	else if (node->prev == nullptr && node->next == nullptr)     //�ж��Ƿ����һ�����
	{
		*head = nullptr;
		return true;
	}
	else
	{
		if (node->prev == nullptr) *head = node->next;    //�ж��Ƿ�Ϊ�׽��
		else node->prev->next = node->next;
		if (node->next != nullptr) node->next->prev = node->prev;
		delete node;
		return true;
	}
}

void destory(LinkedNode* head)   //����destory������������������
{
	while (head != nullptr)        //�ж��׵�ַ�Ƿ�Ϊ��
	{
		LinkedNode* tmp = head;     
		head = head->next;
		delete tmp;
	}
}