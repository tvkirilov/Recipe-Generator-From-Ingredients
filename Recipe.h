#pragma once
#include "Ingredient.h"
#include "FoodProduct.h"
#include <vector>
#include <string>
#include <map>
class Recipe
{
	std::string recipe_name;
	std::vector<Ingredient> list_of_needed_ingredients;

public:
	Recipe(const std::string& name, std::vector<Ingredient> list);
	const std::string& getName() const;

	void addIngredient(const Ingredient& ingr);
	int calculateMaxServings(const std::map<std::string, FoodProduct>& products);
	double calculateEnergyPerServing(const std::map<std::string, FoodProduct>& products);
	double calculatePricePerServing(const std::map<std::string, FoodProduct>& products);
	void printSummary(const std::map<std::string, FoodProduct>& products);
};