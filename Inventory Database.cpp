// S112 Kowata Inventory Database.cpp 

#include "Item.h"

//Global const-------------------------------------------------------------
const int CLOSE_OPTION = 9;

//Prototypes---------------------------------------------------------------
void showDatabase(vector<Item>& db);
void experiment01();
void experiment02();
int showMenu();
int findItem(vector<Item>& db, int key);
void addItemToDb(vector<Item>& db);
void saveDbToDisk(vector<Item>& db);
void retrieveDbFromDisk(vector<Item>& db);

void experiment03();


//-------------------------------------------------------------------------
int main()
{
    //experiment01();
    //experiment02();
    experiment03();

}

//-------------------------------------------------------------------------
void experiment03()
{
    Item i1({ 111, 10, 1.50 });
    cout << i1.stringify() << endl;

    Item i2({ 222, 20, 5.95 });
    cout << i2.stringify() << endl;

    Item* p1 = &i1;
    cout << p1->stringify() << endl;

    Item* p2 = new Item({ 333, 30, 9.95 });
    cout << p2->stringify() << endl;

    delete p2;
}
void experiment02()
{
    //expose the app's menu
    vector<Item> db;
    Item item;
    int pos = 0;
    int keyId;
    int option = 0;
    do
    {
        option = showMenu();
        if (option == 1)
            showDatabase(db);
        else if (option == 2)
        {
            cout << "Enter item ID: ";
            cin >> keyId;
            pos = findItem(db, keyId);
            if (pos == -1)
                cout << "ERROR - Invalid item ID - try again\n";
            else
                cout << db[pos].stringify() << endl;
        }

        else if (option == 3)
            addItemToDb(db);
        else if (option == 5)
            saveDbToDisk(db);
        else if (option == 6)
            retrieveDbFromDisk(db);
        else if (option == 7)
        {
            cout << "Enter item ID: ";
            cin >> keyId;
            pos = findItem(db, keyId);
            if (pos == -1)
                cout << "ERROR - Invalid item ID - try again\n";
            else
            {
                int newQty;
                cout << "Enter new qty: ";
                cin >> newQty;
                db[pos].qty = newQty;
                cout << db[pos].stringify() << endl;
            }
        }
        else if (option == 8)
        {
            cout << "Enter item ID: ";
            cin >> keyId;
            pos = findItem(db, keyId);
            if (pos == -1)
                cout << "ERROR - Invalid item ID - try again\n";
            else
            {
                int newPrice;
                cout << "Enter new price: ";
                cin >> newPrice;
                db[pos].price = newPrice;
                cout << db[pos].stringify() << endl;
            }
        }

        //TODO - complete the menu
        cout << "\nDo you want to continue [y/n]: ";
        char response;
        cin >> response;
        if (response == 'n')break;
        system("cls");
    } while (option != CLOSE_OPTION);
}
//----------------------------------------------------------------------------
int showMenu()
{
    int selectedOption = 0;
    do
    {
        cout << endl;
        cout << "Database Menu - Selected Option \n";
        cout << "--------------------------------\n";
        cout << " 1. ShowDatabase                \n";
        cout << " 2. Find Item                   \n";
        cout << " 3. Add Item                    \n";
        cout << " 4. Remove Item                 \n";
        cout << " 5. Save DB to disk             \n";
        cout << " 6. Retrieve DB from disk.       \n";
        cout << " 7. Modify Item's qty.          \n";
        cout << " 8. Modify Item's price.        \n";
        cout << " 9. Close DB                    \n";
        cout << "--------------------------------\n";
        cout << " Enter option: ";
        cin >> selectedOption;
        if (selectedOption<1 or selectedOption > CLOSE_OPTION)
        {
            cout << " >>> Invalid choice - Try again \n";
        }
    } while (selectedOption<1 or selectedOption > CLOSE_OPTION);
    return selectedOption;
}

int findItem(vector<Item>& db, int key)
{
    int pos = 0;
    for (pos = 0; pos < db.size(); pos++)
    {
        if (db[pos].id == key) return pos;
    }
    return -1;
}

void addItemToDb(vector<Item>& db)
{
    Item item;
    cout << endl;
    cout << "Enter ID:      "; cin >> item.id;
    cout << "Enter QTY:     "; cin >> item.qty;
    cout << "Enter PRICE:   "; cin >> item.price;
    db.push_back(item);
}

//----------------------------------------------------------------------------
void experiment01()
{
    Item i1({ 111, 10, 100.00 });
    Item i2({ 222, 20, 200.00 });
    Item i3({ 333, 30, 300.00 });

    vector <Item> db {i1, i2, i3};
    showDatabase(db);
    std::cout << "Hello World!\n";
}

void showDatabase(vector<Item>& db)
{
    cout << "\nInventory Database - Size: " << db.size() << endl;

    for (int i = 0; i < db.size(); i++)
    {
        cout << db[i].stringify() << endl;
    }
}
//----------------------------------------------------------------------------
void saveDbToDisk(vector<Item>& db) 
{
    ofstream myfile("c:/users/mkowata/temp/inventoryDb.txt");
    if (!myfile)
    {
        cout << "Error - file not found\n";
        exit(101);
    }
    for (int i = 0; i < db.size(); i++)
    {
        myfile << db[i].id << endl;
        myfile << db[i].price << endl;
        myfile << db[i].qty << endl;
    }
    myfile.close();
}


void retrieveDbFromDisk(vector<Item>& db)
{
    ifstream myfile("c:/users/mkowata/temp/inventorydb.txt");
    if (!myfile)
    {
        cout << "ERROR - File not found\n";
        exit(2);
    }
    db.clear();
    Item item;
    while (myfile >> item.id)
    {
        myfile >> item.qty;
        myfile >> item.price;
        db.push_back(item);
    }
    myfile.close();
    cout << "Database re-constructed\n";
}
