#include <iostream>

using namespace std;

void devolver();
bool compararCadenas();
int caracteresANumeros(char[]);
void mayusculasMinusculas(char*);
void separarNumerosCaracteres(char*);
void sumarNumeros(int);
void llenarMatriz(int, int, int*);
bool isMagicSquare(int , int , int*);
bool tieneElementosRepetidos(int, int, int*);
void mostrarMatriz(int, int, int*);
void cuadradoMagico();
void cantidadEstrellas();
int contarEstrellas(int, int, int*);
void rectanguloInterseccion(float*, float*, float[]);
float menor(float, float);
float mayor(float, float);
bool formaRectangulo(float, float, float, float);
void rectangulos();
bool leerRectangulo(float* rectangulo);
short int hacerPermutacionLexicografica(short int*, short int);
void intercambiar(short int, short int, short int*);
void invertir(short int, short int*, short int);
void permutacionLexicografica();

int main()
{
    short int opc = -1;
    char lectura[23];
    short int n = 0;

        while(opc != 0){
            cout << "Seleccione una opcion: \n"
                    "1. Problema 1 \n"
                    "2. Problema 3 \n"
                    "3. Problema 4 \n"
                    "4. Problema 6 \n"
                    "5. Problema 8 \n"
                    "6. Problema 9 \n"
                    "7. Problema 12 \n"
                    "8. Problema 13 \n"
                    "9. Problema 15 \n"
                    "10. Problema 18 \n"
                    "0. Salir \n" << endl;
            cin >> opc;

            switch (opc){
                case(0):
                    cout << "Salir" << endl;
                    break;
                case(1):
                    cout << "Problema 1" << endl;
                    devolver();
                    break;
                case(2):
                    cout<<"Comprar cadenas"<<endl;
                    if(compararCadenas()){
                        cout << "Son iguales" << endl;
                    }
                    else{
                        cout << "Son distintas" << endl;
                    }
                    break;
                case(3):
                    cout<<"Caracteres a numeros"<<endl;
                    cout << "Escriba una cadena numerica " << endl;
                    cin >> lectura;
                    cout << caracteresANumeros(lectura) << endl;
                    break;
                case(4):
                    cout<<"Minusculas a mayusculas"<<endl;
                    cout << "Escriba una cadena" << endl;
                    cin >> lectura;
                    mayusculasMinusculas(lectura);
                    cout << lectura << endl;
                    break;
                case(5):
                    cout<<"Separar caracteres y numeros"<<endl;
                    cout << "Escriba una cadena" << endl;
                    cin >> lectura;
                    separarNumerosCaracteres(lectura);
                    break;
                case(6):
                    cout<<"Sumar n digitos"<<endl;
                    cout << "De a cuantos digitos quiere sumar?" << endl;
                    cin >> n;
                    if(n > 9){
                    cout << "Muchos digitos para el tipo de dato" << endl;
                    }else{
                        sumarNumeros(n);
                    }
                    break;
                case(7):
                    cout<<"Cuadrado magico"<<endl;
                    cuadradoMagico();
                    break;
                case(8):
                    cout<<"Estrellas"<<endl;
                    cantidadEstrellas();
                    break;
                case(9):
                    cout<<"Rectangulos intersectados"<<endl;
                    rectangulos();
                    break;
                case(10):
                    cout<<"Permutacion lexicografica"<<endl;
                    permutacionLexicografica();
                    break;
                default:
                    cout << "Opcion no valida" << endl;
                    break;
            }
        }
}

