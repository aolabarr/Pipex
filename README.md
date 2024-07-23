# Pipex

## Descripción

Este proyecto es parte del cursus 42 y se llama **pipex**. El objetivo principal es trabajar la creación de procesos y el uso de tuberías (pipes) en sistemas Unix/Linux.
El programa simula el comportamiento de las tuberías de la shell, permitiendo la comunicación entre procesos mediante la redirección de la salida estándar de un comando a la entrada estándar de otro.
El primer comando recibe información de un fichero y ejecuta la salida final en otro fichero. La versión mas simple comunica solo 2 comandos.
La otra más completa gestiona más de 2 comandos y por otro lado simula el funcionamiento de cuando la entrada se realiza por la entrada estandar escribiendo mediante el teclado. En ese caso la información escrita por pantalla se almacena en un fichero temporal `here_doc`.

## Reglas de Compilación y ejecución del programa
El programa tiene 4 reglas:
- `make`:          Genera la versión simple del programa.
- `make re`: Realiza la limpieza de los objetos y del ejecutable.
- `make bonus`:    Genera la version extendida del programa.
- `make fclean`: Realiza la limpieza de los objetos y del ejecutable.

Para recompilar la versión extendida ejecutar: `make re && make bonus`

La ejecución del programa se realiza de la siguiente manera. Se introducen como argumentos los nombres de los ficheros de entrada y de salida y los comandos del shell con sus respectivos flags opcionales:

```
./pipex infile "cmd1" "cmd2" outfile
```

Esta ejecución simula la siguiente operación en la terminal:
```
< infile cmd1 | cmd2 > outfile
```
Por ejemplo:
```
./pipex infile "ls -l" "wc -l" outfile
./pipex infile "grep h" "wc -l" outfile
```
La versión extendida que se compila con la regla *bonus* funciona de igual forma, pudiendo concatenar mas de 2 comandos. Por otro lado la sintaxis para ejecutar de forma que la información de entrada venga de la entrada estandar se realiza de la siguinte manera:

(_EOF se puede sustituir por cualquier palabra que haga de fin de lectura_)
```
./pipex here_doc EOF "cmd1" "cmd2" outfile
```
que simula la siguiente sentencia en la terminal:
```
cmd1 << EOF | cmd2 >> outfile
```
## Recomendaciones
 [manual de la función printf](https://man7.org/linux/man-pages/man3/printf.3.html).

