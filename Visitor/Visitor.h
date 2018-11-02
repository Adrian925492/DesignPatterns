/*
 * Visitor.h
 *
 *  Created on: 2 lis 2018
 *      Author: Adrian
 */

#ifndef VISITOR_VISITOR_H_
#define VISITOR_VISITOR_H_

#include <iostream>
using namespace std;

/*
 * Wzorzec odwiedzaj¹cy - Reprezentuje operacje wykonywan¹ na elementach struktury obiektów. Umo¿liwia zdefiniowanie nowej operacji
 * bez zmiany klasy obiektu dla tej operacji. Wzorzec odwiedzajacy stosujemy, gdy mamy strukturê klas i chcemy dodac kolejen zadania
 * ale nie chcemy zasmiecac klas ze struktury. Odwiedzajacy dziedzicza po wspolnej abstrakcji definiujacej interfejs. Jeden odwiedzajcy
 * obsluguje (rozszerza) metody jednego odwiedzanego, w konsekwencji mamy 2 struktury - odwiedzajacych i odwiedzanych. Odwiedzajacy jest
 * wykorzystywany, jesli struktura obiektow obejmuje wiele kals o roznych interfejsach, a chcemy wykonywac na tych obiektach
 * operacje zalezne od ich klas konkretnych, kiedy na obiektach z ich struktury trzeba wykonywac wiele roznych niepowiazanych operacji, gdy
 * klasy definiujace strukture obiektow rzadko sie zmieniaja, a chcemy dodawac nowe funkcjnalnosci do tej struktury. Element w czasie
 * odwiedzin wywoluje operacje Visitor odpowiednia dla jego klasy. Element przekazuje sam siebie jako argument odwiedzajacemu, aby umozliwic odwiedzajacemu
 * dostep do stanu, jesli to konieczne. Konsekwencja moze byc naruszenie kapsulkowania (stany musza byc publiczne zeby visitor móg³ z nich korzystac). Elementy
 * nie musz¹ miec w pelni wspolnego interfejsu!
 */

//PRZYKLAD

class ElementA;
class ElementB;

/* Abstract visitors */
class VisitorAbstract {
public:
	virtual void VisitElementA(ElementA* element){};
	virtual void VisitElementB(ElementB* element){};
	virtual ~VisitorAbstract(){}
};

/* Concete visitors */
class ConcreteVisiotrA : public VisitorAbstract
{
public:
	virtual void VisitElementA(ElementA* element);
	virtual void VisitElementB(ElementB* element);
	virtual ~ConcreteVisiotrA(){}
};

class ConcreteVisiotrB : public VisitorAbstract
{
public:
	virtual void VisitElementA(ElementA* element);
	virtual void VisitElementB(ElementB* element);
	virtual ~ConcreteVisiotrB(){}
};

/* Abstract element - deklaruje tylko operacje Accept dla elementow */
class ElementAbstract{
public:
	virtual ~ElementAbstract(){}
	virtual void Accept(VisitorAbstract* visitor) = 0;
protected:
	ElementAbstract(){}
};

/* Element A */
class ElementA : public ElementAbstract
{
public:
	virtual ~ElementA(){param = 1;}
	virtual void Accept(VisitorAbstract* visitor)
	{
		cout << "Visitor: element A accept" << endl;
		visitor->VisitElementA(this);
	}
	int param;	//Parametr - publiczny - na tym bedzie pracowal odwiedzajacy
};

/* Element B */
class ElementB : public ElementAbstract
{
public:
	virtual ~ElementB(){param = 2;}
	virtual void Accept(VisitorAbstract* visitor)
	{
		cout << "Visitor: element B accept" << endl;
		visitor->VisitElementB(this);
	}
	int param;	//Parametr - publiczny - na tym bedzie pracowal odwiedzajacy
};


void ConcreteVisiotrB::VisitElementB(ElementB* element)
	{
		element->param = 5;
		cout << "ConcreteVisitorB: VisitB: sets param to 5" << endl;
	}

void ConcreteVisiotrB::VisitElementA(ElementA* element)
	{
		element->param = 7;
		cout << "ConcreteVisitorB: VisitA: sets param to 7" << endl;
	}

void ConcreteVisiotrA::VisitElementB(ElementB* element)
	{
		cout << "ConcreteVisitorB: VisitB: gets param from B: " << element->param << endl;
	}

void ConcreteVisiotrA::VisitElementA(ElementA* element)
	{
		cout << "ConcreteVisitorB: VisitA: gets param from A: " << element->param << endl;
	}

#endif /* VISITOR_VISITOR_H_ */
