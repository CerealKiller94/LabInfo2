#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
using namespace std;

bool leerArchivo(string nombre, string& archivoBinario);
string convertirBinario(char c);
string invertir(string binario);
int binarioDecimal(string binario);
string codificarMetodo2(string& archivoBinario, int semilla);
bool codificar();
string moverBits(string seccion);
bool escribir(string nombre, string aEscribir);
bool descodificar();
string descodificarMetodo2(string& archivoBinario, int semilla);
string regresarBits2(string& seccion);
string traducir(string& descodificado);
char intercambiarBit(char bit);
string codificarMetodo1(string& archivoBinario, int semilla);
int contarBits(string& noCodificado, string& aCodificar);
int contarBits(string& noCodificado);
string aplicarCifrado2(string& aCodificar, int resp);
string aplicarCifrado2(string& aCodificar, int resp);
string descodificarMetodo1(string& archivoBinario, int semilla);
void simularCajero();
string leerArchivoCajero(string& nombre);
void separar(string* arreglo, string& linea, char limitador);
bool agregarUsuario();
bool validarNumerosPositivos(string& cedula);
int contarSeparadores(string& cadena, char sep);
int validarUsuario(string& id, string& pass, string* usuarios, int cant);
float consultarSaldo(int user, string* usuarios);
bool actualizarUsuarios(string* usuarios, int cant);
bool retirarDinero(string* usuarios, int user, float saldo);

int main()
{

    short int opc = 0;
    while(true){
        cout << "Seleccione una opcion: \n"
                "1. Codificar \n"
                "2. Descodificar \n"
                "3. Simulador del cajero \n"
                "0. Salir \n" << endl;
        cin >> opc;
        switch (opc) {
            case 0:
                cout << "Salir" << endl;
                return 0;
            case 1:
                if(!codificar()){
                    cout << "Nada para codificar" << endl;
                }
            break;
            case 2:
                if(!descodificar()){
                    cout << "Nada para descodificar" << endl;
                }
            break;
            case 3:
                simularCajero();
                break;
            default:
                cout << "Opcion no valida" << endl;
            break;
        }

    }
    return 0;
}

void simularCajero(){
    /*
    id: 1001
    pass: 2020
    cifrado: 2
    Semilla: 16
    El nombre del archivo de usuarios debe ser: users.txt
    */
    short int opc = -1;
    string administrador[2];
    string nombre;
    string id;
    string pass;
    short int flag = -1;
    string linea;
    int user;
    float saldo;
    while(true){
        cout << "Seleccione su perfil: \n"
                "1. Administrador \n"
                "2. Usuario \n"
                "3. Salir \n" << endl;
        cin >> opc;
        switch (opc) {
            case 1:
                nombre = "sudo.txt";
                linea = leerArchivoCajero(nombre);
                if(linea != "-1"){
                    separar(administrador, linea, ',');
                    cout << "Escriba el id del administrador" << endl;
                    cin >> id;
                    cout << "Escriba el password del administrador" << endl;
                    cin >> pass;
                    if(administrador[0] == id && administrador[1] == pass){
                        cout << "Administrador" << endl;
                        cout << "Agregar un usuario? 1: Si, 0: No" << endl;
                        cin >> flag;
                        while(flag == 1){
                            if(flag == 1){
                                if(!agregarUsuario()){
                                    break;
                                }
                            }else if (flag != 0){
                                cout << "No eligio una opcion valida" << endl;
                            }
                            cout << "Agregar otro usuario? 1: Si, 0: No" << endl;
                            cin >> flag;
                        }
                    }
                    else{
                        cout << "Administrador no valido" << endl;
                    }
                }
                break;
            case 2:
                    nombre = "users.txt";
                    cout << "Cedula " << endl;
                    cin >> id;
                    cout << "Password" <<endl;
                    cin >> pass;
                    linea = leerArchivoCajero(nombre);
                    if(linea != "-1"){
                        int cant = contarSeparadores(linea, ',');
                        string usuarios[1024];
                        separar(usuarios, linea, ',');
                        user = validarUsuario(id, pass, usuarios, cant);
                        if(user != -1){
                            cout << "Usuario" << endl;
                            cout << "1: Consultar saldo\n"
                                    "2: Retirar dinero\n"
                                    "0. Salir" << endl;
                            cin >> flag;
                            while(flag == 1 || flag == 2){
                                switch (flag) {
                                    case 1:
                                        cout << "El costo de la transaccion es 1000" << endl;
                                        saldo = consultarSaldo(user, usuarios);
                                        if(saldo == -1){
                                            cout << "No tiene suficiente dinero para pagar la operacion" << endl;
                                        }else{
                                            cout << "Su saldo actual es: " << saldo << endl;
                                            actualizarUsuarios(usuarios,cant);
                                        }
                                        break;
                                    case 2:
                                        cout << "Valor a retirar" << endl;
                                        cin >> saldo;
                                        if(retirarDinero(usuarios, user, saldo)){
                                            cout << "La operacion tiene un costo de 1000" << endl;
                                            cout << "Valor retirado: " << saldo << endl;
                                            actualizarUsuarios(usuarios,cant);
                                        }else{
                                            cout << "No hay dinero suficiente para retirar" << endl;
                                        }
                                    case 3:
                                        return;
                                }
                                cout << "1: Consultar saldo\n"
                                        "2: Retirar dinero\n"
                                        "0. Salir" << endl;
                                cin >> flag;
                            }
                        }
                        else{
                            cout << "El usuario no existe" << endl;
                        }
                    }
                    break;
            case 3:
                return;
            default:
                    cout << "Selecciono una opcion no valida" << endl;
                    break;
        }
    }
}

