#include <iostream>
#include <vector>
#include "datamodel.h"

// Define a vector to store all available products    
vector<Product> allProducts={
    Product(1, "apple", 5),
    Product(2, "banana", 3),
    Product(3, "orange", 4),
    Product(4, "mango", 7)
};

// Function to allow the user to choose a product from the available list
Product* ChooseProduct(){
    string product_list;
    cout << "Available Products: " << endl;
    
    // Display the available products
    for(auto product : allProducts){
        product_list.append(product.getDisplayName());
    }
    cout << product_list << endl;

    cout << "--------------------------"<< endl;
    string choice;
    cin>>choice;

    // Search for the chosen product by its short name
    for (int i = 0; i < allProducts.size(); ++i) {
        if(allProducts[i].getShortName() == choice){
            return &allProducts[i]; // Return a pointer to the chosen product
        }
    }
    cout << "Product was not fount"<< endl;
    return NULL;
}

// Function to perform the checkout process
bool checkout(Cart &cart){
    if(cart.isEmpty()){
        return false; // If the cart is empty, return false
    }

    int total = cart.getTotal();
    cout << "Pay in Cash: ";

    int paid;
    cin >> paid;

    if(paid >= total){
        cout << "Change " << paid - total << endl;
        cout << "Thank you for shopping"<<endl;
        return true; // If payment is sufficient, return true
    }
    else{
        cout << "Not enought Cash"<<endl;
        return false; // If payment is insufficient, return false
    }
}


int main(){
    char action;
    Cart cart;

    while(true){
        cout << "select an action - (a)dd item, (v)iew cart, (c)heckout"<<endl;
        cin >> action;
        
        // Add item to the cart
            if(action == 'a' )
            {
                
                Product *product = ChooseProduct(); // Choose a product from the available list
                if(product != NULL){
                    cout << "added to the cart " << product->getDisplayName()<<endl;
                    cart.addProduct(*product); // Add the chosen product to the cart
                }}

            // View the contents of the cart
            if(action == 'v'){
                cout << "---------------------\n";
                cout << cart.viewCart()<<endl;
                cout << "---------------------\n";
            }

            // Proceed to checkout
            if(action == 'c') {
                cout << cart.viewCart()<<endl;
                if(checkout(cart)){ // Perform the checkout process
                    exit(0); // Exit the program after successful checkout
                }

            }


        }
}

