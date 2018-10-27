/*
 * Flyweight.h
 *
 *  Created on: 27 paŸ 2018
 *      Author: Adrian
 */

#ifndef FLYWEIGHT_FLYWEIGHT_H_
#define FLYWEIGHT_FLYWEIGHT_H_

#include <iostream>
using namespace std;

/*
 * Wzorzec py³ek - pozwala zast¹pic du¿¹ liczbê rzeczywistych instancji obiektow obiektami wspó³dzielonymi. To znaczy, ¿e
 * zamiast du¿ej liczby sparametryzowanych instancji mamy zbiór py³ków, które s¹ wpsó³dzielone i parametryzowane tylko gdy s¹
 * potrzebne. Py³ek ma swój stan wewnêtrzny i zewnêtrzny. Stan wewnêtrzny jest zapisany w py³ki i nie zale¿y od konkekstu,
 * jego zmiana przez klienty umo¿liwia wzpó³u¿ytkowanie py³ku. Stan zewnetrzny jest zale¿ny i zmienia siê wraz z kontekstem (nie mo¿na
 * go wspó³u¿ytkowac). Pylki wykorzystujemy, gdy aplikacja korzysta z duzej liczby obiektow, gdy chcemy oszczedzic pamiêc, gdy
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
