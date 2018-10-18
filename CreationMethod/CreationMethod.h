/*
 * CreationMethod.h
 *
 *  Created on: 18 paü 2018
 *      Author: Adrian
 */

#ifndef CREATIONMETHOD_CREATIONMETHOD_H_
#define CREATIONMETHOD_CREATIONMETHOD_H_

#include <iostream>
using namespace std;

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
