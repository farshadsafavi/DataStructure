#include "Sparse.h"
#include<Element.h>
Sparse::Sparse(int row, int col, int num)
{
    this->row = row;
    this->col = col;
    this->num = num;
    this->e = new Element[num];
}

Sparse::~Sparse()
{
    delete []this->e;
}

void Sparse::Create(){
    int r, c, v;
    int cnt= 0;
    for(int i = 0; i < this->num; i++){
        cout <<"Please enter number i, j, val:";
        cin >> r >> c >> v;
        this->e[cnt++] = Element(r, c, v);
    }
}

istream& operator>>(istream &i, Sparse &s){
    int r, c, v;
    int cnt= 0;
    for(int i = 0; i < s.num; i++){
        cout <<"Please enter number i, j, val:";
        cin >> r >> c >> v;
        s.e[cnt++] = Element(r, c, v);
    }
    return i;
}

ostream& operator<<(ostream &o, Sparse &s){
    int c = 0;
    for(int i = 0; i < s.row; i++){
        for(int j = 0; j < s.col; j++){
            if(s.e[c].get_i() == i && s.e[c].get_j() == j){
                o <<s.e[c++].get_val() << " ";
            } else{
                o <<"0 ";
            }
        }
        cout <<endl;
    }
    cout <<endl;
    return o;
}

Sparse operator+(Sparse &s1, Sparse &s2){
    Sparse res(s1.row, s1.col, s1.num + s2.num);
    int cnt = 0;
    if(s1.col != s2.col || s1.row != s2.row){
        return res;
    }
    res.e = new Element[res.num];
    int i = 0, j = 0;

    while(i < s1.num && j <s2.num){
        if(s1.e[i].get_i() <s2.e[j].get_i()){
            res.e[cnt++] = s1.e[i++];
        } else if(s1.e[i].get_i() > s2.e[j].get_i()){
            res.e[cnt++] = s2.e[j++];
        } else{
            if(s1.e[i].get_j() < s2.e[j].get_j()){
                res.e[cnt++] = s1.e[i++];
            } else if(s1.e[i].get_j() > s2.e[j].get_j()){
                res.e[cnt++] = s2.e[j++];
            } else{
                res.e[cnt] = s2.e[j];
                res.e[cnt++].set_val(s1.e[i].get_val() + s2.e[j].get_val());
                i++;
                j++;
            }
        }
    }
    while(i < s1.num){
        res.e[cnt++] = s1.e[i++];
    }
    while(j < s2.num){
        res.e[cnt++] = s2.e[j++];
    }

    res.num = cnt;
    return res;
}


