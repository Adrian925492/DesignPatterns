/*
 * State.h
 *
 *  Created on: 2 lis 2018
 *      Author: Adrian
 */

#ifndef STATE_STATE_H_
#define STATE_STATE_H_

#include <iostream>
using namespace std;

/*
 * Wzorzec stan - umo¿liwia obiektowi modyfikacjê zachowania w wyniku zmiany wewnêtrznego stanu. W zale¿noœci od stanu obiektu
 * zdefiniowane zachowania maj¹ ró¿ne impementacje. Wzorzec stosujemy, gdy operacje obejmuj¹ d³ugie, wieloczêœciowe instrukcje warunkowe
 * zale¿ne od stanu obiektu. Wzorzec stan pozwala uproœcic takie struktury. Wzorzec sk³¹da sie z abstrakcji definiujacej interfejs (State) i zestaw metod, które
 * s¹ impementowane przez konkretne - dziedziczace po wspomnianej abstrakcji - stany. W zaleznosci od tego w którym stanie znajduje siê obiekt Contex (wspópracuj¹cy) -
 * taka implementacja zostanie wywo³ana. Obiekt context to interfejs dla klientów. Poniewa¿ ca³y kod specyficzny dla stanu znajduje sie w jednej
 * konkretnej podklasie, stany mo¿na ³atwo rozszerzac i modyfikowac. Pozwala uniknac realizacji maszyny stanow na strukturach warunkowych lub typu case.
 * Dodatkowo zastosowanie wzorca powoduje, ¿e zmiany stanu maj¹ jawne reprezentacje w postaci onkretnych podklas stanu. Wzorzec nie okresla które elementy
 * maja definiowac zmiany stanu. Mo¿e to robic kalsa contex, same stany lub klienty.
 */

// PRZYK£AD

/*
 * Abstrakcja stanów
 */
class StateAbstract
{
public:
	virtual ~StateAbstract(){}
	virtual void method(){};		//Imple,entuje domyslne zachowanie!
};

/*
 * Stan konkretny - stan 1
 */
class State1 : public StateAbstract
{
public:
	virtual void method()
	{
		cout << "State: State 1 specific method 1 called" << endl;
	}
};

/*
 * Stan konkretny - stan 2
 */
class State2 : public StateAbstract
{
public:
	virtual void method()
	{
		cout << "State: State 2 specific method 1 called" << endl;
	}
};

/*
 * Klasa Kontext
 */
class StateContex
{
public:
	StateContex(StateAbstract* st)
	{
		_state = st;
	}
	void setState(StateAbstract* st)
	{
		_state = st;
	}
	void method()
	{
		cout << "State: Contex method called " << endl;
		_state->method();
	}
private:
	StateAbstract* _state;
};

#endif /* STATE_STATE_H_ */
