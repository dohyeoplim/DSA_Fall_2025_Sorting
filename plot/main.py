import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

def plot(path="bench/bench_result_base.csv"):
    df = pd.read_csv(path)

    sns.set_theme(style="whitegrid", context="talk")
    fig, axes = plt.subplots(1, 3, figsize=(18, 6), sharey=True)

    benchmarks = {
        "random_time": "Random Array",
        "partial_random1_time": "Partial Random Array 1",
        "partial_random2_time": "Partial Random Array 2",
    }

    for ax, (col, title) in zip(axes, benchmarks.items()):
        sns.lineplot(
            data=df,
            x="size",
            y=col,
            hue="algorithm",
            marker="o",
            ax=ax
        )
        ax.set_xscale("log")
        ax.set_yscale("log")
        ax.set_title(title, fontsize=15, weight="bold")
        ax.set_xlabel("Array size (log scale)")
        ax.set_ylabel("Execution time (sec, log scale)")
        # ax.grid(True, which="both", linestyle="--", linewidth=0.7, alpha=0.7)

    plt.tight_layout()
    plt.savefig(f"bench/{path.split('/')[-1].split('.')[0]}.png", dpi=300)

def main():
    plot()
    plot("bench/bench_result_faster_merge_1.csv")
    plot("bench/bench_result_faster_merge_2.csv")

if __name__ == "__main__":
    main()
