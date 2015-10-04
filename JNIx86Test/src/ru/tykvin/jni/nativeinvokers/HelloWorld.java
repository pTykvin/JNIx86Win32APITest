package ru.tykvin.jni.nativeinvokers;

public class HelloWorld extends NativeLibrary {

    @Override
    protected String getName() {
        return "libHello";
    }

    public native void sayHello();
}