bool retirarDinero(string* usuarios, int user, float saldo){
    float saldoActual = stof(*(usuarios + user + 2));
    if(saldoActual < saldo+1000){
        return false;
    }
    *(usuarios + user + 2) = to_string(saldoActual-(saldo+1000));
    return true;
}

bool actualizarUsuarios(string* usuarios, int cant){
    string binaryUser = "";
    string linea = "";
    for(int i=0; i<cant; i++){
        linea += usuarios[i] + ",";
    }

    for(int i=0; i<int(linea.length()); i++){
        binaryUser += convertirBinario(linea[i]);
    }
    binaryUser = codificarMetodo2(binaryUser, 16);
    ofstream escribir("users.txt");
    escribir << binaryUser;
    return true;

}

float consultarSaldo(int user, string* usuarios){
    float saldoActual = stof(*(usuarios + user + 2)) - 1000;
    if(saldoActual < 1000){
        return -1;
    }
    *(usuarios + user + 2) = to_string(saldoActual);
    return saldoActual;
}

int validarUsuario(string& id, string& pass, string* usuarios, int cant){
    for(int i=0; i<cant; i+=3){
        if(*(usuarios + i) == id && *(usuarios + i + 1) == pass){
            return i;
        }
    }
    return -1;
}

int contarSeparadores(string& cadena, char sep){
    int cont = 0;
    for(int i=0; i<int(cadena.length()); i++){
        if(cadena[i] == sep){
            cont++;
        }
    }
    return cont;

}

bool agregarUsuario(){
    cout << "Agregar usuario. Presione 0 en cualquier momento para cancelar" << endl;
    string cedula;
    string pass;
    string saldo;
    string user = "";
    string binaryUser = "";
    string linea;
    string nombre;
    while (true){
        cout << "Escriba la cedula o 0 para cancelar" << endl;
        cin >> cedula;
        if(cedula == "0"){
            return false;
        }
        if(validarNumerosPositivos(cedula)){
            break;
        }
    }

    cout << "Escriba el password o 0 para cancelar" << endl;
    cin >> pass;

    if(pass == "0"){
        return false;
    }

    while (true){
        cout << "Escriba el saldo o 0 para cancelar" << endl;
        cin >> saldo;
        if(saldo == "0"){
            return false;
        }
        if(validarNumerosPositivos(saldo)){
            break;
        }
    }
    nombre = "users.txt";
    linea = leerArchivoCajero(nombre);
    if(linea != "-1"){
        int cant = contarSeparadores(linea, ',');
        string usuarios[1024];
        separar(usuarios, linea, ',');
        for(int i=0; i<cant; i+=3){
            if(*(usuarios + i) == cedula){
                cout << "El usuario ya existe" << endl;
                return true;
            }
        }
    }
    user = cedula + "," + pass + "," + saldo + ",";
    for(int i=0; i<int(user.length()); i++){
        binaryUser += convertirBinario(user[i]);
    }

    binaryUser = codificarMetodo2(binaryUser, 16);
    ofstream escribir("users.txt", ios::app);
    escribir << binaryUser;
    return true;
}

