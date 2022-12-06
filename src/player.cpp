#include "player.h"

Player::Player()
{
    name = "Don Joe";
    balance = 1000;
    netWorth = balance + calculatedStockValue();
}

Player::Player(string name, uint64_t balance)
{
    this->name = name;
    this->balance = balance;
    netWorth = balance + calculatedStockValue();
}

void Player::buyStock(Stock stock, int numStocks)
{
    if (balance >= stock.getStockPrice() * numStocks)
    {
        balance -= stock.getStockPrice() * numStocks;
        stock.setNumStocksOwned(numStocks);
        portfolio.push_back(stock);
    }
    else
    {
        cout << "You don't have enough money to buy that many stocks." << endl;
    }
}

void Player::sellStock(string stock, int numStocks)
{
    // lazy way of finding things, but it works
    bool stockFound = false;
    for (auto it = portfolio.begin(); it <= portfolio.end(); it++)
    {
        if (it->getName() == stock)
        {
            stockFound = true;
            if (it->getNumStocksOwned() >= numStocks)
            {
                balance += it->getStockPrice() * numStocks;
                it->setNumStocksOwned(it->getNumStocksOwned() - numStocks);
            }
            else
            {
                cout << "You don't have enough stocks to sell that many." << endl;
            }
        }
    }
}

void Player::setBalance(uint64_t balance)
{
    this->balance = balance;
}

uint64_t Player::getBalance() const
{
    return balance;
}

uint64_t Player::getNetWorth()
{
    netWorth = balance + calculatedStockValue();
    return netWorth;
}

unsigned long long Player::calculatedStockValue() const
{
    unsigned long long stockValue = 0;
    for (int i = 0; i < portfolio.size(); i++)
    {
        stockValue += portfolio[i].getValuation();
    }
    return stockValue;
}