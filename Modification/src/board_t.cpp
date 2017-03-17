#ifdef __unix__
#define LIMPIAR "clear"
#endif // __unix__

#ifdef __WIN32__
#define LIMPIAR "cls"
#endif // __WIN32__

#include "board_t.hpp"
#include "cell_a_t.hpp"
#include "cell_b_t.hpp"
#include "cell_c_t.hpp"
#include "cell_d_t.hpp"
#include "cell_edge_t.hpp"


/***** MÉTODOS PÚBLICOS *****/

/* Constructor por defecto */
board_t::board_t (void):
rows_(2),
columns_(2),
turn_(0),
population_(0),
end_(false)
{
    mesh_.clear();
    mesh_.resize(rows_, vector<cell_t*>(columns_));  /* Se redimensiona la malla a 2x2 (todo bordes) */

    for (int i=0; i<rows_; i++){
        for (int j=0; j<columns_; j++){
            if (mesh_[i][j]!=NULL){
                delete mesh_[i][j];
                mesh_[i][j] = NULL;
            }
            mesh_[i][j] = new cell_edge_t();
        }
    }
}


/* Constructor parametrizado */
board_t::board_t (int rows, int columns):
rows_(rows),
columns_(columns),
turn_(0),
population_(0),
end_(false)
{
	mesh_.clear();
    /* Se redimensiona a 2 filas y 2 columnas más para añadir las células del borde del tablero */
    mesh_.resize(rows_+2, vector<cell_t*>(columns_+2));  /* Se redimensiona la malla */
    /* Se crean las células del borde del tablero */
    for (int i=0; i<rows_+2; i++){
        if (mesh_[i][0]!=NULL){
            delete mesh_[i][0];
            mesh_[i][0] = NULL;
        }
        mesh_[i][0] =  new cell_edge_t();

        if (mesh_[i][columns_+1]!=NULL){
            delete mesh_[i][columns_+1];
            mesh_[i][columns_+1] = NULL;
        }
        mesh_[i][columns_+1] = new cell_edge_t();
    }

    for (int i=1; i<=columns_; i++){
        if (mesh_[0][i]!=NULL){
            delete mesh_[0][i];
            mesh_[0][i] = NULL;
        }
        mesh_[0][i] = new cell_edge_t();

        if (mesh_[rows_+1][i]!=NULL){
            delete mesh_[rows_+1][i];
            mesh_[rows_+1][i] = NULL;
        }
        mesh_[rows_+1][i] = new cell_edge_t();
    }
}


/* Destructor */
board_t::~board_t (void)
{
    mesh_.clear();
}


/* Getter del atributo rows_ */
int board_t::get_rows (void) const
{
    return rows_;
}


/* Getter del atributo columns_ */
int board_t::get_columns (void) const
{
    return columns_;
}


/* Getter del atributo status_ de una célula */
Status board_t::get_cell_status (int i, int j) const
{
    if (in_range(i, j)){
        return mesh_[i][j]->get_status();
    }
}


/* Getter del atributo alive_neighbours_ de una célula */
int board_t::get_cell_neighbours (int i, int j) const
{
    if (in_range(i, j)){
        return mesh_[i][j]->get_neighbours();
    }
}


/* Getter del atributo turn_ */
int board_t::get_turn (void) const
{
    return turn_;
}


/* Getter del atributo population_ */
int board_t::get_population (void) const
{
    return population_;
}


/* Getter del atributo end_ */
bool board_t::get_end (void) const
{
    return end_;
}


/* Revive una célula en tipo A */
void board_t::reborn_a (int i, int j){
    if (mesh_[i][j]!=NULL){
        delete mesh_[i][j];
        mesh_[i][j] = NULL;
    }
    mesh_[i][j] = new cell_a_t();
}


/* Revive una célula en tipo B */
void board_t::reborn_b (int i, int j){
    if (mesh_[i][j]!=NULL){
        delete mesh_[i][j];
        mesh_[i][j] = NULL;
    }
    mesh_[i][j] = new cell_b_t();
}


/* Revive una célula en tipo C */
void board_t::reborn_c (int i, int j){
    if (mesh_[i][j]!=NULL){
        delete mesh_[i][j];
        mesh_[i][j] = NULL;
    }
    mesh_[i][j] = new cell_c_t();
}


/* Revive una célula en tipo D */
void board_t::reborn_d (int i, int j){
    if (mesh_[i][j]!=NULL){
        delete mesh_[i][j];
        mesh_[i][j] = NULL;
    }
    mesh_[i][j] = new cell_d_t();
}


/* Redimensiona el tablero */
void board_t::resize_board(int rows, int columns)
{
    mesh_.clear();

    rows_ = rows;
    columns_ = columns;

    /* Se redimensiona a 2 filas y 2 columnas más para añadir las células del borde del tablero */
    mesh_.resize(rows_+2, vector<cell_t*>(columns_+2));  /* Se redimensiona la malla */
    /* Se crean las células del borde del tablero */
    for (int i=0; i<rows_+2; i++){
        if (mesh_[i][0]!=NULL){
            delete mesh_[i][0];
            mesh_[i][0] = NULL;
        }
        mesh_[i][0] =  new cell_edge_t();

        if (mesh_[i][columns_+1]!=NULL){
            delete mesh_[i][columns_+1];
            mesh_[i][columns_+1] = NULL;
        }
        mesh_[i][columns_+1] = new cell_edge_t();
    }

    for (int i=1; i<=columns_; i++){
        if (mesh_[0][i]!=NULL){
            delete mesh_[0][i];
            mesh_[0][i] = NULL;
        }
        mesh_[0][i] = new cell_edge_t();

        if (mesh_[rows_+1][i]!=NULL){
            delete mesh_[rows_+1][i];
            mesh_[rows_+1][i] = NULL;
        }
        mesh_[rows_+1][i] = new cell_edge_t();
    }

    for (int i=1; i<=rows_; i++){
        for (int j=1; j<=columns_; j++){
            if (mesh_[i][j]!=NULL){
                delete mesh_[i][j];
                mesh_[i][j] = NULL;
            }
            mesh_[i][j] = new cell_t();
        }
    }
}