bool validarNumerosPositivos(string& cedula){
    for(int i=0; i<int(cedula.length()); i++){
        if(int(cedula[i]) < 48 || int(cedula[i]) > 57){
            return false;
        }
    }
    return true;
}

string leerArchivoCajero(string& nombre){
    string linea = "";
    try {
        ifstream texto(nombre);
        if(!texto.is_open()){
            throw 0;
        }
        while(!texto.eof()){
            getline(texto, linea);
            linea = descodificarMetodo2(linea, 16);
            linea = traducir(linea);
        }
    }  catch(int except) {
        if(except == 0){
            cout << "El archivo de texto no existe o el nombre no es valido" << endl;
            return "-1";
        }
    }
    return linea;
}

void separar(string* arreglo, string& linea, char limitador){
    int i = 0;
    int tam = int(linea.length());
    string elemento;
    for(int k=0; k<tam; k++){
        if(linea[k] == limitador){
            *(arreglo + i) = elemento;
            elemento.clear();
            i++;
        }else{
            elemento += linea[k];
        }
    }
    *(arreglo + i) = elemento;
}

bool descodificar(){
    string nombre, salida, archivoBinario, descodificado;
    int semilla, opc;
    cout << "Escriba el nombre del archivo a descodificar" << endl;
    cin >> nombre;
    nombre += ".txt";
    cout << "Escriba la semilla de codificacion" << endl;
    cin >> semilla;
    cout << "Escriba el nombre del archivo de salida" << endl;
    cin >> salida;
    salida += ".txt";

    if(semilla < 0){
        return false;
    }

    try {
        ifstream texto(nombre);
        if(!texto.is_open()){
            throw 0;
        }
        char c;
        while(texto.get(c)){
             archivoBinario += c;
        }
        texto.close();
    }  catch(int except) {
        if(except == 0){
            cout << "El archivo de texto no existe o el nombre no es valido" << endl;
            return false;
        }
    }

    cout << "Seleccione una opcion:\n"
            "1. Descodificar metodo 1\n"
            "2. Descodificar metodo 2\n" << endl;
    cin >> opc;
    switch (opc) {
        case 1:
            descodificado = descodificarMetodo1(archivoBinario, semilla);
            if(escribir(salida, traducir(descodificado))){
                cout << "Archivo descodificado con metodo 1" << endl;
            }
            break;
        case 2:
            descodificado = descodificarMetodo2(archivoBinario, semilla);
            if(escribir(salida, traducir(descodificado))){
                cout << "Archivo descodificado con metodo 2" << endl;
            }
            break;
        default:
            break;
    }
    return true;
}

