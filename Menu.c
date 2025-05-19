#include <stdio.h> //Libreria entrada/salida estánda (scanf, printf, fgets)
#include <stdlib.h> //Gestión de memoria (getchar)
#include <string.h> //operaciones sobre cadenas de caracteres y bloques de memoria 

//#define es un macro de preprocesador que sirven para definir constantes
#define MAX_VUELOS    50   //Hasta 50 vuelos.
#define MAX_CLIENTES  50   //Hasta 50 clientes.

//Definir un nuevo tipo de dato estructurado (objeto)
typedef struct {
    int    id;                  //Tipo de dato Entero
    char   origen[50];          //Tipo de dato Caracter entre [] va el numero de caracteres permitidos
    char   destino[50];         //Tipo de dato Caracter entre [] va el numero de caracteres permitidos
    char   fechaVuelo[20];      //Tipo de dato Caracter entre [] va el numero de caracteres permitidos
    int    asientos;            //Tipo de dato Entero
    float  precio;              //Tipo de dato Flotante (Dígitos decimales)
} Vuelo;                        //Nombre del Objeto

typedef struct {
    char   nombre[50];          //Tipo de dato Caracter entre [] va el numero de caracteres permitidos
    char   email[50];           //Tipo de dato Caracter entre [] va el numero de caracteres permitidos
    int    idVuelo;             //Tipo de dato Entero
    float  pago;                //Tipo de dato Flotante (Dígitos decimales)
} Cliente;                      //Nombre del Objeto

//Incialización de Variables
Vuelo   vuelos[MAX_VUELOS];         //Tipo de dato Vuelo(typedef struct) [MAX_VUELOS] le indica al compilador que reserve espacio para MAX_VUELOS(50)
int     totalVuelos = 0;            //Tipo de dato Entero
Cliente clientes[MAX_CLIENTES];     //Tipo de dato Clientes(typedef struct) [MAX_CLIENTES] le indica al compilador que reserve espacio para MAX_CLIENTES(50)
int     totalClientes = 0;          //Tipo de dato Entero

//Inicialización de funciones
void    vuelosDisponibles();        //Arma arreglo de los vuelos
void    mostrarMenu();              //Muestra en consola las opciones del menú
void    listarVuelos();             //Muestra en consola la información de los vuelos disponibles
void    comprarBoleto();            //Compra de boletos por Id de vuelo
void    listarClientes();           //Muestra en consola los clientes registrados
int     buscarVueloPorID(int id);   //Busca el vuelo por Id del vuelo
void    pausa();                    //Pausa el programa para que le usuario decida en que momento continuar

//Inicio del Programa
int main() {
    //Llenado de datos para vuelos disponibles
    vuelosDisponibles();  
    
    int opcion; //Tipo de dato Entero

    //do–while Queremos mostrar el menú y procesar la elección del usuario al menos una vez, y luego seguir repitiendo mientras no elija “4. Salir”.
    do {
        mostrarMenu();                  //Muestra en consola las opciones del menú
        printf("Elige una opción: ");   //printf lo ocupamos para mostrar mensajes en consola
        scanf("%d", &opcion);           //scanf se usa para leer datos de la entrada (%d significa que se va a leer un entero)
        getchar();                      //Limpiar buffer

        // Condicional: switch te permite seleccionar entre múltiples caminos de ejecución basándote en el valor de una expresión entera
        switch (opcion) {     //Expresión del switch      
            case 1:
                //Opcion 1 Vuelos disponibles: Muestra los vuelos disponibles
                listarVuelos();
                break;      //termina el bloque del case 1
            case 2:
                comprarBoleto();
                break;      //termina el bloque del case 2
            case 3:
                listarClientes();
                break;      //termina el bloque del case 3
            case 4:
                printf("\nGracias por prefencia. ¡Vuelva Pronto!"); //printf lo ocupamos para mostrar mensajes en consola (\n es un salto de linea)
                break;      //Termina el bloque del case 4
            default:        //Bloque que se ejecuta si ningún case coincide
                printf("Opción de Meú no encontrada. Favor de elegir una opcion valida.\n"); //printf lo ocupamos para mostrar mensajes en consola (\n es un salto de linea)
        }
    } while (opcion != 4);   // Condicón: do–while va repetir la accion dentro del do, hasta que se cumpla la condicion opcion es diferente de 4

    return 0; //valor retornado
}

