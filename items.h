#include <iostream>
using namespace std;

// Colors
#define KNRM "\x1B[0m"  // Normal, default
#define KRED "\x1B[31m" // Red, etc.
#define KGRN "\x1B[32m"
#define KYEL "\x1B[33m"
#define KBLU "\x1B[34m" // Blue
#define KMAG "\x1B[35m"
#define KCYN "\x1B[36m"
#define KWHT "\x1B[37m"

struct Crop
{
  string name;
  char symbol;
  int price;
};

struct SeedBag
{
  int numSeeds;
  Crop thisCrop;
};

struct Box
{
  int numItems;
  Crop thisCrop;
};

struct Alice
{
  char prevSymbol;
  char symbol;
  int x;
  int y;
};
