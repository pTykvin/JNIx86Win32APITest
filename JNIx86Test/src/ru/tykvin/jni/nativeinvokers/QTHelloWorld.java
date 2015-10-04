package ru.tykvin.jni.nativeinvokers;

public class QTHelloWorld extends NativeLibrary {

    @Override
    protected String getName() {
        return "libHelloQt";
    }

    public native void showWindow();

    public native void addButton();

    public native void close();
}
