#include "stock.h"

Stock::Stock()
{
    ss.imbue(std::locale(std::locale(), new Currency));
    name = "Nuka-Cola, Inc.";
    price = 50.00;
    oldPrice = 0.00;
    priceHighCounter = 0;

    ss << fixed << setprecision(3) << price;
}

Stock::Stock(const Stock& stock)
{
    ss.imbue(std::locale(std::locale(), new Currency));
    name = stock.name;
    price = stock.price;
    oldPrice = stock.oldPrice;
    priceHighCounter = stock.priceHighCounter;

    ss << fixed << setprecision(3) << price;
}

Stock::Stock(string name, int price, int oldPrice, int priceHighCounter)
{
    this->name = name;
    this->price = price;
    this->oldPrice = oldPrice;
    this->priceHighCounter = priceHighCounter;
}

void Stock::setPrice(int price)
{
    this->price = price;
}

void Stock::setNumStocksOwned(int numStocksOwned)
{
    this->numStocksOwned = numStocksOwned;
}

string Stock::getName() const
{
    return name;
}

long double Stock::getStockPrice() const
{
    return price;
}

long double Stock::getNumStocksOwned() const
{
    return numStocksOwned;
}

long double Stock::getOldPrice() const
{
    return oldPrice;
}

long double Stock::getPriceHighCounter() const
{
    return priceHighCounter;
}

long double Stock::getValuation() const
{
    return price * numStocksOwned;
}

std::ostream& operator<<(std::ostream& os, const Stock& stock)
{
    os << stock.name << " stock is currently worth " << stock.ss.str() << stock.price << endl;
    return os;
}

std::istream& operator>>(std::istream& is, Stock& stock)
{
    is.imbue(std::locale(std::locale(), new Currency));
    is >> stock.price;
    return is;
}