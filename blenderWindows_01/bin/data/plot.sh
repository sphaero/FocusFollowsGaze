#!/bin/bash

DATA=$1
XLABEL="taskno."
YLABEL="seconds"

gnuplot -p -e "set autoscale;\
 set xlabel \"$XLABEL\" tc rgb \"black\";\
 set xlabel \"$XLABEL\" tc rgb \"black\";\
 set grid xtics lt 0 lw 1 lc rgb \"#AAAAAA\";\
 set grid ytics lt 0 lw 1 lc rgb \"#AAAAAA\";\
 set style fill solid;\
 set datafile separator \";\";\
 set datafile commentschars \"-\";\
 plot \"-\" using 2:4 with boxes"
