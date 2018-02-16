#include <iostream>
#include "beverage.h"

int main() {
	Beverage* b;
	b = new HouseBlend();
	Beverage* d;
	d = new Mocha(b);
	d = new Mocha(d);
	std::cout << d->GetDescription() << std::endl;
	std::cout << d->Cost() << std::endl;
}
