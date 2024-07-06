#!/bin/bash 

#SBATCH --job-name=mpi_example          # Job name
#SBATCH --output=mpi_example_%j.out     # Standard output log
#SBATCH --error=mpi_example_%j.err      # Standard error log
#SBATCH --ntasks=18                     # Number of MPI tasks (processes)
#SBATCH --nodes=3                       # Number of nodes
#SBATCH --ntasks-per-node=6             # Adjust based on your cluster's configuration
#SBATCH --time=01:00:00                 # Time limit hrs:min:sec
#SBATCH --partition=12threads           # Partition name

## Load the necessary modules (adjust based on your system)
#module load mpi

# Run the MPI program using srun
#srun pwd
#srun hostname
#srun --mpi=pmi2 ./a.out
#srun --mpi=pmi2 hostname
#srun echo $SLURMD_NODENAME
#srun -n $SLURM_NTASKS ./a.out
mpirun ./basic.x
#mpirun hostname

