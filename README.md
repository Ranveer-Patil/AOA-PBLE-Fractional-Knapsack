# AOA PBLE – Smart Delivery Planning (Fractional Knapsack)

## Project Overview

**Smart Delivery Planning – Fractional Knapsack** is an individual Problem-Based Learning Experiment (PBLE) for **Analysis of Algorithms (AOA)**.

The project implements the **Fractional Knapsack Greedy Algorithm in C**. A delivery vehicle has a fixed carrying capacity and a set of packages. Each package has a value/profit and weight. The program selects complete packages whenever possible and a fraction of a package when required to maximize the total value carried within the vehicle capacity.

## Objectives

- Understand and implement the Greedy Method.
- Calculate the Value/Weight ratio for every package.
- Arrange packages in decreasing order of Value/Weight ratio.
- Select complete packages whenever possible.
- Select a fraction of a package when a complete package cannot fit.
- Calculate and display the maximum possible value.
- Analyze the time complexity of the solution.

## Features

The program provides a menu-driven interface with:

1. Enter Package Details
2. Display Package Details
3. Calculate Value/Weight Ratio
4. Sort Packages by Ratio
5. Find Maximum Value
6. Display Selected Packages
7. Exit

## Algorithm

1. Read the number of packages and vehicle capacity.
2. Read the value/profit and weight of each package.
3. Calculate the Value/Weight ratio for every package.
4. Sort packages in decreasing order of their ratio.
5. Start with the package having the highest ratio.
6. If the complete package fits, select it.
7. Otherwise, select the required fraction of the package and fill the remaining capacity.
8. Calculate the total weight used and maximum value.
9. Display the selected quantity/fraction of each package.

## Example

### Input

- Number of packages: **3**
- Vehicle capacity: **50**

| Package | Value | Weight | Value/Weight |
|---|---:|---:|---:|
| 1 | 60 | 10 | 6.00 |
| 2 | 100 | 20 | 5.00 |
| 3 | 120 | 30 | 4.00 |

### Greedy Selection

- Package 1 → complete package → 10 kg → value 60
- Package 2 → complete package → 20 kg → value 100
- Package 3 → 20 kg out of 30 kg → approximately 0.67 fraction → value 80

### Output

**Total Weight Used:** 50.00 kg

**Maximum Value:** 240.00

## Time Complexity

The program uses Bubble Sort to arrange packages in decreasing order of Value/Weight ratio.

- Ratio calculation: **O(n)**
- Sorting: **O(n²)**
- Knapsack selection: **O(n)**

Therefore, the overall time complexity is:

**O(n²)**

## Space Complexity

The program stores package information in an array, so the auxiliary storage is:

**O(n)**

## Technologies Used

- **Language:** C
- **Algorithm:** Greedy Method
- **Problem:** Fractional Knapsack
- **Concepts:** Arrays, Structures, Functions, Sorting, Greedy Selection, Time Complexity

## Project File

- `fractional_knapsack.c` – Complete menu-driven C implementation.

## Author

**Ranveer Patil**

## Repository

This repository contains the source code for the AOA PBLE project and can be used to run and demonstrate the Fractional Knapsack Greedy Algorithm.