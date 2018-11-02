/*
 * Iterator.h
 *
 *  Created on: 30 pa� 2018
 *      Author: Adrian
 */

#ifndef ITERATOR_ITERATOR_H_
#define ITERATOR_ITERATOR_H_

#include <iostream>
#include <vector>

using namespace std;

/*
 * Wzorzec iterator - s�u�y do dostarczania sekwencyjnego dost�pu do obiekt�w iterowalnych (z�o��nych) bez ujawniania ich
 * wewn�trznej struktury. Ponadto, iterator mo�e definiowac r�ne sposoby poruszania si� po obiektach z�o�onych. Wzorzec przenosi
 * odpowiedzialnosc za przechodzenie po elementacj obiektu i dstepu do nich z samego elementu z�o�onego na iterator.
 *
 * Iterator mo�e implementowac r�ne metody iteracji, tak jak i obiekt z�o�ony mo�e byc r�nego typu (iteracja polimorficzna). Wraz ze wzorcem iterator
 * wskazane jest stosowanie metody wytw�czej na iterator powi�zany z danym typem z�o�onym. W tym przypdaku, to obiekt iterowany ma operacje
 * CreateIterator, za pomoc� kt�rej, zgodnie z metod� wytw�rcz� tworzy odpowiedni iterator.
 *
 * Iteratory (je�eli ma byc ich du�o) tak jak i obiekty iterowane, mog� dziedziczyc po swoich klasach abstrakcyjnych.
 *
 * Iteratory stosujemy, gdy chcemy udostepnic operacje przechodzenia po obiektach bez ujawniania ich wewnetrznje struktury;
 * gdy chcemy umo�liwic jednoczesne wieloprocesowe przechodzenie(du�o r�nych iterator�) lub iterowanie polimorficzne (r�ne typy iterowane).
 *
 * Iterator zewn�trzny - klient steruje kt�ry element teraz jest wybrany, steruje procesem iteracji.
 * Iterator wewn�trzny - sam iterator steruje procesem iteracji, a tylko udost�pnia szereg metod.
 */

/*
 * Przyk��d implementacji - iterator listy std
 */

// W TEJ IMPLEMENTACJI OBIEKTEM ITEROWANYM B�DZIE OBIEKT TYPU LIST Z BIBLIOTEKI STANDARDOWEJ


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
 * Klasa up iterator - iteruje po li�cie do g�ry (od pocz�tku do ko�ca)
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
	const vector<Item>* _list;	//Powi�zana lista do iterownaia
	long _current;				//Kt�ry teraz element listy

};


/*
 * Klasa down iterator - iteruje po li�cie od g�ry (od ko�ca do pocz�tku)
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
	const vector<Item>* _list;	//Powi�zana lista do iterownaia
	long _current;				//Kt�ry teraz element listy

};

#endif /* ITERATOR_ITERATOR_H_ */
