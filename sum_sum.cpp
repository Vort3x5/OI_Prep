int B = sqrt(n);

int blok(int x){
    return x/B;
}

long long suma[MAXB], tab[MAXN], lazy[MAXB];

void single_update(int i, long long ile){
    tab[i] += ile;
    suma[blok(i)] += ile;
}

int get_single_value(int i){
    return tab[i] + lazy[i];
}

void block_update(int i, long long ile){
    lazy[i] += ile;
    suma[i] += ile * B;
}

void update(int x, int y, int ile) {
    int b1 = blok(x), b2 = blok(y);
    // zapytanie wewnatrz jednego bloku
    if (b1 == b2){
        for (int i=x; i<=y; ++i) single_update(i, ile);
        return;
    }

    // przerabiamy lewy niepelny kubelek
    while (blok(x) == b1){
        single_update(x, ile);
        ++x;
    }
    // przerabiamy prawy niepelny kubelek
    while (blok(y) == b2){
        single_update(y, ile);
        --y;
    }
    //przerabiamy pelne kubelki
    for (int i=b1 + 1; i < b2; ++i) block_update(i, ile);
    return wyn;
}

long long query(int x, int y){
    int b1 = blok(x), b2 = blok(y);
    long long wyn = 0;
    // zapytanie wewnatrz jednego bloku
    if (b1 == b2){
        for (int i=x; i<=y; ++i) wyn += get_single_value(i) ;
        return wyn;
    }

    // przerabiamy lewy niepelny kubelek
    while (blok(x) == b1){
        wyn += get_single_value(x);
        ++x;
    }
    // przerabiamy prawy niepelny kubelek
    while (blok(y) == b2){
        wyn += get_single_value(y);
        --y;
    }
    //przerabiamy pelne kubelki
    for (int i=b1 + 1; i < b2; ++i) wyn += suma[i];
    return wyn;
}