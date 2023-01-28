export AFL_I_DONT_CARE_ABOUT_MISSING_CRASHES=1

timeout --preserve-status 5m make fuzz

if [[ "$(ls -A ./out/hangs)"]] || [["$(ls -A ./out/crashes)" ]]
    then 
        if [ "$(ls -A ./out/hangs)"]
            then
                echo "hangs"
                find ./out/hangs -maxdepth 1 -type f -not -name 'README.txt' -exec cat {} \;
        fi

        if [ "$(ls -A ./out/crashes)" ]
            then
                echo "chrashes"
                find ./out/crashes  -maxdepth 1 -type f -not -name 'README.txt' -exec cat {} \;
        fi

        exit 1
fi