#!/bin/bash 
#SBATCH --job-name="parallel"
#SBATCH --time=01:00:20
#SBATCH --partition=12threads
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=12
#SBATCH --output slurm-%j.out
#SBATCH --error slurm-%j.err
# #SBATCH --mem-per-cpu=667MB

export OMP_NUM_THREADS=$SLURM_CPUS_PER_TASK

time ./p.x 1000000000
