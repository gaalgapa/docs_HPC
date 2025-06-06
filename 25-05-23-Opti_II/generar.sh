parallel 'g++ -O{1} matmul_block.cpp -o {1}.x' ::: 0 1 2 3 fast
parallel './{2}.x 1024 {1} >> {2}.txt' ::: 32 64 128 512 1024 ::: 0 1 2 3 fast
for level in 0 1 2 3 fast; do sort -n ${level}.txt > ${level}-sorted.txt; done
#g++ -O{1} matmul.block.cpp -o ejecOPT{}.x
#./ejecOPT{1} 2048 {2} ::: 0 1 2 3 fast ::: 64 128 256 512 