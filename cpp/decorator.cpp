#include <iostream>
using namespace std;

class Pizza
{
public:
  virtual ~Pizza() {}

  virtual std::string getDescription() = 0;
  virtual int cost() = 0;
};

class ThinPizza : public Pizza
{
public:
  ~ThinPizza() {}

  string getDescription()
  {
    return "Thin Pizza";
  }
  int cost()
  {
    return 5;
  }
};

class Toppings : public Pizza
{
public:
  ~Toppings() {}

  Toppings(Pizza *p) : pizza(p) {}

  virtual string getDescription()
  {
    return pizza->getDescription();
  }
  virtual int cost()
  {
    return pizza->cost();
  }

private:
  Pizza *pizza;
};

class Cheese : public Toppings
{
public:
  Cheese(Pizza *p) : Toppings(p) {}

  int cost()
  {
    return Toppings::cost() + 10;
    // std::cout << "Decorator A" << std::endl;
  }
};

// class ConcreteDecoratorB : public Decorator
// {
// public:
//   ConcreteDecoratorB(Component *c) : Decorator(c) {}

//   void operation()
//   {
//     Decorator::operation();
//     std::cout << "Decorator B" << std::endl;
//   }
// };

int main()
{
  ThinPizza *tp = new ThinPizza();
  Cheese *cs = new Cheese(tp);
  // ConcreteDecoratorA *da = new ConcreteDecoratorA(db);

  Pizza *pizza = cs;
  cout << pizza->cost() << endl;

  delete tp;
  delete cs;
  // delete cc;

  return 0;
}
