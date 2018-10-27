/*
 * Bridge.h
 *
 *  Created on: 27 pa� 2018
 *      Author: Adrian
 */

#ifndef BRIDGE_BRIDGE_H_
#define BRIDGE_BRIDGE_H_

#include <iostream>
using namespace std;

/*
 * Wzorzec most - s�u�y do oddzielania abstrakcji kalsy od jej implementacji, w spos�b nie statyczny (czyli bez u�ycia dziedziczenia)
 * ale wykorzystuj�c sk��danie obiekt�w. Umo�liwia rozszerzanie (niezale�ne) zar�wni implementacji, jak i abstrakcji. Abstrakcja
 * posiada referencj� do implementacji (konkretnej). Je�eli mamy wi�cej ni� jedn� impementacj�, wszystkie implementacje powinny
 * dziedziczyc po wspolnej klasie interfejsowej. Wszelkie zmiany w implementacji abstrakcji s� ukryte i nie maj� wp�ywu na klienty.
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
		_imp = implementation;		//Przekazywanie implementacji z zewn�trz nie jest narzucone jako constrain!
									//Implementacje mo�na uzyska� w inny spos�b (to jest najprostsze)
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
