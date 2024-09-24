//This program creates 10 dynamic bank accounts for user.

import java.util.Scanner;
public class ATM_Machine {
    private static Scanner input = new Scanner(System.in);

    public static void main (String[] args) {
        Account1[] accountArray = new Account1[10];
        for (int i = 0; i < 10; i++) {
            accountArray[i] = new Account1(i, 100.0);
        }
        
        System.out.println("Welcome to the ATM Machine Game!");
        
        System.out.println("Enter an ID between 0 and 9, 999 to quit the game: ");
        int id = input.nextInt();
        
        if (id < 0 || id > 9){
            invalidID(id);}
        
        while(true) {
        System.out.println("Main menu");
        System.out.println("1: Check Balance");
        System.out.println("2: Withdraw");
        System.out.println("3: Deposit");
        System.out.println("4: Exit");
        System.out.println("");
        System.out.println("Enter a choice: ");
        int select = input.nextInt();
        
        if (select == 999) {
            System.out.println("Game over. Goodbye!");
            System.exit(0);
        }

        if (select == 4) {
      System.out.println("Enter an ID between 0 and 9, 999 to quit the game: ");
      id = input.nextInt();
      
        if(id < 0 || id > 9){
            invalidID(id);}
        }
        
        if (select == 1) {
          System.out.println("The balance is $" + accountArray[id].getBalance());
          System.out.println(""); }
          
        else if (select == 2) {
            System.out.println("Enter an amount to withdraw: ");
            accountArray[id].withdraw(input.nextDouble());
            
        }
        else if (select == 3) {
            System.out.println("Enter an amount to deposit: ");
            accountArray[id].deposit(input.nextDouble());
        }
        }
    }
    
    
    public static int invalidID(int id) {
        while (id < 0 || id > 9) {
            System.out.print("Invalid ID, enter a valid id: ");
            id = input.nextInt();
            System.out.println();
        }
        return id;
    }
    
    static class Account1 {
    
    private int id = 0;
    private double monthlyFee = 0;
    private double balance = 100;
    
    Account1() {}
    public Account1(int id, double balance) {
        this();
        this.id = id;
        this.balance = balance;
    }
    public int getId(){
        return this.id;
    }
    public double getBalance() {
        return this.balance;
    }
    public double getmonthlyFee() {
        return this.monthlyFee;
    }
    
    public void setId(int id){
        this.id = id;
    }
    public void setBalance(double balance) {
        this.balance = balance;
    }
    public void setMonthlyFee(double monthlyFee) {
        this.monthlyFee = monthlyFee;
    }
    
    public double calMonthlyBalance() {
        return balance - monthlyFee;
    }
    public void withdraw(double withdraw) {
        this.balance -= withdraw;
    }
    public void deposit(double deposit) {
        this.balance += deposit;
    }
    }
}

