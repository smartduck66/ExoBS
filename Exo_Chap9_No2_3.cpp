//
// Exercice N°2&3 page 339 - Chapitre 9
// Class Name_pairs : définition complète
// Commit initial : 13 janvier 2018
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup


#include "std_lib_facilities.h"

// Caractères spéciaux : [ ]   '\n'   {  }   ||    Bool : 0 Faux 1 Vrai
// CTRL D termine la saisie dans cin


class Name_pairs{
public:
    // Définition des fonctions permettant de manipuler les données de la classe
    // Les arguments sont passés par référence pour éviter les copies - const protège les données qui ne doivent être que lues
    // ***********************************************************************************************************************
    
    // Constructeur par défaut : on initialise seulement les 2 vecteurs
    Name_pairs():name{},age{}{  };
    
    // Opérations qui modifient les données
    void read_names();
    void read_ages();
    void tri();
    
    // Opérations qui ne modifient pas les données
    void print();                                               // Affichage de l'ensemble (nom+âge) des données de l'objet
    string print_chaine();                                      // Idem mais dans une chaîne de caractères (pour l'overloading de <<)
    int nb_people(){return static_cast<int>(name.size()); };    // fonction inline, car courte, qui retourne le nombre d'éléments du vecteur nom
    string nom_p(int rang)  { return name[rang]; }              // On renvoit le nom en fonction du rang passé : PAS DE GESTION D'OUT OF RANGE
    int age_p(int rang)  { return age[rang]; }                  // On renvoit l'âge en fonction du rang passé : PAS DE GESTION D'OUT OF RANGE
    
private:
    // Les données de la classe ne sont accessibles que via les fonctions-membres publiques
    vector<string>name;
    vector<int>age;
    
};

// Implémentation des fonctions de la classe
// *****************************************

void Name_pairs::read_names(){

    string saisie="";
    cout << "Nom (END pour sortir) :\n";
    
    while (cin>>saisie && saisie!="END") {
        name.push_back(saisie);
    }

}

void Name_pairs::read_ages(){

    for (auto i:name){
        cout << "Saisir l'âge de "<<i<<" :\n";
        int saisie=0;
        cin>>saisie;
        age.push_back(saisie);
    
    }
    
}

void Name_pairs::print(){
    for (int i=0;i<name.size();i++){cout << name[i] <<" est âgé de "<<age[i]<<" ans\n";}
    
}

string Name_pairs::print_chaine(){  // Ne sert qu'à l'overloading de l'opérateur << qui nécessite une 'string' (code identique à ci-dessus)
    string chaine_a_afficher="";
    for (int i=0;i<name.size();i++){chaine_a_afficher+= name[i] +" est âgé de "+to_string(age[i])+" ans\n";}
    return chaine_a_afficher;

}

// Overloading de l'opérateur <<, identique fonctionnellement à Name_pairs::print()
ostream& operator<<(ostream& os, Name_pairs& np) {return os<<np.print_chaine();}

// Overloading de l'opérateur ==, permettant de comparer deux panels de personnes saisies (deux objets passés)
bool operator==( Name_pairs& a,  Name_pairs& b)
{
    // On s'appuie sur des fonctions-membres de la classe étant donné que les données sont privées
    
    // 1er test : on vérifie que les tailles des deux objets sont bien identiques
    if (a.nb_people()!=b.nb_people()) return false;
    
    // 2ème test : si c'est le cas, on "balaie" les données (=2 vecteurs) des objets
    for (int i=0;i<a.nb_people();i++){
        if (a.nom_p(i) != b.nom_p(i)) return false;
        if (a.age_p(i) != b.age_p(i)) return false;
        
    }
    
    // Si aucune dissemblance n'a été trouvée...
    return true;

}


int find_index(const vector<string>& v,const string& n)
// find n's index in v -> Tiré de BS (chapitre 8, exo 7) - fonction Helper pour le tri ci-dessous
{
    for (int i=0; i<n.size(); ++i)
        if (n==v[i]) return i;
    error("name not found: ",n);
    return 1;
}

void Name_pairs::tri(){ // Tiré de BS (chapitre 8, exo 7)
    
    // Avant de trier, on passe par des vecteurs "tampons"
    vector<string> original_names = name;	// copy the names
    vector<int> original_ages = age;		// copy the ages
    
    sort(name.begin(),name.end());			// sort the names
    
    for(int i=0; i<name.size(); ++i)		// update ages
        age[i] = original_ages[find_index(original_names,name[i])];

}


// -----------------------------------------------------------------------------------------------------
int main()
{
    try {
        
        // Instanciation d'un objet Name_pairs : saisie d'un premier panel de personnes ***************************************
        Name_pairs panel1;
        
        // Saisie de noms
        cout << "Saisie du 1er panel de personnes\n";
        panel1.read_names();
        
        // Saisie des âges pour chaque nom précédemment stocké
        panel1.read_ages();
        
        // Print des deux vecteurs renseignés
        cout << "\ntableau initial non trié avec "<<panel1.nb_people()<<" personnes ******\n";
        panel1.print();
        
        // Tri des noms
        panel1.tri();
        
        // Re-Print des deux vecteurs renseignés pour vérification
        cout << "\ntableau trié v1*******\n";
        panel1.print();
        
        // Re-Print en passant par l'overloading de l'opérateur <<
        cout << "\ntableau trié v2*******\n";
        cout << panel1 <<'\n';
        
        // Instanciation d'un objet Name_pairs : saisie d'un second panel de personnes pour le comparer avec le 1er **************
        Name_pairs panel2;
        
        // Saisie de noms
        cout << "Saisie du 2ème panel de personnes\n";
        panel2.read_names();
        
        // Saisie des âges pour chaque nom précédemment stocké
        panel2.read_ages();
        
        // Vérification de leur égalité parfaite via l'overloading de l'opérateur ==
        if (panel1==panel2) {
            cout << "Les deux panels saisis sont identiques, tant sur les noms que sur les âges des personnes\n";
        } else {
            cout << "Les deux panels saisis ne sont PAS identiques !\n";
        }
        
    }
    catch (runtime_error e) {	// this code is to produce error messages; it will be described in Chapter 5
        cout << e.what() << '\n';
        //keep_window_open("~");	// For some Windows(tm) setups
    }
    catch (...) {	// this code is to produce error messages; it will be described in Chapter 5
        cout << "exiting\n";
        //keep_window_open("~");	// For some Windows(tm) setups
    }
    
 }
    

  