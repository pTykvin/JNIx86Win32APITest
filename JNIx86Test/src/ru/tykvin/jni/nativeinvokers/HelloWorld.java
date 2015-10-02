package ru.tykvin.jni.nativeinvokers;

import ru.tykvin.jni.NativeLibrary;

public class HelloWorld extends NativeLibrary {

    public native void sayHello();

    @Override
    protected String getName() {
        return "untitled";
    }
}
