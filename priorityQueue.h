//
// Created by guilherme on 24/04/19.
//

#ifndef UNTITLED1_PRIORITYQUEUE_H
#define UNTITLED1_PRIORITYQUEUE_H

#include <iostream>
#include <vector>

using namespace std;

class priorityQueue {
private:
    vector<pair<int, string>> queue;
    long size;
public:
    priorityQueue() {
        pair<int, string> temp;
        queue.push_back(temp);
        this->size = 0;
    }

    void change(string a, int b){
        for(int i = 1; i <= size; i++){
            if(queue[i].second == a){
                queue[i].first = b;
            }
        }
    }

    void heapfyInsert() {
        bool heap = false;
        long pos = size;
        while (!heap && pos > 1) {
            if (queue[pos].first < queue[pos / 2].first) {
                heap = true;
            } else {
                pair<int, string> aux = queue[pos];
                queue[pos] = queue[pos / 2];
                queue[pos / 2] = aux;
                pos = pos / 2;
            }
        }
    }

    void insert(const pair<int, string>& v) {
        queue.push_back(v);
        size++;
        heapfyInsert();
    }

    void heaaap(){

    }

    void heapfyRemove() {
        bool heap = false;
        int pos = 1;
        int maxPos;
        while(!heap && pos < size) {
            if (pos * 2 <= size && queue[2 * pos].first > queue[pos].first && queue[2 * pos].first < queue[2 * pos + 1].first) {
                maxPos = 2 * pos;
            }else if(pos * 2 + 1 <= size && queue[2 * pos + 1].first < queue[pos].first){
                maxPos = 2*pos+1;
            }else{
                maxPos = pos;
            }
            if(maxPos != pos) {
                pair<int, string> aux = queue[pos];
                queue[pos] = queue[maxPos];
                queue[maxPos] = aux;
                pos = maxPos;
            }else{
                heap = true;
            }
        }
    }

    pair<int, string> remove() {
        pair<int, string> max = queue[1];
        queue[1] = queue[size];
//        cout << "fim anterior " << queue[size][1] << endl;
        queue.pop_back();
        size--;
//        if(size > 0){
//            cout << "novo fim " << queue[size][1] << endl;
//        }
        heapfyRemove();
        return max;
    }
};


#endif //UNTITLED1_PRIORITYQUEUE_H
