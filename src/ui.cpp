#include "ui.h"

UI::UI()
{
    player = Player();
    selection = 0;
}

void UI::showMenu()
{   
    cout << "Welcome to the Stock Market Simulator!" << endl;
    do{
        cout << "1. Buy Stock" << endl;
        cout << "2. Sell Stock" << endl;
        cout << "3. View Portfolio" << endl;
        cout << "4. View Stock Market" << endl;
        cout << "5. Exit" << endl;
        cout << "Please enter a number: ";
        cin >> selection;
        menuSelection();
    }while(selection != 5);
}

void UI::menuSelection()
{
    switch(selection)
    {
    case 1:
        cout << "Buy Stock" << endl;
        break;
    case 2:
        cout << "Sell Stock" << endl;
        break;
    case 3:
        cout << "View Portfolio" << endl;
        break;
    case 4:
        cout << "View Stock Prices" << endl;
        break;
    case 5:
        cout << "View Balance" << endl;
        break;
    case 6:
        cout << "Goodbye!" << endl;
        break;
    default:
        cout << "Invalid selection" << endl;
        break;
    }
}