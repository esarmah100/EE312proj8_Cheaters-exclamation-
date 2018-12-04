#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <string.h>


using namespace std;

/*function... might want it in some class?*/
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

int main()
{
    string dir = string("C:\\Users\\esarmah100\\EE312\\GitHub\\EE312proj8_Cheaters-exclamation-\\sm_doc_set");
    vector<string> files = vector<string>();

    getdir(dir,files);

    for (unsigned int i = 0;i < files.size();i++) {
        cout << i << files[i] << endl;
    }
    return 0;
}

