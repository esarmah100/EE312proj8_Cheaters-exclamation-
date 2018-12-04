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
#include <locale>

using namespace std;

string chunkFormatter(vector<string> v);


int main(int argc, char *argv[]){

    string dir = string("C:\\Users\\Devina Parihar\\Documents\\GitHub\\EE312proj8_Cheaters-exclamation-\\sm_doc_set");
    vector<string> files = vector<string>();

    getdir(dir,files);

    for (unsigned int i = 0;i < files.size();i++) {
        cout << i << files[i] << endl;
    }


    //for arg stuff?

    ifstream inFile;

    int n  = atoi(argv[2]);     //n is number of word chunks specified by user

    vector <string> wordChunks;
    string word;
    int count = 0;


    for(unsigned int i = 0; i< 3; i++){
        string fileName = "sm_doc_set/" + files[i];         //change to argv[1]
        inFile.open(fileName.c_str());
        if(!inFile)
            cout << "error opening the file" << endl;
        else
            while(inFile >> word)
            {
                if(count == n)
                    break;
                wordChunks.push_back(word);
                count++;
            }

            string key = chunkFormatter(wordChunks);



    }

    inFile.close();

}

string chunkFormatter(vector<string> v){

    string s;
    for(int i = 0; i < v.size(); i++){
        s = s + v.back();                   //concatenate
        v.pop_back();
    }
    locale loc;
    for(int i = 0; i < v.size(); i++)       //change to lowercase
        tolower(v[i], loc);


}

