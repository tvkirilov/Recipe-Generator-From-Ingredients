#include "FoodProduct.h"
#include<iostream>
FoodProduct::FoodProduct(const std::string& name, double energy, double price, double quantitiy)

	:name_of_product(name), energy_per_product(energy), price_per_product(price), available_quantity(quantitiy)
{
}

const std::string& FoodProduct::getName() const
{
	return name_of_product;
}

double FoodProduct::getEnergyPerProduct() const
{
	return energy_per_product;
}

double FoodProduct::getPricePerProduct() const
{
	return price_per_product;
}

double FoodProduct::getAvailableQuantity() const
{
	return available_quantity;
}

void FoodProduct::print()
{
	std::cout << "Info about product:" << std::endl;
	std::cout << "Name:" << name_of_product << " Energy:" << energy_per_product
		<< " Price:" << price_per_product << " available quantity:" << available_quantity << std::endl;
}
