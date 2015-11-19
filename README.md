# MWC-rand-gen

Standard input params:
```
k
m
a0
a1
..
ak-1
mwc0
mwc1
..
mwck-1
a-b
```


where `k`, `m` are generator params, `a0 .. ak-1` are k coefficients, `mwc0 .. mwck-1` are k first elements of sequence (should be taken from a random generator) and `a-b` is the range of which sequence elements to render (inclusive)
Example params are in the `test.txt` file. 
