#include "image.h"

/* |-----------------------------| Constructeurs |-----------------------------| */

// A partir de rien;
Image::Image()
{
    _largeur = 0;
    _longueur = 0;
}

// A partir d'un fichier.ppm;
Image::Image(string &nom_ppm)
{

    // Declaration des variables
    string line;   // Lit les informations inultiles
    string format; // Format de l'image P3
    string name;   // Au cas où l'utilisateur se trompe dans le nom de l'image a charger, on redemande le nom.

    vector<int> mypixels; // pour recuperer les donnees du fichier de maniere lineaire. On repartira ensuite ces donnees dans les tableaux correspondants

    ifstream entree; // Declaration d'un "flux" qui permettra ensuite de lire les donnees de l'image.

    // Initialisation des variables
    name = nom_ppm;

    // Debut de l'ouverture du fichier
    entree.open(name);

    // On verifie que le fichier a bien ete ouvert.
    while (!entree)
    {
        cerr << "Erreur! Impossible de lire de fichier " << name << " ! " << endl;
        cerr << "Redonnez le nom du fichier a ouvrir SVP. Attention ce fichier doit avoir un nom du type nom.ppm : ";
        cin >> name;
        entree.open(name); // relance
    }

    // Lecture du format (P3)
    entree >> format;
    // Pour aller à la ligne suivante
    getline(entree, line);
    // Lecture du commentaire
    getline(entree, line);
    // Lecture des dimensions
    entree >> _largeur >> _longueur;
    // Pour aller à la ligne suivante
    getline(entree, line);

    while (format != "P3")
    {
        if (format != "P3")
        {
            cerr << "Erreur! L'image que vous nous avez donnee a un format ne verifiant pas les conditions requises." << endl;
            cerr << "L'image que vous nous avez donnee doit etre codee en ASCII et non en brut." << endl;
        }
        entree.close();

        // Redemande d'un nom de fichier valide.
        do
        {
            cerr << "Veuillez redonner un nom de fichier qui respecte les conditions de format et de taille. Attention, ce nom doit etre de la forme nom.ppm : ";
            cin >> name;
            entree.open(name);
        }
        while (!entree);

        // Lecture du format (P3)
        entree >> format;
        // Pour aller à la ligne suivante
        getline(entree, line);
        // Lecture du commentaire
        getline(entree, line);
        // Lecture des dimensions
        entree >> _largeur >> _longueur;
        // Pour aller à la ligne suivante
        getline(entree, line);
    }

    nom_ppm = name;

    // Lecture de la valeur maximum
    getline(entree, line);

    // Declaration de la variable lisant l'intensité de chaque couleur pour chaque pixel
    int pix;
    mypixels.resize(3 * _longueur * _largeur);

    // Lecture de pixel de couleur
    for (int i = 0; i < 3 * _longueur * _largeur; i++)
    {
        entree >> pix;
        mypixels[i] = pix;
    }

    _rouge.resize(_longueur);
    _vert.resize(_longueur);
    _bleu.resize(_longueur);

    for (int i = 0; i < _longueur; i++)
    {
        vector<unsigned int> R(_largeur);
        vector<unsigned int> G(_largeur);
        vector<unsigned int> B(_largeur);

        for (int j = 0; j < _largeur; j++)
        {
            R[j] = mypixels[3 * j + 3 * _largeur * i];
            G[j] = mypixels[3 * j + 1 + 3 * _largeur * i];
            B[j] = mypixels[3 * j + 2 + 3 * _largeur * i];
        }

        _rouge[i] = R;
        _vert[i] = G;
        _bleu[i] = B;
    }

    // Informations a l'utilisateur pour dire que tout s'est bien passe
    cout << "L'image " << name << " a bien ete chargee !" << endl << endl;
    entree.close();
}

