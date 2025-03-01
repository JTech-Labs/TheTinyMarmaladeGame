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
#include <unistd.h>

// Include the **very** important raylib library
#include "raylib.h"
#include "../include/raygui.h"

//Import our own headers for functions from different files
#include "../include/baseCommands.h"
#include "../include/resourceDir.h"	// utility header for SearchAndSetResourceDir (part of the raylib-quickstart template)

/// The all important main function
int main(int argc, char *argv[]) {

	/// Startup

	// Run the command line parameters, if none are received, continue as normal
	theArgs(argc, argv);

	printf("Starting...\n");
	printf("\n===============\n\n");
	
	/// Initialisation

	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
	SearchAndSetResourceDir("assets/images");

	// Init variables
	const int screenWidth = 1920;
	const int screenHeight = 1080;

	
	char gameTitle[] = "The Tiny Marmalade Game";
	bool exitWindow = false;
	bool exitWindowReq = false;

	InitWindow(screenWidth, screenHeight, gameTitle);

	ToggleFullscreenWindow(screenWidth, screenHeight);

	SetTargetFPS(60);

	Image icon = LoadImage("icon.png");
	SetWindowIcon(icon);

	// Textures
	
	// Wabbit
	Texture2D wabbit = LoadTexture("wabbitAlpha.png");
	
	// The background
	Image backgroundImage = LoadImage("background.png");
	Texture2D background = LoadTextureFromImage(backgroundImage);
	UnloadImage(backgroundImage);

	// Marmalade jar
	Image jarImage = LoadImage("jar.png");
	Texture2D jar = LoadTextureFromImage(jarImage);
	UnloadImage(jarImage);

	while (!exitWindow) {

		/// Manage Scene

		

		/// Update

		// Exit manager 
		if (WindowShouldClose() && !IsKeyPressed(KEY_ESCAPE)) exitWindowReq = true;

		WaitTime(0.01);
		
		if (exitWindowReq) {

			if (IsKeyReleased(KEY_Y)) exitWindow = true;
			else if (IsKeyReleased(KEY_N) || IsKeyReleased(KEY_ESCAPE)) exitWindowReq = false;
			else if (IsKeyPressed(KEY_F)) { exitWindowReq = false; ToggleFullscreenWindow(screenWidth, screenHeight); }
		}


		/// Draw
		BeginDrawing();

			ClearBackground(WHITE);
			
			DrawTexture(background, 0, 0, WHITE);
			DrawTexture(jar, GetDisplayWidth()/2 - jar.width/2, GetDisplayHeight()/2 - jar.height/2, WHITE);



			// Exit manager
			if (exitWindowReq) {
				DrawRectangle(0, (GetDisplayHeight()/10)*2, GetDisplayWidth(), (GetDisplayHeight()/10)*6, BLACK);
				DrawText("Are you sure you want to exit? [Y/N]", 40, (GetDisplayHeight()/2)-(GetDisplayHeight()/20), 30, WHITE);
				
			}

		EndDrawing();
	}


	/// Cleanup
	UnloadTexture(wabbit);
	UnloadTexture(background);
	UnloadImage(icon);

	// Return with no errors unless previously stated otherwise
	return 0;
}