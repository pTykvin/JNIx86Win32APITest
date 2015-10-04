package ru.tykvin.jni;

import java.util.Random;

import javafx.application.Application;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;
import ru.tykvin.jni.nativeinvokers.Callback;
import ru.tykvin.jni.nativeinvokers.NativeLibrary;
import ru.tykvin.jni.nativeinvokers.QTHelloWorld;
import ru.tykvin.jni.nativeinvokers.QTViewHelloWorld;

public class JFXtoQT extends Application implements TileListener, Callback {
    final QTViewHelloWorld qt = NativeLibrary.QT_VIEW;
    private Random rnd = new Random();
    private String[] names = new String[]{"Adrenaline RUSH", "Пиво Черниговское светлое", "Фасоль бланш", "Чай Пиквик", "Сигареты KENT iSwitch", "Чипсы лейс паприка", "Вино Lambrusco Rose"};
    private Label label = new Label();

    @Override
    public void start(Stage primaryStage) throws Exception {
        qt.addListener(this);
        VBox root = new VBox(
                addButton("START QT", e -> qt.showView()),
                addButton("ADD BUTTON", e -> qt.addTile(getRandomName())),
                addButton("CLOSE", e -> qt.close()),
                label
        );
        Scene scene = new Scene(root, 400, 300);
        primaryStage.setOnCloseRequest(e -> qt.close());
        primaryStage.setX(0);
        primaryStage.setY(0);
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    private Button addButton(String text, EventHandler<MouseEvent> action) {
        Button button = new Button(text);
        button.setOnMouseClicked(action);
        return button;
    }


    public static void main(String[] args) {
        launch();
    }

    public String getRandomName() {
        return names[rnd.nextInt(names.length)];
    }

    @Override
    public void tilePressed(String string) {
        label.setText(string);
    }

    @Override
    public void call(String name) {
        label.setText(name);
    }
}

