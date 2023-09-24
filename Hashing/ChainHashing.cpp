#include <iostream>

#include <list>

using namespace std;

class MyHash
{
    int BUCKET;
    list<int> *table;

    public : 

    MyHash(int size) : BUCKET(size)
    {
        table = new list<int>[BUCKET];
        cout << "Hashing has stored " << endl;
    }

    void insertKey(int n);
    void searchKey(int key);
    void deleteKey(int key);
    void removeKey(int key); // Same as deleteKey;
    void printHash();
};

void MyHash::insertKey(int n)
{
    int index = n%BUCKET;

    table[index].push_back(n);
}

void MyHash::searchKey(int key)
{
    int index = key%BUCKET;
    list<int>::iterator it;
   for(it = table[index].begin(); it!= table[index].end(); it++)
   {
      if(*it == key)
      {
        cout << "Found in list " << index << endl;
        return;
      }
   }

   cout << "Not found" << endl;
}


void MyHash::deleteKey(int key)
{
    int index = key%BUCKET;
    list<int>::iterator it;
   for(it = table[index].begin(); it!= table[index].end(); it++)
   {
      if(*it == key)
      {
        break;
      }
   }

   if(it != table[index].end())
   {
    table[index].erase(it);
   }
}

void MyHash::removeKey(int key)
{
    int index = key%BUCKET;

    table[index].remove(key);
}

void MyHash::printHash()
{

    list<int>::iterator it;
    for(int i=0;i<BUCKET;i++)
    {
        
        for(auto x : table[i])
        {
          cout << "-->" << x;
        }
        cout << endl;
    }
}

int main()
{
   
   MyHash table1(7);

   table1.insertKey(1);
   table1.insertKey(2);
   table1.insertKey(8);
   table1.insertKey(7);
   table1.insertKey(1);
   
   table1.printHash();

  table1.removeKey(1);

   table1.printHash();




}