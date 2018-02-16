#include "pizza.h"

class NYCheesePizza : public Pizza {
public:
  NYCheesePizza() : 
    Pizza("New York Cheese Pizza", "Thin Crust Dough", "Marinara Pizza") {
  }
  
  ~NYCheesePizza();
  void bake() override;
  void cut() override;
  void box() override;
};

NYCheesePizza::~NYCheesePizza() {
  std::cout<< "New York Cheese Pizza is eated" << std::endl;
}

void NYCheesePizza::bake() {
  std::cout<< "New York Cheese Pizza is baked" << std::endl;
}

void NYCheesePizza::cut() {
  std::cout<< "New York Cheese Pizza is cutted" << std::endl;
}

void NYCheesePizza::box() {
  std::cout<< "New York Cheese Pizza is boxed" << std::endl;
}