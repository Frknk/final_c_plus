#include <iostream>
#include <vector>
#include <fstream>
#include "repuesto.cpp"
#include "moto.cpp"
#include "taller.cpp"

using namespace std;

class Tienda
{
protected:
    // Atributos
    string nombre, direccion, nro_telefono;
    vector<Repuesto> lista_repuestos; // Arreglo dinamico
    vector<Moto> lista_motos;         // Arreglo dinamico
    ofstream reporte;

    // Metodos
public:
    // Constructor
    Tienda(string _nombre, string _direccion, string _nro_telefono)
    {
        nombre = _nombre;
        direccion = _direccion;
        nro_telefono = _nro_telefono;
    }

    void agregarRepuesto(Repuesto repuesto)
    {
        lista_repuestos.push_back(repuesto); // Agrega un elemento al arreglo
    }

    void agregarMoto(Moto moto)
    {
        lista_motos.push_back(moto); // Agrega un elemento al arreglo
    }

    void encontrarRepuesto()
    {
        string codigo;
        cout << "Ingresa el codigo del repuesto que deseas encontrar: ";
        cin >> codigo;
        for (int i = 0; i < lista_repuestos.size(); i++)
        {
            if (lista_repuestos[i].getCodigo() == codigo)
            {
                cout << "El repuesto que buscas es: " << lista_repuestos[i].getDescripcion() << endl;
                cout << "El precio del repuesto es: " << lista_repuestos[i].getPrecio() << endl;
                cout << "El stock del repuesto es: " << lista_repuestos[i].getStock() << endl;
                break;
            }
            else
            {
                cout << "El repuesto que buscas no se encuentra en la tienda" << endl;
                break;
            }
        }
    }

    void reporteStock()
    {

        cout << "Que tipo de reporte desea realizar: " << endl;
        cout << "1. Reporte de repuestos ordenados por stock" << endl;
        cout << "2. Reporte de repuestos ordenados por categoria" << endl;
        cout << "3. Reporte de repuestos ordenados por fecha de registro" << endl;

        reporte.open("reporte.txt"); // Abriendo el archivo

        int opcion;
        cout << "Ingresa la opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            // Ordenando por cantidad
            for (int i = 0; i < lista_repuestos.size(); i++)
            { // Recorriendo el arreglo
                for (int j = 0; j < lista_repuestos.size(); j++)
                { // Recorriendo el arreglo nuevamente para ordenar
                    if (lista_repuestos[i].getStock() > lista_repuestos[j].getStock())
                    {                                            // Ordenando de mayor a menor
                        Repuesto aux = lista_repuestos[i];       // Variable auxiliar para hacer el intercambio
                        lista_repuestos[i] = lista_repuestos[j]; // Intercambiando
                        lista_repuestos[j] = aux;                // Intercambiando
                    }
                }
            }
            // Imprimiendo el reporte
            reporte << "Reporte de repuestos ordenados por stock: " << endl;
            for (int i = 0; i < lista_repuestos.size(); i++)
            {
                reporte << lista_repuestos[i].getDatos() << endl;
            }
            cout << "Reporte generado con exito" << endl;
            break;

        case 2:
            // Ordenando por categoria
            reporte << "Reporte de repuestos ordenados por categoria: " << endl;
            reporte << "Categoria: Frenos" << endl;
            for (int i = 0; i < lista_repuestos.size(); i++){
                if (lista_repuestos[i].getCategoria() == "Frenos" || lista_repuestos[i].getCategoria() == "frenos"){
                    reporte << lista_repuestos[i].getDatos() << endl;
                }
            }
            reporte << "Categoria: Motor" << endl;
            for (int i = 0; i < lista_repuestos.size(); i++){
                if (lista_repuestos[i].getCategoria() == "Motor" || lista_repuestos[i].getCategoria() == "motor"){
                    reporte << lista_repuestos[i].getDatos() << endl;
                }
            }
            reporte << "Categoria: Llantas" << endl;
            for (int i = 0; i < lista_repuestos.size(); i++){
                if (lista_repuestos[i].getCategoria() == "Llantas" || lista_repuestos[i].getCategoria() == "llantas"){
                    reporte << lista_repuestos[i].getDatos() << endl;
                }
            }
            reporte << "Categoria: Suspension" << endl;
            for (int i = 0; i < lista_repuestos.size(); i++){
                if (lista_repuestos[i].getCategoria() == "Suspension" || lista_repuestos[i].getCategoria() == "suspension"){
                    reporte << lista_repuestos[i].getDatos() << endl;
                }
            }
            reporte << "Categoria: Cuadro" << endl;
            for (int i = 0; i < lista_repuestos.size(); i++){
                if (lista_repuestos[i].getCategoria() == "Cuadro" || lista_repuestos[i].getCategoria() == "cuadro"){
                    reporte << lista_repuestos[i].getDatos() << endl;
                }
            }
            cout << "Reporte generado con exito";
            break;
        
        case 3:
            // Ordenando por fecha de registro
            for (int i = 0; i < lista_repuestos.size(); i++)
            { // Recorriendo el arreglo
                for (int j = 0; j < lista_repuestos.size(); j++)
                { // Recorriendo el arreglo nuevamente para ordenar
                    if (lista_repuestos[i].getFechaRegistro() > lista_repuestos[j].getFechaRegistro())
                    {                                            // Ordenando de mayor a menor
                        Repuesto aux = lista_repuestos[i];       // Variable auxiliar para hacer el intercambio
                        lista_repuestos[i] = lista_repuestos[j]; // Intercambiando
                        lista_repuestos[j] = aux;                // Intercambiando
                    }
                }
            }
            // Imprimiendo el reporte
            reporte << "Reporte de repuestos ordenados por fecha de registro: " << endl;
            for (int i = 0; i < lista_repuestos.size(); i++)
            {
                reporte << lista_repuestos[i].getDatos() << endl;
            }
            cout << "Reporte generado con exito" << endl;
            break;

        default:
            cout << "Opcion no valida" << endl;
            break;
        }
    }
};