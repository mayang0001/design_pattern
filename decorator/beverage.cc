#include <iostream>
#include <string>

class Beverage {
 public:
  Beverage(const std::string& description = "") 
      : description_(description) { 
    std::cout << "constructor is called" << std::endl;
  }

  virtual std::string GetDescription() const { return description_; }
  virtual double Cost() const = 0;

 private:
  std::string description_;
};

class HouseBlend : public Beverage {
 public:
  HouseBlend() : Beverage("House Blend Coffe") {}

  double Cost() const override { return 0.89; }
};

class Espresso : public Beverage {
 public:
  Espresso() : Beverage("Espresso Coffe") {}

  double Cost() const override { return 1.99; }
};

class CondimentDecorator : public Beverage {
 public:
  CondimentDecorator(Beverage* beverage) : beverage_(beverage) {}

 protected:
  Beverage* beverage_;
};

class Mocha : public CondimentDecorator {
 public:
  Mocha(Beverage* beverage) : CondimentDecorator(beverage) {}

  std::string GetDescription() const override { 
    return beverage_->GetDescription() + " Mocha"; 
  }
  double Cost() const override { return 0.20 + beverage_->Cost(); }
};

int main() {
  //Beverage* b;
  //Mocha mocha = Mocha(b);
  //mocha = Mocha(&mocha);
  //b = &mocha;
  Beverage* b = new HouseBlend;
  b = new Mocha(new Mocha(b));
  std::cout << b->GetDescription() << std::endl;
  std::cout << b->Cost() << std::endl;
}
