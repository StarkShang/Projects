#pragma once
struct LinkedNode//�����ṹ��LinkedNode
{
	int data;//��������Ԫ��data
	LinkedNode* prev;//����LinkedNode��ָ��prev
	LinkedNode* next;//����LinkedNode��ָ��next
};

LinkedNode* create(int* array, int size)
{
	LinkedNode *head, *iterator;//����ָ��head,iteratorΪLinkedNode��
	head = iterator = new LinkedNode();//��ͷһ��������һ���ռ�
	iterator->data = *array;//��ͷһ����㸳ֵ
	iterator->prev = nullptr;//ͷ����prevָ���
	iterator->next = nullptr;//ͷ����next��ʱָ���
	for (int i = 1; i < size; i++)//��ѭ�����������ÿһ����㸳ֵ���㽨����ϵ
	{
		iterator->next = new LinkedNode();//�ȸ���һ��������һ���ռ�
		iterator->next->data = array[i];//��������ÿһ����㸳ֵ
		iterator->next->prev = iterator;//��һ������prevָ�򱾽ڵ��ַ
		iterator->next->next = nullptr;//��һ�����next��ʱָ���
		iterator = iterator->next;//�����ĵ�ַָ����һ�ڵ�
	}//ѭ����ϣ�˫��������ɣ����һ������nextָ���
	return head;//���غ���
}//���ʣ�Ϊʲô��ֱ�ӷ���interator����Ȼhead��interator�õ���ͬһ�ռ䣬����head��Ӱ�췵��ֵ����ֱ�ӷ���interator���Ǹ�����𣬻����ö���head��

LinkedNode* find(LinkedNode* head, int index)
{
	while (--index>0)//��index����0ʱѭ������index��1
	{
		if (head->next == nullptr) return nullptr;//��ͷ���Ϊ�գ����ؿ�
		else head = head->next;//����ָ��������һ�����
	}//������index-1�κ��ҵ�����index�����
	return head;//���غ���ֵ
}

bool insert(LinkedNode* node, LinkedNode** head, int index)
{
	if (*head == nullptr)//��ͷ���Ϊ��Ϊ��
	{
		node->prev = nullptr;//���������prevΪ��
		node->next = nullptr;//���������nextҲΪ��
		*head = node;//����ڵ㼴Ϊͷ���
		return true;//���غ���ֵ
	}
	LinkedNode* n = find(*head, index);//�ҵ�Ҫ�������λ��
	if (n == nullptr)//��Ҫ����ĵط�Ϊ��
	{
		n = find(*head, index - 1);//��ǰ��һ�����
		if (n == nullptr)//����Ϊ��
		{
			delete node;//ɾ��Ҫ������
			return false;//���ش���
		}
		else//���Ѳ�Ϊ��
		{
			n->next = node;//n(Ҫ�����㣩��nextָ��node���������������һ��㣩
			node->prev = n;//node��prevָ��n
			node->next = nullptr;//node��nextָ���
			return true;//������ȷ
		}
	}
	if (n->prev == nullptr) *head = node;//��Ҫ������ǰһ��Ϊ�գ���Ҫ��ͷ���ǰ�����㣬ͷ���Ϊnode
	else n->prev->next = node;//��Ҫ����ĵط���Ϊ�գ�Ҫ������ǰһ��Ҳ��Ϊ��
	node->prev = n->prev;//node�����������ı������㣩��prevָ��n(Ҫ�����㣩��prev
	node->next = n;//node��nextָ��n
	n->prev = node;//n��prevָ��node
	return true;//������ȷ
}

bool remove(LinkedNode** head, int index)
{
	LinkedNode* node = find(*head, index);//�ҵ���ɾ������λ��
	if (node == nullptr) return false;//���ô�Ϊ�գ����ش���
	else if (node->prev == nullptr && node->next == nullptr)//����Ϊ����ǰһ���Ϊ�գ���һ���Ϊ�գ�������ֻ��һ�������Ϊͷ��㣩
	{
		*head = nullptr;//ɾ����ͷ��㣨ʹ��ͷ���Ϊ�գ�
		return true;//������ȷ
	}
	else//����λ�ò�Ϊ����ǰһ��㲻Ϊ�գ���һ���Ҳ��Ϊ��
	{
		if (node->prev == nullptr) *head = node->next;//��Ҫɾ���Ľ��ǰһ���Ϊ�գ�Ҫɾ����Ϊͷ��㣩��ͷ���ָ����һ��㣬��ʱͷ�����ʧ
		else node->prev->next = node->next;//����Ϊͷ��㣬�˽���ǰһ���next�����˽��ֱ��ָ����һ���
		if (node->next != nullptr) node->next->prev = node->prev;//���˽�����һ��㲻Ϊ�գ��˽�㲻Ϊ���һ����㣩���˽�����һ����prev�����˽��ֱ��ָ����һ��㣬�˽���������ʧ
		delete node;//ɾ���˽��
		return true;//������ȷ
	}
}

void destory(LinkedNode* head)
{
	while (head != nullptr)//��ͷ�ڵ㲻Ϊ��ʱѭ��
	{
		LinkedNode* tmp = head;//����ָ��tmpʹ��ָ��ͷ���,
		head = head->next;//ͷ����ָ��ָ����һ��㣬ͷ��㱻�������Ƴ���һ����Ϊͷ���
		delete tmp;//ɾ��ԭͷ����ַ
	}
}
//����Ϊ��ϰ
bool append(LinkedNode*node,LinkedNode*head)
{
	if(head==NULL)return false;//��ͷ���Ϊ�գ����ش���
	else//����
	{
		while(head->next!=NULL)//����ǰ�ڵ����һ��㲻Ϊ�գ�����ѭ��
		{
			head=head->next;//�����һ���
		}
		head->next=node;//��ǰ�ڵ��nextָ�򱻲�����
		node->prev=head;//���������prevָ��ǰ���
		node->next=NULL;//������ڵ��nextָ���
		return true;//������ȷ
	}
}
