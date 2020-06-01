#include "actions.h"
using namespace std;

void printMarketBanner()
{
  ifstream market;
  market.open("marketplace.txt");
  string line;
  while(getline(market, line))
  {
    cout << line << endl;
  }
  market.close();
}

// TODO: change to return dimensions
void readMainScreen(char arr[][67])
{
  int height = 0;
  ifstream readstream;
  readstream.open("mainScreen.txt");
  string line;
  while(getline(readstream, line))
  {
    for(int i = 0; i < line.length(); i++)
    {
      arr[height][i] = line[i];
    }
    height++;
  }
}

int readBalance()
{
  ifstream readBalance;
  readBalance.open("sessionData.txt");
  string line;
  getline(readBalance, line);
  readBalance.close();
  return stoi(line);
}

int readInventory(Crop inventory[])
{
  ifstream readInv;
  readInv.open("sessionData.txt");
  string line;
  int invItems = 0;
  int lineNum = 0;
  while(getline(readInv, line))
  {
    if(lineNum == 1)
    {
      if(line == "")
      {
        return 0;
      }
      for(int i = 0; i < line.length(); i++)
      {
        if(line[i] != ',')
        {
          Crop newCrop;
          newCrop.symbol = line[i];
          if(newCrop.symbol == 'T')
          {
            newCrop.name = "Tomato";
            newCrop.price = 1;
          }
          else if(newCrop.symbol == 'C')
          {
            newCrop.name = "Corn";
            newCrop.price = 2;
          }
          else if(newCrop.symbol == 'G')
          {
            newCrop.name = "Grapes";
            newCrop.price = 3;
          }
          else if(newCrop.symbol == 'L')
          {
            newCrop.name = "Lilies";
            newCrop.price = 4;
          }
          inventory[invItems] = newCrop;
          invItems++;
        }
      }
      break;
    }
    lineNum++;
  }
  readInv.close();
  return invItems;
}

int readMarket(Crop market[])
{
  ifstream readMar;
  readMar.open("sessionData.txt");
  string line;
  int marItems = 0;
  int lineNum = 0;
  while(getline(readMar, line))
  {
    if(lineNum == 2)
    {
      if(line == "")
      {
        return 0;
      }
      for(int i = 0; i < line.length(); i++)
      {
        if(line[i] != ',')
        {
          Crop newCrop;
          newCrop.symbol = line[i];
          if(newCrop.symbol == 'T')
          {
            newCrop.name = "Tomato";
            newCrop.price = 1;
          }
          else if(newCrop.symbol == 'C')
          {
            newCrop.name = "Corn";
            newCrop.price = 2;
          }
          else if(newCrop.symbol == 'G')
          {
            newCrop.name = "Grapes";
            newCrop.price = 3;
          }
          else if(newCrop.symbol == 'L')
          {
            newCrop.name = "Lilies";
            newCrop.price = 4;
          }
          market[marItems] = newCrop;
          marItems++;
        }
      }
      break;
    }
    lineNum++;
  }
  readMar.close();
  return marItems;
}

void printMainScreen(char arr[][67])
{
  int height = 15;
  int width = 67;
  for(int i = 0; i < height; i++)
  {
    for(int j = 0; j < width; j++)
    {
      if(arr[i][j] == 'T')
      {
        cout << KRED << arr[i][j] << KNRM;
      }
      else if(arr[i][j] == 'C')
      {
        cout << KYEL << arr[i][j] << KNRM;
      }
      else if(arr[i][j] == 'G')
      {
        cout << KMAG << arr[i][j] << KNRM;
      }
      else if(arr[i][j] == 'L')
      {
        cout << KCYN << arr[i][j] << KNRM;
      }
      else
      {
        cout << arr[i][j];
      }
    }
    cout << endl;
  }
}

void saveMainScreen(char arr[][67])
{
  ofstream writestream;
  writestream.open("mainScreen.txt");
  int height = 15;
  int width = 67;
  for(int i = 0; i < height; i++)
  {
    for(int j = 0; j < width; j++)
    {
      writestream << arr[i][j];
  }
  writestream << endl;
  }
}

void saveSessionData(int balance, Crop inventory[], Crop market[], int numItems, int numMarketItems)
{
  ofstream sessionSave;
  sessionSave.open("sessionData.txt");
  sessionSave << balance << endl;
  for(int i = 0; i < numItems; i++)
  {
    sessionSave << inventory[i].symbol << ',';
  }
  sessionSave << endl;
  for(int i = 0; i < numMarketItems; i++)
  {
    sessionSave << market[i].symbol << ',';
  }
  sessionSave << endl;
  sessionSave.close();
}

void printInventory(Crop inventory[], int numItems)
{
  cout << "Inventory: [ ";
  for(int i = 0; i < numItems; i++)
  {
    if(inventory[i].symbol == 'T')
    {
      cout << KRED << inventory[i].symbol << " ";
    }
    else if(inventory[i].symbol == 'G')
    {
      cout << KMAG << inventory[i].symbol << " ";
    }
    else if(inventory[i].symbol == 'L')
    {
      cout << KCYN << inventory[i].symbol << " ";
    }
    else if(inventory[i].symbol == 'C')
    {
      cout << KYEL << inventory[i].symbol << " ";
    }
  }
  cout << KNRM << "]" << endl;
}

