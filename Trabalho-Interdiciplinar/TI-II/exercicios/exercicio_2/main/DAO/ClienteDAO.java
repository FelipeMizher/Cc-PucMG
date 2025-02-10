package DAO;

public class ClienteDAO extends DAO{
	public ClienteDAO(){
		super();
		conectar();
	}
	
	public void finaliza(){
		close();
	}
	
	public boolean insert(Cliente cliente){
		boolean status = false;
		
		try{
			Statement st = conexao.createStatement();
			String sql = "INSERT INTO Clientes (codigo, nome, email, idade) "
			+ "VALUES ("+cliente.getCodigo()+ ", '" + cliente.getNome() + "', '"
			+ cliente.getEmail() + "', '" + cliente.getIdade() + "');";
			System.out.println(sql);
			st.executeUpdate(sql);
			st.close();
			status = true;
		} catch(SQLException u){
			throw new RuntimeException(u);
		}
			return status;
		}
	
	public List<Cliente> getAll(){
		List<Cliente> clientes = new ArrayList<>();
		
		try{
			Statement st = conexao.createStatement(ResultSet.TYPE_SCROLL_INSENSITIVE, ResultSet.CONCUR_READ_ONLY);
			String sql = "SELECT * FROM Clientes";
			System.out.println(sql);
			ResultSet rs = st.executeQuery(sql);
			while(rs.next()){
				Cliente cliente = new Cliente(rs.getInt("codigo"), rs.getString("nome"), rs.getString("email"), rs.getInt("idade"));
				clientes.add(cliente);
			}
			st.close();
		} catch(Exception e){
			System.out.println(e.getMessage());
		}
			return clientes;
		}
	
	public boolean delete(int codigo){
		boolean status = false;
		
		try{
			Statement st = conexao.createStatement();
			String sql = "DELETE FROM Clientes WHERE codigo = " + codigo;
			System.out.println(sql);
			st.executeUpdate(sql);
			st.close();
			status = true;
		} catch(SQLException u){
			throw new RuntimeException(u);
		}
		return status;
	}
	
	public Cliente getByCodigo(int codigo){
		Cliente cliente = null;
		
		try{
			Statement st = conexao.createStatement(ResultSet.TYPE_SCROLL_INSENSITIVE, ResultSet.CONCUR_READ_ONLY);
			String sql = "SELECT * FROM Clientes where codigo = " + codigo;
			System.out.println(sql);
			ResultSet rs = st.executeQuery(sql);
			if (rs.next()){
				cliente = new Cliente(rs.getInt("codigo"), rs.getString("nome"), rs.getString("email"), rs.getInt("idade"));
			}
			st.close();
		} catch(Exception e){
			System.err.println(e.getMessage());
		}
		return cliente;
	}
	
	
	public boolean update(Cliente cliente){
		boolean status = false;
		
		try{
			Statement st = conexao.createStatement();
			String sql = "UPDATE Clientes SET codigo = '" + cliente.getCodigo() + "', nome = '"
			+ cliente.getNome() + "', email = '" + cliente.getEmail() + "'"
			+ " WHERE codigo = " + cliente.getCodigo();
			System.out.println(sql);
			st.executeUpdate(sql);
			st.close();
			status = true;
		} catch(SQLException u){
			throw new RuntimeException(u);
		}
		return status;
	}
}
