#include <iostream>
#include<HashTableLL.h>
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    int table[8] ={1, 101, 12, 13, 111, 19, 20, 21};
    HashTableLL ht(10);
    for(int i =0 ; i < 5; i++){
        ht.HashInsert(table[i]);
    }
    ht.Display();
    cout <<"===============" << endl;
    for(int i =0 ; i < 8; i++){
        if(ht.Search(table[i]))
            cout<<table[i]<<" exist!"<<endl;
        else
            cout <<"Not exist!" << endl;
    }
    ht.Delete(101);
    ht.Display();

    return 0;
}
