
extern int oro, experiencia, nivel, mana, vida, monstruosDerrotados, potion, hipotion, mpotion, clave;
extern int quienAtaca, vidaMonstruo, factorAtaque, numeroMonstruo;
extern char nombreMonstruo[30], nombreJugador[30];
extern int variableEnter;

void aLaCarga(){
    // escoge quien sera el oponente
    iniciarDatosDeJuego();
    // llama a iniciar los datos de turno y monstruo aleatorio
    opcionesDePelea();
}


void iniciarDatosDeJuego(){
    //procedimiento para escoger turno de atacante y monstruo, aleatoriamente todo.
    numeroMonstruo = 1+rand()%(3+1-1);
    if(numeroMonstruo==1){
        vidaMonstruo=100;
        factorAtaque=10;
        strcpy(nombreMonstruo,"Dark Wolf");
        
    }
    if(numeroMonstruo==2){
        vidaMonstruo=200;
        factorAtaque=15;
        strcpy(nombreMonstruo,"Dragon");
    }
    if(numeroMonstruo==3){
        vidaMonstruo=300;
        factorAtaque=25;
        strcpy(nombreMonstruo,"Mighty Golem");
    }
    quienAtaca= 1+rand()%(2+1-1);
    printf("\n\nTe enfrentaras a: %s ",nombreMonstruo);
    printf("\nSu factor de ataque es: %i",factorAtaque);
    printf("\nSu vida es: %i",vidaMonstruo);
}

void opcionesDePelea(){

    //aparece cuando se llama a la carga en el menu principal, es el encargado de toda la pelea
    int opcion;
    //variabel local
    clave=1;//clave de tengo miedo, para cuando se pulse dicho procedimiento termine la batalla, es un comodin
    while(vida>0 && vidaMonstruo>0 && clave==1){
        // ciclo mientras tenga vida algun jugador y no le de a tengo miedo
        if(quienAtaca==1 && vida>0){
            printf("\n\nJugador: %s",nombreJugador);
            printf("\nNivel: %i",nivel);
            printf("\nVida: %i",vida);
            printf("\nManá: %i",mana);
            printf("\nOro: %i     Experiencia: %i     Monstruos derrotados: %i",oro,experiencia,monstruosDerrotados);
            printf("\nMonstruo Enemigo: %s",nombreMonstruo);
            printf("\nVida: %i     Factor de ataque: %i",vidaMonstruo,factorAtaque);
            printf("\nEs tu turno puedes escoger 4 opciones");
            printf("\n1.-Atacar");
            printf("\n2.-Curar");
            printf("\n3.-Item");
            printf("\n4.-Tengo miedo\n");
            scanf("%i",&opcion);
            switch(opcion){
                case 1:opcionAtacar();break;
                case 2:opcionCurar();break;
                case 3:opcionItem();break;
                case 4:tengoMiedo();break;
            }
            // muestra todas las estadisticas de la batalla, en tiempo real
    }
        if (quienAtaca==2){
            // cualquiera de estos procedimientos terminan aqui, a excepcion de tengo miedo
            printf("\nataca el enemigo");
            opcionAtacar();
            // llama otra vez al procedimiento opcion atacar pero ahora solo para el monstruo
        }
    }//Termina el while
    if(vida<=0){
        // comodin de cuando el monstruo mata al jugador
        printf("\nTurno de: %s, Pulsa enter",nombreMonstruo);
        pausa();
        printf("\nTe ha atacado: %s",nombreMonstruo);
        printf("\nAhora tienes de vida: 0 ");
    }
            opcionVidaJugador();
            /* esto se ejecuta cuando el monstruo mata al jugador
                reinicia las estadisticas
            */
    
}//termina el procedimiento opciones de pelea

