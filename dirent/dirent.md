# dirent.h

## Installation

Déplacer le fichier dirent.h dans le dossier :

```vendors\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\include```

## Utilisation

Dans le fichier dirent.cpp, vous trouverez un exemple d'implémentation :

```cpp
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
```