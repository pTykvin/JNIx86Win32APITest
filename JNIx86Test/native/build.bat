:g++ -c -pipe -fno-keep-inline-dllexport -O2 -std=c++0x -frtti -O0 -Wall -Wextra -fexceptions -mthreads -DUNICODE -IWin32HelloWorld -I. -I"C:\Program Files (x86)\Java\jdk1.8.0_60\include" -I"C:\Program Files (x86)\Java\jdk1.8.0_60\include\win32" -IC:\Qt\5.5\mingw492_32\mkspecs\win32-g++  -o main.o Win32HelloWorld\main.cpp
:g++ -Wl,-s -Wl,--kill-at -shared -Wl,-subsystem,console -mthreads -Wl,--out-implib,liblibWindow.a -o ../lib/libWindow.dll main.o

:del "../lib/libWindow.dll"

:g++ -I"%JAVA_HOME_X86%\include" -I"%JAVA_HOME_X86%\include\win32" -O0 -Wall -c -oMain.o Win32HelloWorld/main.cpp
:g++ -Wl,--kill-at -shared -Wl,-s -o../lib/libWindow.dll Main.o

:-Wl,--kill-at -shared
:C:\Ruby22-x64\bin;C:\ProgramData\Oracle\Java\javapath;%SystemRoot%\system32;%SystemRoot%;%SystemRoot%\System32\Wbem;%SYSTEMROOT%\System32\WindowsPowerShell\v1.0\;D:\Program Files\gradle-1.11\bin;C:\Program Files (x86)\scala\bin;C:\Program Files (x86)\scala\bin;D:\MinGW\bin;C:\Program Files (x86)\NSIS\Bin;C:\Program Files\Java\jdk1.8.0_40\bin;C:\Program Files\TortoiseHg\;D:\Qt\5.5\mingw492_32\bin

:C:\Qt\5.5\mingw492_32\bin\uic.exe QTHelloWorld\mainwindow.ui -o ui_mainwindow.h
:g++ -c -pipe -fno-keep-inline-dllexport -O2 -frtti -Wall -Wextra -fexceptions -mthreads -DUNICODE -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -DQT_NEEDS_QMAIN -IQTHelloWorld -I. -IC:\Qt\5.5\mingw492_32\include -IC:\Qt\5.5\mingw492_32\include\QtWidgets -IC:\Qt\5.5\mingw492_32\include\QtGui -IC:\Qt\5.5\mingw492_32\include\QtANGLE -IC:\Qt\5.5\mingw492_32\include\QtCore -Irelease -I. -I"C:\Program Files (x86)\Java\jdk1.8.0_60\include" -I"C:\Program Files (x86)\Java\jdk1.8.0_60\include\win32" -IC:\Qt\5.5\mingw492_32\mkspecs\win32-g++  -o main.o QTHelloWorld\main.cpp
:g++ -c -pipe -fno-keep-inline-dllexport -O2 -frtti -Wall -Wextra -fexceptions -mthreads -DUNICODE -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -DQT_NEEDS_QMAIN -IQTHelloWorld -I. -IC:\Qt\5.5\mingw492_32\include -IC:\Qt\5.5\mingw492_32\include\QtWidgets -IC:\Qt\5.5\mingw492_32\include\QtGui -IC:\Qt\5.5\mingw492_32\include\QtANGLE -IC:\Qt\5.5\mingw492_32\include\QtCore -Irelease -I. -I"C:\Program Files (x86)\Java\jdk1.8.0_60\include" -I"C:\Program Files (x86)\Java\jdk1.8.0_60\include\win32" -IC:\Qt\5.5\mingw492_32\mkspecs\win32-g++  -o mainwindow.o QTHelloWorld\mainwindow.cpp
:C:\Qt\5.5\mingw492_32\bin\moc.exe -DUNICODE -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -DQT_NEEDS_QMAIN -D__GNUC__ -DWIN32 -IC:/Qt/5.5/mingw492_32/mkspecs/win32-g++ -ID:/SVNAll/JNIx86Win32APITest/JNIx86Test/native/QTHelloWorld -IC:/Qt/5.5/mingw492_32/include -IC:/Qt/5.5/mingw492_32/include/QtWidgets -IC:/Qt/5.5/mingw492_32/include/QtGui -IC:/Qt/5.5/mingw492_32/include/QtANGLE -I"C:\Program Files (x86)\Java\jdk1.8.0_60\include" -I"C:\Program Files (x86)\Java\jdk1.8.0_60\include\win32" -IC:/Qt/5.5/mingw492_32/include/QtCore -I. QTHelloWorld\mainwindow.h -o moc_mainwindow.cpp
:g++ -c -pipe -fno-keep-inline-dllexport -O2 -frtti -Wall -Wextra -fexceptions -mthreads -DUNICODE -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -DQT_NEEDS_QMAIN -IQTHelloWorld -I. -IC:\Qt\5.5\mingw492_32\include -IC:\Qt\5.5\mingw492_32\include\QtWidgets -IC:\Qt\5.5\mingw492_32\include\QtGui -IC:\Qt\5.5\mingw492_32\include\QtANGLE -IC:\Qt\5.5\mingw492_32\include\QtCore -Irelease -I. -I"C:\Program Files (x86)\Java\jdk1.8.0_60\include" -I"C:\Program Files (x86)\Java\jdk1.8.0_60\include\win32" -IC:\Qt\5.5\mingw492_32\mkspecs\win32-g++  -o moc_mainwindow.o moc_mainwindow.cpp
:g++ -Wl,--kill-at -shared -Wl,-s -Wl,-subsystem,windows -mthreads -o C:\Qt\5.5\mingw492_32\bin\libHelloQT.dll main.o mainwindow.o moc_mainwindow.o  -lmingw32 -LC:/Qt/5.5/mingw492_32/lib -lqtmain -lshell32 -lQt5Widgets -lQt5Gui -lQt5Core


