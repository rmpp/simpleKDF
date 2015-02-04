KDF
=======

Simple implementation of a key derivation fuction,
---------------


KDF = F(SK,(CTX||0)) || F(SK,(CTX||1)) .... F(SK,(CTX||n))
 
SK- source key
CTX- contex - simple "string" dependent of the aplication, and diferent from each one
n - numer of runs (each run produce 128 bits)

----

