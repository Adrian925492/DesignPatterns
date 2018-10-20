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

/*
 * Udostepnia interfejs do tworzenia rodzin obiektow bez okreslania ich klas konkretnych. Uzywany w sytuacjach, gdy wymagane
 * jest dostarczneie rodzin powiazanych produktow. Mmy do czynienia z abstrakcyjna fabryka - definiujaca interfejs dla konkretnych
 * fabryk. Podobnie mamy abstrakcyjne produkty, ktore dostarczaja interfejsu dla rodzin konkretnych produktow. Konkretne abstrakcyjan fabryka
 * wie, ktore produkty z kazdej rodziny produktow nalezy zozyc/ dostarczyc na ¿¹danie klienta. Klient, za posrednictwem fabryki, dostaje
 * konkretna implementacje prouktu, ale nie wie ktory konkretny produkt otrzymal. Klient zna tylko abstrakcyjny interfejs dla
 * rodziny produktow, natomiast sama strikte implementacja jest mu nieznana - ta informacja jest zakapsulkowana w powiazanej
 * konkretnej fabryce. W celu utworzenia konkretnego produktu, klient wywoluje metode utworz z interfejsy abstrakcyjnego fabryk.
 * Wymaganejest takze odniesiennie sie do konkretnej fabryki (jej wywolujemy metode "utworz"). Fabryka zwraca produkt, który ma abstrakcyjny
 * typ odpowiadajacy rodzinie produktów, z któej klient za¿¹da³ produktu. Klient w efekcie ie zna konkretnej implementacji produktu, a jedynie interfejsy
 *  - fabryki i produktu.
 */

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
