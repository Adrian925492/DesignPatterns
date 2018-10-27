/*
 * Composite.h
 *
 *  Created on: 26 pa� 2018
 *      Author: Adrian
 */

#ifndef COMPOSITE_COMPOSITE_H_
#define COMPOSITE_COMPOSITE_H_

#include <iostream>
#include <list>

using namespace std;

/*
 * Wzorzec kompozyt - pozwala z�o�yc obiekty w struktury drzewiaste, odzwierciedlajace hierarchie obiektow, z tym, �e
 * umo�liwia traktowanie z�o�e� i obiektow w taki sam spos�b. Wzorzec jest sotsowany, je�lei klienty maj� ignorowac roznice
 * mi�dzy prostymi obiektami a ich z�o�eniami. Najwa�niejsz� cz�ci� wzorca jest abstrakcyjna kalsa definiuj�ca interfejs
 * dla obiekt�w, po kt�ej dziedzicz� obiekty zar�wno proste, jak i z�o�one. Klasa musi implementowac zarowno metody wspolne,
 * jak i specyficzne dla zozonych komponentow. Komponenty zlozone mog� skladac si� z komponent�w prostych itd... Wzorzec stosuje
 * si� te� gdy chcemy przedstawic hierarchi� obiekt�w typu cz�c - calosc.
 */

/*
 * Abstrakcja - interfejs
 */
class AbstractComposite
{
public:
	virtual ~AbstractComposite(){}
	virtual int method1(){}
	virtual int method2(){}

	virtual void AddComposite(AbstractComposite*){}
	virtual void RemoveComposite(AbstractComposite*){}
};

/*
 * Leaf - simple part of composite (atomic part)
 */
class Leaf1 : public AbstractComposite
{
public:
	virtual ~Leaf1(){}
	virtual int method1()
	{
		cout << "Composite: Leaf1 Method1 called" << endl;
		return 11;
	}
	virtual int method2()
	{
		cout << "Composite: Leaf1 Method2 called" << endl;
		return 12;
	}
};

class Leaf2 : public AbstractComposite
{
public:
	virtual ~Leaf2(){}
	virtual int method1()
	{
		cout << "Composite: Leaf2 Method1 called" << endl;
		return 11;
	}
	virtual int method2()
	{
		cout << "Composite: Leaf2 Method2 called" << endl;
		return 12;
	}
};

/*
 * Composite - has leafs or other composites
 */
class Composite : public AbstractComposite
{
public:
	virtual ~Composite(){}
	virtual int method1()
	{
		 _element.front()->method1();
		 _element.back()->method1();
		 cout << "Composite: Composite method1 called" << endl;

	}
	virtual void AddComposite(AbstractComposite* element)
	{
		_element.push_back(element);
		cout << "Composite: Element added to List" << endl;
	}
	virtual void RemoveComposite(AbstractComposite* element)
	{
		_element.remove(element);
		cout << "Composite: Element removed from list " << endl;
	}

private:
	list<AbstractComposite*> _element;
};
#endif /* COMPOSITE_COMPOSITE_H_ */
