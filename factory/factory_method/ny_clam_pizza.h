#ifndef NY_CLAM_PIZZA_H_
#define MY_CLAM_PIZZA_H_

#include "pizza.h"

class NYClamPizza : public Pizza {
public:
  NYClamPizza() : 
    Pizza("New York Clam Pizza", "Thin Crust Dough", "Marinara Pizza") {
  }
  
  ~NYClamPizza();
  void bake() override;
  void cut() override;
  void box() override;
};

NYClamPizza::~NYClamPizza() {
  std::cout<< "New York Clam Pizza is eated" <<std::endl;
}

void NYClamPizza::bake() {
  std::cout<< "New York Clam Pizza is baked" << std::endl;
}

void NYClamPizza::cut() {
  std::cout<< "New York Clam Pizza is cutted" << std::endl;
}

void NYClamPizza::box() {
  std::cout<< "New York Clam Pizza is boxed" << std::endl;
}

#endif
