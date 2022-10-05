while (i<tam) {
        printf("%do num: ", i+1);
        scanf("%d", arrei[i]);
        i++;
    }

    int soma;
    for (i=0; i<tam; i++) {
        soma += *arrei[i];
    }