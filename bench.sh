#!/bin/bash

ALGORITHMS=("insertion" "merge" "quick")
# ALGORITHMS=("merge2" "merge3")
SIZES=(10 30 50 100 500 1000 10000 100000 1000000 10000000)

echo "algorithm,size,random_time,partial_random1_time,partial_random2_time"

for algo in "${ALGORITHMS[@]}"; do
  for size in "${SIZES[@]}"; do
    OUTPUT=$(./sort $algo $size)

    random_time=$(echo "$OUTPUT" | grep "random array:" | awk '{print $(NF-1)}')
    partial1_time=$(echo "$OUTPUT" | grep "partial random array1:" | awk '{print $(NF-1)}')
    partial2_time=$(echo "$OUTPUT" | grep "partial random array2:" | awk '{print $(NF-1)}')

    echo "$algo,$size,$random_time,$partial1_time,$partial2_time"
  done
done
