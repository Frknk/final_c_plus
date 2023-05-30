#include <iostream>

using namespace std;

class Cliente
{
protected:
    // Atributos
    string apellido, nombre , dni , servicios;
    int nro_servicios = 0;

    // Metodos
public:
    // Constructor
    Cliente(string _apellido , string _nombre , string _dni)
    {
        apellido = _apellido;
        nombre = _nombre;
        dni = _dni;
    }
    // Getters
    string getDni()
    {
        return dni;
    }

    string getApellidoNombre()
    {
        return apellido + ", " + nombre;
    }

    string getServicios()
    {
        return servicios;
    }

    int getNroServicios()
    {
        return nro_servicios;
    }

    // Setters
    void setServicio(string _servicio)
    {
        servicios = servicios + _servicio;
        nro_servicios++;
    }
};