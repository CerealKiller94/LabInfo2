#include <iostream>

using namespace std;

bool devolverMonedas();
void validarFecha();
void dibujarFigura();
void sumaFibionacci();
void sumaMultiplos();
void sumaMultiplosElevados();
void minimoComunMultiplo();
int cribaEratostenes(int maximo);
void numerosPrimos();
bool isCapicua(int num);
void maximoCapicua();
int generarTriangular(int n);
int numeroDivisores(int n);
void divisoresTriangular();

int main()
{
    short int opc = -1;
    while(opc != 0){
        cout << "Seleccione una opcion: \n"
                "1. Problema 2 \n"
                "2. Problema 3 \n"
                "3. Problema 5 \n"
                "4. Problema 7 \n"
                "5. Problema 8 \n"
                "6. Problema 9 \n"
                "7. Problema 11 \n"
                "8. Problema 13 \n"
                "9. Problema 14 \n"
                "10. Problema 17 \n"
                "0. Salir \n" << endl;
        cin >> opc;

        switch (opc){
            case(0):
                cout << "Salir" << endl;
                break;
            case(1):
                cout << "Problema 2" << endl;
                if(not devolverMonedas()){
                    cout << "Vuelva a intentarlo" << endl;
                }
                break;
            case(2):
                cout << "Problema 3" << endl;
                validarFecha();
                break;
            case(3):
                cout << "Problema 5" << endl;
                dibujarFigura();
                break;
            case(4):
                cout << "Problema 7" << endl;
                sumaFibionacci();
                break;
            case(5):
                cout << "Problema 8" << endl;
                sumaMultiplos();
                break;
            case(6):
                cout << "Problema 9" << endl;
                sumaMultiplosElevados();
                break;
            case(7):
                cout << "Problema 11" << endl;
                minimoComunMultiplo();
                break;
            case(8):
                cout << "Problema 13" << endl;
                numerosPrimos();
                break;
            case(9):
                cout << "Problema 14" << endl;
                maximoCapicua();
                break;
            case(10):
                cout << "Problema 17" << endl;
                divisoresTriangular();
                break;
            default:
                cout << "Opcion no valida" << endl;
                break;
        }
    }


    return 0;
}

void maximoCapicua(){
    int maximo = 0;
    int mult1 = 0;
    int mult2 = 0;
    for(int i=100; i<= 999; i++){
        for(int k=i; k<=999; k++){
            if(isCapicua(i*k)){
                if(i*k > maximo){
                    maximo = i*k;
                    mult1 = i;
                    mult2 = k;
                }
            }
        }
    }
    cout << mult1 << "*" << mult2 << "=" << maximo << endl;
}

bool isCapicua(int num){

    int digito = 0;
    int restante = num;
    int numInvertido = 0;

    while(restante != 0){
        digito = restante%10;
        restante = restante/10;
        numInvertido = numInvertido*10 + digito;
    }
    if(numInvertido != num){
        return false;
    }

    return true;
}

bool isPrime(int numero){
    if(numero == 2){
        return true;
    }
    if(numero % 2 == 0){
        return false;
    }

    for(int i=3; i<numero; i +=2){
        if(numero%i == 0){
            return false;
        }
    }
    return true;
}

void numerosPrimos(){
    int numero = 0;
    int suma = 0;
    while(true) {
        cout << "Escriba un numero positivo para calcular la suma de primos o -1 para salir" << endl;
        cin >> numero;
        if(numero == -1){
            return;
        }else if(numero < 2){
            cout << "Ningun numero menor que 2 es primo. La suma es: 0" << endl;
        }
        else{
            break;
        }
    }
    for(int i=2; i<numero; i++){
        if(isPrime(i)){
            suma += i;
        }
    }
    cout << "La suma es: " << suma << endl;
}

bool devolverMonedas(){

    int devolver = 0;

    cout << "Escriba el valor a devolver: " << endl;
    cin >> devolver;

    if (devolver < 0){
        cout << "No es una cantidad valida para devolver" << endl;
        return false;
    }
    else if (devolver == 0){
        cout << "Nada a devolver" << endl;
        return true;
    }

    cout << "50000: " << devolver/50000 << endl;
    devolver %= 50000;

    cout << "20000: " << devolver/20000 << endl;
    devolver %= 20000;

    cout << "10000: " << devolver/10000 << endl;
    devolver %= 10000;

    cout << "5000: " << devolver/5000 << endl;
    devolver %= 5000;

    cout << "2000: " << devolver/2000 << endl;
    devolver %= 2000;

    cout << "1000: " << devolver/1000 << endl;
    devolver %= 1000;

    cout << "500: " << devolver/500 << endl;
    devolver %= 500;

    cout << "200: " << devolver/200 << endl;
    devolver %= 200;

    cout << "100: " << devolver/100 << endl;
    devolver %= 100;

    cout << "50: " << devolver/50 << endl;
    devolver %= 50;

    cout << "Faltante: " << devolver << endl;

    return true;
}

