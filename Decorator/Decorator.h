/*
 * Decorator.h
 *
 *  Created on: 25 paŸ 2018
 *      Author: Adrian
 */

#ifndef DECORATOR_DECORATOR_H_
#define DECORATOR_DECORATOR_H_

#include <iostream>
using namespace std;

/*
 * Wzorzec dekorator s³u¿y do dodawania obiektowi danej klasy dodatkowych funkcjinalnoœci. Dekorator jest to klasa któa prze
 * chowuje referencjê do dekorowanego obiektu, ale te¿ jest interfejsowo zgodna z interfejsem dekorowanego obiektu.
 * Metody dekoratora wywo³uj¹ metody dekorowanego obiektu i mog¹ w swej implementacji zawierac pewne dodatki - wlasnie te dodatki
 * "dekoruj¹" dekorowany obiekt.
 */


/*
 * Abstract class - interface - for decorated elements. Not needed if only one concrete component is used.
 */
class AbstractComponent
{
public:
	virtual void baseMethod1(){}
	virtual void baseMethod2(){}

	virtual ~AbstractComponent(){}
};

/*
 * Concete component - one of components with common intrface (abstract) defined. Component to be decorated.
 */
class ConcreteComponent : public AbstractComponent
{
public:
	virtual void baseMethod1()
	{
		cout << "Decorator: Base component method 1 called" << endl;
	}
	virtual void baseMethod2()
	{
		cout << "Decorator: Base component method 2 called" << endl;
	}
	~ConcreteComponent(){}
};

/*
 * Dekorator - abstrakcja wymagana tylko wtedy, gdy u¿ywamy wiecej ni¿ jednego dekoratora!
 */
class AbstractDecorator : public AbstractComponent
{
	AbstractComponent* _component;
public:
	AbstractDecorator(AbstractComponent* componentRef)
	{
		_component = componentRef;
	}
	virtual void baseMethod1()
	{
		_component->baseMethod1();
	}
	virtual void baseMethod2()
	{
		_component->baseMethod2();
	}
};

/*
 * Concrete decorator - dodaje funkcjinalnoœci (konkretnie to metody) do dekorowanego obiektu _component
 */
class ConcreteDecorator : public AbstractDecorator
{
	void privateMethod()
	{
		cout << "Decoretor: private method called - functionality extended!" << endl;
	}
public:
	ConcreteDecorator(ConcreteComponent* component) : AbstractDecorator(component) {}
	void baseMethod1()
	{
		AbstractDecorator::baseMethod1();
		privateMethod();
	}
	void baseMethod2()
	{
		AbstractDecorator::baseMethod2();
		privateMethod();
	}
};


#endif /* DECORATOR_DECORATOR_H_ */
