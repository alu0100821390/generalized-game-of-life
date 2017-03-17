#include "cell_t.hpp"

/* Constructor por defecto */
cell_t::cell_t (void):
status_(dead),
alive_neighbours_(0)
{

}


/* Constructor */
cell_t::cell_t (Status status):
status_(status),
alive_neighbours_(0)
{

}


/* Destructor */
cell_t::~cell_t (void)
{

}


/* Getter del atributo status_ */
Status cell_t::get_status (void) const
{
    return status_;
}


/* Getter del atributo alive_neighbours_ */
int cell_t::get_neighbours (void) const
{
    return alive_neighbours_;
}


/* Setter del atributo alive_neighbours */
void cell_t::set_alive_neighbours (int alive_neighbours)
{
    alive_neighbours_ = alive_neighbours;
}


/* Actualiza el estado de la célula y devuelve un código referente a éste */
Status cell_t::next_status (void) const
{
    if (alive_neighbours_ == 3){
        return aliveA;
    }
    else{
        if ((alive_neighbours_ == 3) || (alive_neighbours_ == 4)){
            return aliveB;
        }
        else{
            if ((alive_neighbours_ == 3) || (alive_neighbours_ == 4) || (alive_neighbours_ == 6)){
                return aliveC;
            }
            else{
                if ((alive_neighbours_ == 3) || (alive_neighbours_ == 5)){
                    return aliveD;
                }
                else{
                    return dead;
                }
            }
        }
    }
}


/* Muestra la célula por la salida especificada */
ostream& cell_t::show_cell (ostream& os) const
{
    os << " ";
    return os;
}
