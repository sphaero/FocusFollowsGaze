#!/bin/bash

DATA=$1
XLABEL="taskno."
YLABEL="time"

gnuplot -p -e "set autoscale;\
 set terminal png size 800,600 enhanced font \"Helvetica,16\";\
 set output '$DATA.png'; \
 set xlabel \"$XLABEL\" tc rgb \"black\";\
 set ylabel \"$YLABEL\" tc rgb \"black\";\
 set grid xtics lt 0 lw 1 lc rgb \"#AAAAAA\";\
 set grid ytics lt 0 lw 1 lc rgb \"#AAAAAA\";\
 set style fill solid;\
 set boxwidth 0.8;\
 set datafile separator \";\";\
 set datafile commentschars \"-\";\
 plot \"< grep PROP $DATA\" using 2:6 with boxes lc rgb \"#2222FF\" title \"modify property\",
 \"< grep PROP $DATA\" using 2:5 with boxes lc rgb \"#2222AA\" notitle,
 \"< grep TDWN $DATA\" using 2:6 with boxes lc rgb \"#FF2222\" title \"rotate cube\",
 \"< grep TDWN $DATA\" using 2:5 with boxes lc rgb \"#AA2222\" notitle,
 \"< grep TXT1 $DATA\" using 2:6 with boxes lc rgb \"#22FF22\" title \"enter text right\",
 \"< grep TXT1 $DATA\" using 2:5 with boxes lc rgb \"#22AA22\" notitle,
 \"< grep TXT2 $DATA\" using 2:6 with boxes lc rgb \"#FF22FF\" title \"enter text right\",
 \"< grep TXT2 $DATA\" using 2:5 with boxes lc rgb \"#AA22AA\" notitle;"
