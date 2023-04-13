#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item {
    char name[20];
    int price;
};

struct item items[] = {
    {"Item 1", 100},
    {"Item 2", 200},
    {"Item 3", 300},
    {"Item 4", 400},
    {"Item 5", 500},
};

int num_items = sizeof(items) / sizeof(struct item);

int main() {
    int i, choice, quantity, total_price = 0;
    int discount_percent = 0;
    char payment_mode[20];
    
    printf("Available Items:\n");
    printf("----------------\n");
    for (i = 0; i < num_items; i++) {
        printf("%d. %s - %d\n", i+1, items[i].name, items[i].price);
    }
    printf("----------------\n");
    
    while (1) {
        printf("Enter item number to add (0 to stop): ");
        scanf("%d", &choice);
        if (choice == 0) {
            break;
        }
        if (choice < 1 || choice > num_items) {
            printf("Invalid item number, try again.\n");
            continue;
        }
        printf("Enter quantity: ");
        scanf("%d", &quantity);
        total_price += items[choice-1].price * quantity;
        printf("Added %d x %s to the cart.\n", quantity, items[choice-1].name);
    }
    
    printf("Total price: %d\n", total_price);
    
    printf("Enter discount percentage (0 if none): ");
    scanf("%d", &discount_percent);
    if (discount_percent > 0 && discount_percent <= 100) {
        total_price = total_price - (total_price * discount_percent / 100);
        printf("Discount of %d%% applied.\n", discount_percent);
    }
    
    printf("Enter payment mode (cash/card/netbanking): ");
    scanf("%s", &payment_mode);
    printf("Payment mode: %s\n", &payment_mode);
    printf("Total Price after discount: %d \n", total_price);
    
    printf("Thank you for shopping with us!\n");
    
    return 0;
}

