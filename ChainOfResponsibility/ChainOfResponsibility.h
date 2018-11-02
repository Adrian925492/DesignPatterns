/*
 * ChainOfResponsibility.h
 *
 *  Created on: 30 pa� 2018
 *      Author: Adrian
 */

#ifndef CHAINOFRESPONSIBILITY_CHAINOFRESPONSIBILITY_H_
#define CHAINOFRESPONSIBILITY_CHAINOFRESPONSIBILITY_H_

#include <iostream>
using namespace std;

/*
 * �a�cuch zobowi�za� - wzorzec pozwala unikn�c wiazania nadawcy i wykonawcy ��dania. ��czy w �a�cuch obiekty zbiorcze i przekazuje
 * mi�dzy nimi ��danie a� zostanie obs�u�one. Stosowany, gdy obiekt mog�cy spe�nic ��danie nie jest znany requestorowi ��dania.
 * Pierwszy obiekt w �a�cuchy odbiera ��danie, i albo je obs�uguje, albo przekazuje dalej, a nast�pny robi to samo. Requester nie
 * wie kt�ry z obiekt�w obs�u�y ��danie. Ka�dy obiekt w �a�cuchy musi miec taki sam (podziedziczony wie po abstrakcji) interfejs
 * do obs�ugi ��dania oraz musi miec dost�p do swojego nast�pnika. Operacja obs�ugi ��dania zwykle domy�lnie przekazuje ��danie
 * do nast�pnika. Odpowiedni do obs�ugi obiekt w �a�cuchy mo�e przes�onic operacje obs�ugi ��dania i w ten spos� obs�u�yc je. Wzorzec
 * jest stosowany, gdy wiecej niz jeden obiekt moze obsluzyc zadanie, ale z gory nie wiadomo kto to zrobi, gdy chcemy przesylac
 * ��danie do jednego z kilku obiekt�w bez okre�lania konkretnego odbiorcy. U�ycie wzorca nie zapewnia gwarancji obs�ugi ��dania.
 */

// Wersja uproszczona - bez kontekstu!

/*
 * Abstrakcja - interfejs
 */
class AbstractChain
{
public:
	AbstractChain* _nastepnik;
	AbstractChain(){_nastepnik = 0;}
	virtual ~AbstractChain(){}
	virtual void handleRequest()
	{
		cout << "Handler moved to the next chain! " << endl;
		_nastepnik->handleRequest();     //Domy�lna Obs�uga ��dania - kierujemy do nastepnika
	}
};

/*
 * Przykladowe elementy �a�cucha
 */
class ChainElement1 : public AbstractChain
{
public:
	void SetSuccesor(AbstractChain* nast)
	{
		_nastepnik = nast;
	}
	//Brak handlera
};

class ChainElement2 : public AbstractChain
{
public:
	void SetSuccesor(AbstractChain* nast)
	{
		_nastepnik = nast;
	}
	//Brak handlera
};

class ChainElement3 : public AbstractChain
{
public:
	void SetSuccesor(AbstractChain* nast)
	{
		_nastepnik = nast;
	}
	virtual void handleRequest()	//Przeslaniamy metode!
	{
		cout << "CHAIN 3 umie obs�u�yc handler !!!" << endl;
	}
};


#endif /* CHAINOFRESPONSIBILITY_CHAINOFRESPONSIBILITY_H_ */
