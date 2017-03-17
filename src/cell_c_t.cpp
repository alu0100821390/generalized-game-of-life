#include "cell_c_t.hpp"

/* Constructor por defecto */
cell_c_t::cell_c_t (void):
cell_t(aliveC)
{

}


/* Destructor */
cell_c_t::~cell_c_t (void)
{

}


/* Actualiza el estado de la célula y devuelve un código referente a éste */
Status cell_c_t::next_status (void) const
{
    if ((get_neighbours() == 5) || (get_neighbours() == 1)){
        return aliveC;
    }
    else{
        return dead;
    }
}


/* Muestra la célula por la salida especificada */
ostream& cell_c_t::show_cell (ostream& os) const
{
    os << "C";
    return os;
}
