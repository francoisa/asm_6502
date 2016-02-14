# mru_cache
A c++ based assembler for the 6502 instruction set

http://e-tradition.net/bytes/6502/6502_instruction_set.html

You can get test data at:
http://e-tradition.net/bytes/6502/assembler.html

A sample assembly program would be:
LDA $1000    AD 00 10
CLC                 18
ADC $1002    6D 02 10
STA $1004    8D 04 10
LDA $1001    AD 01 10
ADC $1003    6D 03 10
STA $1005    8D 05 10
