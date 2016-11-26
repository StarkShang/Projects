#pragma once
struct LinkedNode
{
	LinkedNode *prev;
	int data;
	LinkedNode *next;//建立结构体
};

LinkedNode* create(int* array, int size)
{
	LinkedNode*head,*iterator;//建立指针
	head =iterator=new LinkedNode();//新的结构空间
	iterator->data=*array;//为第一个子链赋值
	iterator->prev=nullptr;//初始化prev
	iterator->next=nullptr;//初始化next
	for(int i=1;i<size;i++)
	{
		iterator->next=new LinkedNode();//建立新的储存空间
		iterator->next->data=array[i];//为新的结构体数据赋值
		iterator->next->prev=iterator;//将新的结构体prev指针赋为iterato的地址
		iterator->next->next=nullptr;//初始化新的结构体的next
		iterator=iterator->next;//更新iterator
	}
	return head;//返回初始地址
}

LinkedNode* find(LinkedNode* head, int index)//函数声明
{
	LinkedNode*temp=head;//将temp指针初始化
	if(index==1) return temp;//如果寻找的是第一个子链则返回初始值
	for(int i=0;i<index-1;i++)
	{
		temp=(*temp).next;//不断更新temp指针对应地址直到对应要寻找子链的地址
	}
	return temp;//返回相应指针


}

bool insert(LinkedNode* node, LinkedNode** head, int index)
{
	if(*head==nullptr)//判断链表中是否已经不存在子链
	{
		node->prev=nullptr;//将node对应结构体prev指针初始化
		node->next=nullptr;//将node对应结构体next指针初始化
		*head=node;//将链表初始地址赋为node对应地址
		return true;//执行成功
	}
	LinkedNode*n=find(*head,index);//n指针对应所要嵌入位置
	if(n==nullptr)//如果该位置不存在
	{
		n=find(*head,index-1);//将n指针对应嵌入位置的前一个位置

	if(n==nullptr)//如果前一个位置也不存在
	{
		delete node;//删除node指针
		return false;//执行失败
	}
	else//如果前一个位置存在
	{
		n->next=node;//将n指针对应子链的next指针指向node对应位置
		node->prev=n;//node指针对应子链的prev指针指向n对应位置
		node->next=nullptr;//将node对应子链的next指针赋空值
		return true;//执行成功
	}}
if(n->prev==nullptr) *head=node;//如果嵌入位置是第一个子链，将node位置赋给head
else n->prev->next=node;//否则将n前一个子链对应的next指针对应到node的位置
node->prev=n->prev;//将n对应的prev指针赋给node的prev指针
node->next=n;//将n的位置赋给node的next指针
n->prev=node;//将node的位置赋值给n对应的prev
return true;//执行成功
}

bool remove(LinkedNode** head, int index)
{

	LinkedNode*node=find(*head,index);//找到所要删除的子链位置
	if(node==nullptr)return false;//如果子链不存在则执行失败
	else if(node->prev==nullptr&&node->next==nullptr)//如果子链存在且前后均不存在子链
	{
		*head=nullptr;//链表不存在
		return true;//执行成功
	}
	else
	{
		if (node->prev==nullptr)
			*head=node->next;//如果要删除的子链是第一个子链，将第二个子链位置赋给head指针
		else node->prev->next=node->next;//否则将要删除的子链前一个子链对应的next指针赋为要删除子链的next指针
		if(node->next!=nullptr)node->next->prev=node->prev;//删除位置后存在子链则将下一个子链next指针赋为删除子链的next指针
		delete node;//删除对应子链
		return true;//执行成功
}
}
void destory(LinkedNode* head)
{
struct LinkedNode *p;//建立指针p
while(head!=NULL)//当第一项存在时
{
	p=head;//将首地址赋给p
	head=head->next;//将下一个子链地址赋给head
	p->next=NULL;
	free(p);//释放p
	p=NULL;//初始化p
}


}