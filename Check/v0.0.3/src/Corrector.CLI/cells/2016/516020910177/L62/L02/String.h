#pragma once
class String
{
private:
   char*	content ;     //表示 String 保存的字符数组数据
   int   capacity ;       //表示 content 所占的内存空间;
public:
	int  count ;          //字符串的长度
    String(char* str);    //赋值构造函数，根据 char*字符串 str 创建 String 类的对象
    String(const String& str);  //拷贝构造函数，根据 String 字符串类对象创建新的 String 类的对象
    ~String();               //在析构函数中释放 content 所占用的空间
    char* GetCString();     //将当前类转换成 c 风格的字符串
};

