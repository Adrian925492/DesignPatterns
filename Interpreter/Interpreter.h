/*
 * Interpreter.h
 *
 *  Created on: 29 paŸ 2018
 *      Author: Adrian
 */

#ifndef INTERPRETER_INTERPRETER_H_
#define INTERPRETER_INTERPRETER_H_

#include <iostream>
using namespace std;

/*
 * Wzorzec interpreter - u¿ywany do okreœlania gramatyki innego jêzyka (intrepretowalnego) oraz wykorzystje tê interpretacjê
 * do wykonywania zadañ danego jêzyka. Wzorzec interpreter sk³¹da siê z abstrakcji narzucaj¹cej interfejs i dziedzicz¹cych
 * po niej klasach. Wzorzec musi implementowac co najmniej operacje interpret. Klasy interpretera mo¿na uk³adac w drzewo (przyk³¹d:
 * regex). Interpreter mo¿emy stosowac gdy: 1. Gramatyka jest prosta; 2. Wydajnoœc nie jest najwazniejsza. Interpreter skalda sie z
 * klasy abstractExpression (wspomniana), oraz koncowych i niekoncowych wyrazen. Wyrazenia koncowe to implementacje metody interpret
 * zwiazane z najmniejszymi, koncowymi symbolami, natomiast wyrazenia posrednie obejmuje interpretacje dla symboli posrednich.
 */

/*
 * Przyklad - interpreter operacji logicznych: and i or
 */



/*
 * Kontekst - klasa okreœli nam jaki znaczek bêdzie znaczy³ true a jaki false
 */
class Contex{
public:
	Contex()
	{
		tr = (char)'T';
		fl = (char)'F';		//TU ZDEFINIOWANO KONTEKST  F - False; T - True
	}
	bool Lookup(char a)
	{
		if (a == tr)
		{
			cout << "Interpreter: TRUE expresion" << endl;
			return true;
		}
		else if(a == fl)
		{
			cout << "Interpreter: FALSE expresion" << endl;
			return false;
		}
	}
private:	//Model uproszczony - nie mamy dodawania do kontekstu - kontekst ju¿ jest zdefiniowany - t¹ klas¹
	char tr;
	char fl;
};

/*
 * Abstract interpreter:
 */
class BooleanExpresion{
public:
	BooleanExpresion(){}
	virtual ~BooleanExpresion(){}
	virtual bool Interpret(Contex& contex)=0;		//Okresla (interpretuje) wyrazenie
};

/*
 * Interpreter koncowy - variable exp
 */

class VariableExp : public BooleanExpresion
{
public:
	VariableExp(char name)
	{
		_name = name;	//Nema of the expression - ta konkretne literka podana do interpretacji!
	}
	virtual bool Interpret(Contex& context)
	{
		return context.Lookup(_name);	// Koncowa interpreacja - w zaleznosci od kontekstu przetlumaczy nam dana literke na jezyk C++ - czyli true lub false
	}
private:
	char _name;
};


/*
 * Intepreter posredni - and
 */
class AndExp : public BooleanExpresion
{
public:
	AndExp(BooleanExpresion* o1, BooleanExpresion* o2)
	{
		_operend1 = o1;
		_operend2 = o2;
	}
	virtual bool Interpret(Contex& contex)
	{
		return (_operend1->Interpret(contex) || _operend2->Interpret(contex));	//Jesli 2x true - interpretujemy jako true
	}
private:
	BooleanExpresion* _operend1;
	BooleanExpresion* _operend2;
};

/*
 * Intepreter posredni - or
 */
class OrExp : public BooleanExpresion
{
public:
	OrExp(BooleanExpresion* o1, BooleanExpresion* o2)
	{
		_operend1 = o1;
		_operend2 = o2;
	}
	virtual bool Interpret(Contex& contex)
	{
		return (_operend1->Interpret(contex) && _operend2->Interpret(contex));
	}
	BooleanExpresion* _operend1;
	BooleanExpresion* _operend2;
};

#endif /* INTERPRETER_INTERPRETER_H_ */
