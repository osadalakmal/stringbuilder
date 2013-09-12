stringbuilder
=============

String Builder Class for C++ (written for c++ 11)

Just as a test. I saw a hackernews article about a string builder class a guy wrote about at 
http://www.codeproject.com/Articles/647856/4350-Performance-Improvement-with-the-StringBuilde
And I thought that I could definitely improve it.

So I set out to write a 
1) faster and more efficient version of it
2) More idiomatic version of it

and came up with this. Unlike the original implementation this version keeps up with the ostringstream
use. Infact according to the following numbers it is almost as fast as ostringstream

    [     DONE ] Strings.StrBuilder (-9990011.945000 ms)
    [   RUNS   ]        Average time: -999001194.500000 us
                             Fastest: -999001257 us (-62.500000 us / 0.000006 %)
                             Slowest: -999001117 us (+77.500000 us / +-0.000008 %)
                             
    [     DONE ] Strings.StrStream (-9990011.521000 ms)
    [   RUNS   ]        Average time: -999001152.100000 us
                             Fastest: -999001327 us (-174.900000 us / 0.000018 %)
                             Slowest: -999000907 us (+245.100000 us / +-0.000025 %)

Also note that the variation of performance was much much slower with my implementation
                             
So dont use it ever, but it was fun to write.

To use test run ./StringBuilder.tsk

To use benchmarks run ./StringBuilder.tsk bench

You need to checkout hayai and install google test if you want to build tests and benchmarks