// Carga algunos vuelos de ejemplo en el arreglo
void vuelosDisponibles() {
    //array de vuelos (todos los arreglos empiezan en la posicion 0)
    
    //llenado vuelo 1
    vuelos[0]               //Etre [] va la posicion del array 
    = (Vuelo)               //tipo de dato Vuelo
        {1,                 //Variable id 
        "Ciudad de México", //Variable origen
        "Madrid",           //Variable destino
        "30/05/2025",       //Variable fechaVuelo
        10,                 //Variable asientos
        830.0f};            //Variable precio f al final indica al compilador que ese literal es un float y no un double.
    
    //llenado vuelo  2
    vuelos[1] = (Vuelo){2, "Ciudad de México", "Guadalajara","15/06/2025",  15,  380.50f};
    //llenado vuelo  3
    vuelos[2] = (Vuelo){3, "Ciudad de México",  "Nueva York", "20/07/2025",  8,  650.0f};
    //llenado vuelo  4
    vuelos[3] = (Vuelo){4, "Ciudad de México",  "Can Cún", "18/08/2025",  4,  420.0f};
    
    totalVuelos = 4; //total de vuelos registrados para mostrar
}

// Muestra el menú principal
void mostrarMenu() {
    printf("\n=== AIRLINE PREMIUM ===\n");  //printf lo ocupamos para mostrar mensajes en consola (\n es un salto de linea)
    printf("1. Vuelos Disponibles\n");      //printf lo ocupamos para mostrar mensajes en consola (\n es un salto de linea)
    printf("2. Comprar Boleto\n");          //printf lo ocupamos para mostrar mensajes en consola (\n es un salto de linea)
    printf("3. Clientes Frecuentes\n");     //printf lo ocupamos para mostrar mensajes en consola (\n es un salto de linea)
    printf("4. Salir\n");                   //printf lo ocupamos para mostrar mensajes en consola (\n es un salto de linea)
}

// Lista todos los vuelos en pantalla
void listarVuelos() {
    printf("\nID    Origen             Destino            Fecha        Asientos   Precio\n");       //printf lo ocupamos para mostrar mensajes en consola (\n es un salto de linea)
    printf("-------------------------------------------------------------------------------\n");    //printf lo ocupamos para mostrar mensajes en consola (\n es un salto de linea)
    //for estructura iterativa que te permite repetir un bloque de código mientras se cuampla la condicón
    for (int i = 0;         //inicializacion de indice
        i < totalVuelos;    //condición si el indice i es menor que el totalVuelos
        i++) {              //Contador ++ (+1)
        
        Vuelo *v = &vuelos[i]; //v objeto de tipo de dato Vuelo [i] obtenemos la imformación del indice 
        
        //%-3d indica que se va a imprimir un entero y 3 indica el ancho
        //%-18s indica que se va a imprimir una cadena de caracteres y el 18 es el ancho
        //%-11s indica que se va a imprimir una cadena de caracteres y el 11 es el ancho
        //%-8d indica que se va a imprimir un entero y 8 indica el ancho
        //$ -Es un carácter literal. .2 indica en numero de decimales que se van a mostrar f indica que se va a imprimar un float
        printf("%-3d %-18s %-18s %-11s  %-8d  $%.2f\n",
               v->id, v->origen, v->destino, v->fechaVuelo, v->asientos, v->precio); //se recupera del objeto v cada una de las variables
    }
    pausa(); //Pausa el programa para que le usuario decida en que momento continuar
}