void permutacionLexicografica(){
    short int valores[10] = {0,1,2,3,4,5,6,7,8,9};
    short int tam = sizeof(valores)/sizeof(valores[0]);
    unsigned int n = 0;
    while(true){
        cout << "Cual permutacion de 10 numeros quiere ver?" << endl;
        cin >> n;
        if(n > 3628800){
            cout << "Hay como maximo 3628800 permutaciones posibles para 10 elementos" << endl;
        }
        else{
            break;
        }
    }
    cout << "La permutacion numero " << n << " es: ";
    for(unsigned int i=1; i<n; i++){
        hacerPermutacionLexicografica(valores, tam);
    }

    for(int k=0; k<tam; k++){
        cout << *(valores + k);
    }
    cout << endl;
}
short int hacerPermutacionLexicografica(short int* valores, short int tam){
    short int mayorX = -1;
    short int mayorY = -1;

    for(int i=0; i<tam - 1; i++){
        if(*(valores + i) < *(valores + i + 1)){
            mayorX = i;
        }
    }

    if(mayorX == -1){
        return -1;
    }

    for(int i=0; i<tam; i++){
        if(*(valores + mayorX) < *(valores + i)){
            mayorY = i;
        }
    }

    intercambiar(mayorX, mayorY, valores);
    invertir(mayorX, valores, tam);
    return 0;
}

void invertir(short int x, short int* valores, short int tam){
    short int tamSubArray = tam-x-1;
    short int subarray[tamSubArray];
    short int aux;
    short subArrayIndx = 0;

    for(int i=0; i<(tam-x); i++){
        *(subarray + i) =*(valores + (x+1) + i);
    }

    for(int i=0; i<(tam-x)/2; i++){
        aux = *(subarray + i);
        *(subarray + i) = *(subarray + (tamSubArray - 1) - i);
        *(subarray + (tamSubArray - 1) - i) = aux;
    }

    for(int i=x+1; i<tam; i++){
        *(valores + i) =*(subarray + subArrayIndx);
        ++subArrayIndx;
    }
}
void intercambiar(short int mayorX, short int mayorY, short int* valores){
    short int aux = *(valores + mayorX);
    *(valores + mayorX) = *(valores + mayorY);
    *(valores + mayorY) = aux;
}

bool leerRectangulo(float* rectangulo){
    float *valores = rectangulo;
    float numero = 0;

    cout << "A continuacion escriba los datos del rectangulo" << endl;
    cout << "Escriba la coordenada X del vertice superior izquierdo" << endl;
    cin >> numero;
    *valores = numero;
    valores = valores + 1;

    cout << "Escriba la coordenada Y del vertice superior izquierdo" << endl;
    cin >> numero;
    *valores = numero;
    valores = valores + 1;

    while(true){
        cout << "Escriba el ancho del rectangulo o 0 para salir" << endl;
        cin >> numero;
        if(numero == 0){
            cout << "Salir" << endl;
            return false;
        }
        else if(numero < 0){
            cout << "No tiene sentido una distancia negativa" << endl;
        }
        else{
            *valores = numero;
            valores = valores + 1;
            break;
        }
    }

    while(true){
        cout << "Escriba el largo del rectangulo o 0 para salir" << endl;
        cin >> numero;
        if(numero == 0){
            cout << "Salir" << endl;
            return false;
        }
        else if(numero < 0){
            cout << "No tiene sentido una distancia negativa" << endl;
        }
        else{
            *valores = numero;
            break;
        }
    }
    return true;
}

void rectangulos(){
    float rectangulo1[4];
    float rectangulo2[4];
    float rectangulo3[4] = {0,0,0,0};


    cout << "Para el rectangulo 1" << endl;
    if(!leerRectangulo(rectangulo1)){
        return;
    }


    cout << "Para el rectangulo 2" << endl;
    if(!leerRectangulo(rectangulo2)){
        return;
    }

    rectanguloInterseccion(rectangulo1, rectangulo2, rectangulo3);
    cout << "{" << *rectangulo3 << " " << *(rectangulo3 + 1) << " " << *(rectangulo3 + 2)
         << " " << *(rectangulo3 + 3) << "}" << endl;
}

