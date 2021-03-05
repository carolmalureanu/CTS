package ro.ase.acs.main;

import ro.ase.acs.readers.ConsoleReader;
import ro.ase.acs.readers.Readable;
import ro.ase.acs.services.Orchestrator;
import ro.ase.acs.writers.ConsoleWriter;
import ro.ase.acs.writers.Writeable;

public class Main
{
    public static void main(String[] args)
    {
        IoC ioC = new IoC();

        ioC.register(Readable.class, ConsoleReader.class);
        ioC.register(Writeable.class, ConsoleWriter.class);

        Orchestrator orchestrator = new Orchestrator(ioC);
        orchestrator.execute();
    }

}
