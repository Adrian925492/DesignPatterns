/*
 * Adapter.h
 *
 *  Created on: 22 pa� 2018
 *      Author: Adrian
 */

#ifndef ADAPTER_ADAPTER_H_
#define ADAPTER_ADAPTER_H_

#include <iostream>
using namespace std;

/*
 * Wzorzec adapter przekszta�ca interfejs jednej klasy (klasy adaptowanej) tak, aby pasowa�a do interfejsu klasy
 * docelowej (Target).
 *
 * Adaptery mozemy podzielic na 2 rodzaje:
 * -> Adaptery klasowe - oparte na wielodziedziczeniu - w tym podej�ciu adapter dziedziczy publicznie interfejs po
 * targcie, a implementacj� dziedziczy prywatnie po klasie adaptowanej. Modyfikuj�c metody interfejsowe z klasy target
 * mo�emy wywo��c odziedziczone (w�ane) metody (implementacje) z klasy adaptowanej. Umo�liwia adaptowanie tylko jednej klasy
 * adaptee.
 *
 * -> Adaptery obiektowe - oparte na sk��daniu obiekt�w. W tej implementacji adapter dziedziczy publicznie interfejs
 * z klasy Target, natomiast metody podziedziczone s� przys�aniane przez metody wykorzystuj�ce interfejs klasy Adaptee.
 * Adapter wywo�uje operacje klasy adaptowanej (zewn�trznej). Wymaga podania wska�nika do sk�adanego obiektu. Umo�liwia adaptowanie
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
