#include <iostream>
#include "StockData.hpp"
#include "Client.hpp"
int main()
{
  StockData stockExchange;
  Client one(1), two(2), three(3);
  float NASDAQ, SP500;
  StockData.registerObserver(&one);
  StockData.registerObserver(&two);
  StockData.registerObserver(&three);
  std::cout << "Enter NASDAQ, SP500 << ";
  std::cin >> NASDAQ >> SP500;
  // All the clients should be notified - simply display clients getting the data using cout
  StockData.setState(NASDAQ, SP500);
  StockData.removeObserver(&two);
  std::cout << "Enter NASDAQ, SP500 << ";
  std::cin >> NASDAQ >> SP500;
  StockData.setState(NASDAQ, SP500);
  // Client 1 and 3 should be notified - simply display clients getting the data using cout
  return 0;
}