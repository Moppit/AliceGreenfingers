#include <iostream>
#include <fstream>
#include "items.h"

void printMarketBanner();
void readMainScreen(char arr[][67]);
int readBalance();
int readInventory(Crop inventory[]);
int readMarket(Crop market[]);
void printMainScreen(char arr[][67]);
void saveMainScreen(char arr[][67]);
void saveSessionData(int balance, Crop inventory[], Crop market[], int numItems, int numMarketItems);
void printInventory(Crop inventory[], int numItems);
void printMarket(Crop market[], int numItems);
void printLegend(int balance);
void printIntro();
Alice moveAlice(Alice a, char dir);
void dig(Alice a, char arr[][67]);
Alice plant(Alice a, char arr[][67]);
int harvest(Alice a, char arr[][67], Crop inventory[], int numItems);
int addItemsToMarket(Crop inventory[], Crop market[], int numItems, int numMarketItems);
