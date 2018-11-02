//============================================================================
// Name        : WzorceProjektowe.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <list>
#include <vector>

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

#include "Interpreter/Interpreter.h"
#include "Iterator/Iterator.h"
#include "ChainOfResponsibility/ChainOfResponsibility.h"
#include "Mediator/Mediator.h"
#include "TemplateMethod/TemplateMethod.h"
#include "Observer/Observer.h"
#include "Visitor/Visitor.h"
#include "Memento/Memento.h"
#include "Command/Command.h"
#include "State/State.h"


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
		// Kontekst moze zmianiac klient (to najprostsza implementacja)
		cout << endl << endl;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		/* Interpreter */
		Contex contex;		//Tworzymy kontekst (narzucony!)
		BooleanExpresion* expression;
		VariableExp* prawda = new VariableExp('T');
		VariableExp* falsz = new VariableExp('F');

		// Expression (T | F) & T

		expression = new OrExp(
			new AndExp (prawda, falsz),
			falsz
		);
		bool result = expression->Interpret(contex);
		if (result == true)
		{
			cout << "TRUE" << endl;
		}else{
			cout << "FALSE" << endl;
		}
		cout << endl << endl;

		/* Iterator */
		//Tworzymy iterowalny obiekt
		vector<char> znaczki;
		znaczki.push_back('A');
		znaczki.push_back('B');
		znaczki.push_back('C');

		//Tworzymy iteratory
		UpIterator<char> up_iterator(&znaczki);
		DownIterator<char> down_iterator(&znaczki);

		cout << "upTer: Item: " << up_iterator.CurrentItem() << endl;
		up_iterator.Next();
		cout << "upTer: Item: " << up_iterator.CurrentItem() << endl;
		up_iterator.Next();

		cout << "downTer: Item: " << down_iterator.CurrentItem() << endl;
		down_iterator.Next();
		cout << "downTer: Item: " << down_iterator.CurrentItem() << endl;
		down_iterator.Next();

		cout << endl << endl;

		/* £añcuch zobowi¹zañ */
		ChainElement1 chain_element1;
		ChainElement2 chain_element2;
		ChainElement3 chain_element3;

		//Powiazanie 1:  1 -> 2 -> 3
		chain_element1.SetSuccesor(&chain_element2);
		chain_element2.SetSuccesor(&chain_element3);
		chain_element1.handleRequest();

		// Powiazanie 2: 1 -> 3 -> 2
		chain_element1.SetSuccesor(&chain_element3);
		chain_element3.SetSuccesor(&chain_element2);
		chain_element1.handleRequest();

		cout << endl << endl;

		/* Mediator		 */
		// ! APP te¿ jest klega dla mediatora! - to my tutaj wywolujemy operacje

		Mediator_Colegue1 colegue1;
		Mediator_Colegue2 colegue2;
		Mediator_Colegue3 colegue3;

		Mediator_AbstractCollegue* col1 = &colegue1;
		Mediator_AbstractCollegue* col2 = &colegue2;
		Mediator_AbstractCollegue* col3 = &colegue3;

		Mediator_ConcreteMediator mediator(col1, col2, col3);
		mediator.method();
		cout << endl << endl;

		/* Metoda szablonowa */
		TM_Concrete1 tm1;
		TM_Concrete2 tm2;

		tm1.templateMethod1();
		tm1.templateMethod_handler();
		tm1.specificMethod1();
		tm1.specificMethod2();

		tm2.templateMethod1();
		tm2.templateMethod_handler();
		tm2.specificMethod1();
		tm2.specificMethod2();

		cout << endl << endl;

		/* Obserwator */
		ConcreteSubject sub;
		AbstractSubject* s = &sub;

		ConcreteObserver obs1(s);
		ConcreteObserver2 obs2(s);

		sub.Notify();		//Informujemy o zmianie tanu
		obs1.methodUpdate();
		obs2.methodUpdate();

		cout << endl << endl;

		/* Odwiedzajacy	 */
		ElementA el_a;
		ElementB el_b;
		ConcreteVisiotrA vis_a;
		ConcreteVisiotrB vis_b;

		VisitorAbstract* abs_vis = &vis_a;
		el_a.Accept(abs_vis);
		el_b.Accept(abs_vis);

		abs_vis = &vis_b;
		el_a.Accept(abs_vis);
		el_b.Accept(abs_vis);

		cout << endl << endl;


		/* Pami¹tka */
		Originator originator;

		originator.GetState();		// Sprawdz stan originatora
		Memento* mem1 = originator.CreateMemento();	//Stworz pamiatke
		originator.SetMemento(mem1);	//Zapamietaj stan
		originator.SetState(2);		// Ustaw nowy stan originatora
		originator.GetState();		// Sprawdz stan originatora
		originator.GetMemento(mem1);	//Przywolaj zapamietany stan
		originator.GetState();		// Sprawdz stan originatora

		cout << endl << endl;


		/* Polecenie		 */
		CommandReceiver receiver;
		CommandConcrete command(&receiver);		//Obiekt command jest poleceniem klasy receiver!
		command.Execute();

		cout << endl << endl;

		/* Stan */
		State1 stan1;
		State2 stan2;
		StateAbstract* stan = &stan2;
		StateContex context(stan);

		context.method();
		stan = &stan1;
		context.setState(stan);
		context.method();

		cout << endl << endl;


	return 0;
}
