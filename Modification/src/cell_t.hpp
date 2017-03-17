#pragma once

#include <iostream>

using namespace std;


enum Status { dead, aliveA, aliveB, aliveC, aliveD, edge };

class cell_t
{
private:
	Status status_;  /* Estado actual de la célula */
	int alive_neighbours_;  /* Número de células vecinas vivas */

public:
	cell_t (void);  /* Constructor por defecto */
	cell_t (Status status);  /* Constructor */
	virtual ~cell_t (void);  /* Destructor */

	Status get_status (void) const;  /* Getter del atributo status_ */
	int get_neighbours (void) const;  /* Getter del atributo alive_neighbours_ */
	void set_alive_neighbours (int alive_neighbours);  /* Setter del atributo alive_neighbours */

	// void count_neighbours (const board_t& board, int i, int j);  /* Calcula y guarda el número de células vecinas vivas */
	virtual Status next_status (void) const;  /* Actualiza el estado de la célula y devuelve un código referente a éste */
	virtual ostream& show_cell (ostream& os) const;  /* Muestra la célula por la salida especificada */
};
