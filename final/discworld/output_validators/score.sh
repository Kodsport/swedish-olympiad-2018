g++ -o joshua.out joshua.cpp
./joshua.out < ../data/secret/grupp1/1.in > 1.ans
g++ validator.cpp
./a.out ../data/secret/grupp1/1.in ../data/secret/grupp1/1.ans output/ < 1.ans
cat output/score.txt
