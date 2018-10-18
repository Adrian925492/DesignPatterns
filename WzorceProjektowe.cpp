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
#include "AbstractFactory/AbstractFactory.h"
#include "CreationMethod/CreationMethod.h"


using namespace std;

/* Singletones inits */
Singleton* Singleton::_instance = 0;
AbstractFactory* AbstractFactory::_singletonInstance = 0;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	/* Builder */
		Director director;
		Product* product1 = director.Construct(new CocnreteBuilder1);
		Product* product2 = director.Construct(new CocnreteBuilder2);
		cout << endl << endl;

	/* SIngleton */
		Singleton* singletonInstance = Singleton::getInstance();
		singletonInstance->metoda1(15);
		singletonInstance->metoda1(25);
		singletonInstance = Singleton::getInstance();
		singletonInstance->metoda1(100);
		singletonInstance->metoda1(112);
		Singleton::getInstance()->metoda1(9);
		cout << endl << endl;

	/* Abstract factory */
		ConcreteFactory1 ConcreteFactory1Instance;
		ConcreteFactory2 ConcreteFactory2Instance;

		AbstractFactory::getInstance()->setConcreteFactory(&ConcreteFactory1Instance);
		AF_AbstractProduct* Product1FromFactory1 = AbstractFactory::getInstance()->CreateProduct1();

		AbstractFactory::getInstance()->setConcreteFactory(&ConcreteFactory2Instance);
		AF_AbstractProduct* Product1FromFactory2 = AbstractFactory::getInstance()->CreateProduct1();	//Tu wiemy ze chcemy produkt 1 (nie metoda wytworcza!)
		cout << endl << endl;

	/* Creator method */
		CM_ConcreteCreator1 Creator1;
		CM_ConcreteCreator2 Creator2;

		CM_AbstractProduct* ProductA = Creator1.createProduct();
		CM_AbstractProduct* ProductB = Creator2.createProduct();		//Nie wiemy jaki konkretnie produkt zostanie utworzony -
		// Od tego mamy creatory 1,2 (z abstrakcj¹ - musi byc interfejs) zeby wiedzialy!



	return 0;
}
