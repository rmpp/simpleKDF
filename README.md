KDF
=======

Simple key derivation fuction.
---------------

KDF = F(SK,(CTX||0)) || F(SK,(CTX||1)) .... F(SK,(CTX||n))

---
F- PRF - pseudo random funtion - AES 128 

SK- Source key - sampled from a purely random number generator

CTX- Context - simple "string" dependent of the aplication, and different from each one

n - Number of runs (each run produce 128 bits)

----

