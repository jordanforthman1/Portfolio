/*
Jordan Forthman
COP 2800 HW11_2
11/18/21
This program predicts future value using monthly investment, interest rate and years.
*/

import java.util.*;
import java.text.*;

public class FutureValueApp
{
    public static void main(String[] args)
    {
        System.out.println("Welcome to the Future Value Calculator\n");

        Scanner sc = new Scanner(System.in);
        String choice = "y";
        final double MIMIN = 0, MIMAX = 1000, IRMIN = 0, IRMAX = 30, YMIN = 1, YMAX = 10;
        boolean isValid = false;
        double monthlyInvestment = 0;
        double interestRate = 0;
        int years = 1;

        while (choice.equalsIgnoreCase("y"))
        {
            // get the input from the user
            System.out.println("DATA ENTRY");
            while (!isValid) {
                try{
                    System.out.print("Enter monthly investment: ");
                    monthlyInvestment = sc.nextDouble(); 
                    
                    if(monthlyInvestment >= MIMIN && monthlyInvestment <= MIMAX) {
                        isValid = true;
                    }
                    else if (monthlyInvestment < MIMIN) {
                        System.out.println("Error! number must be greater than 0.");
                        sc.nextLine();
                    }
                    else if (monthlyInvestment > MIMAX) {
                        System.out.println("Error! number must be less than 1000.");
                        sc.nextLine();
                    }
                }
                catch (InputMismatchException ex) {
                        System.out.println("Error! Invalid decimal value.");
                        sc.nextLine();
                        }
                   }
            
            isValid = false;
            
            while (!isValid) {
                try {
                    System.out.print("Enter yearly interest rate: ");
                    interestRate = sc.nextDouble();
                    
                    if (interestRate >= IRMIN && interestRate <= IRMAX) {
                        isValid = true;
                    }
                    else if (interestRate < IRMIN) {
                        System.out.println("Error! number must be greater than " + IRMIN);
                        sc.nextLine();
                    }
                    else if (interestRate > IRMAX) {
                        System.out.println ("Error! number mmust be less than " + IRMAX);
                        sc.nextLine();
                    }
                }
                catch (InputMismatchException ex) {
                    System.out.println ("Error! Invalid decimal value.");
                    sc.nextLine();                            
                }
            }            
            
            isValid = false;
            
            while(!isValid) {
                try {
                    System.out.print("Enter number of years: ");
                    years = sc.nextInt();  
                    
                    if (years >= YMIN && years <= YMAX) {
                        isValid = true;
                    }
                    else if (years < YMIN) {
                        System.out.println ("Error! Number must be greater than " + YMIN);
                        sc.nextLine();
                    }
                    else if (years > YMAX) {
                        System.out.println ("Error! Number must be less than " + YMAX);
                        sc.nextLine();
                    }
                }
                catch (InputMismatchException ex) {
                    System.out.println ("Error! Invalid decimal value.");
                    sc.nextLine();                            
                }
            }
           

            // calculate the future value
            double monthlyInterestRate = interestRate/12/100;
            int months = years * 12;
            double futureValue = calculateFutureValue(
                monthlyInvestment, monthlyInterestRate, months);

            // get the currency and percent formatters
            NumberFormat currency = NumberFormat.getCurrencyInstance();
            NumberFormat percent = NumberFormat.getPercentInstance();
            percent.setMinimumFractionDigits(1);

            // format the result as a single string
            String results =
                  "Monthly investment:\t"
                      + currency.format(monthlyInvestment) + "\n"
                + "Yearly interest rate:\t"
                      + percent.format(interestRate/100) + "\n"
                + "Number of years:\t"
                      +  years + "\n"
                + "Future value:\t\t"
                      + currency.format(futureValue) + "\n";

            // print the results
            System.out.println();
            System.out.println("FORMATTED RESULTS");
            System.out.println(results);

            // see if the user wants to continue
            System.out.print("Continue? (y/n): ");
            choice = sc.next();
            sc.nextLine();  // discard any other data entered on the line
            System.out.println();
        }
    }

    public static double calculateFutureValue(double monthlyInvestment,
    double monthlyInterestRate, int months)
    {
        double futureValue = 0;
        for (int i = 1; i <= months; i++)
        {
            futureValue =
                (futureValue + monthlyInvestment) *
                (1 + monthlyInterestRate);
        }
        return futureValue;
    }
}
