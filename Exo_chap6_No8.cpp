//
// Exercice N�8 page 219 - Chapitre 6
// Nouvelle version de Bulls & Cows
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
// 25 d�cembre 2017
// Caract�res sp�ciaux : [ ]   '\n'   {  }   ||

#include "../std_lib_facilities.h"

int main()
{
    // On utilise une technique de g�n�ration apparue en C++11 - Demeure un probl�me de s�quence de g�n�ration
    random_device rd;  //Will be used to obtain a seed for the random number engine
    mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    uniform_int_distribution<> dis(65, 90); // Intervalle de g�n�ration : 65 = A / 90 = Z


    vector<char>v={};

    int coups=0;
    bool gagne=false;

    // G�n�ration d'un mot secret de 4 lettres
    for (int i=0;i<4;i++)
        v.push_back(char(dis(gen)));

    // Affichage du mot g�n�r� pour v�rification
    // for(char n : v)
    //   std::cout << n << '\n';

    while (!gagne) {
        string proposition="";
        cout << "Ta proposition en 4 lettres :\n";
        cin >> proposition;
        vector<int>w;

        // d�codage de la saisie et stockage dans un vecteur int pour comparaison
        for (int i=0;i<4;i++)
            w.push_back(proposition[i]);

        // Bull & Cows
        int bull=0;
        int cow=0;
        for (int i=0;i<4;i++)
        {

            for (int j=0;j<4;j++)
            {
                if (w[i]==v[j]&&i==j)++bull;
                if (w[i]==v[j]&&i!=j)++cow;
            }
        }

        if (bull==4)
            gagne=true;
        else
        {

            cout << "Bull = "<<bull<<'\n';
            cout << "Cow = "<<cow<<'\n';
        }

        ++coups;
    }

    cout << "Gagn� en "<<coups<<" coups\n" ;



}
