#!/bin/bash

DATA=$1
XLABEL="taskno."
YLABEL="seconds"

gnuplot -p -e "set autoscale;\
 set xlabel \"$XLABEL\" tc rgb \"black\";\
 set ylabel \"$YLABEL\" tc rgb \"black\";\
 set grid xtics lt 0 lw 1 lc rgb \"#AAAAAA\";\
 set grid ytics lt 0 lw 1 lc rgb \"#AAAAAA\";\
 set style fill solid;\
 set boxwidth 0.8;\
 set datafile separator \";\";\
 set datafile commentschars \"-\";\
 plot \"< grep PROP 1383763425\" using 2:4 with boxes lc rgb \"green\" title \"modify property\",
 \"< grep TDWN 1383763425\" using 2:4 with boxes lc rgb \"red\" title \"rotate cube\",
 \"< grep TXT1 1383763425\" using 2:4 with boxes lc rgb \"blue\" title \"enter text right\",
 \"< grep TXT2 1383763425\" using 2:4 with boxes lc rgb \"purple\" title \"enter text bottom\";"
