#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class token
{
  public:
  //因为这个是单向链表，所以无法再查找get后，获得前驱节点，导致增加删除为O(n)复杂度
    token *next = nullptr;
    token *down = nullptr;
    int val;
};

class skip_list
{
  public:
    token *head;
    const int MIN = 1e8;

    token *get(int val)
    {
        token *u = head;
        while (u->next != nullptr)
        {
            if (u->next->val > val)
            {
                u = u->down;
            }
            else
            {
                u = u->next;
            }
        }
        return u;
    }

    static int rand()
    {
        static default_random_engine e;
        static uniform_int_distribution<unsigned> u(0, 1);
        int ret = 0;
        while (u(e) > 0)
        {
            ret++;
        }
        return ret;
    }

    void insert(int val)
    {
        int cen = 0;
        Token *u = head;
        while (u->down != nullptr)
        {
            cen++;
        }
        int newcen = rand();
        for (int i = 0; i < newcen - cen; i++)
        {
            Token *nt = new Token();
            nt->val = MIN;
            nt->down = head;
            head = nt;
            cen++;
        }
        u = head;
        int gap = cen - newcen;
        while (gap > 0)
        {
            u = head->down;
            gap--;
        }
        Token *top = nullptr;
        for (;;)
        {
            Token *cur = insert(u, val);
            if (top != nullptr)
            {
                top->down = cur;
            }
            top = cur;
            if (u->down != nullptr)
            {
                break;
            }
        }
    }

    //这个插入不也他妈的O(n)吗？
    Token *insert(Token *t, int val)
    {
        Token *u = t;
        for (;;)
        {
            if (u->next == nullptr || u->next->val > val)
            {
                Token *n = new Token();
                n->val = val;
                n->next = u->next;
                u->next = n;
                break;
            }
            else
            {
                u = u->next;
            }
        }
        return u;
    }
    //O(n)的删除方法
    void del(int val)
    {
        Token *u = head;
        for (;;)
        {
            Token *t = u;
            Token *p = u;
            while (t.next != nullptr)
            {
                if (t.val == val)
                {
                    p.next = t.next;
                    delete t;
                    break;
                }
                if (t.val > val)
                {
                    break;
                }
                p=t;
                t=t.next;
            }
            if (u->down == nullptr)
            {
                break;
            }
            else
            {
                u = u->down;
            }
        }
    }
};

int main()
{
    cout << "fdsf" << endl;
    int a;
    cin >> a;
    return 0;
}