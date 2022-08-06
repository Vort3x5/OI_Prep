python3 Gen.py $1

for ((i = 1; i <= $1; ++i))
do
    ./out < ./In/Inpts$i.in
done
