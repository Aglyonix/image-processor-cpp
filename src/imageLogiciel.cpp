#include "image.h"

void Rafraichissement(string &Info_Image, Image &Img)
{
    if (Info_Image == "Aucune Image chargée") cout << "Image : " << Info_Image << endl << endl;
    else cout << "Image : " << Info_Image << endl << "Taille Image : " << Img.lon() << "x" << Img.lar() << endl << endl;
}

void verif_imgChargee(bool &chargee)
{
    if (!chargee) throw(invalid_argument("Vous ne pouvez pas modifier d'image si aucune n'est chargee"));
}

void menu(Image &Img, Image &Original, vector<Image> &historique,  string &nom_img, bool &actif, bool &chargee, char methode,  const string &split)
{
    string action;

    cout << "a : Chargée une Image" << endl;
    cout << "b : Enregistrer une image" << endl;
    cout << "c : Afficher l'image" << endl;
    cout << "d : Créer une image composante" << endl;
    cout << "e : Detecter une couleur dans l'image" << endl;
    cout << "f : Créer une image grisée" << endl;
    cout << "g : Simulation de la vision des daltoniens" << endl;
    cout << "h : Transformer l'image en noir et blanc" << endl;
    cout << "i : Rendu histogramme" << endl;
    cout << "j : Ajuster la luminosité de l'image" << endl;
    cout << "k : Ajuster le contraste de l'image" << endl;
    cout << "l : Rogner l'image" << endl;
    cout << "m : Effectuer une rotation" << endl;
    cout << "n : Retourner l'image" << endl;
    cout << "o : Zoomer l'image" << endl;
    cout << "p : Appliquer un filtre" << endl;
    cout << "q : Rotation des teintes" << endl;
    cout << "r : Blanchir une couleur" << endl;
    cout << "s : Undo | Annuler la modification" << endl;
    cout << "x : Fermer l'application" << endl;

    cout << endl << "Saississez le lettre correspondante à l'action que vous souhaitez réaliser (il est possible de les enchaînés): ";
    cin >> action;
    cout << endl;

    for (int i = 0; i < action.size(); i++)
    {
        action[i] = tolower(action[i]);
    }

    string his_action = "";

    for (int i = 0; i < action.size(); i++)
    {
        bool saisi_incorrecte = action[i] != 'x' && action[i] != 'a' && action[i] != 'b' && action[i] != 'c' && action[i] != 'd' && action[i] != 'e' && action[i] != 'f' && action[i] != 'g' && action[i] != 'h' && action[i] != 'i' && action[i] != 'j' && action[i] != 'k' && action[i] != 'l' && action[i] != 'm' && action[i] != 'n' && action[i] != 'o' && action[i] != 'p' && action[i] != 'q' && action[i] != 'r' && action[i] != 's';

        while(saisi_incorrecte)
        {
            cout << "Saissi incorrecte au " << i << "em caractère, ";

            if (i != 0)
            {
                char choix;

                cout << "souhaitez-vous conserver les premières actions (" << his_action << ") 'o' pour oui sinon non : ";
                cin >> choix;

                cout << "Saisissez à nouveau votre action : ";
                if (choix == 'o') cout << his_action; cin >> action;
                if (choix == 'o') action = his_action + action; cout << endl;
            }
            else
            {
                cout << "saisissez à nouveau : ";
                cin >> action;
                cout << endl;
            }

            saisi_incorrecte = action[i] != 'x' && action[i] != 'a' && action[i] != 'b' && action[i] != 'c' && action[i] != 'd' && action[i] != 'e' && action[i] != 'f' && action[i] != 'g' && action[i] != 'h' && action[i] != 'i' && action[i] != 'j' && action[i] != 'k' && action[i] != 'l' && action[i] != 'm' && action[i] != 'n' && action[i] != 'o' && action[i] != 'p' && action[i] != 'q' && action[i] != 'r' && action[i] != 's';
        }

        if (!(saisi_incorrecte)) his_action += action[i];
    }

    for (int i = 0; i < action.size(); i++)
    {
        switch (action[i])
        {
        case 'a':
            cout << "Saisissez le nom de fichier.ppm de votre image : ";
            cin >> nom_img;
            // Le nom de l'image est vérifier dans le constructeur
            Img = Image(nom_img);
            Original = Img;
            chargee = true;
            break;
        case 'b':
            {
            verif_imgChargee(chargee);
            string nom;
            cout << "Saisissez le nom du fichier.ppm : ";
            cin >> nom;
            Img.enregistrer(nom);
            break;
            }
        case 'c':
            verif_imgChargee(chargee);
            Img.afficher();
            break;
        case 'd':
            verif_imgChargee(chargee);
            menuComposante(Img, historique);
            break;
        case 'e':
            verif_imgChargee(chargee);
            menuDetection(Img);
            break;
        case 'f':
            verif_imgChargee(chargee);
            historique.push_back(Img);
            Img = Img.niveauxdeGris();
            cout << endl;
            break;
        case 'g':
            verif_imgChargee(chargee);
            menuDaltonien(Img, historique);
            break;
        case 'h':
            verif_imgChargee(chargee);
            historique.push_back(Img);
            Img = Img.noireEtBlanc();
            cout << endl;
            break;
        case 'i':
            verif_imgChargee(chargee);
            menuHistogramme(Img, methode, split);
            break;
        case 'j':
            verif_imgChargee(chargee);
            menuLuminosite(Img, historique);
            break;
        case 'k':
            verif_imgChargee(chargee);
            menuContraste(Img, historique);
            break;
        case 'l':
            verif_imgChargee(chargee);
            menuRogner(Img, historique);
            break;
        case 'm':
            verif_imgChargee(chargee);
            menuRotation(Img, historique);
            break;
        case 'n':
            verif_imgChargee(chargee);
            menuSymetrie(Img, historique);
            break;
        case 'o':
            verif_imgChargee(chargee);
            menuZoom(Img, historique);
            break;
        case 'p':
            verif_imgChargee(chargee);
            menuFiltres(Img, historique);
            break;
        case 'q':
            verif_imgChargee(chargee);
            historique.push_back(Img);
            Img = Img.rotationCouleur();
            cout << endl;
            break;
        case 'r':
            verif_imgChargee(chargee);
            menuBlanchissement(Img, historique);
            break;
        case 's':
            if (historique.size() == 0) throw(invalid_argument("Vous ne pouvez pas revenir plus en arrière."));
            else
            {
                cout << "Retour effectué avec succés." << endl << endl;
                Img = historique.back();
                historique.pop_back();
            }
            break;
        case 'x':
            actif = false;
            break;
        default:
            break;
        }

        if (i != action.size() - 1) cout << split << endl << endl;
    }
}
