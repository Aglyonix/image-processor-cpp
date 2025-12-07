#include "image.h"

/* |------------------------------| Daltonismes |------------------------------| */

void menuDaltonien(Image &Img, vector<Image> &His)
{
    char type_daltonisme;

    cout << "Quelle forme de Daltonisme voulez-vous voir ?" << endl;
    cout << "a : Deuteranopie" << endl;
    cout << "b : Protanopie" << endl;
    cout << "c : Tritanopie" << endl;
    cout << "x : Revenir au menu" << endl;

    cout << endl << "Saississez le lettre correspondante à l'action que vous souhaitez " "réaliser : ";
    cin >> type_daltonisme;
    cout << endl;

    while (type_daltonisme != 'a' && type_daltonisme != 'b' && type_daltonisme != 'c' && type_daltonisme != 'x')
    {
        cout << "Saissi incorrecte, vérifier à nouveau : ";
        cin >> type_daltonisme;
        cout << endl;
    }

    switch (type_daltonisme)
    {
    case 'a':
        His.push_back(Img);
        Img = Img.visionDeuteranopie();
        cout << endl;
        break;
    case 'b':
        His.push_back(Img);
        Img = Img.visionProtanopie();
        cout << endl;
        break;
    case 'c':
        His.push_back(Img);
        Img = Img.visionTritanopie();
        cout << endl;
        break;
    default:
        break;
    }
}

/* |------------------------------| Composantes |------------------------------| */

void menuComposante(Image &Img, vector<Image> &His)
{
    char choix;

    cout << "Choisissez la composante : " << endl;
    cout << "a : Composante rouge" << endl;
    cout << "b : Composante vert" << endl;
    cout << "c : Composante bleu" << endl;
    cout << "x : Revenir au menu" << endl;

    cout << endl << "Saississez le lettre correspondante à l'action que vous souhaitez réaliser : ";
    cin >> choix;
    cout << endl;

    while (choix != 'a' && choix != 'b' && choix != 'c' && choix != 'x')
    {
        cout << "Saissi incorrecte, vérifier à nouveau : ";
        cin >> choix;
        cout << endl;
    }

    switch (choix)
    {
    case 'a':
        His.push_back(Img);
        Img = Img.composanteRouge();
        cout << endl;
        break;
    case 'b':
        His.push_back(Img);
        Img = Img.composanteVert();
        cout << endl;
        break;
    case 'c':
        His.push_back(Img);
        Img = Img.composanteBleu();
        cout << endl;
        break;
    default:
        break;
    }
}

/* |-------------------------------| Detection |-------------------------------| */

void menuDetection(Image &Img)
{
    unsigned int r, v, b;
    bool saisi_correct = false;

    while (!saisi_correct)
    {
        cout << endl << "Saississez les intensités de chaque couleurs : " << endl;
        cout << "r :"; cin >> r;
        cout << "v :"; cin >> v;
        cout << "b :"; cin >> b;
        cout << endl;

        try
        {
            if (Img.detection(r, v, b)) // Lance une erreur si mal saisi
            {
                cout << "La couleur rechercher existe dans votre image" << endl << endl;
            }
            else
            {
                cout << "La couleur rechercher n'existe pas dans votre image" << endl << endl;
            }

            saisi_correct = true;
        }
        catch (const invalid_argument &e)
        {
            cerr << e.what() << endl;
        }
    }
}

/* |------------------------------| Histogramme |------------------------------| */

