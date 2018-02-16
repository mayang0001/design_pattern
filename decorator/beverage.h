#include <string>

class Beverage {
public:
	Beverage() {}
	Beverage(const std::string& d) : description_(d) {}
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
	CondimentDecorator(Beverage* b) : beverage_(b) {}
protected:
	Beverage* beverage_;
};

class Mocha : public CondimentDecorator {
public:
	Mocha(Beverage* b) : CondimentDecorator(b) {}
	std::string GetDescription() const override { return beverage_->GetDescription() + " Mocha"; }
	double Cost() const override { return 0.20 + beverage_->Cost(); }
};
