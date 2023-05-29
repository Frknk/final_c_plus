#include <string>
#include <vector>

using namespace std;

class Cliente
{
protected:
    // Atributos
    string apellido, nombre, direccion, nro_telefono;
    vector<string> lista_trabajos_realizados;            // Arreglo dinamico
    int nro_trabajos = lista_trabajos_realizados.size(); // Tamaño del arreglo

    // Metodos
public:
    // Constructor
    Cliente(string _apellido, string _nombre, string _direccion, string _nro_telefono)
    {
        apellido = _apellido;
        nombre = _nombre;
        direccion = _direccion;
        nro_telefono = _nro_telefono;
    }

    void agregarTrabajoRealizado(string trabajo_realizado)
    {
        lista_trabajos_realizados.push_back(trabajo_realizado); // Agrega un elemento al arreglo
    }

    int getNroTrabajos()
    {
        return nro_trabajos;
    }
};