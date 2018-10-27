/*
 * Bridge.h
 *
 *  Created on: 27 paŸ 2018
 *      Author: Adrian
 */

#ifndef BRIDGE_BRIDGE_H_
#define BRIDGE_BRIDGE_H_

#include <iostream>
using namespace std;

/*
 * Wzorzec most - s³u¿y do oddzielania abstrakcji kalsy od jej implementacji, w sposób nie statyczny (czyli bez u¿ycia dziedziczenia)
 * ale wykorzystuj¹c sk³¹danie obiektów. Umo¿liwia rozszerzanie (niezale¿ne) zarówni implementacji, jak i abstrakcji. Abstrakcja
 * posiada referencjê do implementacji (konkretnej). Je¿eli mamy wiêcej ni¿ jedn¹ impementacjê, wszystkie implementacje powinny
 * dziedziczyc po wspolnej klasie interfejsowej. Wszelkie zmiany w implementacji abstrakcji s¹ ukryte i nie maj¹ wp³ywu na klienty.
 */

/*
 * Interfejs - implementacja
 */
class Bridge_AbstractImplementation{
public:
	virtual ~Bridge_AbstractImplementation(){}
	virtual void method1()=0;
	virtual void method2()=0;
};

/*
 * Implementacja
 */
class Bridge_ConcreteImplementation : public Bridge_AbstractImplementation
{
	virtual void method1()
	{
		cout << "Brige: ConcreteImp1: method1 called" << endl;
	}
	virtual void method2()
	{
		cout << "Brige: ConcreteImp1: method2 called" << endl;
	}
};

/*
 * Abstrakcja
 */
class Bridge_Abstraction{
public:
	Bridge_Abstraction(Bridge_AbstractImplementation* implementation)
	{
		_imp = implementation;		//Przekazywanie implementacji z zewn¹trz nie jest narzucone jako constrain!
									//Implementacje mo¿na uzyska¿ w inny sposób (to jest najprostsze)
	}
	virtual ~Bridge_Abstraction(){}

	virtual void method1()
	{
		_imp->method1();
	}
	virtual void method2()
	{
		_imp->method2();
	}
private:
	Bridge_AbstractImplementation* _imp;
};



#endif /* BRIDGE_BRIDGE_H_ */
