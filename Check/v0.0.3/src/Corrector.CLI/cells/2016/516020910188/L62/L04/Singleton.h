#pragma once
class Singleton
{
private:
	Singleton();
	~Singleton();
    static Singleton* instance;
public:
	static Singleton* GetInstance();
};