void menuHistogramme(Image &Img, char &methode, const string &split)
{
    char choix;

    cout << "Choisissez l'histogramme à rendre : " << endl;
    cout << "a : Histogramme Gris" << endl;
    cout << "b : Histogramme Couleurs" << endl;
    cout << "c : Changer la methode d'affichage" << endl;
    cout << "x : Revenir au menu" << endl;

    cout << endl << "Saississez le lettre correspondante à l'action que vous souhaitez réaliser : ";
    cin >> choix;
    cout << endl;

    while (choix != 'a' && choix != 'b' && choix != 'c' && choix != 'x')
    {
        cout << "Saissi incorrecte, vérifier à nouveau : ";
        cin >> choix;
        cout << endl;
    }

    switch (choix)
    {
    case 'a':
    {
        vector<unsigned int> Histogramme = Img.histogrammeGris();
        // Affichage Historigramme des nuances de gris
        for (int i = 0; i < 256; i++)
        {
            if (Histogramme[i] == 0) cout << ".";
            else cout << Histogramme[i];
            if ((i + 1) % 16 == 0) cout << endl;
            if (i != 255 && (i + 1) % 16 != 0) cout << "\t";
        }
        break;
    }
    case 'b':
    {
        // Affichage Historigramme des couleurs
        switch (methode)
        {
        case 'c':
        {
            char couleur;

            cout << "Choisissez la ou les couleurs à rendre : " << endl;
            cout << "a : Rouge" << endl;
            cout << "b : Vert" << endl;
            cout << "c : Bleu" << endl;
            cout << "d : Toutes" << endl;
            cout << "x : Revenir au menu" << endl;

            cout << endl << "Saississez le lettre correspondante à l'action que vous souhaitez réaliser : ";
            cin >> couleur;
            cout << endl;

            while (couleur != 'a' && couleur != 'b' && couleur != 'c' && couleur != 'd' && couleur != 'x')
            {
                cout << "Saissi incorrecte, vérifier à nouveau : ";
                cin >> couleur;
                cout << endl;
            }

            switch (couleur)
            {
            case 'a':
            {
                vector<unsigned int> Histogramme = Img.histogrammeRouge();
                for (int i = 0; i < 256; i++)
                {
                    if (Histogramme[i] == 0) cout << ".";
                    else cout << Histogramme[i];
                    if ((i + 1) % 16 == 0) cout << endl;
                    if (i != 255 && (i + 1) % 16 != 0) cout << "\t";
                }
                break;
            }
            case 'b':
            {
                vector<unsigned int> Histogramme = Img.histogrammeVert();
                for (int i = 0; i < 256; i++)
                {
                    if (Histogramme[i] == 0) cout << ".";
                    else cout << Histogramme[i];
                    if ((i + 1) % 16 == 0) cout << endl;
                    if (i != 255 && (i + 1) % 16 != 0) cout << "\t";
                }
                break;
            }
            case 'c':
            {
                vector<unsigned int> Histogramme = Img.histogrammeBleu();
                for (int i = 0; i < 256; i++)
                {
                    if (Histogramme[i] == 0) cout << ".";
                    else cout << Histogramme[i];
                    if ((i + 1) % 16 == 0) cout << endl;
                    if (i != 255 && (i + 1) % 16 != 0) cout << "\t";
                }
                break;
            }
            case 'd':
            {
                vector<vector<unsigned int>> Histogrammes = {Img.histogrammeRouge(false), Img.histogrammeVert(false), Img.histogrammeBleu(false)};

                for (int j = 0; j < 3; j++)
                {
                    for (int i = 0; i < 256; i++)
                    {
                        if (Histogrammes[j][i] == 0) cout << ".";
                        else cout << Histogrammes[j][i];
                        if ((i + 1) % 16 == 0) cout << endl;
                        if (i != 255 && (i + 1) % 16 != 0) cout << "\t";
                    }

                    if (j != 2) cout << split << endl;
                }
                break;
            }
            default:
                break;
            }
        }
        case 'p':
        {
            vector<vector<vector<unsigned int>>> Histogramme = Img.histogrammeCouleur();

            for (int i = 0; i < 256; i++)
            {
                for (int j = 0; j < 256; j++)
                {
                    for (int k = 0; k < 256; k++)
                    {
                        if (Histogramme[i][j][k] != 0) cout << "r: " << i << "\tv: " << j << "\tb: " << k << "\t| " << Histogramme[i][j][k] << endl;
                    }
                }
            }
            break;
        }
        default:
            break;
        }
        break;
    }
    case 'c':
    {
        char affichage;

        cout << "Choisissez la méthode d'affichage : " << endl;
        cout << "a : Par Histogramme de couleur" << endl;
        cout << "b : Par pixel" << endl;
        cout << "x : Revenir au menu" << endl;

        cout << endl << "Saississez le lettre correspondante à l'action que vous souhaitez réaliser : ";
        cin >> affichage;
        cout << endl;

        while (affichage != 'a' && affichage != 'b' && affichage != 'x')
        {
            cout << "Saissi incorrecte, vérifier à nouveau : ";
            cin >> affichage;
            cout << endl;
        }

        switch (affichage)
        {
        case 'a':
            methode = 'c';
            break;
        case 'b':
            methode = 'p';
            break;
        default:
            break;
        }
    }
    default:
        break;
    }
}

