/*
================================================================================
|    PROJETO: Sistema de Cadastro de Funcionários                              |
|    LINGUAGEM: C#                                                             |
================================================================================
*/

namespace SistemaCadastro{
    // =======================================================================
    // 1. DEFININDO A CLASSE FUNCIONÁRIO
    // =======================================================================
    public class Funcionario{
        // --- PROPRIEDADES + GET + SET ---
        public int Id{ 
            get; 
            set; 
        }
        public string Nome{ 
            get; 
            set; 
        }
        public string Cargo{ 
            get; 
            set; 
        }
        public double Salario{ 
            get; 
            set; 
        }

        // --- CONSTRUTOR DA CLASSE FUNCIONARIO ---
        public Funcionario(int id, string nome, string cargo, double salario){
            Id = id;
            Nome = nome;
            Cargo = cargo;
            Salario = salario;
        }

        // --- MÉTODO PARA AUMENTAR O SALARIO DE ACORDO COM UMA PORCENTAGEM ---
        public void AumentarSalario(double porcentagem){
            if(porcentagem > 0){
                Console.WriteLine($"Salário de {Nome} atual: {Salario:C}");
                Salario += Salario * (porcentagem / 100);
                Console.WriteLine($"Salário de {Nome} aumentado para: {Salario:C}"); // O ':C' formata para moeda local (R$)
            }
        }

        // --- MÉTODO PARA MOSTRAR OS DADOS ---
        public override string ToString(){
            return $"ID: {Id} | Nome: {Nome} | Cargo: {Cargo} | Salário: {Salario:C}";
        }
    }

    // =======================================================================
    // 2. A ESTRUTURA DO PROGRAMA E INTERAÇÃO COM O USUÁRIO
    // =======================================================================
    class Seminario{
        // =======================================================================
        // 3. MÉTODOS AUXILIARES PARA OS FUNCIONARIOS
        // =======================================================================
        public static void AdicionarFuncionario(List<Funcionario> lista, ref int idAtual){
            Console.WriteLine("\n--- Adicionar Novo Funcionário ---");

            Console.Write("Nome: ");
            string nome = Console.ReadLine();

            Console.Write("Cargo: ");
            string cargo = Console.ReadLine();

            Console.Write("Salário: ");
            // Console.ReadLine() sempre retorna um tipo 'string'.
            // Precisamos converter para o tipo 'double' => 'double.TryParse'
            if(double.TryParse(Console.ReadLine(), out double salario)){
                Funcionario novoFuncionario = new Funcionario(idAtual, nome, cargo, salario); // Criando uma instancia do objeto.
                lista.Add(novoFuncionario);                                                   // Adicionando a Lista.
                idAtual++;                                                                    // Incrementamos o ID para o próximo a ser cadastrado.

                Console.WriteLine("Funcionário adicionado com sucesso!");
            } else{
                Console.WriteLine("Salário inválido. Operação cancelada.");
            }
        }

        public static void ListarFuncionarios(List<Funcionario> lista){
            Console.WriteLine("\n--- Lista de Funcionários ---");
            if(lista.Count == 0){
                Console.WriteLine("Nenhum funcionário cadastrado.");
                return;
            }

            foreach(var func in lista.OrderByDescending(f => f.Salario)){
                Console.WriteLine(func);
            }
        }

        public static void AumentarSalarioFuncionario(List<Funcionario> lista){
            Console.WriteLine("\n--- Aumentar Salário ---");
            Console.Write("Digite o ID do funcionário: ");

            if(int.TryParse(Console.ReadLine(), out int idBusca)){
                Funcionario funcionarioEncontrado = lista.FirstOrDefault(f => f.Id == idBusca);
                if(funcionarioEncontrado != null){
                    Console.Write($"Digite a porcentagem de aumento para {funcionarioEncontrado.Nome}: ");
                    if(double.TryParse(Console.ReadLine(), out double porcentagem)){
                        // Chama o método do PRÓPRIO objeto para realizar a operação.
                        funcionarioEncontrado.AumentarSalario(porcentagem);
                    } else{
                        // Tratamento para uma porcentagem inválida
                        Console.WriteLine("Porcentagem inválida.");
                    }
                } else{
                    // Tratamento para um funcionário não encontrado.
                    Console.WriteLine("Funcionário não encontrado com este ID.");
                }
            } else{
                // Tratamento para um ID inválido.
                Console.WriteLine("ID inválido.");
            }
        }

        // --- METÓDO MAIN PARA A EXECUTAR O PROGRAMA ---
        static void Main(string[] args){
            // --- DEFININDO UMA LISTA PARA OS FUNCIONARIOS ---
            // 'List<Funcionario>' é como um array onde pode crescer os diminuir dinamicamente.
            List<Funcionario> funcionarios = new List<Funcionario>();
            // Variável para gerar Ids únicos automaticamente.
            int proximoId = 1;

            // --- ESTRUTURA DE REPETIÇÃO DO MENU PRINCIPAL ---
            // Usando o while(true) para que o programa mantenha rodando até que seja digitado o comando para sair.
            while(true){
                Console.WriteLine("\n--- Sistema de Gestão de Funcionários ---");
                Console.WriteLine("1. Adicionar Funcionário");
                Console.WriteLine("2. Listar todos os Funcionários");
                Console.WriteLine("3. Aumentar Salário de um Funcionário");
                Console.WriteLine("4. Sair");
                Console.Write("Escolha uma opção: ");

                string opcao = Console.ReadLine();

                // --- ESTRUTURA DE DECISÃO: SWITCH CASE ---
                switch (opcao){
                    // --- CHAMADA DE MÉTODOS USADOS PARA INTERAGIR COM OS FUNCIONARIOS ---
                    case "1":
                        AdicionarFuncionario(funcionarios, ref proximoId);
                        break;
                    case "2":
                        ListarFuncionarios(funcionarios);
                        break;
                    case "3":
                        AumentarSalarioFuncionario(funcionarios);
                        break;
                    case "4":
                        Console.WriteLine("Saindo do sistema...");
                        return;
                    default:
                        Console.WriteLine("Opção inválida! Tente novamente.");
                        break;
                }
            }
        }
    }
}