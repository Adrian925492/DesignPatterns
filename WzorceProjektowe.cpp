//============================================================================
// Name        : WzorceProjektowe.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "Singleton/Singleton.h"
#include "Builder/Builder.h"

using namespace std;

Singleton* Singleton::_instance = 0;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	/* Builder */
		Director director;
		Product* product1 = director.Construct(new CocnreteBuilder1);
		Product* product2 = director.Construct(new CocnreteBuilder2);

	/* SIngleton */
		Singleton* singletonInstance = Singleton::getInstance();
		singletonInstance->metoda1(15);
		singletonInstance->metoda1(25);
		singletonInstance = Singleton::getInstance();
		singletonInstance->metoda1(100);
		singletonInstance->metoda1(112);
		Singleton::getInstance()->metoda1(9);

	return 0;
}
