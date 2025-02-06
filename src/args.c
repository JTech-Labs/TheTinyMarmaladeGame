/*
This is the main file for The Tiny Marmalade Game.
Please see the README.md file that should have been distributed with this source code (it is probably in the root of the project).

This file is part of The Tiny Marmalade Game.
The Tiny Marmalade Game is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
The Tiny Marmalade Game is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with The Tiny Marmalade Game's source code (It resides in the LICENCE file at the root of the project). If not, see <https://www.gnu.org/licenses/>. 

(c) 2025 JTech-Labs
*/

// Headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// The header where the `theArgs` function is called from
#include "theCommands.h"

int theArgs(int argc, char *argv[]) {
  // Print the number of arguments passed to the program
  printf("Number of arguments: %d\n", argc);
  // Print each argument
  for (int i = 0; i < argc; i++) {
    printf("Argument %d: %s\n", i, argv[i]);
  }
  // Parse command-line options
  int opt;
  int flag = 0;
  while ((opt = getopt(argc, argv, "hf:")) != -1) {
    switch (opt) {
      case 'h':
        printf("Usage: %s [-h] [-f filename]\n", argv[0]);
        printf("  -h           Display this help message\n");
        printf("  -f filename  Specify a file to process\n");
        exit(EXIT_SUCCESS);
      case 'f':
        printf("Opening file: %s\n", optarg);
        flag = 1;
      break;
      case '?':
        fprintf(stderr, "Unknown option: %c\n", optopt);
        exit(EXIT_FAILURE);
     default:
        fprintf(stderr, "Error parsing options\n");
        exit(EXIT_FAILURE);
    }
 }
 // Check for positional arguments
 if (optind < argc) {
   printf("Positional arguments:\n");
   for (int i = optind; i < argc; i++) {
     printf(" %s\n", argv[i]);
   }
 }
 // Check for missing required options
 if (flag == 0) {
   fprintf(stderr, "Error: Missing required option -f\n");
   exit(EXIT_FAILURE);
 }
 // Program logic here
 return 0;
}
