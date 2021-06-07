# Caso 7 - Análisis de Algoritmos

Kendall López Quesada

El programa trabaja por medio de una abstracción de un grafo, reduciendo la memoria que el programa pueda necesitar sin afectar gravemente a la eficiencia del algoritmo. Esta decisión se llega luego de analizar el problema y la creación de bosquejos sobre el funcionamiento del programa.

Se adjunta los bosquejos por si se necesita entender esta explicación, sin embargo este no pretende suplantar un diagrama de flujos o un diagrama de clases, este fue utilizado para crear las clases, no para explicar el trabajo.

# Carpetas

## Program

- MainProgram.cpp : Main del trabajo

## Logic

- PasswordMaker.h : Definición de la clase creadora de contraseñas
- PasswordMaker.cpp : Implementación de la clase creadora de contraseñas

	Posee el algoritmo probabilista que funciona con las clases de la carpeta "models"

## Models

- Password.h : Definición de la clase contraseña
- Password.cpp : Implementación de la clase contraseña

- Position.h : Definición de la clase que controla la posición
- Position.cpp : Implementación de la clase contraseña

	Se utiliza como abstracción de los movimientos entre los nodos del grafo facilitado

- ProbTable.h : Definición de la clase que maneja las probabilidades
- ProbTable.cpp : Implementación de la clase que maneja las probabilidades

	Es una abstracción de los arcos del grafo facilitado
	
## Utils

- IConst.h : Almacena todas las constantes que se utilizan en el programa, reduciendo los valores "alambrados" y facilitando los cambios de estos valores
