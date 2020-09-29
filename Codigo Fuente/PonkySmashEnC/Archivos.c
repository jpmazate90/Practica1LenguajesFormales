#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


extern int oro, experiencia, nivel, mana, vida, monstruosDerrotados, potion, hipotion, mpotion, clave;
extern int quienAtaca, vidaMonstruo, factorAtaque, numeroMonstruo;
extern char nombreMonstruo[30], nombreJugador[30];
FILE *archivoPunteos, *archivoPunteos2;
extern char DIRECCION[],DIRECCION2[];
extern int variableEnter;

char temporal[50];
char auxiliar;
typedef struct{
    char *nombre;
    int punteo;
}punteos;

punteos *punteo;

void mostrarPunteos(){
    leerDatosArchivo();
    mostrarDatosArchivo();
}
void guardarPunteo(){
    leerDatosArchivo();
    copiarDatosArchivo();
    escribirTexto();
    leerDatosArchivo();
    printf("\nSe registro tu punteo");
}

void crearArchivo(){
    
    archivoPunteos = fopen(DIRECCION,"rt");
    if(archivoPunteos !=NULL){
    }else{
        archivoPunteos = fopen(DIRECCION,"wt");
        printf("\nSe ha creado el archivo correctamente %s",DIRECCION);
    }
    fclose(archivoPunteos);
}

void copiarDatosArchivo(){
    archivoPunteos = fopen(DIRECCION,"rt");
    archivoPunteos2 = fopen(DIRECCION2,"wt");
    rewind(archivoPunteos);
    while(!feof(archivoPunteos)){
        fgets(temporal,50,archivoPunteos);
        if(temporal!=NULL){
        fprintf(archivoPunteos2,temporal);
        }
        else{
        }
        vaciar(temporal);
    }
    fclose(archivoPunteos);
    fclose(archivoPunteos2);
}

void vaciar(char temporal[]){
    for(int i=0;i<50;i++){
        temporal[i]='\0';
    }
}

void copiar(char temporal[], int i){
    int capacidad = strlen(temporal)+1;
    punteo[i].nombre = (char*)malloc(capacidad*sizeof(char));
    strcpy(punteo[i].nombre,temporal);
}


// solucionado
void leerDatosArchivo(){
    int contador=cantidadRegistros();
    archivoPunteos = fopen(DIRECCION,"rt");
    if(archivoPunteos==NULL){
        printf("\nNo se ha podido acceder al archivo");
        exit(1);
    }
    punteo =(punteos*)malloc(contador*sizeof(punteos));
    for(int i=0;!feof(archivoPunteos);i++){
        vaciar(temporal);
        auxiliar ='\0';
        for(int j=0; auxiliar !='-' || auxiliar==-1;j++){
            auxiliar = fgetc(archivoPunteos);
            if(auxiliar!='-'){
                temporal[j] = auxiliar;
            }
            if(auxiliar==-1){
                break;
            }
        }
        copiar(temporal, i);
        fgets(temporal,6,archivoPunteos);
        punteo[i].punteo = atoi(temporal);   
    }
    fclose(archivoPunteos);
}

void mostrarDatosArchivo(){
    printf("\n\n");
    printf("\tTOP 5 DE MEJORES PUNTEOS");
    int auxiliar = sizeof(punteo);
    for(int i=0;i<auxiliar;i++){
        if(punteo[i].nombre!=NULL && punteo[i].punteo!=NULL){
            printf("\n%i.-Jugador: %s, Punteo:%i",i+1,punteo[i].nombre,punteo[i].punteo);
        }else{
            break;
        }
    }
    pausa();
}
void escribirTexto(){
    int contador= cantidadRegistros();
    archivoPunteos= fopen(DIRECCION,"wt");
    archivoPunteos2= fopen(DIRECCION2,"rt");
    int clave=1;
    if(punteo[0].nombre!=NULL && punteo[0].punteo!=NULL){
    for(int j=0;j<contador && j<5;j++){
        vaciar(temporal);
        if(monstruosDerrotados>punteo[j].punteo && clave==1){
            escribirRegistroActual(archivoPunteos);
            clave=0;
        }else{
            fgets(temporal,50,archivoPunteos2);
            fwrite(temporal,1,strlen(temporal),archivoPunteos);
        }
    }
    }else{
        escribirRegistroActual(archivoPunteos);
    }
    fclose(archivoPunteos);
    fclose(archivoPunteos2);
}

