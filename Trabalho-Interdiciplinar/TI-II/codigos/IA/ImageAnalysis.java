import com.azure.ai.vision.imageanalysis.*;
import com.azure.ai.vision.imageanalysis.models.*;
import com.azure.core.credential.KeyCredential;
import java.util.Arrays;
import java.util.regex.*;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.time.format.DateTimeParseException;
import java.util.ArrayList;
import java.util.List;

public class ImageAnalysis {
    /**
     * Verifica se uma data está dentro da validade em relação à data atual.
     * @param dataValidade Data de validade no formato DD/MM/YYYY.
     * @return true se a data de validade é maior ou igual à data atual, false caso contrário.
     */
    public static boolean isDataDentroValidade(String dataValidade) {
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd/MM/yyyy");
        try {
            LocalDate validade = LocalDate.parse(dataValidade, formatter); // Converte a string para LocalDate
            LocalDate hoje = LocalDate.now(); // Data atual
            return !validade.isBefore(hoje); // Verifica se validade >= hoje
        } catch (DateTimeParseException e) {
            System.out.println("Erro ao analisar a data: " + dataValidade);
            return false; // Retorna false em caso de erro de formatação
        }
    }

    /**
     * Compara duas datas no formato DD/MM/YYYY.
     * @param data1 Primeira data.
     * @param data2 Segunda data.
     * @return 1 se data1 > data2, -1 se data1 < data2, 0 se forem iguais.
     */
    public static int compareDatas(String data1, String data2) {
        String[] partes1 = data1.split("/"); // Divide data1 em [dia, mes, ano]
        String[] partes2 = data2.split("/"); // Divide data2 em [dia, mes, ano]

        int ano1 = Integer.parseInt(partes1[2]);
        int ano2 = Integer.parseInt(partes2[2]);

        if (ano1 != ano2) {
            return Integer.compare(ano1, ano2);
        }

        int mes1 = Integer.parseInt(partes1[1]);
        int mes2 = Integer.parseInt(partes2[1]);

        if (mes1 != mes2) {
            return Integer.compare(mes1, mes2);
        }

        int dia1 = Integer.parseInt(partes1[0]);
        int dia2 = Integer.parseInt(partes2[0]);

        return Integer.compare(dia1, dia2);
    }

    public static String expandirAno(String data) {
        try {
            String[] partes = data.split("/");
            
            // Verifica e ajusta o dia para ter dois dígitos
            partes[0] = partes[0].length() == 1 ? "0" + partes[0] : partes[0];
            
            // Verifica e ajusta o mês para ter dois dígitos
            partes[1] = partes[1].length() == 1 ? "0" + partes[1] : partes[1];
            
            // Verifica e ajusta o ano para ter quatro dígitos
            if (partes[2].length() == 2) { 
                partes[2] = "20" + partes[2]; // Adiciona "20" como prefixo
            }
            
            // Recompõe a data no formato DD/MM/YYYY
            return String.join("/", partes);
        } catch (Exception e) {
            System.out.println("Erro ao expandir o ano da data: " + data);
            return null; // Retorna null em caso de erro
        }
    }
     

    public static void main(String[] args) {

        String endpoint = System.getenv("VISION_ENDPOINT");
        String key = System.getenv("VISION_KEY");

        if (endpoint == null || key == null) {
            System.out.println("Missing environment variable 'VISION_ENDPOINT' or 'VISION_KEY'.");
            System.out.println("Set them before running this sample.");
            System.exit(1);
        }

        // Criando cliente de análise de imagem
        ImageAnalysisClient client = new ImageAnalysisClientBuilder()
            .endpoint(endpoint)
            .credential(new KeyCredential(key))
            .buildClient();

        // Análise síncrona da imagem a partir de uma URL
        ImageAnalysisResult result = client.analyzeFromUrl(
            "https://th.bing.com/th/id/OIP.2iBkGDTzNIuRJeHKHN1r1QHaDM?rs=1&pid=ImgDetMain",
            Arrays.asList(VisualFeatures.CAPTION, VisualFeatures.READ),
            new ImageAnalysisOptions().setGenderNeutralCaption(true));

        // Imprimindo resultados da análise
        System.out.println("Resultados da análise de imagem:");
        System.out.println("Legenda:");
        System.out.println("   \"" + result.getCaption().getText() + "\", Confiança "
            + String.format("%.4f", result.getCaption().getConfidence()));

        System.out.println("Texto detectado:");
        List<String> datasEncontradas = new ArrayList<>(); // Lista para armazenar as datas encontradas
        String regex = "\\b(\\d{1,2})/(\\d{1,2})/(\\d{2,4})\\b"; // Regex para datas no formato DD/MM/AAAA
        Pattern pattern = Pattern.compile(regex);

        for (DetectedTextLine line : result.getRead().getBlocks().get(0).getLines()) {
            String text = line.getText();
            // Procurando datas na linha
            Matcher matcher = pattern.matcher(text);
            while (matcher.find()) {
                String dataExpandida = expandirAno(matcher.group());
                if (dataExpandida != null) {
                    datasEncontradas.add(dataExpandida); // Adiciona apenas datas válidas
                }
            }
        }

        // Verificando a maior data
        String dataValidade = null;
        if (!datasEncontradas.isEmpty()) {
            System.out.println("\nDatas encontradas na imagem:");
            for (String data : datasEncontradas) {
                System.out.println(" - " + data);
            }
            dataValidade = datasEncontradas.get(0); // Assume a primeira data como validade inicialmente
            for (String data : datasEncontradas) {
                if (compareDatas(data, dataValidade) > 0) {
                    dataValidade = data; // Atualiza para a maior data encontrada
                }
            }
            System.out.println("\nData de validade identificada: " + dataValidade);

            boolean dentroDaValidade = isDataDentroValidade(dataValidade);
            if (dentroDaValidade) {
                System.out.println("O remédio está dentro do prazo de validade.");
            } else {
                System.out.println("O remédio está fora do prazo de validade.");
            }

        } else {
            System.out.println("Nenhuma data foi encontrada na imagem.");
        } 
    }
}
