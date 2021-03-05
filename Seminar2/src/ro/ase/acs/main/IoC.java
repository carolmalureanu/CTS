package ro.ase.acs.main;

import java.util.HashMap;
import java.util.Map;

public class IoC
{
    private Map<Class<?>, Class<?>> map = new HashMap<>();

    public void register(Class<?> contract, Class<?> implementation)
    {
        map.put(contract, implementation);
    }

    public <T> T resolve(Class<?> contract)
    {
        try
        {
            return (T) map.get(contract).newInstance();
        }
        catch (InstantiationException e)
        {
            e.printStackTrace();
        }
        catch (IllegalAccessException e)
        {
            e.printStackTrace();
        }

        return null;
    }

}
