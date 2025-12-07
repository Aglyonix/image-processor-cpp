## Description

Ce projet est un traiteur d'image, il permet de traîter les images .ppm à travers différentes fonctionnalitées interactives.

## Table des matières

- Essayer
- Utilisation
- Contributeur

## Essayer

Pour essayer le projet, ou executer directement le main.exe.
Ou compiler ```g++ src/*.cpp -o main.exe```
Puis executer le projet.

## Utilisation

L'affichage du programme est syndé en 2 partie, l'une affiche des information sur l'image tel que le nom puis la taille. Etl'autre affiche un menu qui vous indiquera quoi saisir pour manipuler votre image.

Voici le différente fonctionalité que propose le programme :

- Charger une image .ppm depuis votre répertoire locale.

- Enregistrer une image au format ppm. Est créé dans le répertoire locale.

- Afficher une image sous le format RGB de chaque pixel.

- Créer une image composante rouge, verte ou bleu.

- Detecter une couleur dans l'image par son code RGB.

- Créer une image grisée

- Simulation de la vision des daltoniens. A prendre à la légére les simulation ont était apuyés par diverse source tel que : https://github.com/MaPePeR/jsColorblindSimulator/blob/master/colorblind.js, mais le rendu n'est celle attendu.

- Créer l'image chargé en noir et blanc

- Rendre l'histogramme gris ou de couleur, plusieur méthode d'affichage peuvent être choisi.

- Ajuster la luminosité de l'image.

- Ajuster le contraste de l'image.

- Rogner l'image.

- Effectuer une rotation.

- Retourner l'image.

- Zoomer l'image.

- Appliquer un filtre. Le rendupeut ne pas être celle attendu.

- Undo | Annuler la modification. Réaliser un retour en arrière.

## Contributeur

Ce projet à été réalisé par Aelig Jimenez de l'IUT informatique d'orsay.