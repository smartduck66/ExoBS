//
// Exercice N°10/11 page 300 - Chapitre 8
// Max, Min, Moyenne, Médiane d'un vecteur
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup


#include "std_lib_facilities.h"

// Caractères spéciaux : [ ]   '\n'   {  }   ||    Bool : 0 Faux 1 Vrai
// CTRL D termine la saisie dans cin



int maxv(vector<int>& v)
{
    // sort(v.begin(),v.end());
    return v[static_cast<int>(v.size()-1)];

}

int minv(vector<int>& v)
{
    // sort(v.begin(),v.end());
    return v[0];
    
}

double moyenne_arithmetique(vector<int>& v)
{
    double moy=0;
    for (auto i:v){moy+=i;}
    return moy/v.size();
    
}

double mediane(vector<int>& v)
{
    // Pour déterminer une médiane d'un ensemble de valeurs, il suffit d'ordonner les valeurs en une liste croissante et de choisir la valeur qui est au centre de cette liste
    
    // Dans le cas où le vecteur possède un nombre impair d'éléments (N), la médiane est le nombre en position int(N/2)+1
    if (v.size()%2==1){
        return v[static_cast<int>((v.size()/2)+1)];
        }
    else
    {

        // Dans le cas où le vecteur possède un nombre pair d'éléments (N), la médiane est la moyenne arithmétique des nombres en position N/2 et N/2+1
        int k = static_cast<int>((v.size()/2)-1);
        return (v[k]+v[k+1])/2.0;
    }

}

// -----------------------------------------------------------------------------------------------------
int main()
{
    
    vector <int> v={10152,3,10,3,987,7,999999,77,1598,34,53,76};
 
    sort(v.begin(),v.end());
    for (auto i:v){cout<<i<<',';}
    cout<<"END\n\n";
    
    cout << "Valeur min est "<<minv(v)<<'\n' ;
    cout << "Valeur max est "<<maxv(v)<<'\n' ;
    cout << "Moyenne est "<<moyenne_arithmetique(v)<<'\n' ;
    cout << "Médiane est "<<mediane(v)<<'\n' ;
    
}
