package ru.tykvin.jni.nativeinvokers;

public class Win32HelloWorld extends NativeLibrary {
    @Override
    protected String getName() {
        return "libWindow";
    }

    public native int getForegroundHwnd();

    public native void showWindow();
}
