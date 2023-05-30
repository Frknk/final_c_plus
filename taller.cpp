#include <iostream>
#include <vector>
#include <fstream>
#include "empleado.cpp"
#include "repuesto.cpp"
#include "cliente.cpp"

using namespace std;



class Servicio
{
protected:
    // Atributos
    string servicio;
    int precio, tiempo, costo;

    // Metodos
public:
    // Constructor
    Servicio(string _servicio, int _precio, int _tiempo)
    {
        servicio = _servicio;
        precio = _precio;
        tiempo = _tiempo;
    }

    string getServicio()
    {
        return servicio;
    }

    int getTiempo()
    {
        return tiempo;
    }

    int getPrecio()
    {
        return precio;
    }
};


class Taller
{
public:
    // Obtienendo todos los datos en arreglos para hacer mas facil las estadisticas

    // Atributos
    vector<Servicio> lista_servicios; // Arreglo dinamico
    vector<Cliente> lista_clientes;   // Arreglo dinamico
    vector<Empleado> lista_empleados; // Arreglo dinamico
    vector<Repuesto> lista_repuestos; // Arreglo dinamico

    // Metodos
    void getClientes(){
        for (int i = 0; i < lista_clientes.size(); i++)
        {
            cout << lista_clientes[i].getApellidoNombre() << lista_clientes[i].getNroServicios() << endl;
        }
    }

    string getClientesString(){
        string clientes = "";
        for (int i = 0; i < lista_clientes.size(); i++)
        {
            clientes += lista_clientes[i].getApellidoNombre() + " Servicios: " + to_string(lista_clientes[i].getNroServicios()) + "\n";
            clientes += lista_clientes[i].getServicios() + "\n";
        }
        return clientes;
    }

    void getRepuestos(){
        for (int i = 0; i < lista_repuestos.size(); i++)
        {
            cout << lista_repuestos[i].getDescripcion() << lista_repuestos[i].getPrecio() << lista_repuestos[i].getStock() << endl;
        }
    }

    void agregarCliente(Cliente cliente)
    {
        lista_clientes.push_back(cliente); // Agrega un elemento al arreglo
    }

    void agregarServicio(Servicio servicio, Empleado empleado, string dni, string codigo_repuesto)
    {
        lista_servicios.push_back(servicio); // Agregar servicio al arreglo
        lista_empleados.push_back(empleado); // Agregar empleado al arreglo
        
        cout << "El servicio se ha agregado correctamente" << endl;

        // Actualizando nro servicios cliente
        for (int i = 0; i < lista_clientes.size(); i++)
        {
            if (lista_clientes[i].getDni() == dni)
            {
                lista_clientes[i].setServicio(servicio.getServicio());
                cout << "El numero de servicios del cliente se ha actualizado correctamente" << endl;
                break;
            }
        }

        // Actualizando el stock de los repuestosa
        for (int i = 0; i < lista_repuestos.size(); i++)
        {
            if (lista_repuestos[i].getCodigo() == codigo_repuesto)
            {
                lista_repuestos[i].setStock(lista_repuestos[i].getStock() - 1);
                cout << "El stock del repuesto se ha actualizado correctamente" << endl;
                break;
            }
        }


    }

    void obtenerServiciosPopulares()
    {
        // string mas_repite = ""; // Variable para guardar el que mas se repite
        int posicion = 0;                                // Variable para guardar la posicion del que mas se repite
        int aux = 0;                                     // Variable auxiliar para guardar el numero de veces que se repite
        for (int i = 0; i < lista_servicios.size(); i++) // Recorriendo el arreglo
        {
            int contador = 0;
            for (int j = 0; j < lista_servicios.size(); j++)
            {
                if (lista_servicios[i].getServicio() == lista_servicios[j].getServicio())
                {
                    contador++;
                }
            }
            if (contador > aux)
            {
                aux = contador;
                // mas_repite = lista_servicios[i];
                posicion = i;
            }
        }
        cout << "El servicio mas popular es: " << lista_servicios[posicion].getServicio() << endl;
        cout << "El tiempo que tarda el servicio es: " << lista_servicios[posicion].getTiempo() << " minutos" << endl;
        cout << "Por un valor de: " << lista_servicios[posicion].getPrecio() << " soles" << endl;
    }

    int obtenerGananciaTotal()
    {
        int total = 0;                                   // Variable para guardar el total
        for (int i = 0; i < lista_servicios.size(); i++) // Recorriendo el arreglo
        {
            total += lista_servicios[i].getPrecio(); // Sumando los elementos del arreglo
        }
        return total; // Retornando el total
    }

    int obtenerTiempoTotal()
    {
        int total = 0;                                   // Variable para guardar el total
        for (int i = 0; i < lista_servicios.size(); i++) // Recorriendo el arreglo
        {
            total += lista_servicios[i].getTiempo(); // Sumando los elementos del arreglo
        }
        return total; // Retornando el total
    }
};