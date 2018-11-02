/*
 * TemplateMethod.h
 *
 *  Created on: 2 lis 2018
 *      Author: Adrian
 */

#ifndef TEMPLATEMETHOD_TEMPLATEMETHOD_H_
#define TEMPLATEMETHOD_TEMPLATEMETHOD_H_

#include <iostream>
using namespace std;

/*
 * Metoda szablonowa - wzorzec s³u¿y do wyodrêbniania wspólnych czêœci algorytmu do klasy abstrakcyjnej (po której dziedziacz¹ konkretne
 * klasy implementuj¹ce czêœci algorytmu, które musz¹ byc odmienne). Okreœla szkielet algorytmu i umo¿liwia doprecyzowanie w podklasach niektórych jego czêœci.
 * Sk³¹da siê z klasy Abstrakcyjnej, w której czêœc metod - metody szablonowe - s¹ zaimplementowane i w swej implementacji korzystaj¹ z wirtualnych metod
 * implementowanyhc w podklasach wspomnianej abstrakcji. W ten sposób mo¿emy dostosowac zachowanie do indywidualnych potrzeb - w poklasach. SPecyficzne jest to, ¿e to
 * klasa nadrzêdna wywo³uje metody klas podrzednych a nie na odwrót. Metoda szablonowa s³u¿y do jednorazowego implementowania
 * niezmiennych czesci algorytmu i umo¿liwia implementowanie czesci zachowac w podklasach. Umo¿liwia ograniczenie kopiowania wspolnych czesci w podklasach.
 * Metoda szablonowa mo¿e wywo³ywac: operacje konkretne(klienta lub konkretnej klasy); operacje abstrakcyjne; operacje proste, metody wytwórcze
 * lub tzw. punkty zaczepienia(udostepniaja zahowanie domyœlne, które mo¿e byc rozszerzone w podklasach w razie potrzeby).
 */

// PRZYK£AD
class TM_Abstraction
{
public:
	virtual ~TM_Abstraction(){}

	// Metody templatowe - nie przeslaniamy
	void templateMethod1()
	{
		cout << "TM: TemplateMethod1 called" << endl;
		specificMethod1();
	}
	void templateMethod_handler()
	{
		cout << "TM: Template method with handler called" << endl;
		handlerMethod();
	}
	//Metody specyficzne - trzeba przes³onic
	virtual void specificMethod1() = 0;
	virtual void specificMethod2() = 0;
protected:
	virtual void handlerMethod() //Tzw. handler - tu mamy zdeiniowane domyœlne zachowanie, ktore mo¿na przes³onic w podklasie wcelu rozszerzenia zachowania
	{
		//TU NIE ROBIMY NIC - rozszerzaniem zachowan zajma sie podklasy
		cout << "X" << endl;
	}
};

// Klasy konkretne:
class TM_Concrete1 : public TM_Abstraction
{
public:
	virtual void specificMethod1()
	{
		cout << "TM: Concrete1: method 1 called specific" << endl;
	}
	virtual void specificMethod2()
	{
		cout << "TM: Concrete1: method 2 called specific" << endl;
	}
private:
	virtual void handlerMethod()
	{
		cout << "TM: Oncrete 1: handler method extension called" << endl;		// Mamy rozszerzenie handler method
	}
};

class TM_Concrete2 : public TM_Abstraction
{
public:
	virtual void specificMethod1()
	{
		cout << "TM: Concrete2: method 1 called specific" << endl;
	}
	virtual void specificMethod2()
	{
		cout << "TM: Concrete2: method 2 called specific" << endl;
	}
	// BRAK rozszerzenia handler method
};



#endif /* TEMPLATEMETHOD_TEMPLATEMETHOD_H_ */
