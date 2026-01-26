
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

// Essa é a nossa classe principal, o nosso programa "Tradutor".
public class ConversorDeCodigos {

    //Esta função funciona como um "dicionário" que pega uma linha de operação (ex: "W=AeB;") e retorna o código de máquina correspondente para aquela operação (ex: "B").
    private static String operacao(String linha) {

        // Primeiro, a gente pega só a parte da linha que vem depois do sinal de "=".
        String expressao = linha.substring(linha.indexOf('=') + 1);
        // Agora, a gente "limpa" essa parte, tirando o ponto e vírgula e qualquer espaço em branco.
        String expressaoLimpa = expressao.replace(";", "").trim();

        // Aqui começa a tradução. A gente compara o comando "limpo" com a nossa lista de mnemônicos.
        switch (expressaoLimpa) {
            // Se o comando for "umL", o código de máquina da operação é "0".
            case "umL": return "0";
            // Se for "zeroL", o código é "1".
            case "zeroL": return "1";
            // E assim por diante para todas as 16 operações...
            case "AonB": return "2";
            case "nAonB": return "3";
            case "AeBn": return "4";
            case "nB": return "5";
            case "nA": return "6";
            case "nAxnB": return "7";
            case "AxB": return "8";
            case "copiaA": return "9";
            case "copiaB": return "A";
            case "AeB": return "B";
            case "AenB": return "C";
            case "nAeB": return "D";
            case "AoB": return "E";
            case "nAeBn": return "F";
            // Se a gente não reconhecer o comando, avisamos o usuário e retornamos "nulo".
            default:
                System.out.println("  -> Aviso: Expressão '" + expressaoLimpa + "' não reconhecida e será ignorada.");
                return null;
        }
    }

    // O método main é onde o programa realmente começa.
    public static void main(String[] args) {
        // Aqui definimos os nomes dos arquivos. Para o trabalho, o ideal é mudar para "testeula.ula"...
        String arquivoEntrada = "TESTEULA.ula";
        // ...e "testeula.hex".
        String arquivoSaida = "TESTEULA.hex";
        
        // Vamos criar duas "memórias" para guardar os últimos valores de X e Y que encontrarmos no arquivo.
        // Elas começam com "0" por padrão.
        String valorA = "0"; // Vai guardar o valor de X
        String valorB = "0"; // Vai guardar o valor de Y

        // Esse "try" é uma forma segura de abrir arquivos. Ele garante que os arquivos sejam fechados no final, mesmo se der erro.
        try (BufferedReader reader = new BufferedReader(new FileReader(arquivoEntrada));
             BufferedWriter writer = new BufferedWriter(new FileWriter(arquivoSaida))) {

            String linha;
            // Aqui a gente lê o arquivo de entrada, uma linha de cada vez, até o fim.
            while ((linha = reader.readLine()) != null) {
                // Se a linha for "fim.", a gente para de ler.
                if ("fim.".equalsIgnoreCase(linha.trim())) {
                    break;
                }

                String linhaLimpa = linha.trim();
                // Verificamos o que a linha faz:
                
                // Se a linha começa com "X=", é uma atribuição para o nosso registrador X.
                if (linhaLimpa.toUpperCase().startsWith("X=")) {
                    // A gente pega o valor que vem depois do "=" e guarda na nossa "memória" valorA.
                    valorA = linhaLimpa.substring(linhaLimpa.indexOf('=') + 1).replace(";", "");
                
                // Se começa com "Y=", é uma atribuição para o registrador Y.
                } else if (linhaLimpa.toUpperCase().startsWith("Y=")) {
                    // E guardamos o valor na nossa "memória" valorB.
                    valorB = linhaLimpa.substring(linhaLimpa.indexOf('=') + 1).replace(";", "");
                
                // Se começa com "W=" é uma linha de operação. Hora de traduzir
                } else if (linhaLimpa.toUpperCase().startsWith("W=")) {
                    // Chamamos nosso "dicionário" (a função 'operacao') para pegar o código da operação (S).
                    String valorW = operacao(linhaLimpa);

                    // Se a tradução deu certo (não é nulo)...
                    if (valorW != null) {
                        
                        // A TRADUÇÃO PARA LINGUAGEM DE MÁQUINA ACONTECE AQUI!              

                        // Juntamos o último valor de X (valorA), o último valor de Y (valorB) e o código da
                        // operação que acabamos de traduzir (valorW) para formar a instrução de 3 caracteres
                        String saidaCompleta = valorA + valorB + valorW;

                        // Escrevemos a instrução de máquina (ex: "C6B") no nosso arquivo de saída.
                        writer.write(saidaCompleta);
                        // Pulamos uma linha, para a próxima instrução ficar na linha de baixo.
                        writer.newLine();
                        // E mostramos no console o que a gente acabou de gerar, pra sabermos que está funcionando.
                        System.out.println("Linha de instrução gerada: " + saidaCompleta);
                    }
                }
            }
        // Se der algum problema para ler ou escrever nos arquivos, essa parte nos avisa.
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}