SET qtPath=D:\Qt\5.5
SET javaInclude=C:/Program Files (x86)/Java/jdk1.8.0_60/include
SET projRoot=D:/SVNAll/JNIx86Win32APITest/JNIx86Test/native/

g++ -c -std=c++11 -pipe -fno-keep-inline-dllexport -O2 -frtti -Wall -Wextra -fexceptions -mthreads -DUNICODE -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -DQT_NEEDS_QMAIN -IView -I. -I"%javaInclude%\win32" -I"%javaInclude%" -I%qtPath%\mingw492_32\include -I%qtPath%\mingw492_32\include\QtWidgets -I%qtPath%\mingw492_32\include\QtGui -I%qtPath%\mingw492_32\include\QtANGLE -I%qtPath%\mingw492_32\include\QtCore -Irelease -I. -I"%javaInclude%" -o main.o View\main.cpp
g++ -c -std=c++11 -Wreturn-type -pipe -fno-keep-inline-dllexport -O2 -frtti -Wall -Wextra -fexceptions -mthreads -DUNICODE -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -DQT_NEEDS_QMAIN -IView -I. -I"%javaInclude%\win32" -I"%javaInclude%" -I%qtPath%\mingw492_32\include -I%qtPath%\mingw492_32\include\QtWidgets -I%qtPath%\mingw492_32\include\QtGui -I%qtPath%\mingw492_32\include\QtANGLE -I%qtPath%\mingw492_32\include\QtCore -Irelease -I. -I%qtPath%\mingw492_32\mkspecs\win32-g++  -o widget.o View\widget.cpp
g++ -Wunused-parameter -c -pipe -fno-keep-inline-dllexport -O2 -frtti -Wall -Wextra -fexceptions -mthreads -DUNICODE -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -DQT_NEEDS_QMAIN -IView -I. -I"%javaInclude%\win32" -I"%javaInclude%" -I%qtPath%\mingw492_32\include -I%qtPath%\mingw492_32\include\QtWidgets -I%qtPath%\mingw492_32\include\QtGui -I%qtPath%\mingw492_32\include\QtANGLE -I%qtPath%\mingw492_32\include\QtCore -Irelease -I. -I%qtPath%\mingw492_32\mkspecs\win32-g++  -o qgtile.o View\qgtile.cpp
g++ -c -pipe -fno-keep-inline-dllexport -O2 -frtti -Wall -Wextra -fexceptions -mthreads -DUNICODE -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -DQT_NEEDS_QMAIN -IView -I. -I"%javaInclude%\win32" -I"%javaInclude%" -I%qtPath%\mingw492_32\include -I%qtPath%\mingw492_32\include\QtWidgets -I%qtPath%\mingw492_32\include\QtGui -I%qtPath%\mingw492_32\include\QtANGLE -I%qtPath%\mingw492_32\include\QtCore -Irelease -I. -I%qtPath%\mingw492_32\mkspecs\win32-g++  -o qgmenu.o View\qgmenu.cpp
%qtPath%\mingw492_32\bin\moc.exe -DUNICODE -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -DQT_NEEDS_QMAIN -D__GNUC__ -DWIN32 -I%qtPath%/mingw492_32/mkspecs/win32-g++ -I%projRoot%View -I"%javaInclude%/win32" -I"%javaInclude%" -I%qtPath%/mingw492_32/include -I%qtPath%/mingw492_32/include/QtWidgets -I%qtPath%/mingw492_32/include/QtGui -I%qtPath%/mingw492_32/include/QtANGLE -I%qtPath%/mingw492_32/include/QtCore -I. View\widget.h -o moc_widget.cpp
g++ -c -pipe -fno-keep-inline-dllexport -O2 -frtti -Wall -Wextra -fexceptions -mthreads -DUNICODE -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -DQT_NEEDS_QMAIN -IView -I. -I"%javaInclude%\win32" -I"%javaInclude%" -I%qtPath%\mingw492_32\include -I%qtPath%\mingw492_32\include\QtWidgets -I%qtPath%\mingw492_32\include\QtGui -I%qtPath%\mingw492_32\include\QtANGLE -I%qtPath%\mingw492_32\include\QtCore -Irelease -I. -I%qtPath%\mingw492_32\mkspecs\win32-g++  -o moc_widget.o moc_widget.cpp
g++ -Wl,--kill-at -shared -Wl,-s -Wl,-subsystem,windows -shared -mthreads -o %qtPath%\mingw492_32\bin\libQtView.dll main.o widget.o qgtile.o qgmenu.o moc_widget.o  -lmingw32 -L%qtPath%/mingw492_32/lib -lqtmain -lshell32 -lQt5Widgets -lQt5Gui -lQt5Core