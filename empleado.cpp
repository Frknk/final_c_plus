#include <string>

using namespace std;

class Empleado{
    protected:
    // Atributos
    string apellido, nombre, codigo;

    // Metodos
    public:
    // Constructor
    Empleado(string _apellido, string _nombre, string _codigo){
        apellido = _apellido;
        nombre = _nombre;
        codigo = _codigo;
    }

    // Getters
    string getApellido(){
        return apellido;
    }

    string getNombre(){
        return nombre;
    }

    string getCodigo(){
        return codigo;
    }

};