import matplotlib.pyplot as plt
import numpy as np

with open('result.csv') as f:
    lines = f.read().splitlines()

points = []
for line in lines:
    data = line.split(',')
    minimum = float(data[0])

    for value in data:
        points.append(float(value) - minimum)

stddev = np.std(points)

print(f"Standard deviation: {stddev:.2f}.")
print(f"Mean: {np.mean(points):.2f}.")
print(f"Median: {np.median(points):.2f}.")

total = len(points)
points = [p for p in points if p < 0.5 * stddev]
print(f"Removed {total - len(points)} outliers. {1 - len(points) / total:.2%}.")

plt.hist(points, bins=100)

plt.savefig('graph.png')
