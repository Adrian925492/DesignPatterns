/*
 * Observer.h
 *
 *  Created on: 2 lis 2018
 *      Author: Adrian
 */

#ifndef OBSERVER_OBSERVER_H_
#define OBSERVER_OBSERVER_H_

#include <iostream>
#include <list>
using namespace std;

/*
 * Wzorzec obserwator - okreœla zale¿noœc jeden do wielu miedzy obiektami. Kiedy zmieni sie stan jednego z obiektów,
 * wszystkie zale¿ne od niego obiekty s¹ o tym automatycznie powiadamiane i aktualizowane. Kluczowe elementy to podmiot i obserwator.
 * Z podmotem mo¿na powi¹zac dowolna liczbe obserwatorow. Podiot, gdy zmieni sie jego stan, wysyla do wszystkich obserwatorow informae o zmianie stanu.
 * Obserwatory same dcyduja kiedy sie zsynchronizowac z nowym stanem lub czy zignorowac informacje o zmianie stanu podmiotu. Ze wzorca korzystamy, jesli
 * zmiana w jednym obiekcie wymaga modyfikacji drugiego, a nie wiadomo ile obserwatorow jest dostepnych, jesli obiekt powinien
 * moc powiadamiac inne o zmianie stanu bez znajomosci ich rodzaju. Dzieki zastosowaniu wzorce, powiazanie miedzy obiektami
 * subject i obserwer jest luŸne - abstrakcyjne. Podmiot przy wysylaniu powiadomien nie musi okreslac odbiorcy - po prosu rozsyla
 * powiadomienia do wszystkich dostepnych odbiorcow.
 */

// PRZYK£AD: - NIE ZADZIA£¥ DOBRZE W PODEJŒCIU HEADEROWYM: NIE MO¯NA ZAIMPLEMENTOWAÆ KOMUNIKACJI DWUSTRONNEJ - PRZYK£¥D "OKROJONY" TYLKO DO METODY UPDATE KALSY SUBJECT
class AbstractSubject;
/*
 * Obserwator - abstrakcja
 */
class AbstractObserver
{
public:
	virtual ~AbstractObserver(){}
	virtual void Update() = 0;
protected:
	AbstractObserver(){}
};

class ConcreteObserver : public AbstractObserver
{
public:
	virtual void Update()
	{
		cout << "Observer: ConcreteObserver1: Update marked called" << endl;
	}
	ConcreteObserver(AbstractSubject* subject);
	void methodUpdate();
	//Powinna byc metoda odwolujaca sie do referencji - obiektu subject
private:
	AbstractSubject* _subject;
};

class ConcreteObserver2 : public AbstractObserver
{
public:
	virtual void Update()
	{
		cout << "Observer: ConcreteObserver2: Update marked called" << endl;
	}
	ConcreteObserver2(AbstractSubject* subject);
	void methodUpdate();
	//Powinna byc metoda odwolujaca sie do referencji - obiektu subject
private:
	AbstractSubject* _subject;
};

/*
 * Subject - abstrakcja
 */
class AbstractSubject
{
public:
	virtual ~AbstractSubject(){}
	virtual void Attact(AbstractObserver* observer)		//Dodaje obserwator
	{
		_observers.push_back(observer);
		cout << "Observer attached" << endl;
	}
	virtual void Detach(AbstractObserver* observer)		//Wyrzuca obserwator
	{
		_observers.remove(observer);
	}
	virtual void Notify()								//Informuje obserwatory o zmianie stanu
	{
		list<AbstractObserver*>::iterator iterator;
		for (iterator = _observers.begin(); iterator != _observers.end(); ++iterator) {
		    cout << *iterator << endl;
		    (*iterator)->Update();
		}
	}
	virtual void getMethod(){};
protected:
	AbstractSubject(){}
private:
	list<AbstractObserver*>  _observers;

};

class ConcreteSubject : public AbstractSubject
{
public:
	virtual void getMethod()
	{
		cout << "Concrete subject: method called" << endl;

	} //Ta metoda MOG£ABY zostac wywo³ana przez obserwator (powinna nawet)!
};

void ConcreteObserver::methodUpdate()
{
	cout << "Concrete observer: update called" << endl;
	_subject->getMethod();
}
ConcreteObserver::ConcreteObserver(AbstractSubject* subject)
{
	_subject = subject;
	_subject->Attact(this);
}

void ConcreteObserver2::methodUpdate()
{
	cout << "Concrete observer2: update called" << endl;
	_subject->getMethod();
}
ConcreteObserver2::ConcreteObserver2(AbstractSubject* subject)
{
	_subject = subject;
	_subject->Attact(this);
}

#endif /* OBSERVER_OBSERVER_H_ */
