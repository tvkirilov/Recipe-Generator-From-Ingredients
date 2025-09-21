#pragma once
#include <string>
class Ingredient
{
	std::string ingredient_name;
	double needed_quantity;
	
public:
	Ingredient(const std::string& name, double needed_q);
	const std::string& getName() const;
	double getNeededQuantitity() const;

};