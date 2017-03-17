#pragma once

#include <iostream>

#include "cell_t.hpp"

using namespace std;


class cell_d_t: public cell_t
{
public:
    cell_d_t (void);  /* Constructor por defecto */
    ~cell_d_t (void);  /* Destructor */

    Status next_status (void) const;  /* Actualiza el estado de la célula y devuelve un código referente a éste */
	ostream& show_cell (ostream& os) const;  /* Muestra la célula por la salida especificada */
};
