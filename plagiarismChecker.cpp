//
// Created by Devina Parihar on 12/3/2018.
//

#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <string.h>
#include <queue>
#include "fileopen.cpp"

using namespace std;


int main(int argc, char *argv[]){


    //opening files/////

    string dir = string("sm_doc_set");
    vector<string> files = vector<string>();

    getdir(dir,files);

    for (unsigned int i = 0;i < files.size();i++) {
        cout << i << files[i] << endl;
    }

    ifstream inFile;
    string store;
    vector<string> word;

    for(unsigned int i = 0; i< 3; i++){
        string fileName = "sm_doc_set/" + files[i];
        inFile.open(fileName);
        if(!inFile)
            cout << "error opening the file" << endl;

    }

    while(inFile >> store){
        word.push_back(store);
    }

    inFile.close();



    int n  = atoi(argv[2]);     //n is number of word chunks specified by user

    queue <string> wordChunks;


}

int hash();

