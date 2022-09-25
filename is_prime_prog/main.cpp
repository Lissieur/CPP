#include <iostream>
#include <fstream>
#include <string>

using namespace std;


//? Transforme une chaine de caractères en un int
int to_int(const char* input,int s,int e)
{
    int res = 0;
    while (s<e)
    {
        res*=10;
        res+=input[s]-'0';
        s++;
    }
    return res;
}

//? Retourne 0 si le nombre entré est un nombre premier, retourne 1 sinon
int eratostene(int n)
{
    if(n <= 1)
        return 1;
    if(n ==2)
        return 0;
    int pos = 3,l = 1,posbis = 0,isprime = 0;
    int era[n/2];
    era[0]=2;
    while(pos<n)
    {
        while(posbis<l && isprime == 0)
        {
            if(pos%era[posbis] == 0)
                isprime = 1;
            posbis++;
        }
        if (isprime == 0)
        {
            era[l] = pos;
            l++;
        }
        else
        {
            isprime = 0;
        }
        posbis = 0;
        pos+=2;
    }
    pos= 0;
    while(pos<l)
    {
        if(n%era[pos]==0)
            return 1;
        pos++;
    }
    return 0;
}


//? Prends une ligne de nombres séparés par un espace en entrée et affiche une ligne pour chacun d'entre eux
//? nous disant si ce dernier est un nombre premier ou non.
int main()
{
    string s;
    getline(cin, s);
    const char* input = s.c_str();
    int start = 0,end = 0;
    int l = s.length();
    while(start < l)
    {
        while(input[end]!=' ' && end<l)
        {
            end++;
        }
        int n = to_int(input,start,end);

        int isprime= eratostene(n);
        if (isprime == 0)
            printf("%d is a prime: True\n",n);
        else
            printf("%d is a prime: False\n",n);
        end++;
        start = end;
    }
    return 0;
}