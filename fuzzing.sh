export AFL_I_DONT_CARE_ABOUT_MISSING_CRASHES=1
export AFL_NO_UI=1

timeout --preserve-status 10s make fuzz

if ! [ -z "$(ls -A ./out/hangs)" ] || ! [ -z "$(ls -A ./out/crashes)" ]; then   
    if ! [ -z "$(ls -A ./out/hangs)" ]; then
        echo "hangs"
        find ./out/hangs -maxdepth 1 -type f -not -name 'README.txt' -exec cat {} \;
    fi

    if ! [ -z "$(ls -A ./out/crashes)" ]; then
        echo "crashes"
        find ./out/crashes -maxdepth 1 -type f -not -name 'README.txt' -exec cat {} \;
    fi

    exit 1
fi