void opcionAtacar(){
    //procedimiento para atacar segun a quien le haya tocado el turno
    int numeroAleatorio3;
    int numeroAleatorio10, danioJugador;
    //variables locales
    if(quienAtaca==1){
        numeroAleatorio3=10+rand()%(20+1-10);
        danioJugador=(((nivel+1)*10)+numeroAleatorio3);
        vidaMonstruo=vidaMonstruo-danioJugador;
    // procedimiento para hacerle daño al monstruo mediante numeros aleatorios
        printf("\nLe haz hecho daño a: %s",nombreMonstruo);
        if(vidaMonstruo<0){
            printf("\nSu vida ahora es 0");
        }else{
            printf("\nSu vida ahora es: %i",vidaMonstruo);
        }
        opcionVidaMonstruo();
        if(vida>0 & vidaMonstruo>0){
            quienAtaca=2;
        }
    
    }//fin si mayor 1
    if(quienAtaca==2){
        numeroAleatorio10=(factorAtaque+nivel)+rand()%((factorAtaque+nivel+10+1)-factorAtaque+nivel);
        vida=vida-numeroAleatorio10;
    //forma de bajarle vida al jugador mediante los valores del monstruo
        if(vida>0){
            printf("\nTurno de: %s, pulsa enter",nombreMonstruo);
            pausa();
            printf("\nTe ha atacado: %s",nombreMonstruo);
            printf("\nAhora tienes de vida: %i",vida);
            opcionVidaMonstruo();
            if(vida>0 && vidaMonstruo>0){
                quienAtaca=1;
            }
        }
    }//fin si mayor 2
}//fin metodo opcion_atacar
void opcionVidaMonstruo(){
    /* esta entra en accion cuando el monstruo se queda sin vida
        Premia al jugador con oro y experiencia, ademas de darle un monstruo derrotado
    */
    if(vidaMonstruo<=0){
        printf("\nHaz conseguido la victoria");
        int numeroAleatorio1, numeroAleatorio2;
        numeroAleatorio1= 2 + rand()%(5+1-2);
        numeroAleatorio2= 5 + rand()%(15+1-5);
        oro=oro+(factorAtaque*numeroAleatorio2);
        experiencia=experiencia+(factorAtaque*numeroAleatorio1);
        monstruosDerrotados=monstruosDerrotados+1;
        //forma de premiar al jugador con valores aleatorios a excepcion de monstruos derrotados
        printf("\nHaz ganado oro por la victoria, ahora  tienes: %i",oro);
        printf("\nHaz ganado experiencia por la victoria, ahora tienes : %i",experiencia);
        printf("\nHaz derrotado a un monstruo, en total haz derrotado a : %i Monstruos",monstruosDerrotados);
        pausa();
        subirNivel();
        pausa();
    }//Termina if vida monstruo

}
void opcionVidaJugador(){
    /* esta entra en accion cuando el jugador se queda sin vida
       reinicia estadisticas
    */
        if (vida<=0){
            printf("\nHaz perdido la batalla");
            printf("\nTus estadisticas se reiniciaran");
            printf("\nTu punteo se registrara");
            guardarPunteo();
            oro=100;
            experiencia=0;
            nivel=0;
            vida=asignarVida();
            mana=asignarMana();
            hipotion=0;
            potion=0;
            mpotion=0;
            monstruosDerrotados=0;
            pausa();
    }//fin si vida jugador
}//Termina opcion vida jugador

void opcionCurar(){
    // entra en accion cuando el jugador desea curarse en medio de una batalla
    int numeroAleatorio11;
    //variable local
    printf("\nTe consumira un punto de mana");
    numeroAleatorio11=((nivel+1)*5)+(15+rand()%(25+1-15));
    if(mana-1<0){
        printf("\nNo tienes suficiente Maná para curarte");  
        quienAtaca=2;
        // si no tiene mana no se cura, pero no pierde el turno
    }else{
        if(vida+numeroAleatorio11>asignarVida()){
        mana=mana-1;
        vida=asignarVida();
        printf("\nTe haz curado al máximo");
        printf("\nTu vida es:%i",vida);
        quienAtaca=2;
        // si la formula da como vida una mayor a la que puede almacenar se le da el maximo nada mas
        }//termina un if menor
        else{
            mana=mana-1;
            vida=vida+numeroAleatorio11;
            printf("\nTe haz curado");
            printf("\nAhora tu vida es: %i",vida);
            quienAtaca=2;
            //forma en la que cura al jugador, mediante una formula que da numeros aleatorios, cambia el turno despues
        }//termina un else menor
    }//termina un else mayor
    pausa();
}//fin Opcion_curar

