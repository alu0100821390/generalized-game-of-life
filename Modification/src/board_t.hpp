#pragma once

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

#include "cell_t.hpp"

using namespace std;


class board_t
{
private:
	int rows_;  /* Número de filas del tablero */
	int columns_;  /* Número de columnas del tablero */
	vector<vector<cell_t*> > mesh_;  /* Vector de vectores que simula una matriz que simula el tablero */
	int turn_;  /* Turno actual del juego */
	int population_;  /* Población actual presente en el tablero */
	bool end_;  /* Establece si el juego ha terminado */

public:
	board_t (void);  /* Constructor por defecto */
	board_t (int rows, int columns);  /* Constructor parametrizado */
	~board_t (void);  /* Destructor */

	int get_rows (void) const;  /* Getter del atributo rows_ */
	int get_columns (void) const;  /* Getter del atributo columns */
	Status get_cell_status (int i, int j) const;  /* Getter del atributo status_ de una célula */
	int get_cell_neighbours (int i, int j) const;  /* Getter del atributo alive_neighbours_ de una célula */
	int get_turn (void) const;  /* Getter del atributo turn_ */
	int get_population (void) const;  /* Getter del atributo population_ */
	bool get_end (void) const;  /* Getter del atributo end_ */

	void reborn_a (int i, int j);  /* Revive una célula en tipo A */
	void reborn_b (int i, int j);  /* Revive una célula en tipo B */
	void reborn_c (int i, int j);  /* Revive una célula en tipo C */
	void reborn_d (int i, int j);  /* Revive una célula en tipo D */

	void resize_board (int rows, int columns);  /* Redimensiona el tablero */

	bool alive_cell (int i, int j) const;  /* Comprueba si la célula especificada está viva */

	void game_of_life (void);  /* Ejecuta El Juego de la Vida sobre el tablero */

	ostream& write (ostream& os) const;  /* Imprime la tabla por la salida especificada */


private:
	void set_turn (int turn);  /* Setter del atributo turn_ */
	void set_end (bool end);  /* Setter del atributo end_ */

	void calculate_population (void);  /* Recalcula la población del tablero */

	void update_cell_neighbours (int i, int j);  /* Actualiza los vecinos vivos de una célula */

	bool in_range (int i, int j) const;  /* Comprueba que las coordenadas dadas pertenecen al tablero */

	void next_turn (void);  /* Actualiza el tablero y pasa un turno */

};
