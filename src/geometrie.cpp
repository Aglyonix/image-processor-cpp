#include "image.h"

/* |--------------------------------| Rogners |--------------------------------| */

Image Image::rognerD(unsigned int nb, bool alert) const
{
    if (nb > _largeur) throw(invalid_argument("Le nombre de pixels à rogner doit être inférieur ou égal à " + to_string(_largeur)));

    Image Img(_longueur, _largeur - nb, false);

    for (int i = 0; i < Img.lon(); i++)
    {
        for (int j = 0; j < Img.lar(); j++)
        {
            Img.get_r()[i][j] = _rouge[i][j];
            Img.get_v()[i][j] = _vert[i][j];
            Img.get_b()[i][j] = _bleu[i][j];
        }
    }

    if (alert) cout << "|-------------------| Image Rogné de " << nb << " case à droite | Nouvelle dimension : " << Img.lon() << " x " << Img.lar() << " |-------------------|"<< endl;
    return Img;
}

Image Image::rognerG(unsigned int nb, bool alert) const
{
    if (nb > _largeur) throw(invalid_argument("Le nombre de pixels à rogner doit être inférieur ou égal à " + to_string(_largeur)));

    Image Img(_longueur, _largeur - nb, false);

    for (int i = 0; i < Img.lon(); i++)
    {
        for (int j = 0; j < Img.lar(); j++)
        {
            Img.get_r()[i][j] = _rouge[i][j+nb];
            Img.get_v()[i][j] = _vert[i][j+nb] ;
            Img.get_b()[i][j] = _bleu[i][j+nb] ;
        }
    }

    if (alert) cout << "|-------------------| Image Rogné de " << nb << " case à gauche | Nouvelle dimension : " << Img.lon() << " x " << Img.lar() << " |-------------------|"<< endl;
    return Img;
}

Image Image::rognerH(unsigned int nb, bool alert) const
{

    if (nb > _longueur) throw(invalid_argument("Le nombre de pixels à rogner doit être inférieur ou égal à " + to_string(_longueur)));

    Image Img(_longueur - nb, _largeur, false);

    for (int i = 0; i < Img.lon(); i++)
    {
        for (int j = 0; j < Img.lar(); j++)
        {
            Img.get_r()[i][j] = _rouge[i+nb][j];
            Img.get_v()[i][j] = _vert[i+nb][j];
            Img.get_b()[i][j] = _bleu[i+nb][j];
        }
    }

    if (alert) cout << "|-------------------| Image Rogné de " << nb << " case en haut | Nouvelle dimension : " << Img.lon() << " x " << Img.lar() << " |-------------------|"<< endl;
    return Img;
}

Image Image::rognerB(unsigned int nb, bool alert) const
{

    if (nb > _longueur) throw(invalid_argument("Le nombre de pixels à rogner doit être inférieur ou égal à " + to_string(_longueur)));

    Image Img(_longueur - nb, _largeur, false);

    for (int i = 0; i < Img.lon(); i++)
    {
        for (int j = 0; j < Img.lar(); j++)
        {
            Img.get_r()[i][j] = _rouge[i][j];
            Img.get_v()[i][j] = _vert[i][j];
            Img.get_b()[i][j] = _bleu[i][j];
        }
    }

    if (alert) cout << "|-------------------| Image Rogné de " << nb << " case en bas | Nouvelle dimension : " << Img.lon() << " x " << Img.lar() << " |-------------------|"<< endl;
    return Img;
}

/* |-------------------------------| Rotations |-------------------------------| */

Image Image::rotationG(bool alert) const
{
    Image Img(_longueur, _largeur, false);

    for (int i = 0; i < _longueur; i++)
    {
        for (int j = 0; j < _largeur; j++)
        {
            Img.get_r()[_longueur - (j + 1)][i] = _rouge[i][j];
            Img.get_v()[_longueur - (j + 1)][i] = _vert [i][j];
            Img.get_b()[_longueur - (j + 1)][i] = _bleu [i][j];
        }
    }

    if (alert) cout << "|-------------------| Image Tourné à 90° à droite créée " << _longueur << " x " << _largeur << " |-------------------|" << endl;
    return Img;
}

Image Image::rotationD(bool alert) const
{
    Image Img(_longueur, _largeur, false);

    for (int i = 0; i < _longueur; i++)
    {
        for (int j = 0; j < _largeur; j++)
        {
            Img.get_r()[j][_largeur - (i + 1)] = _rouge[i][j];
            Img.get_v()[j][_largeur - (i + 1)] = _vert [i][j];
            Img.get_b()[j][_largeur - (i + 1)] = _bleu [i][j];
        }
    }

    if (alert) cout << "|-------------------| Image Tourné à 90° à gauche créée " << _longueur << " x " << _largeur << " |-------------------|" << endl;
    return Img;
}

