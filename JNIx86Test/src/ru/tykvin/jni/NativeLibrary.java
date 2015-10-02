package ru.tykvin.jni;

public abstract class NativeLibrary {

    protected abstract String getName();

    public NativeLibrary () {
        System.loadLibrary(getName());
    }

}
