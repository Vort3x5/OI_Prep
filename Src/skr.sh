g++ -std=c++17 ./Main.cpp -o wzor
g++ -std=c++17 ./Brut.cpp -o brut
g++ -std=c++17 ./gen.cpp -o gen

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