/* |-------------------------------| Symètries |-------------------------------| */

Image Image::retournementV(bool alert) const
{
    Image Img(_longueur, _largeur, false);

    for (int i = 0; i < _longueur; i++)
    {
        for (int j = 0; j < _largeur; j++)
        {
            Img.get_r()[j][i] = _rouge[j][_largeur - (i + 1)];
            Img.get_v()[j][i] = _vert [j][_largeur - (i + 1)];
            Img.get_b()[j][i] = _bleu [j][_largeur - (i + 1)];
        }
    }

    if (alert) cout << "|-------------------| Image retourner verticalement " << _longueur << " x " << _largeur << " |-------------------|" << endl;
    return Img;
}

Image Image::retournementH(bool alert) const
{
    Image Img(_longueur, _largeur, false);

    for (int i = 0; i < _longueur; i++)
    {
        for (int j = 0; j < _largeur; j++)
        {
            Img.get_r()[i][j] = _rouge[_longueur - (i + 1)][j];
            Img.get_v()[i][j] = _vert [_longueur - (i + 1)][j];
            Img.get_b()[i][j] = _bleu [_longueur - (i + 1)][j];
        }
    }

    if (alert) cout << "|-------------------| Image retourner horizontalement " << _longueur << " x " << _largeur << " |-------------------|" << endl;
    return Img;
}

/* |---------------------------------| Zooms |---------------------------------| */

Image Image::agrandissement(int zoom, bool alert) const
{
    if(zoom < 2) throw(invalid_argument("L'intensite du zoom ne peut pas être inférieur à 2."));

    Image Img(_longueur*zoom, _largeur*zoom, false);

    for (int i = 0; i < _longueur; i++)
    {
        for (int j = 0; j < _largeur; j++)
        {
            for (int k = 0; k < zoom; k++)
            {
                for (int l = 0; l < zoom; l++)
                {
                    Img.get_r()[i*zoom+k][j*zoom+l] = _rouge[i][j];
                    Img.get_v()[i*zoom+k][j*zoom+l] = _vert [i][j];
                    Img.get_b()[i*zoom+k][j*zoom+l] = _bleu [i][j];
                }
            }
        }
    }

    if (alert) cout << "|-------------------| Image agrandit " << Img.lon() << " x " << Img.lar() << " |-------------------|" << endl;
    return Img;
}

Image Image::retrecissement(int zoom, bool alert) const
{
    if(zoom < 2) throw(invalid_argument("L'intensite du zoom ne peut pas être inférieur à 2."));

    Image Img(_longueur/zoom, _largeur/zoom, false);

    for (int i = 0; i < Img.lon(); i++)
    {
        for (int j = 0; j < Img.lar(); j++)
        {
            int moyenne_r = 0;
            int moyenne_v = 0;
            int moyenne_b = 0;

            for (int k = 0; k < zoom; k++)
            {
                for (int l = 0; l < zoom; l++)
                {
                    moyenne_r += _rouge[i*zoom+k][j*zoom+l];
                    moyenne_v += _vert [i*zoom+k][j*zoom+l];
                    moyenne_b += _bleu [i*zoom+k][j*zoom+l];
                }
            }

            Img.get_r()[i][j] = moyenne_r / zoom*zoom;
            Img.get_v()[i][j] = moyenne_v / zoom*zoom;
            Img.get_b()[i][j] = moyenne_b / zoom*zoom;
        }
    }

    if (alert) cout << "|-------------------| Image rétrécit " << Img.lon() << " x " << Img.lar() << " |-------------------|" << endl;
    return Img;
}

// Pas Fini
Image Image::zoom(float zoom, bool alert) const
{
    if(zoom <= 0) throw(invalid_argument("L'intensite du zoom ne peut pas être inférieur ou égale à 0."));

    Image Img(_longueur*zoom, _largeur*zoom, false);

    for (int i = 0; i < _longueur; i++)
    {
        for (int j = 0; j < _largeur; j++)
        {
            // Origine est à 0, 0 donc P - O = P

            Img.get_r()[i*zoom][j*zoom] = _rouge[i][j];
            Img.get_v()[i*zoom][j*zoom] = _vert [i][j];
            Img.get_b()[i*zoom][j*zoom] = _bleu [i][j];
        }
    }

    if (alert) cout << "|-------------------| Image zoomer " << Img.lon() << " x " << Img.lar() << " |-------------------|" << endl;
    return Img;
}
