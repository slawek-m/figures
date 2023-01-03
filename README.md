Figures Multithread is a simple package for creating and manipulating geometric figures.
The user can add his own figures in accordance with the "Figure" interface.
Figure manipulation is done in batch form using the "Batch" class. Batch runs
commands that implement the "Command" interface. Batch can use sequential or
multithread policy. The user can add his own command in accordance with the
"Command" interface. Batch implements the "Execute" and "Validate" methods
for executing commands and checking for overlapping figures after manipulations.
