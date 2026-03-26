import matplotlib.pyplot as plt
import numpy as np

data = np.loadtxt('result.csv', delimiter=',')
data = np.atleast_2d(data)

row_min = np.min(data, axis=1, keepdims=True)
points = (data - row_min).ravel()

mean = np.mean(points)
median = np.median(points)
stddev = np.std(points)

print(f"Mean: {mean:.3f}ns")
print(f"Median: {median:.3f}ns")
print(f"Stddev: {stddev:.3f}ns")

total = points.size
mask = np.all([points < 500, points > 0], axis=0)
points = points[mask]
print(f"Removed {total - points.size} outliers. {1 - points.size / total:.2%}.")

plt.hist(points, bins=500)
plt.savefig('graph.png')
