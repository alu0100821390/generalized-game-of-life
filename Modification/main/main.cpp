#ifdef __unix__
#define LIMPIAR "clear"
#endif // __unix__

#ifdef __WIN32__
#define LIMPIAR "cls"
#endif // __WIN32__

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <ctime>

#include "../src/board_t.hpp"

using namespace std;

/* Función que comprueba que la opción introducida por teclado es correcta */
void opc_corr (int &opc){
	while (cin.fail()){
		cin.clear();
		cin.ignore(99, '\n');
		cout << "Enter a valid option: ";
		cin >> opc;
	}
}


/* Función que pide los datos del tablero por teclado */
void manual_input (board_t &game){
	int rows = 0;
	int cols = 0;
	int n_cells = -1;

	/* Se pide las dimensiones del tablero por teclado */
	cout << "\nEnter the board dimensions:" << endl;
	while ((rows*cols)<1){
		cout << "Number of rows: ";
		cin >> rows;
		opc_corr(rows);
		cout << "Number of columns: ";
		cin >> cols;
		opc_corr(cols);
		if ((rows*cols)<1){
			cout << "Insufficient board, there must be at least one cell." << endl;
			cout << "Enter the data again:" << endl;
		}
	}

	/* Se crea un tablero con las dimensiones especificadas */
	game.resize_board(rows, cols);

	/* Se pide el número de células vivas iniciales por teclado */
	cout << "\nEnter the number of alive cells the starting board will have: ";
	cin >> n_cells;
	opc_corr(n_cells);
	while ((n_cells<0) || (n_cells>(game.get_rows()*game.get_columns()))){
		if (n_cells<0){
			cout << "Insufficient amount!" << endl;
		}
		else{
			if (n_cells>(game.get_rows()*game.get_columns())){
				cout << "Insufficient board for too many cells!" << endl;
			}
		}
		cout << "Enter the alive cells amount again: ";
		cin >> n_cells;
		opc_corr(n_cells);
	}

	if (n_cells>0){  /* Si se va a introducir alguna célula viva... */
		int amount_a, amount_b, amount_c, amount_d;
		int m;
		int n;
		bool dead_cell;
		cout << "\nEnter the amount of alive cells of type A, B and C." << endl;
		cout << "(The amount of alive cells of type D will be the remaining amount)" << endl;
		cout << "\nAmount of type A: ";
		cin >> amount_a;
		opc_corr(amount_a);
		while ((amount_a<0) || (amount_a>n_cells)){
			cout << "Amount out of range.\nEnter a valid amount: ";
			cin >> amount_a;
			opc_corr(amount_a);
		}
		cout << "\nEnter the coordinates of the " << amount_a << " cells of type A:";
		for (int i=1; i<=amount_a; i++){
			dead_cell = true;
			while (dead_cell){
				cout << "\nCell A_" << i << ":" << endl;
				cout << "Row: ";
				cin >> m;
				opc_corr(m);
				while ((m<1) || (m>game.get_rows())){
					cout << "Row out of range.\nEnter a valid row number: ";
					cin >> m;
					opc_corr(m);
				}
				cout << "Column: ";
				cin >> n;
				opc_corr(n);
				while ((n<1) || (n>game.get_columns())){
					cout << "Column out of range.\nEnter a valid column number: ";
					cin >> n;
					opc_corr(n);
				}

				if (!(game.get_cell_status(m, n)==dead)){
					cout << "Cell not dead!" << endl;
					cout << "Enter other coordinates:" << endl;
				}
				else{
					game.reborn_a(m, n);
					dead_cell = false;
				}
			}
		}

		if ((n_cells-amount_a)>0){
			cout << "\nAmount of type B: ";
			cin >> amount_b;
			opc_corr(amount_b);
			while ((amount_b<0) || ((amount_a+amount_b)>n_cells)){
				cout << "Amount out of range.\nEnter a valid amount: ";
				cin >> amount_b;
				opc_corr(amount_b);
			}
			cout << "\nEnter the coordinates of the " << amount_b << " cells of type B:";
			for (int i=1; i<=amount_b; i++){
				dead_cell = true;
				while (dead_cell){
					cout << "\nCell B_" << i << ":" << endl;
					cout << "Row: ";
					cin >> m;
					opc_corr(m);
					while ((m<1) || (m>game.get_rows())){
						cout << "Row out of range.\nEnter a valid row number: ";
						cin >> m;
						opc_corr(m);
					}
					cout << "Column: ";
					cin >> n;
					opc_corr(n);
					while ((n<1) || (n>game.get_columns())){
						cout << "Column out of range.\nEnter a valid column number: ";
						cin >> n;
						opc_corr(n);
					}

					if (!(game.get_cell_status(m, n)==dead)){
						cout << "Cell not dead!" << endl;
						cout << "Enter other coordinates:" << endl;
					}
					else{
						game.reborn_b(m, n);
						dead_cell = false;
					}
				}
			}

			if ((n_cells-(amount_a+amount_b))>0){
				cout << "\nAmount of type C: ";
				cin >> amount_c;
				opc_corr(amount_c);
				while ((amount_c<0) || ((amount_a+amount_b+amount_c)>n_cells)){
					cout << "Amount out of range.\nEnter a valid amount: ";
					cin >> amount_c;
					opc_corr(amount_c);
				}
				if (amount_c>0){
					cout << "\nEnter the coordinates of the " << amount_c << " cells of type C:";
					for (int i=1; i<=amount_c; i++){
						dead_cell = true;
						while (dead_cell){
							cout << "\nCell C_" << i << ":" << endl;
							cout << "Row: ";
							cin >> m;
							opc_corr(m);
							while ((m<1) || (m>game.get_rows())){
								cout << "Row out of range.\nEnter a valid row number: ";
								cin >> m;
								opc_corr(m);
							}
							cout << "Column: ";
							cin >> n;
							opc_corr(n);
							while ((n<1) || (n>game.get_columns())){
								cout << "Column out of range.\nEnter a valid column number: ";
								cin >> n;
								opc_corr(n);
							}

							if (!(game.get_cell_status(m, n)==dead)){
								cout << "Cell not dead!" << endl;
								cout << "Enter other coordinates:" << endl;
							}
							else{
								game.reborn_c(m, n);
								dead_cell = false;
							}
						}
					}
				}
			}

			amount_d = n_cells - (amount_a + amount_b + amount_c);
			if (amount_d>0){
				cout << "\nAmount of type D: " << amount_d << endl;
				cout << "\nEnter the coordinates of the " << amount_d << " cells of type D:";
				for (int i=1; i<=amount_d; i++){
					dead_cell = true;
					while (dead_cell){
						cout << "\nCell D_" << i << ":" << endl;
						cout << "Row: ";
						cin >> m;
						opc_corr(m);
						while ((m<1) || (m>game.get_rows())){
							cout << "Row out of range.\nEnter a valid row number: ";
							cin >> m;
							opc_corr(m);
						}
						cout << "Column: ";
						cin >> n;
						opc_corr(n);
						while ((n<1) || (n>game.get_columns())){
							cout << "Column out of range.\nEnter a valid column number: ";
							cin >> n;
							opc_corr(n);
						}

						if (!(game.get_cell_status(m, n)==dead)){
							cout << "Cell not dead!" << endl;
							cout << "Enter other coordinates:" << endl;
						}
						else{
							game.reborn_d(m, n);
							dead_cell = false;
						}
					}
				}
			}
		}
	}
}