void validarFecha(){

   int dia = 0;
   int mes = 0;
   cout << "Escriba el mes: \n" << endl;
   cin >> mes;
   cout << "Escriba el dia \n" << endl;
   cin >> dia;

   if (dia > 31 || dia < 1){
       cout << dia << " es un dia invalido" << endl;
       return;
   }
   else if (mes > 12 || mes <1){
       cout << mes <<" es un mes invalido" << endl;
       return;
   }
   else if (mes == 2 && dia == 29){
       cout << dia << "/" << mes << " es valida en bisiesto" << endl;
       return;
   }
   else if (mes == 2 && dia > 29){
       cout << dia << "/" << mes << " es una fecha invalida" << endl;
       return;
   }
   else if ((mes == 4 || mes == 6 || mes == 8 || mes == 11) && dia > 30){
       cout << dia << "/" << mes << " es una fecha invalida" << endl;
       return;
   }
   cout << dia << "/" << mes << " es una fecha valida" << endl;
}

void dibujarFigura(){
    int lineas = 0;
    int blancos = 0;
    int figuras = 1;

    while(lineas % 2 == 0){
        cout << "Digite un numero impar para la figura o 0 para salir" << endl;
        cin >> lineas;
        if(lineas == 0){
            cout << "Cantidad par de líneas, reintente" << endl;
            return;
        }
        if(lineas < 0){
            cout << "Cantidad negativa de lineas, reintente" << endl;
            lineas = 0;
        }
    }
    blancos = lineas/2;
    while(figuras <= lineas){
        for(int i=0; i<blancos; i++){
            cout << " ";
        }
        for(int i=0; i<figuras; i++){
            cout << "*";
        }
        cout << "\n";
        figuras += 2;
        blancos -= 1;
    }

    blancos = 1;
    figuras = lineas-2;
    while(blancos <= (lineas/2)){
        for(int i=0; i<blancos; i++){
            cout << " ";
        }
        for(int i=0; i<figuras; i++){
            cout << "*";
        }
        cout << "\n";
        figuras -= 2;
        blancos += 1;
    }

}

void sumaFibionacci(){
    int n = 0;
    int suma = 0;
    int a = 1;
    int b = 1;
    int c = a + b;
    while(true){
        cout << "Escriba el maximo numero de la sucesion fibionacci que quiere ver o -1 para salir: " << endl;
        cin >> n;
        if(n == -1){
            return;
        }
        if(n < 0){
            cout << "La sucesion fibionacci es una sucesion positiva, reintente" << endl;
        }
        else{
            break;
        }
    }
    while(c < n){
        if ((c % 2) == 0){
            suma += c;
        }
        a = b;
        b = c;
        c = a + b;
    }
    cout << "El resultado de la suma es: " << suma << endl;

}

void sumaMultiplos(){
    int a, b, c;
    int multiplo = 1;
    int suma = 0;
    cout << "Escriba el primer numero (a): " << endl;
    cin >> a;
    cout << "Escriba el segundo numero (b): " << endl;
    cin >> b;
    cout << "Escriba el tercer numero (c): " << endl;
    cin >> c;

    while(multiplo < c){
        if(multiplo % a == 0){
            suma += multiplo;          
        }
        else if(multiplo % b == 0){
            if (!(multiplo % a == 0)){
                suma += multiplo;
            }
        }

        multiplo++;
    }

    cout << "La suma es: " << suma << endl;
}

void sumaMultiplosElevados(){
    int numero = 0;
    int suma = 0;
    int digito = 0;
    int potencia = 1;
    cout << "Escriba el numero: " << endl;
    cin >> numero;

    while(numero != 0){
        digito = numero%10;
        for(int i=1; i<= digito; i++){
            potencia *= digito;

        }
        suma += potencia;
        numero = numero / 10;
        potencia = 1;

    }
    cout << "El resultado de la suma es: " << suma <<endl;
}

void minimoComunMultiplo(){
    int maximo = 0;
    int numero = 1;
    while(maximo <= 0){
        cout << "Escriba el numero maximo mayor o igual que 1 para encontrar el mcm 0 -1 para salir: " << endl;
        cin >> maximo;
        if(maximo == -1){
            break;
        }
    }
    bool esMultiplo = false;
    while(!esMultiplo){
        esMultiplo = true;
        for(int i=2; i<=maximo; i++){
            if(!(numero % i == 0)){
                esMultiplo = false;
                numero++;
                break;
            }
        }
    }

    cout << "El minimo comun multiplo es: " << numero << endl;
}

int generarTriangular(int n){
    return n*(n + 1)/2;
}

int numeroDivisores(int n){
    int divisores = 1;
    for(int i=2; i<=n; i++){
        if(n%i == 0){
            divisores++;
        }
    }
    return divisores;
}

void divisoresTriangular(){
    int k = 0;
    int nTriangular = 1;
    int primerTriangular = 1;
    int numDivisores = 1;
    while(true){
        cout <<"Digite un numero mayor o igual que 0 o escriba -1 para salir: "<< endl;
        cin >> k;
        if(k == -1){
            return;
        }
        else if(k < 0){
            cout <<"Numero no valido "<< endl;
            continue;
        }
        break;
    }
    while(numDivisores <= k){
        nTriangular++;
        primerTriangular = generarTriangular(nTriangular);
        numDivisores = numeroDivisores(primerTriangular);
    }
    cout << "El numero es: " << primerTriangular << " que tiene: " << numDivisores << " divisores" << endl;
}
