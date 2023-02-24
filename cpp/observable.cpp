#include <iostream>
#include <vector>

class Subject;
struct StockState
{
  int nasdaq;
  int sp500;
};

class Observer
{
public:
  virtual ~Observer() {}

  virtual StockState getState() = 0;
  virtual void update(Subject *subject) = 0;
};

class ConcreteObserver : public Observer
{
public:
  ConcreteObserver(const StockState state) : observer_state(state) {}

  ~ConcreteObserver() {}

  StockState getState()
  {
    return observer_state;
  }

  void update(Subject *subject);

private:
  StockState observer_state;
};

class Subject
{
public:
  virtual ~Subject() {}

  void registerObserver(Observer *observer)
  {
    observers.push_back(observer);
  }

  void removeObserver(const int index)
  {
    observers.erase(observers.begin() + index);
  }

  void notify()
  {
    for (unsigned int i = 0; i < observers.size(); i++)
    {
      observers.at(i)->update(this);
    }
  }

  virtual StockState getState() = 0;
  virtual void setState(const int nasdaq, const int sp500) = 0;

private:
  std::vector<Observer *> observers;
};

class ConcreteSubject : public Subject
{
public:
  ~ConcreteSubject() {}

  StockState getState()
  {
    return stockState;
  }

  void setState(const int n, const int s)
  {
    stockState.nasdaq = n;
    stockState.sp500 = s;
  }

private:
  StockState stockState;
  int nasdaq;
  int sp500;
};

void ConcreteObserver::update(Subject *subject)
{
  observer_state = subject->getState();
  std::cout << "Observer state updated." << std::endl;
}

int main()
{
  StockState ss1;
  ss1.nasdaq = 2;
  ss1.sp500 = 3;

  ConcreteObserver observer1(ss1);
  ConcreteObserver observer2(ss1);

  std::cout << "Observer 1 state: " << observer1.getState().nasdaq << observer1.getState().sp500 << std::endl;
  std::cout << "Observer 2 state: " << observer2.getState().nasdaq << observer2.getState().sp500 << std::endl;

  Subject *subject = new ConcreteSubject();
  subject->registerObserver(&observer1);
  subject->registerObserver(&observer2);

  subject->setState(5, 6);
  subject->notify();

  std::cout << "Observer 1 state: " << observer1.getState().nasdaq << observer1.getState().sp500 << std::endl;
  std::cout << "Observer 2 state: " << observer2.getState().nasdaq << observer2.getState().sp500 << std::endl;

  delete subject;
  return 0;
}