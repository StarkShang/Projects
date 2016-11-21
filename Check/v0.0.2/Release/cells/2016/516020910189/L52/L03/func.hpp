#pragma once
struct LinkedNode //�����ṹ��
{
	LinkedNode *prev;
	int data;
	LinkedNode *next;
};

LinkedNode* create(int* array, int size)  //�������鴴������
{
	LinkedNode* Head = new LinkedNode;  //������һ���ڵ�
	Head->prev = NULL;
	Head->next = NULL;
	Head->data = *array;
	LinkedNode* prev = Head;  //��prevָ���һ���ڵ�
	for (int i = 1; i < size; i++)
	{
		LinkedNode *node = new LinkedNode; //�����ڵ�
		node->data=*(array+i);  //�������鸳ֵ
		node->prev = prev; //ָ��ǰһ����ָ��
		prev->next = node; //��ǰһ�ڵ�ָ��ýڵ��ָ��
		node->next = NULL; //ָ����һ���ڵ��ָ��ָ���
		prev = node; //��prevָ��ýڵ㣬������һ���ڵ�Ĵ���
	}
	return Head; //���ص�һ���ڵ�ĵ�ַ
}

LinkedNode* find(LinkedNode* head, int index) //�ҵ���i���ڵ�
{
	int i = 1;
	LinkedNode *Node = head;
	for (; Node->next != NULL;)  //�����ж��ٸ��ڵ�
	{
		i = i + 1;
		Node = Node->next;
	}
	if (index > i) return NULL;  //���i���ڽڵ���������NULL
	else 
	{
		i = 1;
		LinkedNode *node = head;
		for (; i < index; i++) //�ҵ���i���ڵ�
		{
			node = node->next; //nodeָ��noded����һ���ڵ�
		}
		return node; //����node
	}
}

bool insert(LinkedNode* node, LinkedNode** head, int index) //�ڵ� i����㴦ǰ������ĺ��� ������ɹ��򷵻�true,ʧ���򷵻�FALSE
{
	int i = 1;
	LinkedNode *Node = *head;
	LinkedNode *Prev;
	for (; Node->next != NULL;) //�����ж��ٸ��ڵ�
	{
		i = i + 1;
		Node = Node->next;
	}
	if (index > i) return false; //�������ʧ���򷵻�false
	else //�ڵ�i���ڵ�ǰ����
	{
		Node = find(*head, index); //�ҵ���i���ڵ�
		Prev = find(*head, index-1); //�ҵ���i-1���ڵ�
		Prev->next = node;//����i-1���ڵ��ָ��ָ��ָ��node
		node->prev = Node->prev; //��node��ָǰָ��ָ���i-1���ڵ�
		node->next = Node; //��node��ָ��ָ��ָ���i���ڵ�
		Node->prev = node; //����i���ڵ��ָǰָ��ָ��node
		return true; //����true
	}
}

bool remove(LinkedNode** head, int index) //ɾ����i���ڵ�
{
	int i = 1;
	LinkedNode *Node = *head;
	LinkedNode *Prev;
	LinkedNode *Next;
	for (; Node->next != NULL;) //����ڵ����
	{
		i = i + 1;
		Node = Node->next;
	}
	if (index > i) return false; //����������false
	else 
	{
		Node = find(*head, index); //�ҵ���i���ڵ�
		Prev = Node->prev; //��¼�µ�i-1���ڵ�ĵ�ַ
		Next = Node->next;//��¼�µ�i+1���ڵ�ĵ�ַ
		Prev->next = Next;//����i-1���ڵ����i+1���ڵ�����
		Next->prev = Prev;
		delete Node; //ɾ����i���ڵ�
		return true;//����true
	}
}

void destory(LinkedNode* head) //������������
{
	LinkedNode*Next = head;//����Next���Դ���
	for (; Next->next != NULL;)
	{
		LinkedNode *Node = Next;
		Next = Node->next; //�ҵ���һ���ڵ�
		delete Node; //ɾ����ǰ�ڵ�
	}
}

bool append(LinkedNode* node, LinkedNode* head) //�������������һ���ڵ�
{
	LinkedNode *Node = head; 
	for (; Node->next != NULL;) //�ҵ����һ���ڵ�
	{
		Node - Node->next;
	}
	Node->next = node;//�����һ���ڵ��ָ��ָ��ָ����ӵĽڵ�
	node->prev = Node;//����ӽڵ��ָǰָ��ָ�����һ���ڵ�
	node->next = NULL;//����ӽڵ��Ϊ���һ���ڵ�
	return true;//����true�Ա�ʾ��ӳɹ�
}