// A partir de 3 vecteur;
Image::Image(const vector<vector<unsigned int>> &rouge, const vector<vector<unsigned int>> &vert, const vector<vector<unsigned int>> &bleu, bool alert)
{
    // Verification
    _verifVect(rouge, "rouge");
    _verifVect(vert, "vert");
    _verifVect(bleu, "bleu");

    if (rouge.size() == vert.size() && rouge.size() == bleu.size())
    {
        if (rouge.size() != 0)
        {
            if (!(rouge[0].size() == vert[0].size() &&
                    rouge[0].size() == bleu[0].size()))
            {
                // Erreur si la largeur des vector des couleur ne sont pas de la même taille
                throw(invalid_argument("L'un des vecteur de couleur entrés en paramétres as une largeur différentes des autres. r : " + to_string(rouge[0].size()) + " | v : " + to_string(vert[0].size()) + " | b : " + to_string(bleu[0].size())));
            }
        }
    }
    else
    {
        // Erreur si la longueur des vector des couleur ne sont pas de la même taille
        throw(invalid_argument("L'un des vecteur de couleur entrés en paramétres as une longueur différentes des autres.r : " + to_string(rouge.size()) + " | v : " + to_string(vert.size()) + " | b : " + to_string(bleu.size())));
    }

    // Affectations des vects
    _rouge = rouge;
    _vert = vert;
    _bleu = bleu;

    // Affectation des tailles
    _longueur = _rouge.size();
    if (_longueur == 0)
    {
        _largeur = 0;
    }
    else
    {
        _largeur = _rouge[0].size();
    }

    if (alert) cout << "|----------------| Image Initialisé par couleur de taille " << _longueur << " x " << _largeur << " |----------------|" << endl;
}

// A partir de deux entier;
Image::Image(unsigned int longueur, unsigned int largeur, bool alert)
{
    // Verification
    if (longueur < 0) throw(invalid_argument("La longueur donné en paramètre ne peut pas être négatif. longueur = " + to_string(longueur)));
    if (largeur < 0) throw(invalid_argument("La largeur donné en paramètre ne peut pas être négatif. largeur = " + to_string(largeur)));

    // Affectation des tailles
    _longueur = longueur;
    _largeur = largeur;

    // Affectation des vects
    for (int i = 0; i < _longueur; i++)
    {
        _rouge.push_back(vector<unsigned int> (_largeur, 0));
        _vert.push_back(vector<unsigned int> (_largeur, 0));
        _bleu.push_back(vector<unsigned int> (_largeur, 0));
    }

    if (alert) cout << "|----------------| Image Initialisé par couleur de taille " << _longueur << " x " << _largeur << " |----------------|" << endl;
}

/* |----------------------------| Méthodes Images |----------------------------| */

// Pour obtenir les couleur :
vector<vector<unsigned int>> &Image::get_r()
{
    return _rouge;
}
vector<vector<unsigned int>> &Image::get_v()
{
    return _vert;
}
vector<vector<unsigned int>> &Image::get_b()
{
    return _bleu;
}

const vector<unsigned int> Image::get_pix(unsigned int i, unsigned int j) const
{
    return vector<unsigned int>
    {
        _rouge.at(i).at(j),
        _vert.at(i).at(j),
        _bleu.at(i).at(j),
    };
}

float Image::moy() const
{
    float moyenne = 0;

    for (int i = 0; i < _longueur; i++)
    {
        for (int j = 0; j < _largeur; j++)
        {
            moyenne += (_rouge[i][j] + _vert[i][j] + _bleu[i][j]) / 3;
        }
    }

    return moyenne / (_longueur * _largeur);
}

// Affichage
void Image::afficher() const
{
    cout << "|-------------| Affichage de image :" << endl << endl;
    for (int i = 0; i < _longueur; i++)
    {
        for (int j = 0; j < _largeur; j++)
        {
            cout << _rouge[i][j] << "\t" << _vert[i][j] << "\t" << _bleu[i][j];
            if (j != _largeur) cout << "\t\t";
        }
        if (i != _longueur) cout << endl << endl;
    }
}

