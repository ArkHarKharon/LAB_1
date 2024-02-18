#pragma once
#include <array>
#include "enums.h"
#include "union.h"


void delete_item(std::array<Awful, 5>& arr, std::size_t index, std::array <States, 5>& states, Civ6& str);
void delete_all(std::array<Awful, 5>& arr, std::array <States, 5>& states, Civ6& str);

void input(std::array<Awful, 5>& arr, std::size_t index, std::array <States, 5>& states);
void input_civ(std::array<Awful, 5>& arr, std::size_t index, std::array <States, 5>& states);
void input_eve(std::array<Awful, 5>& arr, std::size_t index, std::array <States, 5>& states);
void add(std::array<Awful, 5>& arr, std::array <States, 5>& states);

void print_item(std::array<Awful, 5> const& arr, std::size_t index, std::array <States, 5>& states);
void print_all(std::array<Awful, 5> const& arr, std::array <States, 5>& states);


void main_menu(std::array<Awful, 5>& arr, std::array<States, 5>& states, Civ6& clear_str);

void joking();

void pclear();

int random(int min, int max);