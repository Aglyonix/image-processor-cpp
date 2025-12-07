#include "image.h"
#include <math.h>

/* |---------------------------| Rotation Couleurs |---------------------------| */

// Effectue une rotation des teintes de couleurs
Image Image::rotationCouleur(bool alert) const
{
    Image Img(_bleu, _rouge, _vert, false); // L'un des conctructeurs prends en paramètre les couleurs RGB, donc suffit de ramplacer RGB par BRG

    if (alert) cout << "|-------------------| Rotation des teintes effectué " << Img.lon() << " x " << Img.lar() << " |-------------------|" << endl;
    return Img;
}

// Blanchit les pixels proche de la couleur entrer en paramètres
Image Image::blanchirCouleur(int rouge, int vert, int bleu, bool alert) const
{
    // Verification
    if(rouge < 0 || rouge > 255) throw(invalid_argument("Lacouleur rouge entree en paramètre est incorrecte."));
    if(vert < 0 || vert > 255)   throw(invalid_argument("Lacouleur verte entree en paramètre est incorrecte."));
    if(bleu < 0 || bleu > 255)   throw(invalid_argument("Lacouleur bleu entree en paramètre est incorrecte.")) ;

    // Création de la nouvelle image
    Image Img(_longueur, _largeur, false);


    for (int i = 0; i < _longueur; i++)
    {
        for (int j = 0; j < _largeur; j++)
        {
            // Detection d'une couleur proche de la couleur entree en paramètre

            float ratio_couleur = sqrt(pow(rouge-_rouge[i][j], 2) + pow(vert-_vert[i][j], 2) + pow(bleu-_bleu[i][j], 2)) / sqrt(pow(rouge, 2) + pow(vert, 2) + pow(bleu, 2));

            // Affectation des couleurs à la nouvelle image
            if(ratio_couleur <= 0.1)
            {
                Img.get_r()[i][j] = 255;
                Img.get_v()[i][j] = 255;
                Img.get_b()[i][j] = 255;
            }
            else
            {
                Img.get_r()[i][j] = _rouge[i][j];
                Img.get_v()[i][j] = _vert[i][j] ;
                Img.get_b()[i][j] = _bleu[i][j] ;
            }

        }
    }

    if (alert) cout << "|-------------------| Image Blanchit " << Img.lon() << " x " << Img.lar() << " |-------------------|" << endl;
    return Img;
}