void rectanguloInterseccion(float* rectangulo1, float* rectangulo2, float rectangulo3[]){
    float xSuperiorIzquierdo1 = *rectangulo1;
    float ySuperiorIzquierdo1 = *(rectangulo1 + 1);
    float xInferiorDerecho1 = *rectangulo1 + *(rectangulo1 + 2);
    float yInferiorDerecho1 = *(rectangulo1 + 1) - *(rectangulo1 + 3);

    float xSuperiorIzquierdo2 = *rectangulo2;
    float ySuperiorIzquierdo2 = *(rectangulo2 + 1);
    float xInferiorDerecho2 = *rectangulo2 + *(rectangulo2 + 2);
    float yInferiorDerecho2 = *(rectangulo2 + 1) - *(rectangulo2 + 3);

    float xSuperiorIzquierdoIntersec = mayor(xSuperiorIzquierdo1, xSuperiorIzquierdo2);
    float ySuperiorIzquierdoIntersec = menor(ySuperiorIzquierdo1, ySuperiorIzquierdo2);
    float xInferiorDerechaIntersect = menor(xInferiorDerecho1, xInferiorDerecho2);
    float yInferiorDerechaIntersect = mayor(yInferiorDerecho1, yInferiorDerecho2);

    bool resp = formaRectangulo(xSuperiorIzquierdoIntersec, ySuperiorIzquierdoIntersec,
                           xInferiorDerechaIntersect, yInferiorDerechaIntersect);
    if(resp){
        *rectangulo3 = xSuperiorIzquierdoIntersec;
        *(rectangulo3 + 1) = ySuperiorIzquierdoIntersec;
        *(rectangulo3 + 2) = (xInferiorDerechaIntersect - xSuperiorIzquierdoIntersec);
        *(rectangulo3 + 3) = (ySuperiorIzquierdoIntersec - yInferiorDerechaIntersect);
    }
}


bool formaRectangulo(float x1, float y1, float x2, float y2){
    /*Valida si las coordenadas de el punto superior izquierdo (x1, y1) e inferior derecho (x2, y2) forman un
    rectangulo*/
    if((x1 < x2) && (y1 > y2)){
        return true;
    }
    return false;
}
float menor(float num1, float num2){
    if(num1 < num2)
        return num1;
    return num2;
}

float mayor(float num1, float num2){
    if(num1 > num2)
        return num1;
    return num2;
}

void cantidadEstrellas(){
    short int rows = -1;
    short int columns = -1;
    int cantidadEstrellas;

    while(rows < 0 || columns < 0){
        cout << "Escriba la cantidad de filas de la matriz o 0 para salir" << endl;
        cin >> rows;
        if(rows == 0){
            cout << "Salir" << endl;
            return;
        }

        cout << "Escriba la cantidad de columnas de la matriz o 0 para salir" << endl;
        cin >> columns;
        if(columns == 0){
            cout << "Salir" << endl;
            return;
        }


        if (columns > 0 && rows > 0){
            break;
        }

        cout << "Dimension no valida" << endl;

    }

    int matriz[rows][columns];
    int* celda = &matriz[0][0];
    llenarMatriz(rows, columns, celda);
    cantidadEstrellas = contarEstrellas(rows, columns, celda);
    cout << "Hay en total: " << cantidadEstrellas << " posibles estrellas en la matriz" << endl;

}

int contarEstrellas(int rows, int columns, int* celda){
    int *estrella = (celda + (columns + 1));
    float suma = 0;
    int cantEstrellas = 0;
    for(int i=1; i<=(rows - 2); i++){
        for(int k=0; k<(columns - 2); k++){
            suma = 0;
            /*suma = *estrella +
                    *(estrella + (columns + 1)) +
                    *(estrella + (columns - 1)) +
                    *(estrella - (columns - 1)) +
                    *(estrella - (columns + 1 ));*/
            suma = *estrella;
            suma += *(estrella + (columns + 1));
            suma += *(estrella + (columns - 1));
            suma += *(estrella - (columns - 1));
            suma += *(estrella - (columns + 1 ));
            suma = suma/5;
            if(suma > 6){
                ++cantEstrellas;
            }
            estrella = estrella + 1;
        }
        estrella = estrella + 2;
    }
    return cantEstrellas;
}

