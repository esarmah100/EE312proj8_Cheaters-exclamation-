//
// Created by Devina Parihar on 12/3/2018.
//

#ifndef EE312PROJ8_CHEATERS_EXCLAMATION_HASHMAP_H
#define EE312PROJ8_CHEATERS_EXCLAMATION_HASHMAP_H

#include <iostream>
#include <string>
#include <vector>
#include <HashNode.h>

using namespace std;

class HashMap
{
private:

    HashNode **arr;  //**arr //2D array of hash elements
    int cap;

    int size; //current size

    HashNode *p1; //dummy node???

public:
    HashMap(int cap, int size){
        this->cap = cap;
        this->size  = size;
        arr = new HashNode *[cap];

        //initialising elements to NULL
        for(int i = 0; i < cap; i++)
            arr[i] = NULL;

        p1 = new HashNode(-1, -1);  //dummy hashNode
    }

    int hashFunc(int key){

        return key % cap;
    }

    void insertNode(int key, int value){
        HashNode *temp = new HashNode(key, value);

        //use hash function to get index for key
        int hashIndex = hashFunc(key);

        //find next free space
        while(arr[hashIndex] !=NULL && arr[hashIndex]->key != key
                && arr[hashIndex]->key !=-1)
        {
            hashIndex++;
            hashIndex = hashIndex%cap;  //??
        }

        //adding a node, increase current size by one
        if(arr[hashIndex] == NULL || arr[hashIndex]->key == -1) {
            size++;
        }
        arr[hashIndex] = temp;

    }

    int deleteNode(int key){
        int hashIndex = hashFunc(key);

        //finding the node with given key
        while(arr[hashIndex] != NULL)
        {
            //if node found
            if(arr[hashIndex]->key == key)
            {
                HashNode *temp = arr[hashIndex];

                //Insert dummy node here for further use
                arr[hashIndex] = p1;

                // Reduce size
                size--;
                return temp->value;
            }
            hashIndex++;
            hashIndex %= cap;

        }

        return NULL;
    }

    int findIndexVal(int key){
        int hashIndex = hashFunc(key);
        int count = 0;
        while(arr[hashIndex] !=NULL){
            int count = 0;
            if(count++>cap)     //out of bounds
                return NULL;
            if(arr[hashIndex]->key == key)  //index found
                return arr[hashIndex]->value;
            hashIndex++;
            hashIndex = hashIndex % cap;
        }
        return NULL;        //not found
    }

    int mapSize(){
        return size;
    }

    bool isEmpty(){
        return(size == 0);
    }

    void display(){

    }







};


#endif //EE312PROJ8_CHEATERS_EXCLAMATION_HASHMAP_H
