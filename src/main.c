/*
This is the main file for The Tiny Marmalade Game.
Please see the README.md file that should have been distributed with this source code (it is probably in the root of the project).

This file is part of The Tiny Marmalade Game.
The Tiny Marmalade Game is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
The Tiny Marmalade Game is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with The Tiny Marmalade Game's source code (It resides in the LICENCE file at the root of the project). If not, see <https://www.gnu.org/licenses/>. 

(c) 2025 JTech-Labs
*/

// Include all the base libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Include the **very** important raylib library
#include "raylib.h"

//Import our own headers for functions from different files
#include "baseCommands.h"
// #include "include/resourceDir.h"	// utility header for SearchAndSetResourceDir (part of the raylib-quickstart template)

// The all important main function
int main(int argc, char *argv[]) {

	theArgs(argc, argv);

	// Return with no errors unless previously stated otherwise
	return 0;
}
