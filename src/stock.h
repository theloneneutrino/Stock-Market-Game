#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "currencies.h"
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::stringstream;
using std::setprecision;
using std::fixed;

class Stock
{
public:
    Stock();
    Stock(const Stock& stock);
    Stock(string name, int price, int oldPrice, int priceHighCounter);
    void setPrice(int price);
    void setNumStocksOwned(int numStocksOwned);

    string getName() const;
    long double getStockPrice() const;
    long double getNumStocksOwned() const;
    // functions for controlling the price of the stock
    long double getOldPrice() const;
    long double getPriceHighCounter() const;
    long double getValuation() const;

    friend std::ostream& operator<<(std::ostream& os, const Stock& stock);
    friend std::istream& operator>>(std::istream& is, Stock& stock);
private:
    // stock's monetary value in the local currency
    stringstream ss;
    // the stock's name
    string name;
    // the number of stocks owned
    int numStocksOwned;
    // the current price of the stock, in tenths of a cent
    long double price;
    // the previous price of the stock, in tenths of a cent
    long double oldPrice;
    // the number of days the stock price has been increasing
    int priceHighCounter;
    // not sure what this is for
    int displayTip;
};