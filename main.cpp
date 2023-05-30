#include "tienda.cpp"
#include <iostream>

using namespace std;

int main()
{
    Tienda tienda("Motorin", "Av. Javier Prado 123", "123456789");
    Taller especializado;

    Cliente cliente_c("Pablo", "Ramos", "12345");
    Cliente cliente_d("Pedro", "Perez", "54321");

    tienda.agregarCliente(cliente_c);
    tienda.agregarCliente(cliente_d);

    Empleado empleado1("E001", "Juan", "Perez");    

    Repuesto repuesto1("R001", "Llanta Negra 1", "01/01/2021", 100, 10, "Llantas");
    Repuesto repuesto2("R002", "Suspension Tipo 1", "01/01/2021", 200, 20, "Suspension");
    Repuesto repuesto3("R003", "Deposito Combustible 1", "01/01/2021", 300, 30, "Cuadro");

    Moto moto1("H001", "Honda", "CBR", "Rojo", "2020", "250", 1000, 10000);

    Servicio servicio1("Cambio de llanta", 5, 15);
    Servicio servicio2("Cambio de suspension", 30, 45);

    especializado.agregarServicio(servicio1, empleado1, "12345", "R001");
    cliente_c.setServicio("Cambio de llanta");
    especializado.agregarServicio(servicio1, empleado1, "12345", "R001");
    cliente_c.setServicio("Cambio de llanta");
    especializado.agregarServicio(servicio1, empleado1, "12345", "R001");
    cliente_c.setServicio("Cambio de llanta");
    especializado.agregarServicio(servicio2, empleado1, "54321", "R002");
    cliente_d.setServicio("Cambio de suspension");
    especializado.agregarServicio(servicio2, empleado1, "54321", "R002");
    cliente_d.setServicio("Cambio de suspension");


    tienda.agregarRepuesto(repuesto1);
    tienda.agregarRepuesto(repuesto2);
    tienda.agregarRepuesto(repuesto3);

    int opcion;
    do
    {
        system("cls");
        cout << "Bienvenido a la tienda Motorin" << endl;
        cout << "--------------------------------" << endl;
        cout << "1. Encontrar/Informacion repuesto" << endl;
        cout << "2. Obtener servicios mas populares del taller" << endl;
        cout << "3. Reporte Stock" << endl;
        cout << "4. Clientes mas comunes" << endl;
        cout << "0. Salir" << endl;
        cout << "\nIngrese opcion: ";

        cin >> opcion;

        switch (opcion)
        {
        case 1:
            tienda.encontrarRepuesto();
            break;
        case 2:
            especializado.obtenerServiciosPopulares();
            system("pause");
            break;
        case 3:
            tienda.reporteStock();
            system("pause");
            break;
        case 4:
            tienda.clienteMasComunes();
            system("pause");
            break;
        default:
            break;
            return 0;
        }
    } while (opcion != 0);
}