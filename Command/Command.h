/*
 * Command.h
 *
 *  Created on: 2 lis 2018
 *      Author: Adrian
 */

#ifndef COMMAND_COMMAND_H_
#define COMMAND_COMMAND_H_

#include <iostream>
using namespace std;

/*
 * Polecenie - wzorzec s�u�y do kapsu�kowania ��dania w formie obiektu. Zastosowanie wzorca powoduje, �e ��dania mo�emy traktowac jak obiekty -
 * ustawiac w listy, zapamietywac, cofac itd... Wykrozystywany jest, gdy trzeba przekazac ��danie do obiektu mimo braku informacji o dobiorcy lub ��danych
 * operacjach. Wzorzec umo�liwia wysy�anie ��da� do nieokre�linych obiekt�w poprzez przekszta�cenie samego ��dania w obiekt. Istotn� kals� jest Abstrakcja
 * okre�lajaca interfejs polece�, p kt�rej dziedzicz� wsystkie polecenia - podklasy. Polecenia przechowuj� referencje do obiekt�w na k�rych pracuj�.
 *
 * Wzorzec mo�na wykorzystac do parametryzowania obiektow za pomoca wykonywalnych zadan, doo obslugi cofania zmian, o kolejkowania
 * ��da�, do obs�ugi rejestrowania zmian i do budowania systemu opartego na wysokopoziomowych operacjach opartych na prostych operacjach (patrz transakcje -
 * transakcja kapsu�kuje zbi�r zmian w danych). Zastosowanie wzorca oddziela obiekt wywo�uj�cy operacje od tego, kt�ry potrafi j� wykonc. Dodawanie nowych
 * polecen jest proste, bo nie wymaga modyfikowania istniejacych klas, a polecenia mo�na sk��dac w polecenia z�o��ne (wykorzystuj�c wzorzec kompozyt na obiektach - poleceniach)
 */

// PRZYK�AD

/*
 * Receiver
 */
class CommandReceiver
{
public:
	void receiverMethod()
	{
		cout << "Receiver method called " << endl;
	}
};

/*
 * Abstrakcja polecenie
 */
class CommandAbstraction
{
public:
	virtual ~CommandAbstraction(){}
	virtual void Execute()=0;		//Operacja wykonania!
protected:
	CommandAbstraction(){}
};

/*
 * Klasa concrete command
 */
class CommandConcrete : public CommandAbstraction
{
public:
	CommandConcrete(CommandReceiver* rec)
	{
		_receiver = rec;
	}
	virtual void Execute()
	{
		cout << "Command: Execute called " << endl;
		_receiver->receiverMethod();						//Efekt - wywolanie metody (lub bardziej zlozone zachowanie, zalezy od implementacji)
	}
private:
	CommandReceiver* _receiver;
};


#endif /* COMMAND_COMMAND_H_ */
