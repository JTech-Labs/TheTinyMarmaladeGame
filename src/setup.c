/*
This is the main file for The Tiny Marmalade Game.
Please see the README.md file that should have been distributed with this source code (it is probably in the root of the project).

This file is part of The Tiny Marmalade Game.
The Tiny Marmalade Game is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
The Tiny Marmalade Game is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with The Tiny Marmalade Game's source code (It resides in the LICENCE file at the root of the project). If not, see <https://www.gnu.org/licenses/>. 

(c) 2025 JTech-Labs
*/

#include "../include/setup.h"

/// Textures

// Wabbit
Texture2D wabbit = LoadTexture("wabbitAlpha.png");

// The background
Image backgroundImage = LoadImage("background.png");
Texture2D background = LoadTextureFromImage(backgroundImage);


Rectangle backgroundSource = (Rectangle){0,0,background.width,background.height};
Rectangle backgroundDest = (Rectangle){0,0,GetScreenWidth(),GetScreenHeight()};
    
// The Welcome Screen
Image welcomeScreenImage = LoadImage("welcomeScreen.png");
Texture2D welcomeScreen = LoadTextureFromImage(welcomeScreenImage);

bool inADaBeningin = false; // TODO change to true for prod
int flipedTimer = 0;

// Marmalade jar
Image jarImage = LoadImage("jar.png");
Texture2D jar = LoadTextureFromImage(jarImage);


struct jarPos {
	int x;
	int y;
} jarPos;
int jarTimer = 0;

int jarYTarget = backgroundDest.height/2 - 3*(backgroundDest.height/20);
int jarXStart = 16*(backgroundDest.width/20);
int jarXTarget = backgroundDest.width/20;

Rectangle jarSource = (Rectangle){0,0,jar.width,jar.height};

struct sceneUpdateStruct {
    Rectangle jarDest;
    struct jarPos;

};

void initSetup() {
    UnloadImage(welcomeScreenImage);
    UnloadImage(jarImage);
    UnloadImage(backgroundImage);
}