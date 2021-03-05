package ro.ase.acs.services;

import ro.ase.acs.main.IoC;
import ro.ase.acs.writers.Writeable;
import ro.ase.acs.readers.Readable;

public class Orchestrator
{
    private Readable reader;
    private Writeable writer;

    public Orchestrator(Readable reader, Writeable writer)
    {
        this.reader = reader;
        this.writer = writer;
    }

    public Orchestrator(IoC ioC)
    {
        this.reader = ioC.resolve(Readable.class);
        this.writer = ioC.resolve(Writeable.class);
    }

    public void execute()
    {
        writer.write(reader.read());
    }


}
