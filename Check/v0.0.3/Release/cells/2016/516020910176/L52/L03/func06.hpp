#pragma once
struct LinkedNode                           //创建一个结构体用来存贮数据
{
	int data;                              
	LinkedNode* prev;                       
	LinkedNode* next;                       //创建指向前后结构体的指针
};

LinkedNode* create(int* array, int size)    //创建函数
{
	LinkedNode *head, *iterator;            //创建第一个结构体和第二个结构体
	head = iterator = new LinkedNode();     
	iterator->data = *array;                //把array里的第一个数据储存到第一个结构体中
	iterator->prev = nullptr;               //第一个结构体的前指针先指向空
	iterator->next = nullptr;               //第一个结构体的后指针指向空
	for (int i = 1; i < size; i++)
	{
		iterator->next = new LinkedNode();  //创建后一个结构体 
		iterator->next->data = array[i];    //赋值
		iterator->next->prev = iterator;    //这个新的结构体的prev指针指向现有的最后一个结构体
		iterator->next->next = nullptr;     //先使的这个结构体的后指针指向空
		iterator = iterator->next;          //把新的结构体换一个名字，成为现有的结构体
	}
	return head;                            //把第一个结构体的指针返回
}

LinkedNode* find(LinkedNode* head, int index)//寻找函数
{
	while (--index>0)                               //当index>0时开始循环（循环index次）  
	{
		if (head->next == nullptr) return nullptr; //如果头结构体的next指向为空（即只有一个结构体）返回空
		else head = head->next;                    //有多个结构体那么指向下一个结构体
	}
	return head;                                   //把最后的那个结构体返回
}

bool insert(LinkedNode* node, LinkedNode** head, int index)  //插入函数
{
	if (*head == nullptr)                                    //如果为空
	{                                                        
		node->prev = nullptr;                                //prev指针为空       
		node->next = nullptr;                                //next指针为空
		*head = node;                                        //head指向node
		return true;                                         //回一个true
	}
	LinkedNode* n = find(*head, index);                      //定义一个指针n指向要插入的结构组之前
	if (n == nullptr)                                        //如果n为空
	{
		n = find(*head, index - 1);                          //n定义为要寻找的结构体前面一个     
		if (n == nullptr)                                    //如果n还是空 
		{
			delete node;                                     //删去node
			return false;                                    //回一个false
		}
		else                                                 
		{
			n->next = node;                                  //n的next指向node
			node->prev = n;                                 //node的prev指向n
			node->next = nullptr;                            //node的next指向空
			return true;                                    //回一个true
		}
	}
	if (n->prev == nullptr) *head = node;                   //如果n的prev指针指向空 那么新的node就是第一个结构体
	else n->prev->next = node;                              //如果不是的话那么n的前一个
	node->prev = n->prev;                                   //把n原先的prev赋给新加入的node的prev
	node->next = n;                                         //node的next指向n
	n->prev = node;                                         //n的prev指向node
	return true;                                            //回一个true
}

bool remove(LinkedNode** head, int index)                        //remove函数
{
	LinkedNode* node = find(*head, index);                       //定义一个node指向需要被删去的函数
	if (node == nullptr) return false;                           //如果node指向空 返回一个false
	else if (node->prev == nullptr && node->next == nullptr)     //如果仅有一个结构体
	{
		*head = nullptr;                                         //定义为空
		return true;                                             //返回一个true
	}
	else                                                            //
	{
		if (node->prev == nullptr) *head = node->next;              //如果指向第一个结构体 直接让头指向第二个结构体
		else node->prev->next = node->next;                         //如果不是第一个结构体 让这个结构体的前一个的next指向这个结构体的下一个结构体
		if (node->next != nullptr) node->next->prev = node->prev;   //如果node不为最后一个 node的下一个的结构体的prev指向node的前一个结构体
		delete node;                                                //删去node
		return true;                                                //回复一个true
	}
}

void destory(LinkedNode* head)                                      //销毁函数
{
	while (head != nullptr)                                         //如果头函数不为空
	{
		LinkedNode* tmp = head;                                    //定义指针指向head
		head = head->next;                                         //用第二个覆盖第一个
		delete tmp;                                                //把原来的第一个删去
	}
}