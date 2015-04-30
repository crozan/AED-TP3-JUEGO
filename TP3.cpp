// El programa pide usuario y realiza un cuestionario, con multiples opciones de menu y opcion para ingresar y salir del mismo constantemente.
// Autor: Cynthia Rozán
// Última modificación: 29/04/2015

#include <iostream>
#include <string>

using namespace std;

#define INDET "indeterminado"
// Declaro como constantes las respuestas a las preguntas
#define RESN1 "JIRAFA"
#define RESN2 "CARNIVOROS"
#define RESN3 "ANFIBIOS"
#define RESN4 "FOTOSINTESIS"
#define RESN5 "ADN"

#define RESG1 "MADRID"
#define RESG2 "PERU"
#define RESG3 "23"
#define RESG4 "ATLANTICO"
#define RESG5 "MEXICO"

#define RESH1 "1810"
#define RESH2 "PREHISTORIA"
#define RESH3 "ROMANO"
#define RESH4 "HIROSHIMA"
#define RESH5 "NAPOLEON"

#define RESL1 "VERONA"
#define RESL2 "1616"
#define RESL3 "VERNE"
#define RESL4 "1872"
#define RESL5 "HOMERO"

int main(){

    char opcion;
    string usuario (INDET);
    char salir;

    cout << "Bienvenido! Por favor ingrese sus respuestas con numeros o letras en mayuscula (sin acentos), segun corresponda." << endl;

    while (usuario.compare(INDET) == 0){

        cout << "Elija una opcion (1/2): " << endl;
        cout << "1. Introducir nombre de usuario." << endl << "2. Salir del programa." << endl;
        cin >> opcion;

        while (opcion != '1' and opcion != '2'){
            cout << "La opcion elegida es invalida. Ingrese una opcion valida (1/2): ";
            cin >> opcion;
        }

        if (opcion == '2'){
            cout << "Esta seguro que desea salir del programa?(S/N)" << endl;
            cin >> salir;
            if (salir == 'S'){
                cout << "Hasta luego!";
                return 0;
            }
        } else {
            cout << "Ingrese su nombre de usuario: ";
            cin >> usuario;
            cout << endl;
        }

// Debo declarar las variables fuera del loop siguiente para que no se inicialicen si no se cambia el usuario.

        string valoracion;
        int tematica1 = 1;
        int tematica2 = 2;
        int tematica3 = 3;
        int tematica4 = 4;
        string respuesta;
        int resultado;
        int ctotales;
        double porcentbien = 0;
// contadores:
        int pnaturaleza = 0;
        int pgeografia = 0;
        int phistoria = 0;
        int pliteratura = 0;
        int cnaturaleza = 0;
        int cgeografia = 0;
        int chistoria = 0;
        int cliteratura = 0;

        while (usuario.compare(INDET) != 0){

            resultado = pnaturaleza + pgeografia + phistoria + pliteratura;
            ctotales = cnaturaleza + cgeografia + chistoria + cliteratura;
            if (ctotales != 0){
                porcentbien = (resultado*100)/ctotales;
            }
            cout << usuario << " elija una opcion (1/2/3/4):" << endl;
            cout << "1. Elegir tematica de las preguntas." << endl << "2. Ver puntaje." << endl << "3. Cambiar usuario." << endl << "4. Salir del programa" << endl;
            cin >> opcion;

            while (opcion != '1' and opcion != '2' and opcion != '3' and opcion != '4'){
            cout << "La opcion elegida es invalida. Ingrese una opcion valida (1/2/3/4): ";
            cin >> opcion;
            }

            if (opcion == '4'){
                cout << "Esta seguro que desea salir del programa?(S/N)" << endl;
                cin >> salir;
                if (salir == 'S'){
                    cout << "Hasta luego!";
                return 0;
                }
            }

            if (opcion == '3'){
                if (porcentbien >= 0 and porcentbien <= 40){
                    valoracion = "A ponerse las pilas! ";
                } else {
                    if (porcentbien > 40 and porcentbien < 75){
                        valoracion = "Bien hecho!";
                    } else {
                        valoracion = "Excelente!";
                    }
                }
                cout << "Gracias " << usuario << " por participar! Su puntaje es " << resultado << " sobre " << ctotales << " respuestas contestadas. " << valoracion << endl;
                usuario = INDET;
            }

            if (opcion == '2'){
                if (ctotales == 0){
                    cout << "Aun no ha contestado ninguna pregunta." << endl;
                } else {
                    if (porcentbien >= 0 and porcentbien <= 40){
                        valoracion = "A ponerse las pilas! ";
                    } else {
                        if (porcentbien > 40 and porcentbien < 75){
                            valoracion = "Bien hecho! ";
                        } else {
                            valoracion = "Excelente!";
                        }
                    }
                }
                cout << "Participante " << usuario << " su puntaje es " << resultado << " sobre " << ctotales << " respuestas contestadas. " << valoracion << endl;
            }

//****************************************** PREGUNTAS**********************************************************************************************

            if (opcion == '1'){
                int tematica;
                char avanzar = 'S';

                cout << "Elija (1/2/3/4):" << endl << "1. Naturaleza" << endl << "2. Geografia" << endl << "3. Historia" << endl << "4. Literatura" << endl;
                cin >> tematica;

                while (tematica != 1 and tematica != 2 and tematica != 3 and tematica != 4){
                    cout << "La tematica elegida es invalida. Ingrese una tematica valida (1/2/3/4): ";
                    cin >> tematica;
                }
//*********************** NATURALEZA ***************************************************************************
                if (tematica == tematica1){
                    cout << usuario << " ha elegido Naturaleza." <<  endl;
                    if (cnaturaleza == 5){
                        cout << "Ya ha contestado todas las preguntas de esta tematica. Elija una nueva opcion." << endl;
                    }
                    opcion = 'S';
                    if (opcion == avanzar and cnaturaleza == 0){
                        cnaturaleza = cnaturaleza + 1;
                        cout << "1. Que animal tiene el cuello mas largo?" << endl;
                        cin >> respuesta;
                        if (respuesta.compare(RESN1) == 0){
                            pnaturaleza = pnaturaleza + 1;
                            cout << "Su respuesta es correcta!" << endl;
                        } else {
                            cout << "Su respuesta es incorrecta. La respuesta correcta es " << RESN1 << endl;
                        }
                        cout << "Desea avanzar a la siguiente pregunta? (S/N): " << endl;
                        cin >> opcion;
                    }
                    if (opcion == avanzar and cnaturaleza == 1){
                        cnaturaleza = cnaturaleza + 1;
                        cout << "2. Como se llaman los animales que comen carne?" << endl;
                        cin >> respuesta;
                        if (respuesta.compare(RESN2) == 0){
                            pnaturaleza = pnaturaleza + 1;
                            cout << "Su respuesta es correcta!" << endl;
                        } else {
                            cout << "Su respuesta es incorrecta. La respuesta correcta es " << RESN2 << endl;
                        }
                        cout << "Desea avanzar a la siguiente pregunta? (S/N): " << endl;
                        cin >> opcion;
                    }
                    if (opcion == avanzar and cnaturaleza == 2){
                        cnaturaleza = cnaturaleza + 1;
                        cout << "3. Como se llaman los animales que se mueven tanto en tierra como en agua?" << endl;
                        cin >> respuesta;
                        if (respuesta.compare(RESN3) == 0){
                            pnaturaleza = pnaturaleza + 1;
                            cout << "Su respuesta es correcta!" << endl;
                        } else {
                            cout << "Su respuesta es incorrecta. La respuesta correcta es " << RESN3 << endl;
                        }
                        cout << "Desea avanzar a la siguiente pregunta? (S/N): " << endl;
                        cin >> opcion;
                    }
                    if (opcion == avanzar and cnaturaleza == 3){
                        cnaturaleza = cnaturaleza + 1;
                        cout << "4. Como se llama el proceso por el cual las plantas consiguen energia?" << endl;
                        cin >> respuesta;
                        if (respuesta.compare(RESN4) == 0){
                            pnaturaleza = pnaturaleza + 1;
                            cout << "Su respuesta es correcta!" << endl;
                        } else {
                            cout << "Su respuesta es incorrecta. La respuesta correcta es " << RESN4 << endl;
                        }
                        cout << "Desea avanzar a la siguiente pregunta? (S/N): " << endl;
                        cin >> opcion;
                    }
                    if (opcion == avanzar and cnaturaleza == 4){
                        cnaturaleza = cnaturaleza + 1;
                        cout << "5. Como se llama la molecula donde se guarda el codigo genetico humano?" << endl;
                        cin >> respuesta;
                        if (respuesta.compare(RESN5) == 0){
                            pnaturaleza = pnaturaleza + 1;
                            cout << "Su respuesta es correcta!" << endl;
                        } else {
                            cout << "Su respuesta es incorrecta. La respuesta correcta es " << RESN5 << endl;
                        }
                        resultado = pnaturaleza + pgeografia + phistoria + pliteratura;
                        cout << "Ha contestado todas las preguntas para esta tematica. Su puntaje es: " << pnaturaleza << endl;
                        cout << "Su puntaje total hasta el momento es: " << resultado << endl;
                    }
				}
//*********************** GEOGRAFIA **********************************************************************************
                if (tematica == tematica2){
                    cout << usuario << " eligio Geografia" << endl;
                    if (cgeografia == 5){
                        cout << "Ya ha contestado todas las preguntas de esta tematica. Elija una nueva opcion." << endl;
                    }
                    opcion = 'S';
                    if (opcion == avanzar and cgeografia == 0){
                        cgeografia = cgeografia + 1;
                        cout << "1. Como se llama la capital de España?" << endl;
                        cin >> respuesta;
                        if (respuesta.compare(RESG1) == 0){
                            pgeografia = pgeografia + 1;
                            cout << "Su respuesta es correcta!" << endl;
                        } else {
                            cout << "Su respuesta es incorrecta. La respuesta correcta es " << RESG1 << endl;
                        }
                        cout << "Desea avanzar a la siguiente pregunta? (S/N): " << endl;
                        cin >> opcion;
                    }
                    if (opcion == avanzar and cgeografia == 1){
                        cgeografia = cgeografia + 1;
                        cout << "2. En que pais se encuentran las ruinas del Machu Picchu?" << endl;
                        cin >> respuesta;
                        if (respuesta.compare(RESG2) == 0){
                            pgeografia = pgeografia + 1;
                            cout << "Su respuesta es correcta!" << endl;
                        } else {
                            cout << "Su respuesta es incorrecta. La respuesta correcta es " << RESG2 << endl;
                        }
                        cout << "Desea avanzar a la siguiente pregunta? (S/N): " << endl;
                        cin >> opcion;
                    }
                    if (opcion == avanzar and cgeografia == 2){
                        cgeografia = cgeografia + 1;
                        cout << "3. Cuantas provincias comprenden la Republica Argentina?" << endl;
                        cin >> respuesta;
                        if (respuesta.compare(RESG3) == 0){
                            pgeografia = pgeografia + 1;
                            cout << "Su respuesta es correcta!" << endl;
                        } else {
                            cout << "Su respuesta es incorrecta. La respuesta correcta es " << RESG3 << endl;
                        }
                        cout << "Desea avanzar a la siguiente pregunta? (S/N): " << endl;
                        cin >> opcion;
                    }
                    if (opcion == avanzar and cgeografia == 3){
                        cgeografia = cgeografia + 1;
                        cout << "4. Cual es el segundo oceano mas grande del mundo?" << endl;
                        cin >> respuesta;
                        if (respuesta.compare(RESG4) == 0){
                            pgeografia = pgeografia + 1;
                            cout << "Su respuesta es correcta!" << endl;
                        } else {
                            cout << "Su respuesta es incorrecta. La respuesta correcta es " << RESG4 << endl;
                        }
                        cout << "Desea avanzar a la siguiente pregunta? (S/N): " << endl;
                        cin >> opcion;
                    }
                    if (opcion == avanzar and cgeografia == 4){
                        cgeografia = cgeografia + 1;
                        cout << "5. De que pais proviene la comida tradicional conocida como 'Tacos'? " << endl;
                        cin >> respuesta;
                        if (respuesta.compare(RESG5) == 0){
                            pgeografia = pgeografia + 1;
                            cout << "Su respuesta es correcta!" << endl;
                        } else {
                            cout << "Su respuesta es incorrecta. La respuesta correcta es " << RESG5 << endl;
                        }
                        resultado = pnaturaleza + pgeografia + phistoria + pliteratura;
                        cout << "Ha contestado todas las preguntas para esta tematica. Su puntaje es: " << pgeografia << endl;
                        cout << "Su puntaje total hasta el momento es: " << resultado << endl;
                    }
				}
//*********************** HISTORIA **********************************************************************************
                if (tematica == tematica3){
                    cout << usuario << " eligio Historia" << endl;
                    if (chistoria == 5){
                        cout << "Ya ha contestado todas las preguntas de esta tematica. Elija una nueva opcion." << endl;
                    }
                    opcion = 'S';
                    if (opcion == avanzar and chistoria == 0){
                        chistoria = chistoria + 1;
                        cout << "1. En que año fue la Revolucion de Mayo?" << endl;
                        cin >> respuesta;
                        if (respuesta.compare(RESH1) == 0){
                            phistoria = phistoria + 1;
                            cout << "Su respuesta es correcta!" << endl;
                        } else {
                            cout << "Su respuesta es incorrecta. La respuesta correcta es " << RESH1 << endl;
                        }
                        cout << "Desea avanzar a la siguiente pregunta? (S/N): " << endl;
                        cin >> opcion;
                    }
                    if (opcion == avanzar and chistoria == 1){
                        chistoria = chistoria + 1;
                        cout << "2. Que epoca finalizo con la invencion de la escritura?" << endl;
                        cin >> respuesta;
                        if (respuesta.compare(RESH2) == 0){
                            phistoria = phistoria + 1;
                            cout << "Su respuesta es correcta!" << endl;
                        } else {
                            cout << "Su respuesta es incorrecta. La respuesta correcta es " << RESH2 << endl;
                        }
                        cout << "Desea avanzar a la siguiente pregunta? (S/N): " << endl;
                        cin >> opcion;
                    }
                    if (opcion == avanzar and chistoria == 2){
                        chistoria = chistoria + 1;
                        cout << "3. Que importante imperio cayo definitivamente en el año 1453?" << endl;
                        cin >> respuesta;
                        if (respuesta.compare(RESH3) == 0){
                            phistoria = phistoria + 1;
                            cout << "Su respuesta es correcta!" << endl;
                        } else {
                            cout << "Su respuesta es incorrecta. La respuesta correcta es " << RESH3 << endl;
                        }
                        cout << "Desea avanzar a la siguiente pregunta? (S/N): " << endl;
                        cin >> opcion;
                    }
                    if (opcion == avanzar and chistoria == 3){
                        chistoria = chistoria + 1;
                        cout << "4. En que ciudad se solto la primera bomba atomica el 6 de agosto de 1945?" << endl;
                        cin >> respuesta;
                        if (respuesta.compare(RESH4) == 0){
                            phistoria = phistoria + 1;
                            cout << "Su respuesta es correcta!" << endl;
                        } else {
                            cout << "Su respuesta es incorrecta. La respuesta correcta es " << RESH4 << endl;
                        }
                        cout << "Desea avanzar a la siguiente pregunta? (S/N): " << endl;
                        cin >> opcion;
                    }
                    if (opcion == avanzar and chistoria == 4){
                        chistoria = chistoria + 1;
                        cout << "5. Cual es el nombre del conquistador europeo que fue derrotado en la batalla de Waterloo?" << endl;
                        cin >> respuesta;
                        if (respuesta.compare(RESH5) == 0){
                            phistoria = phistoria + 1;
                            cout << "Su respuesta es correcta!" << endl;
                        } else {
                            cout << "Su respuesta es incorrecta. La respuesta correcta es " << RESH5 << endl;
                        }
                        resultado = pnaturaleza + pgeografia + phistoria + pliteratura;
                        cout << "Ha contestado todas las preguntas para esta tematica. Su puntaje es: " << phistoria << endl;
                        cout << "Su puntaje total hasta el momento es: " << resultado << endl;
                    }
				}
//*********************** LITERATURA **********************************************************************************
                if (tematica == tematica4){
                    cout << usuario << " eligio Literatura" << endl;
                    if (cliteratura == 5){
                        cout << "Ya ha contestado todas las preguntas de esta tematica. Elija una nueva opcion." << endl;
                    }
                    opcion = 'S';
                    if (opcion == avanzar and cliteratura == 0){
                        cliteratura = cliteratura + 1;
                        cout << "1. En que ciudad de Italia transcurre la obra 'Romeo y Julieta'?" << endl;
                        cin >> respuesta;
                        if (respuesta.compare(RESL1) == 0){
                            pliteratura = pliteratura + 1;
                            cout << "Su respuesta es correcta!" << endl;
                        } else {
                            cout << "Su respuesta es incorrecta. La respuesta correcta es " << RESL1 << endl;
                        }
                        cout << "Desea avanzar a la siguiente pregunta? (S/N): " << endl;
                        cin >> opcion;
                    }
                    if (opcion == avanzar and cliteratura == 1){
                        cliteratura = cliteratura + 1;
                        cout << "2. En que año fallecieron los famosos escritores William Shakespeare y Miguel de Cervantes?" << endl;
                        cin >> respuesta;
                        if (respuesta.compare(RESL2) == 0){
                            pliteratura = pliteratura + 1;
                            cout << "Su respuesta es correcta!" << endl;
                        } else {
                            cout << "Su respuesta es incorrecta. La respuesta correcta es " << RESL2 << endl;
                        }
                        cout << "Desea avanzar a la siguiente pregunta? (S/N): " << endl;
                        cin >> opcion;
                    }
                    if (opcion == avanzar and cliteratura == 2){
                        cliteratura = cliteratura + 1;
                        cout << "3. Cual es el apellido del autor de '20000 leguas de viaje submarino'?" << endl;
                        cin >> respuesta;
                        if (respuesta.compare(RESL3) == 0){
                            pliteratura = pliteratura + 1;
                            cout << "Su respuesta es correcta!" << endl;
                        } else {
                            cout << "Su respuesta es incorrecta. La respuesta correcta es " << RESL3 << endl;
                        }
                        cout << "Desea avanzar a la siguiente pregunta? (S/N): " << endl;
                        cin >> opcion;
                    }
                    if (opcion == avanzar and cliteratura == 3){
                        cliteratura = cliteratura + 1;
                        cout << "4. En que año se publico por primera vez en Argentina el libro 'Martin Fierro'?" << endl;
                        cin >> respuesta;
                        if (respuesta.compare(RESL4) == 0){
                            pliteratura = pliteratura + 1;
                            cout << "Su respuesta es correcta!" << endl;
                        } else {
                            cout << "Su respuesta es incorrecta. La respuesta correcta es " << RESL4 << endl;
                        }
                        cout << "Desea avanzar a la siguiente pregunta? (S/N): " << endl;
                        cin >> opcion;
                    }
                    if (opcion == avanzar and cliteratura == 4){
                        cliteratura = cliteratura + 1;
                        cout << "5. Quien fue el autor de 'La Iliada' y 'La odisea'?" << endl;
                        cin >> respuesta;
                        if (respuesta.compare(RESL5) == 0){
                            pliteratura = pliteratura + 1;
                            cout << "Su respuesta es correcta!" << endl;
                        } else {
                            cout << "Su respuesta es incorrecta. La respuesta correcta es " << RESL5 << endl;
                        }
                        resultado = pnaturaleza + pgeografia + phistoria + pliteratura;
                        cout << "Ha contestado todas las preguntas para esta tematica. Su puntaje es: " << pliteratura << endl;
                        cout << "Su puntaje total hasta el momento es: " << resultado << endl;
                    }
				}
//******************* FIN PREGUNTAS************************************************************************************************
			}
		}
	}
}
