#include <iostream>
#include <vector>

using namespace std;

class Taller
{
protected:
    // Obtienendo todos los datos en arreglos para hacer mas facil las estadisticas

    // Atributos
    vector<string> lista_servicios; // Arreglo dinamico
    vector<int> contador_servicios; // Arreglo dinamico
    vector<int> tiempo_servicios;   // Arreglo dinamico
    vector<int> ganancia;           // Arreglo dinamico

    // Metodos
public:
    /*void realizarTrabajo()
    {
        cout << "*** Realizar un nuevo trabajo ***" << endl;
        cout << "1. Cambio de aceite | $5 | 5 min" << endl;
        cout << "2. Cambio de llantas | $25 | 20 min" << endl;
        cout << "3. Cambio de frenos | $30 | 20 min" << endl;
        cout << "4. Cambio de amortiguadores | $60 | 45 min" << endl;
        cout << "5. Cambio de bateria | $50 | 30 min" << endl;
        cout << "6. Cambio de bujias | $10 | 10 min" << endl;
        cout << "7. Cambio de filtro de aire | $5 | 5 min" << endl;
        cout << "8. Cambio de filtro de aceite | $5 | 5 min" << endl;
        cout << "9. Cambio de filtro de gasolina | $5 | 5 min" << endl;
        cout << "10. Cambio de direccionales | $25 | 25 min" << endl;
    }*/

    void agregarServicio(string servicio, int tiempo, int costo)
    {
        lista_servicios.push_back(servicio); // Agregar servicio al arreglo
        tiempo_servicios.push_back(tiempo);  // Agregar tiempo al arreglo
        ganancia.push_back(costo);           // Agregar costo al arreglo
    }

    void obtenerServiciosPopulares()
    {
        int mayor = 0; // Variable para guardar el mayor
        int posicion = 0; // Variable para guardar la posicion del mayor 
        for (int i = 0; i < contador_servicios.size(); i++) // Recorriendo el arreglo
        {
            if (contador_servicios[i] > mayor) // Comparando si el elemento es mayor que la variable mayor
            {
                mayor = contador_servicios[i]; // Guardando el mayor
                posicion = i; // Guardando la posicion del mayor
            }
        }
        cout << "El servicio mas popular es: " << lista_servicios[posicion] << endl;
        cout << "El tiempo que tarda el servicio es: " << tiempo_servicios[posicion] << " minutos" << endl;
    }

    int obtenerGananciaTotal()
    {
        int total = 0; // Variable para guardar el total
        for (int i = 0; i < ganancia.size(); i++) // Recorriendo el arreglo
        {
            total += ganancia[i]; // Sumando los elementos del arreglo
        }
        return total; // Retornando el total
    }

    int obtenerTiempoTotal()
    {
        int total = 0; // Variable para guardar el total
        for (int i = 0; i < tiempo_servicios.size(); i++) // Recorriendo el arreglo
        {
            total += tiempo_servicios[i]; // Sumando los elementos del arreglo
        }
        return total; // Retornando el total
    }
};