string descodificarMetodo1(string& archivoBinario, int semilla){
    string descodificado = "";
    string noCodificado = "";
    string aDescodificar = "";
    int tam = archivoBinario.length();
    if(semilla > tam){
        semilla = tam;
    }
    int secciones = tam/semilla;
    int faltantes = tam%semilla;
    int i=1;
    int j=semilla;
    int resp;

    if(semilla > int(archivoBinario.length())){
        semilla = int(archivoBinario.length());
    }

    for(int i=0; i<semilla; i++){
        noCodificado += intercambiarBit(archivoBinario[i]);
    }
    descodificado += noCodificado;

    while(i<secciones){
        for(int k=0; k<semilla; k++){
            aDescodificar += archivoBinario[j+k];
        }
        j+=semilla;
        resp = contarBits(noCodificado);
        noCodificado = aplicarCifrado2(aDescodificar, resp);
        descodificado += noCodificado;
        aDescodificar.clear();
        i++;

    }

    if(faltantes > 0){
        for(int k=0; k<faltantes; k++){
            aDescodificar += archivoBinario[j+k];
        }
        resp = contarBits(noCodificado);
        descodificado += aplicarCifrado2(aDescodificar, resp);
    }

    return descodificado;
}

string traducir(string& descodificado){
    string byte = "";
    string traducido = "";
    int tam = descodificado.length();
    for(int i=0; i<tam; i+=8){
        for(int k=i; k<i+8; k++){
            byte += descodificado[k];
        }
        traducido += char(binarioDecimal(byte));
        byte.clear();
    }
    return traducido;
}

string descodificarMetodo2(string& archivoBinario, int semilla){
    string seccion;
    string descodificado = "";
    int tam = archivoBinario.length();
    if(tam == 0){
        return descodificado;
    }
    if(semilla > tam){
        semilla = tam;
    }
    int secciones = tam/semilla;
    int sobrantes = tam%semilla;
    int i = 0;
    int k = 0;
    int j = 0;
    while(i < secciones){
        while(k < semilla){
            seccion += archivoBinario[j];
            j++;
            k++;
        }
        k = 0;
        i++;
        descodificado += regresarBits2(seccion);
        seccion.clear();
    }

    if(sobrantes > 0){
        for(int i=0; i<sobrantes; i++){
            seccion += archivoBinario[j];
            j++;
        }
    descodificado += regresarBits2(seccion);
    }
    return descodificado;
}


string regresarBits2(string& seccion){
    string seccionAux = "";
    int tam = seccion.length();
    seccionAux += seccion[tam-1];
    for(int i=0; i<tam-1; i++){
        seccionAux += seccion[i];
    }
    return seccionAux;
}

bool codificar(){
    string nombre, archivoBinario, salida, codificado;
    int opc;
    int semilla;

    cout << "Escriba el nombre del archivo a codificar" << endl;
    cin >> nombre;
    nombre += ".txt";

    cout << "Escriba la semilla de codificacion " << endl;
    cin >> semilla;

    cout << "Escriba el nombre del archivo de salida" << endl;
    cin >> salida;
    salida += ".txt";

    if(semilla < 0){
        return false;
    }

    if(!leerArchivo(nombre, archivoBinario)){
        cout << "No se pudo leer un archivo valido" << endl;
        return false;
    }

    cout << "Seleccione una opcion:\n"
            "1. Codificar metodo 1\n"
            "2. Codificar metodo 2\n" << endl;
    cin >> opc;
    switch (opc) {
        case 1:
            codificado = codificarMetodo1(archivoBinario, semilla);
            if(escribir(salida, codificado)){
                cout << "Archivo codificado con metodo 1" << endl;
            }
            break;
        case 2:
            codificado = codificarMetodo2(archivoBinario, semilla);
            if(escribir(salida, codificado)){
                cout << "Archivo codificado con metodo 2" << endl;
            }
            break;
        default:
            break;
    }
    return true;
}

string codificarMetodo1(string& archivoBinario, int semilla){
    string codificado = "";
    string noCodificado = "";
    string aCodificar = "";
    int tam = archivoBinario.length();
    if(semilla > tam){
        semilla = tam;
    }
    int secciones = tam/semilla;
    int faltantes = tam%semilla;
    int i=1;
    int j=0;
    int resp;
    for(int i=0; i<semilla; i++){
        codificado += intercambiarBit(archivoBinario[i]);
    }

    while(i<secciones){
        for(int k=0; k<semilla; k++){
            noCodificado += archivoBinario[j];
            j++;
        }
        for(int k=0; k<semilla; k++){
            aCodificar += archivoBinario[j+k];
        }
        resp = contarBits(noCodificado);
        noCodificado.clear();
        codificado += aplicarCifrado2(aCodificar, resp);
        aCodificar.clear();
        i++;

    }
    if(faltantes > 0){
        for(int i=0; i<semilla; i++){
            noCodificado += archivoBinario[j];
            j++;
        }
        for(int k=0; k<faltantes; k++){
            aCodificar += archivoBinario[j+k];
        }
        resp = contarBits(noCodificado);
        noCodificado.clear();
        codificado += aplicarCifrado2(aCodificar, resp);
        aCodificar.clear();
    }

    return codificado;
}

