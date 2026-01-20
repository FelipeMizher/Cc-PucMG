package aeds3;

public interface Entidade {
    public int getID();
    public void setID(int id);
    public byte[] toByteArray() throws Exception;
    public void fromByteArray(byte[] vb) throws Exception;
}
