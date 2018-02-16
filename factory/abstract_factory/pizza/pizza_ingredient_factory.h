#ifndef PIZZA_INGREDIENT_FACTORY_H
#define PIZZA_INGREDIENT_FACTORY_H

#include <string>
#include <iostream>
#include "ingredient.h"

class PizzaIngredientFactory {
public:
	virtual Dough* CreateDough() = 0;
	virtual Sauce* CreateSauce() = 0;
	virtual Cheese* CreateCheese() = 0;
	virtual Clam* CreateClam() = 0;
};

class NYPizzaIngredientFactory : public PizzaIngredientFactory {
public:
	Dough* CreateDough() override;
	Sauce* CreateSauce() override;
	Cheese* CreateCheese() override;
	Clam* CreateClam() override;
};

Dough* NYPizzaIngredientFactory::CreateDough() {
	return new Dough();
}


Sauce* NYPizzaIngredientFactory::CreateSauce() {
	return new Sauce();
}


Cheese* NYPizzaIngredientFactory::CreateCheese() {
	return new Cheese();
}

Clam* NYPizzaIngredientFactory::CreateClam() {
	return new Clam();
}

#endif
