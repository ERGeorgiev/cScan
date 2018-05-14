#pragma once
#include <stdint.h>

uint32_t scan_date();
int date_day(uint32_t date);
int date_month(uint32_t date);
int date_year(uint32_t date);
int check_date(uint32_t date);
int input_date(uint32_t *input, int *total, char *ch);
void print_date(uint32_t *input, int *total, char *ch);
void erase_date(uint32_t *input, int *total, int times);