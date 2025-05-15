# 2D N-body Problem solver

This solver uses dimensionless gravitational interaction forces between `n` bodies and a Verlet integrator to simulate their orbits in 2D. Using an input file `initial-conditions.cvs` storing the initial conditions in position and velocity as well as the mass of each body, the program can be used as follows:

- Create a folder `build`:
  ```cpp
  $ mkdir build
  $ cd ./build
  ````
- Compile the project:
  ```cpp
  $ cmake ..
  $ make
- Run the executable `nbody` with the arguments (optional in `[]`):
  ```cpp
  $ .\nbody <initial_conditions_file> [T_start] [T_end] [dt]
  ````
