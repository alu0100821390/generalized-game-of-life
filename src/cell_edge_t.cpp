#include "cell_edge_t.hpp"

/* Constructor por defecto */
cell_edge_t::cell_edge_t (void):
cell_t(edge)
{
    
}


/* Destructor */
cell_edge_t::~cell_edge_t (void)
{

}


/* Muestra la célula por la salida especificada */
ostream& cell_edge_t::show_cell (ostream& os) const
{
    os << "X";
    return os;
}
