#include "cell_b_t.hpp"

/* Constructor por defecto */
cell_b_t::cell_b_t (void):
cell_t(aliveB)
{

}


/* Destructor */
cell_b_t::~cell_b_t (void)
{

}


/* Actualiza el estado de la célula y devuelve un código referente a éste */
Status cell_b_t::next_status (void) const
{
    if ((get_neighbours() == 3) || (get_neighbours() == 4)){
        return aliveB;
    }
    else{
        return dead;
    }
}


/* Muestra la célula por la salida especificada */
ostream& cell_b_t::show_cell (ostream& os) const
{
    os << "B";
    return os;
}
