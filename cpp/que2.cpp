#include <iostream>
using namespace std;
class Pizza
{
public:
  Pizza();
  virtual ~Pizza();
  virtual string getDescription() = 0;
  virtual double getCost() = 0;
};
class PizzaDecorator : public Pizza
{
private:
  Pizza *m_wrappee;

protected:
  PizzaDecorator(){};
  PizzaDecorator(Pizza *inner) { this->m_wrappee = inner; }

public:
  ~PizzaDecorator() { delete this->m_wrappee; };
  double getCost() { return this->m_wrappee->getCost(); }
  string getDescription() { return this->m_wrappee->getDescription(); }
};

class ThinCrustPizza : public PizzaDecorator
{

private:
  double m_cost;
  string description;

public:
  ThinCrustPizza(Pizza *core) : PizzaDecorator(core) { this->m_cost = 5; }
  ThinCrustPizza();
  ~ThinCrustPizza();
  double getCost() { return (PizzaDecorator::getCost() + m_cost); }
  string getDescription() { return (description); }
};

class ThickCrustPizza : public PizzaDecorator
{

private:
  double m_cost;
  string description;

public:
  ThickCrustPizza(Pizza *core) : PizzaDecorator(core) { this->m_cost = 10; }
  ThickCrustPizza();
  ~ThickCrustPizza();
  double getCost() { return (PizzaDecorator::getCost() + m_cost); }
  string getDescription() { return (description); }
};

class RegularPizza : public Pizza
{
private:
  double m_cost;

public:
  RegularPizza() { this->m_cost = 25; }
  ~RegularPizza(){};
  double getCost() { return this->m_cost; }
};