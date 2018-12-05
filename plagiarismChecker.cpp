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
//#include "fileopen.cpp"
#include <locale>

using namespace std;

string chunkFormatter(vector<string> v);

int getdir (string dir, vector<string> &files)
{
    ifstream inFile;
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << dir << endl;
        return errno;
    }

    while ((dirp = readdir(dp)) != NULL) {
        if (strcmp(dirp->d_name, ".") != 0 && strcmp(dirp->d_name, "..") !=0) {
            inFile.open(dirp->d_name);
            files.push_back(string(dirp->d_name));
        }
    }
    closedir(dp);
    return 0;
}

string chunkFormatter(string key){

    std::locale loc;
    for(std::string::size_type i = 0; i < key.length(); i++) {   //change to lowercase
        key[i] = std::tolower(key[i], loc);
    }

    for (int j = 0, length =  key.size(); j < length; j ++){        //remove punctuation
        if (key[j]  ==  46 || key[j] == 45 || key[j] == 44 || key [j] == 96 || key[j] == 63){
            key.erase(j--, 1);
            length = key.size();
        }
    }
    cout << key << endl;
    return key;

}

int main(int argc, char *argv[]) {

    string dir = string("C:\\Users\\esarmah100\\EE312\\GitHub\\EE312proj8_Cheaters-exclamation-\\sm_doc_set");
    vector <string> files = vector<string>();

    getdir(dir, files);

    for (unsigned int i = 0; i < files.size(); i++) {
        cout << i << files[i] << endl;
    }


    //for arg stuff?

    ifstream inFile;

    //int n  = atoi(argv[2]);     //n is number of word chunks specified by user
    int n = 6;

    //vector <string> wordChunks;
    queue<string> wordChunks;
    queue<string> currentChunk;
    string word;
    int count = 0;


    for (unsigned int i = 0; i < 3; i++) {
        //string fileName = "sm_doc_set\\" + files[i];         //change to argv[1]
        string fileName =
                "C:\\Users\\esarmah100\\EE312\\GitHub\\EE312proj8_Cheaters-exclamation-\\sm_doc_set\\" + files[i];
        inFile.open(fileName.c_str());
        if (!inFile)
            cout << "error opening the file" << endl;
        else
            /*
            while (inFile >> word) {
                if (count == n)
                    break;
                wordChunks.push(word);
                count++;
                */
           for (int j = 0; j < n; j++) {
               if (inFile >> word) {
                   wordChunks.push(word);
                   currentChunk.push(word);
                   count++;
               }
           }

        string key;
        for (int j = 0; j < count; j++) {
            key += wordChunks.front();   //concatenate
            wordChunks.pop();
        }
            key = chunkFormatter(key);


        if (inFile >> word) {
            currentChunk.push(word);
            currentChunk.pop();
            wordChunks = currentChunk;
            key = "";

            for (int j = 0; j < count; j++) {

                key += wordChunks.front();   //concatenate
                wordChunks.pop();
            }
            key = chunkFormatter(key);

        }

    }

        inFile.close();

}






