#include <stdio.h>

int main() {
    // Declaração das variáveis para a primeira carta
    char estado1[3];
    char codigo1[5];
    char nomeCidade1[50];
    unsigned long int populacao1;
    float area1, pib1;
    int pontosTuristicos1;
    float densidadePopulacional1, pibPerCapita1;
    
    // Entrada de dados para a primeira carta
    printf("Insira os dados da primeira carta:\n");
    printf("Estado (ex: SP): ");
    scanf(" %2s", estado1);
    printf("Código da Carta: ");
    scanf(" %4s", codigo1);
    printf("Nome da Cidade: ");
    scanf(" %49s", nomeCidade1);
    printf("População: ");
    scanf(" %lu", &populacao1);
    printf("Área (km²): ");
    scanf(" %f", &area1);
    printf("PIB (bilhões de reais): ");
    scanf(" %f", &pib1);
    printf("Número de Pontos Turísticos: ");
    scanf(" %d", &pontosTuristicos1);
    
    // Cálculo da densidade populacional e PIB per capita
    densidadePopulacional1 = populacao1 / area1;
    pibPerCapita1 = (pib1 * 1000000000) / populacao1;
    
    // Declaração das variáveis para a segunda carta
    char estado2[3];
    char codigo2[5];
    char nomeCidade2[50];
    unsigned long int populacao2;
    float area2, pib2;
    int pontosTuristicos2;
    float densidadePopulacional2, pibPerCapita2;
    
    // Entrada de dados para a segunda carta
    printf("\nInsira os dados da segunda carta:\n");
    printf("Estado (ex: RJ): ");
    scanf(" %2s", estado2);
    printf("Código da Carta: ");
    scanf(" %4s", codigo2);
    printf("Nome da Cidade: ");
    scanf(" %49s", nomeCidade2);
    printf("População: ");
    scanf(" %lu", &populacao2);
    printf("Área (km²): ");
    scanf(" %f", &area2);
    printf("PIB (bilhões de reais): ");
    scanf(" %f", &pib2);
    printf("Número de Pontos Turísticos: ");
    scanf(" %d", &pontosTuristicos2);
    
    // Cálculo da densidade populacional e PIB per capita
    densidadePopulacional2 = populacao2 / area2;
    pibPerCapita2 = (pib2 * 1000000000) / populacao2;
    
    // Menu interativo para escolha dos dois atributos
    int escolha1, escolha2;
    printf("\nEscolha o primeiro atributo para comparar:\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Populacional\n6 - PIB per Capita\nOpção: ");
    scanf("%d", &escolha1);
    
    do {
        printf("\nEscolha o segundo atributo para comparar (diferente do primeiro):\n");
        printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Populacional\n6 - PIB per Capita\nOpção: ");
        scanf("%d", &escolha2);
    } while (escolha2 == escolha1);
    
    float valoresCarta1[7] = {0, populacao1, area1, pib1, pontosTuristicos1, densidadePopulacional1, pibPerCapita1};
    float valoresCarta2[7] = {0, populacao2, area2, pib2, pontosTuristicos2, densidadePopulacional2, pibPerCapita2};
    
    // Comparação dos dois atributos
    float somaCarta1 = 0, somaCarta2 = 0;
    for (int i = 0; i < 2; i++) {
        int escolha = (i == 0) ? escolha1 : escolha2;
        float valor1 = valoresCarta1[escolha];
        float valor2 = valoresCarta2[escolha];
        
        printf("\nComparação de atributo %d:\n", escolha);
        printf("Carta 1 - %s (%s): %.2f\n", nomeCidade1, estado1, valor1);
        printf("Carta 2 - %s (%s): %.2f\n", nomeCidade2, estado2, valor2);
        
        if (escolha == 5) { // Regra inversa para Densidade Populacional
            printf("Resultado: Carta %d venceu!\n", (valor1 < valor2) ? 1 : (valor2 < valor1) ? 2 : 0);
        } else {
            printf("Resultado: Carta %d venceu!\n", (valor1 > valor2) ? 1 : (valor2 > valor1) ? 2 : 0);
        }
        somaCarta1 += valor1;
        somaCarta2 += valor2;
    }
    
    // Comparação final pela soma dos atributos
    printf("\nSoma dos atributos:\n");
    printf("Carta 1 - %s: %.2f\n", nomeCidade1, somaCarta1);
    printf("Carta 2 - %s: %.2f\n", nomeCidade2, somaCarta2);
    
    if (somaCarta1 > somaCarta2) {
        printf("Resultado final: Carta 1 (%s) venceu!\n", nomeCidade1);
    } else if (somaCarta2 > somaCarta1) {
        printf("Resultado final: Carta 2 (%s) venceu!\n", nomeCidade2);
    } else {
        printf("Resultado final: Empate!\n");
    }
    
    return 0;
}