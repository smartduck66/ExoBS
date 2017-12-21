class Mot_type {                      // Création d'un nouveau type composé de deux membres
public:
    string mot;
    int type;                          // 0 = indéfini, 1 = nom   2 = verbe   3 = conjonction
    Mot_type(string ch, int val)     // On crée une nouvelle occurence
    :mot(ch), type(val) { }
};



// -----------------------------------------------------------------------------------------------------
int main()
{

    // Initialisation de la grammaire
    vector<string>noms={"birds", "fish", "C++"};
    vector<string>verbes={"rules", "fly", "swim"};
    vector<string>conjonctions={"and", "or", "but"};
    
    string mot="";
    vector<Mot_type>mots;
    
    cout << "Saisissez votre phrase dont la syntaxe sera vérifiée <. pour terminer la saisie> :\n";
    
    while (cin){
        cin >> mot;
        if (mot==".")break;
        else mots.push_back(Mot_type(mot,0)); // On pushe 0 car le type du mot est indéfini à ce stade
        
    }

    for (int i=0;i<mots.size();i++){
        // On affecte un type (1, 2, 3) à chaque mot saisi en balayant les 3 vecteurs prédéfinis : noms, verbes, conjonctions
        for (int j=0;j<noms.size();j++)
            if (mots[i].mot==noms[j])mots[i].type=1;
        for (int j=0;j<verbes.size();j++)
            if (mots[i].mot==verbes[j])mots[i].type=2;
        for (int j=0;j<conjonctions.size();j++)
            if (mots[i].mot==conjonctions[j])mots[i].type=3;
        
        // Affichage
        cout << mots[i].mot << " "<< mots[i].type <<'\n';
        
    }
    
    // On vérifie la grammaire qui doit suivre la régle "nom verbe conjonction" (1, 2, 3)
    // Ex : birds fly = OK / birds fly but = NOK / birds fly but birds = NOK / birds fly but fish swim = OK
    bool phrase_valide=false;
    bool new_phrase_attendue=false;
    
    int rang_seq=1;
    
    for (int i=0;i<mots.size();i++){
        if (mots[i].type==rang_seq){
            
            phrase_valide=true; // Si le type du mot est bien égal au rang de la séquence (nom verbe conjonction), on est OK !
            rang_seq++;         // on avance dans la séquence
            
            if (rang_seq==3){
                new_phrase_attendue=false; // La phrase est complète (nom+verbe)
            }
            
            if (rang_seq==4){                   // Quand on atteint la conjonction tous les 3 mots, on attend une nouvelle phrase
                new_phrase_attendue=true;
                rang_seq=1;               // On repart au début de la séquence
                }
            
            }
        else
            {
            phrase_valide=false;
            break;
        }
    }
    
    // On affiche le résultat si la phrase est valide et que l'on n'attend pas une nouvelle phrase post-conjonction
    if (phrase_valide&&!new_phrase_attendue)cout<<"La phrase saisie est OK !\n";
    else cout<<"La phrase saisie n'est pas conforme !\n";
    
    
}
