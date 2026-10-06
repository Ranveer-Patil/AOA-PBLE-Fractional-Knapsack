#include <stdio.h>

#define MAX 100

struct Package
{
    int id;
    float value;
    float weight;
    float ratio;
    float quantity;
};

/* Function to calculate Value/Weight ratio */
void calculateRatio(struct Package p[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        p[i].ratio = p[i].value / p[i].weight;
    }

    printf("\nValue/Weight ratios calculated successfully.\n");
}

/* Function to sort packages in decreasing ratio */
void sortPackages(struct Package p[], int n)
{
    int i, j;
    struct Package temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (p[j].ratio < p[j + 1].ratio)
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    printf("\nPackages sorted by decreasing Value/Weight ratio.\n");
}

/* Function to find maximum value */
void findMaximumValue(struct Package p[], int n, float capacity)
{
    int i;
    float remaining = capacity;
    float totalValue = 0;

    /* Initially no package is selected */
    for (i = 0; i < n; i++)
    {
        p[i].quantity = 0;
    }

    for (i = 0; i < n; i++)
    {
        if (remaining <= 0)
            break;

        /* Complete package can be selected */
        if (p[i].weight <= remaining)
        {
            p[i].quantity = 1;
            remaining = remaining - p[i].weight;
            totalValue = totalValue + p[i].value;
        }
        else
        {
            /* Fraction of package is selected */
            p[i].quantity = remaining / p[i].weight;
            totalValue = totalValue + (p[i].quantity * p[i].value);
            remaining = 0;
        }
    }

    printf("\n========== RESULT ==========\n");

    printf("Total Weight Used : %.2f\n", capacity - remaining);
    printf("Maximum Value     : %.2f\n", totalValue);
}

/* Function to display package details */
void displayPackages(struct Package p[], int n)
{
    int i;

    printf("\n------------------------------------------------------------\n");
    printf("ID\tValue\tWeight\tRatio\tSelected Quantity\n");
    printf("------------------------------------------------------------\n");

    for (i = 0; i < n; i++)
    {
        printf("%d\t%.2f\t%.2f\t%.2f\t%.2f\n",
               p[i].id,
               p[i].value,
               p[i].weight,
               p[i].ratio,
               p[i].quantity);
    }

    printf("------------------------------------------------------------\n");
}

/* Main function */
int main()
{
    struct Package p[MAX];

    int n;
    int choice;
    int dataEntered = 0;
    int ratioCalculated = 0;
    int sorted = 0;
    int resultCalculated = 0;

    float capacity;

    printf("==============================================\n");
    printf("     SMART DELIVERY PLANNING\n");
    printf("       FRACTIONAL KNAPSACK\n");
    printf("==============================================\n");

    do
    {
        printf("\n\n========== MENU ==========\n");
        printf("1. Enter Package Details\n");
        printf("2. Display Package Details\n");
        printf("3. Calculate Value/Weight Ratio\n");
        printf("4. Sort Packages by Ratio\n");
        printf("5. Find Maximum Value\n");
        printf("6. Display Selected Packages\n");
        printf("7. Exit\n");
        printf("===========================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("\nEnter number of packages: ");
                scanf("%d", &n);

                printf("Enter vehicle capacity: ");
                scanf("%f", &capacity);

                for (int i = 0; i < n; i++)
                {
                    p[i].id = i + 1;

                    printf("\nPackage %d\n", i + 1);

                    printf("Enter value/profit: ");
                    scanf("%f", &p[i].value);

                    printf("Enter weight: ");
                    scanf("%f", &p[i].weight);

                    p[i].quantity = 0;
                    p[i].ratio = 0;
                }

                dataEntered = 1;
                ratioCalculated = 0;
                sorted = 0;
                resultCalculated = 0;

                printf("\nPackage details entered successfully!\n");
                break;

            case 2:
                if (!dataEntered)
                {
                    printf("\nPlease enter package details first.\n");
                }
                else
                {
                    printf("\nPackage Details:\n");

                    printf("-----------------------------------\n");
                    printf("ID\tValue\tWeight\n");
                    printf("-----------------------------------\n");

                    for (int i = 0; i < n; i++)
                    {
                        printf("%d\t%.2f\t%.2f\n",
                               p[i].id,
                               p[i].value,
                               p[i].weight);
                    }

                    printf("-----------------------------------\n");
                    printf("Vehicle Capacity = %.2f\n", capacity);
                }
                break;

            case 3:
                if (!dataEntered)
                {
                    printf("\nPlease enter package details first.\n");
                }
                else
                {
                    calculateRatio(p, n);
                    ratioCalculated = 1;

                    printf("\nPackage Ratios:\n");

                    for (int i = 0; i < n; i++)
                    {
                        printf("Package %d : %.2f\n",
                               p[i].id,
                               p[i].ratio);
                    }
                }
                break;

            case 4:
                if (!dataEntered)
                {
                    printf("\nPlease enter package details first.\n");
                }
                else
                {
                    if (!ratioCalculated)
                    {
                        calculateRatio(p, n);
                        ratioCalculated = 1;
                    }

                    sortPackages(p, n);
                    sorted = 1;

                    printf("\nPackages after sorting:\n");

                    printf("------------------------------------------\n");
                    printf("ID\tValue\tWeight\tRatio\n");
                    printf("------------------------------------------\n");

                    for (int i = 0; i < n; i++)
                    {
                        printf("%d\t%.2f\t%.2f\t%.2f\n",
                               p[i].id,
                               p[i].value,
                               p[i].weight,
                               p[i].ratio);
                    }

                    printf("------------------------------------------\n");
                }
                break;

            case 5:
                if (!dataEntered)
                {
                    printf("\nPlease enter package details first.\n");
                }
                else
                {
                    if (!ratioCalculated)
                    {
                        calculateRatio(p, n);
                        ratioCalculated = 1;
                    }

                    if (!sorted)
                    {
                        sortPackages(p, n);
                        sorted = 1;
                    }

                    findMaximumValue(p, n, capacity);
                    resultCalculated = 1;
                }
                break;

            case 6:
                if (!resultCalculated)
                {
                    printf("\nPlease find maximum value first.\n");
                }
                else
                {
                    printf("\nSelected Packages:\n");
                    displayPackages(p, n);
                }
                break;

            case 7:
                printf("\nThank you! Program terminated.\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 7);

    return 0;
}