/* Genera unos valores aleatorios para las variables especificadas */
void random_coords (board_t &game, int &a, int &b){
	a = rand() % (game.get_rows()) + 1;
	b = rand() % (game.get_columns()) + 1;

	while (game.alive_cell(a, b)){
		a = rand() % (game.get_rows()) + 1;
		b = rand() % (game.get_columns()) + 1;
	}
}


/* Genera un estado de célula viva aleatorio */
void random_cell (Status &cell_status){
	int aux = rand();
	aux = aux % 4;
	switch (aux){
		case 0:
			cell_status = aliveA;
			break;
		case 1:
			cell_status = aliveB;
			break;
		case 2:
			cell_status = aliveC;
			break;
		case 3:
			cell_status = aliveD;
			break;
	}
}


/* Función que pide los datos del tablero por teclado y genera las células vivas iniciales de forma aleatoria */
void random_input (board_t &game){
	int row = 0;
	int col = 0;
	int n_cells = -1;

	/* Se pide las dimensiones del tablero por teclado */
	cout << "\nEnter the board dimensions:" << endl;
	while ((row*col)<1){
		cout << "Number of rows: ";
		cin >> row;
		opc_corr(row);
		cout << "Number of columns: ";
		cin >> col;
		opc_corr(col);
		if ((row*col)<1){
			cout << "Insufficient board, there must be at least one cell." << endl;
			cout << "Enter the data again:" << endl;
		}
	}

	/* Se crea un tablero con las dimensiones especificadas */
	game.resize_board(row, col);

	/* Se pide el número de células vivas iniciales por teclado */
	cout << "\nEnter the number of alive cells the starting board will have: ";
	cin >> n_cells;
	opc_corr(n_cells);
	while ((n_cells<0) || (n_cells>(row*col))){
		if (n_cells<0)
			cout << "Insufficient amount!" << endl;
		else
			if (n_cells>(row*col))
				cout << "Insufficient board for too many cells!" << endl;
		cout << "Enter the alive cells amount again: ";
		cin >> n_cells;
		opc_corr(n_cells);
	}

	char option='x';
	while (option=='x'){
		cout << "Want to enter a number of alive cells per type? ([Y]es/[N]o): ";
		cin >> option;

		int a = -1;
		int b = -1;
		switch (option){
			case 'y':
			case 'Y':
				int amount_a, amount_b, amount_c, amount_d;

				cout << "\nEnter the amount of alive cells of type A, B and C." << endl;
				cout << "(The amount of alive cells of type D will be the remaining amount)" << endl;
				cout << "\nAmount of type A: ";
				cin >> amount_a;
				opc_corr(amount_a);
				while ((amount_a<0) || (amount_a>n_cells)){
					cout << "Amount out of range.\nEnter a valid amount: ";
					cin >> amount_a;
					opc_corr(amount_a);
				}
				for (int i=0; i<amount_a; i++){
					random_coords(game, a, b);
					game.reborn_a(a, b);
				}

				if ((n_cells-amount_a)>0){
					cout << "\nAmount of type B: ";
					cin >> amount_b;
					opc_corr(amount_b);
					while ((amount_b<0) || ((amount_a+amount_b)>n_cells)){
						cout << "Amount out of range.\nEnter a valid amount: ";
						cin >> amount_b;
						opc_corr(amount_b);
					}
					for (int i=0; i<amount_b; i++){
						random_coords(game, a, b);
						game.reborn_b(a, b);
					}
					if (n_cells-(amount_a+amount_b)>0){
						cout << "\nAmount of type C: " << amount_c << endl;
						for (int i=0; i<amount_c; i++){
							random_coords(game, a, b);
							game.reborn_c(a, b);
						}
					}

					amount_d = n_cells - (amount_a + amount_b + amount_c);
					if (amount_d>0){
						cout << "\nAmount of type D: " << amount_d << endl;
						for (int i=0; i<amount_d; i++){
							random_coords(game, a, b);
							game.reborn_d(a, b);
						}
					}
				}
				break;
			case 'n':
			case 'N':
				/* Se revive las células de forma aleatoria */
				Status cell_status;
				for (int i=0; i<n_cells; i++){
					random_coords(game, a, b);
					random_cell(cell_status);
					switch (cell_status){
						case aliveA:
							game.reborn_a(a, b);
							break;
						case aliveB:
							game.reborn_b(a, b);
							break;
						case aliveC:
							game.reborn_c(a, b);
							break;
						case aliveD:
							game.reborn_d(a, b);
							break;
					}
				}
				break;
			default:
				cout << "Incorrect option!\n" << endl;
				option = 'x';
		}
	}
}


