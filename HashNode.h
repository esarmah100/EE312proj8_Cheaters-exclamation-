//
// Created by Devina Parihar on 12/3/2018.
//

#ifndef EE312PROJ8_CHEATERS_EXCLAMATION_HASHNODE_H
#define EE312PROJ8_CHEATERS_EXCLAMATION_HASHNODE_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class HashNode
{
public:
    int value;
    int key;

    HashNode(int key, int value)
    {
        this->value = value;
        this->key = key;
    }


};



#endif //EE312PROJ8_CHEATERS_EXCLAMATION_HASHNODE_H
