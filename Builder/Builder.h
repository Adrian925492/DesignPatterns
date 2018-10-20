/*
 * Builder.h
 *
 *  Created on: 16 paŸ 2018
 *      Author: Adrian
 */

#ifndef BUILDER_H_
#define BUILDER_H_

#include <iostream>

/*
 * Oddziela tworzenie obiektu od jego reprezentacji, dziêki czemu mo¿na utworzyc obiekt o roznej (nieznanej) reprezentacji.
 * Wzorzec stotujemy, gdy mamy skonkretyzowany obiekt jaki chcemy uzyskac, ale sama implementacja obiektu, jego cechy i sposob
 * dzialania jest nieznany. Przykladem moze byc implementacja klasy do sterowania portem na rozne mikrokontrolery. Niezaleznie
 * od implementacji, dla kazdej implementacji sterowanie pinem portu sprowadza sie do kilku prostych operacji. Zaleznie jednak
 * od mikroontrolera, implementacja wykonania tych operacji bedzi inna.
 *
 * Dyrektor i Konkretni budowniczy to kalsy konkretne. Konkretni budowniczy maja podziedziczony interfejs, co gwarantuje spojnosc
 * co do udostepnionych metod (przyklad: zapal; gas pin). Dyrektor przyjmuje konkretnego budowniczego jako argument, a
 * budowniczy zwraca obiekty konkretnego typu (odpowiadajacego typowi budowniczego) implementujace okreslone metody.
 */

/* Klasa "Produkt" - definiuje instancjê danego, sparametryzowanego produktu */
class Product {
	int atribute0;
	int atribute1;
	int atribute2;
public:
	Product(int at0, int at1, int at2)
	{
		atribute0 = at0;		//!<< Parametr 1
		atribute1 = at1;		//!<< Parametr 2
		atribute2 = at2;		//!<< Parametr 3
	}

	void SetAtribute0(int at0)
	{
		atribute0 = at0;
		std::cout << "Product created; at0 given " << at0 << std::endl;
	}
	void SetAtribute1(int at1)
	{
		atribute1 = at1;
		std::cout << "Product created at1 given " << at1 << std::endl;
	}
	void SetAtribute2(int at2)
	{
		atribute2 = at2;
		std::cout << "Product created at2 given " << at2 << std::endl;
	}
};

/* Interface class "Builder" - provides interface for concrete builders */
class Builder {
public:
	virtual ~Builder() {}				//<! Virtual destructor

	virtual void Build()=0;

	virtual void SetAtribute0(int) = 0;		//<! Atribute build (part 1)
	virtual void SetAtribute1(int) = 0;		//<! Atribute build (part 2)
	virtual void SetAtribute2(int) = 0;		//<! Atribute build (part 3)

	virtual Product* GetPart() {return 0;}	//!< Returns built part
};

/* "ConcreteBuilder" class */
class CocnreteBuilder1 : public Builder
{
private:
	Product* _Product;
public:
	CocnreteBuilder1()
	{
		_Product = 0;
	}

	virtual void Build()
	{
		_Product = new Product(0,0,0);
		std::cout << "Concrete builder type 1: product creation called! " << std::endl;
		SetAtribute0(128);
		SetAtribute1(12);
		SetAtribute2(15);
	}
private:
	void SetAtribute0(int atribute0)
	{
		std::cout << "ConcreteBuilder1 Part 1 called:   " << std::endl;
		_Product->SetAtribute0(atribute0);
	}
	void SetAtribute1(int atribute1)
	{
		std::cout << "ConcreteBuilder1 Part 1 called:   " << std::endl;
		_Product->SetAtribute1(atribute1);
	}
	void SetAtribute2(int atribute2)
	{
		std::cout << "ConcreteBuilder1 Part 2 called:   " << std::endl;
		_Product->SetAtribute2(atribute2);
	}
public:
	virtual Product* GetPart()
	{
		return _Product;
	}
};

/* "ConcreteBuilder" class */
class CocnreteBuilder2 : public Builder
{
private:
	Product* _Product;
public:
	CocnreteBuilder2()
	{
		_Product = 0;
	}

	virtual void Build()
	{
		_Product = new Product(0,0,0);
		std::cout << "Concrete builder type 2: product creation called! " << std::endl;
		SetAtribute0(1);
		SetAtribute1(2);
		SetAtribute2(3);
	}
private:
	void SetAtribute0(int atribute0)
	{
		std::cout << "ConcreteBuilder2 Part 1 called:   " << std::endl;
		_Product->SetAtribute0(atribute0);
	}
	void SetAtribute1(int atribute1)
	{
		std::cout << "ConcreteBuilder2 Part 1 called:   " << std::endl;
		_Product->SetAtribute1(atribute1);
	}
	void SetAtribute2(int atribute2)
	{
		std::cout << "ConcreteBuilder2 Part 2 called:   " << std::endl;
		_Product->SetAtribute2(atribute2);
	}
public:
	virtual Product* GetPart()
	{
		return _Product;
	}
};

/* Director class */
class Director
{
public:
	Director(){}
	Product*  Construct(Builder* builder)
	{
		builder->Build();
		return builder->GetPart();
	}
};

#endif /* BUILDER_H_ */
