#ifndef PIZZA_H
#define PIZZA_H

#include <iostream>
#include "pizza_ingredient_factory.h"

class Pizza {
public:
	Pizza(PizzaIngredientFactory* p) : 
		pizza_ingredient_factory_(p) {}
	virtual void Prepare() = 0;
	void Bake();
	void Cut();
	void Box();
protected:
	std::string name_;
	PizzaIngredientFactory* pizza_ingredient_factory_;
	Dough* dough_;
	Sauce* sauce_;
	Cheese* cheese_;
	Clam* clam_;
};

void Pizza::Bake() {
	std::cout<< "pizza is baked" << std::endl;
}

void Pizza::Cut() {
	std::cout<< "pizza is cutted" << std::endl;
}

void Pizza::Box() {
	std::cout<< "pizza is boxed" << std::endl;
}

class CheesePizza : public Pizza {
public:
	CheesePizza(PizzaIngredientFactory* p) :
		Pizza(p) {
	}

	void Prepare() override;
};

void CheesePizza::Prepare() {
	dough_ = pizza_ingredient_factory_->CreateDough();
	sauce_= pizza_ingredient_factory_->CreateSauce();
	cheese_ = pizza_ingredient_factory_->CreateCheese();
}
	
class ClamPizza : public Pizza {
public:
	ClamPizza(PizzaIngredientFactory* p) :
		Pizza(p) {
	}
	void Prepare() override;
};

void ClamPizza::Prepare() {
	dough_ = pizza_ingredient_factory_->CreateDough();
	sauce_= pizza_ingredient_factory_->CreateSauce();
	cheese_ = pizza_ingredient_factory_->CreateCheese();
	clam_ = pizza_ingredient_factory_->CreateClam();
}

#endif
