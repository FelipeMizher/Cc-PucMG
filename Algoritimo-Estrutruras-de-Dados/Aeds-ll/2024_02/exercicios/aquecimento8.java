import java.util.*;

class aquecimento8{
    public static void insercao(int[] array, int M){
        for(int i = 1; i < array.length; i++){
            int tmp = array[i];
            int j = i - 1;

            boolean troca = true;
    
            while(j >= 0 && troca){
                int modJ = array[j] % M;
                int modTmp = tmp % M;

                troca = false;
    
                if(modJ > modTmp){
                    troca = true;
                } else if(modJ == modTmp){
    
                    boolean jImpar = array[j] % 2 != 0;
                    boolean tmpImpar = tmp % 2 != 0;
    
                    if(!jImpar && tmpImpar){
                        troca = true;
                    } else if(jImpar && tmpImpar){
                        if(tmp > array[j]){
                            troca = true;
                        }
                    } else if(!jImpar && !tmpImpar){
                        if(tmp < array[j]){
                            troca = true;
                        }
                    }
                }
    
                if(troca){
                    array[j + 1] = array[j];
                    j--;
                }
            }
    
            array[j + 1] = tmp;
        }
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N;
        int M = 0;
        
        N = sc.nextInt();
        M = sc.nextInt();
        
        while(N != 0 && M != 0){
            int[] array = new int[N]; 

            System.out.println(N + " " + M);
            for(int i = 0; i < N; i++){
                
                array[i] = sc.nextInt();
            }
            
            insercao(array, M);

            for(int i = 0; i < N; i++){
                System.out.println("" + array[i]);
            }
            
            N = sc.nextInt();
            M = sc.nextInt();
        }

        System.out.println("0 0");
        
        sc.close();
    }
}
