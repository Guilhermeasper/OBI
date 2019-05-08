#include <bits/stdc++.h>
#include <iostream>

using namespace std;

vector<vector<int>> row(vector<vector<int>> matrix, int a, int b, int size){
    for(int i = 0; i < size; i++){
        swap(matrix[a-1][i], matrix[b-1][i]);
    }
    return matrix;
}

vector<vector<int>> col(vector<vector<int>> matrix, int a, int b, int size){
    for(int i = 0; i < size; i++){
        swap(matrix[i][a-1], matrix[i][b-1]);
    }
    return matrix;
}

vector<vector<int>> inc(vector<vector<int>> matrix, int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            matrix[i][j] = (matrix[i][j]+1)%10;
        }
    }
    return matrix;
}

vector<vector<int>> dec(vector<vector<int>> matrix, int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            matrix[i][j] = (matrix[i][j]-1)%10;
        }
    }
    return matrix;
}

vector<vector<int>> transpose(vector<vector<int>> matrix, int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    return matrix;
}


int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cout << "Case #" << i+1 << endl;
        int size;
        cin >> size;
        vector<vector<int>> matrix (size);
        for(int j = 0; j < size; j++){
            matrix[j].reserve(size);
        }
        for(int j = 0; j < size; j++){
            string line;
            cin >> line;
            for(int k = 0; k < size; k++){
                cout << (char)line[k];
                matrix[i][j] = (char)line[k];
            }
        }
        int ops;
        cin >> ops;
        for(int j = 0; j < ops; j++){
            string operation;
            cin >> operation;
            int a, b;
            if(operation == "row"){
                cin >> a;
                cin >> b;
                matrix = row(matrix, a, b, size);
            }else if(operation == "col"){
                cin >> a;
                cin >> b;
                matrix = col(matrix, a, b, size);
            }else if(operation == "inc"){
                matrix = inc(matrix, size);
            }else if(operation == "dec"){
                matrix = dec(matrix, size);
            }else{
                matrix = transpose(matrix, size);
            }
        }
        for(int j = 0; j < size; j++){
            for(int k = 0; k < size; k++){
                cout << matrix[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
