#include <string>

#include "pizza_store.h"
#include "ny_cheese_pizza.h"
#include "ny_clam_pizza.h"

class NYPizzaStore : public PizzaStore {
  Pizza* CreatePizza(const std::string&) override;
};

Pizza* NYPizzaStore::CreatePizza(const std::string& pizza_type) {
  if (pizza_type == "Cheese")
    return new NYCheesePizza();
  else
    return new NYClamPizza();
}

