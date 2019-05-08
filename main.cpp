#include <bits/stdc++.h>
#include <iostream>
#include "priorityQueue.h"

using namespace std;

bool func(int a, int b) {
    return a == b;
}

int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
    int n;
    cin >> n;
    auto stocks = new priorityQueue;
    for(int i = 0; i < n; i++){
        int operation, price;
        string stock;
        cin >> operation;
        if(operation == 1){
            cin >> stock;
            cin >> price;
            stocks->insert(make_pair(price, stock));
        }else if(operation == 2){
            cin >> stock;
            cin >> price;

        }else{
            cout << stocks->remove().second << " "<< i+1 << endl;
        }
    }

    return 0;
}