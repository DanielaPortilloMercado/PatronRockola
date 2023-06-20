#ifndef ArtistaManejadorDatos_H
#define ArtistaManejadorDatos_H

#include <iostream>
#include <List>
#include "Artista.h"

using namespace std;

class ArtistaManejadorDatos
{

public:

    virtual list<Artista> cargar() = 0;
    virtual void guardar(Artista artist) = 0;
};

#endif /* GRANDPARENT_H */