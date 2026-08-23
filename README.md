# Blood Donation System

## Project Overview

Blood Donation System is a console-based application developed in C programming language. The system is designed to manage blood donors and available blood stock using a simple menu-driven interface.

The project uses file handling to store donor and blood stock information so that data can be maintained between program runs.

## Objectives

- Manage blood donor information.
- Add, display, search, update, and delete donor records.
- Manage available blood stock.
- Allow users to request blood.
- Use file handling for permanent data storage.
- Practice modular programming in C.
- Develop a simple and user-friendly console application.

## Features

### 1. Login System
The system provides a basic login system before accessing the main menu.

**Default Login:**
- User ID: `admin`
- Password: `1234`

### 2. Donor Management

The system allows users to:

- Add a new donor
- Display all donors
- Search donors by blood group
- Update donor information
- Delete donor records

### 3. Blood Stock Management

The blood stock module allows users to:

- Add blood stock
- View available blood stock
- Request blood
- Automatically update available units after a blood request

### 4. File Handling

The system uses binary files to store information.

- `donors.dat` — stores donor information
- `stock.dat` — stores blood stock information

These files are generated automatically when the program is used.

## Project Structure

```text
BloodDonationSystem/
│
├── main.c
│
├── login.c
├── login.h
│
├── menu.c
├── menu.h
│
├── donor.c
├── donor.h
│
├── stock.c
└── stock.h
