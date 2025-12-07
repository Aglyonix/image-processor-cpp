#include "filtres.h"

/* |------------------------------| Filtre |------------------------------| */

void menuFiltres(Image& Img, vector<Image>& His)
{
    char choix;

    cout << "Quel filtre appliquer ? : " << endl;
    cout << "a : Flou gaussien rayon 1" << endl;
    cout << "b : Flou gaussien rayon 2" << endl;
    cout << "c : Gradient X" << endl;
    cout << "d : Gradient Y" << endl;
    cout << "x : Revenir au menu" << endl;

    cout << endl << "Saississez le lettre correspondante à l'action que vous souhaitez réaliser : ";
    cin >> choix;
    cout << endl;

    while (choix != 'a' && choix != 'b' && choix != 'c' && choix != 'd' && choix != 'x')
    {
        cout << "Saissi incorrecte, vérifier à nouveau : ";
        cin >> choix;
        cout << endl;
    }

    switch (choix)
    {
    case 'a':
        {
        His.push_back(Img);
        // Filtre précalculé
        Filtre F({{1.0/16, 1.0/8, 1.0/16}, {1.0/8, 1.0/4, 1.0/8}, {1.0/16, 1.0/8, 1.0/16}});
        Img = F.application(Img);
        break;
        }
    case 'b':
        {
        His.push_back(Img);
        // Filtre précalculé
        Filtre F({{1.0/256, 1.0/64, 6.0/256, 1.0/64, 1.0/256},
                 {1.0/64, 1.0/16, 1.0/8, 1.0/16, 1.0/64},
                 {6.0/256, 1.0/8, 36.0/256, 1.0/8, 6.0/256},
                 {1.0/64, 1.0/16, 1.0/8, 1.0/16, 1.0/64},
                 {1.0/256, 1.0/64, 6.0/256, 1.0/64, 1.0/256}});
        Img = F.application(Img);
        break;
        }
    case 'c':
        {
        His.push_back(Img);
        // Filtre précalculé
        Filtre F({{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}});
        Img = F.application(Img);
        break;
        }
    case 'd':
        {
        His.push_back(Img);
        // Filtre précalculé
        Filtre F({{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}});
        Img = F.application(Img);
        break;
        }
    default:
        break;
    }
}