/* |------------------------------| Luminosités |------------------------------| */

void menuLuminosite(Image &Img, vector<Image> &His)
{
    char choix;
    float intensite;
    bool saisi_correct = false;

    cout << "Modifier la luminosité : " << endl;
    cout << "a : Augmenter la luminosité" << endl;
    cout << "b : Diminuer la luminosité" << endl;
    cout << "x : Revenir au menu" << endl;

    cout << endl << "Saississez le lettre correspondante à l'action que vous souhaitez réaliser : ";
    cin >> choix;
    cout << endl;

    while (choix != 'a' && choix != 'b' && choix != 'x')
    {
        cout << "Erreur, saisir un choix valide: " << endl;
        cin >> choix;
        cout << endl;
    }

    while (!saisi_correct)
    {
        cout << endl << "Saississez l'intensite de luminosite : ";
        cin >> intensite;
        cout << endl;

        try
        {
            switch (choix)
            {
            case 'a':
                His.push_back(Img);
                Img = Img.luminosityUp(intensite);
                cout << endl;
                saisi_correct = true;
                break;
            case 'b':
                His.push_back(Img);
                Img = Img.luminosityDown(intensite);
                cout << endl;
                saisi_correct = true;
                break;
            default:
                saisi_correct = true;
                break;
            }
        }
        catch (const invalid_argument &e)
        {
            cerr << e.what() << endl << endl;
        }
    }
}

/* |-------------------------------| Contraste |-------------------------------| */

void menuContraste(Image &Img, vector<Image> &His)
{
    char choix;
    float intensite;
    bool saisi_correct = false;

    cout << "Modifier le contraste : " << endl;
    cout << "a : Augmenter le contraste" << endl;
    cout << "b : Diminuer le contraste" << endl;
    cout << "x : Revenir au menu" << endl;

    cout << endl << "Saississez le lettre correspondante à l'action que vous souhaitez réaliser : ";
    cin >> choix;
    cout << endl;

    while (choix != 'a' && choix != 'b' && choix != 'x')
    {
        cout << "Saissi incorrecte, vérifier à nouveau : ";
        cin >> choix;
        cout << endl;
    }

    while (!saisi_correct)
    {
        cout << endl << "Saississez l'intensite du contraste : ";
        cin >> intensite;
        cout << endl;

        try
        {
            switch (choix)
            {
            case 'a':
                His.push_back(Img);
                Img = Img.contrasteUp(intensite);
                cout << endl;
                saisi_correct = true;
                break;
            case 'b':
                His.push_back(Img);
                Img = Img.contrasteDown(intensite);
                cout << endl;
                saisi_correct = true;
                break;
            default:
                saisi_correct = true;
                break;
            }
        }
        catch (const invalid_argument &e)
        {
            cerr << e.what() << endl << endl;
        }
    }
}

/* |-------------------------------| Rotations |-------------------------------| */

void menuRotation(Image &Img, vector<Image> &His)
{
    char choix;

    cout << "Rotation de l'image : " << endl;
    cout << "a : Rotation à +90°" << endl;
    cout << "b : Rotation à -90°" << endl;
    cout << "x : Revenir au menu" << endl;

    cout << endl << "Saississez le lettre correspondante à l'action que vous souhaitez réaliser : ";
    cin >> choix;
    cout << endl;

    while (choix != 'a' && choix != 'b' && choix != 'x')
    {
        cout << "Saissi incorrecte, vérifier à nouveau : ";
        cin >> choix;
        cout << endl;
    }

    switch (choix)
    {
    case 'a':
        His.push_back(Img);
        Img = Img.rotationD();
        break;
    case 'b':
        His.push_back(Img);
        Img = Img.rotationG();
        break;
    default:
        break;
    }
}

/* |--------------------------------| Rogners |--------------------------------| */

