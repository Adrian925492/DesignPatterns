/*
 * Singleton.h
 *
 *  Created on: 6 paü 2018
 *      Author: Adrian
 */

#ifndef SINGLETON_H_
#define SINGLETON_H_

#include <iostream>

/*
 * Przyk≥ad wzorce projektowego - singleton - gwarantuje, øe tylko jedna instancja zostanie utworzona (danje klasy).
 *
 */

/*
 * Wzorzec projektowy -
 * ! istnieje tylko jedna moøliwa instancja danej klasy
 * -> Singleton jest tworzony w momencie pierwszgo odwo≥ania
 * -> Singleton przestaje istniec po zakonczeniu glownej funkcji
 * -> W trakcie zycia istnieje tylko 1 instancja singletona
 */


class Singleton {
protected:
	Singleton(){}
private:
	static Singleton* _instance;
	int value;
public:
	static Singleton* getInstance(void)
	{
		if (_instance == 0)
		{
			_instance = new Singleton;
			std::cout << "Singleton instance created " << std::endl;
		}
		std::cout << "Singleton instance get " << std::endl;
		return _instance;
	}

	void metoda1(int newVal)
	{

		std::cout << "Singleton method1; old value: "<< value << " New value: " << newVal << std::endl;
		value = newVal;
	}
	void metoda2(void)
	{
		std::cout << "Singleton method2; value: " << std::endl;
	}
	//...//


};


#endif /* SINGLETON_H_ */
