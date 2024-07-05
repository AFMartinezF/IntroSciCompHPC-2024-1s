for size in {1..12}; do sed -i 's/cpus-per-task.*/cpus-per-task='$size'/' esc_parallel.sh ; sbatch esc_parallel.sh; done

#Calculo de la tabla con Nthreads | Wall time | Speed-up | Efficency
#cat slurm-{1067..1078}.out | awk '{print $1, $5, 0.937303/$5, 0.937303/$5/$1}'
#Reemplazar 1067..1078 con los números adecuados de los .out
