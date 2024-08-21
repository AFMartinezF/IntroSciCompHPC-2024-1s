# Ejecutar para varios threads
for nth in {1..32}; do echo -n "$nth  " ; OMP_NUM_THREADS=$nth ./a.out 6000 2 2> /dev/null; done | tee times.txt

# Calcular las metricas
# NOTA: Cambiar el valor inicial de referencia de acuerdo a los datos
awk '{print $1, 35.5632/$3, 35.5632/$3/$1}' times.txt > metrics.txt

# Plot
gnuplot plot.gp