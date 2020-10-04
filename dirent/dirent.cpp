#include <iostream>
#include <dirent.h>

using namespace std;

int main()
{
    DIR *dr;
    dirent *en;
    dr = opendir("."); 
    if (dr)
    {
        while ((en = readdir(dr)) != NULL)
        {
            cout << en->d_name << endl;
        }
        closedir(dr);
    }
    return 0;
}