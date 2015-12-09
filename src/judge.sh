#!/bin/bash
function run()
{
    echo -n "Running on test 1...  verdict:"
    ./sim bimodal 7 0 0 ../traces/gcc_trace.txt  > ../results/DebugRun1.txt
    diff ../results/DebugRun1.txt ../validation/val_bimodal_1.txt
    if [ "${?}" == "0" ]
        then
            echo "OK"
    fi

    echo -n "Running on test 2...  verdict:"
    ./sim bimodal 10 0 0 ../traces/gcc_trace.txt   > ../results/DebugRun2.txt
    diff ../results/DebugRun2.txt ../validation/val_bimodal_2.txt
    if [ "${?}" == "0" ]
        then
            echo "OK"
    fi

    echo -n "Running on test 3...  verdict:"
    ./sim bimodal 5 0 0 ../traces/jpeg_trace.txt > ../results/DebugRun3.txt
    diff ../results/DebugRun3.txt ../validation/val_bimodal_3.txt
    if [ "${?}" == "0" ]
        then
            echo "OK"
    fi

    echo -n "Running on test 4...  verdict:"
    ./sim bimodal 6 0 0 ../traces/perl_trace.txt  > ../results/DebugRun4.txt
    diff ../results/DebugRun4.txt ../validation/val_bimodal_4.txt
    if [ "${?}" == "0" ]
        then
            echo "OK"
    fi

    echo -n "Running on test 5...  verdict:"
    ./sim gshare 10 4 0 0 ../traces/gcc_trace.txt > ../results/DebugRun5.txt
    diff ../results/DebugRun5.txt ../validation/val_gshare_1.txt
    if [ "${?}" == "0" ]
        then
            echo "OK"
    fi

    echo -n "Running on test 6...  verdict:"
    ./sim gshare 14 9 0 0 ../traces/gcc_trace.txt > ../results/DebugRun6.txt
    diff ../results/DebugRun6.txt ../validation/val_gshare_2.txt
    if [ "${?}" == "0" ]
        then
            echo "OK"
    fi

    echo -n "Running on test 7...  verdict:"
    ./sim gshare 11 5 0 0 ../traces/jpeg_trace.txt  > ../results/DebugRun7.txt
    diff ../results/DebugRun7.txt ../validation/val_gshare_3.txt
    if [ "${?}" == "0" ]
        then
            echo "OK"
    fi

    echo -n "Running on test 8...  verdict:"
    ./sim gshare 10 6 0 0 ../traces/perl_trace.txt   > ../results/DebugRun8.txt
    diff ../results/DebugRun8.txt ../validation/val_gshare_4.txt
    if [ "${?}" == "0" ]
        then
            echo "OK"
    fi
}

make clean && make

mkdir -p ../results

run
echo "All done."
exit 0

