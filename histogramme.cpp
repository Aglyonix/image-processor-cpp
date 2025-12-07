#include "image.h"

/* |------------------------------| Histogramme |------------------------------| */

const vector<unsigned int> Image::histogrammeGris(bool alert) const
{
    vector<unsigned int> historigramme(256, 0);

    for (int i = 0; i < _longueur; i++)
    {
        for (int j = 0; j < _largeur; j++)
        {
            int moyenne = (_rouge[i][j] + _vert[i][j] + _bleu[i][j]) / 3;

            historigramme[moyenne] += 1;
        }
    }

    if (alert) cout << "|-------------------| Historigramme des nuances de gris créée |-------------------|" << endl;
    return historigramme;
}

const vector<unsigned int> Image::histogrammeRouge(bool alert) const
{
    vector<unsigned int> historigramme(256, 0);

    for (int i = 0; i < _longueur; i++)
    {
        for (int j = 0; j < _largeur; j++)
        {
            historigramme[_rouge[i][j]] += 1;
        }
    }

    if (alert) cout << "|-------------------| Historigramme des nuances de rouge créée |------------------|" << endl;
    return historigramme;
}

const vector<unsigned int> Image::histogrammeVert(bool alert) const
{
    vector<unsigned int> historigramme(256, 0);

    for (int i = 0; i < _longueur; i++)
    {
        for (int j = 0; j < _largeur; j++)
        {
            historigramme[_vert[i][j]] += 1;
        }
    }

    if (alert) cout << "|-------------------| Historigramme des nuances de vert créée |-------------------|" << endl;
    return historigramme;
}

const vector<unsigned int> Image::histogrammeBleu(bool alert) const
{
    vector<unsigned int> historigramme(256, 0);

    for (int i = 0; i < _longueur; i++)
    {
        for (int j = 0; j < _largeur; j++)
        {
            historigramme[_bleu[i][j]] += 1;
        }
    }

    if (alert) cout << "|-------------------| Historigramme des nuances de bleu créée |-------------------|" << endl;
    return historigramme;
}

const vector<vector<vector<unsigned int>>> Image::histogrammeCouleur(bool alert) const
{
    vector<vector<vector<unsigned int>>> historigramme(256, vector<vector<unsigned int>>(256, vector<unsigned int>(256, 0)));

    for (int i = 0; i < _longueur; i++)
    {
        for (int j = 0; j < _largeur; j++)
        {
            historigramme[_rouge[i][j]][_vert[i][j]][_bleu[i][j]] += 1;
        }
    }

    if (alert) cout << "|-----------------| Historigramme des nuances de couleurs crée |-----------------|" << endl;
    return historigramme;
}
