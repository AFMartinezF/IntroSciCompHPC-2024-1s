#!/bin/bash

#Comentarios interpretados por slurm:
#SBATCH --job-name="example-stress"
#SBATCH --time=01:00:00
#SBATCH --partition=12threads
#SBATCH --ntasks=18

date
srun stress -t 10 -c 1 
#Comando original: 
#srun -p 12threads -n 18 stress -t 10 -c 1
