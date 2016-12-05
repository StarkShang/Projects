#pragma once
class String
{
private:
	char* content;//String保存的字符数组数据
	int capacity;//content所含的内存空间
public:
	int count;//content中字符串的长度
	String (char* str);//赋值构造函数，根据 char*字符串 str 创建 String 类的对象。
	                   //在构造函数中应为 content 变量 new 出相应的内存空间，并给相应的成员赋值; 
	String (const String&str);//拷贝构造函数，根据 String 字符串类对象创建新的 String 类的对象。
	                          //在构造函数 中应为 content 变量 new 出相应的内存空间，并给相应的成员赋值; 
	~String();//在析构函数中应释放 content 所占用的空间;
	char* GetCString();//GetCString 将当前类转换成 c 风格的字符串。
		               //确保 content 内字符串以’\0’结尾 并返回 content 首地址。 

};