void printMarket(Crop market[], int numItems)
{
  cout << "Market: [ ";
  for(int i = 0; i < numItems; i++)
  {
    if(market[i].symbol == 'T')
    {
      cout << KRED << market[i].symbol << " ";
    }
    else if(market[i].symbol == 'G')
    {
      cout << KMAG << market[i].symbol << " ";
    }
    else if(market[i].symbol == 'L')
    {
      cout << KCYN << market[i].symbol << " ";
    }
    else if(market[i].symbol == 'C')
    {
      cout << KYEL << market[i].symbol << " ";
    }
  }
  cout << KNRM << "]" << endl;
}

void printLegend(int balance)
{
  cout << "Balance: $" << balance << endl;
  cout << "D: dig     H: harvest    P: plant    M: market    Q: save & quit"<< endl;
}

void printIntro()
{
  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ALICE GREENFINGERS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
  cout << "j = left, i = up, k = down, l = right" << endl;
}

Alice moveAlice(Alice a, char dir)
{
  if(dir == 'j') // Left
  {
    a.x -= 1;
  }
  else if(dir == 'i') // Up
  {
    a.y -= 1;
  }
  else if(dir == 'l') // Right
  {
    a.x += 1;
  }
  else if(dir == 'k') // Down
  {
    a.y += 1;
  }
  else
  {
    cout << "ERROR: couldn't move" << endl;
  }
  return a;
}

void dig(Alice a, char arr[][67])
{
  if(arr[a.y][a.x-1] == '[' && arr[a.y][a.x+1] == ']')
  {
    arr[a.y][a.x-1] = ' ';
    arr[a.y][a.x+1] = ' ';
    a.prevSymbol = ' ';
  }
  else
  {
    arr[a.y][a.x-1] = '[';
    arr[a.y][a.x+1] = ']';
  }
}

// TODO: make updatable
void listSeeds()
{
  cout << "T = Tomatoes" << endl;
  cout << "C = Corn" << endl;
  cout << "G = Grapes" << endl;
  cout << "L = Lilies" << endl;
}

Alice plant(Alice a, char arr[][67])
{
  // Check if at a hole
  if(arr[a.y][a.x-1] != '[' || arr[a.y][a.x+1] != ']')
  {
    cout << "Crops must be grown in a patch! Use 'dig' to make one." << endl;
    return a;
  }
  listSeeds();
  char seed;
  cout << "Which seed do you want to use?" << endl;
  cout << "> ";
  cin >> seed;
  if(seed == 'T' || seed == 't')
  {
    a.prevSymbol = 'T';
    arr[a.y][a.x] = 'T';
  }
  else if(seed == 'C' || seed == 'c')
  {
    a.prevSymbol = 'C';
    arr[a.y][a.x] = 'C';
  }
  else if(seed == 'G' || seed == 'g')
  {
    a.prevSymbol = 'G';
    arr[a.y][a.x] = 'G';
  }
  else if(seed == 'L' || seed == 'l')
  {
    a.prevSymbol = 'L';
    arr[a.y][a.x] = 'L';
  }
  else
  {
    cout << "ERROR: could not plant crop!" << endl;
  }
  return a;
}

int harvest(Alice a, char arr[][67], Crop inventory[], int numItems)
{
  if(numItems == 10)
  {
    cout << "Cannot add item -- inventory full!" << endl;
  }
  else
  {
    Crop newCrop;
    newCrop.symbol = a.prevSymbol;
    if(newCrop.symbol == 'T')
    {
      newCrop.name = "Tomato";
      newCrop.price = 1;
    }
    else if(newCrop.symbol == 'C')
    {
      newCrop.name = "Corn";
      newCrop.price = 2;
    }
    else if(newCrop.symbol == 'G')
    {
      newCrop.name = "Grapes";
      newCrop.price = 3;
    }
    else if(newCrop.symbol == 'L')
    {
      newCrop.name = "Lilies";
      newCrop.price = 4;
    }
    else
    {
      cout << "ERROR: no crop detected" << endl;
      return numItems;
    }

    inventory[numItems] = newCrop;
    numItems++;
    arr[a.y][a.x] = ' ';
  }
  return numItems;
}

int isInList(Crop items[], int numItems, char toFind)
{
  for(int i = 0; i < numItems; i++)
  {
    if(items[i].symbol == toFind)
    {
      return i;
    }
  }
  return -1;
}

int addItemsToMarket(Crop inventory[], Crop market[], int numItems, int numMarketItems)
{
  cout << "Enter an item to add to market, or click V to view inventory/market." << endl;
  cout << "Press Q to exit: " << endl;
  int numTransferred = 0;
  char user = ' ';
  while(user != 'Q' && user != 'q')
  {
    if(user == 'V' || user == 'v')
    {
      printInventory(inventory, numItems);
      printMarket(market, numMarketItems);
    }
    // Check if the item exists in the inventory
    else if(numItems == 0)
    {
      cout << "No items to transfer." << endl;
    }
    else if(numMarketItems == 20) // Market capacity
    {
      cout << "Your booth is full at the market! No items transferred." << endl;
    }
    else if(user != ' ' && isInList(inventory, numItems, toupper(user)) < 0)
    {
      cout << "You don't have this item in your inventory!" << endl;
    }
    else if(user != ' ')
    {
      int index = isInList(inventory, numItems, toupper(user));
      market[numMarketItems] = inventory[index];
      // Delete from inventory
      for(int i = index; i < numItems-1; i++)
      {
        inventory[i] = inventory[i+1];
      }
      numItems--;
      numMarketItems++;
      // Show Change
      cout << "Successful Transfer!" << endl;
      printInventory(inventory, numItems);
      printMarket(market, numMarketItems);
      numTransferred++;
    }
    cout << "> ";
    cin >> user;
  }

  return numTransferred;
}