void cuadradoMagico(){

    short int dimension = -1;
    while(dimension < 0){
        cout << "Escriba la dimension de la matriz cuadrada nxn  o 0 para salir" << endl;
        cin >> dimension;
        if(dimension == 0){
            cout << "Salir" << endl;
            return;
        }

        if (dimension > 0){
            break;
        }

        cout << "Dimension no valida" << endl;

    }
    if(dimension == 1){
        cout << "Una matriz de 1x1 se puede considerar un cuadrado magico" << endl;
        return;
    }

    int matriz[dimension][dimension];
    int *celda = &matriz[0][0];
    llenarMatriz(dimension, dimension, celda);
    mostrarMatriz(dimension, dimension, celda);

    if(tieneElementosRepetidos(dimension, dimension, celda)){
        cout << "La matriz tiene elementos repetidos. No es un cuadrado magico" << endl;
    }
    else if(isMagicSquare(dimension, dimension, celda)){
         cout << "La matriz es un cuadrado magico" << endl;
    }
    else{
         cout << "La matriz no es un cuadrado magico" << endl;
    }
}

void mostrarMatriz(int rows, int columns, int *celda){
    for(int r=0; r<rows; r++){
        for(int c=0; c<columns; c++){
            cout << *celda << " ";
            celda = celda + 1;
        }
        cout << endl;
    }
}

bool tieneElementosRepetidos(int rows, int columns, int* celda){
    int numeros[rows*columns];
    int* numero = numeros;
    int cantidad = 1;
    *numero = *celda;
    int i=1;
    while(i < rows*columns){
        for(int k=0; k<cantidad; k++){
            if(*(numero + k) == *(celda + i)){
                return true;
            }
        }
        *(numero + cantidad) = *(celda + i);
        ++cantidad;
        ++i;
    }
    return false;
}

void llenarMatriz(int rows, int columns, int *celda){
    for(int r=0; r<rows; r++){
        for(int c=0; c<columns; c++){
            cout << "Digite el elemento de la fila: " << r+1 << " columna: " << c+1 << endl;
            cin >> *celda;
            celda = celda + 1;
        }
    }
}

bool isMagicSquare(int rows, int columns, int *celda){
    int sumaControl = 0;
    int suma = 0;
    int i = 0;

    for(int i=0; i<rows*columns; i = i + (rows+1)){
        sumaControl += *(celda + i);
    }

    i = rows - 1;

    while(i <= ((rows*columns) - (rows - 1))){
        suma += *(celda + i);
        i = i + (rows-1);
    }

    if(suma != sumaControl){
        return false;
    }

    for(int i=0; i<columns; i++){
        suma = 0;
        for(int k=0; k<rows*columns; k = k+rows){
            suma += *(celda + i + k);
        }
        if(suma != sumaControl){
            return false;
        }
    }


    i = 0;
    while(i <= ((rows*columns) - (rows - 1))){
        suma = 0;
        for(int k=0; k<rows; k++){
            suma += *(celda + i + k);
        }
        if(suma != sumaControl){
            return false;
        }
        i = i + rows;
    }

    return true;
}

void sumarNumeros(int n){

    if(n <= 0){
        cout << "No se hicieron sumas pues no hay grupos de numeros para sumar" <<endl;
        return;
    }

    char numeros[9];
    char valores[n+1];
    char *valor = valores;
    char *numero = numeros;
    short int cantNumeros = 0;
    short int gruposNumeros = 0;
    int suma = 0;
    short faltantes = 0;
    cout << "Escriba un numero para separar" <<endl;
    cin >> numeros;

    while(*numero != '\0'){
        if (int(*numero) < 48 || int(*numero) > 57){
            cout << "La cadena contiene caracteres no numericos. No seguira" << endl;
            return;
        }
        else{
            cantNumeros++;
        }
        numero = numero + 1;
    }

    numero = numeros;
    gruposNumeros = cantNumeros / n;
    faltantes = cantNumeros % n;


    if (faltantes > 0){
        for(int i=faltantes; i<n; i++){
            *valor = '0';
            valor = valor + 1;
        }
        for(int i=0; i<faltantes; i++){
            *valor = *numero;
            valor = valor + 1;
            numero = numero+1;
        }
        *valor = '\0';
        suma += caracteresANumeros(valores);
        valor = valores;
    }

    for(short int i=0; i<gruposNumeros; i++){
        for(short int k=0; k<n; k++){
            *valor = *numero;
            numero = numero + 1;
            valor = valor + 1;
        }
        *valor = '\0';
        suma += caracteresANumeros(valores);
        valor = valores;
    }

    cout << suma << endl;
}

