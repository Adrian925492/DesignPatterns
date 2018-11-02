/*
 * Memento.h
 *
 *  Created on: 2 lis 2018
 *      Author: Adrian
 */

#ifndef MEMENTO_MEMENTO_H_
#define MEMENTO_MEMENTO_H_

#include <iostream>
using namespace std;

/*
 * Wzorzec pami�tka - s�u�y do zachowywania i w razie potrzeby odtwarzania wewn�trznego stanu obiektu. Poniewa� stan obiektu
 * zazwyczaj jest zakapsu�kowany, niwmo�liwe jest zapami�tanie jego zewn�trznie. Pami�tka jest mechanizmem zapami�tywania obejmuj�cym wewn�trzny stan,
 * ale tylko obiekt sam w sobie mo�e pami�tk� zapisac i pobrac z niej zapisane dane. Dla pozosta�ych obiekt�w pami�tka jest nieprzezroczysta.
 * Pami�tk� stosujemy, kiedy trzeba zapisac wewn�trzny stan obiektu i ten stan musi byc zakapsu�kowany. We wzorcu mamy 3 zasadnicze elementy:
 * -> Pami�tka - przechowuje zapisane stany
 * -> Creator - �r�d�o - tworzy i odczytuje zapisane w pami�tce dane
 * -> Createker, zarz�dca - zarz�dza pami�tk�, m�wi kiedy pami�tka ma zostac utworzona, wywo�ana, kiedy ma zostac zapamietany stan.
 *
 * Pami�tka pozwala zachowac granice kapsu�kowania (unikn�c dostepu do wewnetrznych informacji). Pozwala na uproszczenie �r�d�a, ale mo�e byc
 * pamieciowo kosztowne - je�eli pami�tka musi zachowywac duze ilosci informacji. Pamiatki maja 2 interfejsy: pe�ny dla �r�de�, i okrojony publiczny.
 *
 */

// PRZYK�AD:

class Originator;

/*
 * Memento class
 */
class Memento{
public:
	//Interfejs publiczny - zaw�ony
	virtual ~Memento(){}
private:
	// Interfejs pe�ny - tylko dla oryginatora
	friend class Originator;
	Memento(){
		_memState = 0;  //Initial memento state
	}

	void SetState(int state)
	{
		_memState = state;
		cout << "Memento: Memento: state set: " << _memState << endl;
	}
	int GetState()
	{
		cout << "Memento: Memento: state get: "<< _memState << endl;
		return _memState;
	}
	int _memState;
};


/*
 * Originator
 */
class Originator{
public:
	Memento* CreateMemento()					//Stworz pamiatke
	{
		return new Memento;
	}
	void SetMemento(Memento* memento)	//Ustaw pamiatke
	{
		memento->SetState(_state);
	}
	void GetMemento(Memento* memento)
	{
		_state = memento->GetState();
	}
	void SetState(int state)					//Metody w�asne
	{
		cout << "Memento: Originator: state set: " << state << endl;
		_state = state;
	}
	int GetState()
	{
		cout << "Memento: Originator: state = " << _state << endl;
		return _state;
	}
	Originator()
	{
		_state = 4;
		cout << "Memento: Originator created, state = " << _state << endl;
	}
private:
	int _state;

};

// WE WSKAZANYM PRZYK�ADZIE ZARZADCA JEST KLIENT (Aplikacja)

#endif /* MEMENTO_MEMENTO_H_ */
