package rltut;

import java.awt.Color;

public class Item {
    private String name;
    public String name() { return name; }

    private char glyph;
    public char glyph() { return glyph; }

    private Color color;
    public Color color() { return color; }

    private int foodValue;
    public int foodValue() { return foodValue; }
    public void modifyFoodValue(int amount) { foodValue += amount; }

    private int attackValue;
    public int attackValue() { return attackValue; }
    public void modifyAttackValue(int amount) { attackValue += amount; }

    private int rangedAttackValue;
    public int rangedAttackValue() { return rangedAttackValue; }
    public void modifyRangedAttackValue(int amount) { rangedAttackValue += amount; }

    private int thrownAttackValue;
    public int thrownAttackValue() { return thrownAttackValue; }
    public void modifyThrownAttackValue(int amount) { thrownAttackValue += amount; }

    private int defenseValue;
    public int defenseValue() { return defenseValue; }
    public void modifyDefenseValue(int amount) { defenseValue += amount; }

    public Item(String name, char glyph, Color color) {
        this.name = name;
        this.glyph = glyph;
        this.color = color;
    }

    public String details() {
        String details = "";

        if (attackValue != 0)
            details += "     attack: " + attackValue;

        if (thrownAttackValue != 0)
            details += "     throwing attack: " + thrownAttackValue;

        if (defenseValue != 0)
            details += "     defense: " + defenseValue;

        if (foodValue != 0)
            details += "     food: " + foodValue;

        return details;
    }
}
