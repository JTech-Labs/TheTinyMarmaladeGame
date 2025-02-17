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
#include "rcamera.h"
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
	SearchAndSetResourceDir("assets");

	// Init variables
	const int screenWidth = 1080;
	const int screenHeight = 720;
	char gameTitle[] = "The Tiny Marmalade Game";
	bool exitWindow = false;
	bool exitWindowReq = false;

	InitWindow(screenWidth, screenHeight, gameTitle);

	SetTargetFPS(60);

	// Textures
	Texture2D wabbit = LoadTexture("images/wabbitAlpha.png");

	// Models
	Model initTable = LoadModel("assets/models/glb-gltf/initTable.glb");


	// Define the camera to look into the 3d world
	Camera menuCamera = { 0 };
	menuCamera.position = (Vector3){ 0.0f,30.0f,-0.0f};
	menuCamera.target = (Vector3){0.0f,0.0f,0.0f};
	menuCamera.up = (Vector3){0.0f,0.0f,0.0f,};
	menuCamera.fovy = 60.0f;
	menuCamera.projection = CAMERA_PERSPECTIVE;



	while (!exitWindow) {

		/// Manage Scene



		/// Update

		// Exit manager
		if (WindowShouldClose() || IsKeyPressed(KEY_ESCAPE)) exitWindowReq = true;

		if (exitWindowReq) {

			if (IsKeyPressed(KEY_Y)) exitWindow = true;
			else if (IsKeyPressed(KEY_N)) exitWindowReq = false;
		}

		// Camera

		UpdateCamera(&menuCamera, CAMERA_FIRST_PERSON);


		/// Draw
		BeginDrawing();

			ClearBackground(WHITE);
			
			DrawText("We are working!", 500, 500, 35, BLACK);

			BeginMode3D(menuCamera);
				
				DrawModel(initTable, (Vector3){0.0f,0.0f,0.0f}, 1.0f, BLUE);

			EndMode3D();

			// Exit manager
			if (exitWindowReq) {
				DrawRectangle(0, (screenHeight/10)*2, screenWidth, (screenHeight/10)*6, BLACK);
				DrawText("Are you sure you want to exit? [Y/N]", 40, screenHeight/2, 30, WHITE);
				
			}

		EndDrawing();
	}


	/// Cleanup
	UnloadTexture(wabbit);
	UnloadModel(initTable);

	// Return with no errors unless previously stated otherwise
	return 0;
}