#include "CoreFunctions.h"
#include<iostream>
std::vector<Recipe> FindAvailableRecipes(std::vector<Recipe>& all_recipes, std::map<std::string, FoodProduct>& given_products)
{
	//we create a vector to store all the recipes we can make
	std::vector<Recipe> available_recipes;

	//we treverse the knowledge base of recipes
	for (int i = 0; i < all_recipes.size(); i++)
	{
		//we check if we can make at least one serving of the curret recipe
		if (all_recipes[i].calculateMaxServings(given_products) > 0)
		{
			//if we can, then we add it to the list (a vector) of available recipes
			available_recipes.push_back(all_recipes[i]);
		}
	}

	//we return the list of possible recipes we can make with our current products
	return available_recipes;
}

FoodProduct loadProductFromTXT(const std::string& productName, double availableQuantity)
{
	std::ifstream file("Products.txt");
	if (!file.is_open())
	{
		std::cerr << "Error opening products.txt"<<std::endl;
		return FoodProduct("NOT_FOUND", 0, 0, 0);
	}

	std::string line;
	while (std::getline(file, line)) {
		std::stringstream ss(line);
		std::string name;
		double energy, price;

		ss >> name >> energy >> price;

		if (name == productName) {
			return FoodProduct(name, energy, price, availableQuantity);
		}
	}

	return FoodProduct("NOT_FOUND", 0, 0, 0);
}


std::vector<Recipe> loadRecipesFromTXT(const std::string& filename)
{
	std::ifstream file(filename);
	if (!file.is_open()) {
		std::cerr << "Error opening recipe file."<<std::endl;
		return {};
	}

	std::vector<Recipe> recipes;
	std::string line;

	std::string currentRecipeName;
	std::vector<Ingredient> currentIngredients;

	while (std::getline(file, line)) {
		
		if (line.empty()) {
		
			if (!currentRecipeName.empty()) {
				recipes.push_back(Recipe(currentRecipeName, currentIngredients));
				currentRecipeName.clear();
				currentIngredients.clear();
			}
			continue;
		}

		std::stringstream ss(line);
		if (currentRecipeName.empty()) {
		
			currentRecipeName = line;
		}
		else {
			
			std::string ingredient_name;
			double quantity;
			ss >> ingredient_name >> quantity;
			currentIngredients.push_back(Ingredient(ingredient_name, quantity));
		}
	}

	// We handle last recipe (if the file doesn't end with a blank line)
	if (!currentRecipeName.empty()) {
		recipes.push_back(Recipe(currentRecipeName, currentIngredients));
	}
	// We reeturn the recipes we loaded from the file
	return recipes;
}

void RunApp()
{
	std::map<std::string, FoodProduct> userProducts;
	std::string p_name;
	double av_amount;

	std::cout << "What products do you have? Type the name and the quantity of each product.\n Type \"done\" when you are ready" << std::endl;
	while (true)
	{
		std::cin >> p_name;
		if (p_name == "done")
		{
			std::cout << "\n The list of available recipes:" << std::endl;
			break;
		}
		std::cin >> av_amount;

		FoodProduct product = loadProductFromTXT(p_name, av_amount);

		if (product.getName() == "NOT_FOUND")
		{
			std::cout << "Product not found in database: " << p_name << std::endl;
		}
		else
		{
			userProducts.insert({ product.getName(), product });
			product.print();
		}
	 }

	std::vector<Recipe> all_recipes = loadRecipesFromTXT("recipes.txt");
	bool found_at_least_one = false;

	//changed! (I forogt to use FindAvailableRecipes function and instead just kinda rewrote the function
	std::vector<Recipe>available_recipes=FindAvailableRecipes(all_recipes, userProducts);
	if (available_recipes.empty())
	{
		std::cout << "No available recipes with those products :(" << std::endl;
	}
	else
	{
		for (int i = 0; i < available_recipes.size(); i++)
		{
			available_recipes[i].printSummary(userProducts);
		}
	}
	
}
