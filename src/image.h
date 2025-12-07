#ifndef IMAGE_INCLUDED
#define IMAGE_INCLUDED
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

/* |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~| Images |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~| */
class Image
{

public:
    /* |-----------------------------| Constructeurs |-----------------------------| */
    Image();
    Image(string &);
    Image(unsigned int, unsigned int, bool=true);
    Image(const vector<vector<unsigned int>> &, const vector<vector<unsigned int>> &, const vector<vector<unsigned int>> &, bool=true);

    /* |----------------------------| Méthodes Images |----------------------------| */
    // Composante
    Image composanteRouge(bool=true) const;
    Image composanteVert(bool=true) const;
    Image composanteBleu(bool=true) const;

    // Nuances de Noire & Blanc
    Image niveauxdeGris(bool=true) const;
    Image noireEtBlanc(bool=true) const;

    // Daltonisme
    Image visionDeuteranopie(bool=true) const;
    Image visionProtanopie(bool=true) const;
    Image visionTritanopie(bool=true) const;

    // Luminosité
    Image luminosityUp(float=1.5, bool=true) const;
    Image luminosityDown(float=0.5, bool=true) const;

    // Contraste
    Image contrasteUp(float=1.5, bool=true) const;
    Image contrasteDown(float=0.5, bool=true) const;

    // Regalge
    Image reglageAuto(bool=true) const;

    // Histogramme
    const vector<unsigned int> histogrammeGris(bool=true) const;
    const vector<unsigned int> histogrammeRouge(bool=true) const;
    const vector<unsigned int> histogrammeVert(bool=true) const;
    const vector<unsigned int> histogrammeBleu(bool=true) const;
    const vector<vector<vector<unsigned int>>> histogrammeCouleur(bool=true) const;

    // Rogner
    Image rognerG(unsigned int, bool=true) const;
    Image rognerD(unsigned int, bool=true) const;
    Image rognerH(unsigned int, bool=true) const;
    Image rognerB(unsigned int, bool=true) const;

    // Rotation
    Image rotationD(bool=true) const;
    Image rotationG(bool=true) const;

    // Symètrie
    Image retournementV(bool=true) const;
    Image retournementH(bool=true) const;

    // Zoom
    Image agrandissement(int, bool=true) const;
    Image retrecissement(int, bool=true) const;
    Image zoom(float, bool=true) const;

    // Rotation Couleur
    Image rotationCouleur(bool=true) const;

    // Blanchissement
    Image blanchirCouleur(int, int, int, bool=true) const;

    /* |---------------------------| Méthodes Basiques |---------------------------| */
    unsigned int lon() const
    {
        return _longueur;
    }
    unsigned int lar() const
    {
        return _largeur;
    }

    vector<vector<unsigned int>> & get_r();
    vector<vector<unsigned int>> & get_v();
    vector<vector<unsigned int>> & get_b();
    const vector<unsigned int> get_pix(unsigned int, unsigned int) const;

    float moy() const;
    void afficher() const;

    void enregistrer(string &, bool=true) const;

    /* |---------------------------| Méthodes booléens |---------------------------| */
    bool est_composanteRouge(const Image &) const;
    bool detection(unsigned int, unsigned int, unsigned int) const;

private:
    unsigned int _longueur;
    unsigned int _largeur;
    vector<vector<unsigned int>> _rouge;
    vector<vector<unsigned int>> _vert;
    vector<vector<unsigned int>> _bleu;

    /* |-----------------------------| Vérifications |-----------------------------| */
    void _verifVect(const vector<vector<unsigned int>> &, string="") const;
};

// Test
void imageTest();
// Affichage
void Rafraichissement(string &, Image &);
// Menu
void menuDaltonien(Image &, vector<Image> &);
void menuComposante(Image &, vector<Image> &);
void menuLuminosite(Image &, vector<Image> &);
void menuContraste(Image &, vector<Image> &);
void menuDetection(Image &);
void menuHistogramme(Image &, char &, const string &);
void menuRogner(Image &, vector<Image> &);
void menuRotation(Image &, vector<Image> &);
void menuSymetrie(Image &, vector<Image> &);
void menuZoom(Image &, vector<Image> &);
void menuFiltres(Image &, vector<Image> &);
void menuBlanchissement(Image &, vector<Image> &);
void menu(Image &, Image &, vector<Image> &, string &, bool &, bool &, char = 'p', const string & = "[----------------------------------------------------------------------------------------------------------------------]");
// Verification
void verif_imgChargee(bool &);
void sasir_img(string &);

#endif