/* |-----------------------------| Vérifications |-----------------------------| */

// Aucune erreur si le tableau est un rectangle et que les valeur ne sont pas ahberrante
void Image::_verifVect(const vector<vector<unsigned int>> &vect, string nom_vect) const
{
    bool valide = true;
    unsigned int i = 1;

    while (valide && i < vect.size())
    {
        unsigned int j = 0;
        valide = vect[0].size() == vect[i].size();

        while (valide && j < vect[i].size())
        {
            // Erreur si la valeur des couleur n'appartient pas à [0, 255]
            if (vect[i][j] < 0 || vect[i][j] > 255) throw(invalid_argument("L'un des vecteur de couleur (" + nom_vect + ") a une valeur interdite : " + to_string(vect[i][j]) + " en pos i: " + to_string(i) + " j:" + to_string(j)));
            j++;
        }

        i++;
    }

    // Erreur si le vetor n'est pas un rectangle.
    if (nom_vect != "")
    {
        if (!valide) throw(invalid_argument( "L'un des vecteur de couleur (" + nom_vect + ") entrés en paramétres n'est pas un vecteur 2D conforme."));
    }
    else
    {
        if (!valide) throw(invalid_argument("L'un des vecteur de couleur entrés en paramétres n'est pas un vecteur 2D conforme."));
    }
}

// Retourne vraie si l'objet cible est une compôsante de l'objet en paramètre
bool Image::est_composanteRouge(const Image &Img) const
{
    vector<vector<unsigned int>> vectnull(_longueur, vector<unsigned int>(_largeur, 0));
    return (_rouge == Img._rouge && _vert == vectnull && _bleu == vectnull);
}

// Retourne vraie si il existe un pixel de couleur (r, v, b)
bool Image::detection(unsigned int r, unsigned int v, unsigned int b) const
{
    // Vérification
    if (r < 0 || r > 255) throw(invalid_argument("La valeur rouge (" + to_string(r) + ") n'est pas entre [0, 255]"));
    if (v < 0 || v > 255) throw(invalid_argument("La valeur vert (" + to_string(v) + ") n'est pas entre [0, 255]"));
    if (b < 0 || b > 255) throw(invalid_argument("La valeur bleu (" + to_string(b) + ") n'est pas entre [0, 255]"));

    // Detection naïve des couleurs
    bool existe = false;

    int i = 0;
    while (!existe && i < _longueur)
    {
        int j = 0;

        while (!existe && j < _largeur)
        {
            existe = (_rouge[i][j] == r && _vert[i][j] == v && _bleu[i][j] == b);
            j++;
        }

        i++;
    }

    return existe;
}

void Image::enregistrer(string &nom, bool alert) const
{
    int n = nom.size();

    if (n > 4)
    {
        if (!(nom[n - 4] == '.' && nom[n - 3] == 'p' && nom[n - 2] == 'p' && nom[n - 1] == 'm'))
        {
            nom = nom + ".ppm";
        }
    }
    else
    {
        nom = nom + ".ppm";
    }

    ofstream sortie;

    sortie.open(nom);

    // Ecriture du format
    sortie << "P3" << endl;
    // Ecriture d'information
    sortie << "# Created by GIMP version 2.10.28 PNM plug-in" << endl;
    // Ecriture des dimensions
    sortie << _largeur << " " << _longueur << endl;
    // Ecriture du maximum
    sortie << 255 << endl;

    // Ecriture des intensites de couleurs
    for (int i = 0; i < _longueur; i++)
    {
        for (int j = 0; j < _largeur; j++)
        {
            sortie << _rouge[i][j] << "\n";
            sortie << _vert[i][j] << "\n";
            sortie << _bleu[i][j] << "\n";
        }
    }

    sortie.close();

    cout << "Le fichier " << nom << " a bien été enregistrer !" << endl << endl;
}