void separarNumerosCaracteres(char *cadena){
    char numeros[23];
    char otrosCaracteres[23];
    char *otroCaracter = otrosCaracteres;
    char *numero = numeros;
    char *i = cadena;

    while(*i != '\0'){
        if((int(*i) >= 48) && (int(*i) <= 57)){
            *numero = *i;
            numero = numero + 1;
        }
        else{
            *otroCaracter = *i;
            otroCaracter = otroCaracter + 1;
        }
        i = i+1;
    }
    *numero = '\0';
    *otroCaracter = '\0';
    cout <<"Original: " << cadena << endl;
    cout <<"Texto: " <<otrosCaracteres <<" " << "Numero: "<<numeros << endl;

}

void mayusculasMinusculas(char *palabra){

    char *caracter = palabra;
    while(*caracter != '\0'){
        if(int(*caracter) >= 97 && int(*caracter) <= 122){
            *caracter = char(int(*caracter) - 32);
        }
        caracter += 1;
    }
}

int caracteresANumeros(char numero[]){
    int num = 0;
    bool signo = false;
    char *digito = numero;
    short int i = 0;
    int cantDigitos = 0;
    while(*(numero + i) != '\0'){
        ++cantDigitos;
        ++i;
    }
    if (cantDigitos > 9){
        return 0;
    }

    if(int(*digito) == 45){
        signo = true;
        digito = digito + 1;
    }

    while(*digito != '\0'){
        if(int(*(digito)) < 48 || int(*(digito)) > 57 ){
            return 0; // Porque no es un número
        }
        num = (num * 10) + ((int(*(digito) - 48)));
        digito++;
    }

    if(signo){
        num *= -1;
    }

    return num;
}

bool compararCadenas(){
    char palabra1[24];
    char palabra2[24];
    char *letraPal1 = palabra1;
    char *letraPal2 = palabra2;
    int numPal1 = 0;
    int numPal2 = 0;
    cout << "Escriba la primera palabra: " << endl;
    cin >> palabra1;
    cout << "Escriba la segunda palabra: " << endl;
    cin >> palabra2;


    while(*letraPal1 != '\0'){
        numPal1++;
        letraPal1 = letraPal1 + 1;
    }

    while(*letraPal2 != '\0'){
        numPal2++;
        letraPal2 = letraPal2 + 1;
    }

    if(numPal1 != numPal2){
        return false;
    }

    letraPal1 = palabra1;
    letraPal2 = palabra2;

    while(true){
        if(*letraPal1 == '\0' && *letraPal2 == '\0'){
            return true;
        }
        if(*letraPal1 != *letraPal2){
            return false;
        }
        letraPal1 = letraPal1 + 1;
        letraPal2 = letraPal2 + 1;
    }

}

void devolver(){

    int billetesMonedas[] = {50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50};
    int cambio[] = {0,0,0,0,0,0,0,0,0,0};
    int aDevolver = 0;
    int *numBilletes = cambio;

    while(true){
        cout <<"Escriba la cantidad a devolver: "<<endl;
        cin >> aDevolver;
        if(aDevolver == 0){
            cout << "Nada a devolver" <<endl;
            return;
        }else if(aDevolver < 0){
            cout << "No se puede devolver una cantidad negativa" <<endl;
        }
        else{
            break;
        }
    }

    for(int *i=billetesMonedas; i<(billetesMonedas)+10; i++){
        if(aDevolver / *i != 0){
            *numBilletes = aDevolver / *i;
            aDevolver = aDevolver % *i;
        }
        numBilletes += 1;
    }

    numBilletes = cambio;
    for(int *i=billetesMonedas; i<(billetesMonedas)+10; i++){
        cout << *i << ":" << *numBilletes << endl;
        numBilletes += 1;
    }
    cout << "Faltante: " << aDevolver << endl;
}
