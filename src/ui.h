#include "player.h"

class UI
{
public:
    UI();
    void showMenu();
    void menuSelection();
private:
    Player player;
    int selection;
};