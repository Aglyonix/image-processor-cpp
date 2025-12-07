#include <iostream>
#include <vector>
#include "image.h"

using namespace std;

void imageTest()
{
    {
        cout << endl << "|--------------------------------| Constructeurs |--------------------------------|" << endl << endl;
        vector<vector<unsigned int>> r1 = {{0, 0, 0}, {0, 0, 255, 255}, {0, 255, 255, 255}, {255, 255, 255, 255}};
        vector<vector<unsigned int>> v1 = {{0, 0, 255, 255}, {0, 255, 255, 255}, {255, 255, 255, 0}, {255, 255, 0, 0}};
        vector<vector<unsigned int>> b1 = {{255, 255, 0, 0}, {255, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};

        try
        {
            Image Img(r1, v1, b1, false);
            cerr << "Failed : Catching Error" << endl << endl;
        }
        catch(const invalid_argument & err)
        {
            cout << "Sucess : Catching Error : " << err.what() << endl << endl;
        }

        r1 = {{0, 0, 0, 0}, {0, 0, 552, 255}, {0, 255, 255, 255}, {255, 255, 255, 255}};

        try
        {
            Image Img(r1, v1, b1, false);
            cerr << "Failed : Catching Error" << endl << endl;
        }
        catch(const invalid_argument & err)
        {
            cout << "Sucess : Catching Error : " << err.what() << endl << endl;
        }

        r1 = {{0, 0, 0, 0}, {0, 0, 255, 255}, {0, 255, 255, 255}, {255, 255, 255, 255}, {0, 0, 0, 0}};

        try
        {
            Image Img(r1, v1, b1, false);
            cerr << "Failed : Catching Error" << endl << endl;
        }
        catch(const invalid_argument & err)
        {
            cout << "Sucess : Catching Error : " << err.what() << endl << endl;
        }

        r1 = {{0, 0, 0}, {0, 0, 255}, {0, 255, 255}, {255, 255, 255}};

        try
        {
            Image Img(r1, v1, b1, false);
            cerr << "Failed : Catching Error" << endl << endl;
        }
        catch(const invalid_argument & err)
        {
            cout << "Sucess : Catching Error : " << err.what() << endl << endl;
        }

        r1 = {{0, 0, 0, 0}, {0, 0, 255, 255}, {0, 255, 255, 255}, {255, 255, 255, 255}};

        try
        {
            Image Img(r1, v1, b1, false);
            cout << "Sucess : Initialisation Image" << endl << endl;
        }
        catch(const invalid_argument & err)
        {
            cerr << "Failed : Initialisation Image : " << err.what() << endl << endl;
        }

        cout << endl << "|---------------------------------| Composantes |---------------------------------|" << endl << endl;

        Image Img(r1, v1, b1);

        Image Img_rouge = Img.composanteRouge();

        if(Img_rouge.est_composanteRouge(Img))
        {
            cout << "Sucess : Cr�ation d'une composante rouge" << endl << endl;
        }
        else
        {
            cerr << "Failed : Cr�ation d'une composante rouge" << endl << endl;
        }

        cout << endl << "|----------------------------------| Detection |----------------------------------|" << endl << endl;

        if(Img.detection(255, 255, 0))
        {
            cout << "Sucess : Detection de couleur" << endl << endl;
        }
        else
        {
            cerr << "Failed : Detection de couleur" << endl << endl;
        }

        cout << endl << "|-------------------------------| Niveaux de gris |-------------------------------|" << endl << endl;

        Image Img_Gris = Img.niveauxdeGris();

        // Img_Gris.afficher();

        if(Img_Gris.get_pix(0, 0) == vector<unsigned int> {85, 85, 85} && Img_Gris.get_pix(1, 2) == vector<unsigned int> {170, 170, 170}) // (0, 0, 255) -> (85, 85, 85) && (255, 255, 0) -> (170, 170, 170)
        {
            cout << "Sucess : Niveaus de Gris" << endl << endl;
        }
        else
        {
            cerr << "Failed : Niveaus de Gris" << endl << endl;
        }

        cout << endl << "|--------------------------------| Noire & Blanc |--------------------------------|" << endl << endl;

        Image Img_noire = Img.noireEtBlanc();

        // Img_noire.afficher();

        if(Img_noire.get_pix(0, 0) == vector<unsigned int> {0, 0, 0} && Img_noire.get_pix(1, 2) == vector<unsigned int> {255, 255, 255}) // (0, 0, 255) -> (0, 0, 0) && (255, 255, 0) -> (255, 255, 255)
        {
            cout << "Sucess : Noire et Blanc" << endl << endl;
        }
        else
        {
            cerr << "Failed : Noire et Blanc" << endl << endl;
        }

        cout << endl << "|---------------------------------| Daltonismes |---------------------------------|" << endl << endl;

        Image Img_dep = Img.visionDeuteranopie();

        Img_dep.afficher();

        Image Img_pro = Img.visionProtanopie();

        Img_pro.afficher();

        Image Img_tri = Img.visionTritanopie();

        Img_tri.afficher();

        cout << endl << "|--------------------------------| Historigramme |--------------------------------|" << endl << endl;

        const vector<unsigned int> Img_hisG = Img.histogrammeGris();

        if(Img_hisG[85] == 10 && Img_hisG[170] == 6)
        {
            cout << "Sucess : Historigramme des nuances de gris" << endl << endl;
        }
        else
        {
            cerr << "Failed : Historigramme des nuances de gris" << endl << endl;
        }

        cout << endl;

        const vector<vector<vector<unsigned int>>> Img_hisC = Img.histogrammeCouleur();

        if(Img_hisC[0][0][255] == 3 && Img_hisC[0][255][0] == 4 && Img_hisC[255][0][0] == 3 && Img_hisC[255][255][0] == 6)
        {
            cout << "Sucess : Historigramme des nuances de gris" << endl << endl;
        }
        else
        {
            cerr << "Failed : Historigramme des nuances de gris" << endl << endl;
        }

        Img_dep.reglageAuto().afficher();
    }

    {
        cout << endl << "|---------------------------------| Luminosité |---------------------------------|" << endl << endl;
        vector<vector<unsigned int>> r1 = {{0, 255, 0}, {0, 255, 0}};
        vector<vector<unsigned int>> v1 = {{127, 200, 64}, {128, 200, 64}};
        vector<vector<unsigned int>> b1 = {{138, 127, 120}, {138, 128, 120}};

        Image Img(r1, v1, b1, false);

        Image Lum_Up = Img.luminosityUp(2);

        if(Lum_Up.get_pix(0, 0) == vector<unsigned int> {0, 254, 255} && Lum_Up.get_pix(0, 1) == vector<unsigned int> {255, 255, 254} && Lum_Up.get_pix(0, 2) == vector<unsigned int> {0, 128, 240})
        {
            cout << "Sucess : Augmentation de la luminosite" << endl << endl;
        }
        else
        {
            cerr << "Failed : Augmentation de la luminosite" << endl << endl;
        }

        Image Lum_Down = Img.luminosityDown();

        if(Lum_Down.get_pix(0, 0) == vector<unsigned int> {0, 63, 69} && Lum_Down.get_pix(0, 1) == vector<unsigned int> {127, 100, 63} && Lum_Down.get_pix(0, 2) == vector<unsigned int> {0, 32, 60})
        {
            cout << "Sucess : Diminution de la luminosite" << endl << endl;
        }
        else
        {
            cerr << "Failed : Diminution de la luminosite" << endl << endl;
        }

        cout << endl << "|---------------------------------| Contrastes |---------------------------------|" << endl << endl;

        Image Con_Up = Img.contrasteUp(2);

        if(Con_Up.get_pix(0, 0) == vector<unsigned int> {0, 126, 148} && Con_Up.get_pix(0, 1) == vector<unsigned int> {255, 255, 126} && Con_Up.get_pix(0, 2) == vector<unsigned int> {0, 0, 112})
        {
            cout << "Sucess : Augmentation du contraste" << endl << endl;
        }
        else
        {
            cerr << "Failed : Augmentation du contraste" << endl << endl;
        }

        Image Con_Down = Img.contrasteDown();

        if(Con_Down.get_pix(0, 0) == vector<unsigned int> {64, 127, 133} && Con_Down.get_pix(0, 1) == vector<unsigned int> {191, 164, 127} && Con_Down.get_pix(0, 2) == vector<unsigned int> {64, 96, 124})
        {
            cout << "Sucess : Diminution du contraste" << endl << endl;
        }
        else
        {
            cerr << "Failed : Diminution du contraste" << endl << endl;
        }
    }
}