int main (int argc, char *argv[])
{
	srand(time(NULL));

	board_t game;  /* Se declara el tablero del juego */

	system(LIMPIAR);
	cout << "Wellcome to The Game of Life.\n" << endl;

	if (argc>1){  /* Si se ejecuta el programa con parámetros, se comprueba si el primero es un fichero */
		ifstream fi;

		fi.open(argv[1]);  /* Se trata de abrir el fichero */

		if (!fi){  /* Si ocurre un error al intentar abrir el fichero... */
			cerr << "Error opening the file " << argv[1] << ".\n" << endl;

			char option='x';
			while (option=='x'){
				cout << "Want to enter the data [m]anually or [r]andomly? (M/R): ";
				cin >> option;

				switch (option){
					case 'm':
					case 'M':
						manual_input(game); /* Se pide los datos por teclado */
						break;
					case 'r':
					case 'R':
						random_input(game);
						break;
					default:
						cout << "Incorrect option!\n" << endl;
						option = 'x';
				}
			}
		}
		else{  /* Si se abre el fichero correctamente... */
			int row;
			int col;
			int n_cells;
			int m;
			int n;
			char status;

			/* Se leen los datos del fichero abierto */
			fi >> row;
			fi >> col;

			game.resize_board(row, col);  /* Se redimensiona el tablero */

			fi >> n_cells;

			for (int i=0; i<n_cells; i++){
				fi >> m;
				fi >> n;
				fi >> status;
				switch (status){
					case 'a':
					case 'A':
						game.reborn_a(m, n);
						break;
					case 'b':
					case 'B':
						game.reborn_b(m, n);
						break;
					case 'c':
					case 'C':
						game.reborn_c(m, n);
						break;
					case 'd':
					case 'D':
						game.reborn_d(m, n);
						break;
					default:
						cerr << "Error in file. Aborting..." << endl;
						exit(1);
				}
			}
			fi.close();  /* Se cierra el fichero */
		}
	}
	else{  /* Si no se ejecuta el programa con parámetros, se pide los datos por teclado */
		char option='x';
		while (option=='x'){
			cout << "Want to enter the data [m]anually or [r]andomly? (M/R): ";
			cin >> option;

			switch (option){
				case 'm':
				case 'M':
					manual_input(game); /* Se pide los datos por teclado */
					break;
				case 'r':
				case 'R':
					random_input(game);
					break;
				default:
					cout << "Incorrect option!\n" << endl;
					option = 'x';
			}
		}
	}

	game.write(cout);  /* Se muestra el tablero inicial */

	game.game_of_life();  /* Se ejecuta El Juego de la Vida */

	return 0;
}
