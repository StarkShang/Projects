#pragma once
struct LinkedNode//��������ڵ�Ľṹ��
{
	int data;
	LinkedNode* prev;
	LinkedNode* next;
};

LinkedNode* create(int* array, int size)//��������ָ��������С��ִ�к���������Ӧ���������һ���ڵ��ָ��
{
	LinkedNode *head, *iterator;//�����һ���ڵ��ָ���һ��ָ�������
	head = iterator = new LinkedNode();//����һ���ڵ㣬��ָ��ֵ��head�͵�����
	iterator->data = *array;
	iterator->prev = nullptr;
	iterator->next = nullptr;//����һ���ڵ㸳ֵ
	for (int i = 1; i < size; i++)//���õ��������ӵڶ����ڵ㿪ʼѭ����ֵ
	{
		iterator->next = new LinkedNode();//�½��ڵ㣬�½ڵ��ָ�븳����һ����next
		iterator->next->data = array[i];//����ֵ�����½ڵ��data
		iterator->next->prev = iterator;//��һ���ڵ��ָ�븳���½ڵ��prev
		iterator->next->next = nullptr;//�½ڵ��nextΪ��
		iterator = iterator->next;//����
	}
	return head;//���ص�һ���ڵ��ָ��
}

LinkedNode* find(LinkedNode* head, int index)//���������һ���ڵ��ָ�����Ҫ���ҵڼ�������������ڵ��ָ��
{
	while (--index>0)//�ҵ�n���ڵ㽫����n-1��
	{
		if (head->next == nullptr) return nullptr;//���index���������ȣ����ؿ�ָ��
		else head = head->next;//����ָ���Ƶ���һ���ڵ�
	}
	return head;//��������ָ��
}

bool insert(LinkedNode* node, LinkedNode** head, int index)//����ڵ㣬������ʼλ�ã�����λ�ã������Ƿ��ܹ�������жϣ��ܹ���ִ�в���ڵ�
{
	if (*head == nullptr)//��������޽ڵ㣬���������ڵ㣬��ֵ������true,����������
	{
		node->prev = nullptr;
		node->next = nullptr;
		*head = node;
		return true;
	}
	LinkedNode* n = find(*head, index);//�ҵ���index���ڵ��ָ�룬��ֵ��n
	if (n == nullptr)//��������ڵ�index���ڵ�
	{
		n = find(*head, index - 1);//��ǰһ���ڵ�
		if (n == nullptr)//���Ҳ�����ڣ��������������ȣ����ܲ��룬������ݣ�����false����������
		{
			delete node;
			return false;
		}
		else//������ڣ����������һ���ڵ�
		{
			n->next = node;
			node->prev = n;
			node->next = nullptr;//�����һ���ڵ�֮�����node�ڵ㣬�޸Ķ�Ӧ������
			return true;//����ɹ�������true����������
		}
	}
	if (n->prev == nullptr) *head = node;//�����index���ڵ��ǵ�һ���ڵ㣬���node��Ϊ����ָ��(��Ϊ��һ���ڵ�)
	else n->prev->next = node;//������ǵ�һ���ڵ㣬�޸�ǰһ���ڵ��nextֵ������node
	node->prev = n->prev;
	node->next = n;
	n->prev = node;//�޸ĵ�index���ڵ���node�ڵ��prev��next������ǰ���Ӧ��ϵ��������ڵ�һ���ڵ�ǰ������node��prev�ĳɿգ�
	return true;//����ɹ�������true
}

bool remove(LinkedNode** head, int index)//��������ָ����Ҫɾ�ڼ����ڵ㣬�����ܷ�ɾ�����ܹ���ִ��ɾ��
{
	LinkedNode* node = find(*head, index);//�ҵ���index���ڵ�
	if (node == nullptr) return false;//�����index���ڵ㲻���ڣ�����ɾ��������false
	else if (node->prev == nullptr && node->next == nullptr)//������ڣ��鿴prev��next�Ƿ�Ϊ�գ��Դ��ж��Ƿ�ýڵ��ǽ��е�һ���ڵ�
	{
		*head = nullptr;
		return true;//����ǾͰ�����ָ���Ϊ��ָ�룬ʵ��ɾ��������true
	}
	else//�������ֹһ���ڵ�
	{
		if (node->prev == nullptr) *head = node->next;//����ǵ�һ���ڵ㣬������ڵ��Ƶ��ڶ����ڵ㣬ʵ��ɾ��
		else node->prev->next = node->next;//������ǵ�һ���ڵ㣬��ǰһ���ڵ��next��Ϊ��һ���ڵ�
		if (node->next != nullptr) node->next->prev = node->prev;//�����ǰ�ڵ㲻�����һ���ڵ㣬�����һ���ڵ��prev�ĳ���һ���ڵ㣬ʵ��ɾ��(���ɾ���˵�һ�������ѵڶ�����prev�ĳɿ�)
		delete node;//���node�Ŀռ�
		return true;//ɾ���ɹ�������true
	}
}

void destory(LinkedNode* head)//��������ָ�룬����������ݵĿռ�
{
	while (head != nullptr)//ֻҪ��ǰ�ڵ���ھͽ�����
	{
		LinkedNode* tmp = head;//�ݴ浱ǰ�ڵ�
		head = head->next;//ָ���Ƶ��¸��ڵ�
		delete tmp;//ɾ���ݴ�Ľڵ�
	}
}