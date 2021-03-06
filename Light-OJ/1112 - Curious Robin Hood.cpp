#include <cstdio>
#include <iostream>

using namespace std;

#define MAX 100001

int ar[MAX];
int tree[4*MAX];

void build( int at, int L, int R )
{
    if (L == R) {
        tree[at] = ar[L];
        return;
    }
    int mid = (L+R) / 2;
    build(at*2,L,mid);
    build(at*2+1,mid+1,R);
    tree[at] = tree[at*2+1] + tree[at*2];
}

void update( int at, int L, int R, int pos, int newVal, int a )
{
    if (L == R) {
        if (a == 2) tree[at] += newVal;
        else tree[at] = newVal;
        return;
    }
    int mid = (L+R) / 2;
    if (pos <= mid)
        update(at*2,L,mid,pos,newVal,a);
    else
        update(at*2+1,mid+1,R,pos,newVal,a);
    tree[at] = tree[at*2] + tree[at*2+1];
}

int query( int at, int L, int R, int l, int r )
{
    if (L>=l && R<=r)
        return tree[at];
    if (L>r || R<l)
        return 0;
    int mid = (L+R) / 2;
    return
        query(at*2,L,mid,l,r) +
        query(at*2+1,mid+1,R,l,r);
}

int main()
{
    int t, n, q, cs=0;

    scanf("%d", &t);

    while(t--) {
        scanf("%d %d", &n, &q);

        for (int i=1; i<=n; ++i)
            scanf("%d", &ar[i]);

        build(1,1,n);

        printf("Case %d:\n", ++cs);
        while(q--) {
            int a, b, c;
            scanf("%d", &a);
            if (a == 1) {
                scanf("%d", &b);
                ++b;
                printf("%d\n", ar[b]);
                ar[b] = 0;
                update (1, 1, n, b, 0, a);
            } else {
                scanf("%d%d", &b, &c);
                ++b;
                if (a == 2) {
                    update (1, 1, n, b, c, a);
                    ar[b] += c;
                }
                else
                    printf("%d\n", query (1, 1, n, b, c+1));
            }
        }
    }

    return 0;
}
