# Snake Game – Terminal Based  
**Author:** Muhammad Raza  
**Roll No:** CPE-23-02  

## Overview  
This is a simple **terminal-based Snake Game** created using fundamental programming and **DSA (Data Structures & Algorithms)** concepts. The game runs in a 2D grid where the player controls a snake that grows in length each time it consumes food. The game ends when the snake collides with the wall or itself.

## Features  
- **2D Grid Game Board** – A matrix-based board representing the playing area.  
- **Snake Movement** – Controlled using **W**, **A**, **S**, **D** keys.  
- **Food Generation** – Randomly appears on the grid; increases snake length upon eating.  
- **Growth Mechanic** – Snake grows with each food item eaten.  
- **Game Over Conditions** – Collision with walls or with the snake's own body ends the game.

## DSA Concepts Used  
- **Arrays** – To represent the snake's body segments.  
- **2D Arrays** – For representing the game grid.  
- **Linear Search** – To detect self-collision by checking if the head overlaps with the body.  
- **Looping and Conditional Logic** – Controls movement, food spawning, collision detection, and game state.

## How It Works  
1. Initialize a grid and place the snake and food.  
2. Continuously update the grid as the snake moves.  
3. Handle user input for direction changes.  
4. Detect collisions and handle snake growth.  
5. End the game when collision criteria are met.
