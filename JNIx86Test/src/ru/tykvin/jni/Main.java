package ru.tykvin.jni;

import ru.tykvin.jni.nativeinvokers.NativeLibrary;

public class Main {
    public static void main(String[] args) {

        System.out.println("Show message...");
        NativeLibrary.QT.showWindow();
        //System.out.println("hwnd = " + NativeLoader.HELLO_WIN32.getForegroundHwnd());
        System.out.println("...hide message");
        //NativeLoader.QT.showWindow();
        //NativeLoader.QT.showWindow();
    }
}
