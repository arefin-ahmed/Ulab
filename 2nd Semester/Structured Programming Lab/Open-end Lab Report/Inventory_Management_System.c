#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PRODUCTS 100

// Struct to represent a product
struct Product
{
    char name[50];
    int units;
    double price;
};

// Global array to store inventory and a counter for the number of products
struct Product inventory[MAX_PRODUCTS];
int product_count = 0;

// Function to add a new product or update an existing one
void add_product()
{
    char name[50];
    int units;
    int found_index = -1;

    printf("Enter product name in lowercase: ");
    scanf(" %[^\n]", name);
    printf("Enter number of units to add: ");
    scanf("%d", &units);

    // Check if the product already exists
    for (int i = 0; i < product_count; i++)
    {
        if (strcmp(inventory[i].name, name) == 0)
        {
            found_index = i;
            break;
        }
    }

    if (found_index != -1)
    {
        // Product exists, just increase units
        inventory[found_index].units += units;
        printf("Units for '%s' updated. Total units: %d\n", name, inventory[found_index].units);
    }
    else
    {
        // Product does not exist, create a new one
        if (product_count < MAX_PRODUCTS)
        {
            double price;
            printf("New Product.\nEnter price per unit: ");
            scanf("%lf", &price);

            strcpy(inventory[product_count].name, name);
            inventory[product_count].units = units;
            inventory[product_count].price = price;

            product_count++;
            printf("New product '%s' added to inventory.\n", name);
        }
        else
        {
            printf("Inventory is full. Cannot add more products.\n");
        }
    }
}

// Function to take a product out of stock
void take_product_out()
{
    char name[50];
    int units_to_remove;
    int found_index = -1;

    printf("Enter product name in lowercase: ");
    scanf(" %[^\n]", name);
    printf("Enter number of units to take out: ");
    scanf("%d", &units_to_remove);

    // Find the product in the inventory
    for (int i = 0; i < product_count; i++)
    {
        if (strcmp(inventory[i].name, name) == 0)
        {
            found_index = i;
            break;
        }
    }

    if (found_index != -1)
    {
        // Product found, check if there are enough units
        if (inventory[found_index].units >= units_to_remove)
        {
            inventory[found_index].units -= units_to_remove;
            printf("Removed %d units of '%s'. Remaining units: %d\n", units_to_remove, name, inventory[found_index].units);
        }
        else
        {
            // Not enough inventory, show a warning
            printf("Warning: Not enough inventory for '%s'. Available units: %d\n", name, inventory[found_index].units);
        }
    }
    else
    {
        printf("Product '%s' not found in inventory.\n", name);
    }
}

// Function to show total inventory and its value
void show_inventory()
{
    double total_value = 0.0;

    if (product_count == 0)
    {
        printf("Inventory is empty.\n");
        return;
    }

    printf("\n----- Current Inventory -----\n");
    for (int i = 0; i < product_count; i++)
    {
        printf("Product: %s, Units: %d, Price: %.2f TK\n", inventory[i].name, inventory[i].units, inventory[i].price);
        total_value += inventory[i].units * inventory[i].price;
    }
    printf("-------------------------\n");
    printf("Total Inventory Value: %.2f TK\n", total_value);
}

int main()
{
    int choice;
    while (1)
    {
        printf("\n----- Main Menu -----\n");
        printf("1. Add new product\n");
        printf("2. Take product out\n");
        printf("3. Show total inventory\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        while (getchar() != '\n')
            ;

        switch (choice)
        {
        case 1:
            add_product();
            break;
        case 2:
            take_product_out();
            break;
        case 3:
            show_inventory();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}