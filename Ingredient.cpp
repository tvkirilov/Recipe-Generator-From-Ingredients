#include "ingredient.h"

Ingredient::Ingredient(const std::string& name, double needed_q)
	:ingredient_name(name), needed_quantity(needed_q)
{
}

const std::string& Ingredient::getName() const
{
	return ingredient_name;
}

double Ingredient::getNeededQuantitity() const
{
	return needed_quantity;
}
