import json
import matplotlib.pyplot as plt
import numpy as np

json_path = "benchmarks.json"
with open(json_path, "r") as f:
  data = json.load(f)

c_res = data["results"][0]
fr_res = data["results"][1]

labels = ["C (Clang)", "Friday"]
means = [c_res["mean"], fr_res["mean"]]
stddevs = [c_res["stddev"], fr_res["stddev"]]
all_times = [c_res["times"], fr_res["times"]]

delta_ms = (means[1] - means[0]) * 1000
overhead_pct = ((means[1] - means[0]) / means[0]) * 100

plt.style.use("seaborn-v0_8-whitegrid" if "seaborn-v0_8-whitegrid" in plt.style.available else "default")
fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(11, 5), dpi=300)

colors = ["#2b5c8f", "#d95f02"]

bars = ax1.bar(labels, means, yerr=stddevs, capsize=6, color=colors, alpha=0.85, width=0.55, edgecolor="black", linewidth=1.2)

y_min = min(means) - 0.15
y_max = max(means) + 0.15
ax1.set_ylim(y_min, y_max)

ax1.set_ylabel("Execution Time (seconds)", fontsize=12, fontweight="bold")
ax1.set_title("Mean Execution Time (± Std Dev)\nLower is better", fontsize=13, fontweight="bold")

for bar, mean, std in zip(bars, means, stddevs):
  height = bar.get_height()
  ax1.text(
    bar.get_x() + bar.get_width() / 2.0,
    height + std + 0.015,
    f"{mean:.3f} s\n(±{std*1000:.1f} ms)",
    ha="center",
    va="bottom",
    fontsize=10,
    fontweight="bold"
  )

box = ax2.boxplot(
  all_times, 
  labels=labels, 
  patch_artist=True, 
  widths=0.4,
  medianprops=dict(color="black", linewidth=2),
  boxprops=dict(linewidth=1.2),
  whiskerprops=dict(linewidth=1.2),
  capprops=dict(linewidth=1.2)
)

for patch, color in zip(box["boxes"], colors):
  patch.set_facecolor(color)
  patch.set_alpha(0.6)

for i, times in enumerate(all_times):
  x = np.random.normal(i + 1, 0.04, size=len(times))
  ax2.plot(x, times, "o", color="black", alpha=0.7, markersize=5)

ax2.set_ylim(y_min, y_max)
ax2.set_ylabel("Execution Time (seconds)", fontsize=12, fontweight="bold")
ax2.set_title("Run-to-Run Distribution (10 runs)", fontsize=13, fontweight="bold")

fig.suptitle(
  f"Game of Life Benchmark: Friday vs. C (Clang)\nDelta: +{delta_ms:.1f} ms (+{overhead_pct:.2f}%)",
  fontsize=14, 
  fontweight="bold", 
  y=1.03
)

plt.tight_layout()
plt.savefig("benchmark_comparison.png", bbox_inches="tight")
plt.show()

print(f"Plot saved as 'benchmark_comparison.png'")
print(f"C Mean:      {means[0]:.4f} s")
print(f"Friday Mean: {means[1]:.4f} s")
print(f"Difference:  +{delta_ms:.2f} ms (+{overhead_pct:.2f}%)")