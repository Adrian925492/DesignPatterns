/*
 * Iterator.h
 *
 *  Created on: 30 paŸ 2018
 *      Author: Adrian
 */

#ifndef ITERATOR_ITERATOR_H_
#define ITERATOR_ITERATOR_H_

#include <iostream>
#include <vector>

using namespace std;

/*
 * Wzorzec iterator - s³u¿y do dostarczania sekwencyjnego dostêpu do obiektów iterowalnych (z³o¿ónych) bez ujawniania ich
 * wewnêtrznej struktury. Ponadto, iterator mo¿e definiowac ró¿ne sposoby poruszania siê po obiektach z³o¿onych. Wzorzec przenosi
 * odpowiedzialnosc za przechodzenie po elementacj obiektu i dstepu do nich z samego elementu z³o¿onego na iterator.
 *
 * Iterator mo¿e implementowac ró¿ne metody iteracji, tak jak i obiekt z³o¿ony mo¿e byc ró¿nego typu (iteracja polimorficzna). Wraz ze wzorcem iterator
 * wskazane jest stosowanie metody wytwóczej na iterator powi¹zany z danym typem z³o¿onym. W tym przypdaku, to obiekt iterowany ma operacje
 * CreateIterator, za pomoc¹ której, zgodnie z metod¹ wytwórcz¹ tworzy odpowiedni iterator.
 *
 * Iteratory (je¿eli ma byc ich du¿o) tak jak i obiekty iterowane, mog¹ dziedziczyc po swoich klasach abstrakcyjnych.
 *
 * Iteratory stosujemy, gdy chcemy udostepnic operacje przechodzenia po obiektach bez ujawniania ich wewnetrznje struktury;
 * gdy chcemy umo¿liwic jednoczesne wieloprocesowe przechodzenie(du¿o ró¿nych iteratoró) lub iterowanie polimorficzne (ró¿ne typy iterowane).
 *
 * Iterator zewnêtrzny - klient steruje który element teraz jest wybrany, steruje procesem iteracji.
 * Iterator wewnêtrzny - sam iterator steruje procesem iteracji, a tylko udostêpnia szereg metod.
 */

/*
 * Przyk³¹d implementacji - iterator listy std
 */

// W TEJ IMPLEMENTACJI OBIEKTEM ITEROWANYM BÊDZIE OBIEKT TYPU LIST Z BIBLIOTEKI STANDARDOWEJ


/*
 * Abstrakcja  iterator
 */
template <class Item>
class AbstractIterator
{
public:
// Podstawowy interfejs iteratora - 4 metody!
	virtual void First()=0;
	virtual void Next()=0;
	virtual bool IsDone()=0;
	virtual Item CurrentItem() = 0;
protected:
	AbstractIterator(){}
	virtual ~AbstractIterator(){}
};


/*
 * Klasa up iterator - iteruje po liœcie do góry (od pocz¹tku do koñca)
 */
template <class Item>
class UpIterator : public AbstractIterator<Item>
{
public:
	UpIterator(const vector<Item>* aList) : _list(aList), _current(0)
	{

	}

// Podstawowy interfejs iteratora - 4 metody!
	virtual void First()
	{
		_current = 0;
	}
	virtual void Next()
	{
		_current++;
	}
	virtual bool IsDone()
	{
		return ((unsigned long)_current >= _list->size());
	}
	virtual Item CurrentItem()
	{
		if(IsDone())
		{
			//throw IteratorOutOfBounds;
		}
		cout << "Element nr: " << _current << " Get! "<< endl;
		return _list->at(_current);
	}
	virtual ~UpIterator(){}
private:
	const vector<Item>* _list;	//Powi¹zana lista do iterownaia
	long _current;				//Który teraz element listy

};


/*
 * Klasa down iterator - iteruje po liœcie od góry (od koñca do pocz¹tku)
 */
template <class Item>
class DownIterator : public AbstractIterator<Item>
{
public:
	DownIterator(const vector<Item>* aList) : _list(aList)
	{
		_current = _list->size()-1;
	}

// Podstawowy interfejs iteratora - 4 metody!
	virtual void First()
	{
		_current = _list->size()-1;
	}
	virtual void Next()
	{
		_current--;
	}
	virtual bool IsDone()
	{
		return (_current == 0);
	}
	virtual Item CurrentItem()
	{
		if(IsDone())
		{
			//throw IteratorOutOfBounds;
		}
		cout << "Element nr: " << _current << " Get! "<< endl;
		return _list->at(_current);
	}
	virtual ~DownIterator(){}
private:
	const vector<Item>* _list;	//Powi¹zana lista do iterownaia
	long _current;				//Który teraz element listy

};

#endif /* ITERATOR_ITERATOR_H_ */