void opcionItem(){
    //es llamada cuando el jugador quiere usar un item
    int item;
    //variable local
    printf("\n\nEscoge un item, pulsando el numero correspondiente");
    printf("\n1.-Potion,    tienes: %i",potion);
    printf("\n2.-Hi-Potion, tienes: %i",hipotion);
    printf("\n3.-M-Potion,  tienes: %i",mpotion);
    printf("\n4.- Regresar");
    printf("\nOpcion:");
    scanf("%i",&item);
    do{
        switch(item){
            case 1: if(potion-1<0){
                    // si no tiene potions no se cura, no pierde el turno
                        printf("\nNo tienes Potions para usar");
                    }//Termina el if
                    else{
                    // si tiene items se cura y pierde el turno
                        potion=potion-1;
                        if(vida+25>asignarVida()){
                            vida=asignarVida();
                            printf("\nTe haz curado al máximo");
                        }//termina un if menor
                        else{
                            // se cura si lo que da el item es menor o igual a su vida maxima
                            vida=vida+25;
                            printf("\nTe haz curado 25 de hp");
                            printf("\nAhora tu vida es: %i",vida);
                        }//Termina un else menor
                    }//Termina el else
                    item=4;
                    quienAtaca=2;break;
            case 2: if(hipotion-1<0){
                // si no tiene potions no se cura, no pierde el turno
                        printf("\nNo tienes Hi-Potions para usar");
                    }//Termina el if
                    else{
                        // si tiene mas vida de la que puede almacenar despues de usar el item, se ejecuta esto
                        hipotion=hipotion-1;
                        if(vida+75>asignarVida()){
                            vida=asignarVida();
                            printf("Te haz curado al máximo");
                        }//Termina un if menor
                        else{
                            // si su vida mas lo del item es menor o igual a su vida maxima, se ejecuta esto, pierde el turno
                            vida=vida+75;
                            printf("\nTe haz curado 75 de hp");
                            printf("\nAhora tu vida es: %i ",vida);
                        }//Termina un else menor
                    }//Termina el else
                    item=4;
                     quienAtaca=2;break;        
            case 3: if(mpotion-1<0){
                    // si no tiene potions no se cura, no pierde el turno
                       printf("\nNo tienes M-Potions para usar");
                    }//Termina el if
                    else{
                        mpotion=mpotion-1;
                        if(mana+10>asignarMana()){
                            // si su mana mas el item es mas de lo que puede almacenar se ejecuta esto, termina su turno
                            mana=asignarMana();
                            printf("\nTienes Maná máximo");
                        }//Termina un if menor
                        else{
                            // si su mana mas el item es menor a lo que puede almacenar se ejecuta esto, pierde el turno
                            mana=mana+10;
                            printf("\nTienes ahora 10 de mp extra");
                            printf("\nTu maná ahora es: %i",mana);
                        }//Termina un else menor
                    }//Termina el else
                    item=4;
                    quienAtaca=2;break;
        }//Termina el switch
    pausa();
    // se ejecuta ya que al usar un item tiene que salir del menu y le toca al monstruo
    }while(item>4 | item<1);
    if(item==4){
        printf("\nSaliste del Menu Item");
        // desenvoca el menu item
    }//Termina el if
}//Termina el metodo opcion_item

void tengoMiedo(){
    //tengo miedo es para salir de la batalla a cambio de un poco de oro
        int numeroAleatorio9;
        // variable local
	numeroAleatorio9=(nivel*2) + (5+rand()%((10+1)-5));
        if(oro-numeroAleatorio9<0){
            printf("\nNo tienes suficiente oro para huir");
            quienAtaca=2;
        }else{
            oro= oro-numeroAleatorio9;
            printf("\nTu oro se ha reducido, ahora tienes: %i",oro);
            clave=0;
            //forma en la que se le reduce el oro por salir de la batalla
        }//termina el else
        pausa();
        
}//termina el procedimiento de tengo miedo

void subirNivel(){
    int restaExperiencia;
    int nivelActual;
    nivelActual=nivel;
    restaExperiencia=experiencia%100;
    nivel=(experiencia-restaExperiencia)/100;
    if(nivel>nivelActual){
        //procedimiento para subir de nivel al jugador
        vida=asignarVida();
        mana=asignarMana();
        printf("\nFelicidades acabas de subir de nivel, esto te dara mas vida y mana");
        printf("\nTu Nivel ahora es: %i",nivel);
        printf("\nTu Vida ahora es: %i",vida);
        printf("\nTu Mana ahora es:%i",mana);
        
    }
}