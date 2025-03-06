/*
This is the main file for The Tiny Marmalade Game.
Please see the README.md file that should have been distributed with this source code (it is probably in the root of the project).

This file is part of The Tiny Marmalade Game.
The Tiny Marmalade Game is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
The Tiny Marmalade Game is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with The Tiny Marmalade Game's source code (It resides in the LICENCE file at the root of the project). If not, see <https://www.gnu.org/licenses/>. 

(c) 2025 JTech-Labs
*/

#pragma once

#ifndef SETUP
#define SETUP

//// Variables

/// Textures

// Wabbit
extern Texture2D wabbit;

// The background
extern Texture2D background;

extern Rectangle backgroundSource;
extern Rectangle backgroundDest;
    
// The Welcome Screen
extern Texture2D welcomeScreen;
extern bool inADaBeningin; // TODO change to true for prod
extern int flipedTimer;

// Marmalade jar
extern Texture2D jar;

extern struct jarPos {
	int x;
	int y;
} jarPos;
extern int jarTimer;

extern int jarYTarget;
extern int jarXStart;
extern int jarXTarget;

extern Rectangle jarSource;

extern struct sceneUpdateStruct {
    Rectangle jarDest;
    struct jarPos;

};

#endif SETUP