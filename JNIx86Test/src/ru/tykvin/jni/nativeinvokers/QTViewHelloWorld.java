package ru.tykvin.jni.nativeinvokers;

import java.util.ArrayList;
import java.util.List;

import ru.tykvin.jni.TileListener;

public class QTViewHelloWorld extends NativeLibrary implements TileListener {

    @Override
    protected String getName() {
        return "libQtView";
    }

    public native void showView();

    public native void addTile(String tileName);

    public native void close();

    private List<TileListener> listeners = new ArrayList<>();

    public QTViewHelloWorld addListener(TileListener listener){
        listeners.add(listener);
        return this;
    }

    public QTViewHelloWorld removeListener(TileListener listener) {
        listeners.remove(listener);
        return this;
    }

    @Override
    public void tilePressed(String string) {
        listeners.forEach(l -> l.tilePressed(string));
    }

}
