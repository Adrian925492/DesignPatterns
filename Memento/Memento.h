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
 * Wzorzec pami¹tka - s³u¿y do zachowywania i w razie potrzeby odtwarzania wewnêtrznego stanu obiektu. Poniewa¿ stan obiektu
 * zazwyczaj jest zakapsu³kowany, niwmo¿liwe jest zapamiêtanie jego zewnêtrznie. Pami¹tka jest mechanizmem zapamiêtywania obejmuj¹cym wewnêtrzny stan,
 * ale tylko obiekt sam w sobie mo¿e pami¹tkê zapisac i pobrac z niej zapisane dane. Dla pozosta³ych obiektów pami¹tka jest nieprzezroczysta.
 * Pami¹tkê stosujemy, kiedy trzeba zapisac wewnêtrzny stan obiektu i ten stan musi byc zakapsu³kowany. We wzorcu mamy 3 zasadnicze elementy:
 * -> Pami¹tka - przechowuje zapisane stany
 * -> Creator - Ÿród³o - tworzy i odczytuje zapisane w pami¹tce dane
 * -> Createker, zarz¹dca - zarz¹dza pami¹tk¹, mówi kiedy pami¹tka ma zostac utworzona, wywo³ana, kiedy ma zostac zapamietany stan.
 *
 * Pami¹tka pozwala zachowac granice kapsu³kowania (unikn¹c dostepu do wewnetrznych informacji). Pozwala na uproszczenie Ÿród³a, ale mo¿e byc
 * pamieciowo kosztowne - je¿eli pami¹tka musi zachowywac duze ilosci informacji. Pamiatki maja 2 interfejsy: pe³ny dla Ÿróde³, i okrojony publiczny.
 *
 */

// PRZYK£AD:

class Originator;

/*
 * Memento class
 */
class Memento{
public:
	//Interfejs publiczny - zawê¿ony
	virtual ~Memento(){}
private:
	// Interfejs pe³ny - tylko dla oryginatora
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
	void SetState(int state)					//Metody w³asne
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

// WE WSKAZANYM PRZYK£ADZIE ZARZADCA JEST KLIENT (Aplikacja)

#endif /* MEMENTO_MEMENTO_H_ */