// Proceso de compra de boleto
void comprarBoleto() {
    int id, idx;                //Inicializacion de variables tipo entero
    char nombre[50], email[50]; //inicializacion de variables 

    printf("\n-- Comprar Boletos --\n");            //printf lo ocupamos para mostrar mensajes en consola (\n es un salto de linea)
    listarVuelos();                                 //Muestra en consola la información de los vuelos disponibles
    printf("Ingresa el ID de vuelo a comprar: ");   //printf lo ocupamos para mostrar mensajes en consola (\n es un salto de linea)
    scanf("%d", &id);                               //scanf se usa para leer datos de la entrada (%d significa que se va a leer un entero)
    getchar();                                      //Limpiar buffer

    idx = buscarVueloPorID(id);                     //Busca el vuelo por Id del vuelo
   
    //if  la forma básica de introducir decisiones
    if (idx < 0) { //si idx es menos que 0 no 
        printf("Error: El ID %d no existe.\n", id); //printf lo ocupamos para mostrar mensajes en consola (\n es un salto de linea) %d indica que se va a imprimir un valor entero
        pausa(); //Pausa el programa para que le usuario decida en que momento continuar
    }else{
        Vuelo *v = &vuelos[idx]; //obtenemos el vuelo del id valido
         //if  la forma básica de introducir decisiones
        
         if (v->asientos <= 0) { //Valida si hay asiento disponibles
            printf("Lo sentimos, no hay asientos disponibles en este vuelo.\n"); //printf lo ocupamos para mostrar mensajes en consola (\n es un salto de linea)
            pausa(); //Pausa el programa para que le usuario decida en que momento continuar
        }else{
             // Solicitar datos del cliente
            printf("Nombre completo: ");            //printf lo ocupamos para mostrar mensajes en consola
            fgets(nombre, sizeof(nombre), stdin);   //fgets se usa para leer datos de entrada completos (incluyendo espacios) sizeof el numero de caracteres permitidos stdin es el flujo de entrada estándar (el teclado).
            nombre[strcspn(nombre, "\n")] = '\0';   // \0 quitar salto de línea strcspn sirve para encontrar la posición del primer carácter en una cadena

            printf("Correo electrónico: ");         //printf lo ocupamos para mostrar mensajes en consola
            fgets(email, sizeof(email), stdin);     //fgets se usa para leer datos de entrada completos (incluyendo espacios) sizeof el numero de caracteres permitidos stdin es el flujo de entrada estándar (el teclado).
            email[strcspn(email, "\n")] = '\0';     // \0 quitar salto de línea strcspn sirve para encontrar la posición del primer carácter en una cadena
        
            //valida que el nombre y el email no esten vacios
             if (strlen(nombre) == 0 || strlen(email) == 0) { //strlen sirve para obtener la longitud de una cadena
                printf("Error: Nombre y correo no pueden estar vacíos.\n"); //printf lo ocupamos para mostrar mensajes en consola
                pausa(); //Pausa el programa para que le usuario decida en que momento continuar
            }else{
                 //Actualizar asiento
                v->asientos--;  //-- (-1) Se resta a la variable asietos -1 que es el boleto comprado
                
                //Registrar clientes
                clientes[totalClientes] = (Cliente){ "", "", id, v->precio };
                //Del array clientes[totalClientes] se obtiene la varible nombre para llenarla con el nombre que se ingreso
                strcpy(clientes[totalClientes].nombre, nombre); //strcpy es la forma más sencilla de duplicar una cadena
                
                //Del array clientes[totalClientes] se obtiene la varible email para llenarla con el email que se ingreso
                strcpy(clientes[totalClientes].email, email);   //strcpy es la forma más sencilla de duplicar una cadena
                
                totalClientes++; //Al total de clientes registrados se le suma 1 (++)

                printf("¡Boleto comprado exitosamente!\n"); //printf lo ocupamos para mostrar mensajes en consola
                printf("Destino: %s", v->destino);          //Se imprime el destiomo del Boleto comprado 
                printf("Precio: $%.2f", v->precio);         //Se imprime el precio del Boleto comprado 
                pausa(); //Pausa el programa para que le usuario decida en que momento continuar
            }
        }
    }
}

// Muestra lista de clientes con boletos
void listarClientes() {
    //valida si hay clientes registrados
    if (totalClientes == 0) {
        printf("\nNo hay clientes registrados aún.\n"); //printf lo ocupamos para mostrar mensajes en consola
    } else {
        //imprime los clientes registados
        printf("\nNombre                   Email                       Vuelo   Pago\n");  //printf lo ocupamos para mostrar mensajes en consola
        printf("--------------------------------------------------------------------\n"); //printf lo ocupamos para mostrar mensajes en consola
        //for estructura iterativa que te permite repetir un bloque de código mientras se cuampla la condicón
        for (int i = 0;         //inicializacion de indice
        i < totalClientes;      //condición si el indice i es menor que el totalClientes
        i++) {                  //Contador ++ (+1)
            
        Cliente *c = &clientes[i]; //c objeto de tipo de dato Cliente [i] obtenemos la imformación del indice 
            
        //%-24s indica que se va a imprimir una cadena de caracteres y el 24 es el ancho
        //%-26s indica que se va a imprimir una cadena de caracteres y el 26 es el ancho
        //%-6d indica que se va a imprimir un entero y 6 indica el ancho
        //$ -Es un carácter literal. .2 indica en numero de decimales que se van a mostrar f indica que se va a imprimar un float
        printf("%-24s %-26s %-6d $%.2f\n",
                   c->nombre, c->email, c->idVuelo, c->pago);//se recupera del objeto c cada una de las variables
        }
    }
    pausa(); //Pausa el programa para que le usuario decida en que momento continuar
}

// Busca un vuelo por su ID; devuelve índice o -1 si no existe
int buscarVueloPorID(int id) {
    //se recorre todos los vuelos registrados
    for (int i = 0; i < totalVuelos; i++) {
        //valida si el id ingresado es igual a un id de alguno de los vuelos registrados
        if (vuelos[i].id == id){
            return i; //si si lo encuntra segresa el id de vuelo
        } 
    }
    return -1; //si no lo encuentra segresa -1
}

// Pausa la pantalla hasta que el usuario presione Enter
void pausa() {
    printf("\nPresiona Enter para continuar...");   //printf lo ocupamos para mostrar mensajes en consola
    getchar();                                      //Limpiar buffer
}