

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Tienda.h"


int oro=150, experiencia=0, nivel=0, mana=0, vida=0, monstruosDerrotados=0, potion=0, hipotion=0, mpotion=0, clave=1;

int quienAtaca, vidaMonstruo, factorAtaque, numeroMonstruo;
char nombreMonstruo[30], nombreJugador[30];
char DIRECCION[]="punteos.txt";
char DIRECCION2[]="punteosTemporal.txt";
char variableEnter;

int main(int argc, char** argv) {
    crearArchivo();
    mana=asignarMana();
    vida=asignarVida();
    srand(time(NULL));
    int opcion;
    char* nombre[20];
    char* temp1;
    printf("\n\nBIENVENIDO A PONKY SMASH");
    if(argc<=1){
        printf("\nVemos que no tienes un nombre");
        printf("\nPor favor escribe uno:");
        gets(nombreJugador);
        printf("hola");
        printf("\n%s",nombreJugador);
        fflush(stdin);
    }
    else{
        printf("\nhola");
        for(int i=1;i<argc;i++){
            temp1 = argv[i];
            strcat(nombreJugador, " ");
            strcat(nombreJugador,temp1);
           //printf(" %s ",nombre); 
        }
        printf("%s",nombreJugador);
        fflush(stdin);
    }
    pausa();
    do{
        printf("\n\n\tMENU PRINCIPAL\n");
        printf("\nSesion Iniciada como: %s",nombreJugador);
        printf("\n1.- A la Carga");
        printf("\n2.- Tienda");
        printf("\n3.- ZZzzZZzz");
        printf("\n4.- Status");
        printf("\n5.- Mejores Punteos");
        printf("\n6.- Salir");
        printf("\nOpcion: ");
        scanf("%i",&opcion);
        
        switch(opcion){
            case 1: aLaCarga();break;
            case 2: tienda();break;
            case 3: zzZZ();break;
            case 4: status();break;
            case 5: mostrarPunteos();break;
        }

    }while(opcion != 6);
    guardarPunteo();
    
    return (EXIT_SUCCESS);
}

