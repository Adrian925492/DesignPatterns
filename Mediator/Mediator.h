/*
 * Mediator.h
 *
 *  Created on: 31 paü 2018
 *      Author: Adrian
 */

#ifndef MEDIATOR_MEDIATOR_H_
#define MEDIATOR_MEDIATOR_H_

#include <iostream>
using namespace std;

/*
 * Wzorzec mediator - s≥uøy do kapsu≥kowania informacji o interakcji miÍzy obiektami z danego wzoru. Mediator
 * sam wie kiedy i jaka metode z jakiego obiektu wywo≥a zamiast zrzucac te odpowiedzialnosc na obiekty. Zastosowanie
 * mediatora powoduje, ze powiazania staja sie luüniejsze, ale przy zbyt duzej liczbie powiazan mediator staje sie bardzo skomplikowany
 * i jego przydatnosc maleje. Mediatory stosujemy, gdy lista obiektow komunikuje sie w dobrze zdefiniowany, ale
 * skomplikowany sposob; gdy z powodu odwolan do wielu innych powtorne wykorzystanie obiektu jest trudne; gdy dostosowanie zachowania rozproszonego
 * po kilku klasach nie powinno wymagac tworzenia wielu podklas. Gdy uzywamy tylko jednego mediatora nie wymagana jest kalsa abstrakcyjna - interfejs.
 * W przeciwnym razie po interfejsowej klasie dziedzicza pozostale mediatory. ediatory maja referencje obiektow z korymi sie komunikuja. Mediator upraszcza caly system,
 * rozdziela obiekty wspolpracujace, centralizuje sterowanie.
 */

// Przyklad

// Klasy - collegue - elementy
class Mediator_AbstractCollegue
{
public:
	virtual void method1(){}
	virtual void method2(){}
};

class Mediator_Colegue1 : public Mediator_AbstractCollegue
{
public:
	void method1()
	{
		cout << "Mediator: Colegue1: method 1 called" << endl;
	}
	void method2()
	{
		cout << "Mediator: Colegue1: method 2 called" << endl;
	}
};

class Mediator_Colegue2 : public Mediator_AbstractCollegue
{
public:
	void method1()
	{
		cout << "Mediator: Colegue2: method 1 called" << endl;
	}
	void method2()
	{
		cout << "Mediator: Colegue2: method 2 called" << endl;
	}
};

class Mediator_Colegue3 : public Mediator_AbstractCollegue
{
public:
	void method1()
	{
		cout << "Mediator: Colegue3: method 1 called" << endl;
	}
	void method2()
	{
		cout << "Mediator: Colegue3: method 2 called" << endl;
	}
};

/* Abstrakcja - mediator */
class Mediator_AbstractMediator
{
public:
	Mediator_AbstractCollegue* _colegue1;
	Mediator_AbstractCollegue* _colegue2;
	Mediator_AbstractCollegue* _colegue3;
	virtual void method(){}
};

/*
 * Mediator konkretny - wie ktora metode wywolac po kolei
 */
class Mediator_ConcreteMediator : public Mediator_AbstractMediator
{
public:
	Mediator_ConcreteMediator(Mediator_AbstractCollegue* c1, Mediator_AbstractCollegue* c2, Mediator_AbstractCollegue* c3)
	{
		_colegue1 = c1;
		_colegue2 = c2;
		_colegue3 = c3;
	}
	virtual void method()
	{
		_colegue1->method1();
		_colegue2->method2();
		_colegue3->method2();
	}
};


#endif /* MEDIATOR_MEDIATOR_H_ */
