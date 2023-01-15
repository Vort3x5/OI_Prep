g++ -std=c++17 -g ./Main.cpp -o wzor
g++ -std=c++17 -g ./Brut.cpp -o brut
g++ -std=c++17 -g ./gen.cpp -o gen

for ((i=1; i<=$1; i++)) do
    ./gen $i > ./in/test$i.in
done

for i  in ./in/*.in;
do
    echo $i
    ./wzor < $i > ./wzor.out
    ./brut < $i > ./brut.out
    if ! diff -bq ./wzor.out ./brut.out &>/dev/null; then
        >&2 echo "different"
        break
    fi
done
