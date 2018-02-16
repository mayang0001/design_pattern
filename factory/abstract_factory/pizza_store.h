#include "pizza.h"
#include "pizza_ingredient_factory.h"

class PizzaStore {
 public:
  void OrderPizza(const std::string&);
  virtual Pizza* CreatePizza(const std::string&) = 0;
};

void PizzaStore::OrderPizza(const std::string& pizza_type) {
  Pizza* pizza = CreatePizza(pizza_type);
  pizza->Prepare();
  pizza->Bake();
  pizza->Cut();
  pizza->Box();
}

class NYPizzaStore : public PizzaStore {
 public:
  Pizza* CreatePizza(const std::string&) override;
};

Pizza* NYPizzaStore::CreatePizza(const std::string& pizza_type) {
  PizzaIngredientFactory* factory = new NYPizzaIngredientFactory();

  if (pizza_type == "cheese")
    return new CheesePizza(factory);
  else
    return new ClamPizza(factory);
}
