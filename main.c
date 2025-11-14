#include <stdio.h>

int main() {
    int productID[10], quantity[10];
    float price[10];
    char name[10][50];
    int n, choice, searchID;
    int i;

    printf("Enter number of products (max 10): ");
    scanf("%d", &n);

    // INPUT PRODUCT DETAILS
    for (i = 0; i < n; i++) {
        printf("\nEnter Product %d ID: ", i + 1);
        scanf("%d", &productID[i]);

        printf("Enter Product %d Name: ", i + 1);
        scanf("%s", name[i]);

        printf("Enter Quantity in Stock: ");
        scanf("%d", &quantity[i]);

        printf("Enter Price per Item: ");
        scanf("%f", &price[i]);
    }

    while (1) {
        printf("\n\n--- Inventory Menu ---\n");
        printf("1. Display all products\n");
        printf("2. Total inventory value\n");
        printf("3. Product with highest value\n");
        printf("4. Product with lowest value\n");
        printf("5. Search product by ID\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\nProduct List:\n");
            for (i = 0; i < n; i++) {
                printf("%d   %s   Qty: %d   Price: %.2f\n",
                       productID[i], name[i], quantity[i], price[i]);
            }
        }

        else if (choice == 2) {
            float total = 0;
            for (i = 0; i < n; i++) {
                total += quantity[i] * price[i];
            }
            printf("\nTotal Inventory Value = %.2f\n", total);
        }

        else if (choice == 3) {
            int maxIndex = 0;
            float maxValue = quantity[0] * price[0];

            for (i = 1; i < n; i++) {
                float value = quantity[i] * price[i];
                if (value > maxValue) {
                    maxValue = value;
                    maxIndex = i;
                }
            }

            printf("\nProduct with Highest Value:\n");
            printf("%d  %s  Qty: %d  Price: %.2f  Total: %.2f\n",
                   productID[maxIndex], name[maxIndex],
                   quantity[maxIndex], price[maxIndex], maxValue);
        }

        else if (choice == 4) {
            int minIndex = 0;
            float minValue = quantity[0] * price[0];

            for (i = 1; i < n; i++) {
                float value = quantity[i] * price[i];
                if (value < minValue) {
                    minValue = value;
                    minIndex = i;
                }
            }

            printf("\nProduct with Lowest Value:\n");
            printf("%d  %s  Qty: %d  Price: %.2f  Total: %.2f\n",
                   productID[minIndex], name[minIndex],
                   quantity[minIndex], price[minIndex], minValue);
        }

        else if (choice == 5) {
            printf("Enter product ID to search: ");
            scanf("%d", &searchID);
            int found = 0;

            for (i = 0; i < n; i++) {
                if (productID[i] == searchID) {
                    printf("\nProduct Found:\n");
                    printf("%d  %s  Qty: %d  Price: %.2f\n",
                           productID[i], name[i], quantity[i], price[i]);
                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf("\nProduct not found!\n");
            }
        }

        else if (choice == 6) {
            printf("Exiting program...\n");
            break;
        }

        else {
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}