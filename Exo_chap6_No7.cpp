//
// This is example code from Chapter 6.7 "Trying the second version" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
// 10 d�cembre 2017
// Caract�res sp�ciaux : [ ]   '\n'   {  }   ||

#include "../std_lib_facilities.h"

int main()

{
    double x=0;
    double y=0;
    cout << "Saisir un nombre x : \n";
    cin >> x;
    cout << "Saisir un nombre y : \n";
    cin >> y;

    // Conversion de x en binaire, calcul de not x, retour � l'�tat initial
    // --------------------------------------------------------------------
    cout <<"\nNOT X\n";
    cout <<"-----\n";
    cout<<"x en decimal  : "<<x<<"\n";
    bitset<8> b(x); // Initialisation
    cout<<"Binaire de x  : "<<b<<"\n";
    b.flip();       // Inversion de chaque bit
    cout<<"Not x         : "<<b<<"\n";
    cout<<"Not x decimal : "<<b.to_ulong()<<"\n";
    b.flip();       // Retour � l'�tat initial
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

    // on applique les 3 r�gles � chaque bit via une boucle inverse
    string et_logique="" ; // R�sultat de l'op�ration binaire &
    string ou_logique="" ; // R�sultat de l'op�ration binaire |
    string xor_logique="" ; // R�sultat de l'op�ration binaire ^

    for (int i=b1.size()-1;i>=0;i--)
        {

        if (b1[i]==1 && b2[i]==1)
            {

            et_logique+="1";
            ou_logique+="1";
            xor_logique+="0";
            }
        if ((b1[i]==1 && b2[i]==0)||(b1[i]==0 && b2[i]==1)) // Bien g�rer les deux cas
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

    // On retransforme les cha�nes "r�sultats" en bitset � partir des 3 variables string construites pr�c�demment, puis on applique un "to_ulong()"
    // pour la transformation du binaire en d�cimal
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
