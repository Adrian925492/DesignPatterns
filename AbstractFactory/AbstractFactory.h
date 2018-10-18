/*
 * AbstractFactory.h
 *
 *  Created on: 18 paŸ 2018
 *      Author: Adrian
 */

#ifndef ABSTRACTFACTORY_ABSTRACTFACTORY_H_
#define ABSTRACTFACTORY_ABSTRACTFACTORY_H_

#include <iostream>
using namespace std;


class AF_AbstractProduct
{

};

class AF_ConcreteProduct1 : public AF_AbstractProduct
{
public:
	AF_ConcreteProduct1(void)
	{
		cout << "Abstract Factory: Pack 1 Product created" << endl;
	}
};

class AF_ConcreteProduct2 : public AF_AbstractProduct
{
public:
	AF_ConcreteProduct2(void)
	{
		cout << "Abstract Factory: Pack 2 Product created" << endl;
	}
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////

/* Fabryka abstrakcyjna */
class AbstractFactory
{
private:
	AbstractFactory* _ConcreteFactory;
protected:
	virtual ~AbstractFactory(void){}
private:
	static AbstractFactory* _singletonInstance;

public:
	static AbstractFactory* getInstance(void)
	{
		if (_singletonInstance == 0)
		{
			_singletonInstance = new AbstractFactory;
			cout << "Singleton (Abstract factory) instance created " << endl;
		}
		cout << "Singleton (Abstract factory) instance get " << endl;
		return _singletonInstance;
	}


	void setConcreteFactory(AbstractFactory* ConcreteFactory)
	{
		_ConcreteFactory = ConcreteFactory;
	}
	AbstractFactory()
	{
		_ConcreteFactory = 0;
	}

	virtual AF_AbstractProduct* CreateProduct1(void)
	{
		return _ConcreteFactory->CreateProduct1();
	}
};

/* Fabryka konkretna 1 - korzysta z AbFact_ObjectCreationPack1 do stworzenia obiektów */
class ConcreteFactory1 : public AbstractFactory
{
public:
	ConcreteFactory1(){}
	virtual AF_AbstractProduct* CreateProduct1(void)
	{
		cout << "Concrete factory 1 called " << endl;
		return new AF_ConcreteProduct1();
	}
};

/* Fabryka konkretna 2 - korzysta z AbFact_ObjectCreationPack2 do stworzenia obiektów */
class ConcreteFactory2 : public AbstractFactory
{
public:
	ConcreteFactory2(){}
	virtual AF_AbstractProduct* CreateProduct1(void)
	{
		cout << "Concrete factory 2 called " << endl;
		return new AF_ConcreteProduct2();
	}
};

#endif /* ABSTRACTFACTORY_ABSTRACTFACTORY_H_ */
