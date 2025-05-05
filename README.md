# Bank Simulator

## Overview

The Bank Simulator is an application that simulates the functionality of a simple banking system. Users can create bank accounts, deposit and withdraw funds, make transfers, and manage their personal information.

## Technologies Used

- **Language**: C++
- **Platform**: Console app

## Features

#### Account Creation:
Users can create new bank accounts by providing their personal information (e.g., first name, last name, identification number, email address, etc.).
- Functions:
   - Verification of user data (e.g., checking if the identification number is unique)
   - Creation of an account with an initial balance

#### Deposits
Users can deposit money into their bank account.
- Functions:
   - Input the deposit amount
   - Update the account balance after making a deposit

#### Withdrawals
Users can withdraw money from their account, provided their balance is sufficient.
- Functions:
   - Verification that the account balance allows for the withdrawal
   - Decrease the balance by the withdrawn amount

#### Checking Balance
Users can check the balance of their account at any time.
- Functions:
   - Display the current account balance

#### Transfers Between Accounts
Users can make transfers to other accounts within the same bank.
- Functions:
   - Transfer funds from one user’s account to another user's account
   - Check available balance before initiating the transfer

#### Transaction History
Users can view the transaction history of their account (deposits, withdrawals, transfers).
- Functions:
   - Display a list of transactions with date, amount, and transaction type

#### Account Management
Users can edit their personal information, such as changing their email address or phone number.
- Functions:
   - Edit user data
   - Change password

