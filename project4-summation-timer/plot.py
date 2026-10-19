import argparse

import matplotlib.pyplot as plt
import pandas as pd

parser = argparse.ArgumentParser()
parser.add_argument('input')
parser.add_argument('output')
parser.add_argument('--logorithmic', action='store_true')

args = parser.parse_args()

df = pd.read_csv(args.input)

fig, ax = plt.subplots()

if args.logorithmic:
    ax.set_yscale('log')

ax.plot(df["n"], df["constant time (ns)"], label="constant")
ax.plot(df["n"], df["linear time (ns)"], label="linear")
ax.plot(df["n"], df["quadratic time (ns)"], label="quadratic")
ax.legend()

ax.set(xlabel="input size", ylabel="time (ns)", title="input size vs computation time")
ax.grid()

fig.savefig(args.output)
