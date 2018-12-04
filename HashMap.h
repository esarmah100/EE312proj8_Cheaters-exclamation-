//
// Created by Devina Parihar on 12/3/2018.
//

#ifndef EE312PROJ8_CHEATERS_EXCLAMATION_HASHMAP_H
#define EE312PROJ8_CHEATERS_EXCLAMATION_HASHMAP_H

#include <iostream>
#include <string>
#include <vector>
#include <HashNode.h>
#include <cmath>

using namespace std;

class HashMap
{
private:

    HashNode **arr;  //**arr // array of linked lists of hash elements
    string key;
    int tableSize;

    int size; //current size


public:
    HashMap(string key){
        this->tableSize = 24103;            //big prime number for tableSize //prime aournd 24000
        this->size  = 0;
        this->key = key;

        arr = new HashNode *[tableSize];

        //initialising elements to NULL
        for(int i = 0; i < tableSize; i++)
            arr[i] = NULL;

    }

    unsigned long int hashFunc(const string & key, int tableSize ){

        int keySize = key.size();
        long unsigned int sum = 0;
        for(int i = 0; i < keySize -1; i++){
            if(keySize > 28){
                sum = sum + key[keySize-i-1]*(pow(11, i));

            }
            else
            sum = sum + key[keySize-i-1]*(pow(37, i));
        }

        sum = sum % tableSize;

        return sum;

    }


    void insertNode(string key, int fileIndex){
        HashNode *temp = new HashNode();


        //use hash function to get index for key
        int hashIndex = hashFunc(key, tableSize);

        temp->value = fileIndex;
        temp->next = arr[hashIndex];

        arr[hashIndex] = temp;

        delete(temp);


    }

/*

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

*/



};


#endif //EE312PROJ8_CHEATERS_EXCLAMATION_HASHMAP_H
