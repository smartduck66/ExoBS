//
// Exercice N�9 page 219 - Chapitre 6
// Programme qui lit un nombre (max : 4 digits) et le d�compose en milliers, centianes, dizaines et unit�s
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
// 26 d�cembre 2017
// Caract�res sp�ciaux : [ ]   '\n'   {  }   ||

#include "../std_lib_facilities.h"

int main()
{

    try {

    string nombre="";
    cout << "Saisis le nombre (max : 4 digits) a decomposer :\n";
    cin >> nombre;
    vector<char>w={};

    vector<string>labels={" unites", " dizaines", " centaines", " milliers"};

    // Si le nombre saisi a une taille nulle ou sup�rieure, on g�n�re une erreur
    // pas de test effectu� sur une valeur nulle ou non-digit : la fonction stoi() n'est pas d�clar�e dans le header "light" de BS
    if (nombre.size()==0||nombre.size()>4)
        error("La saisie est incorrecte !");

    // Construction de la cha�ne de r�ponse
    string decomposition="";
    for (int i=0;i<nombre.size();i++)
        {
        // d�codage de la saisie et stockage dans un vecteur : d'abord les unit�s, puis les dizaines, etc.
        w.push_back(nombre[i]);

        // Construction incr�mentale de la cha�ne de r�ponse
        // to_string est n�cessaire pour transformer un "char" en "string"
        decomposition+=to_string(nombre[i])+labels[nombre.size()-1-i]+' ';

        }

    // Affichage du r�sultat final
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
