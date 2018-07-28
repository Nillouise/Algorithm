// test.cpp : Defines the entry point for the console application.
#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

struct Node
{
    Node *ch[2] = {NULL, NULL};
    int r, v;
    int cmp(int x) const
    {
        if (x == v)
            return -1;
        return x < v ? 0 : 1;
    }
};

//注意o不要写成零。

struct Treap
{
    int s = 0; //size;
    Node *head = NULL;
    //d=0代表左旋，d=1代表右旋
    void rotate(Node *&o, int d)
    {
        Node *k = o->ch[d ^ 1];
        o->ch[d ^ 1] = k->ch[d];
        k->ch[d] = o;
        o = k;
    }
    int myrand()
    {
        static int seed = 110355245;
        long long a = 1103515245;
        long long m = 1000000007, c = 12345;
        seed = (a * seed + c) % m;
        return seed;
    }

    void insert(Node *&o, int x)
    {
        if (o == NULL)
        {
            s++;
            o = new Node();
            o->ch[0] = o->ch[1] = NULL;
            o->v = x;
            o->r = myrand();
        }
        else
        {
            int d = o->cmp(x);
            insert(o->ch[d], x);
            if (o->ch[d]->r > o->r)
                rotate(o, d ^ 1);
        }
    }

    void remove(Node *&o, int x)
    {
        int d = o->cmp(x);
        if (d == -1)
        {
            if (o->ch[0] == NULL)
            {
                s--;
                o = o->ch[1];
            }
            else if (o->ch[1] == NULL)
            {
                s--;
                o = o->ch[0];
            }
            else
            {
                int d2 = (o->ch[0]->r > o->ch[1]->r ? 1 : 0);
                rotate(o, d2);
                remove(o->ch[d2], x);
            }
        }
        else
        {
            remove(o->ch[d], x);
        }
    }
    int find(Node *o, int x)
    {
        while (o != NULL)
        {
            int d = o->cmp(x);
            if (d == -1)
                return 1; //存在
            else
                o = o->ch[d]; //不存在
        }
        return 0;
    }

    //查前驱
    Node *pre(Node *o, int x)
    {
        if (o == NULL)
            return NULL;
        int d = o->cmp(x);
        if (d == -1)
        {
            return o;
        }
        else if (d == 0)
        {
            return pre(o->ch[0], x);
        }
        else
        {
            Node *c = pre(o->ch[1], x);
            if (c == NULL)
                return o;
            return c;
        }
    }

    Node *nxt(Node *o, int x)
    {
        if (o == NULL)
            return NULL;
        int d = o->cmp(x);
        if (d == -1)
        {
            return o;
        }
        else if (d == 1)
        { //x>o
            Node *c = nxt(o->ch[1], x);
            return c;
        }
        else
        {
            Node *c = nxt(o->ch[0], x);
            if (c == NULL)
                return o;
            return c;
        }
    }
};

int test()
{
    srand(time(0));
    set<int> s;
    Treap t;
    int n = 10;
    for (int i = 0; i < n; i++)
    {
        int v = rand();
        printf("%d ", v);
        s.insert(v);
        t.insert(t.head, v);
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        int v = rand();
        if (s.lower_bound(v) != s.end())
            printf("v:%d, t: %d, s: %d\n", v, t.nxt(t.head, v)->v, *s.lower_bound(v));
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    //	test();
    int n;
    cin >> n;
    Treap pet, cus;
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        int c, v;
        cin >> c >> v;
        if (c == 0)
        {
            if (cus.s > 0)
            {
                Node *a = cus.pre(cus.head, v);
                Node *b = cus.nxt(cus.head, v);
                long long it = 0;
                if (a == NULL)
                {
                    it = b->v;
                }
                else if (b == NULL)
                {
                    it = a->v;
                }
                else
                {
                    it = abs(a->v - v) <= abs(b->v - v) ? a->v : b->v;
                }
                cus.remove(cus.head, it);
                ans += abs(it - v);
                ans %= 1000000;
            }
            else
            {
                pet.insert(pet.head, v);
            }
        }
        else if (c == 1)
        {
            if (pet.s > 0)
            {
                Node *a = pet.pre(pet.head, v);
                Node *b = pet.nxt(pet.head, v);
                long long it = 0;
                if (a == NULL)
                {
                    it = b->v;
                }
                else if (b == NULL)
                {
                    it = a->v;
                }
                else
                {
                    it = abs(a->v - v) <= abs(b->v - v) ? a->v : b->v;
                }
                pet.remove(pet.head, it);
                ans += abs(it - v);
                ans %= 1000000;
            }
            else
            {
                cus.insert(cus.head, v);
            }
        }
    }
    cout << ans << endl;

    return 0;
}