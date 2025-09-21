# Recipe Generator from Ingredients

This is a simple C++ project that suggests possible recipes based on the ingredients you have available.  
It was built as a learning exercise in object-oriented programming, working with files, and basic data structures.

---

## 📌 Features
- Define food products and their nutritional values.
- Store ingredients in text files (`Products.txt` and `Recipes.txt`).
- Suggest recipes based on which ingredients are currently available.
- Demonstrates class usage (`Ingredient`, `FoodProduct`, `Recipe`) and modular project structure.

---

## 📂 Project Structure
- `CoreFunctions.cpp / .h` – contains helper functions used across the project.
- `FoodProduct.cpp / .h` – defines food products and their properties.
- `Ingredient.cpp / .h` – defines ingredients and their usage in recipes.
- `Recipe.cpp / .h` – defines recipes and the logic for checking required ingredients.
- `Main.cpp` – entry point of the application.
- `Products.txt` – sample list of available ingredients.
- `Recipes.txt` – sample list of recipes.

---

## ⚙️ How It Works
1. The program loads **available ingredients** from `Products.txt`.
2. It then loads **recipes** from `Recipes.txt`.
3. For each recipe, it checks whether all required ingredients are available.
4. It outputs the recipes that can be prepared with the current ingredients.

---

## ▶️ Building and Running
1. Open the `.vcxproj` file in **Visual Studio**.
2. Build the project (`Ctrl + Shift + B`).
3. Run the executable.  
   - Make sure `Products.txt` and `Recipes.txt` are in the same directory as the executable.

---

## 📝 Example
**Products.txt**
