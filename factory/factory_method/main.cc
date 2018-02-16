#include "pizza.h"
#include "ny_pizza_store.h"

int main() {
  PizzaStore* store = new NYPizzaStore();
  store->OrderPizza("Cheese");
}
