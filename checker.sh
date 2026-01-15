for ((i = 1; ; ++i)); do
    echo $i
    ./gen $i > in.txt
    diff -w <(./e < in.txt) <(./bruteForce < in.txt) || break
done

# This program will run in.txt input to a.cpp and b.cpp. Whenever 
# for any test case, output differs, it will break in that test case.
# you will get that input file(for which it breaks) in the in.txt file.

# here "a" is the main code and "b" is the bruteforce code. in.txt is
# the file name where the output will be saved. 