string aplicarCifrado2(string& aCodificar, int resp){
    string cifrado = "";
    int saltos = 1;
    int k = 0;
    if(resp == 0){
        saltos = 2;
    }
    else if(resp == 1){
        saltos = 3;
    }

    for(int i=0; i<int(aCodificar.length()); i++){
        ++k;
        if(k==saltos){
            cifrado += intercambiarBit(aCodificar[i]);
            k=0;
        }
        else{
            cifrado += aCodificar[i];
        }

    }

    return cifrado;
}

int contarBits(string& noCodificado){
    int numCeros = 0;
    int numUnos = 0;
    for(int i=0; i < int(noCodificado.length()); i++){
        if(noCodificado[i] == '0'){
            numCeros++;
        }
        else{
            numUnos++;
        }
    }
    if(numCeros > numUnos){
        return 0;
    }else if(numUnos > numCeros){
        return 1;
    }
    else{
        return -1;
    }
}

char intercambiarBit(char bit){
    if(bit == '1'){
        return '0';
    }
    return '1';
}

bool escribir(string nombre, string aEscribir){
    ofstream escribir(nombre);
    escribir << aEscribir;
    return true;
}


string codificarMetodo2(string& archivoBinario, int semilla){
    string seccion;
    string codificado;
    int tam = int(archivoBinario.length());
    if(semilla > tam){
        semilla = tam;
    }
    int secciones = tam/semilla;
    int sobrantes = tam%semilla;
    int i = 0;
    int k = 0;
    int j = 0;
    while(i < secciones){
        while(k < semilla){
            seccion += archivoBinario[j];
            j++;
            k++;
        }
        k = 0;
        i++;
        codificado += moverBits(seccion);
        seccion.clear();
    }

    if(sobrantes > 0){
        for(int i=0; i<sobrantes; i++){
            seccion += archivoBinario[j];
            j++;
        }
    codificado += moverBits(seccion);
    }
    return codificado;
}

string moverBits(string seccion){
    string nuevaSeccion;
    for(int i=1; i<int(seccion.length()); i++){
        nuevaSeccion += seccion[i];
    }
    nuevaSeccion += seccion[0];
    return nuevaSeccion;
}

bool leerArchivo(string nombre, string& archivoBinario){
    try {
        ifstream texto(nombre);
        if(!texto.is_open()){
            throw 0;
        }
        char c;
        while(texto.get(c)){
             archivoBinario += convertirBinario(c);
        }
    }  catch(int except) {
        if(except == 0){
            cout << "El archivo de texto no existe o el nombre no es valido" << endl;
            return false;
        }
    }
    return true;
}

string convertirBinario(char c){
    string binario;
    binario.clear();
    short int charNumber = int(c);
    for(int i=0; i<8; i++){
        binario += to_string(charNumber%2);
        charNumber = charNumber/2;
    }

    binario = invertir(binario);
    return binario;
}

string invertir(string binario){
    char aux;
    int tam = binario.length();
    for(int i=0; i<tam/2; i++){
        aux = binario[i];
        binario[i] = binario[tam-1-i];
        binario[tam-1-i] = aux;
    }
    return binario;
}

int binarioDecimal(string binario){
    int decimal = 0;
    int i=0;
    for(int j=7; j>=0; j--){
        decimal += (binario[i] - '0') * pow(2, j);
        i++;
    }
    return decimal;
}