int cantidadRegistros(){
    int contador=0;
    archivoPunteos=fopen(DIRECCION,"rt");
    while(!feof(archivoPunteos)){
        fgets(temporal,50,archivoPunteos);
        contador++;
    }
    fclose(archivoPunteos);
    return contador;
}
// lo uso y es nuevo
void escribirRegistroActual(FILE *archivo1){
    char punteoTemporal[5];
    sprintf(punteoTemporal,"%i",monstruosDerrotados);
    fflush(stdin);
    fwrite(nombreJugador,1,strlen(nombreJugador),archivo1);
    fprintf(archivo1,"-");
    fwrite(punteoTemporal,1,strlen(punteoTemporal),archivo1);
    fprintf(archivo1,"\n");
}


/*
void ordenamientoPorInsercion(int[] arregloNumeros){
        int variableAuxiliar;
        int contador1;
        int contador2;
        for(contador1 = 1;contador1<arregloNumeros.length;contador1++){
            variableAuxiliar= arregloNumeros[contador1];
            for(contador2=contador1-1;contador2>=0 & arregloNumeros[contador2]>variableAuxiliar; contador2--){
                arregloNumeros[contador2+1]=arregloNumeros[contador2];
                arregloNumeros[contador2]=variableAuxiliar;
            }  
        }
    }
*/
/*
void anadirDatosArchivo(){
    int contador=0;
    int posicionJugador;
    int auxiliar=0;
    archivoPunteos = fopen(DIRECCION,"rt");
    while(!feof(archivoPunteos)){
        fgets(temporal,50,archivoPunteos);
        contador++;
    }
    rewind(archivoPunteos);
    contador-=1;
    auxiliar=monstruosDerrotados;
    if(contador==5){
        for(int i=0;!feof(archivoPunteos);i++){
            if(monstruosDerrotados>punteo[i].punteo){
                posicionJugador=i;
                colocarPosicionJugador(contador, posicionJugador);
                break;
            }
        }
    }        
    if(contador<5){
        for(int i=0;!feof(archivoPunteos);i++){
            if(monstruosDerrotados>punteo[i].punteo){
                posicionJugador=i;
                colocarPosicionJugador(contador,posicionJugador);
                break;
            }
        }
    }
}*/

// falta analizarlo posiblemente no se tenga que utilizar para nada
/*void colocarPosicionJugador(int contadorLocal, int posicionJugadorLocal){
    rewind(archivoPunteos);
    char jugadorAGuardar[50];
    if(contadorLocal<5){
        for(int i=0; i<posicionJugadorLocal+1;i++){
            fgets(jugadorAGuardar,50,archivoPunteos);
            
        }
        vaciar(jugadorAGuardar);
        fprintf(archivoPunteos, "%s-%i\n",nombreJugador,monstruosDerrotados);
        //crearNuevoArchivo(contadorLocal+1);

        
        
    }else{
        if(contadorLocal==5){
            for(int i=0; i<posicionJugadorLocal+1;i++){
            fgets(jugadorAGuardar,50,archivoPunteos);
            
            }
            vaciar(jugadorAGuardar);
            fprintf(archivoPunteos, "%s-%i\n",nombreJugador,monstruosDerrotados);
            //crearNuevoArchivo(contadorLocal);
        }
    }
}*/
/*// este nos servira para ver cuantos copiara luego
void crearNuevoArchivo(int contadorLocal2){
    char datos[50];
    copiarDatosArchivo(archivoPunteos);
    archivoPunteos2 = fopen(DIRECCION2,"rt");
    vaciar(temporal);
    //aqui esta el error
    archivoPunteos = fopen(DIRECCION,"wt");
    for(int j=0;j<contadorLocal2;j++){
        fgets(temporal,50,archivoPunteos2);
        fprintf(archivoPunteos,temporal);
        fprintf(archivoPunteos,"\n");
    }
}*/