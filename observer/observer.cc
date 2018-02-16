#include <iostream>
#include <list>
#include <unordered_map>

class Observer;

class Subject {
 public:
  Subject() = default;
  ~Subject() = default;
  
  void AddObserver(Observer* observer);
  void RemoveObserver(const Observer* observer);

  void NotifyAll();

  int NumObservers() const { return observers_.size(); }

 private:
  std::list<Observer*> observers_;
  std::unordered_map<const Observer*, std::list<Observer*>::iterator>
    observer_to_iter_;
};

class Observer {
 public:
  Observer(std::shared_ptr<Subject> subject) {
    subject_ = subject;
    subject_->AddObserver(this);
  } 

  ~Observer() {
    subject_->RemoveObserver(this);
  }

  virtual void Update() = 0; 

 private:
  std::shared_ptr<Subject> subject_;
};

class TrueObserver : public Observer {
 public:
  TrueObserver(std::shared_ptr<Subject> subject)
      : Observer(subject) {}

  void Update() override {
    std::cout << "observer updated" << std::endl;
  }
};

void Subject::AddObserver(Observer* observer) {
  observers_.push_back(observer);
  observer_to_iter_[observer] = --observers_.end();
}

void Subject::RemoveObserver(const Observer* observer) {
  auto iter = observer_to_iter_[observer];
  observers_.erase(iter);
  observer_to_iter_.erase(observer);
}

void Subject::NotifyAll() {
  std::cout << "total observer numbers: " << observers_.size() << std::endl;
  for (auto observer : observers_) {
    observer->Update();
  } 
}

int main() {
  std::shared_ptr<Subject> subject(new Subject);
  TrueObserver obs1(subject);
  TrueObserver obs2(subject);
  subject->NotifyAll();
}
