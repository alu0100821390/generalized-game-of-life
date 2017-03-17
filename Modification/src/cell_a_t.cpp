#include "cell_a_t.hpp"

/* Constructor por defecto */
cell_a_t::cell_a_t (void):
cell_t(aliveA)
{

}


/* Destructor */
cell_a_t::~cell_a_t (void)
{

}


/* Actualiza el estado de la célula y devuelve un código referente a éste */
Status cell_a_t::next_status (void) const
{
    if ((get_neighbours() == 2) || (get_neighbours() == 3)){
        return aliveA;
    }
    else{
        return dead;
    }
}


/* Muestra la célula por la salida especificada */
ostream& cell_a_t::show_cell (ostream& os) const
{
    os << "A";
    return os;
}
