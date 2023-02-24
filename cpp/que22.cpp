#include <iostream>
using namespace std;
class Pizza
{
private:
  string description;

public:
  Pizza();
  virtual ~Pizza();
  virtual double cost() = 0;
  string getDescription()
  {
    return description;
  }
};

class Toppings : public Pizza
{

  string getDescription()
  {
    return "Toppings";
  };
};
class Cheese : public Toppings
{
public:
  Pizza *pizza;
  Cheese(Pizza *pizza);
  string getDescription()
  {
    return this->pizza->getDescription() + "cheese Toppings";
  }
  double cost()
  {
    return this->cost() + 3.0;
  }
};
class Olive
{
};
class Pepper
{
};

class ThinCrustPizza : public Pizza
{
  string getDescription()
  {
    return "Thin Crust";
  }
  double cost()
  {
    return 10.0;
  }
};

class ThickCrust : public Pizza
{
  string getDescription()
  {
    return "Thick Crust";
  }
  double cost()
  {
    return 20.0;
  }
};
int main()
{
  // Pizza *pizza = NULL;
  Pizza *pizza = new Cheese(new ThinCrustPizza());
  cout << pizza->getDescription() << endl;
}