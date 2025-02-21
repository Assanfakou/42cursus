#!/bin/bash

LIMIT=9999
case $1 in
    100) LIMIT=700 ;;
    5|4) LIMIT=12 ;;
    3) LIMIT=8 ;;
    2) LIMIT=3 ;;
    500) LIMIT=5500 ;;
esac

THREADS=4

run_test() {
    local elements=$1
    while true; do
        ARG=$(seq 1 "$elements" | sort -R)
        TMP=$(mktemp)
        ./push_swap $ARG > "$TMP"
        COUNT=$(wc -l < "$TMP")
        IS_SORTED=$(./checker_linux $ARG < "$TMP")
        rm "$TMP"
        echo "$COUNT -- $IS_SORTED"
        if (( COUNT > LIMIT )); then
            echo "Case: $ARG FAILED with $COUNT"
        fi
    done
}

for ((i=0; i<THREADS; i++)); do
    run_test "$1" &
done

wait
