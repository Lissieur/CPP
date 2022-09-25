#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//? checkmotive est appelé lorsque l'on tombe 
//? sur le même charactère que le premier du motif lorsqu'on llit le fichier texte.
//? Si on retrouve le motif, la fonction retourne 1, sinon elle retourne 0.
int checkmotive(const char* line,char* motive, int pos)
{
    int delta = 1;
    while(line[pos+delta] != NULL && motive[delta] != NULL)
    {
        if(line[pos+delta] != motive[delta])
        {
            return 0;
        }
        delta++;
    }
    if(motive[delta]==NULL)
    {
        return 1;
    }
    return 0;
}

//? On ouvre un fichier texte afin d'y trouver un motif précisé dans les parametres de la fonction main.
//? Si le nombre d'argument n'est pas valide ou si on ne trouve pas le fichier texte, on renvoie 1 avec un 
//? message d'erreur approprié.
//? Si tout est bon, on compte le nombre de mots contenant le moif dans le fichier texte avant de retourner 0.

int main(int n, char* params[])
{
    if (n!= 3)
    {
        printf("Wrong number of arguments\n");
        return 1;
    }
    string line;
    const char* currl;
    ifstream myfile (params[1]);
    char* motive = params[2];
    int count = 0;
    if(myfile.is_open())
    {
        while(getline(myfile,line))
        {
            int pos=0, e = line.length();
            currl = line.c_str();
            while (pos< e)
            {
                if (currl[pos] == motive[0])
                {
                    int res;
                    res= checkmotive(currl, motive, pos);
                    count+=res;
                    if (res == 1)
                    {
                        while(currl[pos] != ' ' && currl[pos]!=NULL)
                        {
                            pos++;
                        }   
                    }
                    else
                    {
                        pos++;
                    }
                }
                else
                {
                    pos++;
                }
            }
        }
        myfile.close();
        printf("The file %s contains %d words containing the motive %s\n",params[1],count,params[2]);
    }
    else
    {
        printf("The file ");
        printf("%s",params[1]);
        printf(" could not be opened.\n");
        return 1;
    }
    return 0;
}