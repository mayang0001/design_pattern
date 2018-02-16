#include <iostream>
#include "ingredient.h"
#include "pizza.h"
#include "pizza_store.h"

int main() {
  PizzaStore* store = new NYPizzaStore();
  store->OrderPizza("cheese");
}
