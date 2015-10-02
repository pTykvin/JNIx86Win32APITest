package ru.tykvin.jni;

public class Main {
    public static void main(String[] args) {

        System.out.println("Show message...");
        NativeLoader.HELLO.sayHello();
        System.out.println("...hide message");
        //NativeLoader.QT.showWindow();
        //NativeLoader.QT.showWindow();
    }
}
