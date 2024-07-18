#!/bin/bash

# Ejemplo 1: Filtrar y ordenar contenido de un archivo
< infile.txt cat infile.txt | grep "log" | sort

./pipex infile.txt "cat infile.txt" "grep log" sort outfile.txt

# Ejemplo 2: Listar archivos, contar líneas y mostrar las primeras
< infile.txt ls -l | wc -l | head -n 10

./pipex infile.txt "ls -l" "wc -l" "head -n 10" outfile.txt

# Ejemplo 3: Buscar procesos, filtrar y contar
< infile.txt ps aux | grep "usuario" | wc -l

./pipex infile.txt "ps aux" "grep usuario" "wc -l" outfile.txt

# Ejemplo 4: Mostrar los archivos más grandes
< infile.txt du -h | sort -rh | head -n 5 > outfile.txt

./pipex infile.txt "du -h" "sort -rh" "head -n 5" outfile.txt

 
# Ejemplo 5: Contar palabras en archivos de texto
< infile.txt find . -name "*.txt" | xargs cat | wc -w > outfile.txt

./pipex infile.txt "find . -name "*.txt"" "xargs cat" "wc -w" outfile.txt

# Ejemplo 6: Analizar logs
# < infile.txt cat /var/log/syslog | grep "error" | tail -n 20 > outfile.txt
