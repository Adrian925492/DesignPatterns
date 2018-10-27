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
#include "Prototype/Prototype.h"

#include "Adapter/Adapter.h"
#include "Decorator/Decorator.h"
#include "Facade/Facade.h"
#include "Composite/Composite.h"
#include "Bridge/Bridge.h"
#include "Proxy/Proxy.h"
#include "Flyweight/Flyweight.h"

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
		cout << endl << endl;

	/* Prototype */
		PrototypeProduct1 prototype1;
		PrototypeProduct2 prototype2;

		AbstractPrototype* prototype_product1 = prototype1.Clone();
		AbstractPrototype* prototype_product2 = prototype2.Clone();

		/* Wzorzec prototyp - mamy klasy "Prototyp", któe dziedzicz¹ po klasie abstrakcyjnej "AbstractPrototyp".
		   Dziedzicz¹ - poniewa¿ to narzuca koniecznoœc implementacji operacji "clone()", dziêi której jesteœmy
		   w stanie utworzyc dowolna liczbe prototypow (znanego typu)

		   Mozemy rozszerzyc wzorzec prototyp o dodanie metody wytwórczej - wtedy konkretne prototypy mo¿emy ukryc
		   w konkretnych metodach wytworczych, a klient nie musi wiedziec nawet jakiego typu klona dostanie

		   Mozemy takze polaczyc prototyp z fabryka abstrakcyjna - jezeli fabryka abstrakcyjan zawiera konkretne fabryki bedace w istocie
		   konkretnymi prototypami danych obiektow (fabryka abstrakcyjna ma zestaw prototypow). W zasadzie w implementacji ^
		   fabryki abstrakcyjnej tak jest, bo konkretne fabryki produkuja w istocie klony konkretnych produktow.

		   */
		cout << endl << endl;
	////////////////////////////////////////////////////////////////////////////////////////////////////////
		/* Adapter */
		Adapter_ClassAdapter classAdapter;
		classAdapter.Target_Method1();
		classAdapter.Target_Method2();

		Adapter_ObjectAdapter objAdapter(new Adapter_Adaptee);
		objAdapter.Target_Method1();
		objAdapter.Target_Method2();
		cout << endl << endl;

		/* Dekorator */
		ConcreteComponent component;
		ConcreteDecorator component_decorated(&component);
		/* Nieudekorowany komponent */
		component.baseMethod1();
		/* Udekorowany komponent */
		component_decorated.baseMethod1();
		cout << endl << endl;

		/*Fasada*/
		Facade facade;
		facade.FacadeMethod();
		cout << endl << endl;

		/* Kompozyt */
		Leaf1 leaf1;
		Leaf2 leaf2;
		Leaf2 leaf2out;
		Composite composite;
		Composite innerComposite;

		innerComposite.AddComposite(&leaf1);	//Tworzymy kompozyt
		innerComposite.AddComposite(&leaf2);
		composite.AddComposite(&leaf2out);
		composite.AddComposite(&innerComposite);

		composite.method1();

		cout << endl << endl;


		/* Most */
		Bridge_ConcreteImplementation bridge;
		Bridge_Abstraction bridgeAbs(&bridge);
		bridgeAbs.method1();
		bridgeAbs.method2();
		cout << endl << endl;

		/* Proxy */
		Proxy_ConcreteObject obj;
		obj.method1();
		obj.metho2();

		Proxy_Proxy proxy;		//Proxy zamiast konkretnego boiektu!
		proxy.method1();
		proxy.metho2();		//Przes³¹nia metodê 2g¹ - ta ma nie byc wywolywana!!!
		cout << endl << endl;


		/* Flyweight */
		FlyweightConcrete flyweight;
		flyweight.method1();
		flyweight.internalContext = 2;		//Zmieniamy kontext (klient zmiania)
		flyweight.method1();
		cout << endl << endl;

	return 0;
}
