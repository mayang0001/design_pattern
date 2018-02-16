#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <iostream>

class Dough {
 public:
  Dough() { std::cout << "dough is created" << std::endl; }
  ~Dough() { std::cout << "dough is used" <<std::endl; }
};

class Sauce {
 public:
  Sauce() { std::cout << "sauce is created" << std::endl; }
  ~Sauce() { std::cout << "sauce is used" <<std::endl; }
};

class Cheese {
 public:
  Cheese() { std::cout << "cheese is created" << std::endl; }
  ~Cheese() { std::cout << "cheese is used" <<std::endl; }
};

class Clam {
 public:
  Clam() { std::cout << "clam is created" << std::endl; }
  ~Clam() { std::cout << "clam is used" <<std::endl; }
};

#endif
