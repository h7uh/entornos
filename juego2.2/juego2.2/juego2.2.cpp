// juego2.2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "Character.h"
#include <iostream>
using namespace std;

void battle(Character& player, Character& enemy) {
    while (player.isAlive() && enemy.isAlive()) {
        player.attack(enemy);
        if (!enemy.isAlive()) {
            cout << enemy.getName() << " ha sido derrotado!" << endl;
            break;
        }
        enemy.attack(player);
        if (!player.isAlive()) {
            cout << player.getName() << " ha sido derrotado!" << endl;
            break;
        }
    }
}

int main() {
    string name;
    cout << "Ingrese el nombre del heroe: ";
    cin >> name;
    Player hero(name, 100, 20);
    Enemy enemy("Goblin", 50, 10);
    Boss finalBoss("Dragon", 150, 25);

    cout << "\n--- Batalla contra el enemigo ---\n";
    battle(hero, enemy);

    if (hero.isAlive()) {
        cout << "\n--- Batalla final contra el Boss ---\n";
        battle(hero, finalBoss);
    }
    return 0;
}


// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
