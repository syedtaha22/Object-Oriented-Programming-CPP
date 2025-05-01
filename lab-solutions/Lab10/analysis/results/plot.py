# Load benchmark data from benchmark_results.csv, using pandas, and use matplotlib to plot the results
# Make two subplots: one for comparisons and one for swaps
# On x-axis, plot the size of the array
# on the y-axis, plot the number of comparisons and swaps
# Data stored in a CSV file with the following columns:
# Size,Insertion Compares,Insertion Swaps,Selection Compares,Selection Swaps,Shell Compares,Shell Swaps,Tree Compares,Tree Swaps

import pandas as pd
import matplotlib.pyplot as plt

# Load the CSV data
df = pd.read_csv("benchmark_results.csv")

# Extract x-axis (array sizes)
sizes = df["Size"]

# Create subplots: one for comparisons, one for swaps
fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(10, 5), sharex=True)

# Main title
fig.suptitle("Random Array (Average Case)", fontsize=14)

# Plot comparisons
ax1.plot(sizes, df["Insertion Compares"], label="Insertion Sort", marker='o', ms=5, markevery=1000)
ax1.plot(sizes, df["Selection Compares"], label="Selection Sort", marker='o', ms=5, markevery=1000)
ax1.plot(sizes, df["Shell Compares"], label="Shell Sort", marker='.', ms=5, markevery=1000)
ax1.set_title("Comparisons vs Array Size")
ax1.set_ylabel("Number of Comparisons")
ax1.legend()
ax1.grid(True)

# Plot swaps
ax2.plot(sizes, df["Insertion Swaps"], label="Insertion Sort", marker='o', ms=5, markevery=1000)
ax2.plot(sizes, df["Selection Swaps"], label="Selection Sort", marker='.', ms=4, markevery=1000)
ax2.plot(sizes, df["Shell Swaps"], label="Shell Sort", marker='o', ms=5, markevery=1000)
ax2.set_title("Swaps vs Array Size")
ax2.set_xlabel("Array Size")
ax2.set_ylabel("Number of Swaps")
ax2.legend()
ax2.grid(True)

# Adjust layout and display
plt.tight_layout()
plt.savefig("benchmark_results_average_case.png", dpi=300)
plt.show()
