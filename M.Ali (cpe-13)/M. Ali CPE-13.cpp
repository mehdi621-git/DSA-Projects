#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item {
    char name[50];
    int quantity;
    float price;
    struct Item* next;
};
struct Item* createItem(char* name, int quantity, float price) {
    struct Item* newItem = (struct Item*)malloc(sizeof(struct Item));
    strcpy(newItem->name, name);
    newItem->quantity = quantity;
    newItem->price = price;
    newItem->next = NULL;
    return newItem;
}

void addItem(struct Item** head, char* name, int quantity, float price) {
    struct Item* newItem = createItem(name, quantity, price);
    newItem->next = *head;
    *head = newItem;
    printf("Item '%s' added to the cart.\n", name);
}

void removeItem(struct Item** head, char* name) {
    struct Item* temp = *head;
    struct Item* prev = NULL;

    if (temp != NULL && strcmp(temp->name, name) == 0) {
        *head = temp->next; // Move the head to the next item
        free(temp);
        printf("Item '%s' removed from the cart.\n", name);
        return;
    }

    // Search for the item to remove
    while (temp != NULL && strcmp(temp->name, name) != 0) {
        prev = temp;
        temp = temp->next;
    }

    // Item not found
    if (temp == NULL) {
        printf("Item '%s' not found in the cart.\n", name);
        return;
    }

   
    prev->next = temp->next;
    free(temp);
    printf("Item '%s' removed from the cart.\n", name);
}


void viewCart(struct Item* head) {
    struct Item* temp = head;
    float totalPrice = 0.0;

    if (temp == NULL) {
        printf("Your cart is empty.\n");
        return;
    }

    printf("\nYour cart items:\n");
    while (temp != NULL) {
        printf("Item: %s, Quantity: %d, Price: %.2f\n", temp->name, temp->quantity, temp->price);
        totalPrice += temp->quantity * temp->price;
        temp = temp->next;
    }
    printf("Total Price: %.2f\n", totalPrice);
}

void sortItemsByPrice(struct Item* head) {
    if (head == NULL) return;
    struct Item* i = head;
    struct Item* j = NULL;
    float tempPrice;
    int tempQuantity;
    char tempName[50];

    while (i != NULL) {
        j = i->next;
        while (j != NULL) {
            if (i->price > j->price) {
                tempPrice = i->price;
                tempQuantity = i->quantity;
                strcpy(tempName, i->name);

                i->price = j->price;
                i->quantity = j->quantity;
                strcpy(i->name, j->name);

                j->price = tempPrice;
                j->quantity = tempQuantity;
                strcpy(j->name, tempName);
            }
            j = j->next;
        }
        i = i->next;
    }

    printf("Items sorted by price.\n");
}

void sortItemsByName(struct Item* head) {
    if (head == NULL) return;
    struct Item* i = head;
    struct Item* j = NULL;
    char tempName[50];
    int tempQuantity;
    float tempPrice;

    while (i != NULL) {
        j = i->next;
        while (j != NULL) {
            if (strcmp(i->name, j->name) > 0) {
                strcpy(tempName, i->name);
                tempQuantity = i->quantity;
                tempPrice = i->price;

                strcpy(i->name, j->name);
                i->quantity = j->quantity;
                i->price = j->price;

                strcpy(j->name, tempName);
                j->quantity = tempQuantity;
                j->price = tempPrice;
            }
            j = j->next;
        }
        i = i->next;
    }

    printf("Items sorted by name.\n");
}

int main() {
    struct Item* cart = NULL;
    int choice;
    char name[50];
    int quantity;
    float price;

    while (1) {
        printf("\nShopping Cart System\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. View Cart\n");
        printf("4. Sort Items by Price\n");
        printf("5. Sort Items by Name\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item name: ");
                scanf("%s", name);
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                printf("Enter price: ");
                scanf("%f", &price);
                addItem(&cart, name, quantity, price);
                break;
            case 2:
                printf("Enter item name to remove: ");
                scanf("%s", name);
                removeItem(&cart, name);
                break;
            case 3:
                viewCart(cart);
                break;
            case 4:
                sortItemsByPrice(cart);
                break;
            case 5:
                sortItemsByName(cart);
                break;
            case 6:
                printf("Exiting the shopping cart system...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

