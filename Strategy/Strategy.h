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
 * Wzorzec strategia - s³u¿y do kapsu³kowania algortymów z rodziny algorytmów i umo¿liwia ich zamienne stosowanie. Wzrozec sosujemy,
 * gdy nie chcemy miec kodu od ró¿nych algorytmów w ramach jednej klasy. Stosowanie wzorca (w takim przypadku) pozwala uniknac instrukcji warunkowych.
 * Wzorzec stosujemy, gdy wiele powiazanych algorytmow rozni sie tylko zachowaniem, a nie interfejsem; jesli potrzebujemy ró¿nych
 * wersji algorytmu, jeœli algorytm korzysta z zakapsu³kowanych przed klientami danych, gdy chcemy wyeliminowac instrukcje warunkowe z klasy
 * definiujacej wiele zachowan na raz. Elementy to abstrakcja - strategia - definiujaca wspólny interfejs dla dziedziczacych obiektów ConcreteStrategy - implementujacych algorytmy.
 * Dodatkowo mamy klase Contsx, która przechowuje referencjê do obiektu strategii i wywo³uje na strategii dzia³anie. Klienty musz¹ znac ró¿ne strategie, zanim
 * wybior¹ jedn¹ z nich. roblematyczne mo¿e byc przekazywanie danych z obiektu contex do strategy - mo¿e to byc zrealizowane poprzez argumenty metod, przekazanie do strategi obiektu contex (samego siebie)
 * lub zachowanie w strategii referenji do obiektu contex.
 */

// PRZYK£AD - podejscie przenoszenie danych do strategii (za pomoc¹ argumentów operacji)

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
