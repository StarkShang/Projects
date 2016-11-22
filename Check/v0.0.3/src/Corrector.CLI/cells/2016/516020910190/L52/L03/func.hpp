#pragma once
struct LinkedNode
{
	int data;
	LinkedNode* prev;
	LinkedNode* next;
};//LinkedNode�ṹ�壬����LinkedNodeָ��prev,int������data,LinkedNodeָ��next

LinkedNode* create(int* array, int size)//����������
{
	LinkedNode *head, *iterator;
	head = iterator = new LinkedNode();//��ʼ��ָ��
	iterator->data = *array;//����ָ��ָ���㴢������data��ֵarray
	iterator->prev = nullptr;//����ָ��ָ��ǰһ������ָ��prev��ֵ��
	iterator->next = nullptr;//����ָ��ָ���һ������ָ��next��ֵ��
	for (int i = 1; i < size; i++)//����һ�������֮�������
	{
		iterator->next = new LinkedNode();
		iterator->next->data = array[i];//ָ���һ������ָ��ָ��Ľ�㴢������data��ֵΪarray[i]
		iterator->next->prev = iterator;//ָ���һ������ָ��ָ���ǰһ����㸳ֵΪ����ָ��
		iterator->next->next = nullptr;//����ָ��ָ���һ������ָ��ָ��ĺ�һ����㸳ֵΪ��
		iterator = iterator->next;//������ָ��ָ���һ������ָ��next
	}
	return head;//����ͷָ��
}

LinkedNode* find(LinkedNode* head, int index)//����i�����ĺ���
{
	while (--index>0)//����ҵ���index�����
	{
		if (head->next == nullptr) return nullptr;//���ͷָ��ָ��ĺ�һ�����Ϊ�գ��򷵻ؿ�
		else head = head->next;//����ͷָ�븳ֵΪ��һ������ָ��
	}
	return head;		//�������¶���һ�������Ϊ����ֵ��ֱ�Ӳ���headָ���ı�ԭ��������
}

bool insert(LinkedNode* node, LinkedNode** head, int index)//�ڵ�index�����ǰ�����㺯��
{
	if (*head == nullptr)
	{
		node->prev = nullptr;
		node->next = nullptr;
		*head = node;
		return true;//���ͷָ��Ϊ�գ�����ָ��ǰһ����ֵΪ�գ���һ����ֵΪ�գ�����ɹ�������true
	}							//ͷָ��Ϊ�գ�˵�����������û��index����㣬������Ϊ����Ϊ������������
	LinkedNode* n = find(*head, index);//Ѱ�ҵ�i�����
	if (n == nullptr)
	{
		n = find(*head, index - 1);
		if (n == nullptr)
		{
			delete node;//�����index-1�����Ϊ�գ�ɾ�����
			return false;//�����Ȳ���index�������������false
		}
		else					//���ǵ�index-1����㲻Ϊ���ҵ�index�����Ϊ�յ����
		{
			n->next = node;//�����index�����ָ�����һ����ֵΪҪ����Ľ��
			node->prev = n;//�ý��ָ���ǰһ����ֵΪ��i�����
			node->next = nullptr;//Ҫ������ָ�����һ����ֵΪ��
			return true;//����ɹ�������true
		}
	}
	if (n->prev == nullptr) *head = node;//�����i�����ָ���ǰһ��Ϊ�գ���Ҫ�����㸳ֵ��ͷָ��
	else n->prev->next = node;//���򣬵�i�����ָ���ǰһ��ָ��ĺ�һ����ֵΪҪ������
	node->prev = n->prev;//Ҫ������ָ���ǰһ����ֵΪ��i�����ָ���ǰһ��
	node->next = n;//Ҫ������ָ��ĺ�һ����ֵΪ��i�����
	n->prev = node;//��i�����ָ���ǰһ����ֵΪҪ������
	return true;//����ɹ�������true
}

bool remove(LinkedNode** head, int index)//ɾ����i����㺯��
{
	LinkedNode* node = find(*head, index);//�ҵ���i�����
	if (node == nullptr) return false;					//��index����㱾���Ͳ����ڣ��޷�ɾ��������false
	else if (node->prev == nullptr && node->next == nullptr)		//��index�������һ�������ġ����������ڵ������ӵĽ�㣿��������Ϊ���ǲ����ܵ����
	{																														//��Ϊfind�����ķ���ֵҪ���ǿգ�Ҫ�����������е�һ����㣬�Ҵ˽��Ӧ�����ǹ����ġ���ֻ��һ������������⣩
		*head = nullptr;																					//���������ȷʵֻ��һ����㣬ֱ�Ӱ�headָ���ÿ�Ҳ�ǲ������Ĵ���ʽ���Ͼ�index��һ����1
		return true;																							//������Ϊ����Ϊɾ������������
	}
	else
	{
		if (node->prev == nullptr) *head = node->next;//����ý��ǰһ��Ϊ�գ��򽫺�һ����ֵ��ͷָ��
		else node->prev->next = node->next;						//����ý��ǰһ���ĺ�һ����ִΪ�ý��ĺ�һ������ɾ����node���
		if (node->next != nullptr) node->next->prev = node->prev;//����ý���һ����Ϊ�ոý���һ����ǰһ����ֵΪ�ý���ǰһ��
		delete node;//ɾ���ý��
		return true;
	}
}

void destory(LinkedNode* head)//��������ṹ
{
	while (head != nullptr)
	{
		LinkedNode* tmp = head;
		head = head->next;//��ͷָ���һ����ֵ��ͷָ��
		delete tmp;//ͷָ�벻Ϊ��ʱ��ɾ��ͷָ��
	}
}
bool append(LinkedNode* node, LinkedNode* head)
{ bool flag=true;  
	LinkedNode *tmp=head;
	if(tmp==nullptr)//ͷָ��Ϊ�գ���node���Ϊ����ĵ�һ�����
	{
		head=node;
		return flag;
	}
	while (tmp->next != nullptr)
	{
		tmp=tmp->next;
	}//��tmpָ�����һ�����
	tmp->next=node;
	node->next=nullptr;
	node->prev=tmp;
	return flag;
}
	
	
	
