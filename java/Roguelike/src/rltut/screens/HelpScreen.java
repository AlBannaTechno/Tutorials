package rltut.screens;

import java.awt.event.KeyEvent;

import asciiPanel.AsciiPanel;

public class HelpScreen implements Screen {
    public void displayOutput(AsciiPanel terminal) {
        terminal.clear();
        terminal.writeCenter("Roguelike Help", 1);
        terminal.write(
                "Descend the Caves of Slight Danger! Find the lost Teddy Bear! And return to",
                1, 3);
        terminal.write("the surface to win! Use what you find to avoid dying.", 1, 4);

        int y = 6;
        terminal.write("[?] for help", 2, y++);
        terminal.write("[g] or [,] to pick up", 2, y++);
        terminal.write("[d] to drop", 2, y++);
        terminal.write("[e] to eat", 2, y++);
        terminal.write("[w] to wear or wield", 2, y++);
        terminal.write("[f] to fire ranged weapon", 2, y++);
        terminal.write("[t] to throw", 2, y++);
        terminal.write("[x] to examine your items", 2, y++);
        terminal.write("[;] to look around", 2, y);

        terminal.writeCenter("-- Press any key to continue --", 22);
    }

    public Screen respondToUserInput(KeyEvent key) {
        return null;
    }
}
