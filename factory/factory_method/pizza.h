#ifndef PIZZA_H
#define PIZZA_H

#include <iostream>
#include <string>

class Pizza {
 public:
  Pizza(const std::string& n, const std::string& d, const std::string& s) 
      : name_(n), dough_(d), souce_(s) {}

  virtual ~Pizza() = 0;

  void prepare();
  virtual void bake() = 0;
  virtual void cut() = 0;
  virtual void box() = 0;

 private:
  std::string name_;
  std::string dough_;
  std::string souce_;
};

void Pizza::prepare() {
  std::cout<< "Preparing " << name_ << std::endl;
  std::cout<< "Dough is " << dough_ << std::endl;
  std::cout<< "Souce is " << souce_ << std::endl;
}	

#endif
