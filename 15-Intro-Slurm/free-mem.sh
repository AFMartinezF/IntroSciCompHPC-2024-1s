#!/bin/bash
#SBATCH --job-name="example-cpu-mem"
#SBATCH --time=01:00:20
#SBATCH --partition=12threads
#SBATCH --ntasks=6
#SBATCH --ntasks-per-node=1
#SBATCH --output slurm-%j.out
#SBATCH --error slurm-%j.err
# #SBATCH --mem-per-cpu=66M
# #SBATCH --mem=2G

export OMP_NUM_THREADS=$SLURM_CPUS_PER_TASK

srun bash -c "hostname; free -m"
