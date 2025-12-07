#include "image.h"

/* |------------------------------| Daltonismes |------------------------------| */

// Absence de vert :/
Image Image::visionDeuteranopie(bool alert) const
{
    Image Img(_longueur, _largeur, false);

    for (int i = 0; i < _longueur; i++)
    {
        for (int j = 0; j < _largeur; j++)
        {
            // RGB Espace de travail : Adobe RGB 1998 ; Reference Blanc : D65
            // RGB Couleur des pixel (synthése d'addition)
            // XYZ

            // Conversion RGB -> XYZ
            float X =
                _rouge[i][j] * 0.5767 + _vert[i][j] * 0.1855 + _bleu[i][j] * 0.1881;
            float Y =
                _rouge[i][j] * 0.2973 + _vert[i][j] * 0.6273 + _bleu[i][j] * 0.0752;
            float Z =
                _rouge[i][j] * 0.0270 + _vert[i][j] * 0.0706 + _bleu[i][j] * 0.9911;

            // Conversion XYZ -> LMS
            float L = X * 0.2105 + Y * 0.8550 + Z * -0.0396;
            float M = X * -0.4170 + Y * 1.1772 + Z * 0.0786;
            float S = X * 0 + Y * 0 + Z * 0.5168;

            // Affectation de la défaillance de cône M
            // L = L*1 + M*0 + S*0; // Revien à faire L = L
            // M = L*1.101 + M*0 + S*-0.009;
            // S = L*0 + M*0 + S*1; // Revien à faire S = S

            // Conversion LMS -> XYZ
            X = L * 1.9479 + M * -1.4147 + S * -0.3644;
            Y = L * 0.69 + M * 0.3483 + S * -0.0001;
            Z = L * 0 + M * 0 + S * 1.9349;

            // Conversion XYZ -> RGB
            float R = X * 2.0413 + Y * -0.5649 + Z * -0.3446;
            float G = X * -0.9692 + Y * 1.8760 + Z * 0.0415;
            float B = X * 0.0134 + Y * -0.1183 + Z * 1.0154;

            /*
            // D'aprés https://github.com/MaPePeR/jsColorblindSimulator/blob/master/colorblind.js
            float R = _rouge[i][j]*0.63642 + _vert[i][j]*0.17525 + _bleu[i][j]*7.0036 ;
            float G = _rouge[i][j]*0.5537  + _vert[i][j]*0.15463 + _bleu[i][j]*6.18012;
            float B = _rouge[i][j]*0       + _vert[i][j]*0       + _bleu[i][j]*0.12121;
            */

            // Valeurs finaux
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

    if (alert) cout << "|------------------| Image deuteranope créée de taille " << _longueur << " x " << _largeur << " |------------------|" << endl;
    return Img;
}

// Absence de rouge :/
Image Image::visionProtanopie(bool alert) const
{
    Image Img(_longueur, _largeur, false);

    for (int i = 0; i < _longueur; i++)
    {
        for (int j = 0; j < _largeur; j++)
        {
            // RGB Espace de travail : Adobe RGB 1998 ; Reference Blanc : D65

            // Conversion RGB -> XYZ
            int X = _rouge[i][j] * 0.5767 + _vert[i][j] * 0.1855 + _bleu[i][j] * 0.1881;
            int Y = _rouge[i][j] * 0.2973 + _vert[i][j] * 0.6273 + _bleu[i][j] * 0.0752;
            int Z = _rouge[i][j] * 0.0270 + _vert[i][j] * 0.0706 + _bleu[i][j] * 0.9911;

            // Conversion XYZ -> LMS
            int L = X * 0.2105 + Y * 0.8550 + Z *-0.0396;
            int M = X *-0.4170 + Y * 1.1772 + Z * 0.0786;
            int S = X * 0      + Y * 0      + Z * 0.5168;

            // Affectation de la défaillance de cône L
            L = L * 0 + M * 0.9082 + S * 0.0081;
            // M = L*0 + M*1 + S*0; // Revien à faire M = M
            // S = L*0 + M*0 + S*1; // Revien à faire S = S

            // Conversion LMS -> XYZ
            X = L * 1.9473 + M *-1.4144 + S *-0.3647;
            Y = L * 0.6899 + M * 0.3483 + S * 0     ;
            Z = L * 0      + M * 0      + S * 1.9348;

            // Conversion XYZ -> RGB
            int R = X * 2.0413 + Y *-0.5649 + Z *-0.3446;
            int G = X *-0.9692 + Y * 1.8760 + Z * 0.0415;
            int B = X * 0.0134 + Y *-0.1183 + Z * 1.0154;

            // Valeurs finaux
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

    if (alert) cout << "|-------------------| Image Protanope créée de taille " << _longueur << " x " << _largeur << " |-------------------|" << endl;
    return Img;
}

// Absence de bleu :/
Image Image::visionTritanopie(bool alert) const
{
    Image Img(_longueur, _largeur, false);

    for (int i = 0; i < _longueur; i++)
    {
        for (int j = 0; j < _largeur; j++)
        {
            // RGB Espace de travail : Adobe RGB 1998 ; Reference Blanc : D65

            // Conversion RGB -> XYZ
            int X = _rouge[i][j] * 0.5767 + _vert[i][j] * 0.1855 + _bleu[i][j] * 0.1881;
            int Y = _rouge[i][j] * 0.2973 + _vert[i][j] * 0.6273 + _bleu[i][j] * 0.0752;
            int Z = _rouge[i][j] * 0.0270 + _vert[i][j] * 0.0706 + _bleu[i][j] * 0.9911;

            // Conversion XYZ -> LMS
            int L = X * 0.2105 + Y * 0.8550 + Z *-0.0396;
            int M = X *-0.4170 + Y * 1.1772 + Z * 0.0786;
            int S = X * 0      + Y * 0      + Z * 0.5168;

            // Affectation de la défaillance de cône S
            // L = L*1 + M*0 + S*0 // Revien à faire L = L
            // M = L*0 + M*1 + S*0; // Revien à faire M = M
            S = L * -0.1577 + M * 1.1946 + S * 0;

            // Conversion LMS -> XYZ
            X = L * 1.9473 + M *-1.4144 + S *-0.3647;
            Y = L * 0.6899 + M * 0.3483 + S * 0     ;
            Z = L * 0      + M * 0      + S * 1.9348;

            // Conversion XYZ -> RGB
            int R = X * 2.0413 + Y *-0.5649 + Z *-0.3446;
            int G = X *-0.9692 + Y * 1.8760 + Z * 0.0415;
            int B = X * 0.0134 + Y *-0.1183 + Z * 1.0154;

            // Valeurs finaux
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

    if (alert) cout << "|-------------------| Image Tripanope créée de taille " << _longueur << " x " << _largeur << " |-------------------|" << endl;
    return Img;
}
