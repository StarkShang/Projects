#pragma once
class Singleton
{
private:
	    static Singleton* instance;
		Singleton(); 
		~Singleton();

public:
	    static Singleton* GetInstance();
};

