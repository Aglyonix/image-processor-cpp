#include "image.h"

/* |--------------------------| Niveaux de couleurs |--------------------------| */

// Retourne une Image Composante de l'image cible
Image Image::composanteRouge(bool alert) const
{
    // Deux affectations différetes car sinon vert et bleu font références au même
    // vector
    vector<vector<unsigned int>> sans_vert(_longueur, vector<unsigned int>(_largeur, 0));
    vector<vector<unsigned int>> sans_bleu(_longueur, vector<unsigned int>(_largeur, 0));

    Image Img(_rouge, sans_vert, sans_bleu, false);

    if (alert) cout << "|----------------| Image composante rouge créée de taille " << _longueur << " x " << _largeur << " |---------------|" << endl;
    return Img;
}

Image Image::composanteVert(bool alert) const
{
    // Deux affectations différetes car sinon vert et bleu font références au même
    // vector
    vector<vector<unsigned int>> sans_rouge(_longueur, vector<unsigned int>(_largeur, 0));
    vector<vector<unsigned int>> sans_bleu(_longueur, vector<unsigned int>(_largeur, 0));

    Image Img(sans_rouge, _vert, sans_bleu, false);

    if (alert) cout << "|----------------| Image composante vert créée de taille " << _longueur << " x " << _largeur << " |----------------|" << endl;
    return Img;
}

Image Image::composanteBleu(bool alert) const
{
    // Deux affectations différetes car sinon vert et bleu font références au même
    // vector
    vector<vector<unsigned int>> sans_rouge(_longueur, vector<unsigned int>(_largeur, 0));
    vector<vector<unsigned int>> sans_vert(_longueur, vector<unsigned int>(_largeur, 0));

    Image Img(sans_rouge, sans_vert, _bleu, false);

    if (alert) cout << "|----------------| Image composante bleu créée de taille " << _longueur << " x " << _largeur << " |----------------|" << endl;
    return Img;
}

// Retourne une Image grisée de l'image cible
Image Image::niveauxdeGris(bool alert) const
{
    Image Img(_longueur, _largeur, false);

    for (int i = 0; i < _longueur; i++)
    {
        for (int j = 0; j < _largeur; j++)
        {
            int moyenne = (_rouge[i][j] + _vert[i][j] + _bleu[i][j]) / 3;
            Img.get_r()[i][j] = moyenne;
            Img.get_v()[i][j] = moyenne;
            Img.get_b()[i][j] = moyenne;
        }
    }

    if (alert) cout << "|--------------------| Image Grisée créée de taille " << _longueur << " x " << _largeur << " |--------------------|" << endl;
    return Img;
}

// créer une nouvelle image uniquement en noir et blanc
Image Image::noireEtBlanc(bool alert) const
{
    Image Img(_longueur, _largeur, false);

    for (int i = 0; i < _longueur; i++)
    {
        for (int j = 0; j < _largeur; j++)
        {
            int moyenne = (_rouge[i][j] + _vert[i][j] + _bleu[i][j]) / 3;
            if (moyenne > 127)
            {
                Img.get_r()[i][j] = 255;
                Img.get_v()[i][j] = 255;
                Img.get_b()[i][j] = 255;
            }
            else
            {
                Img.get_r()[i][j] = 0;
                Img.get_v()[i][j] = 0;
                Img.get_b()[i][j] = 0;
            }
        }
    }

    if (alert)
        cout << "|-----------------| Image noire & blanc créée de taille "
             << _longueur << " x " << _largeur << " |-----------------|" << endl;
    return Img;
}

/* |------------------------------| Luminosités |------------------------------| */

Image Image::luminosityUp(float intensite, bool alert) const
{
    if (intensite <= 1) throw(invalid_argument("L'intensité de la luminosité doit être supérieur à 1 exclu pour augmenter la luminosité. Valeur donnée " + to_string(intensite) + " <= 1"));

    Image Img(_longueur, _largeur, false);

    for (int i = 0; i < _longueur; i++)
    {
        for (int j = 0; j < _largeur; j++)
        {
            int R = float(_rouge[i][j]) * intensite;
            int G = float(_vert[i][j]) * intensite;
            int B = float(_bleu[i][j]) * intensite;

            if (R > 255) Img.get_r()[i][j] = 255;
            else if (R < 0) Img.get_r()[i][j] = 0;
            else Img.get_r()[i][j] = int(R);

            if (G > 255) Img.get_v()[i][j] = 255;
            else if (G < 0) Img.get_v()[i][j] = 0;
            else Img.get_v()[i][j] = int(G);

            if (B > 255) Img.get_b()[i][j] = 255;
            else if (B < 0) Img.get_b()[i][j] = 0;
            else Img.get_b()[i][j] = int(B);
        }
    }

    if (alert) cout << "|-------------------| Image d'intensité lumineuse supérieur créée de taille " << _longueur << " x " << _largeur << " |-------------------|" << endl;
    return Img;
}

