#!/bin/bash
#SBATCH --array=1-16
#SBATCH --job-name="using-jobarray"
#SBATCH --time=01:00:20
#SBATCH --partition=16threads
#SBATCH --ntasks=1
# #SBATCH --cpus-per-task=1
#SBATCH --ntasks-per-node=1
#SBATCH --output slurm-%A_%a.out
#SBATCH --error slurm-%A_%a.err

export OMP_NUM_THREADS=${SLURM_ARRAY_TASK_ID}

echo -n "$OMP_NUM_THREADS    "

srun ./esc_p.x 50000000

