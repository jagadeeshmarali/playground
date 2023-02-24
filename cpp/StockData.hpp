#include "Client.hpp"

struct Stocks
{
  float nasdaq;
  float sp500;
};
class StockData
{
public:
  ~StockData() {}

  void registerObserver(Client *client)
  {
    clients.push_back(client);
  }

  void removeObserver(const int index)
  {
    clients.erase(clients.begin() + index);
  }

  void notify()
  {
    for (unsigned int i = 0; i < clients.size(); i++)
    {
      clients.at(i)->update(this);
    }
  }

  Stocks getState()
  {
    return {nasdaq, sp500};
  };
  void setState(const float nasdaq, const float sp500)
  {
    nasdaq = nasdaq;
    sp500 = sp500;
  }

private:
  std::vector<Client *> clients;
  std::float nasdaq;
  std::float sp500;
};
