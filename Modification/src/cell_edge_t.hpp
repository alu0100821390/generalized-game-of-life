#pragma once

#include <iostream>

#include "cell_t.hpp"

using namespace std;


class cell_edge_t: public cell_t
{
public:
    cell_edge_t (void);  /* Constructor por defecto */
    ~cell_edge_t (void);  /* Destructor */

	ostream& show_cell (ostream& os) const;  /* Muestra la célula por la salida especificada */
};
