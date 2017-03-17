#include "cell_d_t.hpp"

/* Constructor por defecto */
cell_d_t::cell_d_t (void):
cell_t(aliveD)
{

}


/* Destructor */
cell_d_t::~cell_d_t (void)
{

}


/* Actualiza el estado de la célula y devuelve un código referente a éste */
Status cell_d_t::next_status (void) const
{
    if ((get_neighbours() == 3) || (get_neighbours() == 4) || (get_neighbours() == 5)){
        return aliveD;
    }
    else{
        return dead;
    }
}


/* Muestra la célula por la salida especificada */
ostream& cell_d_t::show_cell (ostream& os) const
{
    os << "D";
    return os;
}
