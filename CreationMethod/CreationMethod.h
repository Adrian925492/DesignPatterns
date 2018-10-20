/*
 * CreationMethod.h
 *
 *  Created on: 18 paŸ 2018
 *      Author: Adrian
 */

#ifndef CREATIONMETHOD_CREATIONMETHOD_H_
#define CREATIONMETHOD_CREATIONMETHOD_H_

#include <iostream>
using namespace std;

/*
 * Okreœla interfejs do tworzenia obiektów, przy czym umo¿liwia podklasom wyznaczenie klasy danego boiektu. Stosowana, gdy
 * dana klasa nie zna typu obiektu jaki nale¿y utworzyc. Tworzone produkty maja wspolny interfejs (jakies cechy wspolne - podziedziczone).
 * Klasa klient nie zna konkretnego typu produkty, zna natomiast wspomniany abstrakcyjny interfejs. Metoda wytworcza to kalsa abstrakcyjan, ktora
 * dostarcza interfejsu konkretnym wytworcom. To sam wytworca kapsu³ukje informacjê o typie produktu konkretnego (zestawu produktów) jaki
 * trzeba wytworzyc, natomaist klient musi znac tylko ktowt z konkretnych wytworcow bedzie uzyty. Metoda wytworcza jest jakby
 * uproszczeniem fabryki abstrakcyjnej. Fabryka abstrakcyjna produkuje zestawy obiektow, antomiast metoda - jeden konkretny obiekt. Fabryka moze
 * implementowac zbior metod wytworczych.
 */

class CM_AbstractProduct
{

};

class CM_ConcreteProduct1 : public CM_AbstractProduct
{
public:
	CM_ConcreteProduct1()
	{
		cout << "Concrete product 1 created " << endl;
	}
};

class CM_ConcreteProduct2 : public CM_AbstractProduct
{
public:
	CM_ConcreteProduct2()
	{
		cout << "Concrete product 2 created " << endl;
	}
};

class CM_virtualCreator
{
public:
	virtual CM_AbstractProduct* createProduct()
	{
		return 0;
	}
};

class CM_ConcreteCreator1 : public CM_virtualCreator		//Konkretny creator
{
public:
	virtual CM_AbstractProduct* createProduct()
	{
		return new CM_ConcreteProduct1;						// WIe jaki konkretnie produkt utworzyc
	}
};

class CM_ConcreteCreator2 : public CM_virtualCreator
{
public:
	virtual CM_AbstractProduct* createProduct()
	{
		return new CM_ConcreteProduct2;
	}
};


#endif /* CREATIONMETHOD_CREATIONMETHOD_H_ */
