# shuffle
Fast (and simple) one pass shuffler of binpacks as long as the record size is 40 bytes.

OPERATION
1. Organize the filenames in lines 7-13 of shuffle.cpp and compile.
2. Either run the tool directly from Visual Studio : Debug -> Start without debugging or run shuffle.exe
3. During Phase-1 the binpack files will be divided into temp files.
4. During Phase-2 the temp files will be merged into one big file. 
5. If Phase-2 is not needed because you are happy with the generated shuffled temp binpack files just abort the tool.

<pre>
BENCHMARK HDD  [AMD Ryzen 5 3600]
File   Size    Positions    Phase-1  Phase-2
test  23.8Gb  640.921.471

BENCHMARK SSD  [AMD Ryzen 5 3600]
File   Size    Positions    Phase-1  Phase-2
test  23.8Gb  640.921.471    4:00     7:47

</pre>
