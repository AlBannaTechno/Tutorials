package rltut;

public class FungusAi extends CreatureAi {
    private StuffFactory factory;
    private int spreadCount;

    public FungusAi(Creature creature, StuffFactory factory) {
        super(creature);
        this.factory = factory;
    }

    @Override
    public void onUpdate() {
        if (spreadCount < 3 && Math.random() < 0.01)
            spread();
    }

    public void spread() {
        int x = creature.x + (int)(Math.random() * 11) - 5;
        int y = creature.y + (int)(Math.random() * 11) - 5;

        if (!creature.canEnter(x, y, creature.z))
            return;

        creature.doAction("spawn a child");

        Creature child = factory.newFungus(creature.z);
        child.x = x;
        child.y = y;
        child.z = creature.z;
        spreadCount++;
    }
}
