#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test;
    scanf("%d", &test);
    for(int caseno=1; caseno<=test; caseno++)
    {
        deque<int>mydeque;
        int sz, q;
        scanf("%d%d", &sz, &q);
        string s;
        printf("Case %d:\n",caseno);
        for(int i=0; i<q; i++)
        {
            int n, m;
            cin>>s;
            if(s=="pushLeft")
            {
                scanf("%d",&n);
                if(sz==mydeque.size())
                    { puts("The queue is full"); continue; }
                mydeque.push_front(n);
                printf("Pushed in left: %d\n",n);
            }
            else if(s=="pushRight")
            {
                scanf("%d",&n);
                if(sz==mydeque.size())
                    { puts("The queue is full"); continue; }
                mydeque.push_back(n);
                printf("Pushed in right: %d\n",n);
            }
            else if(s=="popLeft")
            {
                if(mydeque.empty())
                   { printf("The queue is empty\n"); continue; }
                m = mydeque.front();
                mydeque.pop_front();
                printf("Popped from left: %d\n", m);
            }
            else if(s=="popRight")
            {
                if(mydeque.empty())
                   { printf("The queue is empty\n"); continue; }
                m = mydeque.back();
                mydeque.pop_back();
                printf("Popped from right: %d\n", m);
            }
        }
    }
    return 0;
}
