#pragma once
#include "Recipe.h"
#include<vector>
#include<string>
#include<map>
#include <fstream>
#include <sstream>

//This is the core function that searches throught the data and finds
// all the available recipes that we can make given the available products
std::vector<Recipe> FindAvailableRecipes(std::vector<Recipe>& all_recipes, std::map<std::string, FoodProduct>& given_products);

//a function that recives the user imput of name and quantity of an available product, reads the energy and price of the product
//from a file and contructs and returns an object from the foodProduct class
FoodProduct loadProductFromTXT(const std::string& productName, double availableQuantity);
//TODO comment on what the function that reads the recipes from a file does
std::vector<Recipe> loadRecipesFromTXT(const std::string& filename);

//The main function where we handle the user input and we output the desired data
void RunApp();

