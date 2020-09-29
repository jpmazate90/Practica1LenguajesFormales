

#ifndef TIENDA_H
#define TIENDA_H

#ifdef __cplusplus
extern "C" {
#endif
// headers de el resto de menus
void tienda();
void zzZZ();
void status();
int asignarMana();
int asignarVida();
void pausa();
// headers de la batalla a la carga
void aLaCarga();
void opcionesDePelea();
void iniciarDatosDeJuego();
void opcionAtacar();
void opcionVidaMonstruo();
void opcionVidaJugador();
void opcionCurar();
void opcionItem();
void tengoMiedo();
void subirNivel();

/// headers de archivos
void mostrarPunteos();
void guardarPunteo();
void crearArchivo();
void copiarDatosArchivo();
void vaciar(char temporal[]);
void copiar(char temporal[], int i);
void leerDatosArchivo();
void mostrarDatosArchivo();
void escribirTexto();
int cantidadRegistros();
void escribirRegistroActual(FILE *archivo1);


#ifdef __cplusplus
}
#endif

#endif /* TIENDA_H */

