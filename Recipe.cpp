#include "Recipe.h"
#include<iostream>
//a constant so we dont have a "magic" number 100 just floating around
const int PER_100G = 100;

Recipe::Recipe(const std::string& name, std::vector<Ingredient> list)

	:recipe_name(name), list_of_needed_ingredients(list)
{
}

const std::string& Recipe::getName() const
{
	return recipe_name;
}

void Recipe::addIngredient(const Ingredient& ingr)
{
	list_of_needed_ingredients.push_back(ingr);
}

int Recipe::calculateMaxServings(const std::map<std::string, FoodProduct>& products)
{
	int max_servings = INT_MAX;
	int possible_servings = 0;
	std::map<std::string, FoodProduct>::const_iterator it;

	for (int i = 0; i < list_of_needed_ingredients.size(); i++)
	{
		//We check if the current ingredient we need is in the list of available ingrediants
		it = products.find(list_of_needed_ingredients[i].getName());
		if (it != products.end())
		{
			//we calculate the possible amount of servings by taking the available quantity of the product and devide it with the requered quantitiy
			possible_servings = floor(it->second.getAvailableQuantity() / list_of_needed_ingredients[i].getNeededQuantitity()); //floor is not needed but just for clarification

			//we update the max amount of servings we can make
			if (possible_servings < max_servings)
			{
				max_servings = possible_servings;
			}
			
		}	
		//if the ingredient is not found in the list of available ingrediants, that means that we cant make any servings of that recipe
		else
		{
			return 0;
		}
	}

	return max_servings;
}

double Recipe::calculateEnergyPerServing(const std::map<std::string, FoodProduct>& products)
{

	double total_energy = 0;
	std::map<std::string, FoodProduct>::const_iterator it;

	for (int i = 0; i < list_of_needed_ingredients.size(); i++)
	{
		it = products.find(list_of_needed_ingredients[i].getName());

		//if (it != products.end())//we should not need this line because we are working on already valid recipes that we have the ingredient for
		// so there should not be any missing ingredients
		//{
			total_energy += it->second.getEnergyPerProduct() *
				(list_of_needed_ingredients[i].getNeededQuantitity() / PER_100G);
		//}
	}
	return total_energy;
}

double Recipe::calculatePricePerServing(const std::map<std::string, FoodProduct>& products)
{
	double total_price = 0;
	std::map<std::string, FoodProduct>::const_iterator it;

	for (int i = 0; i < list_of_needed_ingredients.size(); i++)
	{
		it = products.find(list_of_needed_ingredients[i].getName());

		total_price += it->second.getPricePerProduct() *
			(list_of_needed_ingredients[i].getNeededQuantitity() / PER_100G);
	}
	return total_price;
}

void Recipe::printSummary(const std::map<std::string, FoodProduct>& products)
{

	const std::string CURRENCY = "BGN";
	const std::string ENERGY_METRIC = "kcal";
	int servings =calculateMaxServings(products);
	if (servings == 0)return;

	double energy = calculateEnergyPerServing(products);
	double price = calculatePricePerServing(products);
	
	std::cout << "Dish: " << recipe_name << std::endl;
	std::cout << "Max Servings: " << servings << std::endl;
	std::cout << "Energy per Serving: " << energy <<" " << ENERGY_METRIC<< std::endl;
	std::cout << "Price per Serving: "<< CURRENCY << " " << price << std::endl;
	std::cout << "Products needed per serving:";
	for (int i = 0; i < list_of_needed_ingredients.size(); i++)
	{
		std::cout << list_of_needed_ingredients[i].getName() << " " << list_of_needed_ingredients[i].getNeededQuantitity() << " grams. ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
}
