#pragma once
#include <stdint.h>

uint64_t scan_real(char limit, char allowminus); //Maximum limit = 18;
uint32_t real_whole(uint64_t number);
uint32_t real_decimal(uint64_t number); //Returns decimal without the zeros on its left, so be careful.
char input_real(char *ch, uint64_t *input, char *total, char *decimal, char limit, char allowminus, char *negative); 
void print_real(char *ch, uint64_t *input, char *total, char *decimal, char limit);
void erase_real(uint64_t *input, char *total, char *decimal, char *negative, int times);