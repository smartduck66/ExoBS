//
// Exercice N°3/4/5 page 300 - Chapitre 8
// Fibonacci
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup

// Caractères spéciaux : [ ]   '\n'   {  }   ||    Bool : 0 Faux 1 Vrai
// CTRL D termine la saisie dans cin


// Version initiale du Book de BS
#include "std_lib_facilities.h"




void fibonacci(int nb1,int nb2,vector<int>& v,int nb_elem)
{
    
    // Création de la suite en modifiant le vecteur passé par référence (la copie serait trop "lourde" en ressources si nb_elem trop grand)
    // Attention : le type int est valide dans ce range (INT 32 bits signed) -2,147,483,648 to 2,147,483,647
    // Conséquence : nb_elemn doit être inférieur ou égal à 45 quand nb1 = 1 et nb2= 2
    // ------------------------------------------------------------------------------------------------------------------------------------
    v[0]=nb1;
    v[1]=nb2;

    for (int numero_elem=3;numero_elem<=nb_elem;++numero_elem){ v[numero_elem-1]=v[numero_elem-2]+v[numero_elem-3]; }

}

void print_vector(vector<int>& v)
{
    
    // Impression des éléments d'un vecteur d'int
    for (auto i:v){ cout <<i<<','; }
    cout << "END\n";
    
}

void reverse_vector_type1(vector<int>& v1,vector<int>& v2)
{
    
    // Le vecteur passé en argument est interverti et le résultat est créé dans un NOUVEAU vecteur renvoyé par référence
    for (int i=0;i<v1.size();i++)
    {
        int rang=static_cast<int>(v1.size()-1-i);   // Uniquement pour éviter la conversion implicite et la perte de précision sur l'opération
        v2[i]=v1[rang];
    
    }
   
   
}

void reverse_vector_type2(vector<int>& v1)
{
    
    // Le vecteur passé en argument est interverti par référence : on se base sur un swap
    
    // On calcule le nombre de permutations à effectuer en ne prenant que la partie entière
    // Ex : si le vecteur contient 11 éléments, seules 5 permutations 2 à 2 seront effectuées
    int nombre_permutations=static_cast<int>(v1.size()/2);
    
    for (int i=1;i<=nombre_permutations;i++)
    {
        
        int rang=static_cast<int>(v1.size()-i);   // Uniquement pour éviter la conversion implicite et la perte de précision sur l'opération
        int temp=v1[rang];
        v1[rang]=v1[i-1];
        v1[i-1]=temp;
    }
    
    
}


// -----------------------------------------------------------------------------------------------------
int main()
{
    try
    {
        
        int x,y,n;
        
        cout << "Saisir les deux éléments de démarrage de la suite de Fibonacci et le nombre d'éléments total, soit x, y et n (>1) :\n";
        cin >>x>>y>>n;
        
        if (n<=1)error("n doit être strictement supérieur à 1 !");
        if (y<=x)error("y doit être strictement supérieur à x !");
        
        // Création et impression de la suite de fibonacci
        vector<int> v(n);
        fibonacci(x,y,v,n);
        print_vector(v);
        
        // Inversion de la suite créée : création d'un nouveau vecteur
        vector <int> new_v(n);
        reverse_vector_type1(v,new_v);
        print_vector(new_v);

        // Inversion de la suite créée : modification du vecteur initial
        reverse_vector_type2(v);
        print_vector(v);
        
        return 0;
        
    }
    catch (runtime_error& e) {
        cerr << "error: " << e.what() << '\n';
        
        return 1;
    }
    catch (...) {
        cerr << "Oops: unknown exception!\n";
        return 2;
    }

    
    
    
    
