g++ -g -std=c++17 Main.cpp -o main
g++ -g -std=c++17 Brut.cpp -o brut

let "a = 0"
for i in ./In/*.in;
do
    let "a += 1"
    ./brut < $i > ./Expected_Out/brut_res$a.out
    ./main < $i > ./Given_Out/opt_res$a.out
done

for ((i = 1; i <= $a; ++i))
do
    if ! diff -bq ./Expected_Out/brut_res$i.out ./Given_Out/opt_res$i.out &>/dev/null; then
        >&2 echo "Test $i: zle"
    else
        echo "Test $i: git"
    fi
done
