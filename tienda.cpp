#include <iostream>
#include <vector>
#include <fstream>
#include "moto.cpp"
#include "taller.cpp"

using namespace std;

class Tienda : public Taller
{
protected:
    // Atributos
    string nombre, direccion, nro_telefono;
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
                system("pause");
                break;
            }
            else
            {
                cout << "El repuesto que buscas no se encuentra en la tienda" << endl;
                system("pause");
                break;
            }
        }
    }

    

    string getDatosArreglo(){
        string datos = "";
        for (int i = 0; i < lista_repuestos.size(); i++)
        {
            datos += lista_repuestos[i].getDatos() + "\n";
        }
        return datos;
    }

    void ordenerArregloFecha(){
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
    }

    void ordenarArregloCantidad(){
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
    }

    void reporteStock()
    {

        cout << "Que tipo de reporte desea realizar: " << endl;
        cout << "1. Reporte de repuestos ordenados por stock" << endl;
        cout << "2. Reporte de repuestos ordenados por categoria" << endl;
        cout << "3. Reporte de repuestos ordenados por fecha de registro" << endl;

        int opcion;
        cout << "Ingresa la opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            reporte.open("reporte.txt"); // Abriendo el archivo
            // Ordenando por cantidad
            ordenarArregloCantidad();
            // Imprimiendo el reporte
            reporte << "Reporte de repuestos ordenados por stock: " << endl;
            reporte << getDatosArreglo() << endl;
            cout << "Reporte generado con exito" << endl;
            reporte.close();
            break;

        case 2:
            // Ordenando por categoria
            // TODO - Simplificar esto en una funcion
            reporte.open("reporte.txt"); // Abriendo el archivo
            reporte << "Reporte de repuestos ordenados por categoria: " << endl;
            reporte << "*-- Categoria: Frenos" << endl;
            for (int i = 0; i < lista_repuestos.size(); i++){
                if (lista_repuestos[i].getCategoria() == "Frenos" || lista_repuestos[i].getCategoria() == "frenos"){
                    reporte << lista_repuestos[i].getDatos() << endl;
                }
            }
            reporte << "*-- Categoria: Motor" << endl;
            for (int i = 0; i < lista_repuestos.size(); i++){
                if (lista_repuestos[i].getCategoria() == "Motor" || lista_repuestos[i].getCategoria() == "motor"){
                    reporte << lista_repuestos[i].getDatos() << endl;
                }
            }
            reporte << "*-- Categoria: Llantas" << endl;
            for (int i = 0; i < lista_repuestos.size(); i++){
                if (lista_repuestos[i].getCategoria() == "Llantas" || lista_repuestos[i].getCategoria() == "llantas"){
                    reporte << lista_repuestos[i].getDatos() << endl;
                }
            }
            reporte << "*-- Categoria: Suspension" << endl;
            for (int i = 0; i < lista_repuestos.size(); i++){
                if (lista_repuestos[i].getCategoria() == "Suspension" || lista_repuestos[i].getCategoria() == "suspension"){
                    reporte << lista_repuestos[i].getDatos() << endl;
                }
            }
            reporte << "*-- Categoria: Cuadro" << endl;
            for (int i = 0; i < lista_repuestos.size(); i++){
                if (lista_repuestos[i].getCategoria() == "Cuadro" || lista_repuestos[i].getCategoria() == "cuadro"){
                    reporte << lista_repuestos[i].getDatos() << endl;
                }
            }
            cout << "Reporte generado con exito";
            reporte.close();
            break;
        
        case 3:
            reporte.open("reporte.txt"); // Abriendo el archivo
            // Ordenando por fecha de registro
            ordenerArregloFecha();
            // Imprimiendo el reporte
            reporte << "Reporte de repuestos ordenados por fecha de registro: " << endl;
            reporte << getDatosArreglo() << endl;
            cout << "Reporte generado con exito" << endl;
            reporte.close();
            break;

        default:
            cout << "Opcion no valida" << endl;
            break;
        }
    }

    void clienteMasComunes(){
        // Ordenar el arreglo de clientes por el numero de servicios
        // de mayor a menor
        for (int i = 0; i < lista_clientes.size() ; i++ ){
            for (int j = 0; j < lista_clientes.size(); j++){
                if (lista_clientes[i].getNroServicios() > lista_clientes[j].getNroServicios()){
                    Cliente aux = lista_clientes[i];
                    lista_clientes[i] = lista_clientes[j];
                    lista_clientes[j] = aux;
                }
            }
        }

        // Imprimir el arreglo
        cout << "Reporte generado!" << endl;
        reporte.open("clientes.txt");
        reporte << getClientesString();
        reporte.close();
        
    }
};