#include "StockData.hpp"
class Client
{
public:
  virtual ~Client() {}

  virtual int getState() = 0;
  virtual void update(StockData *stockData) = 0;
};

class ConcreteObserver : public Client
{
public:
  ConcreteObserver(const int state) : observer_state(state) {}

  ~ConcreteObserver() {}

  int getState()
  {
    return observer_state;
  }

  void update(Subject *subject);

private:
  int observer_state;
};