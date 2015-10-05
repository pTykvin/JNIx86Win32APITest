package ru.tykvin.jni.nativeinvokers;

public abstract class NativeLibrary {

    //public static final HelloWorld HELLO = new HelloWorld();
    //public static final Win32HelloWorld HELLO_WIN32 = new Win32HelloWorld();
    //public static final QTHelloWorld QT = new QTHelloWorld();

    public static final QTViewHelloWorld QT_VIEW = new QTViewHelloWorld();

    protected abstract String getName();

    public NativeLibrary () {
        System.loadLibrary(getName());
    }


}
