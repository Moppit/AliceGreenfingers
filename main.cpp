#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include "actions.h"

using namespace std;

int main()
{
  int height = 15;
  int width = 67;
  int balance = readBalance();
  char mainScreen[15][67];
  const int INVENTORY_CAPACITY = 10;
  const int MARKET_CAPACITY = 20;
  Crop inventory[INVENTORY_CAPACITY];
  Crop market[MARKET_CAPACITY];
  int numItems = readInventory(inventory);
  int numMarketItems = readMarket(market);
  readMainScreen(mainScreen);

  // Put Alice somewhere and then print screen
  Alice alice;
  alice.x = 2;
  alice.y = 2;
  alice.symbol = 'A';
  alice.prevSymbol = ' ';
  mainScreen[alice.y][alice.x] = alice.symbol;

  char userInput;
  while(userInput != 'Q' && userInput != 'q')
  {
    // Check if user is trying to move (ASCII = arrow key)
    if(userInput >= 'i' && userInput <= 'l')
    {
      mainScreen[alice.y][alice.x] = alice.prevSymbol;
      alice = moveAlice(alice, userInput);
      alice.prevSymbol = mainScreen[alice.y][alice.x];
      mainScreen[alice.y][alice.x] = alice.symbol;
    }

    // dig
    if(userInput == 'd' || userInput == 'D')
    {
      dig(alice, mainScreen);
      balance -= 1;
    }

    // plant
    if(userInput == 'P' || userInput == 'p')
    {
      alice = plant(alice, mainScreen);
    }

    // harvest
    if(userInput == 'H' || userInput == 'h')
    {
      int original = numItems;
      numItems = harvest(alice, mainScreen, inventory, original);
      if(original != numItems)
      {
        alice.prevSymbol = ' ';
      }
    }

    // market
    if(userInput == 'M' || userInput == 'm')
    {
      printMarketBanner();
      int numTransferred = addItemsToMarket(inventory, market, numItems, numMarketItems);
      numItems -= numTransferred;
      numMarketItems += numTransferred;
    }

    // Print Items
    printIntro();
    printMainScreen(mainScreen);
    printInventory(inventory, numItems);
    printLegend(balance);

    // Selling notification!
    if(numMarketItems > 0)
    {
      int random = rand() % 15;
      if(random == 7)
      {
        cout << "!!! Item sold: " << market[numMarketItems-1].name << " !!!" << endl;
        balance += market[numMarketItems-1].price;
        numMarketItems--;
      }
    }

    cout << KNRM << "> ";
    cin >> userInput;
  }

  mainScreen[alice.y][alice.x] = alice.prevSymbol;
  saveMainScreen(mainScreen);
  saveSessionData(balance, inventory, market, numItems, numMarketItems);
  cout << endl << "Data saved." << endl;
  cout << "Thanks for playing!" << endl;
}
