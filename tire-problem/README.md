#Task of the exercise

"Create a program that asks the user for the dimensions of a car tire and calculates the tire's diameter and rolling circle based on them.

You program the tire diameter and rolling circle formulas as subroutines. You can also program so that the subroutine that calculates the rolling circle calls the subroutine that calculates the diameter.

(You can also use tire calculators found on the internet here. Google: tire calculator.

There may be 0.1-centimeter rounding differences in the rolling circle results between your own program and theirs, but you don't have to worry about them.)

The tire dimensions are
· width, millimetres,
· profile height, percentage of width and
· rim diameter, inches.

The tire size can be, for example, 205/60R16, where R stands for steel rimmed tire. (In the cross-stitch ring, there is a line instead of R.)

The tire diameter and rolling circle in millimetres are calculated from the above dimensions using the formulas
· Outer diameter = 25.4*rim size + 2*width*profile height/100.
· Rolling circle = coefficient*outer diameter, where the coefficient (programmatic constant before the main program) is approx. 3.049. (The reason that the multiplier is not silicon is apparently that the ring always flexes a little while rolling.)"