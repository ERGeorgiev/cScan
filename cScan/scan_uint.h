#pragma once

int scan_uint(unsigned int *output, int limit);
int input_uint(char *ch, unsigned int *input, int *total, int limit);
void print_uint(char *ch, unsigned int *input, int *total, int limit);
void erase_uint(unsigned int *input, int *total, int times);
void trans_uint(char ch, unsigned int *output, unsigned int input);