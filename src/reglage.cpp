#include "image.h"

/* |--------------------------------| Reglage |--------------------------------| */

Image Image::reglageAuto(bool alert) const
{
    Image Img(_rouge, _vert, _bleu, false);

    float moyenne_lum = 0;
    int max_distance = 0;

    for (int i = 0; i < _longueur; i++)
    {
        for (int j = 0; j < _largeur; j++)
        {
            // Travailler avec des couleur à 0 est un problème pour ajuster la lumière

            Img.get_r()[i][j] = Img.get_r()[i][j] == 0 ? 1 : Img.get_r()[i][j];
            Img.get_v()[i][j] = Img.get_v()[i][j] == 0 ? 1 : Img.get_v()[i][j];
            Img.get_b()[i][j] = Img.get_b()[i][j] == 0 ? 1 : Img.get_b()[i][j];

            moyenne_lum += (Img.get_r()[i][j] + Img.get_v()[i][j] + Img.get_b()[i][j]) / 3;

            int distance_R = Img.get_r()[i][j] - 128 > 0 ? Img.get_r()[i][j] - 128 : -(Img.get_r()[i][j] - 128);
            int distance_G = Img.get_v()[i][j] - 128 > 0 ? Img.get_v()[i][j] - 128 : -(Img.get_v()[i][j] - 128);
            int distance_B = Img.get_b()[i][j] - 128 > 0 ? Img.get_b()[i][j] - 128 : -(Img.get_b()[i][j] - 128);

            if (max_distance < distance_R) max_distance = distance_R;
            if (max_distance < distance_G) max_distance = distance_G;
            if (max_distance < distance_B) max_distance = distance_B;
        }
    }

    // moyenne_lum toujours differents de 0 voir ci-dessus
    moyenne_lum = moyenne_lum / (_longueur * _largeur);

    float ajustement_lum = 128 / moyenne_lum;

    if (ajustement_lum < 1)
    {
        Img = Img.luminosityDown(ajustement_lum, false);
    }
    else if (ajustement_lum > 1)
    {
        Img = Img.luminosityUp(ajustement_lum, false);
    }
    // Sinon (ajustement_lum = 1) pas touche à l'image

    if (max_distance < 127)
    {
        float ajustment_ctrst = 128 / max_distance;

        Img = Img.contrasteUp(ajustment_ctrst, false);
    }

    if (alert) cout << "|-------------------| Image réglé automatiquement créée de taille " << _longueur << " x " << _largeur << " |-------------------|" << endl;
    return Img;
}
