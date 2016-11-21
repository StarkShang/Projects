#pragma once
struct LinkedNode//
{//
	int data;//
	LinkedNode* prev;//
	LinkedNode* next;//
};//

LinkedNode* create(int* array, int size)
{
	LinkedNode *head, *iterator;//��������м�ṹ��
	head = iterator = new LinkedNode();//create�ṹ��
	iterator->data = *array;//�����һ���ṹ�������Ԫ��
	iterator->prev = nullptr;//
	iterator->next = nullptr;//
	for (int i = 1; i < size; i++)//ѭ��size-1�δ���size-1�����
	{//
		iterator->next = new LinkedNode();//��ÿһ������next����һ���ṹ��
		iterator->next->data = array[i];//��д����
		iterator->next->prev = iterator;//�½ṹ���prevָ��������
		iterator->next->next = nullptr;//�½ṹ���next�ݶ�Ϊ��
		iterator = iterator->next;//����iteratorΪ�½ṹ��ָ������ѭ��
	}//
	return head;//���ص�һ������ָ��
}//

LinkedNode* find(LinkedNode* head, int index)
{//
	while (--index>0)//ѭ��index-1���ҵ��ý��
	{
		if (head->next == nullptr) return nullptr;//�����ѭ���г����������ȣ�����nullptr
		else head = head->next;//headָ�������һ������ѭ��
	}//
	return head;//����head
}

bool insert(LinkedNode* node, LinkedNode** head, int index)
{
	if (*head == nullptr)//��������ǿյ�
	{//
		node->prev = nullptr;//����nodeΪ�����һ�����
		node->next = nullptr;//
		*head = node;//
		return true;//����true
	}//
	LinkedNode* n = find(*head, index);//ʹָ��nָ���index�����
	if (n == nullptr)//���������������
	{//
		n = find(*head, index - 1);//��nָ���index-1�����
		if (n == nullptr)//����������ڣ�������������
		{//
			delete node;//ɾ��node
			return false;//����false
		}//
		else//
		{//���򼴲����Ϊ���һ�����
			n->next = node;//��node��ԭ���һ��㽨����ϵ��ʹ֮��Ϊ���һ���
			node->prev = n;//
			node->next = nullptr;//
			return true;//����true
		}//
	}//
	if (n->prev == nullptr) *head = node;//���Ҫ�ڵ�һ�����֮ǰ���룬��*headָ��node
	else n->prev->next = node;//���������һ��ǰһ���nextָ��node
	node->prev = n->prev;//node��prevָ����һ���ǰһ��
	node->next = n;//node��nextָ����һ��
	n->prev = node;//��һ���prevָ��node
	return true;//����true
}

bool remove(LinkedNode** head, int index)
{//
	LinkedNode* node = find(*head, index);//����nodeָ���index�����
	if (node == nullptr) return false;//���node�޷�ָ�򼴳���������false
	else if (node->prev == nullptr && node->next == nullptr)//������һ��Ϊ����Ψһ�Ľ��ʱ
	{//
		*head = nullptr;//ɾ����һ�����
		return true;//����true
	}//
	else//����
	{//
		if (node->prev == nullptr) *head = node->next;//��ɾ��һ����㣬��*headָ����һ�����
		else node->prev->next = node->next;//������ǰһ������nextָ������һ�����
		if (node->next != nullptr) node->next->prev = node->prev;//��δɾ���һ����㣬������һ������prevָ������һ�����
		delete node;//ɾ��nodeָ��Ľ��
		return true;//����true
	}//
}

void destory(LinkedNode* head)
{//
	while (head != nullptr)//ֻҪ�����һ��������
	{
		LinkedNode* tmp = head;//��tmp����ָ���һ�����
		head = head->next;//ʹheadָ����һ�����
		delete tmp;//�ѵ�һ�����ɾ��
	}//
}//
	else
	{
		if(node->prev == nullptr)*head = node->next;
		else node->prev->next=node->next;
		if (node->next !=nullptr)node->next->prev=node->prev;
		delete node;
		return true;
	}
}

void destory(LinkedNode* head)
{

}