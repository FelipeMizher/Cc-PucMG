package Utils;

import java.text.Normalizer;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class ProcessadorTexto {
    // Lista básica de stop words em português
    private static final Set<String> STOP_WORDS = new HashSet<>(Arrays.asList(
            "de", "a", "o", "que", "e", "do", "da", "em", "um", "para", "com", "não",
            "uma", "os", "as", "dos", "das", "por", "ao", "se", "ou", "mas", "foi",
            "ser", "é", "são", "foi", "como", "quando", "seu", "sua", "pela", "peloclear"));

    public static Map<String, Double> calcularTF(String texto) {
        if (texto == null || texto.isEmpty()) {
            return new HashMap<>();
        }

        //LINHA DE DEBUG 1 (temporario)
        //System.out.println("\nProcessando: " + texto);

        // Normalizar: minúsculas e sem acentos
        String normalizado = Normalizer.normalize(texto, Normalizer.Form.NFD)
                .replaceAll("\\p{M}", "") // Remove acentos
                .toLowerCase();

        // Tokenizar: remove pontuação e quebra em palavras
        String[] tokens = normalizado.replaceAll("[^a-z0-9\\s]", "").split("\\s+");

        // Contar frequências
        Map<String, Integer> contagem = new HashMap<>();
        int totalTermosValidos = 0;

        for (String token : tokens) {
            //LINHA DE DEBUG 2 (temporario)
            //System.out.println(" > Token: '" + token + "'");

            if (token.isEmpty() || STOP_WORDS.contains(token) || token.length() < 2) {
                continue; // Ignora stop words, tokens vazios ou muito curtos
            }
            contagem.put(token, contagem.getOrDefault(token, 0) + 1);
            totalTermosValidos++;
        }

        // Calcular TF (Term Frequency)
        Map<String, Double> tfMap = new HashMap<>();
        if (totalTermosValidos == 0) {
            return tfMap; // Retorna mapa vazio se nenhum termo válido foi encontrado
        }

        for (Map.Entry<String, Integer> entry : contagem.entrySet()) {
            double tf = (double) entry.getValue() / totalTermosValidos;
            tfMap.put(entry.getKey(), tf);
        }

        return tfMap;
    }
}