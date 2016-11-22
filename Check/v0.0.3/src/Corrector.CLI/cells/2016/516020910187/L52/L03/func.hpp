#pragma once
struct LinkedNode
{
	int data;
	LinkedNode* prev;
	LinkedNode* next;
};

LinkedNode* create(int* array, int size)
{
	LinkedNode *head, *iterator;//指示物
	head = iterator = new LinkedNode();
	iterator->data = *array;
	iterator->prev = nullptr;
	iterator->next = nullptr;//初始化
	for (int i = 1; i < size; i++)//循环
	{
		iterator->next = new LinkedNode();//开辟下一项
		iterator->next->data = array[i];//存入数据
		iterator->next->prev = iterator;//保留本项
		iterator->next->next = nullptr;//定义下下一项
		iterator = iterator->next;//移动指示物
	}
	return head;//创建结束返回head
}

LinkedNode* find(LinkedNode* head, int index)
{
	while (--index>0)//循环，要求项数存在
	{
		if (head->next == nullptr) return nullptr;
		else head = head->next;//逐项查找
	}
	return head;
}

bool insert(LinkedNode* node, LinkedNode** head, int index)
{
	if (*head == nullptr)//空的链表
	{
		node->prev = nullptr;
		node->next = nullptr;
		*head = node;//直接创建一项
		return true;
	}
	LinkedNode* n = find(*head, index);//使用找项函数
	if (n == nullptr)//超范围
	{
		n = find(*head, index - 1);//前一项
		if (n == nullptr)//还是超范围
		{
			delete node;
			return false;//无法插入
		}
		else//末尾项
		{
			n->next = node;
			node->prev = n;
			node->next = nullptr;
			return true;//在末尾添加，插入成功
		}
	}
	if (n->prev == nullptr) *head = node;//第一项直接添加
	else n->prev->next = node;//中间项获取空间
	node->prev = n->prev;//n之间不动
	node->next = n;
	n->prev = node;//插入到原来n的位置
	return true;//插入成功
}

bool remove(LinkedNode** head, int index)
{
	LinkedNode* node = find(*head, index);//找项函数
	if (node == nullptr) return false;//没有项，移除失败
	else if (node->prev == nullptr && node->next == nullptr)//只有一项
	{
		*head = nullptr;
		return true;//全删光，成功
	}
	else//不止一项
	{
		if (node->prev == nullptr) *head = node->next;//原位是第一项，head往后挪一下
		else node->prev->next = node->next;//原位是其他项，原位被后项占据
		if (node->next != nullptr) node->next->prev = node->prev;//如果不是最后一项，还要说明一下后项占据了原位
		delete node;//删掉原位内容
		return true;//成功
	}
}

void destory(LinkedNode* head)
{
	while (head != nullptr)//删光之前
	{
		LinkedNode* tmp = head;//提取head
		head = head->next;//往后挪一下head
		delete tmp;//把提取出来的东西删掉
	}
}