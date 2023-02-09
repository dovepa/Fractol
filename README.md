# Project Fractol

Fractol is a graphic project from the 42 School curriculum. The objective of this project is to create a program that generates and renders fractals, mathematical objects with intricate patterns and shapes.

### Requirements
- X11 library
- GCC compiler
- Make

### Installation
1. Clone this repository: `git clone https://github.com/[username]/fractol.git`
2. Enter the repository: `cd fractol`
3. Compile the program: `make`

### Usage
1. Run the program: `./fractol [fractal_name]`
2. The program takes in a single argument, the name of the fractal to be displayed. Available fractals are: Mandelbrot, Julia, and Burning Ship.
3. Use the following keys to interact with the image:
    - Zoom: scroll up and down
    - Move: arrow keys
    - Change iterations: + and - keys
    - Change color scheme: C key
    - Reset: R key
    - Exit: Esc key

### Fractal generation
The program uses complex number arithmetic to generate and render the fractals. Each pixel in the image is assigned a value based on the number of iterations it takes for the value to escape a certain boundary. The color of the pixel is then determined based on the number of iterations.
