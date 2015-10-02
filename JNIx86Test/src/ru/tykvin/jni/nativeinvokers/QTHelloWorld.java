package ru.tykvin.jni.nativeinvokers;

import ru.tykvin.jni.NativeLibrary;

public class QTHelloWorld extends NativeLibrary {

    public native void showWindow();

    @Override
    protected String getName() {
        return "libHelloQt";
    }
}