void menuRogner(Image &Img, vector<Image> &His)
{
    char choix;
    int nb;
    bool saisi_correct = false;

    cout << "Rogner l'image: " << endl;
    cout << "a : Haut" << endl;
    cout << "b : Bas" << endl;
    cout << "c : Gauche" << endl;
    cout << "d : Droite" << endl;
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

    cout << endl << "Saississez le nombre de case à rogner : ";
    cin >> nb;
    cout << endl;

    while (!saisi_correct)
    {
        try
        {
            switch (choix)
            {
            case 'a':
                His.push_back(Img);
                Img = Img.rognerH(nb);
                saisi_correct = true;
                break;
            case 'b':
                His.push_back(Img);
                Img = Img.rognerB(nb);
                saisi_correct = true;
                break;
            case 'c':
                His.push_back(Img);
                Img = Img.rognerG(nb);
                saisi_correct = true;
                break;
            case 'd':
                His.push_back(Img);
                Img = Img.rognerD(nb);
                saisi_correct = true;
                break;
            default:
                saisi_correct = true;
                break;
            }
        }
        catch (const invalid_argument &e)
        {
            cerr << e.what() << endl << endl;

            cout << "Saissi incorrecte, vérifier à nouveau : ";
            cin >> nb;
            cout << endl;
        }
    }
}

/* |-------------------------------| Symétries |-------------------------------| */

void menuSymetrie(Image &Img, vector<Image> &His)
{
    char choix;

    cout << "Rotorner l'image : " << endl;
    cout << "a : Verticalement" << endl;
    cout << "b : Horizontalement" << endl;
    cout << "x : Revenir au menu" << endl;

    cout << endl << "Saississez le lettre correspondante à l'action que vous souhaitez réaliser : ";
    cin >> choix;
    cout << endl;

    while (choix != 'a' && choix != 'b' && choix != 'x')
    {
        cout << "Saissi incorrecte, vérifier à nouveau : ";
        cin >> choix;
        cout << endl;
    }

    switch (choix)
    {
    case 'a':
        His.push_back(Img);
        Img = Img.retournementV();
        break;
    case 'b':
        His.push_back(Img);
        Img = Img.retournementH();
        break;
    default:
        break;
    }
}

/* |-------------------------------| Zooms |-------------------------------| */

void menuZoom(Image &Img, vector<Image> &His)
{
    char choix;
    int nb;
    bool saisi_correct = false;

    cout << "Zoomer l'image: " << endl;
    cout << "a : Agrandir" << endl;
    cout << "b : Rétrécir" << endl;
    cout << "x : Revenir au menu" << endl;

    cout << endl << "Saississez le lettre correspondante à l'action que vous souhaitez réaliser : ";
    cin >> choix;
    cout << endl;

    while (choix != 'a' && choix != 'b' && choix != 'x')
    {
        cout << "Saissi incorrecte, vérifier à nouveau : ";
        cin >> choix;
        cout << endl;
    }

    cout << endl << "Saississez l'intensité du zoom : ";
    cin >> nb;
    cout << endl;

    while (!saisi_correct)
    {
        try
        {
            switch (choix)
            {
            case 'a':
                His.push_back(Img);
                Img = Img.agrandissement(nb);
                saisi_correct = true;
                break;
            case 'b':
                His.push_back(Img);
                Img = Img.retrecissement(nb);
                saisi_correct = true;
                break;
            default:
                saisi_correct = true;
                break;
            }
        }
        catch (const invalid_argument &e)
        {
            cerr << e.what() << endl << endl;

            cout << "Saissi incorrecte, vérifier à nouveau : ";
            cin >> nb;
            cout << endl;
        }
    }
}

void menuBlanchissement(Image &Img, vector<Image> &His)
{
    int r; int g; int b;
    bool saisi_correct = false;

    cout << endl << "Saississez la couleur à blanchir : " << endl;
    cout << "Rouge: "; cin >> r;
    cout << "Vert : "; cin >> g;
    cout << "Bleu : "; cin >> b;
    cout << endl;

    while (!saisi_correct)
    {
        try
        {
            His.push_back(Img);
            Img = Img.blanchirCouleur(r, g, b); // Retoune une erreur si r , g ou b mal saisie
            saisi_correct = true;
        }
        catch (const invalid_argument &e)
        {
            cerr << e.what() << endl << endl;

            cout << "Saissi incorrecte, vérifier à nouveau la couleur à blanchir : " << endl;
            cout << "Rouge: "; cin >> r;
            cout << "Vert : "; cin >> g;
            cout << "Bleu : "; cin >> b;
            cout << endl;
        }
    }
}
