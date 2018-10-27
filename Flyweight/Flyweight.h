/*
 * Flyweight.h
 *
 *  Created on: 27 pa� 2018
 *      Author: Adrian
 */

#ifndef FLYWEIGHT_FLYWEIGHT_H_
#define FLYWEIGHT_FLYWEIGHT_H_

#include <iostream>
using namespace std;

/*
 * Wzorzec py�ek - pozwala zast�pic du�� liczb� rzeczywistych instancji obiektow obiektami wsp�dzielonymi. To znaczy, �e
 * zamiast du�ej liczby sparametryzowanych instancji mamy zbi�r py�k�w, kt�re s� wps�dzielone i parametryzowane tylko gdy s�
 * potrzebne. Py�ek ma sw�j stan wewn�trzny i zewn�trzny. Stan wewn�trzny jest zapisany w py�ki i nie zale�y od konkekstu,
 * jego zmiana przez klienty umo�liwia wzp�u�ytkowanie py�ku. Stan zewnetrzny jest zale�ny i zmienia si� wraz z kontekstem (nie mo�na
 * go wsp�u�ytkowac). Pylki wykorzystujemy, gdy aplikacja korzysta z duzej liczby obiektow, gdy chcemy oszczedzic pami�c, gdy
 * mozna wyodrebnic stan obiektow i przeniesc poza nim, a to co zostaje jest wspolne dla obuektow (pylkow). Stan wewnetrzny jest zapisywany
 * lub obliczany przez klienty. Korzystanie z pylkow to koszty zwiazane z koniecznoscia obliczania stanow, ale znaczna oszczednosc pamieci.
 */

/*
 * Abstraction for flyweights
 */
class Flyweight_Abstraction{
public:
	virtual ~Flyweight_Abstraction(){}
	virtual void method1()=0;
	virtual void method2()=0;
};

/*
 * Pylek konkretny
 */
class FlyweightConcrete : public Flyweight_Abstraction
{
public:
	FlyweightConcrete()
{
		_contextState = 2;
		internalContext = 0;
}
	virtual ~FlyweightConcrete(){}
	virtual void method1()
	{
		cout << "Fyweight: Context internal: " << _contextState << "Cntext external: " << internalContext << endl;
	}
	virtual void method2()
	{

	}
	int internalContext;
private:
	int _contextState;		//To jest zewnetrzny parametr!
};

#endif /* FLYWEIGHT_FLYWEIGHT_H_ */
