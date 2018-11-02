/*
 * ChainOfResponsibility.h
 *
 *  Created on: 30 paŸ 2018
 *      Author: Adrian
 */

#ifndef CHAINOFRESPONSIBILITY_CHAINOFRESPONSIBILITY_H_
#define CHAINOFRESPONSIBILITY_CHAINOFRESPONSIBILITY_H_

#include <iostream>
using namespace std;

/*
 * £añcuch zobowi¹zañ - wzorzec pozwala unikn¹c wiazania nadawcy i wykonawcy ¿¹dania. £¹czy w ³añcuch obiekty zbiorcze i przekazuje
 * miêdzy nimi ¿¹danie a¿ zostanie obs³u¿one. Stosowany, gdy obiekt mog¹cy spe³nic ¿¹danie nie jest znany requestorowi ¿¹dania.
 * Pierwszy obiekt w ³añcuchy odbiera ¿¹danie, i albo je obs³uguje, albo przekazuje dalej, a nastêpny robi to samo. Requester nie
 * wie który z obiektów obs³u¿y ¿¹danie. Ka¿dy obiekt w ³añcuchy musi miec taki sam (podziedziczony wie po abstrakcji) interfejs
 * do obs³ugi ¿¹dania oraz musi miec dostêp do swojego nastêpnika. Operacja obs³ugi ¿¹dania zwykle domyœlnie przekazuje ¿¹danie
 * do nastêpnika. Odpowiedni do obs³ugi obiekt w ³añcuchy mo¿e przes³onic operacje obs³ugi ¿¹dania i w ten sposó obs³u¿yc je. Wzorzec
 * jest stosowany, gdy wiecej niz jeden obiekt moze obsluzyc zadanie, ale z gory nie wiadomo kto to zrobi, gdy chcemy przesylac
 * ¿¹danie do jednego z kilku obiektów bez okreœlania konkretnego odbiorcy. U¿ycie wzorca nie zapewnia gwarancji obs³ugi ¿¹dania.
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
		_nastepnik->handleRequest();     //Domyœlna Obs³uga ¿¹dania - kierujemy do nastepnika
	}
};

/*
 * Przykladowe elementy ³añcucha
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
		cout << "CHAIN 3 umie obs³u¿yc handler !!!" << endl;
	}
};


#endif /* CHAINOFRESPONSIBILITY_CHAINOFRESPONSIBILITY_H_ */
