# Algoritmos y Estructuras de Datos Avanzadas

## Práctica 2: El Juego de la Vida Generalizado (modificación)

### Objetivo

El objetivo de la práctica es implementar tipos de datos definidos por el usuario y utilizarlos en un programa en lenguaje C++.

### Enunciado

En la versión estándar del juego las transiciones solo dependen del número de células vecinas vivas:

* [Regla de supervivencia]: Una célula viva con 2 ó 3 células vecinas vivas sigue viva, en otro caso muere.
* [Regla de nacimiento]: Una célula muerta con exactamente 3 células vecinas vivas “nace”.

Estas reglas de transición se denotan como “23/3” donde el primer número, o lista de números, indica lo que requiere una célula para que siga viva (regla de supervivencia); y el segundo número es el requisito para nacer (regla de nacimiento).

Se han desarrollado variantes del juego que utilizan distintas reglas de transición. A continuación se presentan algunas de las variantes estudiadas, aunque casi todas son demasiado caóticas o demasiado desoladas:

* /3            (estable)   casi todo es una chispa
* 5678/35678    (caótico)   diamantes, catástrofes
* 1357/1357     (crece)     todo son replicantes
* 1358/357      (caótico)   un reino equilibrado de amebas
* 23/3          (caótico)   "Juego de la Vida de Conway"
* 23/36         (caótico)   "HighLife" (tiene replicante)
* 235678/3678   (estable)   mancha de tinta que se seca rápidamente
* 245/368       (estable)   muerte, locomotoras y naves
* 34/34         (crece)     "Vida 34"
* 51/346        (estable)   "Larga vida" casi todo son osciladores

En esta segunda práctica se pide implementar una versión del juego de la vida en la que coexistan, de forma simultánea sobre el mismo tablero, distintos tipos de células con distintas reglas de supervivencia.

Mediante herencia de una clase base Celula, se definen los distintos tipos de células con las siguientes reglas de transición:

* Célula A: 23/3
* Célula B: 34/34
* Célula C: 51/346
* Célula D: 345/35

La regla de nacimiento, que sólo se aplica sobre las células muertas de la clase base, dará prioridad a la creación de células en el orden: A, B, C, D.

La regla de supervivencia, que es distinta para cada tipo de célula, será implementada mediante polimorfismo en cada tipo de célula.

Cada tipo de célula se visualiza utilizando un carácter distinto (A, B, C, D). Mientras que las casillas que se corresponden con células muertas si visualizan con el carácter blanco ' '.

### Compilación

El ejecutable generado se guarda en *bin/*

~~~
make
~~~

### Ejecución

#### Ejecución sin parámetros

El programa pedirá los datos iniciales al usuario por teclado.

~~~
make run
~~~

#### Ejecución con parámetros

El programa tomará los datos del fichero que se le pase como primer parámetro a la hora de la ejecución (en el fichero *Makefile* se ha establecido por defecto el fichero *input/default.txt*), en el que la primera línea indica el número de filas y columnas, la segúnda línea el número de células vivas que se introducirán, y de la tercera línea en adelante, las coordenadas de las células vivas iniciales (fila y columna respectivamente), seguidas de su correspondiente tipo.

~~~
make run-file
~~~

### A tener en cuenta

El programa realiza llamadas al sistema propias de los sistemas Windows o Unix (dependiendo de qué tipo de sistema se esté usando), por lo que podrían no funcionar en sistemas Mac.

### Información personal

**Autor:** [Kevin Estévez Expósito](https://alu0100821390.github.io/)

**ULL-ID:** alu0100821390
