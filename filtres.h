#ifndef FILTRES_H_INCLUDED
#define FILTRES_H_INCLUDED

#include "image.h"

/* |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~| Filtres |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~| */
class Filtre
{

public:
    /* |-----------------------------| Constructeurs |-----------------------------| */
    Filtre(int=1);
    Filtre(const vector<vector<float>> &);

    /* |---------------------------| Méthodes Basiques |---------------------------| */
    Image application(Image &, bool=true);

private:
    vector<vector<float>> _action;
    int _rayon;

    /* |-----------------------------| Vérifications |-----------------------------| */
    void _verifAction(const vector<vector<float>> &action) const;

};

#endif // FILTRES_H_INCLUDED
