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
 * Polecenie - wzorzec s³u¿y do kapsu³kowania ¿¹dania w formie obiektu. Zastosowanie wzorca powoduje, ¿e ¿¹dania mo¿emy traktowac jak obiekty -
 * ustawiac w listy, zapamietywac, cofac itd... Wykrozystywany jest, gdy trzeba przekazac ¿¹danie do obiektu mimo braku informacji o dobiorcy lub ¿¹danych
 * operacjach. Wzorzec umo¿liwia wysy³anie ¿¹dañ do nieokreœlinych obiektów poprzez przekszta³cenie samego ¿¹dania w obiekt. Istotn¹ kals¹ jest Abstrakcja
 * okreœlajaca interfejs poleceñ, p której dziedzicz¹ wsystkie polecenia - podklasy. Polecenia przechowuj¹ referencje do obiektów na kórych pracuj¹.
 *
 * Wzorzec mo¿na wykorzystac do parametryzowania obiektow za pomoca wykonywalnych zadan, doo obslugi cofania zmian, o kolejkowania
 * ¿¹dañ, do obs³ugi rejestrowania zmian i do budowania systemu opartego na wysokopoziomowych operacjach opartych na prostych operacjach (patrz transakcje -
 * transakcja kapsu³kuje zbiór zmian w danych). Zastosowanie wzorca oddziela obiekt wywo³uj¹cy operacje od tego, który potrafi j¹ wykonc. Dodawanie nowych
 * polecen jest proste, bo nie wymaga modyfikowania istniejacych klas, a polecenia mo¿na sk³¹dac w polecenia z³o¿óne (wykorzystuj¹c wzorzec kompozyt na obiektach - poleceniach)
 */

// PRZYK£AD

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
