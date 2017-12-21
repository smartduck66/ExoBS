class Name_value {                      // Création d'un nouveau type composé de deux membres
public:
    string name;
    int value;
    Name_value(string ch, int val)     // On crée une nouvelle occurence
    :name(ch), value(val) { }
};


class Name_value_exist{ // On crée une classe avec une seule méthode qui permet de vérifier l'existence d'une occurence dans un vecteur
public:
    bool exist(vector<Name_value> p, string n, int v);
};

Name_value_exist e; // On fournit la méthode exist

bool Name_value_exist::exist(vector<Name_value> p, string n, int v) // Définition de la méthode exist
{
    // On balaye le vecteur pour vérifier
    for (Name_value x:p)
        if (x.name==n&&x.value==v)return 1; // la paire existe déjà
    return 0; // la paire n'existe pas
}


// -----------------------------------------------------------------------------------------------------
int main()
{
    
    vector<Name_value> paire; // Création du vecteur avec la classe définie plus haut
    string nom="";
    int valeur=0;
    
    while (cin) {
        
        cout << "Saisir une paire (nom valeur) - NoName 0 permet de stopper la saisie :\n";
        cin >>nom>>valeur;
        if (nom=="NoName"&&valeur==0)break;
        
        // Vérification que cette nouvelle paire saisie n'a pas DEJA été saisie
        if (e.exist(paire,nom,valeur)) {
            cout << "Cette paire a déjà été saisie. Veuillez recommencer\n";
        } else {
            // Si ce n'est pas le cas, on push
            paire.push_back(Name_value(nom,valeur));
        }
        
    }
    
    // Affichage de toutes les paires saisies en balayant le vecteur après un tri
    // Attention : le tri sort(paire) ne fonctionne pas - Il faudra vérifier plus tard quelle syntaxe de tri sur un vecteur construit autour d'un type particulier (nom, valeur)
    cout << "Le vecteur comprend "<<paire.size()<<" éléments\n";
    for (Name_value x:paire)
        cout << x.name << " - "<<x.value<<'\n';
    
}
