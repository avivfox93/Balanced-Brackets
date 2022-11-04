# Balanced brackets solution
## Why?
A few days ago, I've been challenged to solve the balanced brackets problem in C.<br>
I got very nervous and tried to solve it using loops. When failed I even tried using recursion.<br>
Just after the time went out I understood how stupid I was.<br>
A few minutes later I finished the solution using simple stack (obvious...).<br>
After that incident I had a hard time falling asleep the next two days, trying to justify my stupidity :).<br>
Then it came to me! Let's solve the problem without any extra memory.<br>
I am coming from the embedded world, so a lot of the time we are looking for a solution that will be memory efficient.

## How?
Using custom implementation of a stack, customized for the solution of the balances brackets problem.<br>
The stack buffer is the input string so no need for any memory allocation.<br>
This solution is less efficient in terms of complexity but far more efficient in terms of memory footprint during runtime.

## Usage
### Building
```
make all
```
### Executing:
Windows:
```
.\standard_solution.exe input_string
.\custom_solution.exe input_string
```
Linux:
```
./standard_solution input_string
./custom_solution input_string
```
