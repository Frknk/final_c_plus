#include <iostream>

using namespace std;

class Tienda {
    protected:
    string nombre, direccion, nro_telefono;

    public:
    Tienda (string _nombre, string _direccion, string _nro_telefono) {
        nombre = _nombre;
        direccion = _direccion;
        nro_telefono = _nro_telefono;
    }

    
};