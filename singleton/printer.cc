#include <iostream>

class Printer {
 public:
  Printer(const Printer&) = delete;
  Printer& operator=(const Printer&) = delete;

  static Printer& GetPrinter(const std::string& name) {
    static Printer printer(name);
    return printer;
  }

  void PrintName() const {
    std::cout << "Printer name is " << name_ << std::endl;
  }

 private:
  Printer(const std::string& str) : name_(str) {};

  std::string name_;
};

int main() {
  Printer::GetPrinter().PrintName();
}
