/*
 * Prototype.h
 *
 *  Created on: 20 paü 2018
 *      Author: Adrian
 */

#ifndef PROTOTYPE_PROTOTYPE_H_
#define PROTOTYPE_PROTOTYPE_H_

#include <iostream>
using namespace std;

/*
 * Prototype - defines interface for concrete prototypes
 */
class AbstractPrototype
{
private:
	AbstractPrototype* _prototypeProduct;
protected:
	virtual AbstractPrototype* Clone() = 0;
public:

	AbstractPrototype(AbstractPrototype* concretePrototype)
	{
		_prototypeProduct = concretePrototype;
	}
	AbstractPrototype(){}

	virtual ~AbstractPrototype(){};

	AbstractPrototype* CreateProduct()
	{
		return _prototypeProduct->Clone();
	}
};

/*
 * Concrete prototype 1
 */
class PrototypeProduct1 : public AbstractPrototype
{
public:
	virtual AbstractPrototype* Clone()
	{
		cout << "Prototype product 1 cloned " << endl;
		return new PrototypeProduct1;
	}
};

/*
 * Concrete prototype 2
 */
class PrototypeProduct2 : public AbstractPrototype
{
public:
	virtual AbstractPrototype* Clone()
	{
		cout << "Prototype product 2 cloned " << endl;
		return new PrototypeProduct2;
	}
};


#endif /* PROTOTYPE_PROTOTYPE_H_ */
