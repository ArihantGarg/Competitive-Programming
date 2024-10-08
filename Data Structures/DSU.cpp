vi parentt, siz;

void make_set(int n)
{
    parentt.assign(n + 1, 0);
    siz.assign(n + 1, 1);

    for (ll i = 0; i <= n; i++)
        parentt[i] = i;
}

ll find_set(int v)
{
    if (v == parentt[v])
        return v;
    return parentt[v] = find_set(parentt[v]);
}

void union_set(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if (siz[a] < siz[b])
            swap(a, b);
        parentt[b] = a;
        siz[a] += siz[b];
    }
}