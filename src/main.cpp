#include <iostream>
#include <vector>
#include "image.h"

using namespace std;
const string split = "[----------------------------------------------------------------------------------------------------------------------]";

int main()
{
    // imageTest();

    bool actif = true;
    string Nom_Image = "Aucune Image chargée";
    bool chargee = false;
    Image Img, Original;
    char His_Affichage = 'p'; // Affichage Histogramme des couleurs Par pixel
    vector<Image> Historique;

    int loop=0;

    cout << endl << endl << "|--------------------------------------| Bienvenue dans votre espace de travail |--------------------------------------|" << endl << endl;

    while(actif)
    {
        if(loop != 0) cout << split << endl << endl;
        Rafraichissement(Nom_Image, Img);
        cout << split << endl << endl;

        try
        {
            menu(Img, Original, Historique, Nom_Image, actif, chargee, His_Affichage, split);
        }
        catch(const invalid_argument & e)
        {
            cerr << e.what() << endl << endl;
        }

        if(Historique.size() > 10)
        {
            vector<Image> tmp (10);

            for(int i=0; i<10; i++)
            {
                tmp.push_back(Historique[Historique.size()-(i+1)]);
            }

            Historique = tmp;
        }

        if(!actif) cout << split << endl << endl;
        loop++;
    }

    return 0;
}
