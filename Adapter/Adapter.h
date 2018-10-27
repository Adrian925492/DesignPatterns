/*
 * Adapter.h
 *
 *  Created on: 22 paŸ 2018
 *      Author: Adrian
 */

#ifndef ADAPTER_ADAPTER_H_
#define ADAPTER_ADAPTER_H_

#include <iostream>
using namespace std;

/*
 * Wzorzec adapter przekszta³ca interfejs jednej klasy (klasy adaptowanej) tak, aby pasowa³a do interfejsu klasy
 * docelowej (Target).
 *
 * Adaptery mozemy podzielic na 2 rodzaje:
 * -> Adaptery klasowe - oparte na wielodziedziczeniu - w tym podejœciu adapter dziedziczy publicznie interfejs po
 * targcie, a implementacjê dziedziczy prywatnie po klasie adaptowanej. Modyfikuj¹c metody interfejsowe z klasy target
 * mo¿emy wywo³¹c odziedziczone (w³ane) metody (implementacje) z klasy adaptowanej. Umo¿liwia adaptowanie tylko jednej klasy
 * adaptee.
 *
 * -> Adaptery obiektowe - oparte na sk³¹daniu obiektów. W tej implementacji adapter dziedziczy publicznie interfejs
 * z klasy Target, natomiast metody podziedziczone s¹ przys³aniane przez metody wykorzystuj¹ce interfejs klasy Adaptee.
 * Adapter wywo³uje operacje klasy adaptowanej (zewnêtrznej). Wymaga podania wskaŸnika do sk³adanego obiektu. Umo¿liwia adaptowanie
 * wielu klas adaptee.
 */

class Adapter_Target
{
public:
	void Target_Method1()
	{
		cout << "Adapter: Target method 1 called" << endl;
	}
	void Target_Method2()
	{
		cout << "Adapter: Target method 2 called" << endl;
	}
};

class Adapter_Adaptee
{
public:
	void Adaptee_Method1()
	{
		cout << "Adapter: Adaptee method 1 called" << endl;
	}
	void Adaptee_Method2()
	{
		cout << "Adapter: Adaptee method 2 called" << endl;
	}
};

/*
 * Adapter klasowy
 *
 */

class Adapter_ClassAdapter : public Adapter_Target, private Adapter_Adaptee
{
public:
	void Target_Method1()
	{
		cout << "Adapter: Class adapter: Method 1 adaptation" << endl;
		Adaptee_Method1();
	}
	void Target_Method2()
	{
		cout << "Adapter: Class adapter: Method 2 adaptation" << endl;
		Adaptee_Method2();
	}
};

/*
 * Adapter obiektowy
 */
class Adapter_ObjectAdapter : public Adapter_Target
{
public:
	Adapter_ObjectAdapter(Adapter_Adaptee* adapteeObj)
	{
		_adaptee = adapteeObj;
	}
	Adapter_Adaptee* _adaptee;
	void Target_Method1()
	{
		cout << "Adapter: Object adapter: Method 1 adaptation" << endl;
		_adaptee->Adaptee_Method1();
	}
	void Target_Method2()
	{
		cout << "Adapter: Object adapter: Method 2 adaptation" << endl;
		_adaptee->Adaptee_Method2();
	}
};


#endif /* ADAPTER_ADAPTER_H_ */
