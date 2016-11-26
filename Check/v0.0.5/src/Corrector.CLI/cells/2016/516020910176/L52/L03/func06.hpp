#pragma once
struct LinkedNode                           //����һ���ṹ��������������
{
	int data;                              
	LinkedNode* prev;                       
	LinkedNode* next;                       //����ָ��ǰ��ṹ���ָ��
};

LinkedNode* create(int* array, int size)    //��������
{
	LinkedNode *head, *iterator;            //������һ���ṹ��͵ڶ����ṹ��
	head = iterator = new LinkedNode();     
	iterator->data = *array;                //��array��ĵ�һ�����ݴ��浽��һ���ṹ����
	iterator->prev = nullptr;               //��һ���ṹ���ǰָ����ָ���
	iterator->next = nullptr;               //��һ���ṹ��ĺ�ָ��ָ���
	for (int i = 1; i < size; i++)
	{
		iterator->next = new LinkedNode();  //������һ���ṹ�� 
		iterator->next->data = array[i];    //��ֵ
		iterator->next->prev = iterator;    //����µĽṹ���prevָ��ָ�����е����һ���ṹ��
		iterator->next->next = nullptr;     //��ʹ������ṹ��ĺ�ָ��ָ���
		iterator = iterator->next;          //���µĽṹ�廻һ�����֣���Ϊ���еĽṹ��
	}
	return head;                            //�ѵ�һ���ṹ���ָ�뷵��
}

LinkedNode* find(LinkedNode* head, int index)//Ѱ�Һ���
{
	while (--index>0)                               //��index>0ʱ��ʼѭ����ѭ��index�Σ�  
	{
		if (head->next == nullptr) return nullptr; //���ͷ�ṹ���nextָ��Ϊ�գ���ֻ��һ���ṹ�壩���ؿ�
		else head = head->next;                    //�ж���ṹ����ôָ����һ���ṹ��
	}
	return head;                                   //�������Ǹ��ṹ�巵��
}

bool insert(LinkedNode* node, LinkedNode** head, int index)  //���뺯��
{
	if (*head == nullptr)                                    //���Ϊ��
	{                                                        
		node->prev = nullptr;                                //prevָ��Ϊ��       
		node->next = nullptr;                                //nextָ��Ϊ��
		*head = node;                                        //headָ��node
		return true;                                         //��һ��true
	}
	LinkedNode* n = find(*head, index);                      //����һ��ָ��nָ��Ҫ����Ľṹ��֮ǰ
	if (n == nullptr)                                        //���nΪ��
	{
		n = find(*head, index - 1);                          //n����ΪҪѰ�ҵĽṹ��ǰ��һ��     
		if (n == nullptr)                                    //���n���ǿ� 
		{
			delete node;                                     //ɾȥnode
			return false;                                    //��һ��false
		}
		else                                                 
		{
			n->next = node;                                  //n��nextָ��node
			node->prev = n;                                 //node��prevָ��n
			node->next = nullptr;                            //node��nextָ���
			return true;                                    //��һ��true
		}
	}
	if (n->prev == nullptr) *head = node;                   //���n��prevָ��ָ��� ��ô�µ�node���ǵ�һ���ṹ��
	else n->prev->next = node;                              //������ǵĻ���ôn��ǰһ��
	node->prev = n->prev;                                   //��nԭ�ȵ�prev�����¼����node��prev
	node->next = n;                                         //node��nextָ��n
	n->prev = node;                                         //n��prevָ��node
	return true;                                            //��һ��true
}

bool remove(LinkedNode** head, int index)                        //remove����
{
	LinkedNode* node = find(*head, index);                       //����һ��nodeָ����Ҫ��ɾȥ�ĺ���
	if (node == nullptr) return false;                           //���nodeָ��� ����һ��false
	else if (node->prev == nullptr && node->next == nullptr)     //�������һ���ṹ��
	{
		*head = nullptr;                                         //����Ϊ��
		return true;                                             //����һ��true
	}
	else                                                            //
	{
		if (node->prev == nullptr) *head = node->next;              //���ָ���һ���ṹ�� ֱ����ͷָ��ڶ����ṹ��
		else node->prev->next = node->next;                         //������ǵ�һ���ṹ�� ������ṹ���ǰһ����nextָ������ṹ�����һ���ṹ��
		if (node->next != nullptr) node->next->prev = node->prev;   //���node��Ϊ���һ�� node����һ���Ľṹ���prevָ��node��ǰһ���ṹ��
		delete node;                                                //ɾȥnode
		return true;                                                //�ظ�һ��true
	}
}

void destory(LinkedNode* head)                                      //���ٺ���
{
	while (head != nullptr)                                         //���ͷ������Ϊ��
	{
		LinkedNode* tmp = head;                                    //����ָ��ָ��head
		head = head->next;                                         //�õڶ������ǵ�һ��
		delete tmp;                                                //��ԭ���ĵ�һ��ɾȥ
	}
}