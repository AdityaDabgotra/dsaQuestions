class Banking:
    # Class-level attribute for the bank name (shared by all instances)
    bank_name = "SBI"
    
    def __init__(self, initial_balance=0, acc_name="Unknown"):
        """Initialize account with an initial balance and account holder's name."""
        self.balance = initial_balance  # Instance attribute
        self.name = acc_name  # Instance attribute

    
    def show_balance(self):
        """Display the current balance of the account."""
        print("*")
        print(f"Account holder: {self.name}")
        print(f"Bank: {self.bank_name}")
        print(f"Your balance is ${self.balance:.2f}")

    def deposit(self):
        """Deposit a valid amount into the account."""
        try:
            amount = float(input("Enter the amount to be deposited: $"))
            if amount <= 0:
                print(f"{amount} is not a valid amount.")
                return 0
            else:
                self.balance += amount
                print(f"Successfully deposited ${amount:.2f}")
                return amount
        except ValueError:
            print("Invalid input. Please enter a valid number.")
            return 0

    def withdraw(self):
        """Withdraw a valid amount from the account."""
        try:
            amount = float(input("Enter the amount to withdraw: $"))
            if amount <= 0:
                print(f"{amount} is not a valid amount.")
                return 0
            elif amount > self.balance:
                print("Insufficient funds.")
                return 0
            else:
                self.balance -= amount
                print(f"Successfully withdrew ${amount:.2f}")
                return amount
        except ValueError:
            print("Invalid input. Please enter a valid number.")
            return 0

    def transfer(self, recipient_account):
        """Transfer money to another account."""
        try:
            amount = float(input(f"Enter the amount to transfer to {recipient_account.name}: $"))
            if amount <= 0:
                print(f"{amount} is not a valid amount.")
                return 0
            elif amount > self.balance:
                print("Insufficient funds for transfer.")
                return 0
            else:
                self.balance -= amount
                recipient_account.balance += amount
                print(f"Successfully transferred ${amount:.2f} to {recipient_account.name}.")
                return amount
        except ValueError:
            print("Invalid input. Please enter a valid number.")
            return 0

    def display_account_info(self):
        """Display account details."""
        print(f"Account holder: {self.name}")
        print(f"Bank Name: {self.bank_name}")
        print(f"Balance: ${self.balance:.2f}")


# Main Program Flow
def main():
    accounts = {}  # Dictionary to store accounts by name
    is_running = True

    # Create some initial accounts (Can be dynamically added)
    accounts["Asad"] = Banking(1000, "Asad")  
    accounts["Rajveer"] = Banking(500, "Rajveer")
    accounts["Mudasir"]= Banking(800,"Mudasir")

    while is_running:
        print("------------------")
        print("BANKING PROGRAM")
        print("------------------")
        print("1. Create a New Account".upper())
        print("2. Select an Account".upper())
        print("3. Exit".upper())
        print("-------------------")
        print()

        # Main menu
        main_choice = input("Choose an option (1-3): ")

        if main_choice == "1":
            # Option to create a new account
            acc_name = input("Enter the account holder's name: ")
            initial_balance = float(input(f"Enter initial balance for {acc_name}: $"))
            accounts[acc_name] = Banking(initial_balance, acc_name)
            print(f"Account for {acc_name} created successfully.")

        elif main_choice == "2":
            # Select an account to operate on
            print("\nAvailable Accounts:")
            for idx, acc in enumerate(accounts.values(), start=1):
                print(f"{idx}. {acc.name}")

            # Loop until a valid account is selected2
            while True:
                try:
                    selected_account_index = int(input("Select the account number (1-2): "))
                    if 1 <= selected_account_index <= len(accounts):
                        selected_account = list(accounts.values())[selected_account_index - 1]
                        break  # Exit loop once a valid account is selected
                    else:
                        print("Invalid account number. Please choose a valid account.")
                except ValueError:
                    print("Invalid input. Please enter a valid number.")

            # Now, perform operations on the selected account
            while True:
                print(f"\nSelected Account: {selected_account.name}")
                print("1. Show balance".upper())
                print("2. Deposit".upper())
                print("3. Withdraw".upper())
                print("4. Transfer".upper())
                print("5. Back to Main Menu".upper())
                print("-------------------")
                print()

                action_choice = input("Enter your choice (1-5): ")

                if action_choice == "1":
                    selected_account.show_balance()  # Show balance for the selected account
                elif action_choice == "2":
                    selected_account.deposit()  # Deposit into the selected account
                elif action_choice == "3":
                    selected_account.withdraw()  # Withdraw from the selected account
                elif action_choice == "4":
                    # Transfer logic: user can transfer to any other account
                    print("Available Accounts for Transfer:")
                    for idx, acc in enumerate(accounts.values(), start=1):
                        if acc != selected_account:  # Skip the selected account itself
                            print(f"{idx}. {acc.name}")

                    recipient_index = int(input("Select recipient account number: "))
                    recipient_account = list(accounts.values())[recipient_index - 1]

                    selected_account.transfer(recipient_account)  # Transfer from the selected account to the recipient

                elif action_choice == "5":
                    break  # Go back to the main menu
                else:
                    print("Invalid choice, please select again.")
        elif main_choice == "3":
            is_running = False  # Exit the loop
        else:
            print("Invalid option, please select again.")

    print("Thank you! Have a nice day.")

    #for key in accounts.keys():
        #print(f"{key}")

if __name__ == "__main__":
    main()
