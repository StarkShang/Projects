#pragma once
struct LinkedNode
{
	LinkedNode *prev;
	int data;
	LinkedNode *next;//�����ṹ��
};

LinkedNode* create(int* array, int size)
{
	LinkedNode*head,*iterator;//����ָ��
	head =iterator=new LinkedNode();//�µĽṹ�ռ�
	iterator->data=*array;//Ϊ��һ��������ֵ
	iterator->prev=nullptr;//��ʼ��prev
	iterator->next=nullptr;//��ʼ��next
	for(int i=1;i<size;i++)
	{
		iterator->next=new LinkedNode();//�����µĴ���ռ�
		iterator->next->data=array[i];//Ϊ�µĽṹ�����ݸ�ֵ
		iterator->next->prev=iterator;//���µĽṹ��prevָ�븳Ϊiterato�ĵ�ַ
		iterator->next->next=nullptr;//��ʼ���µĽṹ���next
		iterator=iterator->next;//����iterator
	}
	return head;//���س�ʼ��ַ
}

LinkedNode* find(LinkedNode* head, int index)//��������
{
	LinkedNode*temp=head;//��tempָ���ʼ��
	if(index==1) return temp;//���Ѱ�ҵ��ǵ�һ�������򷵻س�ʼֵ
	for(int i=0;i<index-1;i++)
	{
		temp=(*temp).next;//���ϸ���tempָ���Ӧ��ֱַ����ӦҪѰ�������ĵ�ַ
	}
	return temp;//������Ӧָ��


}

bool insert(LinkedNode* node, LinkedNode** head, int index)
{
	if(*head==nullptr)//�ж��������Ƿ��Ѿ�����������
	{
		node->prev=nullptr;//��node��Ӧ�ṹ��prevָ���ʼ��
		node->next=nullptr;//��node��Ӧ�ṹ��nextָ���ʼ��
		*head=node;//�������ʼ��ַ��Ϊnode��Ӧ��ַ
		return true;//ִ�гɹ�
	}
	LinkedNode*n=find(*head,index);//nָ���Ӧ��ҪǶ��λ��
	if(n==nullptr)//�����λ�ò�����
	{
		n=find(*head,index-1);//��nָ���ӦǶ��λ�õ�ǰһ��λ��

	if(n==nullptr)//���ǰһ��λ��Ҳ������
	{
		delete node;//ɾ��nodeָ��
		return false;//ִ��ʧ��
	}
	else//���ǰһ��λ�ô���
	{
		n->next=node;//��nָ���Ӧ������nextָ��ָ��node��Ӧλ��
		node->prev=n;//nodeָ���Ӧ������prevָ��ָ��n��Ӧλ��
		node->next=nullptr;//��node��Ӧ������nextָ�븳��ֵ
		return true;//ִ�гɹ�
	}}
if(n->prev==nullptr) *head=node;//���Ƕ��λ���ǵ�һ����������nodeλ�ø���head
else n->prev->next=node;//����nǰһ��������Ӧ��nextָ���Ӧ��node��λ��
node->prev=n->prev;//��n��Ӧ��prevָ�븳��node��prevָ��
node->next=n;//��n��λ�ø���node��nextָ��
n->prev=node;//��node��λ�ø�ֵ��n��Ӧ��prev
return true;//ִ�гɹ�
}

bool remove(LinkedNode** head, int index)
{

	LinkedNode*node=find(*head,index);//�ҵ���Ҫɾ��������λ��
	if(node==nullptr)return false;//���������������ִ��ʧ��
	else if(node->prev==nullptr&&node->next==nullptr)//�������������ǰ�������������
	{
		*head=nullptr;//��������
		return true;//ִ�гɹ�
	}
	else
	{
		if (node->prev==nullptr)
			*head=node->next;//���Ҫɾ���������ǵ�һ�����������ڶ�������λ�ø���headָ��
		else node->prev->next=node->next;//����Ҫɾ��������ǰһ��������Ӧ��nextָ�븳ΪҪɾ��������nextָ��
		if(node->next!=nullptr)node->next->prev=node->prev;//ɾ��λ�ú������������һ������nextָ�븳Ϊɾ��������nextָ��
		delete node;//ɾ����Ӧ����
		return true;//ִ�гɹ�
}
}
void destory(LinkedNode* head)
{
struct LinkedNode *p;//����ָ��p
while(head!=NULL)//����һ�����ʱ
{
	p=head;//���׵�ַ����p
	head=head->next;//����һ��������ַ����head
	p->next=NULL;
	free(p);//�ͷ�p
	p=NULL;//��ʼ��p
}


}