#include <iostream>
#include<HashTable.h>
using namespace std;

int main()
{
    cout << "Linear probing Hashing Technique!" << endl;
    HashTable ht(10);
    ht.Insert(5);
    ht.Insert(15);
    ht.Insert(25);
    ht.Insert(35);
    ht.Insert(45);

    ht.Display();
    int table[10] = {5, 15, 25, 35, 45, 55, 68, 19, 20};
    for(int i = 0; i < 10; i++){
        if (ht.Search(table[i]) != -1){
            cout <<"found" << endl;
        } else{
            cout <<"Not fond!" << endl;
        }
    }
    return 0;
}
