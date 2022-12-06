#include "stock.h"
#include <vector>
using std::vector;

class Player
{
public:
    Player();
    Player(string name, uint64_t balance);
    void buyStock(Stock stock, int numStocks);
    void sellStock(string stock, int numStocks);
    void setBalance(uint64_t balance);
    uint64_t getBalance() const;
    uint64_t getNetWorth();
private:
    unsigned long long calculatedStockValue() const;
    // the player's name
    string name;
    // The player's decision to buy or sell stocks
    string playerDecision;
    // the player's balance, in tenths of a cent
    uint64_t balance;
    // the player's net worth, in tenths of a cent
    uint64_t netWorth;
    vector<Stock> portfolio;
};