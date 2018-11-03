/*
 * Strategy.h
 *
 *  Created on: 3 lis 2018
 *      Author: Adrian
 */

#ifndef STRATEGY_STRATEGY_H_
#define STRATEGY_STRATEGY_H_

#include <iostream>
using namespace std;

/*
 * Wzorzec strategia - s�u�y do kapsu�kowania algortym�w z rodziny algorytm�w i umo�liwia ich zamienne stosowanie. Wzrozec sosujemy,
 * gdy nie chcemy miec kodu od r�nych algorytm�w w ramach jednej klasy. Stosowanie wzorca (w takim przypadku) pozwala uniknac instrukcji warunkowych.
 * Wzorzec stosujemy, gdy wiele powiazanych algorytmow rozni sie tylko zachowaniem, a nie interfejsem; jesli potrzebujemy r�nych
 * wersji algorytmu, je�li algorytm korzysta z zakapsu�kowanych przed klientami danych, gdy chcemy wyeliminowac instrukcje warunkowe z klasy
 * definiujacej wiele zachowan na raz. Elementy to abstrakcja - strategia - definiujaca wsp�lny interfejs dla dziedziczacych obiekt�w ConcreteStrategy - implementujacych algorytmy.
 * Dodatkowo mamy klase Contsx, kt�ra przechowuje referencj� do obiektu strategii i wywo�uje na strategii dzia�anie. Klienty musz� znac r�ne strategie, zanim
 * wybior� jedn� z nich. roblematyczne mo�e byc przekazywanie danych z obiektu contex do strategy - mo�e to byc zrealizowane poprzez argumenty metod, przekazanie do strategi obiektu contex (samego siebie)
 * lub zachowanie w strategii referenji do obiektu contex.
 */

// PRZYK�AD - podejscie przenoszenie danych do strategii (za pomoc� argument�w operacji)

/*
 * Strategia - interfejs
 */
class AbstractStrategy
{
public:
	virtual void method(int paramA, int paramB) = 0;
protected:
	AbstractStrategy(){}
	virtual ~AbstractStrategy(){}
};

/*
 * Konkretne strategie
 */
class ConcreteStrategy1 : public AbstractStrategy
{
public:
	virtual void method(int paramA, int paramB)
	{
		cout << "Strategy: Strategy 1 called: algorithm counts a + b = " << paramA + paramB << endl;
	}
};

class ConcreteStrategy2 : public AbstractStrategy
{
public:
	virtual void method(int paramA, int paramB)
	{
		cout << "Strategy: Strategy 2 called: algorithm counts a * b = " << paramA * paramB << endl;
	}
};

/*
 * Context
 */
class StrategyContext
{
public:
	StrategyContext(AbstractStrategy* start)
	{
		_startegy = start;
	}
	void SetStrategy(AbstractStrategy* start)
	{
		_startegy = start;
	}
	void CallStartegy(int a, int b)
	{
		_startegy->method(a, b);
	}
private:
	AbstractStrategy* _startegy;
};

#endif /* STRATEGY_STRATEGY_H_ */
