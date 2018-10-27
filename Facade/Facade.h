/*
 * Facade.h
 *
 *  Created on: 25 pa� 2018
 *      Author: Adrian
 */

#ifndef FACADE_FACADE_H_
#define FACADE_FACADE_H_

#include <iostream>
using namespace std;

/*
 * Wzorzec fasada - s�u�y do definiowania prostego, wsp�lnego interfejsu do korzystania zamiast z�o��nych interfejs�w
 * klas sk��daj�cych si� na jaki� bardziej z�o��ny system. Fasada przechowuje referencje do obiekt�w podsystemu i wywo�uje
 * na nich konkretne metody, czyli korzysta z ich interfejs� wystawiaj�c za razem w�asny, uproszczony interfejs. Pozwala na
 * zmniejszenie powi�zania mi�dzy klientem i podsystemem, oddziela klienty od komponent� podsystemu.
 */

/*
 * Komponenty
 */
class Facade_Component1
{
public:
	void methodToCall()
	{
		cout << "Facade: COmponent1 method called" << endl;
	}
};

class Facade_Component2
{
public:
	void methodToCall()
	{
		cout << "Facade: COmponent2 method called" << endl;
	}
};

class Facade_Component3
{
public:
	void methodToCall()
	{
		cout << "Facade: COmponent3 method called" << endl;
	}
};

class Facade_Component4
{
public:
	void methodToCall()
	{
		cout << "Facade: COmponent4 method called" << endl;
	}
};


/*
 * Fasada
 */
class Facade
{
public:
	void FacadeMethod()
	{
		Facade_Component1 component1;
		component1.methodToCall();

		Facade_Component2 component2;
		component2.methodToCall();

		Facade_Component3 component3;
		component3.methodToCall();

		Facade_Component4 component4;
		component4.methodToCall();
	}
};


#endif /* FACADE_FACADE_H_ */
