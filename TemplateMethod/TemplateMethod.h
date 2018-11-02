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
 * Metoda szablonowa - wzorzec s�u�y do wyodr�bniania wsp�lnych cz�ci algorytmu do klasy abstrakcyjnej (po kt�rej dziedziacz� konkretne
 * klasy implementuj�ce cz�ci algorytmu, kt�re musz� byc odmienne). Okre�la szkielet algorytmu i umo�liwia doprecyzowanie w podklasach niekt�rych jego cz�ci.
 * Sk��da si� z klasy Abstrakcyjnej, w kt�rej cz�c metod - metody szablonowe - s� zaimplementowane i w swej implementacji korzystaj� z wirtualnych metod
 * implementowanyhc w podklasach wspomnianej abstrakcji. W ten spos�b mo�emy dostosowac zachowanie do indywidualnych potrzeb - w poklasach. SPecyficzne jest to, �e to
 * klasa nadrz�dna wywo�uje metody klas podrzednych a nie na odwr�t. Metoda szablonowa s�u�y do jednorazowego implementowania
 * niezmiennych czesci algorytmu i umo�liwia implementowanie czesci zachowac w podklasach. Umo�liwia ograniczenie kopiowania wspolnych czesci w podklasach.
 * Metoda szablonowa mo�e wywo�ywac: operacje konkretne(klienta lub konkretnej klasy); operacje abstrakcyjne; operacje proste, metody wytw�rcze
 * lub tzw. punkty zaczepienia(udostepniaja zahowanie domy�lne, kt�re mo�e byc rozszerzone w podklasach w razie potrzeby).
 */

// PRZYK�AD
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
	//Metody specyficzne - trzeba przes�onic
	virtual void specificMethod1() = 0;
	virtual void specificMethod2() = 0;
protected:
	virtual void handlerMethod() //Tzw. handler - tu mamy zdeiniowane domy�lne zachowanie, ktore mo�na przes�onic w podklasie wcelu rozszerzenia zachowania
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
