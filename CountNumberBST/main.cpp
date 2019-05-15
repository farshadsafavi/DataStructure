#include <iostream>

using namespace std;

int countBST(int n){
    int res = 0;
    if(n == 0 || n == 1){
        return 1;
    }
    for(int i = 0; i < n; i++){
        res += countBST(i)*countBST(n - i - 1);
    }

    return res;
}

int main()
{
    cout << "Give number of node count number of BST:" << endl;
    cout <<"Catalan arr[0]:" << countBST(0) << endl;
    cout <<"Catalan arr[1]:" << countBST(1) << endl;
    cout <<"Catalan arr[2]:" << countBST(2) << endl;
    cout <<"Catalan arr[3]:" << countBST(3) << endl;
    cout <<"Catalan arr[4]:" << countBST(4) << endl;
    return 0;
}