/* Comprueba si la célula especificada está viva */
bool board_t::alive_cell (int i, int j) const
{
    if (in_range(i, j)){
        if ((get_cell_status(i, j) == aliveA) || (get_cell_status(i, j) == aliveB) || (get_cell_status(i, j) == aliveC) || (get_cell_status(i, j) == aliveD)){
            return true;
        }
    }
    return false;
}


/* Ejecuta El Juego de la Vida sobre el tablero */
void board_t::game_of_life (void)
{
    system(LIMPIAR);
    calculate_population();
    while (!end_){  /* Mientras el juego no haya terminado... */
        write(cout);
        system(LIMPIAR);
        next_turn();  /* Se actualiza el estado de las células del tablero y se avanza un turno */
        calculate_population();
    }

	cout << "GAME OVER x_x\n" << endl;
}


/***** MÉTODOS PRIVADOS *****/

/* Setter del atributo turn_ */
void board_t::set_turn (int turn)
{
    turn_ = turn;
}


/* Setter del atributo end_ */
void board_t::set_end (bool end)
{
    end_ = end;
}


/* Recalcula la población del tablero */
void board_t::calculate_population (void)
{
    population_ = 0;

    for (int i=1; i<=rows_; i++){
        for (int j=1; j<=columns_; j++){
            if ((get_cell_status(i, j) == aliveA) || (get_cell_status(i, j) == aliveB) || (get_cell_status(i, j) == aliveC) || (get_cell_status(i, j) == aliveD)){
                population_++;
            }
        }
    }
}


/* Actualiza los vecinos vivos de una célula */
void board_t::update_cell_neighbours (int i, int j)
{
    int alive_neighbours = 0;
    for (int a=i-1; a<=i+1; a++){
        for (int b=j-1; b<=j+1; b++){
            if (!((a==i) && (b==j))){
                if((get_cell_status(a, b) == aliveA) || (get_cell_status(a, b) == aliveB) || (get_cell_status(a, b) == aliveC) || (get_cell_status(i, j) == aliveD)){
                    alive_neighbours ++;
                }
            }
        }
    }
    mesh_[i][j]->set_alive_neighbours(alive_neighbours);
}


/* Comprueba que las coordenadas dadas pertenecen al tablero */
bool board_t::in_range (int i, int j) const
{
    if ((i>=1) && (i<=rows_) && (j>=1) && (j<=columns_)){
        return true;
    }

	return false;
}


/* Actualiza el tablero y pasa un turno */
void board_t::next_turn (void)
{
    set_end(true);
    for (int i=1; i<=rows_; i++){
        for (int j=1; j<=columns_; j++){
            update_cell_neighbours(i, j);
        }
    }

    Status next_status;
    for (int i=1; i<=rows_; i++){
        for (int j=1; j<=columns_; j++){
            next_status = mesh_[i][j]->next_status();
            if (next_status!=dead){
                set_end(false);
            }
            if (mesh_[i][j]->get_status()!=next_status){
                switch (next_status){
                    case aliveA:
                        delete mesh_[i][j];
                        mesh_[i][j] = new cell_a_t();
                        set_end(false);
                        break;
                    case aliveB:
                        delete mesh_[i][j];
                        mesh_[i][j] = new cell_b_t();
                        set_end(false);
                        break;
                    case aliveC:
                        delete mesh_[i][j];
                        mesh_[i][j] = new cell_c_t();
                        set_end(false);
                        break;
                    case aliveD:
                        delete mesh_[i][j];
                        mesh_[i][j] = new cell_d_t();
                        set_end(false);
                        break;
                    case dead:
                        delete mesh_[i][j];
                        mesh_[i][j] = new cell_t();
                        set_end(false);
                        break;
                    default:
                        cerr << "Ha ocurrido un error inesperado. Abortando..." << endl;
                        exit(1);
                }
            }
        }
    }
    set_turn(get_turn()+1);
}


/* Imprime la tabla por la salida especificada */
ostream& board_t::write (ostream& os) const
{
	if (turn_==0){
		os << "Initial board." << endl;
	}
	else{
		os << "Turn: " << turn_ << endl;
	}

    os << "Population: " << population_ << endl;

	os << " ";
    for (int i=0; i<columns_+2; i++){
        os << "-";
    }
    os << endl;

    for (int i=0; i<rows_+2; i++){
        os << "|";
        for (int j=0; j<columns_+2; j++){
            mesh_[i][j]->show_cell(os);
        }
        os << "|" << endl;
    }

	os << " ";
    for (int i=0; i<columns_+2; i++){
        os << "-";
    }
    os << endl;

	os << "Press 'Enter' for the next turn." << endl;

    getchar();

    return os;
}
