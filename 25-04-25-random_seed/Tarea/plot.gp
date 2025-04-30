set term pdf
set out "Tarea_normal_distribution.pdf"
set xlabel "rango"
set ylabel "densidad"
set title "Resultados 5000 samples - rango [2.7, 4.6] - 50 bins"
plot 'seed_1.txt' w lp pt 4 lc rgb 'red' title 'semilla = 1', \
     'seed_2.txt' w lp pt 6 lc rgb 'blue' title 'semilla = 2', \
     'seed_3.txt' w lp pt 8 lc rgb 'green' title 'semilla = 5'
