#include "Singleton.h"

Singleton* Singleton::instance = nullptr;
 Singleton* Singleton::GetInstance()
 {
	 if(instance==nullptr) instance=new Singleton;
	 return instance;
 }
 Singleton::Singleton()
 {

 }
 Singleton::~Singleton()
 {
	 delete instance;
 }