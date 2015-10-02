package ru.tykvin.jni;

import java.io.File;

import org.apache.commons.lang.StringUtils;

import ru.tykvin.jni.nativeinvokers.HelloWorld;
import ru.tykvin.jni.nativeinvokers.QTHelloWorld;

public class NativeLoader {
    public static final HelloWorld HELLO = new HelloWorld();
    //public static final QTHelloWorld QT = new QTHelloWorld();
}