Image Image::luminosityDown(float intensite, bool alert) const
{
    if (1 < intensite) throw(invalid_argument("L'intensité de la luminosité doit être compris entre 0 et 1 exlu pour diminuer la luminosité. Valeur donnée " + to_string(intensite) + " > 1"));
    if (intensite < 0) throw(invalid_argument("L'intensité de la luminosité doit être positif compris entre 0 et 1 exlu pour diminuer la luminosité. Valeur donnée " + to_string(intensite) + " < 0"));

    Image Img(_longueur, _largeur, false);

    for (int i = 0; i < _longueur; i++)
    {
        for (int j = 0; j < _largeur; j++)
        {
            int R = float(_rouge[i][j]) * intensite;
            int G = float(_vert[i][j]) * intensite;
            int B = float(_bleu[i][j]) * intensite;

            if (R > 255) Img.get_r()[i][j] = 255;
            else if (R < 0) Img.get_r()[i][j] = 0;
            else Img.get_r()[i][j] = int(R);

            if (G > 255) Img.get_v()[i][j] = 255;
            else if (G < 0) Img.get_v()[i][j] = 0;
            else Img.get_v()[i][j] = int(G);

            if (B > 255) Img.get_b()[i][j] = 255;
            else if (B < 0) Img.get_b()[i][j] = 0;
            else Img.get_b()[i][j] = int(B);
        }
    }

    if (alert) cout << "|-------------------| Image d'intensité lumineuse supérieur créée de taille " << _longueur << " x " << _largeur << " |-------------------|" << endl;
    return Img;
}

/* |-------------------------------| Contraste |-------------------------------| */

Image Image::contrasteUp(float intensite, bool alert) const
{
    if (intensite <= 1) throw(invalid_argument("L'intensité du contraste doit être supérieur à 1 exclu pour augmenter le contraste. Valeur donnée " + to_string(intensite) + " <= 1"));

    Image Img(_longueur, _largeur, false);

    for (int i = 0; i < _longueur; i++)
    {
        for (int j = 0; j < _largeur; j++)
        {
            int R = 128 + ((int(_rouge[i][j]) - 128) * intensite);
            int G = 128 + ((int(_vert[i][j]) - 128) * intensite);
            int B = 128 + ((int(_bleu[i][j]) - 128) * intensite);

            if (R > 255) Img.get_r()[i][j] = 255;
            else if (R < 0) Img.get_r()[i][j] = 0;
            else Img.get_r()[i][j] = int(R);

            if (G > 255) Img.get_v()[i][j] = 255;
            else if (G < 0) Img.get_v()[i][j] = 0;
            else Img.get_v()[i][j] = int(G);

            if (B > 255) Img.get_b()[i][j] = 255;
            else if (B < 0) Img.get_b()[i][j] = 0;
            else Img.get_b()[i][j] = int(B);
        }
    }

    if (alert) cout << "|-------------------| Image contrasté supérieur créée de taille " << _longueur << " x " << _largeur << " |-------------------|" << endl;
    return Img;
}

Image Image::contrasteDown(float intensite, bool alert) const
{
    if (1 < intensite) throw(invalid_argument("L'intensité du contraste doit être compris entre 0 et 1 exlu pour diminuer le contraste. Valeur donnée " + to_string(intensite) + " > 1"));
    if (intensite < 0) throw(invalid_argument("L'intensité du contraste doit être positif compris entre 0 et 1 exlu pour diminuer le contraste. Valeur donnée " + to_string(intensite) + " < 0"));

    Image Img(_longueur, _largeur, false);

    for (int i = 0; i < _longueur; i++)
    {
        for (int j = 0; j < _largeur; j++)
        {
            int R = 128 + ((int(_rouge[i][j]) - 128) * intensite);
            int G = 128 + ((int(_vert[i][j]) - 128) * intensite);
            int B = 128 + ((int(_bleu[i][j]) - 128) * intensite);

            if (R > 255) Img.get_r()[i][j] = 255;
            else if (R < 0) Img.get_r()[i][j] = 0;
            else Img.get_r()[i][j] = int(R);

            if (G > 255) Img.get_v()[i][j] = 255;
            else if (G < 0) Img.get_v()[i][j] = 0;
            else Img.get_v()[i][j] = int(G);

            if (B > 255) Img.get_b()[i][j] = 255;
            else if (B < 0) Img.get_b()[i][j] = 0;
            else Img.get_b()[i][j] = int(B);
        }
    }

    if (alert) cout << "|-------------------| Image contrasté inférieur créée de taille " << _longueur << " x " << _largeur << " |-------------------|" << endl;
    return Img;
}
