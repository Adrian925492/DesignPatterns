/*
 * Proxy.h
 *
 *  Created on: 27 pa� 2018
 *      Author: Adrian
 */

#ifndef PROXY_PROXY_H_
#define PROXY_PROXY_H_

#include <iostream>
using namespace std;

/*
 * Wzorzec pa�nomocnik - umo�liwia zastosowanie zast�pczego reprezentanta danego obiektu w miejsce obiektu, pozwala kontrolowac
 * dostep do rzeczywistego obiektu. Dziala jako zast�pca rzeczywistego obiektu. Rodzaje:
 * - Zdalny pe�nomocnik: reprezentant obiektu w innej przestrzeni adresowej (np, je�li nie musimy zawsze odwo�ywac sie do FLASHA
 * mamy w RAMIE pelnomocnika obiektu
 * - Wirtualny pelnomocnik: tworzy na ��danie kosztowne obiekty (np. rysunki), tylko gdy sa potrzebne, �eby przyoszcz�dzic zasoby
 * - Zabezpieczajacy pelnomocnik - kontroluje dostep do pierwotnego obiektu.
 * - Inteligentne referencje - zastepuj zwykle wspa�niki i wykonuj� dodatkowe operacje przy dost�pie do obiektu.
 */

// Ptzyklad pelnomocnika wirtualnego //

/*
 * Abstrakcja obiektu rzeczywistego - jego interfejs
 */
class Proxy_AbstractObject{
public:
	virtual ~Proxy_AbstractObject(){}
	virtual void method1()=0;
	virtual void metho2()=0;
};

/*
 * Obiekt rzeczywisty
 */
class Proxy_ConcreteObject : public Proxy_AbstractObject
{
public:
	virtual ~Proxy_ConcreteObject(){}
	virtual void method1()
	{
		cout << "Proxy: ConcreteObject1: method 1 called" << endl;
	}
	virtual void metho2()
	{
		cout << "Proxy: ConcreteObject1: method 2 called" << endl;
	}
};

/*
 * Po�rdnik
 */
class Proxy_Proxy : public Proxy_AbstractObject
{
private:
	Proxy_AbstractObject* _object;

protected:
	Proxy_AbstractObject* getElement()
	{
		if (_object == 0)
		{
			_object = new Proxy_ConcreteObject;		//Proxy dobrze ZNA sw�j obiekt rzeczywisty!!!  -agregacja
		}
		return _object;
	}

public:
	Proxy_Proxy()
	{
		_object=0;
	}

	virtual void method1()
	{
		cout << "Proxy: Proxy: method 1 called" << endl;
		getElement()->method1();

	}
	virtual void metho2()
	{
		cout << "Proxy: Proxy1: method 2 called" << endl;
	}
};

#endif /* PROXY_PROXY_H_ */
