Tarea_normal_distribution.pdf : seed_1.txt seed_2.txt seed_3.txt plot.gp
	gnuplot plot.gp
	okular Tarea_normal_distribution.pdf

seed_1.txt seed_2.txt seed_3.txt : Normal.x
	./Normal.x 1 5000 3.5 0.4 2.7 4.6 50 > seed_1.txt
	./Normal.x 2 5000 3.5 0.4 2.7 4.6 50 > seed_2.txt
	./Normal.x 5 5000 3.5 0.4 2.7 4.6 50 > seed_3.txt

Normal.x : Normal_Distribution.cpp
	g++ Normal_Distribution.cpp -o Normal.x

clean :
	rm -f *.x *.txt *.pdf
	ls
