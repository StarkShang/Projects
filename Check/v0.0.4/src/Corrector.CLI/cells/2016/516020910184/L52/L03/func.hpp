#pragma once
struct LinkedNode//�����ṹ�壬���� LinkedNodeָ��prev��int��data LinkedNodeָ��next
{
	 LinkedNode *prev;
	 int data;
	 LinkedNode *next;
};

LinkedNode* create(int* array, int size)
{
	 LinkedNode *head,*iterator;//����LinkedNode�ͽṹ��head,iterator��
	 head = iterator = new LinkedNode();//Ϊhead,iterator���䶯̬�ڴ�
	 iterator->data=*array;//��������Ԫ�ص�ֵ�ָ�iterator��data
	 iterator->prev=nullptr;//iteratorָ��ǰһ����ָ��Ϊ��
	 iterator->next=nullptr;//iteratorָ���һ����ָ��Ϊ��
	 for(int i=1;i<size;i++)//ѭ����������ֵ
	 {
		 iterator->next=new LinkedNode();//��iterator���䶯̬�ڴ�
		 iterator->next->data=array[i];//�������i��Ԫ�ص�ֵ�ָ�iterator��next ��data
		 iterator->next->prev=iterator;//iterator��next ��preָ��iterator����
		 iterator->next->next=nullptr;//iterator��next ��nextָ���
		 iterator= iterator->next;//iteratorָ������next

	 }
	 return head;//����LinkedNode�ͽṹ��head
}

LinkedNode* find(LinkedNode* head, int index)
{
	 LinkedNode *iterator;//����LinkedNode�ͽṹ��iterator
	 iterator = head;//iteratorָ��head
	 int i;//�������
	for( i=0;i<index;i++)//ѭ������ҵ���i���ڵ�
	 {
		 if(iterator->next != nullptr)//���������Ҫ�ҵ��ĵ�i���ڵ�
		 iterator =iterator->next;//ִ��iteratorָ������next
		 else break;//��������ѭ�����
	 }
	if(i==(index-1))return iterator;//���������Ҫ�ҵ��ĵ�i���ڵ㣬����iterator
	else return nullptr;//���򷵻ؿ�
}

bool insert(LinkedNode* node, LinkedNode** head, int index)
{
	
	if (*head == nullptr)//������Ϊ�յ�ʱ�򣬴���һ�����node������true

	{
		node->prev = nullptr;
		node->next = nullptr;
		*head = node;
		return true;
	}
	else if( find( *head,  index)!=nullptr ||find( *head,  index-1)!=nullptr)//���������Ҫ�ҵ��ĵ�i���ڵ㣬ִ�в�����䲢������
		{
		 
		 node->next=find( *head,  index);//node��nextָ���i���ڵ�
		 node->prev=find( *head,  (index-1));//node��preָ���i-���ڵ�
		 return true;//������
		}
	else //�����������Ҫ�ҵ��ĵ�i���ڵ㣬���ؼ�
		return false;
	
}

bool remove(LinkedNode** head, int index)
{
	LinkedNode* n = find(*head, index);
	if (*head == nullptr)//������Ϊ�յ�ʱ�򣬷���false

	{
		return false;
	}
	else if( n!=nullptr )//���������Ҫ�ҵ��ĵ�i���ڵ㣬ִ��ɾ����䲢������
	{
		n=nullptr;
		find(*head, index-1)->next=find(*head, index+1);
		find(*head, index+1)->prev=find(*head, index-1);
		return true;
	}
	else//�����������Ҫ�ҵ��ĵ�i���ڵ㣬���ؼ�
		return false;

}

void destory(LinkedNode* head)
{
	while (head != nullptr)
	{
		LinkedNode* tmp = head;
		head = head->next;
		delete tmp;
	}
}