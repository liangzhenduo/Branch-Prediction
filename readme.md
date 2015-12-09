#Hint

If you got a compile error in Ubuntu, just try

`sudo apt-get install g++-4.8-multilib`

`sudo apt-get install libc6-dev-i386`

`sudo apt-get install build-essential`

and run `make clean && make` again.

#Validation

```
./sim bimodal 7 0 0 gcc_trace.txt	> DebugRun1.txt
diff DebugRun1.txt val_bimodal_1.txt
    
./sim bimodal 10 0 0 gcc_trace.txt	> DebugRun2.txt
diff DebugRun2.txt val_bimodal_2.txt
    
./sim bimodal 5 0 0 jpeg_trace.txt	> DebugRun3.txt
diff DebugRun3.txt val_bimodal_3.txt
    
./sim bimodal 6 0 0 perl_trace.txt	> DebugRun4.txt
diff DebugRun4.txt val_bimodal_4.txt
    
./sim gshare 10 4 0 0 gcc_trace.txt  > DebugRun5.txt
diff DebugRun5.txt val_gshare_1.txt
    
./sim gshare 14 9 0 0 gcc_trace.txt  > DebugRun6.txt
diff DebugRun6.txt val_gshare_2.txt

./sim gshare 11 5 0 0 jpeg_trace.txt > DebugRun7.txt
diff DebugRun7.txt val_gshare_3.txt

./sim gshare 10 6 0 0 perl_trace.txt > DebugRun8.txt
diff DebugRun8.txt val_gshare_4.txt
```