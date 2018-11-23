modele load anaconda/python3

rm *.dat
gcc -fopenmp walk.c -o walk 
gcc -fopenmp walkno.c -o walkno 

python3 plots.py
