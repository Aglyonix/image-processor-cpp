#include "filtres.h"

/* |-----------------------------| Constructeurs |-----------------------------| */

Filtre::Filtre(int rayon)
{
    if(rayon<1) throw(invalid_argument("Le rayon doit etre egale ou superieur à 1"));

    _rayon = rayon;

    int n = (_rayon*2)+1;
    for(int i=0; i<n; i++)
    {
        _action.push_back(vector<float> (0, n));
    }
}

Filtre::Filtre(const vector<vector<float>> &action)
{
    int n = action.size();

    // Vérification
    _verifAction(action);
    if(n < 3) throw(invalid_argument("Votre action de filtre est un carree trop petit."));
    if(n%2 == 0) throw(invalid_argument("Votre action de filtre doit etre carree de taille impaire."));

    _action = action;

    _rayon = (n-1)/2;
}

/* |---------------------------| M�thodes Basiques |---------------------------| */

Image Filtre::application(Image & Org, bool alert)
{
    // Org pour Originale et Img pour Image

    Image Img(Org.lon(), Org.lar(), false);

    for(int i=0; i<Org.lon(); i++)
    {
        for(int j=0; j<Org.lar(); j++)
        {
            //Borne min lon
            int u=i-_rayon;
            if(u<0) u=0;

            //Borne min lar
            int v=j-_rayon;
            if(v<0) v=0;

            //Borne max lon
            int m=i+_rayon;
            if(m>Org.lon()) m=Org.lon();

            //Borne max lar
            int n=j+_rayon;
            if(n>Org.lon()) n=Org.lon();

            //Somme des couleurs.
            int sum_r=0; int sum_v=0; int sum_b=0;

            for(; u<m+1; u++)
            {
                for(; v<n+1; v++)
                {
                    int r = u-(i-_rayon); int s = v-(j-_rayon);
                    sum_r += _action[r][s] * Org.get_r()[u][v];
                    sum_v += _action[r][s] * Org.get_v()[u][v];
                    sum_b += _action[r][s] * Org.get_b()[u][v];
                }
            }

            Img.get_r()[i][j] = sum_r;
            Img.get_v()[i][j] = sum_v;
            Img.get_b()[i][j] = sum_b;
        }
    }

    if (alert) cout << "|-------------------| Le filtre a ete applique avec succes " << Img.lon() << " x " << Img.lar() << " |-------------------|" << endl;
    return Img;
}

/* |-----------------------------| V�rifications |-----------------------------| */

// Aucune erreur si le tableau est un carree
void Filtre::_verifAction(const vector<vector<float>> &action) const
{
    bool valide = true;
    unsigned int i = 1;

    int n = action.size();

    while (valide && i < n)
    {
        valide = action[i].size() == n;
        i++;
    }

    if(!valide) throw(invalid_argument("Votre action de filtre n'est pas conforme, il n'est pas carree."));
}
