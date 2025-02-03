#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int theArgs(int argc, char *argv[]) {
  // Print the number of arguments passed to the program
  printf(“Number of arguments: %d\n”, argc);
  // Print each argument
  for (int i = 0; i < argc; i++) {
    printf(“Argument %d: %s\n”, i, argv[i]);
  }
  // Parse command-line options
  int opt;
  int flag = 0;
  while ((opt = getopt(argc, argv, “hf:”)) != -1) {
    switch (opt) {
      case ‘h’:
        printf("Usage: %s [-h] [-f filename]\n", argv[0]);
        printf("  -h           Display this help message\n");
        printf("  -f filename  Specify a file to process\n");
        exit(EXIT_SUCCESS);
      case ‘f’:
        printf(“Opening file: %s\n”, optarg);
        flag = 1;
      break;
      case ‘?’:
        fprintf(stderr, “Unknown option: %c\n”, optopt);
        exit(EXIT_FAILURE);
     default:
        fprintf(stderr, “Error parsing options\n”);
        exit(EXIT_FAILURE);
    }
 }
 // Check for positional arguments
 if (optind < argc) {
   printf(“Positional arguments:\n”);
   for (int i = optind; i < argc; i++) {
     printf(“ %s\n”, argv[i]);
   }
 }
 // Check for missing required options
 if (flag == 0) {
   fprintf(stderr, “Error: Missing required option -f\n”);
   exit(EXIT_FAILURE);
 }
 // Program logic here
 return 0;
}
