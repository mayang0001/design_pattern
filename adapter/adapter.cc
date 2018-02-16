#include <iostream>

class Duck {
 public:
  virtual void Quack() = 0;
  virtual void Fly() = 0;
};

class MallardDuck : public Duck {
 public:
  void Quack() override {
    std::cout << "mallard duck quack" << std::endl;
  }

  void Fly() override {
    std::cout << "mallard duck fly" << std::endl;
  }
};

class Turkey {
 public:
  virtual void Gobble() = 0;
  virtual void Fly() = 0;
};

class WildTurkey : public Turkey {
 public:
  void Gobble() override {
    std::cout << "wild turkey gobble" << std::endl;
  }

  void Fly() override {
    std::cout << "wild turkey fly" << std::endl;
  }
};

class TurkeyAdapterObject : public Duck {
 public:
  TurkeyAdapterObject(std::shared_ptr<Turkey> turkey) {
    turkey_ = turkey;
  }

  void Quack() override {
    turkey_->Gobble();
  }

  void Fly() override {
    for (int i = 0; i < 5; i++) {
      turkey_->Fly();
    }
  }

 private:
  std::shared_ptr<Turkey> turkey_;
};

//class TurkeyAdapterClass : public Duck, public Turkey {
// public:
//  void Quack() override {
//    Gobble();
//  }
//
//  void Fly() override {
//    for (int i = 0; i < 5; i++) {
//      Turkey::Fly();
//    }
//  }
//};

int main() {
  std::shared_ptr<Duck> duck(new MallardDuck);
  duck->Quack();
  duck->Fly();

  std::shared_ptr<Turkey> turkey(new WildTurkey);
  TurkeyAdapterObject* turkey_duck_object = new TurkeyAdapterObject(turkey);
  turkey_duck_object->Quack();
  turkey_duck_object->Fly();
  delete turkey_duck_object;

  //std::shared_ptr<Duck> turkey_duck_class(new TurkeyAdapterClass);
  //turkey_duck_class->Quack();
  //turkey_duck_class->Fly();
}
