#pragma once
struct LinkedNode //�����ṹ��
{
	int data;//���������
	LinkedNode* prev;//ָ��ǰ�ڵ��ָ��
	LinkedNode* next;//ָ���ڵ��ָ��
};

LinkedNode* create(int* array, int size)//�����������ݴ�������ĺ���
{
	LinkedNode *head, *iterator;//���������ṹ��ָ��
	head = iterator = new LinkedNode();
	iterator->data = *array;//���������ݸ��Ƹ��������DATA��Ա��
	iterator->prev = nullptr;//��ǰ��ָ�붼��ֵΪ�գ�����ʼ��
	iterator->next = nullptr;
	for (int i = 1; i < size; i++)
	{
		iterator->next = new LinkedNode();//������ָ�뿪һ���ڴ棬�����µĽṹ�����
		iterator->next->data = array[i];//������ָ������ݳ�Ա��ֵ������ĵ�I������
		iterator->next->prev = iterator;//��ͬʱ��ǰָ�븳ֵ�ϵ�����
		iterator->next->next = nullptr;//����ָ���е�����ָ�븳ֵΪ��ָ��
		iterator = iterator->next;//������ָ�븳ֵ���������У��Ա��´�ѭ������
	}
	return head;
}

LinkedNode* find(LinkedNode* head, int index)//�ҵ���I���ڵ�ĺ���
{
	while (--index>0)
	{
		if (head->next == nullptr) return nullptr;//��HEAD�е�����ָ��Ϊ��ʱ�����ؿ�ָ��
		else head = head->next;//�����HEAD��ֵΪHEAD������ָ��
	}
	return head;//����HEAD��ֵ
}

bool insert(LinkedNode* node, LinkedNode** head, int index)//�ڵ�I���ڵ������ĺ���������ɹ�����TRUE,���򷵻�FALSE
{
	if (*head == nullptr)//��HEADΪ��ʱ
	{
		node->prev = nullptr;//NODE��ǰ��ָ�붼��ֵ��
		node->next = nullptr;
		*head = node;//��HEAD��ֵΪNODE
		return true;//����ɹ�
	}
	LinkedNode* n = find(*head, index);//�ҵ���I���ڵ�
	if (n == nullptr)
	{
		n = find(*head, index - 1);//��N�ǿպ�������NΪ���Сһ���Ľڵ�
		if (n == nullptr)
		{
			delete node;//��N��Ȼ�ǿյģ��򷵻�ʧ�ܣ�����ڴ�
			return false;
		}
		else
		{
			n->next = node;//���򣬰�NODE��ֵ��N������ָ��
			node->prev = n;//��NODE����ǰָ�븳ֵΪN
			node->next = nullptr;//NODE������ָ��Ϊ��
			return true;
		}
	}
	if (n->prev == nullptr) *head = node;//���N����ǰָ��Ϊ�գ����NEAD��ֵΪNODE
	else n->prev->next = node;//���򣬽���һϵ���滻����NODE��������
	node->prev = n->prev;
	node->next = n;
	n->prev = node;
	return true;
}

bool remove(LinkedNode** head, int index)//ɾ����I���ڵ�ĺ������ɹ�����TRUE,ʧ�ܷ���FALSE
{
	LinkedNode* node = find(*head, index);//�ҵ���I���ڵ�
	if (node == nullptr) return false;//����I���ڵ�Ϊ�գ�����ʧ��
	else if (node->prev == nullptr && node->next == nullptr)//��������i���ڵ��ǰ��ָ�붼Ϊ��
	{
		*head = nullptr;//��HEADΪ��
		return true;
	}
	else
	{
		if (node->prev == nullptr) *head = node->next;//�������ڵ����ǰָ��ʽ�յģ���ô��HEADΪNODE �����ڵ�
		else node->prev->next = node->next;//����λ�գ����NODE��ǰָ��ĺ�ָ�븳ֵΪNODE�ĺ�ָ��
		if (node->next != nullptr) node->next->prev = node->prev;//���NODE�ĺ�ָ�벻�գ���NODE�ĺ�ָ���ǰָ�븳ֵΪNODEǰָ��
		delete node;//�ͷ��ڴ棬���سɹ�
		return true;
	}
}

void destory(LinkedNode* head)//�������������б�
{
	while (head != nullptr)//���б���ʱ�������ͷ��ڴ�
	{
		LinkedNode* tmp = head;
		head = head->next;
		delete tmp;
	}
}