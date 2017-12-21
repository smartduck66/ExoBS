//
// This is example code from Chapter 6.7 "Trying the second version" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
// 10 décembre 2017
// Caractères spéciaux : [ ]   '\n'   {  }   ||

#include "../std_lib_facilities.h"

int main()

{
    double x=0;
    double y=0;
    cout << "Saisir un nombre x : \n";
    cin >> x;
    cout << "Saisir un nombre y : \n";
    cin >> y;

    // Conversion de x en binaire, calcul de not x, retour à l'état initial
    // --------------------------------------------------------------------
    cout <<"\nNOT X\n";
    cout <<"-----\n";
    cout<<"x en decimal  : "<<x<<"\n";
    bitset<8> b(x); // Initialisation
    cout<<"Binaire de x  : "<<b<<"\n";
    b.flip();       // Inversion de chaque bit
    cout<<"Not x         : "<<b<<"\n";
    cout<<"Not x decimal : "<<b.to_ulong()<<"\n";
    b.flip();       // Retour à l'état initial
    cout<<"Back en bin.  : "<<b<<"\n";
    cout<<"Back en dec.  : "<<b.to_ulong()<<"\n";
    cout <<"-----------------------\n";

    // Le AND binaire :     1&1 = 1, 1&0 = 0, 0&0 = 0
    // Le OU binaire :      1|1 = 1, 1|0 = 1, 0|0 = 0
    // Le OU exclu. bin. :  1^1 = 0, 1^0 = 1, 0^0 = 0
    // ------------------------------------------

    // On transforme les deux nombres saisis en binaire
    bitset<8> b1(x);
    bitset<8> b2(y);

    // on applique les 3 règles à chaque bit via une boucle inverse
    string et_logique="" ; // Résultat de l'opération binaire &
    string ou_logique="" ; // Résultat de l'opération binaire |
    string xor_logique="" ; // Résultat de l'opération binaire ^

    for (int i=b1.size()-1;i>=0;i--)
        {

        if (b1[i]==1 && b2[i]==1)
            {

            et_logique+="1";
            ou_logique+="1";
            xor_logique+="0";
            }
        if ((b1[i]==1 && b2[i]==0)||(b1[i]==0 && b2[i]==1)) // Bien gérer les deux cas
            {
            et_logique+="0";
            ou_logique+="1";
            xor_logique+="1";
            }
        if (b1[i]==0 && b2[i]==0)
            {
            et_logique+="0";
            ou_logique+="0";
            xor_logique+="0";
            }

        }

    // On retransforme les chaînes "résultats" en bitset à partir des 3 variables string construites précédemment, puis on applique un "to_ulong()"
    // pour la transformation du binaire en décimal
    bitset<8>r1(et_logique);
    bitset<8>r2(ou_logique);
    bitset<8>r3(xor_logique);
    cout <<"x AND y :"<<r1.to_ulong()<<"\n";
    cout <<"x OR y :"<<r2.to_ulong()<<"\n";
    cout <<"x XOR y :"<<r3.to_ulong()<<"\n";
    cout <<"-----------------------\n";

    return 0;


}



//------------------------------------------------------------------------------
