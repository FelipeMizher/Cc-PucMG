package Arquivo;

import java.security.SecureRandom;
import java.util.Random;

public class ArquivoNanoID {
    private static final Random RANDOM = new SecureRandom();
    private static final char[] ALPHABET = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ".toCharArray();

    /**
     * Gera um código alfanumérico aleatório com 10 caracteres.
     * @return A String com o código gerado.
     */
    public static String generate() {
        StringBuilder sb = new StringBuilder(10);
        for (int i = 0; i < 10; i++) {
            sb.append(ALPHABET[RANDOM.nextInt(ALPHABET.length)]);
        }
        return sb.toString();
    }
}