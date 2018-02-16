#include <iostream>

class Printer {
public:
  static Printer& GetPrinter() {
    static Printer p("may");
    return p;
  }

  void PrintName() {
    std::cout << "Printer name is " << name_ << std::endl;
  }

private:
  Printer(const std::string& str) 
      : name_(str) {};
  Printer(const Printer&);
  Printer& operator = (const Printer&);

  std::string name_;
};

int main() {
  Printer::GetPrinter().PrintName();
}
