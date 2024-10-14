/*
Name: Vrishank Kulkarni
ID: 3115417
Class: EECS 348 lab 05
Lab time: Wednesday 1-2:50
sameple file: sales.txt

Objective: Given 12 monthly sales figures in an input file, generate the following reports
1. Monthly Sales Report: Display the month and sales in two columns.

2. Sales Summary Report: Show the minimum, maximum, and average monthly sales.

3. Six-Month Moving Average Report.

4. Sales Report (Highest to Lowest): Display the sales from highest to lowest
*/

#include <stdio.h>
#include <stdlib.h>

#define NUM_MONTHS 12  //defining the number of months as a constant

//function to generate the Monthly Sales Report
void monthlyReport(double sales[]) {
    printf("Monthly Sales Report for 2024\n");
    printf("%-12s %-10s\n", "Month", "Sales");  //print header with aligned columns

    //store month names corresponding to their index (0 = January, 1 = February, etc.)
    const char* months[] = {"January", "February", "March", "April", "May", "June", 
                            "July", "August", "September", "October", "November", "December"};
    
    //loop to print each month's sales data
    for (int i = 0; i < NUM_MONTHS; i++) {
        printf("%-12s $%-10.2f\n", months[i], sales[i]);  
    }
    printf("\n");
}

//function to generate the Sales Summary Report
void salesSummary(double sales[]) {
    double min = sales[0], max = sales[0], sum = 0;  //track min max and sum of sales
    int minMonth = 0, maxMonth = 0;     //track the month of min and max sales

    //loop to calculate the total sales and find min and max sales
    for (int i = 0; i < NUM_MONTHS; i++) {
        sum += sales[i]; 

        //check if the current month's sales is the new minimum
        if (sales[i] < min) {
            min = sales[i];
            minMonth = i;  
        }

        //check if the current month's sales is the new maximum
        if (sales[i] > max) {
            max = sales[i];
            maxMonth = i;  
        }
    }

    //calculate the average sales
    double avg = sum / NUM_MONTHS;

    //array to store month names corresponding to their index
    const char* months[] = {"January", "February", "March", "April", "May", "June", 
                            "July", "August", "September", "October", "November", "December"};
    
    //print the sales summary (min, max, and average sales)
    printf("Sales Summary Report:\n");
    printf("Minimum sales: $%.2f (%s)\n", min, months[minMonth]);  
    printf("Maximum sales: $%.2f (%s)\n", max, months[maxMonth]);  
    printf("Average sales: $%.2f\n", avg);  
    printf("\n");
}

//function to generate the Six-Month Moving Average Report
void sixMonthReport(double sales[]) {
    printf("Six-Month Moving Average Report:\n");

    //loop to calculate the moving average for each sliding window of 6 months
    for (int i = 0; i <= NUM_MONTHS - 6; i++) {
        double sum = 0;  

        //inner loop to sum the sales for the 6 months
        for (int j = i; j < i + 6; j++) {
            sum += sales[j]; 
        }

        //calculate the average for 6 months
        double average = sum / 6;

        //array to store month names corresponding to their index
        const char* months[] = {"January", "February", "March", "April", "May", "June", 
                                "July", "August", "September", "October", "November", "December"};
        
        printf("%-12s-%-12s: %.2f\n", months[i], months[i + 5], average); 
    }
    printf("\n");
}

//function to generate the Sales Report sorted from highest to lowest sales
void salesReport(double sales[]) {
    double sortedSales[NUM_MONTHS];  
    int months[NUM_MONTHS];  

    //copy the original sales data and month indices to new arrays
    for (int i = 0; i < NUM_MONTHS; i++) {
        sortedSales[i] = sales[i];
        months[i] = i; 
    }

    //sort the sales data in descending order 
    for (int i = 0; i < NUM_MONTHS - 1; i++) {
        for (int j = i + 1; j < NUM_MONTHS; j++) {
            if (sortedSales[i] < sortedSales[j]) {
                //swap sales values
                double tempSale = sortedSales[i];
                sortedSales[i] = sortedSales[j];
                sortedSales[j] = tempSale;

                //swap month indices to keep track of which month had which sales
                int tempMonth = months[i];
                months[i] = months[j];
                months[j] = tempMonth;
            }
        }
    }

    //array to store month names corresponding to their index
    const char* monthNames[] = {"January", "February", "March", "April", "May", "June", 
                                "July", "August", "September", "October", "November", "December"};
    
    //print the sales report in descending order
    printf("Sales Report (Highest to Lowest):\n");
    printf("%-12s %-10s\n", "Month", "Sales");

    //loop to print each month's sales in descending order
    for (int i = 0; i < NUM_MONTHS; i++) {
        printf("%-12s $%-10.2f\n", monthNames[months[i]], sortedSales[i]);  //print month and corresponding sales
    }
}



int main() {
    char inpFile[30];  //store the input file name
    double sales[NUM_MONTHS];  //array to store sales data for 12 months
    FILE *file;  //file pointer to handle the input file

    //get file name from user
    printf("Enter an input file name: ");
    scanf("%s", inpFile);  

    file = fopen(inpFile, "r");

    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;  //exit the program with an error code if the file couldn't be opened
    }

    //read sales data from file and store it in the sales array
    for (int i = 0; i < NUM_MONTHS; i++) {
        fscanf(file, "%lf", &sales[i]);  
    }


    fclose(file);

    //call functions
    monthlyReport(sales); 
    salesSummary(sales);    
    sixMonthReport(sales);  
    salesReport(sales);   

    return 0;
}
