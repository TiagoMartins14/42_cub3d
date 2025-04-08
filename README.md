# 42_cub3d
Project developed during the Common Core @ 42 Porto

## cub3d
My first RayCaster with miniLibX

### Summary:
This project is inspired by the world-famous Wolfenstein 3D game, which is
considered the first FPS ever created. It will enable you to explore ray-casting. Your goal
will be to make a dynamic view inside a maze, where you will have to find your way.

## 🛠️ Usage

### Requirements

The project is written in C language and needs the **`gcc` compiler** and some standard **C libraries** to run.

### Instructions

**1. Compiling the project**<p>

### Step 1 / Clone the repository:
```bash
$> git clone git@github.com:TiagoMartins14/42_cub3d.git
```

### Step 2 / Install Minilibx and its dependencies:
Minilibx download:
```bash
$> make download
```
Minilibx dependencies:
```bash
$> sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev
```

### Step 3 / Compile the program:  
```bash
$> make
```

### Step 4 / Run the program:
The map folder has some pre-configured maps for you to test the game environment.  
You're able to create a map of your own and the program will tell you if the map is valid or not.  

<details>
<summary>Click here for map creation tutorial.</summary>
  
Map Rules:
There has to be a path for each wall texture
The floor and ceileing colors need to be defined in r,g,b format.
The map layout has to be the last thing on the file.
It has to be a **closed map** (walls around).
The map file extension has to be **'.cub'**.  
The map is composed by 3 elements:  
```
- '0' for empty spaces;
- '1' for walls;
- 'N', 'S', 'E' or 'W' for Player's starting position and spawning orientation;
```

Map example:
```
NO ./textures/tech_1.xpm
SO ./textures/tech_2.xpm
WE ./textures/tech_3.xpm
EA ./textures/tech_4.xpm

F 95,95,95
C 50,50,50

        1111111111111111111111111
        1000000000110000000000001
        1011000001110000000000001
        1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111100111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
```
</details>

To run the program, you need to select a map from the existing ones or the one that you've created. For that, you need to put its filename. The map needs to be inside the **maps** folder  
  
```bash
$> ./cub3d map.cub
```

To exit the game, just press 'ESC' on your keyboard or click the 'X' in the game window. **HAVE FUN!**

## 👥 Contributors
This project was developed collaboratively as part of the 42 School curriculum.

- [josevazf](https://github.com/josevazf)
