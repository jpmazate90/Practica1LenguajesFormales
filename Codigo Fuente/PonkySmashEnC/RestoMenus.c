

extern int oro, experiencia, nivel, mana, vida, monstruosDerrotados, potion, hipotion, mpotion, clave;
extern int quienAtaca, vidaMonstruo, factorAtaque, numeroMonstruo;
extern char nombreMonstruo[30], nombreJugador[30];
extern int variableEnter;

void pausa(){
    printf("\nPresiona cualquier tecla y enter para continuar\n");
    scanf("%c",&variableEnter);
}

int asignarVida(){
    int vidaTemporal;
    vidaTemporal=100*(nivel+1);
    return vidaTemporal;
}
int asignarMana(){
    int manaTemporal;
    manaTemporal=10*(nivel+1);
    return manaTemporal;
}

void tienda(){
    int opcion;
    printf("\n\tTIENDA\n");
    do{        
        printf("\nTu oro actual es: %i",oro);
        printf("\n1.- Potion: cura 25 hp, por 50 de oro");
        printf("\n2.- Hi-Potion: cura 75 hp, por 100 de oro");
        printf("\n3.- M-potion: repone 10 mp, por 75 de oro");
        printf("\n4.- Regresar");
        printf("\nOpcion: ");
        scanf("%i",&opcion);
        
        switch(opcion){
            case 1: if(oro-50<0){//si no tiene oro
                      printf("\nNo tienes suficiente oro para comprar una Potion, pulsa enter");
                      pausa();
                    }else{//si tiene oro ejecuta la compra
                              oro=oro-50;
                              potion=potion+1;
                              printf("\nExcelente acabas de comprar una Potion");
                              printf("\nTu cantidad de Potion actual es %i ",potion);
                              
                             pausa();
                      } 
                      break;
            case 2: if(oro-100<0){//si no tiene oro
                       printf("\nNo tienes suficiente oro para comprar una Hi-Potion, pulsa enter");
                       pausa();
                    }else{    //si tiene oro
                       oro-=100;
                       hipotion=hipotion+1;
                       printf("\nAcabas de comprar una Hi-Potion");
                       printf("\nTu cantidad de Hi-potion actual es %i",hipotion);
                       pausa();
                    }
                    break;
            case 3: if(oro-75<0){//si no tiene oro
                        printf("\nNo tienes suficiente oro para comprar una M-Potion, pulsa enter");
                        pausa();
                    }else{// si tiene oro ejecuta la compra
                        oro=oro-75;
                        mpotion=mpotion+1;
                        printf("\nCompraste una M-potion");
                        printf("\nTu cantidad de M-Potion es: %i ",mpotion);
                        pausa();
                    }
                    break;
        }
                
    }while(opcion!=4);
}

void zzZZ(){
    int opcion;
    do{
        printf("\n\t ZZzzZZzz\n");
        printf("\nTe recuperarás por 30 de oro");
        printf("\nTu oro actual es: %i",oro);
        printf("\nTu vida actual es: %i",vida);
        printf("\nTu mana actual es: %i ",mana);
        printf("\n1.- Recuperarme");
        printf("\n2.- Regresar");
        printf("\nOpcion: ");
        scanf("%i",&opcion);
        
        if(opcion==1){
            if(oro-30<0){
                // si no tiene oro suficiente aparece esto
                printf("\nNo tienes suficiente oro para curarte, pulsa enter\n");
                pausa();
            }else{
                //si tiene oro aparece esto
                vida=asignarVida();
                mana=asignarMana();
                oro=oro-30;
                printf("Tu vida ahora es: %i ",vida);
                printf("Tu mana ahora es %i ",mana);
                printf("Tu oro actual es: %i ",oro);
                printf("Pulsa enter");
                pausa();
          }
        }
    }while(opcion!=2);
}

void status(){
    int opcion;
    do{
        printf("\nPULSE 1 PARA SALIR");
        printf("\nJugador: %s",nombreJugador);
        printf("\nExperiencia: %i", experiencia);
        printf("\nOro: %i ",oro);
        printf("\nNivel: %i",nivel);
        printf("\nManá: %i ",mana);
        printf("\nVida: %i",vida);
        printf("\nPotion: %i",potion);
        printf("\nHi-Potion: %i",hipotion);
        printf("\nM-Potion: %i",mpotion);
        printf("\nMonstruos derrotados: %i\n",monstruosDerrotados);
        scanf("%i",&opcion);
    }while(opcion!=1);
    
}



