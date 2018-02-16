#ifndef PIZZA_STORE_H_
#define PIZZA_STORE_H_

#include "pizza.h"

class PizzaStore {
public:
  virtual Pizza* CreatePizza(const std::string&) = 0;
  void OrderPizza(const std::string&);
};

void PizzaStore::OrderPizza(const std::string& pizza_type) {
  Pizza* pizza = CreatePizza(pizza_type);

  pizza->prepare();
  pizza->bake();
  pizza->cut();
  pizza->box();

  delete pizza;
}

#endif
