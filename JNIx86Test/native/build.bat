g++ -I"%JAVA_HOME_X86%\include" -I"%JAVA_HOME_X86%\include\win32" -O0 -Wall -c -oMain.o main.cpp
g++ -Wl,--kill-at -shared -o../lib/libHello.dll Main.o