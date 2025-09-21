#pragma once
#include <string>
class FoodProduct
{
	std::string name_of_product;
	double energy_per_product;
	double price_per_product;
	double available_quantity;

public:
	FoodProduct(const std::string& name, double energy, double price, double quantitiy);
	
	const std::string& getName() const;
	double getEnergyPerProduct() const;
	double getPricePerProduct() const;
	double getAvailableQuantity() const;
	//for testing and clarity
	void print();
	
};