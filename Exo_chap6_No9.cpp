//
// Exercice N°9 page 219 - Chapitre 6
// Programme qui lit un nombre (max : 4 digits) et le décompose en milliers, centianes, dizaines et unités
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
// 26 décembre 2017
// Caractères spéciaux : [ ]   '\n'   {  }   ||

#include "../std_lib_facilities.h"

int main()
{

    try {

    string nombre="";
    cout << "Saisis le nombre (max : 4 digits) a decomposer :\n";
    cin >> nombre;
    vector<char>w={};

    vector<string>labels={" unites", " dizaines", " centaines", " milliers"};

    // Si le nombre saisi a une taille nulle ou supérieure, on génère une erreur
    // pas de test effectué sur une valeur nulle ou non-digit : la fonction stoi() n'est pas déclarée dans le header "light" de BS
    if (nombre.size()==0||nombre.size()>4)
        error("La saisie est incorrecte !");

    // Construction de la chaîne de réponse
    string decomposition="";
    for (int i=0;i<nombre.size();i++)
        {
        // décodage de la saisie et stockage dans un vecteur : d'abord les unités, puis les dizaines, etc.
        w.push_back(nombre[i]);

        // Construction incrémentale de la chaîne de réponse
        // to_string est nécessaire pour transformer un "char" en "string"
        decomposition+=to_string(nombre[i])+labels[nombre.size()-1-i]+' ';

        }

    // Affichage du résultat final
    cout << nombre<<" correspond a "<<decomposition<<'\n';
    return 0;

}

catch (exception& e) {
        cerr << "Erreur : " << e.what() << '\n';
        return 1;
    }
    catch (...) {
        cerr << "Oops: unknown exception!\n";
        return 2;
    }
}
